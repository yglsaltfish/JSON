#pragma once

#include "jsonException.h"
#include "json.h"
#include <string>

namespace LJson
{   
inline bool is1to9(char ch) { return ch >= '1' && ch <= '9';}
inline bool is0to9(char ch) { return ch >= '0' && ch <= '9';}


class Parser final
{

public: //ctor
    explicit Parser(const char *cstr) noexcept : start(cstr), curr(cstr) {}
    explicit Parser(const std::string& content) noexcept : start(content.c_str()) ,curr(content.c_str()){}

public: //uncopyable
    Parser(const Parser&) = delete;
    Parser& operator=(const Parser&) = delete;

public:    //parse interface
    Json ParseValue();
    Json ParseLiteral(const std::string &literal);
    Json ParseNumber();
    Json ParseString() { return Json(ParseRawString()); }
    std::string ParseRawString();
    unsigned Parse4hex();
    std::string encodeUTF8(unsigned u) noexcept;
    Json ParseArray();
    Json ParseObject();
    void ParseWhitespace() noexcept;

    [[noreturn]] void error(const std::string &msg) const{
        throw JsonException(msg + " " + start);
    }

public: // total parse interface
    Json Json_Parse();
    
    

private:    //private member
    const char* start;
    const char* curr;



};

}








