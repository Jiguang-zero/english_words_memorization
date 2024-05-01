//
// Created by 86158 on 2024/4/30.
//

#ifndef WORDS_FILE_H
#define WORDS_FILE_H

#include <fstream>
#include "trie.h"

namespace words_memorization::trie {

    /**
     * �����ֵ�ĳ־û�
     * �� Trie �洢���ļ�
     * ���ļ��ع�Ϊ Trie
     */
    class file {
    private:
        file() = default;
        ~file() = default;

        // ��������
        static file* instance;

    public:
        // ��ֹ����
        const file &operator=(const file & _file) = delete;
        file(const file& _file) = delete;

    private:
        std::ofstream outFile;
        std::ifstream inFile;

    public:
        /**
         * ��ȡ����
         * @return file*
         */
        static file * getInstance();

        /**
         * ���ֵ����洢���ļ�
         * @param trie Trie*, �ֵ���ָ��
         */
        void storeTrieToFile(Trie* trie);

        /**
         * ���ļ��ж�ȡ �ֵ���
         * @param trie Trie*& ��Ҫ��trie�������·���ռ�
         */
        void getTrieFromFile(Trie*& trie);

    private:

    };

} // words_memorization
// Trie

#endif //WORDS_FILE_H
