//
// Created by 86158 on 2024/4/28.
//

#include "myDate.h"


namespace words_memorization::utils {
    myDate::myDate() {
        time_t now = time(nullptr);
        tm* p = localtime(&now);
        year = p->tm_year + 1900;
        month = p->tm_mon + 1;
        day = p->tm_mday;

        delete p;
    }

    std::string myDate::String() const {
        return std::string(
                std::to_string(year) + "-" +
                std::to_string(month) + "-" +
                std::to_string(day));
    }
} // words_memorization
// utils