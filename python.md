[TOC]

# 预备知识

## 编码规范



==python文件组成==

Linux 平台上，一个 python 源码文件应该以下部分组成。Windows 平台上，可以省略第一项。

> 1. 解释器声明
> 2. 编码格式声明
> 3. 模块注释或文档字符串
> 4. 模块导入
> 5. 常量和全局变量声明
> 6. 顶级定义（函数或类定义）
> 7. 执行代码

```python
#!/usr/bin/env python
# -*- coding: utf-8 -*-


"""通常这里是关于本文档的说明（docstring），须以半角的句号、 问号或惊叹号结尾!

本行之前应当空一行，继续完成关于本文档的说明
如果文档说明可以在一行内结束，结尾的三个双引号不需要换行；否则，就要像下面这样
"""


import os, time
import datetime
import math

import numpy as np
import xlrd, xlwt, xlutils

import youth_mongodb
import youth_curl


BASE_PATH = r"d:\YouthGit"
LOG_FILE = u"运行日志.txt"


class GameRoom(object):
    """对局室"""
    
    def __init__(self, name, limit=100, **kwds):
        """构造函数!
        
        name        对局室名字
        limit       人数上限
        kwds        参数字典
        """
        
        pass


def craete_and_start():
    """创建并启动对局室"""
    
    pass


if __name__ == '__main__':
    # 开启游戏服务
    start()

```



==导入函数==

> 1. 标准库导入
> 2. 第三方库导入
> 3. 本地应用程序/库特定的导入



==编码格式声明==

这通常是必需的。如果 `python` 源码文件没有声明编码格式，解释器会默认使用 ASCII 编码。

```python
#!/usr/bin/env pyhton
# -*- coding: utf-8 -*-
```

`linux`中第一行是解释器的路径声明，windows钟编码格式必须放在第一行



==缩进==

**使用四个空格！不要用tab，更不要混用，连接情况使用悬浮式缩进**

```python
var_dict = {
    'name': "zhouweijie",
    'mail': "elonzhou99@gmail.com"
}
```



==行长度==

每行最大长度**79字符**，换行可以使用反斜杠，最好使用圆括号，IDE中一般Enter会自动添加。

文档字符串或注释，行长应限制为**72 字符**。

一般过长，IDE会提示。

有二元操作符时应在操作符前换行

```python
# Correct:
# easy to match operators with operands
income = (gross_wages
          + taxable_interest
          + (dividends - qualified_dividends)
          - ira_deduction
          - student_loan_interest)
# Wrong:
# operators sit far away from their operands
income = (gross_wages +
          taxable_interest +
          (dividends - qualified_dividends) -
          ira_deduction -
          student_loan_interest)
```



==空行==

用**两个空白行**分隔**顶层函数和类定义**。
用**一个空行**分隔类中的**方法定义**。
可以使用额外的空白行（节省空间）来分隔相关功能组。在一堆相关的单行程序（例如，一组虚拟执行程序）之间可能会省略空白行。
在函数中使用空行来节省逻辑部分。
恰当的使用空白行可以提高代码的可读性。



==引号==

使用双引号来包含长度大于1的字符串，使用单引号来包含长度为1的字符串

> - 自然语言使用双引号
> - 机器标识使用单引号
> - 正则表达式使用双引号
> - 文档字符串(docstring)使用三个双引号



==注释==

**代码更改的时候注释也要改**

- 块注释：通常由一个或多个段落组成完整的句子，每个句子以句号结尾

- 行注释：一般在代码的上一行，如果代码较短，又很重要，可以与代码一行，建议与代码空两个空格

- 文档字符串：常用三个双引号作文档字符串，文档字符串常用在模块的开端用以说明模块的基本功能，或紧跟函数定义的后面用以说明函数的基本功能，参数，返回值。

- 函数注释：第一行说明函数的作用，接下来是函数的参数、函数的返回值。

  - ```python
    def plus(a,b):
        """
        compute a+b and return result
        :param a: int, a number
        :param b: int, another number
        :return: int, a+b
        """
    ```

==命名规范==

- 模块尽量使用小写命名，首字母保持小写，尽量不要用下划线
- 类名使用驼峰(CamelCase)命名风格，首字母大写，私有类可用一个下划线开头
- 函数名一律小写，如有多个单词，用下划线隔开
- 私有函数可用一个下划线开头
- 变量名尽量小写, 如有多个单词，用下划线隔开
- 常量采用全大写，如有多个单词，使用下划线隔开



## 模块管理

- 自定义模块的时候要注意命名的规范，使用小写，不要使用大写，不要使用中文，不要使用特殊字符等。
- 不要与内置模块冲突 sys 等。

**模块和包**

==包==

包其实本质上就是一个文件夹，将一些相关联的模块组合在一起。

- 但是如果一个文件夹要让Python识别为一个包，则必须在这个文件夹中创建一个叫做**\_\_init\_\_.py**的文件。一个文件夹中只有拥有了**\_\_init\_\_.py**这个文件，才能被视为一个包。
- 在同一个包中的模块如果要互相导入，则只能通过相对的方式进行导入，即：from . import xxx。



创建一个模块package

```python
# 在模块中定义变量
a = 10
b = 20

# 在模块中定义函数
def max(x, y):
    """
    加法
    :param x:
    :param y:
    :return:
    """
    return x + y

def min(x,y):
    """
    减法
    :param x:
    :param y:
    :return:
    """
    return x-y


# 在模块中定义类
class calculator: # 定义一个加法计算器
    @classmethod #导入计算器模块
    def sum(cls,*nums):
        res = 0 
        for i in nums:
            res += i
        return res


'''
__name__ 属性是模块的内置属性，每个模块中都有该属性，当该
.py文件是主执行文件，直接被执行时，其值为 __main__ ，当该
.py文件是被调用，导入执行文件时，其值为模块名
'''
# print(__name__）# 如果这么直接这么测试，被导入文件执行时，导入文件也会打印该内容
#程序入口，类似于java中的main()方法，只在当直接调用该文件时才会执行，用来执行测试
if __name__ == '__main__' :
    print(calculator.sum(1,2,3))  # 只有在当前界面执行才会打印该内容，其他文件中不会执行。

```

==循环导入==

比如有现在目录中有两个模块，一个a.py，一个b.py。在a.py中引用了b。而在b.py中又引用了a，那么这时候就产生了循环导入，让两个导入都不能完成。



# 基础语法

## 函数

==无参定义函数==

==带参定义函数==

- 在调用函数时候，参数个数和位置一定要按照函数定义。
- 可以在函数调用的过程中给指明特定的参数`func(b=2,a=1)`, 参数的位置将不受影响。

```python
def func(a, b):
    c = a+b
    print('the c is ', c)
```



==函数默认参数==

**所有的默认参数都不能出现在非默认参数的前面。**

```python
def sale_car(price, color='red', brand='carmy', is_second_hand=True):
    print('price', price,
          'color', color,
          'brand', brand,
          'is_second_hand', is_second_hand)
```

- 调用函数 `sale_car(1000)`, 那么与 `sale_car(1000, 'red', 'carmy', True)`是一样的效果。
- 当然也可以在函数调用过程中传入特定的参数用来修改默认参数。通过默认参数可以减轻我们函数调用的复杂度。

-**函数进阶：**-

