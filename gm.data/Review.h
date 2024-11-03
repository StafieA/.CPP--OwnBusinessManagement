#ifndef REVIEW_H
#define REVIEW_H
#include<iostream>
#include <string>
#include "Rating.h"

class Review {
private:
    
    Rating rating;
    std::string comment;

public:
    Review();
    Review(Rating rating, const std::string& comment);

    
    std::string getComment() const;
    Rating getRating() const;

   friend std::ostream& operator<<(std::ostream& os, const Review& review);
   bool operator<(const Review& other) const {
        return this->getRating() < other.getRating();
    }

    // Optionally, you can also add operator> if needed
    bool operator>(const Review& other) const {
        return this->getRating() > other.getRating();
    }
    static bool compareDescending(const Review& lhs, const Review& rhs);
};

#endif 