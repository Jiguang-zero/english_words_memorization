//
// Created by 86158 on 2024/5/6.
//

#include "command.h"
#include "sstream"

std::string words_memorization::command::InsertCommand::help() {
    std::ostringstream oss;

    oss << "insert <word> <meaning> " << std::endl;
    oss << "word and meaning can be null." << std::endl;
    oss << "You can use insert to enter insert mode and full command to insert one word." << std::endl;

    return oss.str();
}

std::string words_memorization::command::InsertCommand::String() {
    std::string res = "insert";

    if (!word.empty() && !meaning.empty()) {
        res += " " + word + " " + meaning;
    }

    return res;
}
