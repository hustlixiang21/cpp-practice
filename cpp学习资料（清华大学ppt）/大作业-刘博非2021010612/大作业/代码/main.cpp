#include"class.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<graphics.h>
#include<conio.h>
#include<fstream>
using namespace std;


int main()
{
	//ȫ�ֱ�����ʵ����Ϸ�е�ѡ��������Ϸ�ṹ
	int w = 20, h = 20, n = 10;//Ĭ�ϵ�ͼ
	int choice = 0;//�˵�ѡ�0Ϊ�ص����˵���12Ϊ����ģʽ�Ĵ浵��4Ϊ��սģʽ
	MENU m_0;
	string one("file1"),two("file2");
	File f_1(one),f_2(two);
	while (choice==0) 
	{
		m_0.startMenu();
		m_0.control_0(w, h, n,choice);
		if (choice == 1)
		{
			MAP m(10, 10, 15);//���Ϊ24*30����Ӧ����648*810   ��1�������Ӧ*27������
			RECORD r;
			ITEM i(m);
			JUDGE j(m);
			DRAW d(m);
			MOUSE m_(m, j, d); 
			if (!f_1.load(m,d))
			{
				m.Setmap();
			}
			d.drawinit();
			d.background();
			while (1)
			{
				d.show();
				d.time();
				d.flag_num();
				m_.control(choice);
				i.item_1();//����1��˳���������������ж�ʤ��֮ǰ
				m.spread(d.time());
				j.correct(choice);
				Sleep(10);
				if (choice == 0)
				{
					if (j.correct(choice) == 0)
					{
						d.gametime = d.time();
						f_1.save(m, d);
						break;
					}
					if (j.correct(choice) == 1)
					{
						r.record(d.time());
						_getch();
						break;
					}
					if (j.correct(choice) == 2)
					{
						r.record();
						_getch();
						break;
					}
				}
			}
		}
		if (choice == 2)
		{
			int ctrl = 1;//����ʵ�ֵ��ߵĿ���
			MAP m(16, 20, 40);//���Ϊ24*30����Ӧ����648*810   ��1�������Ӧ*27������
			RECORD r;
			ITEM i(m);
			JUDGE j(m);
			DRAW d(m);
			MOUSE m_(m, j, d);
			if (!f_2.load(m, d))
			{
				m.Setmap();
			}
			d.drawinit();
			d.background();

			while (1)
			{
				d.show();
				d.time();
				d.flag_num();
				if (ctrl)
				{
					m_.control(choice);
				}
				i.item_2(ctrl,j);
				m.spread(d.time());
				j.correct(choice);
				Sleep(10);
				if (choice == 0)
				{
					if (j.correct(choice) == 0)
					{
						d.gametime = d.time();
						f_2.save(m, d);
						break;
					}
					if (j.correct(choice) == 1)
					{
						r.record(180,d.time());
						_getch();
						break;
					}
					if (j.correct(choice) == 2)
					{
						r.record();
						_getch();
						break;
					}
				}
			}
		}
		if (choice == 4)
		{
			MAP m(w, h, n);//���Ϊ24*30����Ӧ����648*810   ��1�������Ӧ*27������
			JUDGE j(m);
			m.Setmap();
			DRAW d(m);			
			MOUSE m_(m, j, d);		
			d.drawinit();
			d.background();
			while (1)
			{
				d.show();
				d.time();
				d.flag_num();
				m_.control(choice);
				j.correct(choice);
				Sleep(10);
				if (choice == 0)
				{
					_getch();
					break;
				}
			}
		}
	}
	return 0;
}
