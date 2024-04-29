//
// Created by 86158 on 2024/4/28.
//

#ifndef WORDS_WORD_H
#define WORDS_WORD_H

#include <string>

namespace words_memorization::words {

    class Word {
    private:
        std::string word;
        std::string content;
        std::string date;
    public:
        [[maybe_unused]] [[nodiscard]] std::string getWord() const { return word; }
        [[maybe_unused]] [[nodiscard]] std::string getContent() const { return content; }
        [[maybe_unused]] [[nodiscard]] std::string getDate() const { return date; }

        /**
         * 构造函数，传入字符串单词
         * @param _word this->word = _word; string
         */
        explicit Word(std::string _word);

        /**
         * 从外部设置单词的含义
         * @param _content std::string this->content = _content
         */
        [[maybe_unused]] void setContent(std::string _content);

        /**
         * 从外部获取单词的显示
         * @return std::string
         */
        std::string String();
    };

} // words_memorization
// words

#endif //WORDS_WORD_H
