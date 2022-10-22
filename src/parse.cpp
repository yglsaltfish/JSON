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





}