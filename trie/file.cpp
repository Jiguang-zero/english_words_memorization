//
// Created by 86158 on 2024/4/30.
//

#include "file.h"
#include <iostream>
#include <filesystem>

namespace words_memorization::trie {
    // 初始化单例
    file *file::instance = new file();

    file *file::getInstance() {
        return instance;
    }

    /**
     * 秉着设计初期不应该过度优化的原则，最开始将所有的单词的所有内容都存储到文件中
     * 未来可以进行优化: 将单词的 meaning 分割处理，存储到对应的词典中，这样也可以手动添加词典
     * @param trie
     */
    void file::storeTrieToFile(Trie *trie) {
        auto trieFileFileJson = trie->getTrieFileJson();

        // 资源文件夹 resource
        std::filesystem::path folderPath = "resource";
        if (!std::filesystem::exists(folderPath)) {
            if (!std::filesystem::create_directories(folderPath)) {
                //TODO: 创建文件夹错误
            }
        }

        outFile.open("resource/dictionary_all.dic.tree");
        outFile << trieFileFileJson;

        // 关闭文件
        outFile.close();
    }

    void file::getTrieFromFile(Trie *&trie) {
        std::string fileJson;

        inFile.open("resource/dictionary_all.dic.tree");
        if (!inFile.is_open()) {
            //TODO:: 报错处理
            return;
        }
        inFile >> fileJson;
        inFile.close();
        if (inFile.is_open()) {
            //TODO: 报错处理，文件无法关闭
            return;
        }

        std::cout << "55: " << fileJson << std::endl;
        Trie::setTrieFromFileJson(fileJson, trie);

        // 重构 trie
    }


} // words_memorization
// Trie