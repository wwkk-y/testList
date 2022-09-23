//�Զ���ͼ�ο�
#pragma once
#ifndef BASE_H
#define BASE_H
#include <Windows.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <initializer_list>
using namespace std;

namespace win {
	void setFont(int size = 16);//���������С(�������ű�),16Ϊԭʼֵ
	void setSize(int w, int h);//���ô��ڿ�ߣ��в�߻�����
	void gotoxy(int y, int x);//���ù��λ��
	void setCursor(bool mode = false);//���ù����ʾ(���ػ�����ʾ)
	void setColor(WORD color = 0x7);
}

inline void clsbuf() {//������뻺����
	while (_kbhit()) {
		static_cast<void>(_getch());
	}
}
inline void eat() {//������뻺����
	while (cin.peek() != '\n') {
		cin.get();
	}
	cin.get();
}

class Base
{
protected:
	int x;//��¼��
	int y;//��¼��

	void cls();//����
	void hideCursor();//���ع��

	char** map;//��¼����
	WORD** mapColor;//��¼��ɫ
	void setColor(WORD color);//���������ɫ
	bool judgeX(int x);//�ж�x�Ƿ�Խ��
	bool judgeY(int y);//�ж�y�Ƿ�Խ��
public:
	Base(int x = 122, int y = 29);//��ʼ��
	virtual ~Base();//�ͷŶ��ڴ�

	//���ܸ�ֵ����ʱ����
	void operator=(const Base& b) = delete;
	Base(const Base& b) = delete;
	Base(const Base&& b) = delete;

	//���ݽӿ�
	int getX() const { return x; };
	int getY() const { return y; };
	int getXH() const { return x / 2; };//x��һ��
	int getYH() const { return y / 2; };//y��һ��
	char* getMap(int x, int y) { return &map[y][x]; };//���ܻ�Խ�磬����
	WORD* getMapColor(int x, int y) { return &mapColor[y][x]; };//���ܻ�Խ�磬����
	char** getmap() { return map; };//���ܻ�Խ�磬����
	WORD** getmapColor() { return mapColor; };//���ܻ�Խ�磬����
	char& Map(int y, int x) { return map[y][x]; };//���ܻ�Խ�磬����
	WORD& MapColor(int y, int x) { return mapColor[y][x]; };//���ܻ�Խ�磬����
	bool isAlive() const { return map; };//map����nullptr��ʱ�򷵻�false

	//�߿�
	Base& setBorder(char border = '/', WORD color = 0x7);//���ñ߿�
	Base& setBorderColor(WORD color);//���ñ߿���ɫ

	//�������
	Base& setText(int x, int y, const char* s, WORD color = 0x7, bool mode = true);//modeΪtrue����false����

	//���þ���������ɫ
	Base& setBufColor(int xStart, int yStart, int xEnd, int yEnd, WORD color);
	Base& setBufColor(int pos, int start, int end, WORD color, const char* mode = nullptr);//modeΪtrue����false����

	//���map
	void draw();

	//��ʼ��map
	Base& initMap();

	//����������������
	Base& gotoxy(int y, int x);

	Base& setFont(int size = 16);//���������С(�������ű�),16Ϊԭʼֵ
};
class Baseder//����һ��Base���Ӵ���
{
protected:
	bool state;
	int x;//��
	int y;//��
	int xpos;
	int ypos;
	Base* base;
	Baseder* baseder;
	char** mapT;//��������
	WORD** mapColorT;//��ɫ����

	char** map;//��������
	WORD** mapColor;//��ɫ����

