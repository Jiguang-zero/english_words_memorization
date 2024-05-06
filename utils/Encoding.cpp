//
// Created by 86158 on 2024/5/3.
//

#include "Encoding.h"


namespace words_memorization::utils {
    [[maybe_unused]] bool Encoding::isUTF8ThreeByteChar(const std::string &str, int index) {
        // 确保字符的开头字节的模式为"1110xxxx"
        if ((str[index] & 0xF0) != 0xE0) {
            return false;
        }

        // 非3字节
        if (index < str.length() - 2) {
            return false;
        }

        // 确保字符的后续字节的模式为"10xxxxxx"
        if ((str[index + 1] & 0xC0) != 0x80 || (str[index + 2] & 0xC0) != 0x80) {
            return false;
        }

        return true;
    }

    [[maybe_unused]] bool Encoding::isGBKByteChar(const std::string &str, int index) {
        // 错误处理
        if (index < 0 || index >= str.length()) {
            return false;
        }
        unsigned char byte = str[index];
        // 判断是否为GBK编码的首字节
        if (byte >= 0x81 && byte <= 0xFE) {
            // 首字节在0x81-0xFE范围内，可能是GBK编码的首字节
            if (index + 1 < str.length()) {
                unsigned char nextByte = str[index + 1];
                // 判断后续字节是否在0x40-0xFE范围内
                if (nextByte >= 0x40 && nextByte <= 0xFE) {
                    return true;
                }
            }
        }

        return false;
    }
} //  words_memorization
// utils