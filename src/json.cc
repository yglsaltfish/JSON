#include "json.h"
#include <cassert>
#include "jsonValue.h"
#include "parse.h"


namespace LJson
{

Json::Json(bool val):value_(std::make_unique<JsonBool>(val)){}
Json::Json(nullptr_t) : value_(std::make_unique<JsonNull>(nullptr)){}
Json::Json(double val) : value_(std::make_unique<JsonDouble>(val)){}



}