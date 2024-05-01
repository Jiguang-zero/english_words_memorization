//
// Created by 86158 on 2024/4/28.
//

#ifndef WORDS_TRIE_H
#define WORDS_TRIE_H

#include <unordered_map>
#include "../words/Word.h"
#include <vector>

namespace words_memorization::trie {

    class Trie {
    private:
        struct TrieNode {
            int cnt; // �жϵ�ǰ�ڵ�ĵ�������
            std::unordered_map<char, TrieNode*> next;
            words::Word* word;
            explicit TrieNode() : word(nullptr), cnt(1) {};
        };
        TrieNode* root;

        /**
         * dfs ����
         * @param trieNode TrieNode*
         * @param curr std::string Ŀǰ�Ľ��
         * @param words std::vector<words::Word*>
         */
        static void dfs(TrieNode* trieNode, std::string & curr, std::vector<words::Word*> &words);

        // Ĭ�Ϲ��캯����˽��
        Trie();

        /**
         * ����������� �����ֵ������ļ��洢�ַ���
         * @param trieNode TrieNode* trieNode
         * @param ans std::string&
         */
        void dfsSetTrieFileJson(TrieNode* trieNode, std::string& ans);

    protected:
        /**
        * ����dfs������ȡ���е���
        * @return std::vector<words::Word*>
        */
        std::vector<words::Word*> allWords();

    public:
        /**
         * ���ⲿ����һ���µ� Trie
         * @return Trie*
         */
        static Trie* New();

        /**
         * �鿴�ֵ����Ƿ��е���
         * @param word const string&
         * @return Word*, ��������ڣ����ؿ�ָ��
         */
        words::Word * search(const std::string & word);

        /**
         * ���뵥�ʵ����������Լ� word* �����뵥��
         * @param wordString  string
         * @param word words::Word*
         */
        void insert(const std::string& wordString, words::Word* word);

        /**
         * ���ֵ����Ƴ�����
         * @param wordString
         * @return std::string, ���ؽ����Ϣ
         */
        std::string remove(const std::string& wordString);

        // ��ʱ�������
        void showAllWords();

        /**
         * @return std::string �����ֵ������ļ�JSON��ʽ
         */
        std::string getTrieFileJson();

        /**
         * �� trie ���ļ��洢�ַ����� ��ȡ trie
         * @param fileJson const std::string& trie���ļ��洢�ַ���, ��ʽӦ����ȷ
         * @param trie Trie*& ��Ҫ����ռ䣬��������
         */
        static void setTrieFromFileJson(const std::string& fileJson, Trie*& trie);

    };


} // words_memorization
// Trie

#endif //WORDS_TRIE_H
