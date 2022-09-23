//�Զ��������
#ifndef MYITERATOR_H
#define MYITERATOR_H
#include "LinkList.h"
#include <iostream>

//��ǰ�����ṹ���������(����������Ԫ��)
template <class T> class LinkList;
template<class T> struct Node;

//���������(���������)
template<class T>
class MyIterator {
	friend class LinkList<T>;//����������Ϊ��Ԫ
	Node<T>* p;//��ǰ��ʾ�Ľڵ�
	int index;//��ǰ�ڵ������λ��
public:
	using value_type = T;//ֵ����,�����㷨�ӿ�
	//���캯��
	//����1:ʹ��index
	//(��Ҫ���㣬ʱ���index�йأ�Ϊ����ʱ��)
	MyIterator(LinkList<T>& ls, int index) {
		this->index = index;
		int i = 0;
		for (p = ls.head; i < index; ++i) {
			p = p->next;
		}
	};
private:
	//����2:Node<T>��indexֱ�ӹ���
	//(����Լʱ��,�ɱ�����������end()����̫��ʱ��,ʹ�õ�һ��������Ҫ��������ʱ�������Ե�)
	MyIterator(Node<T>* p, int index) :p(p), index(index) {};
public:
	//�������� - ������������
	int operator-(const MyIterator& it) const {
		return index - it.index;//��������������󶨵��ǲ�ͬ��LinkList���󣬸ò����Ľ����δ�����
	}
	

	//������ò���,ֵΪp->data
	T& operator*() {
		return this->p->data;
	};

	//++����
	//ǰ׺++
	MyIterator<T>& operator++() {
		if (this->p == nullptr) {//ȷ������Խ�磬����inserter�����㷨�ڽ�β����ʱ�ĺ���(++iterator)����
			return *this;
		}
		++index;
		p = p->next;
		return *this;
	};
	//��׺++
	MyIterator<T> operator++(int) {
		MyIterator<T> temp = *this;
		if (this->p == nullptr) {//ȷ������Խ�磬����inserter�����㷨�ڽ�β����ʱ�ĺ���(iterator++)����
			return temp;
		}
		this->index += 1;
		this->p = this->p->next;
		return temp;
	}

	//��������(���ܻ�Խ��,Խ��������δ�����)
	MyIterator<T>& operator+=(int num) {
		index += num;
		for (int i = 0; i < num; ++i) {
			p = p->next;
		}
		return *this;
	}
	MyIterator<T> operator+(int num) const{
		MyIterator<T> temp = *this;
		temp.index += num;
		for (int i = 0; i < num; ++i) {
			temp.p = temp.p->next;
		}
		return temp;
	}

	//�ж�
	//==
	bool operator==(const MyIterator<T>& it) const{
		return p == it.p;
	}
	//< 
	bool operator<(const MyIterator<T>& it) const {
		return  index < it.index;//��������������󶨵��ǲ�ͬ��LinkList���󣬸ò����Ľ����δ�����
	}
	//( >, >=, <, <= ����ͨ���������������ʵ��)
	// != 
	bool operator!=(const MyIterator<T>& it) const {
		return p != it.p;
	}
	
	//bool����ת��,pΪnullptrʱת��Ϊfalse,���������Ϊtrue
	explicit operator bool() const{ return p; };//����explicit�����Զ�ת��

	//���ݽӿ�
	int getIndex() { return index; };
	Node<T>* getNode() { return p; };


	//���
	friend std::ostream& operator<<(std::ostream& os, MyIterator<T> it) {
		using namespace std;
		if (!it) {
			cout << "data:nullptr  index:"<<it.getIndex();
		}
		else {
			cout <<"data:" << it.p->data << "  index:" << it.getIndex();
		}
		return os;
	}
};
#endif