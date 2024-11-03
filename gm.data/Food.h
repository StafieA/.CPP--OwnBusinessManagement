
#ifndef FOOD_H
#define FOOD_H

#include "Product.h"
#include <string>
#include <chrono> // or #include <chrono> if you're using chrono for date handling
#include <memory>

class Food : public Product {
    
  private:  
    std::chrono::system_clock::time_point bestBefore;// Example field for date (use time library for simplicity)

public:
    Food(int id, const std::string &name, float price, Rating rating, std::chrono::system_clock::time_point bestBefore_p);
     ~Food() override;

    std::chrono::system_clock::time_point getBestBefore() const override;
    
    void print(std::ostream& os) const override;
   std::shared_ptr<Product> applyRating(Rating newRating) override;
    double getDiscount() override;
    friend std::ostream& operator<<(std::ostream& os, const Food& food);
};

#endif // FOOD_H
