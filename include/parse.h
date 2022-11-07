#pragma once

#include "jsonException.h"
#include "json.h"
#include <string>

namespace LJson
{   
inline bool is1to9(char ch) { return ch >= '1' && ch <= '9';}
inline bool is0to9(char ch) { return ch >= '0' && ch <= '9';}


class Parser
{

public: //ctor
    explicit Parser(const char *cstr) noexcept : start(cstr), curr(cstr) {}
    explicit Parser(const std::string& content) noexcept : start(content.c_str()) ,curr(content.c_str()){}

public: //uncopyable
    Parser(const Parser&) = delete;
    Parser& operator=(const Parser&) = delete;

public:    //parse interface
    void parseWhitespace()noexcept;
    Json parseNumber();
    Json Parse_Value();
    Json ParseLiteral(const std::string &literal);
    std::string ParseRawString();
    unsigned parse4hex();
    std::string encodeUTF8(unsigned u) noexcept;

    [[noreturn]] void error(const std::string &msg) const{
        throw JsonException(msg+" "+start);
    }

public: // total parse interface
    Json Json_Parse();
    
    

private:    //private member
    const char* start;
    const char* curr;



};

}








