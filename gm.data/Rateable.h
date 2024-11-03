#ifndef RATEABLE_H
#define RATEABLE_H

#include "Rating.h"
#include <memory>

template <typename T>
class Rateable {
public:
    static const Rating DEFAULT_RATING = Rating::NOT_RATED;

    
    virtual std::shared_ptr<T> applyRating(Rating rating) = 0;

    
    virtual std::shared_ptr<T> applyRating(int stars) {
        return applyRating(Rateable::convert(stars));
    }

    
    virtual Rating getRating() const {
        return DEFAULT_RATING;
    }

    
    static Rating convert(int stars) {
        if (stars >= 0 && stars <= 5) {
            return static_cast<Rating>(stars);
        }
        return DEFAULT_RATING;
    }

   
    virtual ~Rateable() = default;
};

#endif 