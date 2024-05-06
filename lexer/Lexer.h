//
// Created by 86158 on 2024/5/3.
//

#ifndef WORDS_LEXER_H
#define WORDS_LEXER_H

#include <string>
#include "../token/Token.h"

namespace words_memorization::lexer {

    class Lexer {
    private:
        char ch;
        int position;
        int readPosition;
        std::string input;

    private:
        /**
         * 构造函数，私有
         * @param input std::string, char  = 0， position, readPosition = 0
         */
        explicit Lexer(std::string input);

        /**
         * 跳过空白字符 ' ', '\t', '\n', '\r'
         */
        void skipWhiteSpace();

        /**
         * 判断是否是空白字符(标识符的结束)
         * @param ch char用于判断的字符
         * @return bool
         */
        static bool isWhiteSpace(char ch);

        /**
         * 判断字符是否是 字母
         * @param ch char
         * @return bool
         */
        static bool isLetter(char ch);

        /**
         * 判断某个字符是否是 数字
         * @param ch char
         * @return bool
         */
        static bool isDigit(char ch);

        /**
         * 窥视下一个字符，不移动位置 position
         * @return 返回下一个字符
         */
        char peekChar();

        /**
         * 新建一个词法单元
         * @param tokenType 词法单元类型
         * @param literal 词法单元的字面量 std::string
         * @return Token 对象
         */
        static token::Token newToken(token::TokenType tokenType, std::string literal);

        /**
         * 读取字符，可以读取 GBK字符
         */
        void readChar();

        /**
         * 读取标识符 (读取单词)
         */
        std::string readIdentifier();


    public:
        /**
         * 动态分配 指向Lexer对象 的指针， 只能通过此静态函数创建
         * @param input
         * @return Lexer*
         */
        static Lexer *New(const std::string &input);

        /**
         * 获取下一个词法单元
         * @return 返回词法单元
         */
        token::Token NextToken();

    };

} //  words_memorization
// lexer

#endif //WORDS_LEXER_H
