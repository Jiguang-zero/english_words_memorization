//
// Created by 86158 on 2024/4/28.
//

#ifndef WORDS_MYDATE_H
#define WORDS_MYDATE_H

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
    };

} // words_memorization
// utils

#endif //WORDS_MYDATE_H
