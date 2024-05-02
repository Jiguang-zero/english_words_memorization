//
// Created by 86158 on 2024/4/28.
//

#ifndef WORDS_MY_DATE_H
#define WORDS_MY_DATE_H

#include <ctime>
#include <string>

namespace words_memorization::utils {

    /**
     * 自定义类表示日期
     */
    class myDate {
    private:
        int year;
        int month;
        int day;

    public:
        /**
         * 默认构造函数，有且只能这一个
         */
        myDate();

        /**
         * 获取日期的字符串表示
         * @return YYYY-MM-DD
         */
        [[nodiscard]] std::string String() const;

        /**
         * 获取完整的时间 yyyy-mm-dd hh:mm:ss 用于日志系统使用
         * @return std::string 时间字符串 e.g. 2024.1.5 32:23:43
         */
        static std::string getFullTimeForLog();
    };

} // words_memorization
// utils

#endif //WORDS_MY_DATE_H
