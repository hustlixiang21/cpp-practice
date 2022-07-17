#pragma once
#include<string>
using namespace std;
//ǰ����������
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
	void control_0(int& w, int& h, int& n, int& c);//ʵ�������˵������ĺ���
	void startMenu()const;//��ʾ���˵�����ĺ���
	void fileMenu()const;//��ʾ��Ϸģʽ�˵�����ĺ���
};
class File
{
private:
	string name;//�浵�ļ�����
public:
	File(const string& n) { name = n; };//���캯��
	void save(const MAP& m, DRAW& d)const;//ͨ���ļ�������Ϸ�浵
	int load(const MAP& m, DRAW& d)const;//ͨ���ļ���ȡ��Ϸ�浵
};
class Button
{
public:
	Button(int x, int y, int height, int width);//���캯��
	int x;//�����ĺ�����
	int y;//������������
	int height;//�����ĳ���
	int width;//�����Ŀ��
	void isClicked(int cx, int cy, int& c)const;//��������¼�
	void isMoved(int cx, int cy)const;//����ƶ��¼�
	void draw()const;//��������
	void isPressed()const;//���̽����¼�
};
class Position//���淽���λ����Ϣ�����ڹ�����������������ʵ��
{
private:
	const int p_x, p_y;//������ĺ�������
	Position* next;//�����¸����ĵ�ַ
public:
	Position(const int x = 1, const int y = 1) :p_x(x), p_y(y)//���캯��
	{
		next = 0;
	};
	friend class JUDGE;//��Ԫ��
};
class MAP
{
private:
	const int  High, Width, Minenumber;//��ͼ������Ϣ�����ȡ���ȺͲ�������
	int** a = 0;//��ά��̬����,�����ͼ��Ϣ���Ƿ��в������Լ�������Χ�Ĳ�������
	int** b = 0;//��ά��̬����,�����ͼ��Ϣ�������Ƿ񱻷������Լ��Ƿ񱻱��
public:
	MAP(const int h = 9, const int w = 9, const int n = 50);//���캯��
	~MAP();//��������
	int search_x(const int n)const;//������n���������ڵĺ�����
	int search_y(const int n)const;//������n���������ڵ�������
	void Setmap();//ͨ��ϴ���㷨ʵ��������ף���ɵ�ͼ�ĳ�ʼ��
	void spread(const double t);//��������ɢ ��ʹ����������ڲ�����Χ��������µĲ���
	friend class JUDGE;//��Ԫ��
	friend class MOUSE;//��Ԫ��
	friend class DRAW;//��Ԫ��
	friend class File;//��Ԫ��
	friend class ITEM;//��Ԫ��
};
class JUDGE
{
private:
	const MAP m;//��Ϸ��ͼ����
public:
	JUDGE(const MAP& m1);
	~JUDGE();
	void judge(const int x, const int y);//��������������жϸ�λ���Ƿ��в�����
	int virus_num(const int x, const int y)const;//�õ���λ�þŹ����ڵĲ�����
	void sweep(const int x, const int y);//��ɨ���飨��ĳ��λ���޲�������ɨ���ж�����Χ�������Ƿ��в��������޼�����ɨ��������������㷨
	int correct(int& c);//���ݲ�����Ŀ�ı仯����֤��ʾ���ֵ���ȷ���Լ��ж���Ϸ��ʤ��
	friend class MOUSE;
	friend class ITEM;
};
class DRAW
{
private:
	const MAP m;//��Ϸ��ͼ����
	static int flag_n;//������Ϸ��ʣ��ı����
public:
	DRAW(const MAP& m);//���캯��
	~DRAW();//��������
	double gametime = 0;//ʱ�侫ȷ������
	void drawinit()const;//ͼƬ������
	void background()const;//��ͼ��������ʾ
	void show()const;//��Ϸ�������ʾ��ʵʱ����
	double time();//��Ϸʱ��ļ�¼����ʾ
	void flag_num();//��ʾʣ����õı����
	friend class MOUSE;
	friend class File;
};
class MOUSE
{
private:
	const MAP m;//��Ϸ��ͼ����
	JUDGE ju;//��Ϸ�ж϶���
	const DRAW d;//��Ϸ��ͼ����
	int M_x, M_y;//��������ڵ�ͼ�е�λ��
public:
	MOUSE(const MAP& m, JUDGE& j, DRAW& d);//���캯��
	~MOUSE();//��������
	void control(int& c);//�����ƣ���������ƶ���������Ҽ����
};
class RECORD
{
public:
	void record(int t = 180,int t2=240)const;//������Ϸ��¼
	void show_r()const;//��Ϸ��¼����ʾ
};
class ITEM
{
private:
	const MAP m;// ��Ϸ��ͼ����
	int use_1;//����1�Ƿ���ʹ�õ���Ϣ
	int use_2;//����2�Ƿ���ʹ�õ���Ϣ
public:
	ITEM(const MAP& m);//���캯��
	void item_1();//����1������
	void item_2(int& c, JUDGE& ju);//����2��������
};



