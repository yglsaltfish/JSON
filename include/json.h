#pragma once

#include <vector>
#include <string>
#include <memory>

#include <unordered_map>



namespace LJson
{

class JsonValue;

enum class JsonType
{
    kNull,
    kBool,
    kNumber,
    kString,
    kArray,
    kObject
};

enum class State
{
    Parse_OK = 0,
    Parse_Expect_Value,
    Parse_Invalid_Value,
    Parse_Root_Not_Singular
};


class Json final{
public:
    using array_t = std::vector<Json>;
    using object_t = std::unordered_map<std::string , Json>;

    static Json parse(const std::string &content, std::string errMsg) noexcept;


public : //ctor dtor
    Json(const Json&);
    Json(bool val);
    Json(std::nullptr_t);
    ~Json();

    explicit Json(bool);



private:
    std::unique_ptr<JsonValue> value_;
};




}