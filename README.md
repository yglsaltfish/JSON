# 前言
本文是记录我在学了C++之后的第一次项目实现
文章内容和项目内容主要参考：https://github.com/miloyip/json-tutorial
我会将原仓库的C风格转为C++风格，代码有参考：https://github.com/zsmj2017/MiniJson
感谢前人的文章和代码

我认为[https://www.json.org/json-en.html]这篇对于json本质的理解很有帮助。我就是参考这个网站，通过网站的dfa来参考的写json中的parse。

我还没有完全测试过代码的功能，单纯实现了一些基本功能。这个项目主要就是为了熟悉C++。



# 前置知识
由于使用了较多的C++11&14，我在这个章节会写一下一些用的比较多的特性

## noexcept
这个关键字是用来处理异常的。
对于异常而言，若未被处理，则会上传到调用方；最终会调用`std::terminate()`，而这个函数会执行`std::abort()`终止程序。
用在这边主要是为了使用`movable ctor`；

## override
主要用于虚函数多态，防止错误实现（本来想写多态，但是新写了一个成员函数）

## [[noreturn]]
表面这个函数是没有return值的。

## explicit
强制显示转换，简单来说就是只有明确调用了构造函数才能使用。

## 右值引用

类似下面的做法。
```c++
explicit JsonArray(const Json::array_t &&val) noexcept: Value(std::move(val)) {}
```
主要就是类似于浅拷贝，在`vector`和`deque`中可以加速。

# 项目结构
我是从`json`开始写的，我先把`json`相关的几个类型都定义出来，完成测试，之后再写`parse`，对于字符串中的`Unicode`处理，初看可能会有点困惑，我简单说明一下

## unicode
`c++11`存在对`Unicode`的处理，如下
```c++
/*
char16_t 用于存储 UTF-16 编码的 Unicode 字符
char32_t 用于存储 UTF-32 编码的 Unicode 字符

u8 表示 UTF-8 编码
u 表示 UTF-16 编码
U 表示 UTF-32 编码
*/
char16_t c = u'\u4f60';
char32_t C = U'\U00004f60';

#include <iomanip>
#include <iostream> 
using namespace std;

int main()
{
	const char* sTest = u8"\u4F60\u597D"; //"你好"的 unicode 码值分别是 0x4F60 和 0x597D
	for(int i=0;sTest[i]!=0;++i)
	{
		cout<<setiosflags(ios::uppercase)<<hex<<(uint32_t)(uint8_t)sTest[i]<<" ";
	}
	return 0;
}
//编译选项：g++ -std=c++0x -finput-charset=utf-8 test.cpp
```
我为了更好理解unicode，是模拟了处理过程。
对于`Json`字符串中的`\uxxxx`是以 16 进制表示码点 U+0000 至 U+FFFF，需要：
* 1、解析 4 位十六进制整数为码点；
* 2、由于字符串是以 UTF-8 存储，我们要把这个码点编码成 UTF-8。

`U+0000` 至 `U+FFFF` 这组 `Unicode` 字符称为基本多文种平面（basic multilingual plane, BMP），还有另外 16 个平面。那么 BMP 以外的字符，JSON 会使用代理对（surrogate pair）表示 \uXXXX\uYYYY。在 BMP 中，保留了 2048 个代理码点。如果第一个码点是 U+D800 至 U+DBFF，我们便知道它的代码对的高代理项（high surrogate），之后应该伴随一个 U+DC00 至 U+DFFF 的低代理项（low surrogate）。然后，我们用下列公式把代理对 (H, L) 变换成真实的码点：
$$codepoint = 0x10000 + (H − 0xD800) × 0x400 + (L − 0xDC00)$$