	void setColor(WORD color);//���������ɫ
	bool judgeX(int x);//�ж�x�Ƿ�Խ��
	bool judgeY(int y);//�ж�y�Ƿ�Խ��

public:
	Baseder(int x, int y, int xPos, int yPos, Base& base);//����Base��(xPos,yPos)λ�õ�С����
	Baseder(int x, int y, int xPos, int yPos, Baseder& baseder);//����Baseder��С����;
	virtual ~Baseder();//ֻ���ͷŶ���ָ����ڴ棬base����ͷ�һ��ָ��
	Baseder(Baseder& b) :Baseder(b.x, b.y, b.xpos, b.ypos, *b.base) {};//ֻ�ܻ���base�Ĵ���
	Baseder(Base& b) :Baseder(b.getX(), b.getY(), 0, 0, b) {};//����base

	//���ܸ�ֵ����ʱ����
	void operator=(const Baseder& b) = delete;

	Baseder(const Baseder&& b) = delete;

	//���ݽӿ�
	int getX() const { return x; };
	int getY() const { return y; };
	int getXH() const { return x / 2; };//x��һ��
	int getYH() const { return y / 2; };//y��һ��

	char* getMap(int x, int y) { return &map[y][x]; };//���ܻ�Խ�磬����
	WORD* getMapColor(int x, int y) { return &mapColor[y][x]; };//���ܻ�Խ�磬����

	char** getmap() { return map; };//���ܻ�Խ�磬����
	WORD** getmapColor() { return mapColor; };//���ܻ�Խ�磬����
	char** getmapT() { return mapT; };//���ܻ�Խ�磬����
	WORD** getmapColorT() { return mapColorT; };//���ܻ�Խ�磬����

	char& Map(int y, int x) { return map[y][x]; };//���ܻ�Խ�磬����
	WORD& MapColor(int y, int x) { return mapColor[y][x]; };//���ܻ�Խ�磬����
	char MapT(int y, int x) const { return mapT[y][x]; };//���ܻ�Խ�磬����
	WORD MapColorT(int y, int x) const { return mapColorT[y][x]; };//���ܻ�Խ�磬����

	bool isAlive() const { return map; };//map����nullptr��ʱ�򷵻�false

	Base& getBase() { return *base; };
	Baseder& getBaseder() { return *baseder; };
	void reState();//state=false,�ͷ�MapT

	//���λ������
	int getXPos() const { if (baseder) { return baseder->getXPos() + xpos; } return xpos; };
	int getYPos() const { if (baseder) { return baseder->getYPos() + ypos; } return ypos; };

	//�߿�
	Baseder& setBorder(char border = '/', WORD color = 0x7);//���ñ߿�
	Baseder& setBorderColor(WORD color);//���ñ߿���ɫ
	virtual Baseder& setBorderLine(char ch = ' ');//���ñ߿�Ϊ��,ch��ʾ4����

	//�������
	Baseder& setText(int x, int y, const char* s, WORD color = 0x7, bool mode = true);//modeΪtrue����false����

	//���þ���������ɫ
	Baseder& setBufColor(int xStart, int yStart, int xEnd, int yEnd, WORD color);
	Baseder& setBufColor(int pos, int start, int end, WORD color, const char* mode = nullptr);//modeΪtrue����false����
	Baseder& setBufColor(int x, int y, WORD color) { mapColor[y][x] = color; return *this; };
	Baseder& setBkColor(WORD color, bool mode = false);//���ñ�����ɫ��mode��ʾ�Ƿ����ñ߿�

	//���map
	void draw();
	void show() { draw(); };//������Ϊ�麯��,��Ϊ�������෵�����͸�����ͬ��ʹ��ָ�������ʱ��ע��
	//��ʼ��map
	virtual Baseder& initMap();

	//�ر�map
	void close();//��map��mapColor��������ͷ�mapT��mapColorT�ڴ�

	//��������λ��
	Baseder& gotoxy(int y, int x);

