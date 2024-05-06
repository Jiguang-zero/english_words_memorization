//
// 定义有关编码的工具
// Created by 86158 on 2024/5/3.
//

#ifndef WORDS_ENCODING_H
#define WORDS_ENCODING_H

#include <iostream>

namespace words_memorization::utils {

    class Encoding {
    private:
        // 构造函数，析构函数
        Encoding() = default;
        ~Encoding() = default;

    public:
        // 删除复制函数全部设为私有
        const Encoding& operator=(const Encoding& encoding) = delete;
        Encoding(const Encoding& encoding) = default;

    public:
        /**
         * 判断字符串的某一位是否是UTF-8 3字节编码
         * @param str const std::string
         * @param index int
         * @return bool
         */
        [[maybe_unused]] inline static bool isUTF8ThreeByteChar(const std::string& str, int index);

        /**
         * 判断字符串的某一位是否是GBK 编码
         * @param str const std::string
         * @param index int
         * @return bool
         */
        [[maybe_unused]] static bool isGBKByteChar(const std::string& str, int index);
    };

} //  words_memorization
// utils

#endif //WORDS_ENCODING_H