> 1. **自调用**
>
> 如果想要在执行脚本的时候执行一些代码，比如[单元测试](https://en.wikipedia.org/wiki/Unit_testing)，可以在脚本最后加上单元测试 代码，但是该脚本作为一个模块对外提供功能的时候单元测试代码也会执行，这些往往我们不想要的，我们可以把这些代码放入脚本最后：`if __name__ == '__main__':`
>
> ```python
> import unittest
> from name_function import get_formmed_name
>  
> class NamesTestCase(unittest.TestCase):
>     """测试name_function.py"""
>  
>     def test_first_last_name(self):
>         """能够正确处理像Janis Joplin这样的姓名吗？"""
>         formatted_name = get_formmed_name('janis','joplin')
>         self.assertEqual(formatted_name,'Janis Joplin')
>  
>  
> #注意这个地方，我在Python 2.7的版本中直接调用书上的主函数
> #unittest.main()时程序无法通过，而改用以下调用方式即可
>  
> if __name__ == '__main__':
>     unittest
> ```
>
> - 导入单元测试类`unittest`
> - 导入要测试的函数，本例为`name_function`模块中的`get_formatted_name()` 函数
> - 创建一个继承于`unittest.TestCase`的类
> - 在类中定义一系列方法对函数的行为进行不同方面的测试，需要注意的是一个测试用例应该只测试一个方面，测试目的和测试内容应很明确。主要是调用`assertEqual`、`assertRaises`等断言方法判断程序执行结果和预期值是否相符。
>
> 2. **可变参数**
>
> - 函数的可变参数是传入的参数可以变化的，1个，2个到任意个。
> - 当然可以将这些 参数封装成一个`list`或者 `tuple` 传入，但不够 `pythonic`。
> - 使用可变参数可以很好解决该问题，注意可变参数在函数定义**不能出现在特定参数和默认参数前面**，因为可变参数会吞噬掉这些参数。
>
> ```python
> def report(name, *grades):
>     total_grade = 0
>     for grade in grades:
>         total_grade += grade
>     print(name, 'total grade is ', total_grade)
> ```
>
> 定义了一个函数，传入一个参数为`name`, 后面的参数`*grades`使用了`*`修饰，表明该参数是一个可变参数，这是一个可迭代的对象。该函数输入姓名和各科的成绩，输出姓名和总共成绩。所以可以这样调用函数 `report('Mike', 8, 9)`，输出的结果为 `Mike total grade is 17`, 也可以这样调用 `report('Mike', 8, 9, 10)`，输出的结果为 `Mike total grade is 27`
>
> 3. **关键字参数**
>
> 关键字参数可以传入0个或者任意个含参数名的参数，这些参数名在函数定义中并没有出现，这些参数在函数内部自动封装成一个字典(dict).
>
> ```python
> def portrait(name, **kw):
>     print('name is', name)
>     for k,v in kw.items():
>         print(k, v)
> ```
>
> 定义了一个函数，传入一个参数 `name`, 和关键字参数 `kw`，使用了`**` 修饰。表明该参数是关键字参数，通常来讲**关键字参数是放在函数参数列表的最后**。如果调用参数 `portrait('Mike', age=24, country='China', education='bachelor')`输出:
>
> ```
> name is Mike
> age 24
> country China
> education bachelor
> ```
>
> 通过可变参数和关键字参数，任何函数都可以用 universal_func(*args, **kw) 表达。
>
> 4. **函数返回值**
>
> 与c不同的是，python可以有多个返回值同时返回。因为python帮我们将其封装成了一个元组类型
>
> ```python
> def mypow(x,y=2):
>     #print(x ** y)
>     # pass
>     return x**y,x+y
> a = mypow(2,4)
> print(a)
> ```
>
> 输出：
>
> ```
> (16, 7)
> ```
>
> 



==全局变量，局部变量==

**1. 局部变量**

```python
APPLY = 100 # 全局变量
def fun():
    a = 10  # 局部变量
    return a+100
 
print(APPLE)    # 100
print(a)    # 报错, 不能拿到一个局部变量的值
```

如果在 `fun` 外面调用`a`, 会报错, 这表明外面的这个 `print(a)`不能找到那个局部的 `a`, 只有全局变量再能在外面被调用, 比如 `APPLE`.

**2. 全局变量**

```python
APPLY = 100 # 全局变量
a = None
def fun():
    global a    # 使用之前在全局里定义的 a
    a = 20      # 现在的 a 是全局变量了
    return a+100
 
print(APPLE)    # 100
print('a past:', a)  # None
fun()
print('a now:', a)   # 20
```

首先我们在外部定义一个全局变量 `a=None`, 然后再 `fun()`中声明 这个`a`是来自外部的 `a`. 声明方式就是 `global a`



## 类与对象

- 首字母大写驼峰命名法
- 类是一种高级抽象，就是一种高级的数据类型，是对象的蓝图，就是用来定义你要用的对象的属性和行为
- 封装、继承、多态
- 变量名以`__`开头为私有变量

```python
class Student(object):

    def __init__(self, name, score):
        self.__name = name
        self.__score = score
    def print_score(self):
        print "%s: %s" %(self.__name,self.__score)
```



### 封装

> 面向对象编程语言
>
> - 类：一个模板，（人类）---是一个抽象的，没有实体的
> - 对象： = 属性 + 方法（eg：张三，李四）
> - 属性：（表示这类东西的特征，眼睛，嘴巴，鼻子）
> - 方法：（表示这类物体可以做的事情，eg：吃饭，睡觉，学习）

```python
class HotDog:
    def __init__(self):
        self.cooked_level = 0
        self.cooked_string = "Raw"
        self.ingredients = []

    def __str__(self):      #定义新的__str__()方法
        msg = "hot dog"
        if len(self.ingredients) > 0:
            msg = msg + "with"
        for i in self.ingredients:
            msg = msg + i + ","
        msg = msg.strip(",")
        msg = self.cooked_string + " " + msg + "."
        return msg
        
    def cook(self, time):
        self.cooked_level = self.cooked_level + time 
        if self.cooked_level > 8:
            self.cooked_string = "Over-toasting"
        elif self.cooked_level > 5:
            self.cooked_string = "Well-down"
        elif self.cooked_level > 3:
            self.cookede_string = "Medium"
        else:
            self.cooked_level = "Raw"
            
    def add_ingredients(self, ingredients):  #定义新的addingredients()方法
        self.ingredients.append(ingredients)
            
myDog = HotDog()

print myDog
print "Cooking hot dog for 4 minutes..."
myDog.cook(4)
print

print myDog
print "Cooking hot dog for 3 minutes..."
myDog.cook(3)
print

print myDog
print "Cooking hot dog for 10 minutes..."
myDog.cook(10)
print myDog
print

print "Now,I'm going to add some ingredients on my hot dog"
myDog.addingredients("ketchup")
myDog.addingredients("mustard")
print myDog
```

__ init__( )：创建实例并设置默认属性。

__ str__( )：告诉Python打印一个对象时具体显示什么内容。



### 继承与多态

==多态==

**同名方法，不同行为**。取决于这些方法应用于哪个类，它们可以有不同的的行为

计算三角形和正方形的类中都有`getArea()`的方法

```python
class Triangle:
    def __init__(self,width,height):
        self.width = width
        self.height = height

    def getArea(self):
        area = self.width * self.height /2.0
        return area

class Square:
    def __init__(self,size):
        self.size = size

    def getArea(self):
        area = self.size * self.size
        return area
```

```
>>> myTriangle = Triangle(4,5)
>>> mySquare = Square(7)
>>> myTriangle.getArea()
10.0
>>> mySquare.getArea()
49
>>> 
```

==继承==

面向对象编程，类可以从其他类继承属性和方法。继承而来的类成为派生类或子类。

```python
class Student(object):
    pass
```

`object`类是所有类都会继承的类

父类：GameObject（捡东西）

- 属性：`name`
- 方法：`pickUp()`

子类：Coin（捡硬币，继承/派生于`GameObject`）

- 属性：`value，name`
- 方法：`spend(), pickUp`

```python
class GameObject:
    def __init__(self,player):
        self.name = name

    def pickUp(self,player):
        pass
        
        
class Coin(GameObject):
    def __init__(self,value):
        GameObject.__init__(self)
        self.value = value

    def spend(self,buyer,seller):
        pass
```



## self用法

- `self`就是指类本身，类似于`c++`中的`this`指针。`self.name`就是`Student`类的属性变量，是`Student`类所有。

- 而`name`是外部传来的参数，不是`Student`类所自带的。故，`self.name = name`的意思就是把外部传来的参数`name`的值赋值给Student类自己的属性变量`self.name`。

==**self代表类的实例，而非类。**==

```python
class Test:
    def ppr(self):
        print(self)
        print(self.__class__)

t = Test()
t.ppr()
执行结果：
<__main__.Test object at 0x000000000284E080>
<class '__main__.Test'>
```

self代表的是类的实例。而`self.__class__`则指向类。

==**self可以不写吗？**==

在Python解释器的内部，当我们调用t.ppr()时，实际上Python解释成Test.ppr(t)，也就是把self替换成了类的实例。

```python
class Test:
    def ppr():
        print(self)

t = Test()  # 创建了实例，打印实例报错
t.ppr()
```

运行结果：

```python
Traceback (most recent call last):
  File "cl.py", line 6, in <module>
    t.ppr()
TypeError: ppr() takes 0 positional arguments but 1 was given
```

运行时提醒错误如下：ppr在定义时没有参数，但是我们运行时强行传了一个参数。

由于上面解释过了t.ppr()等同于Test.ppr(t)，所以程序提醒我们多传了一个参数t。

这里实际上已经部分说明了self在定义时不可以省略。

当然，如果我们的定义和调用时均不传类实例是可以的，这就是类方法。

```python
class Test:
    def ppr():
        print(__class__)

Test.ppr()  # 不创建实例，直接打印类

运行结果：
<class '__main__.Test'>
```

总之`self`很复杂。



## 顺序、条件分支和循环语句结构

==程序中的组织结构==

任何算法都可以由**顺序结构**、**选择结构**和**循环结构**这三部分组成。

==顺序结构==

从上到下执行代码，中间没有判断和跳转，直到程序结束。

==对象的布尔值==

**Python一切皆对象**，所有的对象都有一个布尔值，可以使用内置函数`bool()`来获取对象的布尔值。
以下对象的布尔值为`False`
（1）`False`
（2）数值`0`
（3）`None`
（4）空字符串
（5）空列表 `list()`
（6）空元组 `tuple()`
（7）空字典 `{},dict()`
（8）空集合 `set()`



==分支结构==

```python
if 条件表达式1:
    条件执行体1
elif 条件表达式2:
    条件执行体2
else:
    条件执行体3
```



==循环结构==

> - `while  ` 循环
> - `break` 和 `continue`
> - `while` 嵌套

**`for` 循环**

```python
for i in range(5):
	print(i)
```

- `range` 的用法

```python
>>> range(5)
[0, 1, 2, 3, 4]
>>> range(10)
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>> range(1,11)
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
>>> range(1,11,2)   
[1, 3, 5, 7, 9]
```

1. `break`:跳出整个循环，不会再执行循环后续的内容
2. `continue`:跳出本次循环，`continue`后面的代码不再执行，但是还是会继续循环
3. `exit()`：结束程序的运行

**`while` 循环**



## 数据类型及内置函数

number（数字）、string（字符串）、Boolean（布尔值）、None（空值）

list（列表）、tuple（元组）、dict（字典）、set（集合）。

格式化输出：

```python
print("num = %d, str15 = %s.3f" %(num, str15, d))
# r表示内部的字符不转义
print(r"\\\t\\\")
```



==数字类型==

类型转换

```python
int(x)  # 向下取整
int("123")  # 字符串转整数
float(1)  # 整型转浮点型
int("123 + 123")  # 有无用字符，会报错
int("-123")  # 这里-作为负号，不会报错
```

数学函数

```python
abs(x)  # 返回绝对值
print((10>9) - (10<9))  # 1 - 0 = 1
max(x1, x2, ...)  # 返回最大值
min(x1, x2, ...)  # 返回最小值
pow(x, y)  # x的y次方
round(3.1415)  # 返回四舍五入值3
round(3.1415, 2)  # 返回小数点后2位：3.14

#  数学库
import math

math.ceil(x)  # 向上取整
math.floor(x)  # 向下取整
math.modf(22.3)  # 返回整数部分和小数部分的元组(0.3, 22.0)
math.sqrt(x)  # 返回x的平方根
```

随机数函数

```python
import random

random.choice(seq)  # 从序列中随机挑选一个元素
random.randrange([start, stop, step])  # 可以只填stop
random.random()  # 随机生成[0, 1)之间的浮点数
random.shuffle(list)  # 将数列的所有元素随机排序
random.uniform(x, y)  # 随机生成一个实数（小数或者整数），返回浮点数
```

三角函数

```python
# 基本的三角函数都有
```



==string字符串类型==

运算

```python
# +， *
# 不建议只用+连接，可以使用join
```

访问

```python
# 下标访问
# ：截取
```

常用方法

```python
eval(str)  # 将字符串str当成有效表达式来求值，str最多三个参数 eg：eval("12 + 3")
len(str)  # 长度
str1.lower()  # str1中大写转小写
str1.upper()  # str1中小写转大写
str1.swapcase()  # 大写转小写，小写转大写
str1.capitalize()  # 首字母大写，其他小写
str1.title()  # 每个单词的首字母大写
str1.count("str, [start], [end]")  # 返回str1中str出现的次数
str1.find("str, [start], [end]")  # 返回第一次出现str的开始下标，没有则返回-1
str1.rfind("str, [start], [end]")  # 从右往左
str1.index("str, [start], [end]")  # 和find方法一样，区别在于没找到会报异常
ord(x)  # 返回十进制
chr(x)  # 返回asscll字符
str1.split("str")  # 以str为分隔符截取字符串
str1.split("str", 15)  #仅截取15个
str1.splitlines()  # false按照(\n, \r\n, \n)这三种分隔，true按照行切
max(str1)  # 按照ascll码比较，min()也一样
str1.replace(oldsre, newstr, count)  # newstr替换oldstr，如果指定了count只替换前count个
str1.maketrans(str1, str2)  # 创建映射表
str1.startswith(str, start, end)  # 给定范围内判断字符串是否以str开头 endswith也一样
str1.encode("utf-8", "ignore")  # 编码格式，报错处理方法。decode也一样
str1.isalpha()  # 长度>=1为True
str1.isalnum()  # 所有的字符都是数字或字母返回True
str1.isupper()  # 所有英文字母都是大写返回True
# islower(), .....同理
# 比较大小
# 截断字符串
```

==list列表==

有序的集合

```python
list1 = [1, 2, "good", True]
```

下标访问，下标替换

列表操作

```python
# + * 连接，重复
# 不建议使用+，可以使用join
# ：截取
print(3 in [1, 2, 3])  # 判断3是否在列表里
```

列表方法

```python
list1.append(x)  # 末尾添加元素
list1.extend(list2)  # 末尾添加另一个列表
list1.insert(index, list2)  # index处添加另一个列表或元素，后面的顺移
list1.pop(index)  # 删除下标处的元素，返回该删除的元素
list1.remove(x)  # 移除列表中某一个元素，匹配第一个
list1.clear()  # 清空
list1.index(x)  # 匹配第一个x的下标
len()  # 返回长度
max() / min()
```

==tuple元组==

**不可变列表，安全，尽量用元组**

是一种有序集合

一旦初始化就不能修改，使用小括号

```python
tuple1 = (1, 2, "good", True)
```

元组的访问

```python
# 下标访问，下标取值
# 不能改变元组的元素，但能改表元组内的列表
tuple1 = (1, [1, 2, 3])
tuple1[-1][0] = 2. # (1, [2, 2, 3])
del tuple1  # 删除元组
# + * 连接重复
# ：截取
print(1 in tuple1)  # 判断是否存在于
# 遍历
for i in (1, 2, 3, 4):
    pass
```

方法

```python
len()
min()
max()
```

列表转换为元组

```python
list1 = [1, 2, 3]
tuple1 = tuple(list1)
```



==dict字典==

字典是无序的，一个字典可以储存错个键值对，类似于hash

字符串和整数可以作为key

```python
dict1 = {"Tom":60, "lilei":70}
```

操作

```python
# 通过key访问value
print(dict1["Tom"])
# 添加
dict1["zhouweijie"] = 100
# 删除
dict1.pop("Tom")
# 遍历
for key in dict1:
    print(key, dict1[key])
for key,value in dict1:
    print(key, value)
```

==set集合==

类似dict，是一组key的组合，不存储value

**"无序，不重复的元素组合"**

**"set的元素不能是列表或者字典"**

**set没有索引操作**

操作

```python
set1 = set([1, 2, 3, 4, 4, 4])
print(set1)  # {1, 2, ,3 4} 记住是不重复的，会自动把重复的删了
set1 = set({1:"good", 2:"bad"})
print(set1)  # {1, 2} 只保存key

# 添加
# set的元素不能是列表或者字典，不能直接插入list或者dict，要打碎插入
set1.add(x)
set1.update([6, 7, 8])

# 删除
set1.remove(x)

# 遍历
for i in set1:
    pass
# 手动添加索引的遍历
for index, data in enumerate(set1):
    print(index, data)
    
# & | 交集并集
```

==数据类型转换==

```python
# list --> set
set(list1)

# tuple --> set
set(tuple1)

# set --> list
list(set1)

# set --> tuple
tuple(set1)

# list去重复
list(set(list1))
```



# 进阶语法

## 推导式/迭代器/生成器

基本格式：[**表达式 for 变量 in 旧列表**] 或者 [**表达式 for 变量 in 旧列表 if 条件**]

```python
# 过滤长度小于等于3的人名
names = ['tom','lily','jack','bob','haha']

result = [name for name in names if len(name) > 3]
print(result)

result = [name.capitalize() for name in names if len(name) > 3]  #capitalize()所有单词首字母大写
print(result)
----------------------------------------------------
['lily', 'jack', 'haha']
['Lily', 'Jack', 'Haha']

# 添加if条件
#0~5 偶数  0~9 奇数 构成列表
result = [(x,y) for x in range(5) if x%2 == 0 for y in range(10) if y%2 != 0]  #可以嵌套for循环
print(result)
-------------------------------------------------
[(0, 1), (0, 3), (0, 5), (0, 7), (0, 9), (2, 1), (2, 3), (2, 5), (2, 7), (2, 9), (4, 1), (4, 3), (4, 5), (4, 7), (4, 9)]


# 没有if
list1 = [[2,5,3],[2,5,6],[3,8,9],[7,8,5]]
list2 = [i[-1] for i in list1]
print(list2)
-----------------------------------------------------
[3, 6, 9, 5]

# if ... else
dict1 = {'name':'lili','salary':5000}
dict2 = {'name':'lyly','salary':4000}
dict3 = {'name':'tom','salary':3500}
dict4 = {'name':'jack','salary':8000}
list1 = [dict1,dict2,dict3,dict4]
newlist = [{'name':dict['name'],'salary':dict['salary']+300} if dict['salary']>5000 else {'name':dict['name'],'salary':dict['salary']+800} for dict in list1]
print(newlist)  #dict 表示取出对应键的值,运用dict把更改后的salary在原字典中进行更新
----------------------------------------------------
[{'name': 'lili', 'salary': 5800}, {'name': 'lyly', 'salary': 4800}, {'name': 'tom', 'salary': 4300}, {'name': 'jack', 'salary': 8300}]
```

==集合推导式==

{}类似于列表推导式，在列表推导式的基础上添加一个去除重复项

```python
list1 = [1,2,1,2,5,6,8,9,8,7,9]
set1 = {x for x in list1 if x>5}
print(set1)
----------------------------------------------------
{8, 9, 6, 7}
```

==字典推导式==

```python
dict1 = {'a':'A','b':'B','c':'C','d':'C'}
newdict = {value:key for key,value in dict1.items()}
print(newdict)
-----------------------------------------------------
{'A': 'a', 'B': 'b', 'C': 'd'}
```

==生成器==

通过列表生成式（列表推导式），我们可以直接创建一个列表，但是，受到内存限制，列表容量肯定是有限的。而且，我们创建一个包含100万个元素的列表，那后面绝大多数元素占用的空间都白白浪费了。所以，如果列表元素可以按照某种算法推算出来，那我们是否可以在循环的过程中不断推算出后续的元素呢？这样就不必创建完整的list，从而节省大量的空间，在python中，这种一边循环一边计算的机制，成为生成器：generator。

得到生成器的方式：
**1.通过列表推导式得到生成器**
[] 是列表推导式，（）是生成器

```python
g = (x*3 for x in range(20))
print(type(g))
------------------------------------------------
<class 'generator'>
```

通过使用g.**next**()方式得到元素，或者使用next(g)得到元素，每调用一次则会产生一个元素。
若生成器产生的元素用完，继续调用则会抛出异常**StopIteration**
利用try…except的方式解决异常

```python
g = (x*3 for x in range(10))
while True:
    try:
        e = next(g)
        print(e)
    except:
        print('没有更过元素了')
        break
```

**2.借助函数完成**
只要函数中出现了*yield*关键字，说明函数就不是函数了，是一个生成器，借助于next(),**next**()得到元素

```python
def func():
    n = 0
    while True:
        n += 1
        yield n

g = func()
print(g)  # generator
print(next(g))
```

***斐波那契数列***

```python
def fib(length):
    n=0
    a,b=0,1
    while n < length:
        yield b    #return b 并且暂停
        a,b = b,a+b
        n+=1
    return '没有更多元素'   #当while循环执行完之后，返回return的值
g = fib(8)
print(next(g))
```

send 方法 和__next__()一样 都可以让生成器执行到下一个yield，send可以向yield的位置传递参数,向每次生成器调用中传值，不能给最后一个yield发送值 会报错,第一次执行函数是不能用send,第一次调用sned(None)

==生成器的应用==

**进程 > 线程 > 协程**
概念：比如迅雷下载1.0G的电影，叫做进程，然后迅雷将1.0G的电影按顺序分为10份，这10份叫做线程，然后其中的一份再分为5份，每一份就叫做协程

```python
def task1(n):
    for i in range(n):
        print("正在搬第{}块砖！".format(i))
        yield None
def task2(n):
    for i in range(n):
        print("正在听第{}首歌！".format(i))
        yield None
g1 = task1(6)
g2 = task2(6)
while True:
    try:
        g1.__next__()
        g2.__next__()
    except:
        break
# 交替输出
```

==迭代器==

可迭代的对象：生成器、元组、列表、集合、字典、字符串
如何判断一个对象是否可迭代？

```python
from collections import Iterable
list1 = [1,4,5,6,8]
f = isinstance(list1,Iterable)
print(f)  #True
```

生成器是可迭代的，并且是迭代器；列表是可迭代的，但不是迭代器。
迭代器只能往前不能往后
可以被next()函数调用，不断返回下一个值得对象称为迭代器：Iterator。

```python
list1 = [1,4,5,6,8]
list1 = iter(list1)
print(next(list1))
```

通过iter()函数将可迭代的变成一个迭代器



## 三元表达式

==其他语言的三元表达式==

```python
result = 判定条件? 为真时的结果:为假时的结果
 
# 示例:
result = 5>3? 1:0             # 条件为真是result赋值为1，条件为假时赋值为0
# 常用于if判断语句中
```

==`pyhton` 中的三元表达式==

```python
result = 为真时的结果 if 判断条件 else 为假时的结果
 
# 示例:
>>> x = 1
>>> y = 2
>>> result = x if x > y else y # 如果条件成立，将x的值赋给result
>>> result
2
```

==三元表达式的几个常见的应用==

- 结合函数使用

```python
# 示例一: 求两个参数的最大值
>>> def max(x, y): 
...     return x if x > y else y                           # 取两个值的比较大的
...
>>> max(1, 3)
3
>>>
 
# 示例二: 斐波那契数列
>>> def fib(n):
...     return n if n<2 else fib(n-1)+fib(n-2)
...
>>> [fib(n) for n in range(10)]
[0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
>>>
```

- 结合匿名函数使用

```python
>>> map(lambda x,y:x-y if x>y else y-x, [2,1,3],[4,3,1])  # 两个列表相减并保证不为负
[2, 2, 2]
>>>
```

- 结合列表推导使用

```python
# 示例一: 将0-9的10个数，奇数用0表示，偶数用1表示
>>> [0 if i % 2 == 0 else 1 for i in range(10)]             
[0, 1, 0, 1, 0, 1, 0, 1, 0, 1]
 
# 示例二: 常规写法
>>> x = 100
>>> L = []
>>> L.append(1 if x>0 else 0)
>>> L
[1]
>>>
```



## 断言

在没完善一个程序之前，不知道程序会在哪出错，与其等到程序运行最后崩溃报错，还不如在出现错误的时候就停止运行并报错。

assert用于判断一个表达式，在表达式结果为 False 的时候触发异常。若表达式结果为True，则不做任何反应。

**assert + 空格 + 要判断语句，“报错语句”**

```python
import os
path_txt = "test.txt"
assert os.path.exists(path_txt), "Not found text.txt"

-----------------------------------------------------------------
Traceback (most recent call last):
  File "F:/PycharmProjects/test_assert.py", line 3, in <module>
    assert os.path.exists(path_txt), "Not found text.txt"
AssertionError: Not found text.txt
```



## 异常处理

with…as，就是个[python](https://so.csdn.net/so/search?from=pc_blog_highlight&q=python)控制流语句，像 if ，while一样。
with…as语句是简化版的try except finally语句

==try...except语句==

执行try后面的语句，如果有异常直接跳入except进行捕捉异常，except都能捕捉到哪些python标准异常。请查看[菜鸟笔记](http://www.runoob.com/python/python-exceptions.html)

```python
# try_except捕获异常

try:
  # 加法会报错
  sum = 1 + '1'
  file = open('不存在的文件.txt')
  print(file.read())
  file.close()
# 操作系统方面的异常
# except OSError:
#   print('文件出错！')
# 输出原因
except OSError as reason:
  print('文件出错！\n错误的原因是' + str(reason))
# 多个except
except TypeError as reason:
  print('类型出错！\n错误的原因是' + str(reason))

```

==try...finally语句==

```python
try:  
    execution block  ##正常执行模块  
except A:  
    exc A block ##发生A错误时执行  
except B:  
    exc B block ##发生B错误时执行  
except:  
    other block ##发生除了A,B错误以外的其他错误时执行  
else:  
    if no exception, jump to here ##没有错误时执行  
finally:  
    final block  ##总是执行  
```

==with...as语句==

```python
with expression [as variable]:  
    with-block  

# 等价于
try:  
    执行 __enter__的内容  
    执行 with_block
finally:  
    执行 __exit__内容  
```



正确的例子

```python
class Sample(object):             # object类是所有类最终都会继承的类
    def __enter__(self):          # 类中函数第一个参数始终是self，表示创建的实例本身
        print("In __enter__()")
        return "Foo"

    def __exit__(self, type, value, trace):
        print("In __exit__()")


def get_sample():
    return Sample()

with get_sample() as sample:
    print("sample:", sample)

print(Sample)    # 这个表示类本身   <class '__main__.Sample'>
print(Sample())  # 这表示创建了一个匿名实例对象 <__main__.Sample object at 0x00000259369CF550>

------------------------------------------------------------------------------------------
In __enter__()
sample: Foo
In __exit__()
<class '__main__.Sample'>
<__main__.Sample object at 0x00000226EC5AF550>
```

错误的例子

```python
class Sample:
    def __enter__(self):
        return self

    def __exit__(self, type, value, trace):
        print("type:", type)
        print("value:", value)
        print("trace:", trace)

    def do_something(self):
        bar = 1 / 0
        return bar + 10


with Sample() as sample:
    sample.do_something()

----------------------------------------------------------------------------
type: <class 'ZeroDivisionError'>
value: division by zero
trace: <traceback object at 0x0000019B73153848>
Traceback (most recent call last):
  File "F:/机器学习/生物信息学/Code/first/hir.py", line 16, in <module>
    sample.do_something()
  File "F:/机器学习/生物信息学/Code/first/hir.py", line 11, in do_something
    bar = 1 / 0
ZeroDivisionError: division by zero
```



## lambda函数和其他高级函数

`lambda` 函数语法：`lambda [arg1 [,arg2,.....argn]]:expression`

特性：

- `lambda` 函数都是匿名的
- `lambda` 函数都有输入和输出
- `lambda` 函数拥有自己的命名空间，不能访问自己参数列表之外或者全局命名空间里的参数

```python
lambda x, y: x*y			# 函数输入是x和y，输出是它们的积x*y
lambda:None					# 函数没有输入参数，输出是None
lambda *args: sum(args)		# 输入是任意个数参数，输出是它们的和(隐性要求输入参数必须能进行算术运算)
lambda **kwargs: 1			# 输入是任意键值对参数，输出是1
```

==常见用法==

**1、将lambda函数赋值给一个变量，通过这个变量间接调用该lambda函数。**

```python
add = lambda x, y: x+y
add(1, 2)
----------------------------------------
3
```

**2、将lambda函数赋值给其他函数，从而将其他函数用该lambda函数替换。**

```python
# 为了把标准库time中的函数sleep的功能屏蔽(Mock)，我们可以在程序初始化时调用：
time.sleep=lambda x: None
# 这样，在后续代码中调用time库的sleep函数将不会执行原有的功能。
# 例如：
time.sleep(3)	# 程序不会休眠 3 秒钟，而是因为lambda输出为None，所以这里结果是什么都不做
```

**3、将 `lambda` 函数作为参数传递给其他函数**

==`map()`函数==

语法：`map(function, iterable, ...)` 

根据提供的函数对指定的序列做映射，返回迭代器

```python
# ===========一般写法：===========
# 1、计算平方数
def square(x):
	return x ** 2

map(square, [1,2,3,4,5])	# 计算列表各个元素的平方
# 结果：
[1, 4, 9, 16, 25]

# ===========匿名函数写法：============
# 2、计算平方数，lambda 写法
map(lambda x: x ** 2, [1, 2, 3, 4, 5])
# 结果：
[1, 4, 9, 16, 25]	 

# 3、提供两个列表，将其相同索引位置的列表元素进行相加
map(lambda x, y: x + y, [1, 3, 5, 7, 9], [2, 4, 6, 8, 10])
# 结果：
[3, 7, 11, 15, 19]
```

==`reduce()`函数==

语法：`reduce(function), iterable[, initializer])`

`iterable`：可迭代对象

`reduce()` 函数会对参数序列中元素进行**累积**，返回函数计算结果（map是返回迭代器的一个序列，reduce还做了累加）

```python
# ===========一般写法：===========
# 1、两数相加
def add(x, y):            
	return x + y

reduce(add, [1, 3, 5, 7, 9])    # 计算列表元素和：1+3+5+7+9
# 结果：
25

"""
===========执行步骤解析：===========
调用 reduce(add, [1, 3, 5, 7, 9])时，reduce函数将做如下计算：
1	先计算头两个元素：f(1, 3)，结果为4；
2	再把结果和第3个元素计算：f(4, 5)，结果为9；
3	再把结果和第4个元素计算：f(9, 7)，结果为16；
4	再把结果和第5个元素计算：f(16, 9)，结果为25；
5	由于没有更多的元素了，计算结束，返回结果25。
"""
# ===========匿名函数写法：===========
# 2、两数相加，lambda 写法
reduce(lambda x, y: x + y, [1, 2, 3, 4, 5])
# 结果：
15

# 当然求和运算可以直接用Python内建函数sum()，没必要动用reduce。
	
# 3、但是如果要把序列 [1, 3, 5, 7, 9] 变换成整数 13579，reduce就可以派上用场：
from functools import reduce

def fn(x, y):
	return x * 10 + y

reduce(fn, [1, 3, 5, 7, 9])
# 结果：
13579
```

==`sorted()` 函数==

`sorted()` 函数对所有可迭代的对象进行`排序操作`。

sort 与 sorted 区别：
sort 是 list 的一个方法，而 sorted 可以对所有可迭代的对象进行排序操作。
list 的 sort 方法返回的是对已经存在的列表进行操作，无返回值，而内建函数 sorted 方法返回的是一个新的 list，而不是在原来的基础上进行的操作。

语法：`sorted(iterable[, cmp[, key[, reverse]]])`，返回重新排序的列表

- 参数说明：

- iterable  ----> 可迭代对象
- cmp       ----> 比较的函数，这个具有两个参数，参数的值都是从可迭代对象中取出，此函数必须遵守的规则为，大于则返回1，小于则返回-1，等于则返回0。
- key        ----> 主要是用来进行比较的元素，只有一个参数，具体的函数的参数就是取自于可迭代对象中，指定可迭代对象中的一个元素来进行排序。
- reverse  ----> 排序规则，reverse = True 降序 ， reverse = False 升序（默认）。

```python
# ===========一般用法：===========
# 1、简单排序
a = [5,7,6,3,4,1,2]
b = sorted(a)       # 使用sorted，保留原列表，不改变列表a的值
print(a)
[5, 7, 6, 3, 4, 1, 2]
print(b)
[1, 2, 3, 4, 5, 6, 7]

# ===========匿名函数用法：===========
L=[('b',2),('a',1),('c',3),('d',4)]
# 2、利用参数 cmp 排序
sorted(L, cmp=lambda x,y:cmp(x[1],y[1]))
# 结果：
[('a', 1), ('b', 2), ('c', 3), ('d', 4)]
# 3、利用参数 key 排序
sorted(L, key=lambda x:x[1])
# 结果：
[('a', 1), ('b', 2), ('c', 3), ('d', 4)]

# 4、按年龄升序
students = [('john', 'A', 15), ('jane', 'B', 12), ('dave', 'B', 10)]
sorted(students, key=lambda s: s[2])
# 结果：
[('dave', 'B', 10), ('jane', 'B', 12), ('john', 'A', 15)]
# 5、按年龄降序
sorted(students, key=lambda s: s[2], reverse=True)
# 结果：
[('john', 'A', 15), ('jane', 'B', 12), ('dave', 'B', 10)]
```

==`filter()` 函数==

`filter()` 函数用于过滤序列，过滤掉不符合条件的元素，返回由符合条件元素组成的新列表。

语法：`filter(function, iterable)`

```python
# ===========一般用法：===========
# 1、过滤出列表中的所有奇数
def is_odd(n):
	return n % 2 == 1
		 
newlist = filter(is_odd, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
print(list(newlist))
# 结果： [1, 3, 5, 7, 9]

# ===========匿名函数用法：===========
# 2、将列表[1, 2, 3]中能够被3整除的元素过滤出来
newlist = filter(lambda x: x % 3 == 0, [1, 2, 3])
print(list(newlist))
# 结果： [3]
```



## 字符编码与解码

Python 3的源码.py文件 的默认编码方式为UTF-8，所以在Python3中你可以不用在py脚本中写coding声明，并且系统传递给python的字符不再受系统默认编码的影响，统一为unicode编码。

# IO编程

## 输入和输出

==输出格式美化==

Python两种输出值的方式: 表达式语句和 print() 函数。

第三种方式是使用文件对象的 write() 方法，标准输出文件可以用 sys.stdout 引用。

如果你希望输出的形式更加多样，可以使用 str.format() 函数来格式化输出值。

如果你希望将输出的值转成字符串，可以使用 repr() 或 str() 函数来实现。

* `str()：` 函数返回一个用户易读的表达形式。
* `repr()：` 产生一个解释器易读的表达形式。

==`print()`==

```python
>>> for x in range(1, 11):
...     print(repr(x).rjust(2), repr(x*x).rjust(3), end=' ')
...     # 注意前一行 'end' 的使用
...     print(repr(x*x*x).rjust(4))
...
 1   1    1
 2   4    8
 3   9   27
 4  16   64
 5  25  125
 6  36  216
 7  49  343
 8  64  512
 9  81  729
10 100 1000

for x in range(1, 11):
    # :2d,:3d:4d 是间隔
    print('{0:2d} {1:3d} {2:4d}'.format(x, x*x, x*x*x))

 1   1    1
 2   4    8
 3   9   27
 4  16   64
 5  25  125
 6  36  216
 7  49  343
 8  64  512
 9  81  729
10 100 1000
```

==`format()`用法==

```python
# 位置参数
>>> print('{0} 和 {1}'.format('Google', 'Runoob'))
Google 和 Runoob
>>> print('{1} 和 {0}'.format('Google', 'Runoob'))
Runoob 和 Google

# 关键字参数
>>> print('{name}网址： {site}'.format(name='菜鸟教程', site='www.runoob.com'))
菜鸟教程网址： www.runoob.com

# 关键字组合位置参数
>>> print('站点列表 {0}, {1}, 和 {other}。'.format('Google', 'Runoob', other='Taobao'))
站点列表 Google, Runoob, 和 Taobao

# !a (使用 ascii()), !s (使用 str()) 和 !r (使用 repr()) 可以用于在格式化某个值之前对其进行转化:
>>> import math
>>> print('常量 PI 的值近似为： {}。'.format(math.pi))
常量 PI 的值近似为： 3.141592653589793。
>>> print('常量 PI 的值近似为： {!r}。'.format(math.pi))
常量 PI 的值近似为： 3.141592653589793。

# 格式标识符可以跟着字段名。 这就允许对值进行更好的格式化。 下面的例子将 Pi 保留到小数点后三位：
>>> import math
>>> print('常量 PI 的值近似为 {0:.3f}。'.format(math.pi))
常量 PI 的值近似为 3.142。

# 在 : 后传入一个整数, 可以保证该域至少有这么多的宽度。 用于美化表格时很有用。
>>> table = {'Google': 1, 'Runoob': 2, 'Taobao': 3}
>>> for name, number in table.items():
...     print('{0:10} ==> {1:10d}'.format(name, number))
...
Google     ==>          1
Runoob     ==>          2
Taobao     ==>          3

# 如果你有一个很长的格式化字符串, 而你不想将它们分开, 那么在格式化时通过变量名而非位置会是很好的事情。
# 最简单的就是传入一个字典, 然后使用方括号 [] 来访问键值 :
>>> table = {'Google': 1, 'Runoob': 2, 'Taobao': 3}
>>> print('Runoob: {0[Runoob]:d}; Google: {0[Google]:d}; Taobao: {0[Taobao]:d}'.format(table))
Runoob: 2; Google: 1; Taobao: 3
            
# 也可以通过在 table 变量前使用 ** 来实现相同的功能：
>>> table = {'Google': 1, 'Runoob': 2, 'Taobao': 3}
>>> print('Runoob: {Runoob:d}; Google: {Google:d}; Taobao: {Taobao:d}'.format(**table))
Runoob: 2; Google: 1; Taobao: 3
```

==`input()`用法==

从标准输入读入一行文本，默认的标准输入是键盘。

```python
#!/usr/bin/python3

str = input("请输入：");
```

==读和写文件==

使用`open()`函数返回一个`file`对象

`open(filename, mode)`

<img src="https://tva1.sinaimg.cn/large/008i3skNgy1gwx93kj69aj30z00l0q4t.jpg" alt="截屏2021-11-30 下午4.21.40" style="zoom:50%;" />

```python
#!/usr/bin/python3

# 打开一个文件
f = open("/tmp/foo.txt", "w")

f.write( "Python 是一个非常好的语言。\n是的，的确非常好!!\n" )

# 关闭打开的文件
f.close()
```

==文件对象的方法==

**f.read()**

为了读取一个文件的内容，调用 f.read(size), 这将读取一定数目的数据, 然后作为字符串或字节对象返回。

size 是一个可选的数字类型的参数。 当 size 被忽略了或者为负, 那么该文件的所有内容都将被读取并且返回。

以下实例假定文件 foo.txt 已存在（上面实例中已创建）：

```python
#!/usr/bin/python3

# 打开一个文件
f = open("/tmp/foo.txt", "r")

str = f.read()
print(str)

# 关闭打开的文件
f.close()

--------------------------
Python 是一个非常好的语言。
是的，的确非常好!!
```

**f.readline()**

f.readline() 会从文件中读取单独的一行。换行符为 '\n'。f.readline() 如果返回一个空字符串, 说明已经已经读取到最后一行。

```python
#!/usr/bin/python3

# 打开一个文件
f = open("/tmp/foo.txt", "r")

str = f.readline()
print(str)

# 关闭打开的文件
f.close()

-----------------------------
Python 是一个非常好的语言。
```

**f.readlines()**

f.readlines() 将返回该文件中包含的所有行。

如果设置可选参数 sizehint, 则读取指定长度的字节, 并且将这些字节按行分割。

```python
#!/usr/bin/python3

# 打开一个文件
f = open("/tmp/foo.txt", "r")

str = f.readlines()
print(str)

# 关闭打开的文件
f.close()

--------------------------------------
['Python 是一个非常好的语言。\n', '是的，的确非常好!!\n']
```

**迭代读取**

```python
#!/usr/bin/python3

# 打开一个文件
f = open("/tmp/foo.txt", "r")

for line in f:
    print(line, end='')

# 关闭打开的文件
f.close()

-----------------------------------
Python 是一个非常好的语言。
是的，的确非常好!!
```

**f.write()**

f.write(string) 将 string 写入到文件中, 然后返回写入的字符数。

```python
#!/usr/bin/python3

# 打开一个文件
f = open("/tmp/foo.txt", "w")

num = f.write( "Python 是一个非常好的语言。\n是的，的确非常好!!\n" )
print(num)
# 关闭打开的文件
f.close()

------------------------------------
29
```

**如果要写入一些不是字符串的东西, 那么将需要先进行转换:**

```python
#!/usr/bin/python3

# 打开一个文件
f = open("/tmp/foo1.txt", "w")

value = ('www.runoob.com', 14)
s = str(value)
f.write(s)

# 关闭打开的文件
f.close()

-------------------------------------
$ cat /tmp/foo1.txt 
('www.runoob.com', 14)
```

**f.tell()**

f.tell() 返回文件对象当前所处的位置, 它是从文件开头开始算起的字节数。

**f.seek()**

如果要改变文件当前的位置, 可以使用 f.seek(offset, from_what) 函数。

from_what 的值, 如果是 0 表示开头, 如果是 1 表示当前位置, 2 表示文件的结尾，例如：

* seek(x,0) ： 从起始位置即文件首行首字符开始移动 x 个字符
* seek(x,1) ： 表示从当前位置往后移动x个字符
* seek(-x,2)：表示从文件的结尾往前移动x个字符

from_what 值为默认为0，即文件开头。下面给出一个完整的例子：

```python
>>> f = open('/tmp/foo.txt', 'rb+')
>>> f.write(b'0123456789abcdef')
16
>>> f.seek(5)     # 移动到文件的第六个字节
5
>>> f.read(1)
b'5'
>>> f.seek(-3, 2) # 移动到文件的倒数第三字节
13
>>> f.read(1)
b'd'
```

**f.close()**

在文本文件中 (那些打开文件的模式下没有 b 的), 只会相对于文件起始位置进行定位。

当你处理完一个文件后, 调用 f.close() 来关闭文件并释放系统的资源，如果尝试再调用该文件，则会抛出异常。

```python
>>> f.close()
>>> f.read()
Traceback (most recent call last):
  File "<stdin>", line 1, in ?
ValueError: I/O operation on closed file
    
# with as方法
>>> with open('/tmp/foo.txt', 'r') as f:
...     read_data = f.read()
>>> f.closed
True
```

## pickle 模块

python的pickle模块实现了基本的数据序列和反序列化。

通过pickle模块的序列化操作我们能够将程序中运行的对象信息保存到文件中去，永久存储。

通过pickle模块的反序列化操作，我们能够从文件中创建上一次程序保存的对象。

基本接口：

```python
pickle.dump(obj, file, [,protocol])
```

**注解：**从 file 中读取一个字符串，并将它重构为原来的python对象。

**file:** 类文件对象，有read()和readline()接口。

```python
#!/usr/bin/python3
import pickle

# 使用pickle模块将数据对象保存到文件
data1 = {'a': [1, 2.0, 3, 4+6j],
         'b': ('string', u'Unicode string'),
         'c': None}

selfref_list = [1, 2, 3]
selfref_list.append(selfref_list)

output = open('data.pkl', 'wb')

# Pickle dictionary using protocol 0.
pickle.dump(data1, output)

# Pickle the list using the highest protocol available.
pickle.dump(selfref_list, output, -1)

output.close()
```

```python
#!/usr/bin/python3
import pprint, pickle

#使用pickle模块从文件中重构python对象
pkl_file = open('data.pkl', 'rb')

data1 = pickle.load(pkl_file)
pprint.pprint(data1)

data2 = pickle.load(pkl_file)
pprint.pprint(data2)

pkl_file.close()
```

# 常用模块

## datetime

```python
from datetime import datetime

# 获取当前时间
now = datetime.now()

# 构造datetime . 2022-1-1 12:00:00
dt = datetime(2022, 1, 1, 12, 0)

# datetime转换为timestamp。timestamp为1970年1月1日0点的0时区的时间，到现在的秒数
t = dt.timestamp()

datetime.formtimestamp(t) # 本地时间
datetime.utcfromtimestamp(t) # utc时间

# str转换为datetime
cday = datetime.strptime("2022-1-1 12:00:00", "%Y-%m-%d %H:%M:%S")

# datetime转化为str
dt.strftime("%a, %b %d %H:%M")

# datetime加减
dt + timedelta(hours=10)

# 本地时间转UTC时间再转时区
```



## collections

collections是Python内建的一个**集合模块**，提供了许多有用的集合类。

==namedtuple==

元组`tuple`可以表示不变集合。像表示一个点的二维坐标x, y可以用`nametuple`。

```python
>>> from collections import namedtuple
>>> Point = namedtuple('Point', ['x', 'y'])  # 创建的Point对象是tuple的一种子类：
# 对象 = namedtuple('子类名称', [属性list]):
>>> p = Point(1, 2)
>>> p.x
1
>>> p.y
2
```

==deque==

使用`list`存储数据时，按索引访问元素很快，但是插入和删除元素就很慢了，因为`list`是线性存储，数据量大的时候，插入和删除效率很低。

deque是为了高效实现插入和删除操作的**双向列表**，适合用于队列和栈：

```python
list1.append(x)  # 尾部插入
list1.pop()  # 尾部删除
list1.appendleft(x) # 头部插入
list1.popleft()  # 头部删除
```

==defaultdict==

使用`dict`时，如果引用的`key`不存在，就会抛出`KeyError`，如果希望`key`不存在时，返回一个默认值，就可以用`defauldict`

```python
>>> from collections import defaultdict
>>> dd = defaultdict(lambda: 'N/A')
>>> dd['key1'] = 'abc'
>>> dd['key1'] # key1存在
'abc'
>>> dd['key2'] # key2不存在，返回默认值
'N/A'
```

==OrderrdDict==

使用`dict`时，`Key`是无序的。在对`dict`做迭代时，无法确定`Key`的顺序，若要保持`Key`的顺序，可以使用`OrderedDict`

```python
>>> from collections import OrderedDict
>>> d = dict([('a', 1), ('b', 2), ('c', 3)])
>>> d # dict的Key是无序的
{'a': 1, 'c': 3, 'b': 2}
>>> od = OrderedDict([('a', 1), ('b', 2), ('c', 3)])
>>> od # OrderedDict的Key是有序的
OrderedDict([('a', 1), ('b', 2), ('c', 3)])
```

**OrderedDict**会按照`Key`插入的顺序排列，不是`key`本身的顺序

`OrderedDict`可以实现一个FIFO（先进先出）的dict，当容量超出限制时，先删除最早添加的Key：

```python
from collections import OrderedDict

class LastUpdatedOrderedDict(OrderedDict):

    def __init__(self, capacity):
        super(LastUpdatedOrderedDict, self).__init__()
        self._capacity = capacity

    def __setitem__(self, key, value):
        containsKey = 1 if key in self else 0
        if len(self) - containsKey >= self._capacity:
            last = self.popitem(last=False)
            print('remove:', last)
        if containsKey:
            del self[key]
            print('set:', (key, value))
        else:
            print('add:', (key, value))
        OrderedDict.__setitem__(self, key, value)
```

==Counter==

`Counter`是一个简单的计数器，也是`dict`的子类，例如，统计字符出现的个数：

```python
>>> from collections import Counter
>>> c = Counter()
>>> for ch in 'programming':
...     c[ch] = c[ch] + 1
...
>>> c
Counter({'g': 2, 'm': 2, 'r': 2, 'a': 1, 'i': 1, 'o': 1, 'n': 1, 'p': 1})
>>> c.update('hello') # 也可以一次性update
>>> c
Counter({'r': 2, 'o': 2, 'g': 2, 'm': 2, 'l': 2, 'p': 1, 'a': 1, 'i': 1, 'n': 1, 'h': 1, 'e': 1})
```

==ChainMap==

`ChainMap`可以把一组`dict`串起来并组成一个逻辑上的`dict`。`ChainMap`本身也是一个dict，但是查找的时候，会按照顺序在内部的dict依次查找。

什么时候使用`ChainMap`最合适？举个例子：应用程序往往都需要传入参数，参数可以通过命令行传入，可以通过环境变量传入，还可以有默认参数。我们可以用`ChainMap`实现参数的优先级查找，即先查命令行参数，如果没有传入，再查环境变量，如果没有，就使用默认参数。

下面的代码演示了如何查找`user`和`color`这两个参数：

```python
from collections import ChainMap
import os, argparse

# 构造缺省参数:
defaults = {
    'color': 'red',
    'user': 'guest'
}

# 构造命令行参数:
parser = argparse.ArgumentParser()
parser.add_argument('-u', '--user')
parser.add_argument('-c', '--color')
namespace = parser.parse_args()
command_line_args = { k: v for k, v in vars(namespace).items() if v }

# 组合成ChainMap:
combined = ChainMap(command_line_args, os.environ, defaults)

# 打印参数:
print('color=%s' % combined['color'])
print('user=%s' % combined['user'])

---------------------------------------------
# 没有任何参数时，打印出默认参数：
$ python3 use_chainmap.py 
color=red
user=guest
---------------------------------------------
# 当传入命令行参数时，优先使用命令行参数：
$ python3 use_chainmap.py -u bob
color=red
user=bob
---------------------------------------------
# 同时传入命令行参数和环境变量，命令行参数的优先级较高：
$ user=admin color=green python3 use_chainmap.py -u bob
color=green
user=bob
```

## base64

Base64是一种任意二进制到文本字符串的编码方法，常用于在URL、Cookie、网页中传输少量二进制数据。

## struct

Python提供了一个`struct`模块来解决`bytes`和其他二进制数据类型的转换。

## hashlib

`Python`的`hashlib`提供了常见的摘要算法，如`MD5，SHA1`等等。

摘要算法又称哈希算法、散列算法。它通过一个函数，把任意长度的数据转换为一个长度固定的数据串（通常用16进制的字符串表示）。

类似于“账户和密码必须匹配”等判断用户口令是否正确等。用保存在数据库中的`password_md5`对比计算`md5(password)`的结果

## hmac

为了防止黑客通过彩虹表根据哈希值反推原始口令，在计算哈希的时候，不能仅针对原始输入计算，需要增加一个salt来使得相同的输入也能得到不同的哈希，这样，大大增加了黑客破解的难度。

如果salt是我们自己随机生成的，通常我们计算MD5时采用`md5(message + salt)`。但实际上，把salt看做一个“口令”，加salt的哈希就是：计算一段message的哈希时，根据不同口令计算出不同的哈希。要验证哈希值，必须同时提供正确的口令。

这实际上就是Hmac算法：Keyed-Hashing for Message Authentication。它通过一个标准算法，在计算哈希的过程中，把key混入计算过程中。

和我们自定义的加salt算法不同，Hmac算法针对所有哈希算法都通用，无论是MD5还是SHA-1。采用Hmac替代我们自己的salt算法，可以使程序算法更标准化，也更安全。

## itertools

Python的内建模块`itertools`提供了非常有用的用于操作迭代对象的函数。

```python
import itertools
a = itertools.count(1)  # count 创建的无限计数迭代器
for n in a:
    print(n)

 ----------------------------
1
2
...

# cycle()函数会把传入的序列无限重复
b = itertools.cycle('AB')
for n in b:
    print(n)
    
------------------------------
'A'
'B'
'A'
'B'
...

# repeat()函数也是重复，不过提供第二个参数可以限定重复次数
c = itertools.repeat('A', 2)
for n in c:
    print(n)
    
------------------------------
'A'
'A'

# 无限序列只有在for迭代时才会无限地迭代下去，
# 如果只是创建了一个迭代对象，它不会事先把无限个元素生成出来，
# 事实上也不可能在内存中创建无限多个元素。
# 无限序列虽然可以无限迭代下去，
# 但是通常我们会通过takewhile()等函数根据条件判断来截取出一个有限的序列：
d = itertools.count(1)
ds = itertools.takewhile(lambda x: x <= 10, d)
list(ds)
-----------------------------
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

==`chain()`函数==

`chain()`可以把一组迭代对象串联起来，形成一个更大的迭代器：

```python
for n in itertools.chain("AB", 'XY'):
    print(n)
  
----------------------------------
'A'
'B'
'X'
'Y'
```

==`groupby()`函数==

`groupby()`把迭代器中相邻的重复元素挑出来放在一起：

```python
for key, group in itertools.groupby("AAABB"):
    print(key, list(group))
  
-----------------------
A ['A', 'A', 'A']
B ['B', 'B']

# key忽略大小写
for key, group in itertools.groupby("AaaBb", lambda c: c.upper()):
	print(key, list(group))
   
----------------------
A ['A', 'a', 'a']
B ['B', 'b']

```

## contexlib

在Python中，读写文件这样的资源要特别注意，必须在使用完毕后正确关闭它们。正确关闭文件资源的一个方法是使用`try...finally`：

```python
try:
    f = open('/path/to/file', 'r')
    f.read()
finally:
    if f:
        f.close()
```

写`try...finally`非常繁琐。Python的`with`语句允许我们非常方便地使用资源，而不必担心资源没有关闭，所以上面的代码可以简化为：

```python
with open('/path/to/file', 'r') as f:
    f.read()
```

并不是只有`open()`函数返回的fp对象才能使用`with`语句。实际上，任何对象，只要正确实现了上下文管理，就可以用于`with`语句。

实现上下文管理是通过`__enter__`和`__exit__`这两个方法实现的。例如，下面的class实现了这两个方法：

```python
class Query(object):

    def __init__(self, name):
        self.name = name

    def __enter__(self):
        print('Begin')
        return self
    
    def __exit__(self, exc_type, exc_value, traceback):
        if exc_type:
            print('Error')
        else:
            print('End')
    
    def query(self):
        print('Query info about %s...' % self.name)
```

这样我们就可以把自己写的资源对象用于`with`语句：

```python
with Query('Bob') as q:
    q.query()
```

编写`__enter__`和`__exit__`仍然很繁琐，因此Python的标准库`contextlib`提供了更简单的写法，上面的代码可以改写如下：

```python
from contextlib import contextmanager

class Query(object):

    def __init__(self, name):
        self.name = name

    def query(self):
        print('Query info about %s...' % self.name)

@contextmanager
def create_query(name):
    print('Begin')
    q = Query(name)
    yield q
    print('End')
```

`@contextmanager`这个decorator接受一个generator，用`yield`语句把`with ... as var`把变量输出出去，然后，`with`语句就可以正常地工作了：

```python
with create_query('Bob') as q:
    q.query()
```

很多时候，我们希望在某段代码执行前后自动执行特定代码，也可以用`@contextmanager`实现。例如：

```python
@contextmanager
def tag(name):
    print("<%s>" % name)
    yield
    print("</%s>" % name)

with tag("h1"):
    print("hello")
    print("world")
    
--------------------------------------------
<h1>
hello
world
</h1>
```

代码的执行顺序是：

1. `with`语句首先执行`yield`之前的语句，因此打印出`<h1>`；
2. `yield`调用会执行`with`语句内部的所有语句，因此打印出`hello`和`world`；
3. 最后执行`yield`之后的语句，打印出`</h1>`。

因此，`@contextmanager`让我们通过编写generator来简化上下文管理。

==`closing()`函数==

如果一个对象没有实现上下文，我们就不能把它用于`with`语句。这个时候，可以用`closing()`来把该对象变为上下文对象。例如，用`with`语句使用`urlopen()`：

```python
from contextlib import closing
from urllib.request import urlopen

with closing(urlopen('https://www.python.org')) as page:
    for line in page:
        print(line)
```

`closing`也是一个经过@contextmanager装饰的generator，这个generator编写起来其实非常简单：

```python
@contextmanager
def closing(thing):
    try:
        yield thing
    finally:
        thing.close()
```

它的作用就是把任意对象变为上下文对象，并支持`with`语句。

## urllib

urllib提供的功能就是利用程序去执行各种HTTP请求。如果要模拟浏览器完成特定功能，需要把请求伪装成浏览器。伪装的方法是先监控浏览器发出的请求，再根据浏览器的请求头来伪装，`User-Agent`头就是用来标识浏览器的。

## XML

解析XML时，注意找出自己感兴趣的节点，响应事件时，把节点数据保存起来。解析完毕后，就可以处理数据。

## HTMLParser

如果我们要编写一个搜索引擎，第一步是用爬虫把目标网站的页面抓下来，第二步就是解析该HTML页面，看看里面的内容到底是新闻、图片还是视频。

假设第一步已经完成了，第二步应该如何解析HTML呢？

HTML本质上是XML的子集，但是HTML的语法没有XML那么严格，所以不能用标准的DOM或SAX来解析HTML。

好在Python提供了HTMLParser来非常方便地解析HTML

利用HTMLParser，可以把网页中的文本、图像等解析出来。

# 面向对象

## 类和实例

如果没有合适的继承类，就使用`object`类，这是所有类最终都会继承的类。

> 1. 定义类
> 2. 创建实例
> 3. `__init__`方法绑定属性

面向对象编程的一个重要特点就是**数据封装**。

## 访问限制

**私有变量private**：在变量名前面加`__`

如果要访问私有变量，添加访问的方法

你会看到以一个下划线开头的实例变量名，比如`_name`，这样的实例变量外部是可以访问的，但是，按照约定俗成的规定，当你看到这样的变量时，意思就是，“虽然我可以被访问，但是，请把我视为私有变量，不要随意访问”

在Python中，变量名类似`__xxx__`的，也就是以双下划线开头，并且以双下划线结尾的，是特殊变量，特殊变量是可以直接访问的，不是private变量

## 继承和多态

在OOP程序设计中，当我们定义一个class的时候，可以从某个现有的class继承，新的class称为子类（Subclass），而被继承的class称为基类、父类或超类（Base class、Super class）。

比如，我们已经编写了一个名为`Animal`的class，有一个`run()`方法可以直接打印：

```python
class Animal(object):
    def run(self):
        print('Animal is running...')
```

当我们需要编写`Dog`和`Cat`类时，就可以直接从`Animal`类继承：

```python
class Dog(Animal):
    pass

class Cat(Animal):
    pass
```

对于`Dog`来说，`Animal`就是它的父类，对于`Animal`来说，`Dog`就是它的子类。`Cat`和`Dog`类似。

*继承有什么好处？*

- 最大的好处是子类获得了父类的全部功能。由于`Animial`实现了`run()`方法，因此，`Dog`和`Cat`作为它的子类，什么事也没干，就自动拥有了`run()`方法：
- 当子类和父类都存在相同的`run()`方法时，我们说，子类的`run()`覆盖了父类的`run()`，在代码运行的时候，总是会调用子类的`run()`。这样，我们就获得了继承的另一个好处：多态。

要理解什么是多态，我们首先要对数据类型再作一点说明。当我们定义一个class的时候，我们实际上就定义了一种数据类型。我们定义的数据类型和Python自带的数据类型，比如str、list、dict没什么两样：

```python
a = list() # a是list类型
b = Animal() # b是Animal类型
c = Dog() # c是Dog类型

# 判断一个变量是否是某个类型可以用isinstance()判断：

>>> isinstance(a, list)
True
>>> isinstance(b, Animal)
True
>>> isinstance(c, Dog)
True

# c不仅仅是Dog，c还是Animal！

```

**在继承关系中，如果一个实例的数据类型是某个子类，那它的数据类型也可以被看做是父类。**

要理解多态的好处，我们还需要再编写一个函数，这个函数接受一个`Animal`类型的变量：

```python
def run_twice(animal):
    animal.run()
    animal.run()
    
# 当我们传入Animal的实例时，run_twice()就打印出：
>>> run_twice(Animal())
Animal is running...
Animal is running...

# 当我们传入Dog的实例时，run_twice()就打印出：
>>> run_twice(Dog())
Dog is running...
Dog is running...

# 当我们传入Cat的实例时，run_twice()就打印出：
>>> run_twice(Cat())
Cat is running...
Cat is running...

# 看上去没啥意思，但是仔细想想，现在，如果我们再定义一个Tortoise类型，也从Animal派生：
class Tortoise(Animal):
    def run(self):
        print('Tortoise is running slowly...')

# 当我们调用run_twice()时，传入Tortoise的实例：
>>> run_twice(Tortoise())
Tortoise is running slowly...
Tortoise is running slowly...
```

多态的好处就是，当我们需要传入`Dog`、`Cat`、`Tortoise`……时，我们只需要接收`Animal`类型就可以了，因为`Dog`、`Cat`、`Tortoise`……都是`Animal`类型，然后，按照`Animal`类型进行操作即可。由于`Animal`类型有`run()`方法，因此，传入的任意类型，只要是`Animal`类或者子类，就会自动调用实际类型的`run()`方法，这就是多态的意思：

对于一个变量，我们只需要知道它是`Animal`类型，无需确切地知道它的子类型，就可以放心地调用`run()`方法，而具体调用的`run()`方法是作用在`Animal`、`Dog`、`Cat`还是`Tortoise`对象上，由运行时该对象的确切类型决定，这就是多态真正的威力：调用方只管调用，不管细节，而当我们新增一种`Animal`的子类时，只要确保`run()`方法编写正确，不用管原来的代码是如何调用的。这就是著名的**“开闭”原则**：

**对扩展开放：允许新增`Animal`子类；**

**对修改封闭：不需要修改依赖`Animal`类型的`run_twice()`等函数。**

继承还可以一级一级地继承下来，就好比从爷爷到爸爸、再到儿子这样的关系。而任何类，最终都可以追溯到根类object，这些继承关系看上去就像一颗倒着的树。

==静态语言 vs 动态语言==

对于静态语言（例如Java）来说，如果需要传入`Animal`类型，则传入的对象必须是`Animal`类型或者它的子类，否则，将无法调用`run()`方法。

对于Python这样的动态语言来说，则不一定需要传入`Animal`类型。我们只需要保证传入的对象有一个`run()`方法就可以了，比如`Animal`类型的子类



## 获取对象信息

==`type()` 函数==

```python
>>> type(123)
<class 'int'>
>>> type('str')
<class 'str'>
>>> type(None)
<type(None) 'NoneType'>
----------------------------------------------------
>>> type(abs)
<class 'builtin_function_or_method'>
>>> type(a)
<class '__main__.Animal'>
```

==`isinstance()` 函数==

对于class的继承关系来说，使用`type()`就很不方便。

继承关系是：`object -> Animal -> Dog -> Husky`

```python
>>> a = Animal()
>>> d = Dog()
>>> h = Husky()

>>> isinstance(h, Husky)
True

>>> isinstance(h, Dog)
True

>>> isinstance(h, Animal)
True

>>> isinstance(d, Husky)
False

------------------------------------
# 判断基本类型
>>> isinstance('a', str)
True
>>> isinstance(123, int)
True
>>> isinstance(b'a', bytes)
True

------------------------------------
>>> isinstance([1, 2, 3], (list, tuple))
True
>>> isinstance((1, 2, 3), (list, tuple))
True
```

==`dir() `函数==

如果要获得**一个对象的所有属性和方法**，可以使用`dir()`函数，它返回一个包含字符串的list，比如，获得一个str对象的所有属性和方法：

```pyhton
>>> dir('ABC')
['__add__', '__class__',..., '__subclasshook__', 'capitalize', 'casefold',..., 'zfill']
```

类似`__xxx__`的属性和方法在Python中都是有特殊用途的，比如`__len__`方法返回长度。在Python中，如果你调用`len()`函数试图获取一个对象的长度，实际上，在`len()`函数内部，它自动去调用该对象的`__len__()`方法，所以，下面的代码是等价的

```python
>>> len("ABC")
3
>>> "ABC".__len__()
3
```

我们自己写的类，如果也想用`len(myObj)`的话，就自己写一个`__len__()`方法：

```python
>>> class MyDog(object):
...     def __len__(self):
...         return 100
...
>>> dog = MyDog()
>>> len(dog)
100
```

仅仅把属性和方法列出来是不够的，配合`getattr()`、`setattr()`以及`hasattr()`，我们可以直接操作一个对象的状态：

```python
>>> class MyObject(object):
...     def __init__(self):
...         self.x = 9
...     def power(self):
...         return self.x * self.x
...
>>> obj = MyObject()
```

测试对象的属性

```python
>>> hasattr(obj, 'x') # 有属性'x'吗？
True
>>> obj.x
9
>>> hasattr(obj, 'y') # 有属性'y'吗？
False
>>> setattr(obj, 'y', 19) # 设置一个属性'y'
>>> hasattr(obj, 'y') # 有属性'y'吗？
True
>>> getattr(obj, 'y') # 获取属性'y'
19
>>> obj.y # 获取属性'y'
19
```

## 实例属性和类属性

由于Python是动态语言，根据类创建的实例可以任意绑定属性。

给实例绑定属性的方法是通过实例变量，或者通过`self`变量：

```python
class Student(object):
    def __init__(self, name):
        self.name = name

s = Student('Bob')
s.score = 90
```

但是，如果`Student`类本身需要绑定一个属性呢？可以直接在class中定义属性，这种属性是类属性，归`Student`类所有：

```python
class Student(object):
    name = 'Student'
```

当我们定义了一个类属性后，这个属性虽然归类所有，但类的所有实例都可以访问到.

## 使用`__slots__`

正常情况下，当我们定义了一个class，创建了一个class的实例后，我们可以给该实例绑定任何属性和方法，这就是动态语言的灵活性。

```python
# 先定义class：
class Student(object):
    pass

# 给实例绑定一个属性：
>>> s = Student()
>>> s.name = 'Michael' # 动态给实例绑定一个属性
>>> print(s.name)
Michael

# 给实例绑定一个方法：
>>> def set_age(self, age): # 定义一个函数作为实例方法
...     self.age = age
...
>>> from types import MethodType
>>> s.set_age = MethodType(set_age, s) # 给实例绑定一个方法
>>> s.set_age(25) # 调用实例方法
>>> s.age # 测试结果
25

# 给一个实例绑定的方法，对另一个实例是不起作用的：
>>> s2 = Student() # 创建新的实例
>>> s2.set_age(25) # 尝试调用方法
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'Student' object has no attribute 'set_age'
    
# 为了给所有实例都绑定方法，可以给class绑定方法：
>>> def set_score(self, score):
...     self.score = score
...
>>> Student.set_score = set_score
# 给class绑定方法之后，所有实例均可调用
```

通常情况下，上面的`set_score`方法可以直接定义在class中，但动态绑定允许我们在程序运行的过程中动态给class加上功能，这在静态语言中很难实现。

==`__slots__`==

Python允许在定义class的时候，定义一个特殊的`__slots__`变量，来限制该class实例能添加的属性：

```python
class Student(object):
    __slots__ = ('name', 'age') # 用tuple定义允许绑定的属性名称
    
-----------------------------------------------------
>>> s = Student() # 创建新的实例
>>> s.name = 'Michael' # 绑定属性'name'
>>> s.age = 25 # 绑定属性'age'
>>> s.score = 99 # 绑定属性'score'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'Student' object has no attribute 'score'
```

使用`__slots__`要注意，`__slots__`定义的属性仅对当前类实例起作用，对继承的子类是不起作用的

除非在子类中也定义`__slots__`，这样，子类实例允许定义的属性就是自身的`__slots__`加上父类的`__slots__`。

## 使用@property

为了限制score的范围，可以通过一个`set_score()`方法来设置成绩，再通过一个`get_score()`来获取成绩，这样，在`set_score()`方法里，就可以检查参数：

```python
class Student(object):

    def get_score(self):
         return self._score

    def set_score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100!')
        self._score = value
        
--------------------------------------------------------------
>>> s = Student()
>>> s.set_score(60) # ok!
>>> s.get_score()
60
>>> s.set_score(9999)
Traceback (most recent call last):
  ...
ValueError: score must between 0 ~ 100!

```

但是，上面的调用方法又略显复杂，没有直接用属性这么直接简单。

有没有既能检查参数，又可以用类似属性这样简单的方式来访问类的变量呢？对于追求完美的Python程序员来说，这是必须要做到的！

还记得装饰器（decorator）可以给函数动态加上功能吗？对于类的方法，装饰器一样起作用。Python内置的`@property`装饰器就是负责把一个方法变成属性调用的：

```python
class Student(object):

    @property
    def score(self):
        return self._score

    @score.setter
    def score(self, value):
        if not isinstance(value, int):
            raise ValueError('score must be an integer!')
        if value < 0 or value > 100:
            raise ValueError('score must between 0 ~ 100!')
        self._score = value
```

`@property`的实现比较复杂，我们先考察如何使用。把一个getter方法变成属性，只需要加上`@property`就可以了，此时，`@property`本身又创建了另一个装饰器`@score.setter`，负责把一个setter方法变成属性赋值，于是，我们就拥有一个可控的属性操作：

```python
>>> s = Student()
>>> s.score = 60 # OK，实际转化为s.set_score(60)
>>> s.score # OK，实际转化为s.get_score()
60
>>> s.score = 9999
Traceback (most recent call last):
  ...
ValueError: score must between 0 ~ 100!
```

还可以定义只读属性，只定义getter方法，不定义setter方法就是一个只读属性：

```python
class Student(object):

    @property
    def birth(self):
        return self._birth

    @birth.setter
    def birth(self, value):
        self._birth = value

    @property
    def age(self):
        return 2015 - self._birth
```

上面的`birth`是可读写属性，而`age`就是一个*只读*属性，因为`age`可以根据`birth`和当前时间计算出来。

## 多重继承MixIn

==MixIn==

比如，编写一个多进程模式的TCP服务，定义如下：

```python
class MyTCPServer(TCPServer, ForkingMixIn):
    pass
```

编写一个多线程模式的UDP服务，定义如下：

```python
class MyUDPServer(UDPServer, ThreadingMixIn):
    pass
```

如果你打算搞一个更先进的协程模型，可以编写一个`CoroutineMixIn`：

```python
class MyTCPServer(TCPServer, CoroutineMixIn):
    pass
```

这样一来，我们不需要复杂而庞大的继承链，只要选择组合不同的类的功能，就可以快速构造出所需的子类。

## 定制类

==`__str__`==

```python
>>> class Student(object):
...     def __init__(self, name):
...         self.name = name
...
>>> print(Student('Michael'))
<__main__.Student object at 0x109afb190>


---------------------------------------------
>>> class Student(object):
...     def __init__(self, name):
...         self.name = name
...     def __str__(self):
...         return 'Student object (name: %s)' % self.name
...
>>> print(Student('Michael'))
Student object (name: Michael)

# 直接敲变量不用print，打印出来的实例还是不好看：
>>> s = Student('Michael')
>>> s
<__main__.Student object at 0x109afb310>

# 这是因为直接显示变量调用的不是__str__()，
# 而是__repr__()，两者的区别是__str__()返回用户看到的字符串，
# 而__repr__()返回程序开发者看到的字符串，也就是说，__repr__()是为调试服务的。
# 解决办法是再定义一个__repr__()。但是通常__str__()和__repr__()代码都是一样的，所以，有个偷懒的写法：
class Student(object):
    def __init__(self, name):
        self.name = name
    def __str__(self):
        return 'Student object (name=%s)' % self.name
    __repr__ = __str__
```

==`__iter__`==

如果一个类想被用于`for ... in`循环，类似list或tuple那样，就必须实现一个`__iter__()`方法，该方法返回一个迭代对象，然后，Python的for循环就会不断调用该迭代对象的`__next__()`方法拿到循环的下一个值，直到遇到`StopIteration`错误时退出循环。

我们以斐波那契数列为例，写一个Fib类，可以作用于for循环：

```python
class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1 # 初始化两个计数器a，b

    def __iter__(self):
        return self # 实例本身就是迭代对象，故返回自己

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b # 计算下一个值
        if self.a > 100000: # 退出循环的条件
            raise StopIteration()
        return self.a # 返回下一个值
   
------------------------------------------------------------------
>>> for n in Fib():
...     print(n)
...
1
1
2
3
5
...
46368
75025
```

==`__getitem__`==

Fib实例虽然能作用于for循环，看起来和list有点像，但是，把它当成list来使用还是不行，比如，取第5个元素：

要表现得像list那样按照下标取出元素，需要实现`__getitem__()`方法：

```python
class Fib(object):
    def __getitem__(self, n):
        a, b = 1, 1
        for x in range(n):
            a, b = b, a + b
        return a
    
------------------------------------------------------------------
>>> f = Fib()
>>> f[0]
1
>>> f[1]
1
>>> f[2]
2
>>> f[3]
3
>>> f[10]
89
>>> f[100]
573147844013817084101
```

==`__getattr__`==

写一个`__getattr__()`方法，动态返回一个属性。修改如下：

```
class Student(object):

    def __init__(self):
        self.name = 'Michael'

    def __getattr__(self, attr):
        if attr=='score':
            return 99
```

当调用不存在的属性时，比如`score`，Python解释器会试图调用`__getattr__(self, 'score')`来尝试获得属性，这样，我们就有机会返回`score`的值：

```
>>> s = Student()
>>> s.name
'Michael'
>>> s.score
99
```

返回函数也是完全可以的：

```
class Student(object):

    def __getattr__(self, attr):
        if attr=='age':
            return lambda: 25
```

只是调用方式要变为：

```
>>> s.age()
25
```

注意，只有在没有找到属性的情况下，才调用`__getattr__`，已有的属性，比如`name`，不会在`__getattr__`中查找。

此外，注意到任意调用如`s.abc`都会返回`None`，这是因为我们定义的`__getattr__`默认返回就是`None`。要让class只响应特定的几个属性，我们就要按照约定，抛出`AttributeError`的错误：

```
class Student(object):

    def __getattr__(self, attr):
        if attr=='age':
            return lambda: 25
        raise AttributeError('\'Student\' object has no attribute \'%s\'' % attr)
```

这实际上可以把一个类的所有属性和方法调用全部动态化处理了，不需要任何特殊手段。

这种完全动态调用的特性有什么实际作用呢？作用就是，可以针对完全动态的情况作调用。

举个例子：

现在很多网站都搞REST API，比如新浪微博、豆瓣啥的，调用API的URL类似：

* http://api.server/user/friends
* http://api.server/user/timeline/list

如果要写SDK，给每个URL对应的API都写一个方法，那得累死，而且，API一旦改动，SDK也要改。

利用完全动态的`__getattr__`，我们可以写出一个链式调用：

```python
class Chain(object):

    def __init__(self, path=''):
        self._path = path

    def __getattr__(self, path):
        return Chain('%s/%s' % (self._path, path))

    def __str__(self):
        return self._path

    __repr__ = __str__
```

试试：

```
>>> Chain().status.user.timeline.list
'/status/user/timeline/list'
```

这样，无论API怎么变，SDK都可以根据URL实现完全动态的调用，而且，不随API的增加而改变！

还有些REST API会把参数放到URL中，比如GitHub的API：

```
GET /users/:user/repos
```

调用时，需要把`:user`替换为实际用户名。如果我们能写出这样的链式调用：

```
Chain().users('michael').repos
```

==`__call__`==

构造函数？自调用函数？？？

任何类，只需要定义一个`__call__()`方法，就可以直接对实例进行调用。请看示例：

```python
class Student(object):
    def __init__(self, name):
        self.name = name

    def __call__(self):
        print('My name is %s.' % self.name)
```

调用方式如下：

```python
>>> s = Student('Michael')
>>> s() # self参数不要传入
My name is Michael.
```

`__call__()`还可以定义参数。对实例进行直接调用就好比对一个函数进行调用一样，所以你完全可以把对象看成函数，把函数看成对象，因为这两者之间本来就没啥根本的区别。

如果你把对象看成函数，那么函数本身其实也可以在运行期动态创建出来，因为类的实例都是运行期创建出来的，这么一来，我们就模糊了对象和函数的界限。

那么，怎么判断一个变量是对象还是函数呢？其实，更多的时候，我们需要判断一个对象是否能被调用，能被调用的对象就是一个`Callable`对象，比如函数和我们上面定义的带有`__call__()`的类实例：

```python
>>> callable(Student())
True
>>> callable(max)
True
>>> callable([1, 2, 3])
False
>>> callable(None)
False
>>> callable('str')
False
```

通过`callable()`函数，我们就可以判断一个对象是否是“可调用”对象。

# 进阶

## 获取命令行参数

==sys模块==

sys 模块是一个非常常用且十分重要的模块，通过模块中的 sys.argv 就可以访问到所有的命令行参数，它的返回值是包含所有命令行参数的列表(list)，

> 参数个数： len(sys.argv)
> 脚本名： sys.argv[0]
> 参数1： sys.argv[1]
> 参数2： sys.argv[2]

```python
#!usr/bin/python
# -*- coding: UTF-8 -*-

import sys

def main():
    print("参数个数:", len(sys.argv))
    print("参数列表:", str(sys.argv))
    print("脚本名为:", sys.argv[0])
    for i in range(1, len(sys.argv)):
        print("参数{}为:{}".format(i, sys.argv[i]))
        
if __name__ == "__main__":
    main()
    
--------------------------------------------------------------
# 不传递参数
>>> python3 test.py
参数个数：1
参数列表：['test.py']
脚本名为：test.py

--------------------------------------------------------------
# 传递多个参数
>>> python3 test.py elonzhou coolBoy
参数个数：3
参数列表：['test.py', 'elonzhou', 'coolBoy']
脚本名为：test.py
参数1为：elonzhou
参数2位：coolBoy

--------------------------------------------------------------
# 传递多个参数和命令行选项
>>> python3 test.py -n elonzhou -d coolBoy
参数个数：3
参数列表：['test.py', '-n', 'elonzhou', '-d', 'coolBoy']
脚本名为：test.py
参数1为：-n
参数2位：elonzhou
参数3为：-d
参数4位：coolBoy
```

**可以看到只用sys.argv**的话会把命令行选项也识别成参数

这时候就要用到另一个模块

==getopt==

getopt模块是专门处理命令行参数的模块，用于获取命令行选项和参数，也就是sys.argv。命令行选项使得程序的参数更加灵活。支持短选项模式（-）和长选项模式（–）。

==`getopt.getopt` 方法==

`getopt.getopt(args, options[, long_options])`

方法参数说明：

- args: 要解析的命令行参数列表。
- options: 以字符串的格式定义，options后的冒号(:)表示该选项必须有附加的参数，不带冒号表示该选项不附加参数。
- long_options: 以列表的格式定义，long_options 后的等号(=)表示如果设置该选项，必须有附加的参数，否则就不附加参数。
- 该方法返回值由两个元素组成: 第一个是 (option, value) 元组的列表。 第二个是参数列表，包含那些没有’-‘或’–'的参数。

在没有找到参数时会触发`Exception getopt.GetoptError`异常

```python
#!usr/bin/python
# -*- coding: UTF-8 -*-

import sys
import getopt

def main(argv):
    name = ""
    distribute = ""
    
    try:
                """
            options, args = getopt.getopt(args, shortopts, longopts=[])
            
            参数args：一般是sys.argv[1:]。过滤掉sys.argv[0]，它是执行脚本的名字，不算做命令行参数。
            参数shortopts：短格式分析串。例如："hp:i:"，h后面没有冒号，表示后面不带参数；
            			  p和i后面带有冒号，表示后面带参数。
            参数longopts：长格式分析串列表。例如：["help", "ip=", "port="]，
            	         help后面没有等号，表示后面不带参数；
            	         ip和port后面带冒号，表示后面带参数。
            
            返回值options是以元组为元素的列表，
            每个元组的形式为：(选项串, 附加参数)，如：('-i', '192.168.0.1')
            返回值args是个列表，其中的元素是那些不含'-'或'--'的参数。
        """
        opts, args = getopt.getopt(argv, "hu:p:", ["help", "name=", "distribute="])
    except getopt.GetoptError:
        print("Error: test.py -u <name> -d <distribute>")
        print("or: test.py --name=<name> --distribute=<distribute>")
    
    for opt, args in opts:
        if opt in ("-h", "--help"):
            print("test.py -u <name> -d <distribute>")
            print("or: test.py --name=<name> --distribute=<distribute>")
            sys.exit()
        elif opt in ("-n", "--name"):
            name = arg
        elif opt in ("-d", "--distribute"):
            distribute = arg
    print("name: ", name)
    print("distribute", distribute)
    for i in range(0, len(args)):
        print("参数{}为{}".format(i, args[i]))
                      
if __name__ == "__main__":
        main(sys.argv[1:]) 
                     
```

````python
>>> test.py -h 
test.py -u <name> -d <distribute>
or: test.py --name=<name> --distribute=<distribute>
    
>>> test.py -n elonzhou --distribute=coolBoy
name: elonzhou
distribute: coolBoy

# 传递选项参数以及不带选项的参数
>>> test.py -n elonzhou --distribute=coolBoy arg1 arg2
name: elonzhou
distribute: coolBoy
参数1为arg1
参数2为aeg2

# 传递错误的参数
>>>test.py -e
Error: test.py -u <name> -d <distribute>
or: test.py --name=<name> --distribute=<distribute>
````



## 网络编程

Python 提供了两个级别访问的网络服务。：

* 低级别的网络服务支持基本的 Socket，它提供了标准的 BSD Sockets API，可以访问底层操作系统Socket接口的全部方法。
* 高级别的网络服务模块 SocketServer， 它提供了服务器中心类，可以简化网络服务器的开发。

==TCP编程==

**客户端**

大多数连接都是可靠的TCP连接。

创建`Socket`时，`AF_INET`指定使用IPv4协议，如果要用更先进的IPv6，就指定为`AF_INET6`。`SOCK_STREAM`指定使用面向流的TCP协议。

TCP连接创建的是双向通道，双方都可以同时给对方发数据。但是谁先发谁后发，怎么协调，要根据具体的协议来决定。例如，HTTP协议规定客户端必须先发请求给服务器，服务器收到后才发数据给客户端。

发送的文本格式必须符合HTTP标准，如果格式没问题，接下来就可以接收数据了

```python
#!usr/bin/python
# -*- coding: UTF-8 -*-

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("127.0.0.1", 9999))

s.send(b"you will change the world")

buffer = []
while True:
    d = s.recv(1024)
    print (d)
    if d:
        buffer.append(d)
    else:
        break
data = b''.join(buffer)
s.close()
```

`Python`中`Socket`通信的消息类型为`bytes`

==服务器==

服务器进程首先要绑定一个端口并监听来自其他客户端的连接。如果某个客户端连接过来了，服务器就与该客户端建立Socket连接，随后的通信就靠这个Socket连接了。

所以，服务器会打开固定端口（比如80）监听，每来一个客户端连接，就创建该Socket连接。由于服务器会有大量来自客户端的连接，所以，服务器要能够区分一个Socket连接是和哪个客户端绑定的。一个Socket依赖4项：服务器地址、服务器端口、客户端地址、客户端端口来唯一确定一个Socket。

但是服务器还需要同时响应多个客户端的请求，所以，**每个连接都需要一个新的进程或者新的线程来处理，否则，服务器一次就只能服务一个客户端了。**

```python
#!usr/bin/python
# -*- coding: UTF-8 -*-

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# 监听端口:
s.bind(('127.0.0.1', 9999))
s.listen(5)
print('Waiting for connection...')
while True:
    # 接受一个新连接:
    sock, addr = s.accept()
    
    # 创建新线程来处理TCP连接:
    t = threading.Thread(target=tcplink, args=(sock, addr))
    t.start()
    
def tcplink(sock, addr):
    print('Accept new connection from %s:%s...' % addr)
    sock.send(b'Welcome!')
    while True:
        data = sock.recv(1024)
        time.sleep(1)
        if not data or data.decode('utf-8') == 'exit':
            break
        sock.send(('Hello, %s!' % data.decode('utf-8')).encode('utf-8'))
    sock.close()
    print('Connection from %s:%s closed.' % addr)
```

==UDP==

TCP是建立可靠连接，并且通信双方都可以以流的形式发送数据。相对TCP，UDP则是面向无连接的协议。

使用UDP协议时，不需要建立连接，只需要知道对方的IP地址和端口号，就可以直接发数据包。但是，能不能到达就不知道了。

虽然用UDP传输数据不可靠，但它的优点是和TCP比，速度快，对于不要求可靠到达的数据，就可以使用UDP协议。

**服务器**

```python
#!usr/bin/python
# -*- coding: UTF-8 -*-

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# 绑定端口:
s.bind(('127.0.0.1', 9999))

print('Bind UDP on 9999...')
while True:
    # 接收数据:
    data, addr = s.recvfrom(1024)
    print('Received from %s:%s.' % addr)
    s.sendto(b'Hello, %s!' % data, addr)
```

**客户端**

```python
#!usr/bin/python
# -*- coding: UTF-8 -*-

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
for data in [b'Michael', b'Tracy', b'Sarah']:
    # 发送数据:
    s.sendto(data, ('127.0.0.1', 9999))
    # 接收数据:
    print(s.recv(1024).decode('utf-8'))
s.close()
```





## 源码打包so



## 正则表达式



## 进程和线程



## 异步IO



# 科学计算基础软件包NumPy

## ndarray对象、属性、创建、数据类型

==ndarray对象==



**ndarray = n 维数组**



# 结构化数据分析工具Pandas





# 绘图库Matplotlib





# 科学计算工具包SciPy









## 













