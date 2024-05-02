//
// Created by 86158 on 2024/4/27.
//

#include "repl/repl.h"
#include <iostream>
#include "utils/myDate.h"
#include "trie/trie.h"
#include "trie/file.h"
#include "utils/Logger.h"


using namespace words_memorization;

int main() {
    /*
    repl::repl::Start();

    utils::myDate myDate;
    std::cout << sizeof(time_t) << std::endl;

    auto * myTrie = trie::Trie::New();
    myTrie->insert("test1", nullptr);
    myTrie->insert("test2", nullptr);
    myTrie->insert("test1", nullptr);

    auto* myWord = new words::Word("text");
    myWord->setContent("测试，名词");
    myTrie->insert(myWord->getWord(), myWord);

    myTrie->showAllWords();

    auto * a = myTrie->search("text");
    std::cout << a->String() << std::endl;

//    std::cout << myTrie->remove("te") << std::endl;
//    std::cout << myTrie->remove("text") << std::endl;

    myTrie->showAllWords();



    auto * _word = words::Word::getWordWithWordJson("{apple,名词,}");
    std::cout << _word->String() << std::endl;
    myTrie->insert(_word->getWord(), _word);

    std::string ans = myTrie->getTrieFileJson();
    std::cout << ans << std::endl;

    trie::file::getInstance()->storeTrieToFile(myTrie);

    trie::Trie *newTrie = nullptr;
    trie::file::getInstance()->getTrieFromFile(newTrie);

    if (newTrie) {
        newTrie->showAllWords();
    }
*/

    auto log1 = utils::Logger::getInstance();

    log1->info("打开文件失败");
    log1->info("关闭文件失败");

    LOG << "Test Error";

//    log->stop();

//    std::cout << utils::myDate::getFullTimeForLog() << std::endl;

    return 0;
}