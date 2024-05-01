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
         * ���캯���������ַ�������
         * @param _word this->word = _word; string
         */
        explicit Word(std::string _word);

        /**
         * ���ⲿ���õ��ʵĺ���
         * @param _content std::string this->content = _content
         */
        [[maybe_unused]] void setContent(std::string _content);

        /**
         * ���ⲿ���õ��ʵĴ���ʱ��
         * @param _date std::string
         */
        [[maybe_unused]] void setDate(std::string _date);

        /**
         * ���ⲿ��ȡ���ʵ���ʾ���Թ�����
         * @return std::string
         */
        std::string String();

        /**
         * �� word ת��Ϊ�ַ����洢���ļ���
         * @param word Word*
         * @return std::string, {word,meaning,createTime} // no extra white characters
         */
        [[maybe_unused]] static std::string getWordJson(Word* word);

        /**
         * �� word.word ת��Ϊ {word,createTime}
         * @param word Word*
         * @return std::string {word, createTime}
         */
        [[maybe_unused]] static std::string getWordJsonNotContent(Word* word);

        /**
         * �� wordJson �нṹ�� Word
         * > ������֮����ʹ��ָ�룬��Ϊ��ʵ�ֶ�̬����ռ䣬�ڲ���Ҫ�ĵط����Լ�ʱ�ͷţ�����Ҫ�ĵط��ŷ���
         * @param wordJson std::string, word ��JSON�洢
         * @return Word*
         */
        static Word* getWordWithWordJson(const std::string& wordJson);

    private:
        /**
         * �� wordJson ���д����ָ�ɼ����֣��洢�� q��
         * @param q std::string*
         * @param wordJson ���ʵ��ļ��洢Json��ʽ
         * @param index int & , Ϊ wordJson ��ǰ������
         */
        static void splitWordJson(std::string * q, const std::string & wordJson, int & index);

        /**
         * ���Ѿ��ָ�ɼ����ֵĵ����£� ���е��ʵ�����
         * @param q
         * @param word
         */
        static void setTheWordWithSpiltWordJson(std::string * q, Word*& word);
    };

} // words_memorization
// words

#endif //WORDS_WORD_H
