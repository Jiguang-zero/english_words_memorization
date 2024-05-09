//
// definite token
// Created by 86158 on 2024/5/3.
//

#ifndef WORDS_TOKEN_H
#define WORDS_TOKEN_H

#include <string>
#include <unordered_map>
#include <utility>

namespace words_memorization::token {
    typedef std::string TokenType;


    class Token {
    public:
        // 词法单元的字面量
        std::string literal;
        TokenType type;

    private:
        static std::unordered_map<std::string, TokenType> keywords;

    public:
        /**
         * 默认构造函数
         */
        Token() = default;

        /**
         * 构造函数
         * @param _literal std::string 词法单元的字面量
         * @param _type TokenType 词法单元的类型
         */
        Token(std::string _literal, TokenType _type) : literal(std::move(_literal)), type(std::move(_type)) {};

        [[maybe_unused]] void setLiteral(std::string _literal);
        [[maybe_unused]] void setType(TokenType _type);
        [[maybe_unused]] [[nodiscard]] std::string getLiteral() const;
        [[maybe_unused]] [[nodiscard]] TokenType getType() const;

        /**
         * 查找关键字
         * @param ident  const std::string&
         * @return TokenType
         */
        static TokenType LookupIdent(const std::string& ident);

    public:
        // 符号
        const static TokenType SLASH; // "/" 斜线，命令的开始
        const static TokenType COMMA; // ",", 分割
        const static TokenType MINUS; // "-" 减号，横杠，选项的开始
        const static TokenType VERTICAL; // "|“ 竖线 分割不同选项

        // 标识符
        const static TokenType IDENT; // 沿用解释器的用法，标识符，表示一个整体(可能是单词)
        const static TokenType DATE; // 日期
        const static TokenType TOKEN_EOF; // 结束
        const static TokenType OPTION; // option, the option of the command
        const static TokenType STRING; // 字符串 用""包括在其中

        // 关键字
        const static TokenType INSERT_COMMAND; // "insert" 命令
        const static TokenType SELECT_COMMAND; // "select" 命令
        const static TokenType MODIFY_COMMAND; // "modify" 命令
    };

} // words_memorization

// token

#endif //WORDS_TOKEN_H
