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
	//全局变量来实现游戏中的选择，完善游戏结构
	int w = 20, h = 20, n = 10;//默认地图
	int choice = 0;//菜单选项，0为回到主菜单，12为闯关模式的存档，4为挑战模式
	MENU m_0;
	string one("file1"),two("file2");
	File f_1(one),f_2(two);
	while (choice==0) 
	{
		m_0.startMenu();
		m_0.control_0(w, h, n,choice);
		if (choice == 1)
		{
			MAP m(10, 10, 15);//最大为24*30，对应像素648*810   （1个坐标对应*27的像素
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
				i.item_1();//道具1的顺序需在鼠标操作后，判断胜负之前
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
			int ctrl = 1;//用于实现道具的控制
			MAP m(16, 20, 40);//最大为24*30，对应像素648*810   （1个坐标对应*27的像素
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
			MAP m(w, h, n);//最大为24*30，对应像素648*810   （1个坐标对应*27的像素
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
