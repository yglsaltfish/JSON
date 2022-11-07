#include "parse.h"
#include "jsonException.h"
#include <cassert>
#include <cstring>
#include <stdexcept>

namespace LJson
{

void Parser::parseWhitespace() noexcept{
    while (*curr == ' '|| *curr == '\t' || *curr == '\r' || *curr == 'n'){
        ++curr;
    }
    start = curr;
}



Json Parser::ParseLiteral(const std::string& literal)
{
    if(strncmp(curr ,literal.c_str(),literal.size()) )
        error("Invalid Value");
    curr += literal.size();
    start = curr;
    switch(literal[0])
    {
        case 't' : return Json(true);
        case 'f' : return Json(false);
        default : return Json(nullptr);
    }
    
}


Json Parser::Parse_Value()
{
    switch (*curr)
    {
    case 'n':  return ParseLiteral("null");
    case 't':  return ParseLiteral("true");
    case 'f':  return ParseLiteral("false");

    default: return parseNumber();
    }
}

Json Parser::parseNumber()
{
    if(*curr == '-') ++curr;

    //int
    if(*curr == '0') ++ curr;
    else
    {
        if(!is1to9(*curr)) error("Invalid Value");
        while (is0to9(*++curr));
    }

    //frac
    if(*curr == '.')
    {
        if(!is0to9(*++curr)) error("Invalid Value");
        while (is0to9(*++curr));
    }

    //exp
    if(toupper(*curr) == 'E')
    {
        ++curr;
        if(*curr == '-' || *curr == '+') ++curr;
        if(!is0to9(*curr)) error("Invalid Value");
        while (is0to9(*++curr));
        
    }

    double val = std::strtod(start,nullptr);
    start = curr;
    return Json(val);
}


std::string Parser::ParseRawString()
{
    std::string str;
    while (1)
    {
        switch (*++curr)
        {
        case '\"': start = ++curr;return str;
        case '\0': error("Miss Quotation Mark");
        case '\\': 
            switch (*++curr)
            {
                case '\"':str.push_back('\"');break;
                case '\\':str.push_back('\\');break;
                case '/':str.push_back('/');break;
                case 'b':str.push_back('\b');break;
                case 'f':str.push_back('\f');break;
                case 'n':str.push_back('\n');break;
                case 't':str.push_back('\t');break;
                case 'r':str.push_back('\r');break;
                case 'u':{
                    unsigned u1 = parse4hex();
                    if(u1 >= 0xd800 && u1 <= 0xdbff){
                        if(*++curr != '\\') error("INVAILD UNICODE SURROGATE");
                        if(*++curr != 'u') error("INVAILD UNICODE SURROGATE");
                        unsigned u2 = parse4hex();
                        if(u2 < 0xdc00 || u2 > 0xdfff) error("INVALID UNICODE SURROGATE");
                        u1 = (((u1 - 0xd800)<< 10 )| (u2 - 0xdc00)) + 0x10000;



                    }
                    //str +=
                    str += encodeUTF8(u1);


                }
                
            default:
                break;
            }
        default:
            if (static_cast<unsigned char>(*curr) < 0x20)
                error("INVALID STRING CHAE");
            str.push_back(*curr);
            break;

        }
    }
}

unsigned Parser::parse4hex()
{
    unsigned u = 0;
    for(int i = 0; i != 4; ++i){
        unsigned ch = static_cast<unsigned>(toupper(*++curr));
        u <<= 4;
        if(ch >= '0' && ch <= '9')
            u |= (ch - '0');
        else if(ch >= 'A' && ch <= 'Z')
            u |= (ch - 'A') + 10;
        else
            error("INVALID UNICODE HEX");
    }
    return u;
}

std::string Parser::encodeUTF8(unsigned u)noexcept 
{
    std::string utf8;
    if(u <= 0x7f) //0111 1111
        utf8.push_back(static_cast<char>(u & 0xff));
    else if (u <= 0x7ff){
        utf8.push_back(static_cast<char>(0xc0 | ((u>>6) & 0xff)));
        utf8.push_back(static_cast<char>(0x80 | (u & 0x3f)));
    }
    

    return utf8;
}


Json Parser::Json_Parse()
{

}

}