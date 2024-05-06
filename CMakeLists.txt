cmake_minimum_required(VERSION 3.26)
project(englishWordsMemorization)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(englishWordsMemorization main.cpp
        repl/repl.cpp
        repl/repl.h
        words/memory.cpp
        words/memory.h
        trie/trie.cpp
        trie/trie.h
        utils/myDate.cpp
        utils/myDate.h
        words/word.cpp
        words/Word.h
        trie/file.cpp
        trie/file.h
        utils/Logger.cpp
        utils/Logger.h
        token/Token.cpp
        token/Token.h
        lexer/Lexer.cpp
        lexer/Lexer.h
        utils/Encoding.cpp
        utils/Encoding.h
        command/command.h
        command/command.cpp)