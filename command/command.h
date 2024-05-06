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
     * insert ���
     * [insert]: ������뵥��ģʽ
     * [insert word meaning]: ���뵥��
     */
    class InsertCommand : public virtual Command {
    private:
        token::Token token; // insert �ʷ���Ԫ
        std::string word; // ��ȱʡ
        std::string meaning; // ��ȱʡ

    public:
        InsertCommand() = default;
        InsertCommand(std::string _word, std::string _meaning) : word(std::move(_word)), meaning(std::move(_meaning)) {}

        std::string help() override;
        std::string String() override;
    };
}

#endif //WORDS_COMMAND_H
