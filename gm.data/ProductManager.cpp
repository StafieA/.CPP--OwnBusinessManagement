
#include "ProductManager.h"
#include "Drink.h"
#include "Food.h"

#include <fstream>
#include <sstream>
#include <cmath>

ProductManager::ProductManager(const std::locale& loc)
    : locale{loc} {
    // Load the resource file
    loadResources("gm.data/resources.properties"); 
    }
std::shared_ptr<Product> ProductManager::createProduct(int id, const std::string &name, float price, Rating rating)
{    
//     auto drink = Drink(id, name, price, rating);
// std::shared_ptr<Product> product = std::make_shared<Drink>(drink);
    std::shared_ptr<Product> product = std::make_shared<Drink>(id, name, price, rating);
    productReviews.insert(std::make_pair( product, std::list<Review>()));
    // std::cout << "createProduct 4 params: product este " << product.get() << std::endl;
    return product; // Return the raw pointer to the created Product
}
    
std::shared_ptr<Product> ProductManager::createProduct(int id, const std::string &name, float price, Rating rating, std::chrono::system_clock::time_point bestBefore)
{
     std::shared_ptr<Product> product = std::make_shared<Food>(id, name, price, rating, bestBefore);
    productReviews.insert(std::make_pair( product, std::list<Review>()));
    
    return product; // Return the raw pointer to the created Product
}



std::shared_ptr<Product> ProductManager::reviewProduct(const std::shared_ptr<Product>& p, Rating rat, const std::string& comment) 
{
          // Find the product in the map
    auto it = productReviews.find(p);
    if (it != productReviews.end()) {
        // Retrieve the list of reviews
        std::list<Review> reviews = it->second;

        // Remove the product from the map
        productReviews.erase(it);

        // Create a new review and add it to the list
        Review review(rat, comment);
        reviews.push_back(review);

        // Calculate the sum of ratings using getOrdinal
        int sum = 0;
        for (const auto& r : reviews) {
            sum += getOrdinal(r.getRating());
        }

        // Calculate the average rating
        float average = static_cast<float>(sum) / reviews.size();
        int mediaStars = static_cast<int>(std::round(average));

        // Convert mediaStars to Rating enum
        Rating newRating = Rateable<Product>::convert(mediaStars);

        // Create a new product with the updated rating
        std::shared_ptr<Product> updatedProduct = p->applyRating(newRating);

        // Insert the updated product and reviews back into the map
        productReviews.insert({updatedProduct, reviews});

        // Return the updated product
        return updatedProduct;
    } else {
        // Product not found
        std::cout << "Product not found." << std::endl;
        return nullptr; // Or handle as needed
    }
    }

void ProductManager::loadResources(const std::string& resourceFile) {
    std::ifstream file(resourceFile);
    if (!file) {
        throw std::runtime_error("Could not open resource file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            resources[key] = value;
        }
    }
}

void ProductManager::printProductReport(const std::shared_ptr<Product>& product) const {
    std::ostringstream txt;
    // Set the locale for formatting
    std::cout.imbue(locale);

    // Format the price as currency
    std::cout << std::fixed << std::setprecision(2); // Set precision for currency

    auto it = productReviews.find(product);

    if (it == productReviews.end()) {
        std::cout << "Product not found" << std::endl;
        return;
    }

    // Get the updated product from the map
    const std::shared_ptr<Product>& updatedProduct = it->first;
     const std::list<Review>& reviews = it->second;
    
    txt << updatedProduct->getName() << ", Price: "
        << std::fixed << std::setprecision(2) << updatedProduct->getPrice() << ", Rating: "
        << getStars(updatedProduct->getRating()) << ", Best Before: ";

    // Convert time_point to time_t
    auto bestBeforeTimePoint = updatedProduct->getBestBefore(); // Assuming this returns time_point
    std::time_t bestBeforeTimeT = std::chrono::system_clock::to_time_t(bestBeforeTimePoint);

    // Convert time_t to tm structure
    std::tm* bestBeforeTm = std::localtime(&bestBeforeTimeT); // Use localtime for local timezone

    // Print the formatted date
    txt << std::put_time(bestBeforeTm, "%Y-%m-%d") << "\n";

    std::list<Review> sortedReviews = reviews;

    // Sort the copied list
    sortedReviews.sort(Review::compareDescending);

    // Append review information
    if (!reviews.empty()) {
        for (const auto& review : sortedReviews) {
            txt << "Review: " << getStars(review.getRating()) << "\t"
                << review.getComment() << "\n";
        }
    } else {
        txt << "No reviews available.\n";
    }

    std::cout << txt.str(); // Print the final report
}
std::shared_ptr<Product> ProductManager::findProduct(int id) const
{

    
    for (const auto& pair : productReviews)
    {
        const std::shared_ptr<Product>& product = pair.first;
        if (product->getId() == id)
        {
             return product;
             
        }
    }
   std:: cout << "Product with id = " << id << " not found"<< std::endl;
    return nullptr;
}

std::shared_ptr<Product> ProductManager::reviewProduct(int id, Rating rat, const std::string &comment)
{
    return ProductManager::reviewProduct(ProductManager::findProduct(id), rat, comment );
}

void ProductManager::printProductReport( int id) const
{
    ProductManager::printProductReport(ProductManager::findProduct(id));
}
