#include"class.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<graphics.h>
#include<conio.h>
#include<fstream>
#include<memory>
#pragma comment(lib,"winmm.lib")   //bgm
using namespace std;

//图片
IMAGE Menu[5];//开始菜单
IMAGE num_2[9];//对显示给用户的周围病毒的图片进行预载入
IMAGE virus_2_1;//紫色的病毒，玩家点击后被感染
IMAGE virus_2_2;//红色的病毒，用于显示所有病毒的位置
IMAGE virus_2_3;//被玩家用道具防护的病毒
IMAGE flag_2_1;//用于表示小旗帜
IMAGE flag_2_2;//用于标志问号的图片预载入
IMAGE StateSetUp;//用于预载入初始化的右边状态
IMAGE masks_2[10];//定义右边的计时器所用到的数字
IMAGE item[3];//道具图片
IMAGE map;//定义地图背景图片
IMAGE dot;//定义显示在右侧状态区域的点
IMAGE Score;//定义显示标记正确的病毒
SYSTEMTIME start;//计时模块

void MENU::startMenu()const
{
	loadimage(&Menu[0], "./images/menu1.bmp");
	loadimage(&Menu[1], "./images/menu2.bmp");
	//菜单图片
	initgraph(500, 750);//不显示控制台窗口, SHOWCONSOLE
	putimage(0, 0, &Menu[0]);
	setfillcolor(RGB(20, 50, 120));
	fillrectangle(150, 225, 350, 275);
	fillrectangle(150, 300, 350, 350);
	fillrectangle(250, 400, 350, 450);

	setbkmode(TRANSPARENT);//设置输出的字符颜色透明
	outtextxy(220, 238, "开始游戏");
	outtextxy(220, 318, "退出游戏");
	outtextxy(270, 420, "游戏记录");
}

void MENU::fileMenu()const
{
	putimage(0, 0, &Menu[1]);
	setfillcolor(RGB(20, 50, 120));
	fillrectangle(150, 150, 350, 200);
	fillrectangle(150, 225, 350, 275);
	//fillrectangle(150, 300, 350, 350);
	fillrectangle(70, 150, 350, 275);
	fillrectangle(175, 400, 350, 450);
	setbkmode(TRANSPARENT);//设置输出的字符颜色透明
	outtextxy(220, 168, "关卡1");
	outtextxy(220, 238, "关卡2");
	//outtextxy(220, 318, "关卡3");
	settextstyle(30, 20, _T("楷体"));
	outtextxy(80, 150, "道");
	outtextxy(80, 180, "具");
	outtextxy(80, 210, "模");
	outtextxy(80, 240, "式");
	outtextxy(185, 415, "挑战模式");

}

