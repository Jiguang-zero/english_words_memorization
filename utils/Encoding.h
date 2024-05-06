//
// �����йر���Ĺ���
// Created by 86158 on 2024/5/3.
//

#ifndef WORDS_ENCODING_H
#define WORDS_ENCODING_H

#include <iostream>

namespace words_memorization::utils {

    class Encoding {
    private:
        // ���캯������������
        Encoding() = default;
        ~Encoding() = default;

    public:
        // ɾ�����ƺ���ȫ����Ϊ˽��
        const Encoding& operator=(const Encoding& encoding) = delete;
        Encoding(const Encoding& encoding) = default;

    public:
        /**
         * �ж��ַ�����ĳһλ�Ƿ���UTF-8 3�ֽڱ���
         * @param str const std::string
         * @param index int
         * @return bool
         */
        [[maybe_unused]] inline static bool isUTF8ThreeByteChar(const std::string& str, int index);

        /**
         * �ж��ַ�����ĳһλ�Ƿ���GBK ����
         * @param str const std::string
         * @param index int
         * @return bool
         */
        [[maybe_unused]] static bool isGBKByteChar(const std::string& str, int index);
    };

} //  words_memorization
// utils

#endif //WORDS_ENCODING_H
