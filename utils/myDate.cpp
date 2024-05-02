//
// Created by 86158 on 2024/4/28.
//

#include "myDate.h"
#include <sstream>


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

    std::string myDate::getFullTimeForLog() {
        std::ostringstream oss;

        time_t now = time(nullptr);
        tm* p = localtime(&now);

        oss << std::to_string(p->tm_year + 1900) + ".";
        oss << std::to_string(p->tm_mon + 1) + ".";
        oss << std::to_string(p->tm_mday) + " ";

        oss << std::to_string(p->tm_hour) + ":";
        oss << std::to_string(p->tm_min) + ":";
        oss << std::to_string(p->tm_sec);

        // delete p;
        // > p 是静态分配的，不应该释放

        return oss.str();
    }
} // words_memorization
// utils