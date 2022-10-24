#include "parse.h"
#include "jsonException.h"
#include <cassert>
#include <cstring>
#include <stdexcept>

namespace LJson
{

void Parser::parseWhitespace() noexcept{
    while (*_curr == ' '|| *_curr == '\t' || *_curr == '\r' || *_curr == 'n'){
        ++_curr;
    }
    _start = _curr;
}



Json Parser::ParseLiteral(const std::string& literal)
{
    if(strncmp(_curr ,literal.c_str(),literal.size()) )
        error("Invalid Value");
    _curr += literal.size();
    _start = _curr;
    switch(literal[0])
    {
        case 't' : return Json(true);
        case 'f' : return Json(false);
        default : return Json(nullptr);
    }
    
}


Json Parser::Parse_Value()
{
    switch (*_curr)
    {
    case 'n':  return ParseLiteral("null");
    case 't':  return ParseLiteral("true");
    case 'f':  return ParseLiteral("false");

    default: return parseNumber();
    }
}

Json Parser::parseNumber()
{
    if(*_curr == '-') ++_curr;

    //int
    if(*_curr == '0') ++ _curr;
    else
    {
        if(!is1to9(*_curr)) error("Invalid Value");
        while (is0to9(*++_curr));
    }

    //frac
    if(*_curr == '.')
    {
        if(!is0to9(*++_curr)) error("Invalid Value");
        while (is0to9(*++_curr));
    }

    //exp
    if(toupper(*_curr) == 'E')
    {
        ++_curr;
        if(*_curr == '-' || *_curr == '+') ++_curr;
        if(!is0to9(*_curr)) error("Invalid Value");
        while (is0to9(*++_curr));
        
    }

    double val = std::strtod(_start,nullptr);
    _start = _curr;
    return Json(val);
}


std::string Parser::ParseRawString()
{
    std::string str;
    while (1)
    {
        switch (*++_curr)
        {
        case '\"': _start = _curr;return str;
        case '\0': error("Miss Quotation Mark");
        case '\\':
            switch (*++_curr)
            {
             
            
            default:
                break;
            }
            default:
                break;


        
        }
    }
    


}


Json Parser::Json_Parse()
{

}

}