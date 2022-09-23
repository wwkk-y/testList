//�洢��ҵ��
#ifndef DEPOSIT_H
#define DEPOSIT_H
#pragma once
#include <string>
#include "LinkList.h"
#include "Base.h"
#include <iostream>

using namespace std;
class depositBusiness
{
	struct data {
		string name;//����
		string opt;//���� +��ͷ����,-��ͷȡ��,' '��ͷ��ʾ����
		string date;//����,��̬��ȡ����ʱ��,Ϊnone�����,��ʾ����
		string balan;//���
		data(string name, string opt, string date,string banlan) :name(name), opt(opt), date(date),balan(banlan) {};
		data() {};
	};
	LinkList<data> ls;//�������ݵ�����
	Base& base;//�Զ��崰����(����ϸ����ο�Base.h�ļ�)
public:
	using data_type = data;

	depositBusiness(Base& base, bool mode = true);//Ĭ�϶��󴴽�ʱ��ȡ�ļ�(depositBusiness.txt),������Ϊѡ��falseѡ�񲻶�ȡ
	~depositBusiness() { save(); };//������������save()

	depositBusiness& save(const string& fileName="depositBusiness.txt");//�����ļ�
	depositBusiness& read(const string& fileName="depositBusiness.txt");//��ȡ�ļ�

	//���ж�ȡ����(׷��),������Ҫ�����ļ�,�ӿ���̨��ȡ���ݵ���������������,���Է���ֵ����Ϊvoid
	friend void operator>>(istream& is, depositBusiness& ml);
	//�����ļ���os
	friend ostream& operator<<(ostream& os, depositBusiness& ml);

	int show(string& name, int& index);
	depositBusiness& findOpt(string& name);
	depositBusiness& addOpt(string& name);
	depositBusiness& takeOpt(string& name);
	data getLast(string& name);

	depositBusiness& login(string name);
	string getDate();//ʱ��
	string getName();
	void addUser();
	void start();//���
};

inline void operator>>(istream& is, depositBusiness& ml)
{
	string name;
	string opt;
	string date;
	string banlan;
	while (is >> name >> opt >> date>>banlan) {
		ml.ls.push_back(depositBusiness::data(name, opt, date,banlan));
	}
}

inline ostream& operator<<(ostream& os, depositBusiness& ml)
{
	for (auto& p : ml.ls) {
		os << p.name << "  " << p.opt << "  " << p.date <<"  "<<p.balan << endl;
	}
	return os;
}

#endif