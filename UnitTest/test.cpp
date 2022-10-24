#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"
#include <gtest/gtest.h>
#include <string>

using namespace LJson;

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

static void test_parse_null(){
    std::string t = "nul ";
    Parser p(t);
    //EXPECT_EQ((int)State::Parse_Invalid_Value, p.Parse_Null());
    //assert((int)State::Parse_Invalid_Value == p.Parse_Null());
    //std::cout << p.Parse_Null() << std::endl;
    std::cout<<std::endl;
}

static void test_parse()
{
    test_parse_null();

}

int main()
{

    test_parse();

}