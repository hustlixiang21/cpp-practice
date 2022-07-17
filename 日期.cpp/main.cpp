#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
bool IsLeap(int year)
{
    if(((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0 )   //是闰年
        return true;
    else                                    //不是闰年
        return false;
}
int main()
{
    string input;
    int n=0,year,month,day,a,flag=0;
    int array_1[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int array_2[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    cout << "Please enter a string standing for a certain date(20220421):" << endl;
    cin >> input >> n;
    int num = 0;
    for(auto &s:input){
        num  = num*10 + s-'0';
    }//将字符串转化成数字（这一段纠结半天，感觉很难处理，可以看看你们老师和同学有什么更好的处理办法)
    //取出每一段作为数据(感觉很呆)
    a = num;
    year = a/10000;
    a = num;
    month = (a%10000)/100;
    day = num%100;
    //用于校准的一天(是因为如果是闰年且恰好从2.29之前的话，后面就会相差一天，这一天要校准)
    if(IsLeap(year) && month<=2 && day<=28)
    {
        flag=1;
    }
    while (true)//首先从年数入手，依次减去365或者366
    {
        if(IsLeap(year+1)&&n>365)//闰年且n足够大
        {
            year++;
            n -= 366;
        }
        else if(!IsLeap(year+1)&&n>364)//平年且n足够大
        {
            year++;
            n -= 365;
        }
        else
            break;//n不够了直接退出
    }
    if(flag==1)//校准日期，减去一天
    {
        //正常减
        if(day==1)//月初得往后一月
        {
            if(month==1)//年初得往后一年
            {
                year--;
                month=12;
                day=31;
            }
            month--;
            if(IsLeap(year))
            {
                day=array_2[month];
            }
            else
            {
                day=array_1[month];
            }
        }
        day--;
    }
    //进行月份和天数的累加
    while(true) {
        if (n == 0) break;
        if (IsLeap(year) && month == 2) //润年且二月
        {
            if (n >= 29 - day + 1) //n够
            {
                n = n - (29 - day + 1);
                month = 3;
                day = 1;

            } else //n不够
            {
                day = day + n;
                n = 0;
            }
        } else if (!IsLeap(year) && month == 2) //平年且二月
        {
            if (n >= 28 - day + 1) //n够
            {
                n = n - (28 - day + 1);
                month = 3;
                day = 1;

            } else //n不够
            {
                day = day + n;
                n = 0;
            }
        } else //普通月份
        {
            if (n >= array_1[month] - day + 1) //n够
            {
                n = n - (array_1[month] - day + 1);
                month++;
                day = 1;

            } else //n不够
            {
                day = day + n;
                n = 0;
            }
        }
        if (month > 12) //若大于十二月，加一年，重置月份
        {
            year++;
            month = month - 12;
        }
    }
    //需满足的输出格式
    if(year>9999)
        cout << "Out of limitation!" << endl;
    else
    {
        cout << setw(4) << setfill('0') << year
             << setw(2) << setfill('0') << month
             << setw(2) << setfill('0') << day << endl;
    }
    return 0;
}
