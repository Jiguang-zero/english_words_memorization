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
        // �ʷ���Ԫ��������
        std::string literal;
        TokenType type;

    private:
        static std::unordered_map<std::string, TokenType> keywords;

    public:
        /**
         * Ĭ�Ϲ��캯��
         */
        Token() = default;

        /**
         * ���캯��
         * @param _literal std::string �ʷ���Ԫ��������
         * @param _type TokenType �ʷ���Ԫ������
         */
        Token(std::string _literal, TokenType _type) : literal(std::move(_literal)), type(std::move(_type)) {};

        [[maybe_unused]] void setLiteral(std::string _literal);
        [[maybe_unused]] void setType(TokenType _type);
        [[maybe_unused]] [[nodiscard]] std::string getLiteral() const;
        [[maybe_unused]] [[nodiscard]] TokenType getType() const;

        /**
         * ���ҹؼ���
         * @param ident  const std::string&
         * @return TokenType
         */
        static TokenType LookupIdent(const std::string& ident);

    public:
        // ����
        const static TokenType SLASH; // "/" б�ߣ�����Ŀ�ʼ
        const static TokenType COMMA; // ",", �ָ�
        const static TokenType MINUS; // "-" ���ţ���ܣ�ѡ��Ŀ�ʼ
        const static TokenType VERTICAL; // "|�� ���� �ָͬѡ��

        // ��ʶ��
        const static TokenType IDENT; // ���ý��������÷�����ʶ������ʾһ������(�����ǵ���)
        const static TokenType DATE; // ����
        const static TokenType TOKEN_EOF; // ����
        const static TokenType OPTION; // option, the option of the command
        const static TokenType STRING; // �ַ��� ��""����������

        // �ؼ���
        const static TokenType INSERT_COMMAND; // "insert" ����
        const static TokenType SELECT_COMMAND; // "select" ����
        const static TokenType MODIFY_COMMAND; // "modify" ����
    };

} // words_memorization

// token

#endif //WORDS_TOKEN_H
