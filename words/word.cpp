//
// Created by 86158 on 2024/4/28.
//

#include <utility>

#include "Word.h"
#include <sstream>
#include <iostream>


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

    [[maybe_unused]] std::string Word::getWordJson(Word *word) {
        if (word == nullptr) {
            return "";
        }
        std::ostringstream oss;
        oss << "{";
        oss << word->word << ",";
        oss << word->content << ",";
        oss << word->date;
        oss << "}";
        return oss.str();
    }

    Word *Word::getWordWithWordJson(const std::string& wordJson) {
        Word* word;
        int index = 0;
        if (wordJson[index ++ ] != '{') {
            //TODO: 格式不正确，返回空指针
            return nullptr;
        }
        std::string q[3] = {""}; // 静态数组,存储
        splitWordJson(q, wordJson, index);

        if (q[0].empty()) {
            // 单词内容不能为空，单词错误，返回空指针
            return nullptr;
        }

        setTheWordWithSpiltWordJson(q, word);

        return word;
    }

    [[maybe_unused]] void Word::setDate(std::string _date) {
        date = std::move(_date);
    }

    void Word::splitWordJson(std::string *q, const std::string &wordJson, int &index) {
        for (int q_i = 0 ; index < wordJson.length(); index ++) {
            if (index == wordJson.length() - 1 && wordJson[index] != '{') {
                //TODO: 格式错误
                break;
            }
            if (wordJson[index] == '}') {
                if (index != wordJson.length() - 1) {
                    //TODO: 日志处理，多余的文件保存
                }
                break;
            }
            if (wordJson[index] == ',') {
                // 可能单词内容为空
                q_i ++;
                continue;
            }
            if (q_i >= 3) {
                //TODO: 日志文件存储: wordJson 有额外的存储， 不止3项
                break;
            }
            auto start = index;
            while (index < wordJson.length() && wordJson[index] != ',') {
                index ++;
            }
            auto end = index;
            q[q_i ++ ] = wordJson.substr(start, end - start);
        }
    }

    void Word::setTheWordWithSpiltWordJson(std::string *q, Word *&word) {
        word = new Word(q[0]);
        if (!q[1].empty()) {
            word->setContent(q[1]);
        }
        if (!q[2].empty()) {
            word->setDate(q[2]);
        }
    }

    std::string Word::getWordJsonNotContent(Word *word) {
        std::ostringstream oss;
        oss << "{";
        oss << word->getWord() << ",";
        oss << word->getDate();
        oss << "}";
        return oss.str();
    }


} // words_memorization
// words