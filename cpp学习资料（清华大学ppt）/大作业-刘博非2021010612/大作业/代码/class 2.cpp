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

//ͼƬ
IMAGE Menu[5];//��ʼ�˵�
IMAGE num_2[9];//����ʾ���û�����Χ������ͼƬ����Ԥ����
IMAGE virus_2_1;//��ɫ�Ĳ�������ҵ���󱻸�Ⱦ
IMAGE virus_2_2;//��ɫ�Ĳ�����������ʾ���в�����λ��
IMAGE virus_2_3;//������õ��߷����Ĳ���
IMAGE flag_2_1;//���ڱ�ʾС����
IMAGE flag_2_2;//���ڱ�־�ʺŵ�ͼƬԤ����
IMAGE StateSetUp;//����Ԥ�����ʼ�����ұ�״̬
IMAGE masks_2[10];//�����ұߵļ�ʱ�����õ�������
IMAGE item[3];//����ͼƬ
IMAGE map;//�����ͼ����ͼƬ
IMAGE dot;//������ʾ���Ҳ�״̬����ĵ�
IMAGE Score;//������ʾ�����ȷ�Ĳ���
SYSTEMTIME start;//��ʱģ��

void MENU::startMenu()const
{
	loadimage(&Menu[0], "./images/menu1.bmp");
	loadimage(&Menu[1], "./images/menu2.bmp");
	//�˵�ͼƬ
	initgraph(500, 750);//����ʾ����̨����, SHOWCONSOLE
	putimage(0, 0, &Menu[0]);
	setfillcolor(RGB(20, 50, 120));
	fillrectangle(150, 225, 350, 275);
	fillrectangle(150, 300, 350, 350);
	fillrectangle(250, 400, 350, 450);

	setbkmode(TRANSPARENT);//����������ַ���ɫ͸��
	outtextxy(220, 238, "��ʼ��Ϸ");
	outtextxy(220, 318, "�˳���Ϸ");
	outtextxy(270, 420, "��Ϸ��¼");
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
	setbkmode(TRANSPARENT);//����������ַ���ɫ͸��
	outtextxy(220, 168, "�ؿ�1");
	outtextxy(220, 238, "�ؿ�2");
	//outtextxy(220, 318, "�ؿ�3");
	settextstyle(30, 20, _T("����"));
	outtextxy(80, 150, "��");
	outtextxy(80, 180, "��");
	outtextxy(80, 210, "ģ");
	outtextxy(80, 240, "ʽ");
	outtextxy(185, 415, "��սģʽ");

}

