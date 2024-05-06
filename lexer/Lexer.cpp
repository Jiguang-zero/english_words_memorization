//
// Created by 86158 on 2024/5/3.
//

#include "Lexer.h"

#include <utility>
#include "../utils/Encoding.h"
#include "../utils/myDate.h"



namespace words_memorization::lexer {
    using utils::Encoding;

    Lexer::Lexer(std::string input) {
        this->input = std::move(input);
        position = 0;
        readPosition = 0;
        ch = 0;
    }

    Lexer *Lexer::New(const std::string &input) {
        auto* lexer = new Lexer(input);

        lexer->readChar();

        return lexer;
    }

    void Lexer::readChar() {
        if (readPosition >= input.length()) {
            ch = 0;
        } else {
            ch = input[readPosition];
        }
        position = readPosition;
        if (Encoding::isGBKByteChar(input, position)) {
            readPosition += 2;
        }
        else {
            readPosition += 1;
        }
    }

    token::Token Lexer::newToken(token::TokenType tokenType, std::string literal) {
        return {std::move(literal), std::move(tokenType)};
    }

    void Lexer::skipWhiteSpace() {
        while (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n') {
            readChar();
        }
    }

    char Lexer::peekChar() {
        if (readPosition >= input.length()) {
            return 0;
        }
        else {
            return input[readPosition];
        }
    }

    token::Token Lexer::NextToken() {
        token::Token token;

        skipWhiteSpace();

        switch (ch) {
            case '/':
                token = newToken(token::Token::SLASH, "/");
                break;
            case '|':
                token = newToken(token::Token::VERTICAL, "|");
                break;
            case '-':
                // �ж��Ƿ���ѡ�� -option option��������ĸ��ͷ
                if (isLetter(peekChar())) {
                    std::string option = readIdentifier();
                    token = newToken(token::Token::OPTION, option);
                }
                // -
                // ��ʱ����Ҳ�ò��ŵ�����һ�������������԰����ŵ��Ƿ��ַ���
                else {
                    token = newToken(token::Token::MINUS, "-");
                }
                break;
            case 0:
                token = newToken(token::Token::TOKEN_EOF, "");
                break;
            default:
                auto literal = readIdentifier();
                if (isDigit(peekChar())) {
                    if (utils::myDate::isDate(literal)) {
                        token = newToken(token::Token::DATE, literal);
                        break;
                    }
                }

                token.setLiteral(literal);
                token.setType(token::Token::LookupIdent(literal));
        }

        readChar();

        return token;
    }

    std::string Lexer::readIdentifier() {
        int p = position;

        while (ch != 0 && !isWhiteSpace(ch)) {
            readChar();
        }

        return input.substr(p, position - p);
    }

    bool Lexer::isWhiteSpace(char ch) {
        if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n') {
            return true;
        }
        return false;
    }

    bool Lexer::isLetter(char ch) {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }

    bool Lexer::isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
} //  words_memorization
// lexer