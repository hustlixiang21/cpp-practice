/*������ݣ�

    ���String��ĳ�Ա����

    String��Ŀ������졢��ֵ���졢��������

    �ַ����ıȽϡ�+�Ⱥ���

    �����ַ���������>>�����<<������

    ���ҡ��滻�Ⱥ���

    ��std::string�Ľ���Ա�*/
#include <iostream>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

class String
{
    friend ostream& operator<< (ostream& os, const String& str);//�������
    friend istream& operator>> (istream& in, const String& str);//��������

public:
    String();        //���캯��
    ~String();    //��������

    String(const char* pstr);    //���캯��
    String(const String& str);    //�������캯��

    //��ֵ����
    String& operator=(const String& str);

    // �Ƚϴ�С
    bool operator<(const String str) const;
    bool operator>(const String str) const;
    bool operator<=(const String str) const;
    bool operator>=(const String str) const;
    bool operator==(const String str) const;
    bool operator!=(const String str) const;

    //+�ϲ��ַ���
    String operator+(const String str) const;

    int Find(char ch);//�����ַ�
    string Replace(char chOld, char chNew);//�滻�ַ�

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
    strcpy(m_pstr, pstr);  //��������ַ������鸴�Ƹ�m_pstr
}

String::String(const String& str)
{
    length = str.length;
    m_pstr = new char[length + 1];
    strcpy(m_pstr, str.m_pstr);  //��������ַ������鸴�Ƹ�m_pstr
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
    memcpy(dest + length, str.m_pstr, str.length + 1); //��ԭ���ַ�������length�����ȣ��ٽ��и���
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