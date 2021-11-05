[TOC]

# 背景

谷歌C++风格目标：

- 风格规则应该发挥其作用，优化阅读、维护、调试体验
- 优化读者，而不是作者
- 与先有代码保持一致，但一致性不应该作为以旧风格做事的理由，也要考虑新风格的好处，随着时间的推移应该更新风格
- 在适当时候与更广泛的C++社区保持一致
- 避免令人感到奇怪和危险的结构
- 避免让普通的C++程序员觉得棘手的或难以维护的结构
- 注意规模，不恰当的简化会带来高昂的代价。例如：每个人都将东西放入全局命名空间，那么数亿行代码的名称冲突就很难处理，也很难避免
- 必要的时候对优化让步。即使会与该文档原则有冲突

# C++版本

目前，代码应面向C++17。

不要使用非标准扩展

但在使用C++14和C++17的功能之前要考虑其他环境的移植性

# Include头文件

## 自包含标题

头文件应该是自包含的（自己编译）并以`.h`结尾

最好将模板和内联函数的定义与其声明放在同一个文件中。

所有相关模板参数集显式实例化的模板，或者是类的私有实现细节，允许在`.cc`实例化模板的唯一文件中定义。

## #define

所有头文件都应该有`#define`保护以防止多次包含。符号名称的格式应为 .`<PROJECT>_<PATH>_<FILE>_H_`

为了保证唯一性，它们应该基于项目源代码树中的完整路径。例如，`foo/src/bar/baz.h`项目中的文件`foo`应具有以下保护：

```CPP
#ifndef FOO_BAR_BAZ_H_ 
#define FOO_BAR_BAZ_H_ 

... 

#endif // FOO_BAR_BAZ_H_
```



## include What you use

如果头文件或者源文件引用了在别处定义的符号，则该文件应该包含一个头文件，该头文件旨在提供符号的声明或定义。

Do not rely on transitive inclusions.This allows people to remove no-longer-needed #include statements from their headers without breaking clients. This also applies to related headers - foo.cc should include bar.h if it uses a symbol from it even if foo.h includes bar.h.

应该是说引用关系同样适用于头文件之间的包含关系，例如`a.h`需要`b.h`中的声明和定义，在`a.h`中也要`#include "b.h"`

## 前向声明

Pros优点：

- 前向声明可以节省编译时间，可以节省不必要的重新编译。

Cons缺点：

- 前向声明可以隐藏依赖项，会让用户代码在标头更改时跳过必要的重新编译。

- 与#include 语句相反的前向声明使自动工具难以发现定义符号的模块。

- 对库的后续更改可能会破坏前向声明。函数和模板的前向声明可以防止标头所有者对其 API 进行其他兼容的更改，例如扩展参数类型、添加具有默认值的模板参数或迁移到新的命名空间。

- 来自命名空间的前向声明符号会 `std::`产生未定义的行为。

- 可能很难确定是否需要前向声明或完整声明`#include`。`#include`用前向声明替换可能默默地改变代码的含义：

  ```CPP
  // b.h:
  struct B {};
  struct D : B {};
  
  // good_user.cc:
  #include "b.h"
  void f(B*);
  void f(void*);
  void test(D* x) { f(x); }  // calls f(B*)
  
  /**
   * 如果#include被前向声明B和D的前向声明替换，test()将调用f(void*).
   */
  ```

- 前向声明一个头中的多个符号,可能比简单地`#include` 更冗长 。

- 构造代码以启用前向声明（例如，使用指针成员而不是对象成员）会使代码更慢和更复杂。

**<u>总之：尽量避免在另一个项目中定义实体的向前声明</u>**

## 内联函数

**<u>仅当函数很小（例如 10 行或更少）时才定义内联函数。</u>**

Pros:

- 只要内联函数很小，内联函数就可以生成更高效的目标代码。随意内联访问器和修改器，以及其他简短的、性能关键的函数。

Cons:

- 过度使用内联实际上会使程序变慢。根据函数的大小，内联它会导致代码大小增加或减少。内联一个非常小的访问器函数通常会减少代码大小，而内联一个非常大的函数却会戏剧性地显著增加代码大小。在现代处理器上，由于更好地使用指令缓存，较小的代码通常运行得更快。

总之：

- 一个体面的经验法则是，如果函数长度超过 10 行，则不要内联函数。当心析构函数，由于隐式成员和基址析构函数调用，它们通常比它们出现的时间长！
- 另一个有用的经验法则：使用循环或 switch 语句内联函数通常不具有成本效益（除非在常见情况下，永远不会执行循环或 switch 语句）。
- 重要的是要知道函数并不总是内联的，即使它们是这样声明的；例如，虚函数和递归函数通常不内联。通常递归函数不应该是内联的。使虚函数内联的主要原因是为了方便起见或记录其行为（例如，访问器和修改器）将其定义放在类中。

