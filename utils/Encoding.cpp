//
// Created by 86158 on 2024/5/3.
//

#include "Encoding.h"


namespace words_memorization::utils {
    [[maybe_unused]] bool Encoding::isUTF8ThreeByteChar(const std::string &str, int index) {
        // ȷ���ַ��Ŀ�ͷ�ֽڵ�ģʽΪ"1110xxxx"
        if ((str[index] & 0xF0) != 0xE0) {
            return false;
        }

        // ��3�ֽ�
        if (index < str.length() - 2) {
            return false;
        }

        // ȷ���ַ��ĺ����ֽڵ�ģʽΪ"10xxxxxx"
        if ((str[index + 1] & 0xC0) != 0x80 || (str[index + 2] & 0xC0) != 0x80) {
            return false;
        }

        return true;
    }

    [[maybe_unused]] bool Encoding::isGBKByteChar(const std::string &str, int index) {
        // ������
        if (index < 0 || index >= str.length()) {
            return false;
        }
        unsigned char byte = str[index];
        // �ж��Ƿ�ΪGBK��������ֽ�
        if (byte >= 0x81 && byte <= 0xFE) {
            // ���ֽ���0x81-0xFE��Χ�ڣ�������GBK��������ֽ�
            if (index + 1 < str.length()) {
                unsigned char nextByte = str[index + 1];
                // �жϺ����ֽ��Ƿ���0x40-0xFE��Χ��
                if (nextByte >= 0x40 && nextByte <= 0xFE) {
                    return true;
                }
            }
        }

        return false;
    }
} //  words_memorization
// utils