void MENU::control_0(int& w, int& h, int& n, int& c)
{
	bool out = 0;
	ExMessage MO;//MOUSEMSG MO;
	while (1)
	{
		MO = getmessage();//对鼠标位置的获取及处理
		if (MO.message == WM_MOUSEMOVE)//对鼠标的位置的跟踪，出现选中框
		{
			setlinestyle(PS_SOLID, 4);
			setlinecolor(WHITE);
			rectangle(150, 225, 350, 275);
			rectangle(150, 300, 350, 350);
			rectangle(250, 400, 350, 450);
			if (MO.x >= 150 && MO.y >= 225 && MO.x <= 350 && MO.y <= 275)
			{
				setlinestyle(PS_SOLID, 4);
				setlinecolor(RGB(100, 0, 0));
				rectangle(150, 225, 350, 275);

			}
			else if (MO.x >= 150 && MO.y >= 300 && MO.x <= 350 && MO.y <= 350)
			{
				setlinestyle(PS_SOLID, 4);
				setlinecolor(RGB(100, 0, 0));
				rectangle(150, 300, 350, 350);

			}
			else if (MO.x >= 250 && MO.y >= 400 && MO.x <= 350 && MO.y <= 450)
			{
				setlinestyle(PS_SOLID, 4);
				setlinecolor(RGB(100, 0, 0));
				rectangle(250, 400, 350, 450);

			}

		}
		if (MO.message == WM_LBUTTONDOWN)//左击鼠标判断
		{
			if (MO.x >= 150 && MO.y >= 225 && MO.x <= 350 && MO.y <= 275)//开始游戏
			{
				fileMenu();
				while (1)
				{
					MO = getmessage();//对鼠标位置的获取及处理
					if (MO.message == WM_MOUSEMOVE)//对鼠标的位置的跟踪，出现选中框
					{
						setlinecolor(WHITE);
						rectangle(150, 225, 350, 275);
						rectangle(150, 150, 350, 200);
						rectangle(70, 150, 350, 275);
						rectangle(175, 400, 350, 450);
						if (MO.x >= 70 && MO.y >= 150 && MO.x <= 350 && MO.y <= 275)
						{
							setlinestyle(PS_SOLID, 4);
							setlinecolor(RGB(100, 0, 0));
							rectangle(70, 150, 350, 275);

							if (MO.x >= 150 && MO.y >= 225 && MO.x <= 350 && MO.y <= 275)
							{
								setlinestyle(PS_SOLID, 4);
								setlinecolor(RGB(100, 0, 0));
								rectangle(150, 225, 350, 275);
							}

							else if (MO.x >= 150 && MO.y >= 150 && MO.x <= 350 && MO.y <= 200)
							{
								setlinestyle(PS_SOLID, 4);
								setlinecolor(RGB(100, 0, 0));
								rectangle(150, 150, 350, 200);
							}
						}
						else if (MO.x >= 175 && MO.y >= 400 && MO.x <= 350 && MO.y <= 450)
						{
							setlinestyle(PS_SOLID, 4);
							setlinecolor(RGB(100, 0, 0));
							rectangle(175, 400, 350, 450);
						}

					}
					if (MO.message == WM_LBUTTONDOWN)//左击鼠标判断
					{
						if (MO.x >= 150 && MO.y >= 150 && MO.x <= 350 && MO.y <= 200)
						{
							c = 1;
							out = 1;
							break;
						}
						if (MO.x >= 150 && MO.y >= 225 && MO.x <= 350 && MO.y <= 275)
						{
							c = 2;
							out = 1;
							break;
						}
						if (MO.x >= 175 && MO.y >= 400 && MO.x <= 350 && MO.y <= 450)
						{
							// 初始化绘图窗口
							initgraph(640, 480);

							// 定义字符串，接收用户输入
							char s1[10], s2[10], s3[10];
							InputBox(s1, 10, _T("请输入宽度（9-24之间）"));
							w = strtol(s1, 0, 10);// 将用户输入转换为数字
							while (w < 9 || w>24)
							{
								InputBox(s1, 10, _T("请输入符合要求的宽度（9-24之间）"));
								w = strtol(s1, 0, 10);
							}
							InputBox(s2, 10, _T("请输入长度（9-30之间）"));
							h = strtol(s2, 0, 10);
							while (h < 9 || h>30)
							{
								InputBox(s2, 10, _T("请输入符合要求的长度（9-30之间）"));
								h = strtol(s2, 0, 10);
							}
							InputBox(s3, 10, _T("请输入病毒数（10-668之间)"));
							n = strtol(s3, 0, 10);
							while (n < 10 || n>668)
							{
								InputBox(s3, 10, _T("请输入符合要求的病毒数（10-668之间)"));
								n = strtol(s3, 0, 10);
							}
							c = 4;
							out = 1;
							break;
						}
					}
				}
				if (out)
				{
					break;
				}

			}
			if (MO.x >= 150 && MO.y >= 300 && MO.x <= 350 && MO.y <= 350)//退出游戏
			{
				closegraph();
				exit(1);
			}
			if (MO.x >= 250 && MO.y >= 400 && MO.x <= 350 && MO.y <= 450)//排行榜
			{
				putimage(0, 0, &Menu[1]);
				RECORD r;
				r.show_r();
				_getch();
				c = 0;
				break;
			}

		}
	}
}

void File::save(const MAP& m, DRAW& d)const
{
	char s1[10];
	int c;
	InputBox(s1, 10, _T("是否保存游戏？（输入‘1’为保存，输入‘0’为不保存"));
	c = strtol(s1, 0, 10);// 将用户输入转换为数字
	while (c != 0 && c != 1)
	{
		InputBox(s1, 10, _T("请输入符合要求的数字（0或1）"));
		c = strtol(s1, 0, 10);
	}
	if (c == 1)
	{
		ofstream myFile(name, ios_base::binary);
		for (int i = 1; i <= m.High; i++)
		{
			for (int j = 1; j <= m.Width; j++)
			{
				myFile.write(reinterpret_cast<char*>(&m.a[i][j]), sizeof(m.a[i][j]));
				myFile.write(reinterpret_cast<char*>(&m.b[i][j]), sizeof(m.b[i][j]));
			}
		}
		myFile.write(reinterpret_cast<char*>(&d.gametime), sizeof(d.gametime));
		myFile.close();
	}
	else if (c == 0)
	{
		ofstream myFile(name, ios_base::binary);
	}
}

