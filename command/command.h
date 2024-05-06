//
// Created by 86158 on 2024/5/6.
//

#ifndef WORDS_COMMAND_H
#define WORDS_COMMAND_H

#include <utility>
#include <string>

#include "../token/Token.h"

namespace words_memorization::command {
    // virtual class
    class Command {
    public:
        virtual std::string String() = 0;
        virtual std::string help() = 0;
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
        InsertCommand(std::string _word, std::string _meaning) : word(std::move(_word)), meaning(std::move(_meaning)) {}

        std::string help() override;
        std::string String() override;
    };
}

#endif //WORDS_COMMAND_H
