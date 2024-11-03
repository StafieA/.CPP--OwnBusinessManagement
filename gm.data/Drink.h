#ifndef DRINK_H
#define DRINK_H

#include "Product.h"
#include <memory>


class Drink: public Product{

    public:
    Drink(int id, const std::string &name, float price, Rating rating);

    std::shared_ptr<Product> applyRating(Rating newRating) override;
    double getDiscount() override;
    // std::string getName();
    ~Drink() override;



};

#endif 