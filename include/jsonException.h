#pragma once

#include <stdexcept>
#include <string>

namespace LJson
{
class JsonException :public std::runtime_error{

public: //ctor
    explicit JsonException(const std::string& errMsg):runtime_error(errMsg){}

public: //interface
    const char * what() const noexcept override{ return runtime_error::what();}
};

} //namespace LJson