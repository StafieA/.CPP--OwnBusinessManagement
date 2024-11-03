#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include "Product.h"
#include "Rating.h"
#include "review.h"
#include <string>
#include <memory>
#include <iostream>
#include <map>
#include <iomanip>
#include <locale>
#include <ctime>
#include <map>
#include <list>
#include <vector>
#include <algorithm>



struct SharedPtrComparator {
    bool operator()(const std::shared_ptr<Product>& lhs, const std::shared_ptr<Product>& rhs) const {
        return lhs->getId() < rhs->getId(); // Compare based on Product name or any other criteria
    }
};

class ProductManager
{
private:

    std::locale locale;
    std::map<std::string, std::string> resources;
    
    // std::unique_ptr<Product> product;
    // Review review;

    void loadResources(const std::string& resourceFile);

public:
std::map<std::shared_ptr<Product>, std::list<Review>, SharedPtrComparator> productReviews;

explicit ProductManager(const std::locale& loc);
    std::shared_ptr<Product> createProduct(int id, const std::string &name, float price, Rating rating);
    std::shared_ptr<Product> createProduct(int id, const std::string &name, float price, Rating rating, std::chrono::system_clock::time_point bestBefore);

    

    std::shared_ptr<Product> reviewProduct(const std::shared_ptr<Product>& p, Rating rat, const std::string &comment);
    std::shared_ptr<Product> reviewProduct(int id, Rating rat, const std::string &comment);
    void printProductReport(const std::shared_ptr<Product>& p) const;
    void printProductReport(  int id) const;
    std::shared_ptr<Product> findProduct(int id) const;
    
    
};

#endif