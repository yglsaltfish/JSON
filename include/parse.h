#pragma once

#include "jsonException.h"
#include "json.h"
#include <string>

namespace LJson
{
inline bool is1to9(char ch) { return ch >= '1' && ch <= '9';}
inline bool is0to9(char ch) { return ch >= '0' && ch <= '9';}


class Parser{

public: //ctor
    explicit Parser(const char *cstr) noexcept : _start(cstr), _curr(cstr) {}
    explicit Parser(const std::string& content) noexcept : _start(content.c_str()) ,_curr(content.c_str()){}

public: //uncopyable
    Parser(const Parser&) = delete;
    Parser& operator=(const Parser&) = delete;

public:    //parse interface
    void parseWhitespace()noexcept;
    Json parseNumber();
    Json Parse_Value();
    Json ParseLiteral(const std::string &literal);
    std::string ParseRawString();

    [[noreturn]] void error(const std::string &msg) const{
        throw JsonException(msg+" "+_start);
    }

public: // total parse interface
    Json Json_Parse();
    

    

private:    //private member
    const char* _start;
    const char* _curr;



};

}