## include包含的名称和顺序

按以下顺序：相关头文件、C的系统文件、C++标准库头文件、其他库的头文件、此项目的头文件

包含头文件不要用目录，而是要用源文件夹srch后面的目录列出，例如 `google-awesome-project/src/base/logging.h` 应包括为：`#include "base/logging.h"`

例如：在`dir/foo.cc`或 `dir/foo_test.cc`中，需要引用 `dir2/foo2.h`，按如下顺序排列您的包含：

1. `#include "dir2/foo2.h"`
2. 一个空行
3. C的头文件，就是`.h`结尾的尖括号头文件，例如`#include <unistd.h>`，`#include <stdlib.h>`
4. 一个空行
5. C++标准库头文件（无文件扩展名），例如`#include <algorithm>`，`#include <cstddef>`
6. 一个空行
7. 其他库的`.h`文件
8. 此项目的`.h`文件

例如，包含在 `google-awesome-project/src/foo/internal/fooserver.cc` 可能看起来像这样：

```CPP
#include "foo/server/fooserver.h" 

#include <sys/types.h> 
#include <unistd.h> 

#include <string> 
#include <vector> 

#include "base/basictypes.h" 
#include "base /commandlineflags.h" 
#include "foo/server/bar.h"
```

例外：条件包含可以放在其他包含之后

```CPP
#include "foo/public/fooserver.h" 

#include "base/port.h" // 对于 LANG_CXX11。

#ifdef LANG_CXX11 
#include <initializer_list> 
#endif // LANG_CXX11
```



# Scoping范围界定

## namespaces命名空间

不要使用using命令例如`using namespace foo`。不要使用内联命名空间

## Internal Linkage内部联动

When definitions in a `.cc` file do not need to be referenced outside that file, give them internal linkage by placing them in an unnamed namespace or declaring them `static`. Do not use either of these constructs in `.h` files.

All declarations can be given internal linkage by placing them in unnamed namespaces. Functions and variables can also be given internal linkage by declaring them `static`. This means that anything you're declaring can't be accessed from another file. If a different file declares something with the same name, then the two entities are completely independent.

Use of internal linkage in `.cc` files is encouraged for all code that does not need to be referenced elsewhere. Do not use internal linkage in `.h` files.

Format unnamed namespaces like named namespaces. In the terminating comment, leave the namespace name empty:

```
namespace {
...
}  // namespace
```

## Nonmember, Static Member, and Global Functions非成员，静态函数和全局函数

更多的将非成员函数放在命名空间中，更少的使用完全全局函数。不要简单的使用类来对静态成员进行分组。类的静态方法通常应与类的实例或类的静态数据密切相关。

有时定义一个不绑定到类实例的函数很有用。这样的函数可以是静态成员或非成员函数。非成员函数不应该依赖于外部变量，并且应该几乎总是存在于命名空间中。

不要仅仅为了分组静态成员而创建类；这与只是给名称一个通用前缀没有什么不同，而且这种分组通常是不必要的。

如果定义了一个非成员函数并且仅在其`.cc`文件中需要它，使用 [内部链接](https://google.github.io/styleguide/cppguide.html#Internal_Linkage)来限制其范围。

## Local Variables局部函数

**<u>将函数的变量放在尽可能窄的范围内，并在声明中初始化变量。</u>**

C++ 允许在函数的任何位置声明变量。

在尽可能局部的范围内声明它们，并尽可能接近第一次使用。

这使读者更容易找到声明并查看变量是什么类型以及它被初始化为什么。特别是，应该使用初始化而不是声明和赋值，例如：

```CPP
int i;
i = f();
// no no no！声明和初始化分开不好。

int j = g();
// good! 声明的同时初始化

std::vector<int> v;
v.push_back(1);
v.push_back(2);
// no no no! 应该使用列表初始化

std::vector<int> v = {1, 2};
// good! 列表初始化

while (const char* p = strchr(str, '/')) str = p + 1;
// if, while, for语句所需的变量应该在这些语句范围中声明，以便将这些变量限制在这些范围内

// 警告！警告！:
for (int i = 0; i < 1000000; ++i) {
  Foo f;  // 对象f被创建了1000000次！！
  f.DoSomething(i);
}
// no no no! 如果变量是一个对象，则每次进入作用域并创建时，都会调用其构造函数，循环一次后都会调用其析构函数

Foo f;  // f对象只创建了一次
for (int i = 0; i < 1000000; ++i) {
  f.DoSomething(i);
}
// good! 
```

## Static and Global Variables 静态和全局变量

























