#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "json.h"
#include <unordered_map>

#include <gtest/gtest.h>
#include <string>

using namespace LJson;
using namespace std;

int main()
{
    
    Json a(true);
    Json b(1.2);
    Json c(nullptr);
    Json d("111");
    std::vector<Json> tmp;
    tmp.push_back(a);
    tmp.push_back(b);
    tmp.push_back(d);
    Json e(tmp);
    std::unordered_map<std::string, Json> mp;
    std::string bn = "bnn";
    mp.insert({bn,a});
    bn = "arrat";
    mp.insert({bn, e});
    Json f(mp);


    
    

    std::cout << "test for bool : " << a << std::endl;
    std::cout << "test for number : " << b << std::endl;
    std::cout << "test for string : " << d << std::endl;
    std::cout << "test for Array : " << e << std::endl;
    std::cout << "test for object : " << f << std::endl;
    //std::cout << "this is a test for demo.\n";
    //std::cout << "test 1 \n" << std::endl;
    

}