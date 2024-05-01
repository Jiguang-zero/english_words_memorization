//
// Created by 86158 on 2024/4/30.
//

#include "file.h"
#include <iostream>
#include <filesystem>

namespace words_memorization::trie {
    // ��ʼ������
    file *file::instance = new file();

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
        std::filesystem::path folderPath = "resource";
        if (!std::filesystem::exists(folderPath)) {
            if (!std::filesystem::create_directories(folderPath)) {
                //TODO: �����ļ��д���
            }
        }

        outFile.open("resource/dictionary_all.dic.tree");
        outFile << trieFileFileJson;

        // �ر��ļ�
        outFile.close();
    }

    void file::getTrieFromFile(Trie *&trie) {
        std::string fileJson;

        inFile.open("resource/dictionary_all.dic.tree");
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

        std::cout << "55: " << fileJson << std::endl;
        Trie::setTrieFromFileJson(fileJson, trie);

        // �ع� trie
    }


} // words_memorization
// Trie