int File::load(const MAP& m, DRAW& d)const
{
	char s1[10];
	int c;
	InputBox(s1, 10, _T("是否读取游戏存档？（输入‘1’为是，输入‘0’为否"));
	c = strtol(s1, 0, 10);// 将用户输入转换为数字
	while (c != 0 && c != 1)
	{
		InputBox(s1, 10, _T("请输入符合要求的数字（0或1）"));
		c = strtol(s1, 0, 10);
	}
	if (c == 1)
	{
		int f = 0;//防止读入空文件的存档，先假设原文件不存在数据
		ifstream myFile(name, ios_base::binary);
		for (int i = 1; i <= m.High; i++)
		{
			for (int j = 1; j <= m.Width; j++)
			{
				myFile.read(reinterpret_cast<char*>(&m.a[i][j]), sizeof(m.a[i][j]));
				myFile.read(reinterpret_cast<char*>(&m.b[i][j]), sizeof(m.b[i][j]));
				if (m.a[i][j] >= 0)//只有有一个值大于0，说明不是空文档（会读出负数
				{
					f = 1;
				}
			}
		}
		if (f == 0)//是空文档
		{
			return 0;
		}
		myFile.read(reinterpret_cast<char*>(&d.gametime), sizeof(d.gametime));
		myFile.close();
		return 1;
	}
	else {
		return 0;
	}
}

Button::Button(int x, int y, int height, int width)//构造函数
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
}

void Button::isClicked(int cx, int cy, int& c)const
{
	if (cx >= x && cy >= y && x + width >= cx && y + height >= cy)
	{
		c = 0;//改变choice的值，返回主菜单
	}
}

void Button::isMoved(const int cx, const int cy)const
{

	if (cx >= x && cy >= y && x + width >= cx && y + height >= cy)
	{
		//moveAction();
		setlinecolor(RGB(100, 0, 0));
		rectangle(x, y, x + width, y + height);
		setlinecolor(0xAAAAAA);
	}
	else
	{
		setlinecolor(0xAAAAAA);
	}
}

void Button::isPressed()const
{
	setlinecolor(RGB(100, 0, 0));
	rectangle(x, y, x + width, y + height);
	setlinecolor(0xAAAAAA);
}

void Button::draw()const
{
	setfillcolor(RGB(20, 50, 120));
	fillrectangle(x, y, x + width, y + height);
}

ITEM::ITEM(const MAP& m) :m(m)
{
	use_1 = 0;
	use_2 = 0;
};

void ITEM::item_1()
{
	char input;
	setlinecolor(0xAAAAAA);
	BeginBatchDraw();//开始批量绘图,避免屏幕闪烁
	Button i_1(m.Width * 27 + 70, 100, 90, 90);
	i_1.draw();
	setbkmode(TRANSPARENT);//设置输出的字符颜色透明
	outtextxy(m.Width * 27 + 72, 165, "口罩(A)");
	putimage(m.Width * 27 + 70, 100, &item[0]);
	FlushBatchDraw();
	if (_kbhit())  // 判断是否有输入
	{
		input = _getch();  // 根据用户的不同输入来判断，不必输入回车
		if (input == 'a')
		{
			use_1 = 1;
		}
	}
	if (use_1 == 1)
	{
		setbkmode(OPAQUE);//设置输出的字符颜色为默认
		outtextxy(m.Width * 27 + 72, 165, "使用中  ");
		i_1.isPressed();
		setbkmode(TRANSPARENT);
		for (int i = 1; i <= m.High; i++)
		{
			for (int j = 1; j <= m.Width; j++)
			{
				if (m.a[i][j] == 9 && m.b[i][j] == 1)//口罩防护病毒
				{
					m.b[i][j] = 4;
					use_1 = 0;
				}
			}
		}
	}
	EndBatchDraw();
}
void ITEM::item_2(int& c, JUDGE& ju)
{
	char input;
	setlinecolor(0xAAAAAA);
	BeginBatchDraw();//开始批量绘图,避免屏幕闪烁
	Button i_2(m.Width * 27 + 70, 190, 90, 90);
	i_2.draw();
	putimage(m.Width * 27 + 70, 190, &item[1]);
	FlushBatchDraw();
	if (_kbhit())  // 判断是否有输入
	{
		input = _getch();
		if (input == 's')
		{
			use_2 = 1;
		}
	}
	if (use_2 != 1)
	{
		BeginBatchDraw();
		setbkmode(TRANSPARENT);//设置输出的字符颜色透明
		outtextxy(m.Width * 27 + 72, 255, "消毒剂(S)");
		EndBatchDraw();
	}
	else if (use_2 == 1)
	{
		BeginBatchDraw();
		c = 0;
		setbkmode(OPAQUE);//设置输出的字符颜色为默认
		outtextxy(m.Width * 27 + 72, 255, " 使用中  ");
		i_2.isPressed();
		setbkmode(TRANSPARENT);
		EndBatchDraw();
		int M_x, M_y;
		ExMessage MO;//MOUSEMSG MO;
		if (peekmessage(&MO, EM_MOUSE, false))
		{
			MO = getmessage();//对鼠标位置的获取及处理
			if (MO.message == WM_MOUSEMOVE)//对鼠标的位置的跟踪，出现选中框
			{
				M_x = MO.x / 27 + 1;
				M_y = MO.y / 27 + 1;
				if (M_x <= m.Width && M_y <= m.High)
				{
					//COLORREF RGB(100, 0, 0);
					setlinestyle(PS_SOLID, 4);
					setlinecolor(0xAAAAAA);
					rectangle((M_x - 2) * 27, (M_y - 2) * 27, (M_x + 1) * 27, (M_y + 1) * 27);
				}
			}
			if (MO.message == WM_LBUTTONDOWN)//左击鼠标判断
			{
				int M_x0 = MO.x / 27 + 1;
				int M_y0 = MO.y / 27 + 1;
				for (int i = 0; i < 9; i++)
				{
					M_x = M_x0 + i % 3 - 1;
					M_y = M_y0 + i / 3 - 1;
					if (M_x >= 1 && M_y >= 1 && M_x <= m.Width && M_y <= m.High)
					{
						ju.judge(M_x, M_y);
						m.b[M_y][M_x] = 1;
						if (m.a[M_y][M_x] == 9)
						{
							m.b[M_y][M_x] = 4;
						}
					}
				}
				c = 1;
				use_2 = 0;
			}
		}
	}
	flushmessage();
}

