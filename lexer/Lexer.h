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
         * ���캯����˽��
         * @param input std::string, char  = 0�� position, readPosition = 0
         */
        explicit Lexer(std::string input);

        /**
         * �����հ��ַ� ' ', '\t', '\n', '\r'
         */
        void skipWhiteSpace();

        /**
         * �ж��Ƿ��ǿհ��ַ�(��ʶ���Ľ���)
         * @param ch char�����жϵ��ַ�
         * @return bool
         */
        static bool isWhiteSpace(char ch);

        /**
         * �ж��ַ��Ƿ��� ��ĸ
         * @param ch char
         * @return bool
         */
        static bool isLetter(char ch);

        /**
         * �ж�ĳ���ַ��Ƿ��� ����
         * @param ch char
         * @return bool
         */
        static bool isDigit(char ch);

        /**
         * ������һ���ַ������ƶ�λ�� position
         * @return ������һ���ַ�
         */
        char peekChar();

        /**
         * �½�һ���ʷ���Ԫ
         * @param tokenType �ʷ���Ԫ����
         * @param literal �ʷ���Ԫ�������� std::string
         * @return Token ����
         */
        static token::Token newToken(token::TokenType tokenType, std::string literal);

        /**
         * ��ȡ�ַ������Զ�ȡ GBK�ַ�
         */
        void readChar();

        /**
         * ��ȡ��ʶ�� (��ȡ����)
         */
        std::string readIdentifier();


    public:
        /**
         * ��̬���� ָ��Lexer���� ��ָ�룬 ֻ��ͨ���˾�̬��������
         * @param input
         * @return Lexer*
         */
        static Lexer *New(const std::string &input);

        /**
         * ��ȡ��һ���ʷ���Ԫ
         * @return ���شʷ���Ԫ
         */
        token::Token NextToken();

    };

} //  words_memorization
// lexer

#endif //WORDS_LEXER_H
