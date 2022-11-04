#include "json.h"
#include <cassert>
#include "jsonValue.h"


namespace LJson
{

//ctor
Json::Json(bool val):value_(std::make_unique<JsonBool>(val)){}
Json::Json(nullptr_t) : value_(std::make_unique<JsonNull>(nullptr)){}
Json::Json(double val) : value_(std::make_unique<JsonDouble>(val)){}

Json::Json(const std::string& val) : value_(std::make_unique<JsonString>(val)){} // string

Json::Json(const array_t & val) : value_(std::make_unique<JsonArray>(val)){}     // array

Json::~Json(){};



}