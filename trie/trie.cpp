//
// Created by 86158 on 2024/4/28.
//

#include "trie.h"
#include <iostream>

namespace words_memorization::trie {
    void trie::dfs(trie::TrieNode *trieNode, std::string &curr, std::vector<words::Word*> &words) { // NOLINT(*-no-recursion)
        if (trieNode->word) {
            words.emplace_back(trieNode->word);
        }
        for (const auto & p : trieNode->next) {
            curr += p.first;
            dfs(p.second, curr, words);
            curr.pop_back();
        }
    }

    std::vector<words::Word *> trie::allWords() {
        std::vector<words::Word*> words;
        std::string curr;
        dfs(root, curr, words);

        return words;
    }

    words::Word * trie::search(const std::string &word) {
        auto p = root;
        for (const char & ch : word) {
            if (p->next.count(ch)) {
                p = p->next[ch];
            }
            else {
                return nullptr;
            }
        }
        return p->word;
    }

    void trie::insert(const std::string& wordString, words::Word *word) {
        if (search(wordString) != nullptr) {
            std::cout << "The Word [" << wordString << "] ";
            std::cout << "has already existed." << std::endl;
            return;
        }
        auto p = root;
        for (const char & ch : wordString) {
            if (!p->next.count(ch)) {
                p->next[ch] = new TrieNode();
            } else {
                p->next[ch]->cnt ++;
            }
            p = p->next[ch];
        }
        if (word) {
            p->word = word;
        }
        else {
            // 如果传入的words 为空，默认添加无内容的单词
            auto * newWord = new words::Word(wordString);
            p->word = newWord;
        }
    }

    void trie::showAllWords() {
        auto words = allWords();
        for (const auto &word : words) {
            std::cout << word->getWord() << std::endl;
        }
    }

    trie *trie::New() {
        auto * resp = new trie();

        return resp;
    }

    trie::trie() {
        root = new trie::TrieNode();
    }

    std::string trie::remove(const std::string &wordString) {
        if (!search(wordString)) {
            return "The word [" + wordString + "] does not exists.";
        }
        auto p = root;
        for (const auto & ch : wordString) {
            p->next[ch]->cnt --;
            auto temp = p;
            p = p->next[ch];
            if (temp->next[ch]->cnt == 0) {
                temp->next.erase(ch);
            }
            if (temp->cnt == 0) {
                delete temp;
            }
        }
        /**
         * 关于 delete p->word, 如果 word 不是动态分配的，那么 delete 会出错
         * 于是避免后续的麻烦，这里先停止释放空间，只设为nullptr
         */
        // delete p->word;
        p->word = nullptr;
        if (p->cnt == 0) {
            delete p;
        }

        return "success deleting word [" + wordString + "].";
    }
} // words_memorization
// trie

