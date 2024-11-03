#include "Rating.h"

std::string getStars(Rating rating) {
    switch (rating) {
        case Rating::NOT_RATED:
            return "☆☆☆☆☆"; 
        case Rating::ONE_STAR:
            return "★☆☆☆☆";
        case Rating::TWO_STAR:
            return "★★☆☆☆"; 
        case Rating::THREE_STAR:
            return "★★★☆☆";
        case Rating::FOUR_STAR:
            return "★★★★☆"; 
        case Rating::FIVE_STAR:
            return "★★★★★"; 
        default:
            return "Invalid rating"; 
    }
}

std::ostream& operator<<(std::ostream& os, Rating rating) {
    return os << getStars(rating);
}
int getOrdinal(Rating rating) {
    return static_cast<int>(rating); // Convert enum to int
}
