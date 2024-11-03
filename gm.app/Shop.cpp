#include <iostream>
#include <locale>
#include <string>
#include <memory>
#include <list>
#include <map>

#include "../gm.data/Product.h"
#include "../gm.data/Rating.h"
#include "../gm.data/Food.h"
#include "../gm.data/Drink.h"
#include "../gm.data/Utils.h"
#include "../gm.data/Review.h"
#include "../gm.data/ProductManager.h"
#include "../gm.data/Rateable.h"

using std::cin;
using std::cout;
using std::endl;



int main()
{
    std::locale loc;
    try
    {
        loc = std::locale("de_DE.utf8");
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Locale not supported on your system: " << e.what() << std::endl;
        std::cerr << "Using default locale." << std::endl;
        loc = std::locale::classic(); 
    }

    
    std::locale::global(loc);
    std::cout.imbue(loc);

    ProductManager pm{loc};

    
    pm.createProduct(100, "Coke", 11.5, Rating::NOT_RATED);
    pm.printProductReport(100);

    pm.reviewProduct(100, Rating::ONE_STAR, "Not enjoyable.");
    pm.reviewProduct(100, Rating::ONE_STAR, "Too sweet for my taste.");
    pm.reviewProduct(100, Rating::THREE_STAR, "Average soda.");
    pm.reviewProduct(100, Rating::THREE_STAR, "It's okay.");
    pm.reviewProduct(100, Rating::FOUR_STAR, "Pretty good!");
    pm.reviewProduct(100, Rating::FIVE_STAR, "Excellent taste!");
    pm.printProductReport(100);

    std::cout << "===================================" << std::endl;


    pm.createProduct(101, "Bread", 2.50, Rating::NOT_RATED, addDays(4));
    pm.printProductReport(101);

    pm.reviewProduct(101, Rating::ONE_STAR, "Stale and dry.");
    pm.reviewProduct(101, Rating::ONE_STAR, "Not fresh.");
    pm.reviewProduct(101, Rating::ONE_STAR, "Didn't like it.");
    pm.reviewProduct(101, Rating::ONE_STAR, "Very hard.");
    pm.reviewProduct(101, Rating::ONE_STAR, "Disappointing.");
    pm.reviewProduct(101, Rating::FIVE_STAR, "Excellent quality!");
    pm.printProductReport(101);

    std::cout << "===================================" << std::endl;

    
    pm.createProduct(102, "Cheese", 5.00, Rating::NOT_RATED, addDays(7));
    pm.printProductReport(102);

    pm.reviewProduct(102, Rating::FIVE_STAR, "Absolutely delicious!");
    pm.reviewProduct(102, Rating::FIVE_STAR, "Best cheese I've ever had.");
    pm.reviewProduct(102, Rating::FIVE_STAR, "Perfect for sandwiches.");
    pm.reviewProduct(102, Rating::FIVE_STAR, "Rich and creamy.");
    pm.reviewProduct(102, Rating::FOUR_STAR, "Very good, but a bit salty.");
    pm.reviewProduct(102, Rating::FOUR_STAR, "Great flavor.");
    pm.printProductReport(102);

    std::cout << "===================================" << std::endl;

    
    pm.createProduct(103, "Apple", 0.80, Rating::NOT_RATED, addDays(10));
    pm.printProductReport(103);

    pm.reviewProduct(103, Rating::TWO_STAR, "Some apples were bruised.");
    pm.reviewProduct(103, Rating::THREE_STAR, "Not as fresh as expected.");
    pm.reviewProduct(103, Rating::TWO_STAR, "A bit sour.");
    pm.reviewProduct(103, Rating::THREE_STAR, "Average quality.");
    pm.reviewProduct(103, Rating::FOUR_STAR, "Pretty good apples.");
    pm.reviewProduct(103, Rating::TWO_STAR, "Could be better.");
    pm.printProductReport(103);

    std::cout << "===================================" << std::endl;

    
    pm.createProduct(201, "Water", 1.00, Rating::NOT_RATED);
    pm.printProductReport(201);

    pm.reviewProduct(201, Rating::FIVE_STAR, "Pure and refreshing.");
    pm.reviewProduct(201, Rating::THREE_STAR, "It's water.");
    pm.reviewProduct(201, Rating::FOUR_STAR, "Good quality.");
    pm.reviewProduct(201, Rating::FIVE_STAR, "Very hydrating.");
    pm.reviewProduct(201, Rating::THREE_STAR, "Nothing special.");
    pm.reviewProduct(201, Rating::FOUR_STAR, "Tastes clean.");
    pm.printProductReport(201);

    std::cout << "===================================" << std::endl;

    
    pm.createProduct(202, "Juice", 2.00, Rating::NOT_RATED);
    pm.printProductReport(202);

    pm.reviewProduct(202, Rating::ONE_STAR, "Didn't like the taste.");
    pm.reviewProduct(202, Rating::TWO_STAR, "Too sweet.");
    pm.reviewProduct(202, Rating::THREE_STAR, "Average juice.");
    pm.reviewProduct(202, Rating::FOUR_STAR, "Good flavor.");
    pm.reviewProduct(202, Rating::FIVE_STAR, "Best juice ever!");
    pm.reviewProduct(202, Rating::TWO_STAR, "Probably won't buy again.");
    pm.printProductReport(202);

    std::cout << "===================================" << std::endl;

    
    pm.createProduct(203, "Milk", 1.50, Rating::NOT_RATED);
    pm.printProductReport(203);

    pm.reviewProduct(203, Rating::FOUR_STAR, "Fresh and creamy.");
    pm.reviewProduct(203, Rating::TWO_STAR, "Slightly sour.");
    pm.reviewProduct(203, Rating::FOUR_STAR, "Good taste.");
    pm.reviewProduct(203, Rating::THREE_STAR, "It's okay.");
    pm.reviewProduct(203, Rating::FOUR_STAR, "Very good.");
    pm.reviewProduct(203, Rating::TWO_STAR, "Not as expected.");
    pm.printProductReport(203);

    return 0;
}
