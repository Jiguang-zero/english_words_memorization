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
         * 从外部设置单词的创建时间
         * @param _date std::string
         */
        [[maybe_unused]] void setDate(std::string _date);

        /**
         * 从外部获取单词的显示，以供调试
         * @return std::string
         */
        std::string String();

        /**
         * 将 word 转化为字符串存储到文件中
         * @param word Word*
         * @return std::string, {word,meaning,createTime} // no extra white characters
         */
        [[maybe_unused]] static std::string getWordJson(Word* word);

        /**
         * 将 word.word 转化为 {word,createTime}
         * @param word Word*
         * @return std::string {word, createTime}
         */
        [[maybe_unused]] static std::string getWordJsonNotContent(Word* word);

        /**
         * 从 wordJson 中结构除 Word
         * > 在这里之所以使用指针，是为了实现动态分配空间，在不需要的地方可以及时释放，在需要的地方才分配
         * @param wordJson std::string, word 的JSON存储
         * @return Word*
         */
        static Word* getWordWithWordJson(const std::string& wordJson);

    private:
        /**
         * 对 wordJson 进行处理，分割成几部分，存储到 q中
         * @param q std::string*
         * @param wordJson 单词的文件存储Json格式
         * @param index int & , 为 wordJson 当前的索引
         */
        static void splitWordJson(std::string * q, const std::string & wordJson, int & index);

        /**
         * 在已经分割成几部分的单词下， 进行单词的设置
         * @param q
         * @param word
         */
        static void setTheWordWithSpiltWordJson(std::string * q, Word*& word);
    };

} // words_memorization
// words

#endif //WORDS_WORD_H
