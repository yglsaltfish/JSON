#pragma once

#include "json.h"
#include "jsonException.h"
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

private:    //parse interface
    void parseWhitespace()noexcept;





private:    //private member
    const char* _start;
    const char* _curr;

};

}








