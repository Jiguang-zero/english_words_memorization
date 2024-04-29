//
// Created by 86158 on 2024/4/28.
//

#include <utility>

#include "Word.h"
#include <sstream>


namespace words_memorization::words {
    Word::Word(std::string _word) {
        word = std::move(_word);
    }

    [[maybe_unused]] void Word::setContent(std::string _content) {
        content = std::move(_content);
    }

    std::string Word::String() {
        std::ostringstream  oss;
        oss << "Word: " << word << std::endl;
        oss << "Meaning: " << content << std::endl;
        oss << "Date: " << date << std::endl;
        return oss.str();
    }
} // words_memorization
// words