	//���ñ���
	Baseder& setTitle(string title, bool mode = true);//mode����Ϊfalse�ڶ���,�����ڵײ�
};
using MenuItem = const char* [];
class Menu :public Baseder {
protected:
	char** str;
	int num;//str��Ԫ�ظ���
public:
	Menu(int x, int y, int xPos, int yPos, Base& base, const char* str[], int num);//����base 
	Menu(int x, int y, int xPos, int yPos, Baseder& baseder, const char* str[], int num);//����baseder
	Menu(Base& base, const char* str[], int num);//����base
	Menu(Baseder& baseder, const char* str[], int num);//����baseder
	//Menu(Menu& m);

	//Menu(int x, int y, int xPos, int yPos, Base& base, initializer_list<string> initls);//����base 
	//Menu(int x, int y, int xPos, int yPos, Baseder& baseder, initializer_list<string> initls);//����baseder
	//Menu(Base& base, initializer_list<string> initls);//����base
	//Menu(Baseder& baseder, initializer_list<string> initls);//����baseder
	virtual ~Menu();//�ͷŶ��ڴ�

	virtual int show(int cho = 0, bool init = true);//��ʼչʾ,����ֵΪѡ��,init����Ϊfalseʱ��initMap()
	//choΪ��ʼѡ��
//���ݽӿ�
	char** getItem() { return str; };
	int getNum() const { return num; };



	virtual Menu& push(MenuItem item, int n);//���ѡ��
	virtual Menu& push(const char* item);//���ѡ��

	virtual bool insert(MenuItem item, int qui, int index = 0);//����ѡ�� qui��ʾ���� ʧ�ܷ���true
	virtual bool insert(const char* item, int index = 0);//����ѡ�� ʧ�ܷ���true

	virtual Menu& reset(MenuItem item, int num);//��������ѡ��
	virtual Menu& reset(char** item, int num);//��������ѡ��
	//virtual Menu& reset(initializer_list<string> ls);
};
class Input :public Baseder {//������
public:
	Input(Base& base, int xPos = 0, int yPos = 0) :Baseder(base.getX() - xPos - 1, 1, xPos, yPos, base) { setBorder(' '); };//�����ֻ��һ��
	Input(Baseder& baseder, int xPos = 0, int yPos = 0) :Baseder(baseder.getX() - xPos - 1, 1, xPos, yPos, baseder) { setBorder(' '); };

	virtual string show();//����ֵΪ����ֵ
};
class InputBox :public Baseder {
	Input input;
public:
	InputBox(Base& base, int WITH, int xPos = 0, int yPos = 0) :Baseder(WITH, 3, xPos, yPos, base), input(base, xpos + 1, ypos + 1) {};
	InputBox(Baseder& baseder, int WITH, int xPos = 0, int yPos = 0) :Baseder(WITH, 3, xPos, yPos, baseder), input(baseder, xpos + 1, ypos = 1) {};

	virtual string show(bool mode = true);
};
class Label :public Baseder {
	InputBox inputBox;
	string str;
	string strR;
public:
	Label(Base& base, int xPos = 0, int yPos = 0, int WITH = 20) :Baseder(WITH, 3, xPos, yPos, base), inputBox(base, WITH, xPos, yPos), str() {};
	Label(Baseder& baseder, int xPos = 0, int yPos = 0, int WITH = 20) :Baseder(WITH, 3, xPos, yPos, baseder), inputBox(baseder, WITH, xPos, yPos), str() {};

	Label& setStr(const string& str);
	Label& setStrR(const string& strR) { this->strR = strR; return *this; };
	const string& getStr() { return str; };
	const string& getStrR() { return strR; };

	virtual string show(bool mode = true);//modeΪfalseֻ��inputBox
	virtual void showAll();//չʾ����������
};

#include <vector>
class LabelBox :public Baseder {//label����
	const int num;//Ԫ�ظ���
	vector<string> str;
	vector<string> strR;
public:
	LabelBox(Base& base, int num, int xPos = 0, int yPos = 0, int WITH = 20) :Baseder(WITH, 2 * num + 1, xPos, yPos, base), num(num) { setBorderLine(); };//num��ʾ����
	LabelBox(Baseder& baseder, int num, int xPos = 0, int yPos = 0, int WITH = 20) :Baseder(WITH, 2 * num + 1, xPos, yPos, baseder), num(num) { setBorderLine(); };

