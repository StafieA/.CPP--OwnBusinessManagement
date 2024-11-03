#ifndef PRODUCT_H
#define PRODUCT_H
#include<string>
#include <chrono>
#include "Rating.h"
#include "Rateable.h"

class Product:public Rateable<Product>{

    private:

    const int id;
    const std::string name;
    const float price;
    const Rating rating;

    public:

    static constexpr double DISCOUNT_RATE = 0.1;

    Product(int id_p, const std::string &name_p, float price_p, Rating rat_p);
    Product(int id_p, const std::string &name_p, float price_p);
    virtual ~Product() = default;

    virtual std::shared_ptr<Product> applyRating(Rating newRat) = 0;
    friend std::ostream& operator<<(std::ostream& os, const Product& product);
    bool operator==(const Product& other) const;

    int getId() const;
    std::string getName() const;
    float getPrice() const;
    Rating getRating() const override;
    std::string getRatingStars()const;
   virtual std::chrono::system_clock::time_point getBestBefore() const;
    // void setId(int id);
    // void setName(std::string name);
    // void setPrice(float price);
    // void setRating(Rating);

    virtual double getDiscount();
    virtual void print(std::ostream& os) const;

    void printToConsoleAndFile(const std::string& filename) const;




};

#endif