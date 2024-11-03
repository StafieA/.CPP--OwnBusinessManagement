// DateUtils.h
#ifndef UTILS_H
#define UTILS_H
#include <chrono>
#include <iostream>
#include "../gm.data/Product.h"

// Function to add days to the current date
std::chrono::system_clock::time_point addDays(int days);

std::ostream& operator<<(std::ostream& os, const std::chrono::system_clock::time_point& tp);

void printToConsoleAndFile(const Product& product, const std::string& filename);


#endif
