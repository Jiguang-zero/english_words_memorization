//
// Created by 86158 on 2024/4/30.
//

#ifndef WORDS_FILE_H
#define WORDS_FILE_H

#include <fstream>
#include "trie.h"

namespace words_memorization::trie {

    /**
     * 用于字典的持久化
     * 将 Trie 存储成文件
     * 将文件重构为 Trie
     */
    class file {
    private:
        file() = default;
        ~file() = default;

        // 创建单例
        static file* instance;

    public:
        // 禁止复制
        const file &operator=(const file & _file) = delete;
        file(const file& _file) = delete;

    private:
        std::ofstream outFile;
        std::ifstream inFile;

    public:
        /**
         * 获取单例
         * @return file*
         */
        static file * getInstance();

        /**
         * 将字典树存储成文件
         * @param trie Trie*, 字典树指针
         */
        void storeTrieToFile(Trie* trie);

        /**
         * 从文件中读取 字典树
         * @param trie Trie*& 需要对trie进行重新分配空间
         */
        void getTrieFromFile(Trie*& trie);

    private:

    };

} // words_memorization
// Trie

#endif //WORDS_FILE_H
