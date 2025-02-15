#include "Logger.h"
#include <iostream>

bool Logger::is_print_logs = true; // Example initialization

void Logger::debug(const std::string& message) {
    if (is_print_logs) {
        log(message, Blue); // For example, blue color for debug
    }
}

void Logger::info(const std::string& message) {
    if (is_print_logs) {
        log(message, Green); // Green for info
    }
}

void Logger::error(const std::string& message) {
    if (is_print_logs) {
        log(message, Red); // Red for error
    }
}

void Logger::warning(const std::string& message) {
    if (is_print_logs) {
        log(message, Yellow); // Yellow for warning
    }
}

void Logger::log(const std::string& message, Colors color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    std::cout << message << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Default); // Reset color
}
