#include "Review.h"

Review::Review(): rating{Rating::NOT_RATED}, comment{""} {}
Review::Review( Rating rating, const std::string& comment)
    : rating{rating}, comment{comment}  {}

// Getter for comment
std::string Review::getComment() const {
    return comment;
}

// Getter for rating
Rating Review::getRating() const {
    return rating;
}

std::ostream& operator<<(std::ostream& os, const Review& review) {
    os << "Comment: " << review.getComment() << ", Rating: " << getStars(review.getRating());
    return os;
}

bool Review::compareDescending(const Review& lhs, const Review& rhs) {
    return lhs.rating > rhs.rating; // Descending order
}


