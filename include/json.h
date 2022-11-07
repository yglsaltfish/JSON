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

public : //ctor
    Json(const Json&);
    explicit Json(bool val);
    explicit Json(std::nullptr_t);
    explicit Json(double val);
    explicit Json(int val) : Json(1.0 * val){};
    explicit Json(const array_t &); // array
    explicit Json(const object_t &val); //object

    // string ctor
    explicit Json(const std::string &);
    explicit Json(const char* cstr) : Json(std::string(cstr)){};

// getType
    JsonType type() const noexcept;
    bool isNull() const noexcept;
    bool isBool() const noexcept;
    bool isNumber() const noexcept;
    bool isString() const noexcept;
    bool isArray() const noexcept;
    bool isObject() const noexcept;

//convert the JsonValue to c++ pod value
    bool toBool() const;
    double toDouble() const;
    const std::string& toString() const;
    const array_t& toArray() const;
    const object_t &toObject() const;

// serialize
    std::string serialize()const noexcept;

// Access a filed of a Json array
    Json& operator[](std::size_t);
    const Json& operator[](std::size_t) const;

    Json &operator[](const std::string &);
    // Accesses a field of a JSON object
    const Json &operator[](const std::string &) const;
    


private:
    std::string serializeString()const noexcept;
    std::string serializeArray() const noexcept;
    std::string serializeObject() const noexcept;

public : // dtor
    ~Json();

private:
    std::unique_ptr<JsonValue> value_;
};

inline std::ostream & operator << (std::ostream & os , const Json & json){
    return os << json.serialize();
}

// Compare two JSON values for equality
bool operator==(const Json &, const Json &) noexcept;
inline bool operator!=(const Json &lhs, const Json &rhs) noexcept
{
    return !(lhs == rhs);
}
}