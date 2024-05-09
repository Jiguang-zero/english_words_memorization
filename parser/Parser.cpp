//
// Created by 86158 on 2024/5/6.
//

#include "Parser.h"


namespace words_memorization::parser {
    Parser *Parser::New(lexer::Lexer *lexer) {
        auto* parser = new Parser(lexer);
        parser->nextToken();

        parser->registerParseCommandFunctions(token::Token::INSERT_COMMAND, &Parser::parseInsertCommand);

        return parser;
    }

    command::Commands *Parser::parseCommand() {
        if (!peekTokenIs(token::Token::SLASH)) {
            // 非命令格式
            return nullptr;
        }
        auto * commands = new command::Commands(peekToken);
        nextToken();

        commands->setCommands(parseCommands());

        return commands;
    }

    void Parser::nextToken() {
        currToken = peekToken;
        peekToken = lexer->NextToken();
    }

    bool Parser::currTokenIs(const token::TokenType &t) {
        return currToken.getType() == t;
    }

    bool Parser::peekTokenIs(const token::TokenType &t) {
        return peekToken.getType() == t;
    }

    /**
     *
     * @return
     */
    std::vector<command::Command *> Parser::parseCommands() {
        std::vector<command::Command *> res;

        while (!currTokenIs(token::Token::TOKEN_EOF)) {
            if (currTokenIs(token::Token::SLASH) || currTokenIs(token::Token::VERTICAL)) {
                nextToken();
                continue;
            }
            parseCommands(res);
        }

        return res;
    }

    void Parser::parseCommands(std::vector<command::Command *> &commands) {
        auto fn = parseCommandsFns[currToken.getType()];
        if (fn == nullptr) {
            return;
        }

        auto * command = (this->*fn)();
        if (command != nullptr) {
            commands.emplace_back(command);
        }
    }

    void Parser::registerParseCommandFunctions(const token::TokenType &type, parseCommandFn fn) {
        parseCommandsFns[type] = fn;
    }

    // currToken: insert
    command::Command *Parser::parseInsertCommand() {
        auto * insertCommand = new command::InsertCommand(currToken);
        nextToken();

        std::string word, meaning;
        // 下一个是单词 insert word meaning
        if (currTokenIs(token::Token::IDENT)) {
            word = currToken.getLiteral();
            nextToken();
        }

        // meaning
        if (currTokenIs(token::Token::IDENT)) {
            meaning = currToken.getLiteral();
            nextToken();
        }

        if (currTokenIs(token::Token::VERTICAL) || currTokenIs(token::Token::TOKEN_EOF)) {
            // 正确格式
            insertCommand->setWord(word);
            insertCommand->setMeaning(meaning);

            return dynamic_cast<command::Command*>(insertCommand);
        }
        else {
            while (!(currTokenIs(token::Token::VERTICAL) || currTokenIs(token::Token::TOKEN_EOF))) {
                nextToken();
            }

            return nullptr;
        }
    }
} // words_memorization
// Parser