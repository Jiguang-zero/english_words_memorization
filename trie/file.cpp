//
// Created by 86158 on 2024/4/30.
//

#include "file.h"
#include <iostream>
#include <filesystem>

namespace words_memorization::trie {
    // ��ʼ������
    file *file::instance = new file();

    const char* file::DICTIONARY_ALL_TREE = "resource/dictionary_all.dic.tree";
    const char* file::DICTIONARY_PATH = "resource";

    file *file::getInstance() {
        return instance;
    }

    /**
     * ������Ƴ��ڲ�Ӧ�ù����Ż���ԭ���ʼ�����еĵ��ʵ��������ݶ��洢���ļ���
     * δ�����Խ����Ż�: �����ʵ� meaning �ָ���洢����Ӧ�Ĵʵ��У�����Ҳ�����ֶ���Ӵʵ�
     * @param trie
     */
    void file::storeTrieToFile(Trie *trie) {
        auto trieFileFileJson = trie->getTrieFileJson();

        // ��Դ�ļ��� resource
        std::filesystem::path folderPath = DICTIONARY_PATH;
        if (!std::filesystem::exists(folderPath)) {
            if (!std::filesystem::create_directories(folderPath)) {
                //TODO: �����ļ��д���
            }
        }

        outFile.open(DICTIONARY_ALL_TREE);
        outFile << trieFileFileJson;

        // �ر��ļ�
        outFile.close();
    }

    void file::getTrieFromFile(Trie *&trie) {
        std::string fileJson;

        inFile.open(DICTIONARY_ALL_TREE);
        if (!inFile.is_open()) {
            //TODO:: ������
            return;
        }
        inFile >> fileJson;
        inFile.close();
        if (inFile.is_open()) {
            //TODO: �������ļ��޷��ر�
            return;
        }

        // �ع� trie
        Trie::setTrieFromFileJson(fileJson, trie);
    }


} // words_memorization
// Trie