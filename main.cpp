//
// Created by 86158 on 2024/4/27.
//

#include "repl/repl.h"
#include <iostream>
#include "utils/myDate.h"
#include "utils/Encoding.h"
#include "trie/trie.h"
#include "trie/file.h"
#include "token/Token.h"
#include "utils/Logger.h"
#include "lexer/Lexer.h"

#include <cstdlib>
#include <ctime>

using namespace words_memorization;

void test();
void test(std::string a);

int main(int argc, char** argv) {
    if (argc == 2) {
        test(argv[1]);
    }
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


    auto log1 = utils::Logger::getInstance();

    log1->info("打开文件失败");
    log1->info("关闭文件失败");

    LOG << "Test Error";
*/
//    log->stop();

    bool a = utils::myDate::isDate("2024-24-23");
    bool b = utils::myDate::isDate("2024-10-3");

    std::cout << utils::myDate::dow(2024, 6, 8) << std::endl;




//    std::cout << utils::myDate::getFullTimeForLog() << std::endl;
    test();


    return 0;
}

void test() {
    srand(static_cast<unsigned int>(time(nullptr)));

    auto isLeap = [] (int year) -> bool {
        return (year / 4 - year / 100 + year / 400) == 1;
    };

    for (int i = 0; i < 10; i ++ ) {
        int year = rand() % 1000 + 1500;
        std::cout << year << ": ";
        std::cout << (isLeap(year) ? "leap" : "common") << std::endl;
    }
}

void test(std::string a) {

    auto * l = lexer::Lexer::New(a);

    auto t = l->NextToken();

    while (t.getType() != token::Token::TOKEN_EOF) {
        std::cout << t.getLiteral() << ' ' << t.getType() << std::endl;
        t = l->NextToken();
    }

}