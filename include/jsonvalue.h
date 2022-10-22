#pragma once
#include <variant>
#include <string>

#include "json.h"
#include "jsonException.h"

namespace LJson
{
//public: //ctor
//    explicit JsonValue(std::)
class JsonValue{

public:



private:
    std::variant<std::nullptr_t, bool, double, std::string, Json::_array,
                 Json::_object>
        _val;
};




}