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
     * 定义在Parser类中 返回command::Command* ，参数为空的函数的指针为 parseCommandFn
     */
    typedef command::Command* (Parser::*parseCommandFn)();

    class Parser {
    private:
        lexer::Lexer* lexer;
        token::Token currToken; // 当前词法单元
        token::Token peekToken; // 下一个词法单元

        // 解析命令函数
        unordered_map<token::TokenType , parseCommandFn > parseCommandsFns;

        explicit Parser(lexer::Lexer* _lexer) {
            lexer = _lexer;
        }

        /**
         * 将命令解析函数和TokenType 对应起来
         * @param type
         * @param fn
         */
        void registerParseCommandFunctions(const token::TokenType & type, parseCommandFn fn);

        /**
         * 解析 insert 命令
         * @return command::Command*
         */
        command::Command* parseInsertCommand();

        /**
         * 更新 token
         */
        void nextToken();

        /**
         * 判断当前token的类型是否与想要的一样
         * @param t
         * @return
         */
        bool currTokenIs(const token::TokenType& t);

        /**
         * 判断下一个token的类型是否与想要的一样
         * @param t
         * @return
         */
        bool peekTokenIs(const token::TokenType& t);

        /**
         * 解析命令，解析Commands.commands
         * @return std::vector <command::Command*>
         */
        std::vector<command::Command*> parseCommands();

        /**
         * 解析命令
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
         * 静态构造一个 parser
         * @param lexer lexer::Lexer*
         * @return Parser*
         */
        static Parser* New(lexer::Lexer* lexer);
    };

} // words_memorization
// Parser

#endif //WORDS_PARSER_H