	//���ñ߿�
	LabelBox& setBorderLine();

	//���ñ�ǩ�����Ԫ��
	template <class It>
	LabelBox& setStr(It begin);//����������Ԫ��

	template <class It>
	LabelBox& setStr(It begin, int num);//����������Ԫ��(�������Ԫ��)

	LabelBox& setStr(const string& str, int index);//����index���ڲ���

	template <class It>
	LabelBox& setStrR(It begin);//����������Ԫ��(�������Ԫ��)

	template <class It>
	LabelBox& setStrR(It begin, int num);//����������Ԫ��

	LabelBox& setStrR(const string& str, int index);//����index���ڲ���

	//���ݽӿ�,���indexԽ���������index(ǰ����index<num)
	string& getStr(int index);
	string& getStrR(int index);

	void show();//����show(����Ԫ��)�������strRȻ������Ϊ����
	void showAll();//����showAll

	bool isNull() { return !(str.size() || strR.size()); };//�ж��Ƿ�Ϊ��
	bool isNullR() { return !strR.size(); };
};
class LabelBoxArr :public Baseder {//����LableBoxArr
	const int num;
	allocator<LabelBox> lb;
	LabelBox* head;
public:
	LabelBoxArr(Base& base, int num, int labelNum = 1, int xPos = 0, int yPos = 0, int WITH = 20);//num��ʾ����
	LabelBoxArr(Baseder& baseder, int num, int labelNum = 1, int xPos = 0, int yPos = 0, int WITH = 20);//labelNum�Ǵ���lableBox��num
	virtual ~LabelBoxArr();//�ͷ�allocator

	LabelBox& getLb(int index);//���ݽӿ�,��������Ƿ�Խ��

	void show(bool mode = true);//mode=tureʱ����showAll()
	void showAll();
	void showQueue();//��������,����ʱ����Ĳ���LabelBoxչʾ
	bool isNull();//�ж��Ƿ�Ϊ��
};

class InputTips :public Baseder {//����ʾ��������
	string tips;
public:
	InputTips(Base& base, int xPos = 0, int yPos = 0)
		:Baseder(base.getX() - xPos - 1, 1, xPos, yPos, base) {
		setBorder(' ');
	};//�����ֻ��һ��

	InputTips(Baseder& baseder, int xPos = 0, int yPos = 0)
		:Baseder(baseder.getX() - xPos - 1, 1, xPos, yPos, baseder) {
		setBorder(' ');
	};

	string& show();
	InputTips& setTips(const string& tip);
};

//ģ��дΪ��������
template<class It>
inline LabelBox& LabelBox::setStr(It begin)
{
	str.clear();
	for (int i = 0; i < num; ++i) {
		str.push_back(*begin);
		++begin;
	}
	// TODO: �ڴ˴����� return ���
	return *this;
}

template<class It>
inline LabelBox& LabelBox::setStr(It begin, int num)
{
	str.clear();
	num = num < this->num ? num : this->num;
	for (int i = 0; i < num; ++i) {
		str.push_back(*begin);
		++begin;
	}
	// TODO: �ڴ˴����� return ���
	return *this;
}

template<class It>
inline LabelBox& LabelBox::setStrR(It begin)
{
	strR.clear();
	for (int i = 0; i < num; ++i) {
		strR.push_back(*begin);
		++begin;
	}
	// TODO: �ڴ˴����� return ���
	return *this;
}

template<class It>
inline LabelBox& LabelBox::setStrR(It begin, int num)
{
	strR.clear();
	num = num < this->num ? num : this->num;
	for (int i = 0; i < num; ++i) {
		strR.push_back(*begin);
		++begin;
	}
	// TODO: �ڴ˴����� return ���
	return *this;
}
#endif