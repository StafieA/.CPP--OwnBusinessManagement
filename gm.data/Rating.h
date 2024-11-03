#ifndef RATING_HPP
#define RATING_HPP
#include<iostream>
#include <string>

enum class Rating {
    NOT_RATED,
    ONE_STAR,
    TWO_STAR,
    THREE_STAR,
    FOUR_STAR,
    FIVE_STAR
};
int getOrdinal(Rating rating);

std::ostream& operator<<(std::ostream& os, Rating rating);
std::string getStars(Rating rating);



#endif 