/*完成内容：

    设计String类的成员函数

    String类的拷贝构造、赋值构造、析构函数

    字符串的比较、+等函数

    重载字符串的输入>>、输出<<符函数

    查找、替换等函数

    与std::string的结果对比*/
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

class String
{
    friend ostream& operator<< (ostream& os, const String& str);//重载输出
    friend istream& operator>> (istream& in, const String& str);//重载输入

public:
    String();        //构造函数
    ~String();    //析构函数

    String(const char* pstr);    //构造函数
    String(const String& str);    //拷贝构造函数

    //赋值函数
    String& operator=(const String& str);

    // 比较大小
    bool operator<(const String str) const;
    bool operator>(const String str) const;
    bool operator<=(const String str) const;
    bool operator>=(const String str) const;
    bool operator==(const String str) const;
    bool operator!=(const String str) const;

    //+合并字符串
    String operator+(const String str) const;

    int Find(char ch);//查找字符
    string Replace(char chOld, char chNew);//替换字符

private:
    mutable char* m_pstr;
    mutable int length;
};

String::String()
{
    m_pstr = new char[1];
    m_pstr[0] = '\0';
    length = 0;
}

String::~String()
{
    delete[] m_pstr;
    length = 0;
}

String::String(const char* pstr)
{
    length = strlen(pstr);
    m_pstr = new char[length + 1];
    strcpy(m_pstr, pstr);  //将输入的字符串数组复制给m_pstr
}

String::String(const String& str)
{
    length = str.length;
    m_pstr = new char[length + 1];
    strcpy(m_pstr, str.m_pstr);  //将输入的字符串数组复制给m_pstr
}

String& String::operator=(const String& str)
{
    if (&str == this)
    {
        return *this;
    }
    length = str.length;
    m_pstr = new char[length + 1];
    strcpy(m_pstr, str.m_pstr);
    return *this;
}

bool String::operator<(const String str) const
{
    if (this->length < str.length)
    {
        return true;
    }
    return false;
}

bool String::operator>(const String str) const
{
    if (this->length > str.length)
    {
        return true;
    }
    return false;
}

bool String::operator<=(const String str) const
{
    if (this->length <= str.length)
    {
        return true;
    }
    return false;
}

bool String::operator>=(const String str) const
{
    if (this->length >= str.length)
    {
        return true;
    }
    return false;
}

bool String::operator==(const String str) const
{
    if (this->length == str.length)
    {
        return true;
    }
    return false;
}

bool String::operator!=(const String str) const
{
    if (this->length != str.length)
    {
        return true;
    }
    return false;
}

String String::operator+(const String str) const
{
    char* dest;
    dest = new char[str.length + length + 1];
    memcpy(dest, m_pstr, length);
    memcpy(dest + length, str.m_pstr, str.length + 1); //把原有字符串后移length个长度，再进行复制
    delete[]m_pstr;
    length = length + str.length;
    m_pstr = dest;
    return*this;
}

ostream& operator<<(ostream& os, const String& str)
{
    os << str.m_pstr;
    return os;
}

istream& operator>> (istream& in, const String& str)
{
    in >> str.m_pstr;
    return in;
}

int String::Find(char ch)
{
    for (int i = 0; i < length; i++)
    {
        if (m_pstr[i] == ch)
        {
            cout << "The index of the char is " << i << endl;
            return 0;
        }
    }
    cout << "The char is not in the string" << endl;
}

string String::Replace(char ch_Old, char ch_New)
{
    //int nCount = 0;
    for (int i = 0; i < length; i++)
    {
        if (m_pstr[i] == ch_Old)
        {
            m_pstr[i] = ch_New;
            //nCount++;
        }
    }
    return m_pstr;
    //return nCount;
}

int main()
{
    //String s1 = "12343";
    //String s2 = "59783";
    char sBuffer[256];
    cout << "s1: ";
    cin.getline(sBuffer, 256);
    String s1(sBuffer);
    cout << "s2: ";
    cin.getline(sBuffer, 256);
    String s2(sBuffer);




    cout << "s1 < s2 is " << s1.operator<(s2) << endl;
    cout << "s1 > s2 is " << s1.operator>(s2) << endl;
    cout << "s1 <= s2 is " << s1.operator<=(s2) << endl;
    cout << "s1 >= s2 is " << s1.operator>=(s2) << endl;
    cout << "s1 == s2 is " << s1.operator==(s2) << endl;
    cout << "s1 != s2 is " << s1.operator!=(s2) << endl;

    String s3 = s1 + s2;
    cout << "s1 + s2 = " << s3 << endl;

    char ch;
    cout << "ch: ";
    cin >> ch;
    s3.Find(ch);

    char ch1, ch2;
    cout << "old char: ";
    cin >> ch1;
    cout << "new char: ";
    cin >> ch2;
    cout << "The new string : " << s3.Replace(ch1, ch2) << endl;

    return 0;
}