#pragma once
#include<string>
using namespace std;
//前向引用声明
class Position;
class MAP;
class File;
class MENU;
class Button;
class JUDGE;
class DRAW;
class MOUSE;
class RANK;
class ITEM;

class MENU
{
public:
	void control_0(int& w, int& h, int& n, int& c);//实现鼠标与菜单交互的函数
	void startMenu()const;//显示主菜单界面的函数
	void fileMenu()const;//显示游戏模式菜单界面的函数
};
class File
{
private:
	string name;//存档文件名称
public:
	File(const string& n) { name = n; };//构造函数
	void save(const MAP& m, DRAW& d)const;//通过文件保存游戏存档
	int load(const MAP& m, DRAW& d)const;//通过文件读取游戏存档
};
class Button
{
public:
	Button(int x, int y, int height, int width);//构造函数
	int x;//按键的横坐标
	int y;//按键的纵坐标
	int height;//按键的长度
	int width;//按键的宽度
	void isClicked(int cx, int cy, int& c)const;//按键点击事件
	void isMoved(int cx, int cy)const;//鼠标移动事件
	void draw()const;//画出按键
	void isPressed()const;//键盘交互事件
};
class Position//储存方块的位置信息，用于广度优先搜索中链表的实现
{
private:
	const int p_x, p_y;//储存结点的横纵坐标
	Position* next;//储存下个结点的地址
public:
	Position(const int x = 1, const int y = 1) :p_x(x), p_y(y)//构造函数
	{
		next = 0;
	};
	friend class JUDGE;//友元类
};
class MAP
{
private:
	const int  High, Width, Minenumber;//地图基本信息，长度、宽度和病毒数量
	int** a = 0;//二维动态数组,储存地图信息，是否有病毒，以及方块周围的病毒数量
	int** b = 0;//二维动态数组,储存地图信息，方块是否被翻开，以及是否被标记
public:
	MAP(const int h = 9, const int w = 9, const int n = 50);//构造函数
	~MAP();//析构函数
	int search_x(const int n)const;//搜索第n个方块所在的横坐标
	int search_y(const int n)const;//搜索第n个方块所在的纵坐标
	void Setmap();//通过洗牌算法实现随机布雷，完成地图的初始化
	void spread(const double t);//病毒的扩散 ，使用随机数，在病毒周围随机产生新的病毒
	friend class JUDGE;//友元类
	friend class MOUSE;//友元类
	friend class DRAW;//友元类
	friend class File;//友元类
	friend class ITEM;//友元类
};
class JUDGE
{
private:
	const MAP m;//游戏地图对象
public:
	JUDGE(const MAP& m1);
	~JUDGE();
	void judge(const int x, const int y);//（鼠标左键点击后）判断该位置是否有病毒，
	int virus_num(const int x, const int y)const;//得到该位置九宫格内的病毒数
	void sweep(const int x, const int y);//清扫方块（若某个位置无病毒，清扫并判断其周围的区域是否有病毒，若无继续清扫（广度优先搜索算法
	int correct(int& c);//根据病毒数目的变化，保证显示数字的正确，以及判定游戏的胜负
	friend class MOUSE;
	friend class ITEM;
};
class DRAW
{
private:
	const MAP m;//游戏地图对象
	static int flag_n;//储存游戏中剩余的标记数
public:
	DRAW(const MAP& m);//构造函数
	~DRAW();//析构函数
	double gametime = 0;//时间精确到毫秒
	void drawinit()const;//图片的载入
	void background()const;//地图背景的显示
	void show()const;//游戏画面的显示和实时更新
	double time();//游戏时间的记录和显示
	void flag_num();//显示剩余可用的标记数
	friend class MOUSE;
	friend class File;
};
class MOUSE
{
private:
	const MAP m;//游戏地图对象
	JUDGE ju;//游戏判断对象
	const DRAW d;//游戏绘图对象
	int M_x, M_y;//储存鼠标在地图中的位置
public:
	MOUSE(const MAP& m, JUDGE& j, DRAW& d);//构造函数
	~MOUSE();//析构函数
	void control(int& c);//鼠标控制，包括鼠标移动，左键，右键点击
};
class RECORD
{
public:
	void record(int t = 180,int t2=240)const;//储存游戏记录
	void show_r()const;//游戏记录的显示
};
class ITEM
{
private:
	const MAP m;// 游戏地图对象
	int use_1;//道具1是否在使用的信息
	int use_2;//道具2是否在使用的信息
public:
	ITEM(const MAP& m);//构造函数
	void item_1();//道具1：口罩
	void item_2(int& c, JUDGE& ju);//道具2：消毒剂
};



