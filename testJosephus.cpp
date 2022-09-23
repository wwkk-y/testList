#include "testJosephus.h"
#include "LinkList.h"
#include <conio.h>
#include <iostream>

void testJosephus(Base& base)
{
	
	Baseder up(base.getX()-2, 4, 1, 1, base);
	up.setBorderLine();
	up.setText(1, 1, "Լɪ��(Josephus)����:",0x06);
	up.setText(1, 2, 
	"    ��n��С��(���1~n)Χ��һȦ���ӵ�1��С����ʼ��˳ʱ�뷽���1~mѭ����������m��С����Ȧ�����ʣ�µ�С��Ϊʤ���ߡ�",0x06);
	
	Label lbNum(base, 1, 4, base.getXH()-1);
	Label lbGap(base, base.getXH()-1, 4, base.getX() - lbNum.getX()-1);
	lbNum.setStr("  ������С������n(����)  ").setBorderLine();
	lbGap.setStr("  ��������m(����)  ").setBorderLine();
	
	Baseder region(base.getX() - 2, base.getY() - up.getY() - 2 - 1, 1, up.getY() + 2,base);
	region.setBorderLine('*');
	up.draw();
	
	int num=10;
	int gap=3;
	try {
		num = stoi(lbNum.show());
		gap = stoi(lbGap.show());
	}
	catch (...) {//������벻������
		lbNum.setStrR(to_string(num).c_str()).showAll();
		lbGap.setStrR(to_string(gap).c_str()).showAll();

	}
	if (num < 0) { num = 10; }//������С��0
	if (gap <= 0) { gap = 3; }

	showJosephus(region, num, gap);

	up.close(); lbNum.close(); lbGap.close(); region.close();
}

void showJosephus(Baseder& baseder, int num, int gap) {
	LinkList<string> ls;
	for (int i = 0; i < num; ++i) {
		ls.push_back(to_string(i+1));
	}

	win::setCursor(true);
	int yt = 1;
	int temp = 0;
	int count = 1;
	while (1) {
		yt=ls.showJosephus(baseder.getX() - 2, baseder, 1, 1, temp);
		baseder.gotoxy(yt + 1, 1);
		
		if (count == gap) {
			cout << ls[temp] << " ����...";
			ls.erase(ls.begin()+temp);
			if (ls.size() == 1) {
				cout << "   " << ls[0] << " ʤ��...";
				break;
			}
			eat();

			--temp;
			count = 0;
			

			baseder.gotoxy(yt, 1);
			for (int i = 0; i < baseder.getX() - 2; ++i) {
				cout << " ";
			}
			baseder.gotoxy(yt + 1, 1);
			for (int i = 0; i < baseder.getX() - 2; ++i) {
				cout << " ";
			}
			if (temp + 1 == ls.size()) {
				temp = -1;

			}
			++temp;
			++count;
			continue;
		}

		if (temp + 1 == ls.size()) {
			temp = -1;

		}

		static_cast<void>(_getch());
		++temp;
		++count;
	}

	cin.get();
	win::setCursor();
}