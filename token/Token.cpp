//
// Created by 86158 on 2024/5/3.
//

#include "Token.h"


namespace words_memorization::token {
    const TokenType Token::SLASH = "/";
    const TokenType Token::COMMA = ",";
    const TokenType Token::MINUS = "-";
    const TokenType Token::VERTICAL = "|";

    const TokenType Token::IDENT = "ident";
    const TokenType Token::DATE = "date";
    const TokenType Token::TOKEN_EOF = "EOF";
    const TokenType Token::OPTION = "option";

    const TokenType Token::INSERT_COMMAND = "insert";
    const TokenType Token::SELECT_COMMAND = "select";
    const TokenType Token::MODIFY_COMMAND = "modify";

    std::unordered_map<std::string , TokenType > Token::keywords = {
            {"select", SELECT_COMMAND},
            {"insert", INSERT_COMMAND},
            {"modify", MODIFY_COMMAND},
    };

    [[maybe_unused]] void Token::setLiteral(std::string _literal) {
        literal = std::move(_literal);
    }

    TokenType Token::LookupIdent(const std::string &ident) {
        if(keywords.count(ident)) {
            return keywords[ident];
        }
        return IDENT;
    }

    [[maybe_unused]] void Token::setType(TokenType _type) {
        type = std::move(_type);
    }

    [[maybe_unused]] std::string Token::getLiteral() const {
        return literal;
    }

    [[maybe_unused]] TokenType Token::getType() const {
        return type;
    }

} // words_memorization
// token