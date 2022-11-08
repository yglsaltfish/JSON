#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <unordered_map>


#include "json.h"
#include "parse.h"

#include <string>

using namespace LJson;
using namespace std;

void Test_Json()
{
    cout << "-----------------Test_Json -------------------\n";
    Json a(true);
    Json b(1.2);
    Json c(nullptr);
    Json d("111");
    std::vector<Json> tmp{a, b, d};
    Json e(tmp);
    std::unordered_map<std::string, Json> mp;
    std::string bn = "Bool";
    mp.insert({bn, a});
    bn = "Array";
    mp.insert({bn, e});
    Json f(mp);
    std::cout << "test for bool : " << a << std::endl;
    std::cout << "test for number : " << b << std::endl;
    std::cout << "test for string : " << d << std::endl;
    std::cout << "test for Array : " << e << std::endl;
    std::cout << "test for Array operator[]: " << e[0] << std::endl;
    std::cout << "test for object : " << f << std::endl;
}

void Test_Parse_Number()
{
    cout << "-----------------Test_Parse_Number -------------------\n";
    string num = "123.3555521";
    cout << Parser(num).ParseValue() << std::endl;
    cout << std::endl;
}

void Test_Parse_String()
{
    cout << "-----------------Test_Parse_String -------------------\n";
    string num = "\"123.3555521\"";
    cout << Parser(num).ParseValue() << std::endl;
    cout << std::endl;
}

void Test_Parse_Array()
{
    cout << "-----------------Test_Parse_Array -------------------\n";
    string num = "[ null , false , true , 123 , \" abc \" ]";
    std::cout << Parser(num).ParseValue() << std::endl;
    num = "[ [ ] , [ 0 ] , [ 0 , 1 ] , [ 0 , 1 , 2 ] ]";
    std::cout << Parser(num).ParseValue() << std::endl;
}


int main()
{
    Test_Json();
    Test_Parse_Number();
    Test_Parse_String();
    Test_Parse_Array();

    /*--------------test for parse--------------------*/
    

    


}