#include "parse.h"
#include <cassert>
#include <cstring>

namespace LJson
{

void Parser::parseWhitespace() noexcept{
    while (*_curr == ' '|| *_curr == '\t' || *_curr == '\r' || *_curr == 'n'){
        ++_curr;
    }
    _start = _curr;
}

inline void Parser::EXPECT(char  C)
{
    assert(*(this->_curr) == C);
    this->_curr ++;
}

int Parser::Parse_Null()
{
    EXPECT('n');
    if(_curr[0]!= 'u' || _curr[1] != 'l' || _curr[2] != 'l')
        return (int)State::Parse_Invalid_Value;
    _curr += 3;
    return (int)State::Parse_OK;
}

}