void MENU::control_0(int& w, int& h, int& n, int& c)
{
	bool out = 0;
	ExMessage MO;//MOUSEMSG MO;
	while (1)
	{
		MO = getmessage();//�����λ�õĻ�ȡ������
		if (MO.message == WM_MOUSEMOVE)//������λ�õĸ��٣�����ѡ�п�
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
		if (MO.message == WM_LBUTTONDOWN)//�������ж�
		{
			if (MO.x >= 150 && MO.y >= 225 && MO.x <= 350 && MO.y <= 275)//��ʼ��Ϸ
			{
				fileMenu();
				while (1)
				{
					MO = getmessage();//�����λ�õĻ�ȡ������
					if (MO.message == WM_MOUSEMOVE)//������λ�õĸ��٣�����ѡ�п�
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
					if (MO.message == WM_LBUTTONDOWN)//�������ж�
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
							// ��ʼ����ͼ����
							initgraph(640, 480);

							// �����ַ����������û�����
							char s1[10], s2[10], s3[10];
							InputBox(s1, 10, _T("�������ȣ�9-24֮�䣩"));
							w = strtol(s1, 0, 10);// ���û�����ת��Ϊ����
							while (w < 9 || w>24)
							{
								InputBox(s1, 10, _T("���������Ҫ��Ŀ�ȣ�9-24֮�䣩"));
								w = strtol(s1, 0, 10);
							}
							InputBox(s2, 10, _T("�����볤�ȣ�9-30֮�䣩"));
							h = strtol(s2, 0, 10);
							while (h < 9 || h>30)
							{
								InputBox(s2, 10, _T("���������Ҫ��ĳ��ȣ�9-30֮�䣩"));
								h = strtol(s2, 0, 10);
							}
							InputBox(s3, 10, _T("�����벡������10-668֮��)"));
							n = strtol(s3, 0, 10);
							while (n < 10 || n>668)
							{
								InputBox(s3, 10, _T("���������Ҫ��Ĳ�������10-668֮��)"));
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
			if (MO.x >= 150 && MO.y >= 300 && MO.x <= 350 && MO.y <= 350)//�˳���Ϸ
			{
				closegraph();
				exit(1);
			}
			if (MO.x >= 250 && MO.y >= 400 && MO.x <= 350 && MO.y <= 450)//���а�
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
	InputBox(s1, 10, _T("�Ƿ񱣴���Ϸ�������롮1��Ϊ���棬���롮0��Ϊ������"));
	c = strtol(s1, 0, 10);// ���û�����ת��Ϊ����
	while (c != 0 && c != 1)
	{
		InputBox(s1, 10, _T("���������Ҫ������֣�0��1��"));
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
	InputBox(s1, 10, _T("�Ƿ��ȡ��Ϸ�浵�������롮1��Ϊ�ǣ����롮0��Ϊ��"));
	c = strtol(s1, 0, 10);// ���û�����ת��Ϊ����
	while (c != 0 && c != 1)
	{
		InputBox(s1, 10, _T("���������Ҫ������֣�0��1��"));
		c = strtol(s1, 0, 10);
	}
	if (c == 1)
	{
		int f = 0;//��ֹ������ļ��Ĵ浵���ȼ���ԭ�ļ�����������
		ifstream myFile(name, ios_base::binary);
		for (int i = 1; i <= m.High; i++)
		{
			for (int j = 1; j <= m.Width; j++)
			{
				myFile.read(reinterpret_cast<char*>(&m.a[i][j]), sizeof(m.a[i][j]));
				myFile.read(reinterpret_cast<char*>(&m.b[i][j]), sizeof(m.b[i][j]));
				if (m.a[i][j] >= 0)//ֻ����һ��ֵ����0��˵�����ǿ��ĵ������������
				{
					f = 1;
				}
			}
		}
		if (f == 0)//�ǿ��ĵ�
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

Button::Button(int x, int y, int height, int width)//���캯��
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
		c = 0;//�ı�choice��ֵ���������˵�
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
	BeginBatchDraw();//��ʼ������ͼ,������Ļ��˸
	Button i_1(m.Width * 27 + 70, 100, 90, 90);
	i_1.draw();
	setbkmode(TRANSPARENT);//����������ַ���ɫ͸��
	outtextxy(m.Width * 27 + 72, 165, "����(A)");
	putimage(m.Width * 27 + 70, 100, &item[0]);
	FlushBatchDraw();
	if (_kbhit())  // �ж��Ƿ�������
	{
		input = _getch();  // �����û��Ĳ�ͬ�������жϣ���������س�
		if (input == 'a')
		{
			use_1 = 1;
		}
	}
	if (use_1 == 1)
	{
		setbkmode(OPAQUE);//����������ַ���ɫΪĬ��
		outtextxy(m.Width * 27 + 72, 165, "ʹ����  ");
		i_1.isPressed();
		setbkmode(TRANSPARENT);
		for (int i = 1; i <= m.High; i++)
		{
			for (int j = 1; j <= m.Width; j++)
			{
				if (m.a[i][j] == 9 && m.b[i][j] == 1)//���ַ�������
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
	BeginBatchDraw();//��ʼ������ͼ,������Ļ��˸
	Button i_2(m.Width * 27 + 70, 190, 90, 90);
	i_2.draw();
	putimage(m.Width * 27 + 70, 190, &item[1]);
	FlushBatchDraw();
	if (_kbhit())  // �ж��Ƿ�������
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
		setbkmode(TRANSPARENT);//����������ַ���ɫ͸��
		outtextxy(m.Width * 27 + 72, 255, "������(S)");
		EndBatchDraw();
	}
	else if (use_2 == 1)
	{
		BeginBatchDraw();
		c = 0;
		setbkmode(OPAQUE);//����������ַ���ɫΪĬ��
		outtextxy(m.Width * 27 + 72, 255, " ʹ����  ");
		i_2.isPressed();
		setbkmode(TRANSPARENT);
		EndBatchDraw();
		int M_x, M_y;
		ExMessage MO;//MOUSEMSG MO;
		if (peekmessage(&MO, EM_MOUSE, false))
		{
			MO = getmessage();//�����λ�õĻ�ȡ������
			if (MO.message == WM_MOUSEMOVE)//������λ�õĸ��٣�����ѡ�п�
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
			if (MO.message == WM_LBUTTONDOWN)//�������ж�
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

void RECORD::record(const int t,const int t2)const//������Ϸ��¼����Ϸ���������ͨ��ʱ��
{
	int x = 0, t_ = 180, t_2 = 240;
	ifstream myFile1("record", ios_base::binary);
	myFile1.read(reinterpret_cast<char*>(&x), sizeof(x));//��ȡ��Ϸ����
	if (x < 0)
		x = 0;
	myFile1.read(reinterpret_cast<char*>(&t_), sizeof(t_));//��ȡ��һ�����ʱ��
	myFile1.read(reinterpret_cast<char*>(&t_2), sizeof(t_2));//��ȡ�ڶ������ʱ��
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
	setbkmode(TRANSPARENT);//����������ַ���ɫ͸��
	outtextxy(180, 168, "��Ϸ����");
	outtextxy(180, 238, "��һ�����ʱ��");
	outtextxy(180, 308, "�ڶ������ʱ��");
	char s1[15], s2[15],s3[15];
	sprintf_s(s1, "%d", x);//int����ת��Ϊ�ַ����飬�������
	sprintf_s(s2, "%d", t_);
	sprintf_s(s3, "%d", t_2);
	outtextxy(280, 168, s1);
	outtextxy(320, 238, s2);
	outtextxy(320, 308, s3);
	outtextxy(90, 100, "(�������ⰴ���������˵���");
}

MAP::MAP(const int h, const int w, const int n) :
	High(h), Width(w), Minenumber(n)
{
	//���������ͼ��Ϣ�Ķ�ά���飬ȫ����[1]��ʼ
	a = new int* [High + 1];//a��ֵΪ9���ʾ�в���(��Ϊ�ж�����)��Ϊ0���ʾ�޲�����������:����1-8��ʾ��Χ����������Χ�޲�����Ϊ10//�� int** a=new int *[High+1];  �ȼ�
	for (int i = 0; i <= High; i++)
	{
		a[i] = new int[Width + 1];
	}
	b = new int* [High + 1];//b���淽���Ƿ񱻷�������Ϣ��δ������Ϊ0��������Ϊ1�������Ϊ2���ʺ���Ϊ3,����������Ϊ4
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

int MAP::search_x(const int n)const//������n���������ڵĺ�����
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
	for (i = 1; i <= High; i++)//��ʼ��ȫ��Ϊ0
	{
		for (j = 1; j <= Width; j++)
		{
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}
	i = 1, j = 1;
	//ϴ���㷨ʵ�ֿ����������
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
	for (int k = 1; k <= Minenumber; k++)//����ǰx��λ�ò��ף�Ȼ�����ǰx��λ�ã�ÿ��λ�úͰ��������ڵ�֮��ÿ��λ�ý��н���������x�ν�����ÿ��λ�����׵ĸ��ʶ���x/������ʵ�ֵȸ����Ҳ��ظ��ز���
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
				if (a[i][j] > 0 && a[i][j] < 9 && b[i][j] != 1 && b[i][j] != 2)//�������и����в�����δ����ǻ򷭿��ķ���
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

JUDGE::JUDGE(const MAP& m1) :m(m1) { };//m(m1)���ø��ƹ��캯����m=m1���ù��캯�������ڰ�ȫ�Կ��ǣ���ʵ��Ӧ������m��ΪJUDGE�ĳ�Ա
JUDGE::~JUDGE() {};

void JUDGE::judge(const int x, const int y)//(���)�㿪����ֻ������������в������޲�������ʾ��Χ������������Χ�޲�������ɨ
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

int JUDGE::virus_num(const int x, const int y)const//ע������xΪ�����꣬yΪ�����꣬��������ӦΪa[y][x]
{
	int x_, y_, num = 0;

	for (int i = 0; i < 9; i++)//����һ����������
	{
		x_ = x + i % 3 - 1;
		y_ = y + i / 3 - 1;

		if (x_ >= 1 && y_ >= 1 && x_ <= m.Width && y_ <= m.High)
		{
			if ((x_ != x || y_ != y) && m.a[y_][x_] == 9)//��һ�εĴ���ԭ���Ƕ�̬�����ں����ڲ������������ڴ���ͷţ���ȡ����Ȩ�޳�ͻ��
				num++;
		}
	}
	return num;
}

void JUDGE::sweep(const int x, const int y)//��ָ̬��
{
	Position p(x, y);
	Position* head = &p, * tail = &p;//ǰ������ָ�룬����ʵ�ֹ����������
	Position* plist = &p;//ָ��p����������ڴ���ͷ�
	do
	{
		if (head->next != 0)//��ָ�����
		{
			head = head->next;
		}
		int x_, y_;
		for (int i = 0; i < 9; i++)//����һ����������
		{
			x_ = head->p_x + i % 3 - 1;
			y_ = head->p_y + i / 3 - 1;
			if (x_ >= 1 && y_ >= 1 && x_ <= m.Width && y_ <= m.High)//&& (x_ != head->p_x || y_ != head->p_y)
			{
				if (m.a[y_][x_] == 9)
				{
					//����ԭ��
				}
				else if (virus_num(x_, y_) > 0 && m.b[y_][x_] != 2 && m.b[y_][x_] != 1)
				{
					m.a[y_][x_] = virus_num(x_, y_);
					m.b[y_][x_] = 1;
				}
				else if (virus_num(x_, y_) == 0 && m.b[y_][x_] != 2 && m.b[y_][x_] != 1)//�������������ķ��飬βָ������
				{
					m.a[y_][x_] = 10;
					m.b[y_][x_] = 1;
					//Position p_(x_, y_);//�������������
					tail->next = new Position(x_, y_);//ע��Ҫdelete�����ڴ�й¶!!!
					tail = tail->next;
				}
			}
		}
	} while (head != tail);
	head = plist->next; // ��ʱheadָ��plist����һ����㣬��һ����㲻��ɾ��������new�õ��ģ���
	while (head != NULL)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
	plist = NULL; // ֻ���ͷ������ڴ�ռ䣬ָ�������ָ��ֵ��û�б���Ϊ��
	
}

int JUDGE::correct(int& c)//���Ų�������ɢ����֤������ʾ������ȷ,ͬʱ�ж���Ϸ��ʤ��������1Ϊʤ��2Ϊ����0Ϊδ����
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
			if (m.a[i][j] == 9 && m.b[i][j] == 1 || n_virus > m.High * m.Width / 3)//�����������򲡶�����������������1/2������Ϸʧ��
			{
				//cout << "��Ϸʧ��";
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
		setbkmode(OPAQUE);//����������ַ���ɫΪĬ��
		settextcolor(WHITE);
		settextstyle(16, 0, _T("Consolas"));
		outtextxy(120, 80, "��Ϸ����");
		outtextxy(90, 100, "(�������ⰴ���������˵���");
		return 2;
	}
	for (int i = 1; i <= m.High; i++)
	{
		for (int j = 1; j <= m.Width; j++)
		{
			if (m.a[i][j] == 9 && m.b[i][j] != 2 && m.b[i][j] != 4)//�����в��������  ��Ϸʤ����ֻҪ��һ������δ�����  ��û��ʤ����ע��Ҫ��֤�������������������
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
		setbkmode(OPAQUE);//����������ַ���ɫΪĬ��
		settextcolor(WHITE);
		settextstyle(16, 0, _T("Consolas"));
		outtextxy(120, 80, "��Ϸʤ��");
		outtextxy(90, 100, "(�������ⰴ���������˵���");
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
	setbkmode(TRANSPARENT);//����������ַ���ɫ͸��
	outtextxy(m.Width * 27 + 90, m.High * 27 - 30, "����");
	ExMessage MO;//MOUSEMSG MO;
	if (peekmessage(&MO, EM_MOUSE, false))
	{
		MO = getmessage();//�����λ�õĻ�ȡ������
		if (MO.message == WM_MOUSEMOVE)//������λ�õĸ��٣�����ѡ�п�
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
		if (MO.message == WM_LBUTTONDOWN)//�������ж�
		{
			b1.isClicked(MO.x, MO.y, c);
			M_x = MO.x / 27 + 1;
			M_y = MO.y / 27 + 1;
			if (M_x >= 1 && M_y >= 1 && M_x <= m.Width && M_y <= m.High && (m.b[M_y][M_x] == 0 || m.b[M_y][M_x] == 3))//��������ʾ������½��в���
			{
				m.b[M_y][M_x] = 1;
				ju.judge(M_x, M_y);
			}

		}
		if (MO.message == WM_RBUTTONDOWN)//�һ�����ж�
		{
			M_x = MO.x / 27 + 1;
			M_y = MO.y / 27 + 1;
			//�ʺźͱ�����������ͬһ�����飬���ı�ԭ������Ϣ������

			if (M_x >= 1 && M_y >= 1 && M_x <= m.Width && M_y <= m.High && m.b[M_y][M_x] != 1)//��������ʾ������½��в���
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
	EndBatchDraw();//������ͼ
	flushmessage();//�����Ϣ������(����ѡ�п��ƶ�����

}

int DRAW::flag_n = 0;
DRAW::DRAW(const MAP& m) :
	m(m) {
	SYSTEMTIME start;
};
DRAW::~DRAW() {};

void DRAW::background()const
{
	initgraph(m.Width * 27 + 160, m.High * 27);//, SHOWCONSOLE(��ʾ����̨����
	loadimage(&map, "./images/map.png");//loadimage(&map, _T(".\\bg.bmp"));
	putimage(0, 0, &map);
	GetLocalTime(&start);//��ʼ��ʱ

}

double DRAW::time()//��ȷ������
{
	int t1, t2;
	int i, j;
	int a, b;
	double sum;
	SYSTEMTIME ti;   //����ͱ��浱ǰʱ��
	sum = 0;//��ʱ��
	GetLocalTime(&ti);		// ��ȡ��ǰʱ��
	sum += ti.wMinute - start.wMinute;
	sum *= 60;
	sum += ti.wSecond - start.wSecond;
	sum += (ti.wMilliseconds - start.wMilliseconds) * 1.0 / 1000;
	sum += gametime;
	i = 0;
	j = 0;
	t1 = sum;
	t2 = sum / 60;//��ʱ����Ӻ������Ļ���
	BeginBatchDraw();//��ʼ������ͼ
	putimage(m.Width * 27 + 91, 20, &dot);
	putimage(m.Width * 27 + 91, 30, &dot);
	while (i != 2)
	{
		if (i == 0)
		{
			t1 = static_cast<int>(sum) % 60;
		}
		a = t1 % 10;
		putimage(m.Width * 27 + 128 - 30 * i, 0, &masks_2[a]);//��ʾ����
		t1 = t1 / 10;
		i++;
	}
	while (j != 2)
	{
		b = t2 % 10;
		putimage(m.Width * 27 + 60 - 30 * j, 0, &masks_2[b]);//��ʾ����
		t2 = t2 / 10;
		j++;
	}
	EndBatchDraw();//������ͼ
	return sum;
}

void DRAW::flag_num()
{
	int n = 0;//ע�����еľֲ�������ȫ�ֱ���
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
	BeginBatchDraw();//��ʼ������ͼ,������Ļ��˸
	settextstyle(20, 0, _T("����"));
	char s[15];
	sprintf_s(s, "%d", flag_n);//int����ת��Ϊ�ַ����飬�������
	outtextxy(m.Width * 27 + 130, 60, s);
	outtextxy(m.Width * 27 + 10, 60, "ʣ��������");
	if (n == 0)
	{
		//settextcolor(BLACK);
		outtextxy(120, 80, "���������");
	}
	EndBatchDraw();//������ͼ
}

void DRAW::drawinit()const
{
	loadimage(&num_2[0], "./images/pg1.bmp", 27, 27);//������ʾ�Ѿ������Ŀո�
	loadimage(&num_2[1], "./images/p1.bmp", 27, 27);
	loadimage(&num_2[2], "./images/p2.bmp", 27, 27);
	loadimage(&num_2[3], "./images/p3.bmp", 27, 27);
	loadimage(&num_2[4], "./images/p4.bmp", 27, 27);
	loadimage(&num_2[5], "./images/p5.bmp", 27, 27);
	loadimage(&num_2[6], "./images/p6.bmp", 27, 27);
	loadimage(&num_2[7], "./images/p7.bmp", 27, 27);
	loadimage(&num_2[8], "./images/p8.bmp", 27, 27);
	//���ϵ�Ϊ�������ʾ��Χ�׵ĸ���
	loadimage(&virus_2_1, "./images/virus1.png", 27, 27);
	loadimage(&virus_2_2, "./images/virus.png", 27, 27);
	loadimage(&virus_2_3, "./images/virus2.png", 27, 27);
	loadimage(&Score, "./images/r1.bmp", 27, 27);
	//����Ϊ�����ը����ʾ���׼���ص�ͼƬ
	loadimage(&flag_2_1, "./images/flag.png", 27, 27);
	loadimage(&flag_2_2, "./images/flag2.png", 27, 27);
	//����Ϊ�һ����ʺ��Լ����ı�ʶ
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
	//����Ϊʱ�ӵ���ʾ
	loadimage(&StateSetUp, "./images/����1.png");
	//����Ϊ״̬����ͼƬ
	loadimage(&item[0], "./images/����1.png", 90, 60);
	loadimage(&item[1], "./images/����2.png", 90, 60);
	loadimage(&item[2], "./images/����3.png");

}

void DRAW::show()const
{
	int i, j;
	BeginBatchDraw();//��ʼ������ͼ,������Ļ��˸
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
				//����Ϊ��ը�������
				//mciSendString("stop fmusic", NULL, 0, NULL);   // �Ȱ�ǰ��һ�ε�����ֹͣ
				//mciSendString("close fmusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
				//mciSendString("open .\\audio\\fail.mp3 alias fmusic", NULL, 0, NULL); // ��ʧ������
				//mciSendString("play fmusic", NULL, 0, NULL); // ������һ��
			}
			if (m.a[i][j] == 9 && m.b[i][j] == 4)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &virus_2_3);
			}
			if (m.b[i][j] == 2)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &flag_2_1);//����ȫ�ֲ��ұ�ǳ�����
			}
			if (m.b[i][j] == 3)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &flag_2_2);//����ȫ�ֲ��ұ���ʺ�
			}
			if (m.a[i][j] != 9 && m.b[i][j] == 1)
			{
				putimage((j - 1) * 27, (i - 1) * 27, &num_2[0]);//����ȫ�ֲ�����ʾ�������ĸ���(ֻҪ���ǲ���������
			}
			//����ȫ�ֲ�����ʾ����Χ����������1-8
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

	EndBatchDraw();//������ͼ
}
