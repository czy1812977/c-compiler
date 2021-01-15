# c-compiler

#陈昭宇
1. 写了这里关于符号表的部分。难点：学长要求要效率需要采用hashmap来实现，关于函数的参数，关于作用域的问题
解决：采用c++编译的方式，用c++自带的STL库完成hashmap
 传参时，创建一个tempVector,在母表里储存了这些symbol，然后创建新符号表时加入
 作用域：用一个类属性储存一个vector，新建时创立，结束使用删除（要写复制构造函数），这样当前使用的域就在vector的最后了
2. 部分错误分析和语义动作。难点：由于直接在yacc与lex里进行表操作（不想遍历一遍树影响效率）很多操作要放在lex里（比如建表等，还需要加很多判断语句来区分前后文相像的动作区别）。
3. 部分生成汇编（主要时帮忙debug,和思路，具体问题见后文）

#贾鑫
做的那些事：
  语法分析器：语法树部分 

遇到问题及解决思路：
1. 树节点的定义和实现分别写在gramtree.h 和 gramtree.cpp文件中，然后又分别在lex.l 和 yacc.y文件中分别引入include<gramtree.h>，但在编译的时候回报重定义的错，最后查找资料得知需在.h文件和.c文件中加入#ifndef 和 #define 头部以及#endif尾部，最终得以解决。
2. 在Makefile文件中写编译命令行时，由于flex 和 bsion命令生成的是.c文件，而语法树的相关文件为.cpp文件，不能使用一种单使用一种编译器进行编译，最后通过
$(BISON) --output="yacc.tab.cpp" --defines="yacc.tab.h" yacc.y 和
$(FLEX) --outfile="lex.yy.cpp" lex.l
两句命令将flex和bison命令生成的文件改为.cpp文件，最后再统一使用g++编译器进行编译。

#曹亮
主要负责代码生成部分。
主要思路：由于我们时间不是很充分，跳过了中间代码的生成，直接进行了目标代码的生成。在yacc的规约动作中进行。
关于内容分的部分实现：
循环：
???????? for循环，通过生成Label完成跳转。主要难点for中第三个位置（如i++），一次for结束后需要再次进行i++，所以我们在整个for(;;){}进行规约时生成i++的汇编，那么这样就可以在每一次for循环结束完成i++操作。
???????? while和for一样，在最后规约时生成条件变化的汇编代码。
输出：
???????? 使用外部导入printf方法，每次输出只需将要输出的值push到eax中，再call print（写好的输出函数）即可。
运算：
???????? 寄存器的分配。由于寄存器数目的限制，需要我们合理的分配寄存器。我分配寄存器的思路：将运算结果及时的存到一个寄存器中，运算完一次就存一次，保证每次运算完使用最少数量的寄存器。如1+2*3-6/2:首先规约2*3，使用一个寄存器eax存2，乘3后保存在edx中（edx=6），接着规约1+6，将1保存在eax中，eax和edx进行相加，结果存在edx中（edx=7），接着规约6/2，除法运算需要两个寄存器，将6存在eax中，2存在ebx中，进行相除，结果存在eax中（eax=3），最后规约7-3，去edx和eax相见即可。在除法过程中，遇到了问题，edx在每次进行除法运算前需要置为0，将edx push进栈，运算结束再pop edx还原它的值。


#吴若愚
1. 代码的黑盒测试，设计黑盒用例，以及测试策略（这部分没有什么问题）
2. 团队的后勤保障


