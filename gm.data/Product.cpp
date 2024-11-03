#include <iostream>

#include "Product.h"
#include "Rating.h"



Product::Product(int id_p, const std::string &name_p, float price_p, Rating rat_p)
         :id{id_p},name{name_p},price{price_p},rating{rat_p}{
// std::cout << "Constructing Product...\n";
}
Product::Product(int id_p, const std::string &name_p, float price_p)
        :Product{id_p, name_p, price_p, Rating::NOT_RATED}{

}

// Product::~Product() {}

// Product Product::applyRating(Rating newRat)
// {
//     return Product{id, name, price, newRat};
// }


int Product::getId() const{
    return id;
}
std::string Product::getName() const{
    return name;
}
float Product::getPrice() const{
     return price;
}

Rating Product::getRating() const{
    return rating;
}

std::string Product::getRatingStars() const{
     return getStars(rating);
}
std::chrono::system_clock::time_point Product::getBestBefore() const{
        return std::chrono::system_clock::now();
}





// void Product::setId(const int id){
//      (*this).id = id;
// }
// void Product::setName(const std::string name){
//     (*this).name = name;

// }
// void Product::setPrice(const float price){
//     this->price = price;

// }

// void Product::setRating(const Rating rat){
//      rating = rat;
// }
double Product:: getDiscount(){
    return price * DISCOUNT_RATE;

}

void Product::print(std::ostream& os) const{
    // std::cout << "ID: " << id 
    // << ", Name: " << name 
    // << ", Price: " << price 
    // << ", Rating: " << rating ;
     os << "{\n\t\"ID\": " << getId() 
       << ",\n\t\"Name\": \"" << getName() 
       << "\",\n\t\"Price\": " << getPrice() 
       << ",\n\t\"Rating\": \"" << getRating() << "\"";
       os << "\n}";
    
}

std::ostream& operator<<(std::ostream& os, const Product& product) {
    product.print(os);
    return os; 
}
bool Product::operator==(const Product& other) const {
    return this->id == other.id ;
}