//
// Created by 86158 on 2024/5/6.
//

#ifndef WORDS_PARSER_H
#define WORDS_PARSER_H

#include "../lexer/Lexer.h"
#include "../command/command.h"

#include <unordered_map>


namespace words_memorization::parser {
    using std::unordered_map;

    class Parser;

    /**
     * ������Parser���� ����command::Command* ������Ϊ�յĺ�����ָ��Ϊ parseCommandFn
     */
    typedef command::Command* (Parser::*parseCommandFn)();

    class Parser {
    private:
        lexer::Lexer* lexer;
        token::Token currToken; // ��ǰ�ʷ���Ԫ
        token::Token peekToken; // ��һ���ʷ���Ԫ

        // ���������
        unordered_map<token::TokenType , parseCommandFn > parseCommandsFns;

        explicit Parser(lexer::Lexer* _lexer) {
            lexer = _lexer;
        }

        /**
         * ���������������TokenType ��Ӧ����
         * @param type
         * @param fn
         */
        void registerParseCommandFunctions(const token::TokenType & type, parseCommandFn fn);

        /**
         * ���� insert ����
         * @return command::Command*
         */
        command::Command* parseInsertCommand();

        /**
         * ���� token
         */
        void nextToken();

        /**
         * �жϵ�ǰtoken�������Ƿ�����Ҫ��һ��
         * @param t
         * @return
         */
        bool currTokenIs(const token::TokenType& t);

        /**
         * �ж���һ��token�������Ƿ�����Ҫ��һ��
         * @param t
         * @return
         */
        bool peekTokenIs(const token::TokenType& t);

        /**
         * �����������Commands.commands
         * @return std::vector <command::Command*>
         */
        std::vector<command::Command*> parseCommands();

        /**
         * ��������
         * @param commands std::vector<command::Command*>&
         */
        void parseCommands(std::vector<command::Command*>& commands);


    public:
        /**
         * parse commands
         * the entrance of parser
         * @return Command*
         */
        command::Commands* parseCommand();

        /**
         * ��̬����һ�� parser
         * @param lexer lexer::Lexer*
         * @return Parser*
         */
        static Parser* New(lexer::Lexer* lexer);
    };

} // words_memorization
// Parser

#endif //WORDS_PARSER_H
