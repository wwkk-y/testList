//ͨѶ¼ʵ��

#ifndef MAILLIST_H
#define MAILLIST_H
#include <string>
#include <iostream>
#include "Base.h"
#include "LinkList.h"

class MailList {//ͨѶ¼
	struct data {
		string id;//ѧ��
		string name;//����
		string tel;//����
		string QQ;//QQ
		data(const char* str[]) :id(str[0]), name(str[1]), tel(str[2]), QQ(str[3]) {};
		data(const string& id, const string& name, const string& tel, const string& QQ) :id(id), name(name),
			tel(tel), QQ(QQ) {};
		data() {};
	};
	LinkList<data> ls;//�������ݵ�����
	Base& base;//�Զ��崰����(����ϸ����ο�Base.h�ļ�)
public:
	using data_type = data;

	MailList(Base& base,bool mode = true);//Ĭ�϶��󴴽�ʱ��ȡ�ļ�(mailList.txt),������Ϊѡ��falseѡ�񲻶�ȡ
	~MailList() { save(); };//������������save()

	MailList& save(const string& fileName="mailList.txt");//�������ݣ�Ĭ�ϱ��浽mailList.txt��Ҳ���Լ�����
	MailList& load(const string& fileName,Baseder& baseder,int& index);//���ļ��ж�ȡ����,��׷�ӵ���ʽ���
	MailList& show(Baseder& baseder, int& index);//չʾ����,��baseder����չʾ����
												  //Ĭ��չʾ��һҳ(index)������һ����̬��������¼һҳ��ʾ���ٸ�����
	MailList& addEle(Baseder& base,int& index);//���Ԫ��

	
	int getMaxIndex(int num) { return (ls.size() - 1) / num; };//����ҳ��
	int getIndex(int index, int num) { return index / num; }//��ǰ�±�ҳ��
	//���ж�ȡ����(׷��),������Ҫ�����ļ�,�ӿ���̨��ȡ���ݵ���������������,���Է���ֵ����Ϊvoid
	friend void operator>>(istream& is, MailList& ml);
	//�����ļ���os
	friend ostream& operator<<(ostream& os, MailList& ml);
	string inputFileName(Baseder& baseder);//����ֵΪ�û�������ļ���
	LinkList<data>::iterator find_by(Baseder& baseder,bool mode=true);//��ѯ

	MailList& insertEle(Baseder& baseder,int &index);//����Ԫ��
	MailList& delEle(Baseder& baseder, int& index);//ɾ��Ԫ��
	MailList& replaceEle(Baseder& baseder, int& index);//�޸�Ԫ��
	MailList& reserveEle(Baseder& baseder, int& index) {//��ת
		ls.reserve(true);
		show(baseder, index = 0);
		return *this;
	}
	MailList& sortAndUnique(Baseder& baseder, int& index);

	void start();//��ʼ��ʾ
};
#endif