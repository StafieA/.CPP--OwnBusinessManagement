#include "Utils.h"
#include "../gm.data/Product.h"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>   // For file handling
#include <chrono>
#include <string>


// Define the function here
std::chrono::system_clock::time_point addDays(int days) {
    return std::chrono::system_clock::now() + std::chrono::hours(24 * days);
}

std::ostream& operator<<(std::ostream& os, const std::chrono::system_clock::time_point& tp) {
    // std::time_t time = std::chrono::system_clock::to_time_t(tp);
    // os << std::ctime(&time);  // Convert to human-readable time format
    std::time_t time = std::chrono::system_clock::to_time_t(tp);
    os << std::put_time(std::localtime(&time), "%c");  // Use %c for full date/time representation
    return os;
}

void printToConsoleAndFile(const Product& product, const std::string& filename) {
    std::cout << "## Starting print method ##"<<std::endl;
    std::cout << "## Start printing to console ##"<<std::endl;
    // Print to console
    std::cout << product << std::endl;

    std::cout << "## End printing to console ##"<<std::endl;
    
    // Open the file to write (create if it doesn't exist)
    std::ofstream outFile(filename, std::ios::app);  // append mode to prevent overwriting
    
    if (outFile.is_open()) {
        std::cout << "## Start printing in JSON file ##"<<std::endl;
        outFile << product << std::endl;
        outFile.close();
        std::cout << "## End printing to JSON file ##"<<std::endl;
        std::cout << "Data written to " << filename << std::endl;
    } else {
        std::cerr << "Error opening file " << filename << std::endl;
    }
}
