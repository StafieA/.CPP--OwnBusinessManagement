#include "Food.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <chrono>

Food::Food(int id_p, const std::string &name_p, float price_p, Rating rating_p, std::chrono::system_clock::time_point bestBefore_p)
    : Product{id_p, name_p, price_p, rating_p}, bestBefore{bestBefore_p} {}

    Food::~Food(){}

    std::shared_ptr<Product> Food::applyRating(Rating newRating)
    {
            return std::make_shared<Food>(getId(), getName(), getPrice(), newRating, bestBefore);
    }

    double Food::getDiscount(){
        auto now = std::chrono::system_clock::now();
        // Convert both the current time and bestBefore to time_t to extract the date
        std::time_t nowTimeT = std::chrono::system_clock::to_time_t(now);
        std::time_t bestBeforeTimeT = std::chrono::system_clock::to_time_t(bestBefore);
        std::tm* nowTm = std::localtime(&nowTimeT);
        std::tm* bestBeforeTm = std::localtime(&bestBeforeTimeT);
        return (nowTm->tm_year == bestBeforeTm->tm_year &&
            nowTm->tm_mon == bestBeforeTm->tm_mon &&
            nowTm->tm_mday == bestBeforeTm->tm_mday) 
            ? Product::getDiscount() // If the dates match, return the base discount
            : 0.0;                    // Otherw
    }



std::chrono::system_clock::time_point Food::getBestBefore() const {
    return bestBefore;
}
// std::ostream& operator<<(std::ostream& os, const Food& food) {
//     os << static_cast<const Product&>(food) // Call the base class operator<<
//        << food.getBestBefore();", Best Before: /* Convert food.bestBefore to a string representation */"; // Customize as needed
//     return os;
// }
// std::chrono::system_clock::time_point addDays(int days) {
//     return std::chrono::system_clock::now() + std::chrono::hours(24 * days);
// }
void Food::print(std::ostream& os) const {
    // Call the base class print method to print common details (id, name, price, rating)
    Product::print(os);

    // Add the specific member of Food (bestBefore)
    // std::time_t bb_time = std::chrono::system_clock::to_time_t(bestBefore);
    // os << ", Best Before: " << std::ctime(&bb_time);  // ctime converts to human-readable form


//     std::time_t time = std::chrono::system_clock::to_time_t(bestBefore);
//     os << ", Best Before: " << std::put_time(std::localtime(&time), "%c");  // Use %c for full date/time representation
        auto bestBeforeTime = std::chrono::system_clock::to_time_t(bestBefore);
    os << ",\n\t\"BestBefore\": \"" << std::put_time(std::localtime(&bestBeforeTime), "%c %Z") << "\"\n}";
    
 }
