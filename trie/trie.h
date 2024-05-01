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

        // 默认构造函数，私有
        Trie();

        /**
         * 深度优先搜索 设置字典树的文件存储字符串
         * @param trieNode TrieNode* trieNode
         * @param ans std::string&
         */
        void dfsSetTrieFileJson(TrieNode* trieNode, std::string& ans);

    protected:
        /**
        * 调用dfs函数获取所有单词
        * @return std::vector<words::Word*>
        */
        std::vector<words::Word*> allWords();

    public:
        /**
         * 从外部构造一个新的 Trie
         * @return Trie*
         */
        static Trie* New();

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

        /**
         * @return std::string 整个字典树的文件JSON格式
         */
        std::string getTrieFileJson();

        /**
         * 从 trie 的文件存储字符串中 读取 trie
         * @param fileJson const std::string& trie的文件存储字符串, 格式应该正确
         * @param trie Trie*& 需要分配空间，传入引用
         */
        static void setTrieFromFileJson(const std::string& fileJson, Trie*& trie);

    };


} // words_memorization
// Trie

#endif //WORDS_TRIE_H