void RECORD::record(const int t,const int t2)const//储存游戏记录，游戏次数和最短通关时间
{
	int x = 0, t_ = 180, t_2 = 240;
	ifstream myFile1("record", ios_base::binary);
	myFile1.read(reinterpret_cast<char*>(&x), sizeof(x));//读取游戏次数
	if (x < 0)
		x = 0;
	myFile1.read(reinterpret_cast<char*>(&t_), sizeof(t_));//读取第一关最短时间
	myFile1.read(reinterpret_cast<char*>(&t_2), sizeof(t_2));//读取第二关最短时间
	myFile1.close();
	if (t < t_ || t_ <= 0)
	{
		t_ = t;
	}
	if (t2 < t_2 || t_2 <= 0)
	{
		t_2 = t2;
	}
	x++;
	ofstream myFile2("record", ios_base::binary);
	myFile2.write(reinterpret_cast<char*>(&x), sizeof(x));
	myFile2.write(reinterpret_cast<char*>(&t_), sizeof(t_));
	myFile2.write(reinterpret_cast<char*>(&t_2), sizeof(t_2));
	myFile2.close();
}

void RECORD::show_r()const
{
	int x, t_,t_2;
	ifstream myFile1("record", ios_base::binary);
	myFile1.read(reinterpret_cast<char*>(&x), sizeof(x));
	myFile1.read(reinterpret_cast<char*>(&t_), sizeof(t_));
	myFile1.read(reinterpret_cast<char*>(&t_2), sizeof(t_2));
	myFile1.close();
	setfillcolor(RGB(20, 50, 120));
	fillrectangle(150, 150, 350, 200);
	fillrectangle(150, 220, 350, 270);
	fillrectangle(150, 290, 350, 340);
	setbkmode(TRANSPARENT);//设置输出的字符颜色透明
	outtextxy(180, 168, "游戏次数");
	outtextxy(180, 238, "第一关最短时间");
	outtextxy(180, 308, "第二关最短时间");
	char s1[15], s2[15],s3[15];
	sprintf_s(s1, "%d", x);//int类型转化为字符数组，便于输出
	sprintf_s(s2, "%d", t_);
	sprintf_s(s3, "%d", t_2);
	outtextxy(280, 168, s1);
	outtextxy(320, 238, s2);
	outtextxy(320, 308, s3);
	outtextxy(90, 100, "(按下任意按键返回主菜单）");
}

MAP::MAP(const int h, const int w, const int n) :
	High(h), Width(w), Minenumber(n)
{
	//建立储存地图信息的二维数组，全部从[1]开始
	a = new int* [High + 1];//a的值为9则表示有病毒(作为判断依据)，为0则表示无病毒，翻开后:数字1-8表示周围病毒数，周围无病毒则为10//与 int** a=new int *[High+1];  等价
	for (int i = 0; i <= High; i++)
	{
		a[i] = new int[Width + 1];
	}
	b = new int* [High + 1];//b储存方块是否被翻开的信息，未翻开则为0，翻开则为1，标记则为2，问号则为3,病毒被防护为4
	for (int i = 0; i <= High; i++)
	{
		b[i] = new int[Width + 1];
	}
};
MAP::~MAP()
{

	if (a[0] != nullptr)
	{
		cout << "delete" << endl;
		for (int i = 0; i <= High; i++)
		{
			delete a[i];
			a[i] = nullptr;
		}
		//delete[]a;
		for (int i = 0; i <= High; i++)
		{
			delete b[i];
			b[i] = nullptr;
		}
		delete[]b;
	}
}

