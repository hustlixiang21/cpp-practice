//头文件
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <stack>
#include <sstream> //字符串流，包含istringstream，ostringstream,stringstream三个类
using namespace std;

int cpapriority(const string &a, const string &b); //比较运算符优先级

vector<string> myrpn(istream &in, ostream &out); //处理表达式,将中缀表达式转换成后缀表达式

int cpapriority(const string &a, const string &b)
{
    // 1代表优先级比存储操作符的栈的栈顶元素优先级高，可直接入栈
    // 0代表优先级相同或低，需出栈
    if (a == "(")
    {
        return 1;
    }
    else if (a.find_first_of("+-") != string::npos) //查找字符串a,b中、字符数组s中任意一个字符第一次出现的位置。string::npos表示没找到
    {
        if (b.find_first_of("*/") != string::npos)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

vector<string> myrpn(istream &in, ostream &out)
{
    //先将中缀表达式转换为后缀表达式(逆波兰式)
    std::stack<string> opstk; //存放操作符的栈
    // opstk.push("#");
    std::stack<string> valstk; //存放操作数

    vector<string> results; //存放后缀表达式的结果

    string expression; //用于读入表达式
    // windows按ctrl+z结束输入，unix/linux按ctrl+d
    while (in >> expression)
    {
        //添加一对括号，变成 (输入表达式) 形式，方便后面求解
        expression.insert(0, "(");
        expression.push_back(')');
        decltype(expression.size()) index = 0;
        //用于保存多位数
        string val;
        val.clear();
        try
        {
            while (index != expression.size())
            {
                auto ch = expression[index];
                //将char转换为string
                auto s = string(1, ch);
                if (ch == '(')
                {
                    //左括号直接入栈
                    opstk.push(s);
                }
                else if (ch == ')')
                {
                    if (!val.empty())
                    {
                        valstk.push(val);
                        val.clear();
                    }
                    while (opstk.top() != string(1, '('))
                    {
                        valstk.push(opstk.top());
                        opstk.pop();
                    }
                    opstk.pop(); //弹出左括号
                }
                else if (s.find_first_of("0123456789") != string::npos)
                {
                    val += ch;
                }
                else if (s.find_first_of("+-*/") != string::npos)
                {
                    if (!val.empty())
                    {
                        //检测到运算符说明操作数处理完毕
                        //此处为了避')'和运算符'+-*/'相邻而将操作数入栈两次
                        valstk.push(val);
                        val.clear();
                    }
                    val.clear();
                    //比较运算符优先级
                    while (cpapriority(opstk.top(), s) == 0)
                    {
                        valstk.push(opstk.top());
                        opstk.pop();
                    }
                    opstk.push(s);
                }
                else
                {
                    throw -1; //出现非法符号
                }
                ++index;
            }
            //输出结果是逆序的，需要处理下
            string result;
            while (!valstk.empty())
            {
                //不断在头部插入,加入空格便于区分
                result.insert(0, valstk.top() + " ");
                valstk.pop();
            }
            results.push_back(result); //保存转换结果
        }
        catch (int errcode)
        {
            out << "Error code:" << errcode
                << " invalid char";
        }
        catch (...)
        {
            out << "Unknown Error";
        }
    }
    return results; //返回逆波兰式(后缀表达式)
}

int main()
{
    for (const auto &st : myrpn(cin, cout))
    {
        cout << st << endl;
        std::istringstream istrm(st); //字符串流，用于读取字符串
        string s;
        long double result = 0.0;    //保存最终运算结果
        std::stack<long double> stk; // C++适配器stack
        while (istrm >> s)
        {
            //发现不是运算符则入栈，否则出栈
            if (s.find_first_not_of("+-*/") != string::npos)
            {
                stk.push(std::stod(s));
            }
            else
            {
                auto lval = stk.top();
                stk.pop();
                auto rval = stk.top();
                stk.pop();
                //发现运算符为“+”
                if (s.find('+') != string::npos)
                {
                    result = lval + rval;
                    stk.push(result);
                }
                //发现运算符为“-”
                else if (s.find('-') != string::npos)
                {
                    result = rval - lval;
                    stk.push(result);
                }
                //发现运算符为“*”
                else if (s.find('*') != string::npos)
                {
                    result = lval * rval;
                    stk.push(result);
                }
                //发现运算符为“/”
                else if (s.find('/') != string::npos)
                {
                    //注意除数不能为0
                    if (lval == 0)
                    {
                        cout << "Divisor can't be zero" << endl;
                        return EXIT_FAILURE;
                    }
                    //后一个数除以前一个数
                    result = rval / lval;
                    stk.push(result);
                }
            }
        }
        cout << stk.top() << endl;
    }
    return EXIT_SUCCESS; // cstdlib定义的预处理变量，与机器无关。其中EXIT_FAILURE表示失败
}
