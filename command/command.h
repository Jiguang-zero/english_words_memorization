//
// Created by 86158 on 2024/5/6.
//

#ifndef WORDS_COMMAND_H
#define WORDS_COMMAND_H

#include <utility>
#include <string>
#include <vector>

#include "../token/Token.h"

namespace words_memorization::command {
    // virtual class
    class Command {
    public:
        virtual std::string String() = 0;

        [[maybe_unused]] virtual std::string help() = 0;
    };

    /**
     * insert 命令：
     * [insert]: 进入插入单词模式
     * [insert word meaning]: 插入单词
     */
    class InsertCommand : public virtual Command {
    private:
        token::Token token; // insert 词法单元
        std::string word; // 可缺省
        std::string meaning; // 可缺省

    public:
        InsertCommand() = default;
        explicit InsertCommand(token::Token _token) : token(std::move(_token)) {}

        [[maybe_unused]] InsertCommand(std::string _word, std::string _meaning) : word(std::move(_word)), meaning(std::move(_meaning)) {}

        [[maybe_unused]] void setWord(const std::string& _word);

        [[maybe_unused]] void setMeaning(const std::string& _meaning);

        std::string help() override;
        std::string String() override;
    };

    /**
     * entrance
     */
    class Commands : public virtual Command {
    private:
        token::Token token; // "/"
        std::vector<Command*> commands;

    public:
        Commands() = default;
        explicit Commands(token::Token _token) : token(std::move(_token)) {}

        /**
         * set the commands of Commands out of class.
         * @param _commands std::vector<Command *>
         */
        [[maybe_unused]] void setCommands(std::vector<Command *> _commands);

        /**
         * get the commands of Commands
         * @return
         */
        [[maybe_unused]] [[nodiscard]] std::vector<Command*> getCommands() const;


        std::string help() override;
        std::string String() override;
    };


}

#endif //WORDS_COMMAND_H
