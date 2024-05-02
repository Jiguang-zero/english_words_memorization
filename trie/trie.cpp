//
// Created by 86158 on 2024/4/28.
//

#include "trie.h"
#include <iostream>

namespace words_memorization::trie {
    void Trie::dfs(Trie::TrieNode *trieNode, std::string &curr, std::vector<words::Word*> &words) { // NOLINT(*-no-recursion)
        if (trieNode->word) {
            words.emplace_back(trieNode->word);
        }
        for (const auto & p : trieNode->next) {
            curr += p.first;
            dfs(p.second, curr, words);
            curr.pop_back();
        }
    }

    std::vector<words::Word *> Trie::allWords() {
        std::vector<words::Word*> words;
        std::string curr;
        dfs(root, curr, words);

        return words;
    }

    words::Word * Trie::search(const std::string &word) {
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

    void Trie::insert(const std::string& wordString, words::Word *word) {
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
            // ��������words Ϊ�գ�Ĭ����������ݵĵ���
            auto * newWord = new words::Word(wordString);
            p->word = newWord;
        }
    }

    void Trie::showAllWords() {
        auto words = allWords();
        for (const auto &word : words) {
            std::cout << word->getWord() << std::endl;
        }
    }

    Trie *Trie::New() {
        auto * resp = new Trie();

        return resp;
    }

    Trie::Trie() {
        root = new Trie::TrieNode();
    }

    std::string Trie::remove(const std::string &wordString) {
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
         * ���� delete p->word, ��� word ���Ƕ�̬����ģ���ô delete �����
         * ���Ǳ���������鷳��������ֹͣ�ͷſռ䣬ֻ��Ϊnullptr
         */
        // delete p->word;
        p->word = nullptr;
        if (p->cnt == 0) {
            delete p;
        }

        return "success deleting word [" + wordString + "].";
    }

    void Trie::dfsSetTrieFileJson(TrieNode* trieNode, std::string &ans) { // NOLINT(*-no-recursion)
        if (!trieNode) {
            return;
        }
        ans += "(";
        if (trieNode->word) {
            ans += words::Word::getWordJson(trieNode->word);
        }
        for (const auto & p : trieNode->next) {
            ans += std::string(1, p.first);
            dfsSetTrieFileJson(p.second, ans);
        }
        ans += ")";
    }

    std::string Trie::getTrieFileJson() {
        std::string res;
        dfsSetTrieFileJson(root, res);
        return res;
    }

    /**
     * ͵����ֱ�ӵ��� insert ������Ч�ʽϵͣ����Ż�
     */
    void Trie::setTrieFromFileJson(const std::string &fileJson, Trie *& trie) {
        trie = new Trie();
        for (int index = 0; index < fileJson.length(); index ++ ) {
            while (index < fileJson.length() && fileJson[index] != '{') {
                index ++;
            }
            if (index >= fileJson.length()) {
                break;
            }
            int start(index);
            while (index < fileJson.length() && fileJson[index] != '}') {
                index ++;
            }
            if (index >= fileJson.length()) {
                break;
            }
            int end(index);
            auto wordJson = fileJson.substr(start, end - start);
            words::Word* word = words::Word::getWordWithWordJson(wordJson);
            trie->insert(word->getWord(), word);
        }
    }
} // words_memorization
// Trie

