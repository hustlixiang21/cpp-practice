## 改进
最大的改进就是之前的程序相关信息始终只存放在内存里，当程序结束的时候，所有的数据都会消失。故通过文件将信息保存下来，下一次的时候只需读取文件就好。

一个思路是吧每个账户的当前状态和过往的账目写入文件里，下次读出，但是这样保存的信息太多；另一种思路就是把执行的命令保存下来，程序启动时执行这些命令。

本程序接收用户的命令时，以字符串的形式读入整条命令，然后用字符串输入流来解析命令的参数。

本程序将解析字符串的功能进行了模块化，建立了Controller类用于保存账户列表，当前日期和处理指定命令。

为Date类重载“>>”运算符，使得从任何输入流中读取日期。

重载“<<"运算符使得日期和账户信息可以更加方便的输出。

>重载>>,<<的时候，由于经常连续的使用，所以需要把输入流或者输出流的引用返回，因为`cout<<a<<b`相当于`operator<<(operator<<(cout,a),b);`
