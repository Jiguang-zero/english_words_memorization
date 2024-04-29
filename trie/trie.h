//
// Created by 86158 on 2024/4/28.
//

#ifndef WORDS_TRIE_H
#define WORDS_TRIE_H

#include <unordered_map>
#include "../words/Word.h"
#include <vector>

namespace words_memorization::trie {

    class trie {
    private:
        struct TrieNode {
            int cnt; // 判断当前节点的单词数量
            std::unordered_map<char, TrieNode*> next;
            words::Word* word;
            explicit TrieNode() : word(nullptr), cnt(1) {};
        };
        TrieNode* root;

        /**
         * dfs 遍历
         * @param trieNode TrieNode*
         * @param curr std::string 目前的结果
         * @param words std::vector<words::Word*>
         */
        static void dfs(TrieNode* trieNode, std::string & curr, std::vector<words::Word*> &words);

        /**
         * 调用dfs函数获取所有单词
         * @return std::vector<words::Word*>
         */
        std::vector<words::Word*> allWords();

        // 默认构造函数，私有
        trie();

    public:
        /**
         * 从外部构造一个新的 trie
         * @return trie*
         */
        static trie* New();

        /**
         * 查看字典树是否有单词
         * @param word const string&
         * @return Word*, 如果不存在，返回空指针
         */
        words::Word * search(const std::string & word);

        /**
         * 传入单词的字面意义以及 word* ，插入单词
         * @param wordString  string
         * @param word words::Word*
         */
        void insert(const std::string& wordString, words::Word* word);

        /**
         * 从字典树移除单词
         * @param wordString
         * @return std::string, 返回结果信息
         */
        std::string remove(const std::string& wordString);

        // 临时输出测试
        void showAllWords();

    };


} // words_memorization
// trie

#endif //WORDS_TRIE_H
