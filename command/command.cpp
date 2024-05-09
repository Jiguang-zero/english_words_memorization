//
// Created by 86158 on 2024/5/6.
//

#include "command.h"

#include <utility>
#include "sstream"

namespace words_memorization::command {
    std::string InsertCommand::help() {
        std::ostringstream oss;

        oss << "insert <word> <meaning> " << std::endl;
        oss << "word and meaning can be null." << std::endl;
        oss << "You can use insert to enter insert mode and full command to insert one word." << std::endl;

        return oss.str();
    }

    std::string InsertCommand::String() {
        std::string res = "insert";

        if (!word.empty() && !meaning.empty()) {
            res += " " + word + " " + meaning;
        }

        return res;
    }

    [[maybe_unused]] void InsertCommand::setWord(const std::string &_word) {
        this->word = _word;
    }

    [[maybe_unused]] void InsertCommand::setMeaning(const std::string &_meaning) {
        this->meaning = _meaning;
    }

    std::string Commands::help() {
        return std::string();
    }

    std::string Commands::String() {
        return std::string();
    }

    [[maybe_unused]] void Commands::setCommands(std::vector<Command *> _commands) {
        this->commands = std::move(_commands);
    }

    [[maybe_unused]] std::vector<Command *> Commands::getCommands() const {
        return commands;
    }
}
