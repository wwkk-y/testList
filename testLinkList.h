//����������

#ifndef TESTLINKLIST_H
#define TESTLINKLIST_H
#include "Base.h"
#include "LinkList.h"
#include <conio.h>
#include <iostream>
using namespace std;
void testLinkList(Base &base);//���������๦��


void testConstruct(Menu& m2, Menu& m3, Baseder& baseder,LinkList<string>& ls);//
																			//������أ�����,����,���ڣ�����
void startIO(Menu& m3, Baseder& baseder, LinkList<string>& ls);//ͨ��IO������list
void stdIO(Baseder& baseder, LinkList<string>& ls);//��׼IO
void fileIO(Baseder& baseder, LinkList<string>& ls);//�ļ�IO

void startConstruct(Menu& m3, Baseder& baseder, LinkList<string>& ls);//����
void defaultConstruct(Baseder& baseder, LinkList<string>& ls);//Ĭ�Ϲ���
void listConstruct(Baseder& baseder, LinkList<string>& ls);//�б���
void valueConstruct(Baseder& baseder, LinkList<string>& ls);//��ֵ����
void valueNumConstruct(Baseder& baseder, LinkList<string>& ls);//num��value����
void cpyConstruct(Baseder& baseder, LinkList<string>& ls);//���ƹ���
void refConstruct(Baseder& baseder, LinkList<string>& ls);//��ֵ���ù���
void iteConstruct(Baseder& baseder, LinkList<string>& ls);//����������

void startEqual(Menu& m3, Baseder& baseder, LinkList<string>& ls);//operator=
void equalSelf(Baseder& baseder, LinkList<string>& ls);//�Լ���ֵ�Լ�
void equalElse(Baseder& baseder, LinkList<string>& ls);//��ֵ��������

void startDecon(Menu& m3, Baseder& baseder, LinkList<string>& ls);//����

void addOpt(Menu& m2, Menu& m3, Baseder& baseder, LinkList<string>& ls);//
																	//���Ԫ�صĲ���
void testPushBack(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testEmplaceBack(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testPushFront(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testEmplaceFront(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testInsert(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void firstInsert(Baseder& baseder, LinkList<string>& ls);//��һ�ֲ��뷽ʽ
void secondInsert(Baseder& baseder, LinkList<string>& ls);//�ڶ��ֲ��뷽ʽ
void thirdInsert(Baseder& baseder, LinkList<string>& ls);//�ڶ��ֲ��뷽ʽ

void testEmplace(Menu& m3, Baseder& baseder, LinkList<string>& ls);

void delOpt(Menu& m2, Menu& m3, Baseder& baseder, LinkList<string>& ls);//
															//ɾ��Ԫ�صĲ���
void testPopBack(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testPopFront(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testClear(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testErase(Menu& m3, Baseder& baseder, LinkList<string>& ls);

void eraseFirst(Baseder& baseder, LinkList<string>& ls);//��һ��ɾ����ʽ
void eraseSecond(Baseder& baseder, LinkList<string>& ls); // �ڶ���ɾ����ʽ

void testEraseBack(Menu& m3, Baseder& baseder, LinkList<string>& ls);

void eraseBackFirst(Baseder& baseder, LinkList<string>& ls);//��һ��ɾ����ʽ
void eraseBackSecond(Baseder& baseder, LinkList<string>& ls); // �ڶ���ɾ����ʽ

void testRemove(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testRemoveIf(Menu& m3, Baseder& baseder, LinkList<string>& ls);

void findOpt(Menu& m2, Menu& m3, Baseder& baseder, LinkList<string>& ls);//
																	//����Ԫ�صĲ���
void testFind(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void findFirst(Baseder& baseder, LinkList<string>& ls);//��һ�ֲ��ҷ�ʽ
void findSecond(Baseder& baseder, LinkList<string>& ls); // �ڶ��ֲ��ҷ�ʽ

void testFindIf(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void findIfFirst(Baseder& baseder, LinkList<string>& ls);//��һ�ֲ��ҷ�ʽ
void findIfSecond(Baseder& baseder, LinkList<string>& ls); // �ڶ��ֲ��ҷ�ʽ

void replaceOpt(Menu& m2, Menu& m3, Baseder& baseder, LinkList<string>& ls);//
																	//�޸�Ԫ�صĲ���
void testReplace(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testReplaceIf(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testDealIf(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void dealIfFirst(Baseder& baseder, LinkList<string>& ls);//��һ�ִ���ʽ
void dealIfSecond(Baseder& baseder, LinkList<string>& ls); // �ڶ��ִ���ʽ
void dealIfThird(Baseder& baseder, LinkList<string>& ls); // �����ִ���ʽ

void testReserve(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testSwap(Menu& m3, Baseder& baseder, LinkList<string>& ls);

void elseOpt(Menu& m2, Menu& m3, Baseder& baseder, LinkList<string>& ls);//
																	//��������
void testData(Menu& m3, Baseder& baseder, LinkList<string>& ls);//�������ݽӿ�
void testSort(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testSortBy(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testUnique(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void testUniqueIf(Menu& m3, Baseder& baseder, LinkList<string>& ls);

void aboutSTL(Menu& m2, Menu& m3, Baseder& baseder, LinkList<string>& ls);//STL����
void testIterator(Menu& m3, Baseder& baseder, LinkList<string>& ls);

void testInserter(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void inserterBack(Baseder& baseder, LinkList<string>& ls);
void inserterFront(Baseder& baseder, LinkList<string>& ls);
void inserterDemo(Baseder& baseder, LinkList<string>& ls);

void testForEach(Menu& m3, Baseder& baseder, LinkList<string>& ls);

void testFill(Menu& m3, Baseder& baseder, LinkList<string>& ls);
void fillLs(Baseder& baseder, LinkList<string>& ls); // �ڶ��ִ���ʽ
void fillNLs(Baseder& baseder, LinkList<string>& ls); // �����ִ���ʽ


inline void setM2Title(Menu& m2) {//�ظ���������Ϊ����
	Label title(m2, 0, m2.getY() - 3, m2.getX());
	title.setText(title.getXH() - 4, 1, "��������", 0xf4);
	title.setBkColor(0xf4);
	title.setBorderLine();
	title.draw();
}

inline void setM3Title(Menu& m3) {//�ظ���������Ϊ����
	Label title(m3, 0, m3.getY() - 3, m3.getX());
	title.setText(title.getXH() - 4, 1, "������ʽ", 0xf4);
	title.setBkColor(0xf4);
	title.setBorderLine();
	title.draw();
}

inline void setTitle(Menu& m3,const char* str) {//�ظ���������Ϊ����
	Label title(m3, 0, m3.getY() - 3, m3.getX());
	title.setText(title.getXH() - 4, 1, str, 0xf4);
	title.setBkColor(0xf4);
	title.setBorderLine();
	title.draw();
}

inline void eatBuf() {//������뻺����
	while (cin.peek() != '\n') {
		cin.get();
	}
	cin.get();
}

#endif