int MAP::search_x(const int n)const//搜索第n个方块所在的横坐标
{
	int x = n % Width;
	if (x == 0)
		x = Width;
	return x;
}
int MAP::search_y(const int n)const
{
	return n / Width + 1;
}

void MAP::Setmap()
{
	int i, j, temp = 0;
	srand(time(0));
	for (i = 1; i <= High; i++)//初始化全部为0
	{
		for (j = 1; j <= Width; j++)
		{
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}
	i = 1, j = 1;
	//洗牌算法实现快速随机布雷
	for (int k = 1; k <= Minenumber; k++)
	{

		a[i][j] = 9;
		j++;
		if (j == Width + 1)
		{
			j = 1;
			i++;
		}
	}
	for (i = 1; i <= High; i++)
	{
		for (j = 1; j <= Width; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

	i = 1, j = 1;
	for (int k = 1; k <= Minenumber; k++)//先在前x个位置布雷，然后对于前x个位置，每个位置和包括它在内的之后每个位置进行交换，经过x次交换后，每个位置有雷的概率都是x/总数，实现等概率且不重复地布雷
	{

		int m = rand() % (High * Width - k) + k;
		temp = a[i][j];
		a[i][j] = a[search_y(m)][search_x(m)];
		a[search_y(m)][search_x(m)] = temp;
		j++;
		if (j == Width)
		{
			j = 1;
			i++;
		}
	}
	//show
	for (i = 1; i <= High; i++)
	{
		for (j = 1; j <= Width; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}

}

void MAP::spread(const double t)
{
	int r;
	int w = 0, break_ = 0;
	if (t > 1 && static_cast<int>(t) % 15 == 0 && t < static_cast<int>(t) + 0.1)
	{
		srand(time(0) + rand());
		for (int i = 1; i <= High; i++)
		{
			for (int j = 1; j <= Width; j++)
			{
				if (a[i][j] > 0 && a[i][j] < 9 && b[i][j] != 1 && b[i][j] != 2)//对于所有附近有病毒切未被标记或翻开的方块
				{
					r = rand() % 30;
					if (r == 0)
					{
						a[i][j] = 9;
						w++;
					}
					if (w >= 3)
					{
						break_ = 1;
						break;
					}
				}
			}
			if (break_ == 1)
			{
				break;
			}

		}
		cout << endl << w;
	}
}

JUDGE::JUDGE(const MAP& m1) :m(m1) { };//m(m1)调用复制构造函数，m=m1调用构造函数，出于安全性考虑，其实不应将对象m作为JUDGE的成员
JUDGE::~JUDGE() {};

void JUDGE::judge(const int x, const int y)//(左键)点开方块只有三种情况，有病毒，无病毒则显示周围病毒数，若周围无病毒则清扫
{
	if (x >= 1 && y >= 1 && x <= m.Width && y <= m.High)
	{
		if (m.a[y][x] != 9)
		{
			if (virus_num(x, y) > 0)
			{
				m.a[y][x] = virus_num(x, y);
			}
			else if (virus_num(x, y) == 0)
			{
				m.a[y][x] = 10;
				sweep(x, y);
			}
		}
	}
}

int JUDGE::virus_num(const int x, const int y)const//注意由于x为横坐标，y为纵坐标，对于数组应为a[y][x]
{
	int x_, y_, num = 0;

	for (int i = 0; i < 9; i++)//遍历一个矩形区域
	{
		x_ = x + i % 3 - 1;
		y_ = y + i / 3 - 1;

		if (x_ >= 1 && y_ >= 1 && x_ <= m.Width && y_ <= m.High)
		{
			if ((x_ != x || y_ != y) && m.a[y_][x_] == 9)//第一次的错误原因是动态数组在函数内部，函数结束内存会释放（读取访问权限冲突）
				num++;
		}
	}
	return num;
}

void JUDGE::sweep(const int x, const int y)//动态指针
{
	Position p(x, y);
	Position* head = &p, * tail = &p;//前后两个指针，用于实现广度优先搜索
	Position* plist = &p;//指向p，用于最后内存的释放
	do
	{
		if (head->next != 0)//首指针后移
		{
			head = head->next;
		}
		int x_, y_;
		for (int i = 0; i < 9; i++)//遍历一个矩形区域
		{
			x_ = head->p_x + i % 3 - 1;
			y_ = head->p_y + i / 3 - 1;
			if (x_ >= 1 && y_ >= 1 && x_ <= m.Width && y_ <= m.High)//&& (x_ != head->p_x || y_ != head->p_y)
			{
				if (m.a[y_][x_] == 9)
				{
					//保持原样
				}
				else if (virus_num(x_, y_) > 0 && m.b[y_][x_] != 2 && m.b[y_][x_] != 1)
				{
					m.a[y_][x_] = virus_num(x_, y_);
					m.b[y_][x_] = 1;
				}
				else if (virus_num(x_, y_) == 0 && m.b[y_][x_] != 2 && m.b[y_][x_] != 1)//遇到满足条件的方块，尾指针延伸
				{
					m.a[y_][x_] = 10;
					m.b[y_][x_] = 1;
					//Position p_(x_, y_);//有作用域的限制
					tail->next = new Position(x_, y_);//注意要delete避免内存泄露!!!
					tail = tail->next;
				}
			}
		}
	} while (head != tail);
	head = plist->next; // 此时head指向plist的下一个结点，第一个结点不能删除（不是new得到的）。
	while (head != NULL)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
	plist = NULL; // 只是释放了其内存空间，指向链表的指针值并没有被置为空
	
}

int JUDGE::correct(int& c)//随着病毒的扩散，保证方块显示数字正确,同时判断游戏的胜负，返回1为胜，2为负，0为未结束
{
	int mark = 1, n_virus = 0;
	for (int i = 1; i <= m.High; i++)
	{
		for (int j = 1; j <= m.Width; j++)
		{

			if (m.a[i][j] != 9)
			{
				m.a[i][j] = virus_num(j, i);
				if (m.a[i][j] == 0)
					m.a[i][j] = 10;
			}
			if (m.a[i][j] == 9)
			{
				n_virus++;
			}
			if (m.a[i][j] == 9 && m.b[i][j] == 1 || n_virus > m.High * m.Width / 3)//触碰到病毒或病毒增长至方块总数的1/2，则游戏失败
			{
				//cout << "游戏失败";
				for (int i = 1; i <= m.High; i++)
				{
					for (int j = 1; j <= m.Width; j++)
					{
						if (m.a[i][j] == 9 && m.b[i][j] == 1)
						{
							putimage((j - 1) * 27, (i - 1) * 27, &virus_2_1);
						}
						if (m.a[i][j] == 9 && m.b[i][j] == 0)
						{
							putimage((j - 1) * 27, (i - 1) * 27, &virus_2_2);
						}
						if (m.a[i][j] == 9 && m.b[i][j] == 2)
						{
							putimage((j - 1) * 27, (i - 1) * 27, &Score);
						}
					}
				}
				mark = 2;
			}
		}
	}
	if (mark == 2)
	{
		c = 0;
		setbkmode(OPAQUE);//设置输出的字符颜色为默认
		settextcolor(WHITE);
		settextstyle(16, 0, _T("Consolas"));
		outtextxy(120, 80, "游戏结束");
		outtextxy(90, 100, "(按下任意按键返回主菜单）");
		return 2;
	}
	for (int i = 1; i <= m.High; i++)
	{
		for (int j = 1; j <= m.Width; j++)
		{
			if (m.a[i][j] == 9 && m.b[i][j] != 2 && m.b[i][j] != 4)//将所有病毒都标记  游戏胜利；只要有一个病毒未被标记  就没有胜利（注意要保证标记数量不超过病毒数
			{
				mark = 0;
			}
		}
	}
	if (mark == 1)
	{
		for (int i = 1; i <= m.High; i++)
		{
			for (int j = 1; j <= m.Width; j++)
			{
				if (m.a[i][j] == 9 && m.b[i][j] == 2)
				{
					putimage((j - 1) * 27, (i - 1) * 27, &Score);
				}
			}
		}
		c = 0;
		setbkmode(OPAQUE);//设置输出的字符颜色为默认
		settextcolor(WHITE);
		settextstyle(16, 0, _T("Consolas"));
		outtextxy(120, 80, "游戏胜利");
		outtextxy(90, 100, "(按下任意按键返回主菜单）");
		//_getch();
		return 1;
	}
	return 0;
}

MOUSE::MOUSE(const MAP& m, JUDGE& j, DRAW& d) :m(m), ju(j), d(d) {};
MOUSE::~MOUSE() {};

void MOUSE::control(int& c)
{

	int M_x, M_y;
	BeginBatchDraw();
	Button b1(m.Width * 27 + 80, m.High * 27 - 40, 40, 80);
	b1.draw();
	setbkmode(TRANSPARENT);//设置输出的字符颜色透明
	outtextxy(m.Width * 27 + 90, m.High * 27 - 30, "返回");
	ExMessage MO;//MOUSEMSG MO;
	if (peekmessage(&MO, EM_MOUSE, false))
	{
		MO = getmessage();//对鼠标位置的获取及处理
		if (MO.message == WM_MOUSEMOVE)//对鼠标的位置的跟踪，出现选中框
		{
			b1.isMoved(MO.x, MO.y);
			M_x = MO.x / 27 + 1;
			M_y = MO.y / 27 + 1;
			if (M_x <= m.Width && M_y <= m.High)
			{
				//COLORREF RGB(100, 0, 0);
				setlinestyle(PS_SOLID, 4);
				setlinecolor(0xAAAAAA);
				rectangle((M_x - 1) * 27, (M_y - 1) * 27, M_x * 27, M_y * 27);
			}
		}
		if (MO.message == WM_LBUTTONDOWN)//左击鼠标判断
		{
			b1.isClicked(MO.x, MO.y, c);
			M_x = MO.x / 27 + 1;
			M_y = MO.y / 27 + 1;
			if (M_x >= 1 && M_y >= 1 && M_x <= m.Width && M_y <= m.High && (m.b[M_y][M_x] == 0 || m.b[M_y][M_x] == 3))//在允许显示的情况下进行操作
			{
				m.b[M_y][M_x] = 1;
				ju.judge(M_x, M_y);
			}

		}
		if (MO.message == WM_RBUTTONDOWN)//右击鼠标判断
		{
			M_x = MO.x / 27 + 1;
			M_y = MO.y / 27 + 1;
			//问号和标记如果与雷在同一个数组，则会改变原来的信息！！！

			if (M_x >= 1 && M_y >= 1 && M_x <= m.Width && M_y <= m.High && m.b[M_y][M_x] != 1)//在允许显示的情况下进行操作
			{
				if (m.b[M_y][M_x] == 0)
				{
					if (d.flag_n == 0)
					{

					}
					else
					{
						m.b[M_y][M_x] = 2;
					}
				}
				else if (m.b[M_y][M_x] == 2)
				{
					m.b[M_y][M_x] = 3;
				}
				else if (m.b[M_y][M_x] == 3)
				{
					m.b[M_y][M_x] = 0;
				}
			}
		}
	}
	EndBatchDraw();//结束绘图
	flushmessage();//清空消息缓冲区(否则选中框移动过慢

}

int DRAW::flag_n = 0;
DRAW::DRAW(const MAP& m) :
	m(m) {
	SYSTEMTIME start;
};
DRAW::~DRAW() {};

void DRAW::background()const
{
	initgraph(m.Width * 27 + 160, m.High * 27);//, SHOWCONSOLE(显示控制台窗口
	loadimage(&map, "./images/map.png");//loadimage(&map, _T(".\\bg.bmp"));
	putimage(0, 0, &map);
	GetLocalTime(&start);//开始计时

}

double DRAW::time()//精确到毫秒
{
	int t1, t2;
	int i, j;
	int a, b;
	double sum;
	SYSTEMTIME ti;   //定义和保存当前时间
	sum = 0;//总时间
	GetLocalTime(&ti);		// 获取当前时间
	sum += ti.wMinute - start.wMinute;
	sum *= 60;
	sum += ti.wSecond - start.wSecond;
	sum += (ti.wMilliseconds - start.wMilliseconds) * 1.0 / 1000;
	sum += gametime;
	i = 0;
	j = 0;
	t1 = sum;
	t2 = sum / 60;//对时间分钟和秒数的换算
	BeginBatchDraw();//开始批量绘图
	putimage(m.Width * 27 + 91, 20, &dot);
	putimage(m.Width * 27 + 91, 30, &dot);
	while (i != 2)
	{
		if (i == 0)
		{
			t1 = static_cast<int>(sum) % 60;
		}
		a = t1 % 10;
		putimage(m.Width * 27 + 128 - 30 * i, 0, &masks_2[a]);//显示秒数
		t1 = t1 / 10;
		i++;
	}
	while (j != 2)
	{
		b = t2 % 10;
		putimage(m.Width * 27 + 60 - 30 * j, 0, &masks_2[b]);//显示分钟
		t2 = t2 / 10;
		j++;
	}
	EndBatchDraw();//结束绘图
	return sum;
}

void DRAW::flag_num()
{
	int n = 0;//注意类中的局部变量和全局变量
	for (int i = 1; i <= m.High; i++)
	{
		for (int j = 1; j <= m.Width; j++)
		{
			if (m.a[i][j] == 9 && m.b[i][j] != 4)
			{
				n++;
			}
			if (m.b[i][j] == 2)
			{
				n--;
			}
		}
	}
	flag_n = n;
	BeginBatchDraw();//开始批量绘图,避免屏幕闪烁
	settextstyle(20, 0, _T("楷体"));
	char s[15];
	sprintf_s(s, "%d", flag_n);//int类型转化为字符数组，便于输出
	outtextxy(m.Width * 27 + 130, 60, s);
	outtextxy(m.Width * 27 + 10, 60, "剩余标记数：");
	if (n == 0)
	{
		//settextcolor(BLACK);
		outtextxy(120, 80, "标记已用完");
	}
	EndBatchDraw();//结束绘图
}

void DRAW::drawinit()const
{
	loadimage(&num_2[0], "./images/pg1.bmp", 27, 27);//用于显示已经翻开的空格
	loadimage(&num_2[1], "./images/p1.bmp", 27, 27);
	loadimage(&num_2[2], "./images/p2.bmp", 27, 27);
	loadimage(&num_2[3], "./images/p3.bmp", 27, 27);
	loadimage(&num_2[4], "./images/p4.bmp", 27, 27);
	loadimage(&num_2[5], "./images/p5.bmp", 27, 27);
	loadimage(&num_2[6], "./images/p6.bmp", 27, 27);
	loadimage(&num_2[7], "./images/p7.bmp", 27, 27);
	loadimage(&num_2[8], "./images/p8.bmp", 27, 27);
	//以上的为载入的显示周围雷的个数
	loadimage(&virus_2_1, "./images/virus1.png", 27, 27);
	loadimage(&virus_2_2, "./images/virus.png", 27, 27);
	loadimage(&virus_2_3, "./images/virus2.png", 27, 27);
	loadimage(&Score, "./images/r1.bmp", 27, 27);
	//以上为点击爆炸后显示的雷及相关的图片
	loadimage(&flag_2_1, "./images/flag.png", 27, 27);
	loadimage(&flag_2_2, "./images/flag2.png", 27, 27);
	//以上为右击的问号以及旗帜标识
	loadimage(&masks_2[0], "./images/t0.bmp");
	loadimage(&masks_2[1], "./images/t1.bmp");
	loadimage(&masks_2[2], "./images/t2.bmp");
	loadimage(&masks_2[3], "./images/t3.bmp");
	loadimage(&masks_2[4], "./images/t4.bmp");
	loadimage(&masks_2[5], "./images/t5.bmp");
	loadimage(&masks_2[6], "./images/t6.bmp");
	loadimage(&masks_2[7], "./images/t7.bmp");
	loadimage(&masks_2[8], "./images/t8.bmp");
	loadimage(&masks_2[9], "./images/t9.bmp");
	loadimage(&dot, "./images/dot.bmp");
	//以上为时钟的显示
	loadimage(&StateSetUp, "./images/背景1.png");
	//以上为状态栏的图片
	loadimage(&item[0], "./images/道具1.png", 90, 60);
	loadimage(&item[1], "./images/道具2.png", 90, 60);
	loadimage(&item[2], "./images/道具3.png");

}

void DRAW::show()const
{
	int i, j;
	BeginBatchDraw();//开始批量绘图,避免屏幕闪烁
	loadimage(&map, "./images/map.png");//loadimage(&map, _T(".\\bg.bmp"));
	putimage(0, 0, &map);
	putimage(m.Width * 27, 0, &StateSetUp);
	for (i = 1; i <= m.High; i++)
	{
		for (j = 1; j <= m.Width; j++)
		{
			if (m.a[i][j] == 9 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &virus_2_1);
				//putimage((j - 1) * 27, (i - 1) * 27, &bomb_2_2);
				//以下为爆炸后的声音
				//mciSendString("stop fmusic", NULL, 0, NULL);   // 先把前面一次的音乐停止
				//mciSendString("close fmusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
				//mciSendString("open .\\audio\\fail.mp3 alias fmusic", NULL, 0, NULL); // 打开失败音乐
				//mciSendString("play fmusic", NULL, 0, NULL); // 仅播放一次
			}
			if (m.a[i][j] == 9 && m.b[i][j] == 4)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &virus_2_3);
			}
			if (m.b[i][j] == 2)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &flag_2_1);//搜索全局并且标记出旗帜
			}
			if (m.b[i][j] == 3)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &flag_2_2);//搜索全局并且标记问号
			}
			if (m.a[i][j] != 9 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &num_2[0]);//搜索全局并且显示出翻开的格子(只要不是病毒都翻开
			}
			//搜索全局并且显示出周围病毒的数量1-8
			if (m.a[i][j] == 1 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &num_2[1]);
			}
			if (m.a[i][j] == 2 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &num_2[2]);
			}
			if (m.a[i][j] == 3 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &num_2[3]);
			}
			if (m.a[i][j] == 4 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &num_2[4]);
			}
			if (m.a[i][j] == 5 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &num_2[5]);
			}
			if (m.a[i][j] == 6 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &num_2[6]);
			}
			if (m.a[i][j] == 7 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &num_2[7]);
			}
			if (m.a[i][j] == 8 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &num_2[8]);
			}
		}
	}

	EndBatchDraw();//结束绘图
}
