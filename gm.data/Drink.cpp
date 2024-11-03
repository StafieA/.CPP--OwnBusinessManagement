#include "Drink.h"
#include <iostream>

Drink::Drink(int id_p, const std::string &name_p, float price_p, Rating rating_p)
    : Product{id_p, name_p, price_p, rating_p} {
        // std::cout << "Constructing Drink...\n";
    }

   std::shared_ptr<Product> Drink::applyRating(Rating newRating) 
    {
        return std::make_shared<Drink>(getId(), getName(), getPrice(), newRating);
    }

    double Drink::getDiscount() {
            auto now = std::chrono::system_clock::now();

    // Convert the time_point to time_t and then to struct tm to extract the time
    std::time_t nowTimeT = std::chrono::system_clock::to_time_t(now);
    std::tm* nowTm = std::localtime(&nowTimeT);

    // Define the time limits for the discount (17:30 and 18:30)
    int discountStartHour = 17;
    int discountStartMinute = 30;
    int discountEndHour = 18;
    int discountEndMinute = 30;

    // Ternary operator to check if the current time is between 17:30 and 18:30
    return (nowTm->tm_hour > discountStartHour || 
            (nowTm->tm_hour == discountStartHour && nowTm->tm_min >= discountStartMinute)) &&
           (nowTm->tm_hour < discountEndHour || 
            (nowTm->tm_hour == discountEndHour && nowTm->tm_min < discountEndMinute))
           ? Product::getDiscount()  // If within the time range, return base discount
           : 0.0;                    // Otherwise, no discount
    }

    // std::string Drink::getName()
    // {
    //     return name;
    // }

Drink::~Drink() {}