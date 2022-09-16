//������ͷ�ļ�
#pragma once
#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>//show�������õ�io��
#include "MyIterator.h"//�Զ��������
#include <initializer_list>//�б��ʼ������õ�
#include <stdexcept>//�������������ʱ�õ���out_of_range�쳣��
#include "Base.h"//�Զ���ͼ�ο�
//����ڵ�ṹ
template<class T>
struct Node
{
	T data;
	Node<T>* next;
	Node(const T& t) {//���캯��(���������ӽڵ���д�ظ�����)���ṹ��Ĭ��Ϊpublic,Ҳ��ֱ���Լ��������ݳ�Ա
		this->data = t;
		this->next = nullptr;
	}
};


template<class T> class MyIterator;//��������ǰ����(��������Ԫ��)

//����ʵ��
template <class T>
class LinkList {
	friend class MyIterator<T>;//����������Ϊ��Ԫ��
	Node<T>* head;//ͷ�ڵ�
	Node<T>* tail;//β�ڵ㣨nullǰһ���ڵ㣩
	int len;//����
public:
	using value_type = T;//ֵ����(���������㷺���㷨)
	using size_type = int;//��������(���������㷺���㷨)
	//������
	using iterator = MyIterator<T>;
	/*
	������˵��:
			�������ǹ����ָ�룬�ɶ�����������ָ��Ĳ���,��*iterator(������)��++iterator(����)��*iterator++=value(��iter
		atorָ���ֵ��Ϊvalue������һλ)��
			��������ο�MyIteator.hͷ�ļ����MyIterator<T>���operator(���������)��
			����ĵ�������Ҫ������ڵ�(��Node<T>* )���й���ʵ����һ�������������
	
	��Ƶ�������Ŀ��:
			�����������ı�̾��飬�Ҹ�����Ϊ������û�ֱ�Ӳ������ݳ�Ա�Ƿǳ�Σ�յ���Ϊ�����û���Ͻ���˼ά�ͷḻ�ľ��飬
		ֱ�Ӳ�������ڵ���ܻ���ֺܶ�������ص�������ܻ�ֱ���ƻ�����ṹ����ʹ�õ������Ͳ��õ���������⣬�������
		ʹ��ָ���������޸����ݣ��ǳ��������֣���������ȷ�������Ĳ��������ƻ����ݽṹ����Ȼ�Ҹ�����Ϊ����ƵĽӿ��Ѿ���
		ʵ��90%���ϵĲ�������ʱ��û�б���ʹ�õ��������޸����ݵ��������Ȼ��������⣬Ҳ����ʹ�õ������������ṩ�Ľӿڡ�
			ʹ�õ��������������ŵ�:����ʹ�ñ�׼���㷨����Ȼ������ʵ�ֵĵ������Ƚϼ�ª�������ǿ���ʹ�ò��ֱ�׼���㷨����
		���޷�ʹ�ã���Ҳ����ʹ�����ṩ����ӿڡ�
			�����������ʹ������ڵ�������Ѿ�ϰ��ʹ������ڵ�,��������ҲΪ���ṩ��getNode()�ӿڣ�����ֵΪ�õ����������
		����ڵ㡣

	�����������������:
			��ʽһ (ʹ��auto(c++11)�ؼ���):
						LinkList<int> ls(10,1);
						auto value=ls.begin();//auto�Զ��Ƴ�����
			��ʽ�� (���Ʊ�׼������,ʹ��LinkList<T>::iterator):
						LinkList<int> ls(10,1);
						LinkList<int>::iterator value=ls.begin();
			��ʽ�� (ֱ��ʹ��������MyIterator<T>):
						LinkList<int> ls(10,1);
						MyIterator<int> value=ls.begin();
	*/
	
	//���캯��
	LinkList() { head = tail = nullptr; len = 0; };//Ĭ�Ϲ��캯��
	LinkList(std::initializer_list<T> il);//{value1, value2, value3, ...}�б��ʼ��
	LinkList(const T& t);//��ֵ����
	LinkList(int num,const T& value);//num��value
	LinkList(int num,int&& value);//num��value (����TΪintʱ�����ض���,�ڶ���ֵʹ����ֵ����,��ֵ����������ƥ��˹��캯��)
	LinkList(const LinkList<T>& t);//���ƹ���
	LinkList(LinkList<T>&& t);//��ֵ���ù���,��������ӵ��Ȩ(����ڸ��ƹ������,ʱ��̶�)
	
	template <class It>
	LinkList(const It begin,const It end);//����������
	
	LinkList<T>& operator=(LinkList<T>& t);//��ֵ�����

	//�����������ͷ�����
	~LinkList();

	//STL������غ���(ʵ������ɾ���,�Լ�����������׼���㷨�Ľӿ�)
	/*
	���ں����������͵�˵��:
				�������������ֵ���Ǳ��������(����������������ls.clear().push_back(value).push_back(value)...)����Ϊ����
			��׼��ӿ����Ӧ��һЩ���������Ϊ���ص���������insert(iterator pos,const T& value)��������Ϊ������������ʹ��
			��׼���inserter������һЩ����ֵ��ʾλ�õĺ���( ����find(const T& value) )����ֵҲΪ��������
	*/
	int size() const{ return len; };//����
	LinkList<T>& push_back(const T& t);//���β�ڵ�
	LinkList<T>& emplace_back(std::initializer_list<T> ls);//�б�ֱ����ӵ�ͷ��
	LinkList<T>& push_front(const T& t);//���ͷ�ڵ�
	LinkList<T>& emplace_front(std::initializer_list<T> ls);//�б�ֱ����ӵ�β��
	LinkList<T>& pop_back();//ɾ��β�ڵ�
	LinkList<T>& pop_front();//ɾ��ͷ�ڵ�
	bool empty() const{ return !head; };//�ж��Ƿ�Ϊ��
	LinkList<T>& clear();//�������Ԫ��
	T& front() { return head->data; };//���ص�һ��Ԫ������
	T& back() { return tail->data; };//�������һ��Ԫ������
	const T& front() const{ return head->data; };//���ص�һ��Ԫ������
	const T& back() const{ return tail->data; };//�������һ��Ԫ������
	/*
	insert:		�����insert�����Ʊ�׼���������insert_back(Ŀ���ǽ�Լ�����������ǰһ���ڵ��ʱ��),�����insertʱ��̶�
	˵��:		������ʹ�ñ�׼���back_inserter,front_inserter,��ʹ��inserter��Ҫ�Լ�ע��:inserter�����Ԫ�ص�����λ��֮
			�󣬶���׼����������ӵ�����λ��֮ǰ��
	
	����inserter˵��:
				�����ǵ�������,��ӵ�����λ��֮ǰ��Ҫ��������,Ϊ�˽�ʡ����ʱ��,������Ƶ�insert���׼��������insert��ͬ:
			�˴���insert�����Ԫ�ص�����λ��֮��,�����Ҫ��ӵ�beginλ��֮ǰ,����ֱ��ʹ��inserter(ls,ls.begin())(ls��ʾ
			һ��LinkList<T>����)��������ʹ��push_front()����ӣ���Ȼinserter���λ�ò�ͬ������ȷ�����������������һϵ��
			Ԫ�ص�����λ��֮��
	
	����end():
				���ڵ�������ṹ�ľ����ԣ�insert���Ϊ����Ԫ�ص�����λ��֮������ʡ����ʱ��,���Ƕ�end()λ�þͲ�̫�Ѻ�,��Ҫ��
			β��ʹ��inserterʱ��һ����˵��Ҫʹ��end()ǰһ��λ�õĵ�������Ϊ�˸����ŵ�ʹ�ã�insert�㷨�͵��������ʱ��������
			����end()������ʹ��inserter��β������Ԫ��ʱ��ֱ��ʹ��end()����Ȼ��������⣬ʹ��begin()+(size()-1)Ҳ���ԣ�������
			���ʱȷ����++iterator��iterator++��������Խ�磨���� iterator+���� ����û��������!!!����
	*/
	iterator insert(const iterator& pos, const T& value);//value���뵽posλ�ú�
														 //���ر�ʾ����Ԫ��λ�õĵ�����(����inserter�����㷨�еĺ��Ʋ���)
	LinkList<T>& insert(const iterator& pos, int num, const T& value);//����num��value��pos��

	template <class It>
	LinkList<T>& insert(const iterator& pos,const It begin,const It end);//����������,���뵽posλ��֮��
	LinkList<T>& emplace(const iterator& pos, std::initializer_list<T> ls);//posλ�ú�ֱ���б����Ԫ��
	
	LinkList<T>& erase(iterator pos);//ɾ��posλ��Ԫ��,����ʱ��(�����posǰһ��Ԫ��)
	LinkList<T>& erase(iterator begin,iterator end);//ɾ��[begin,end)����Ԫ�أ�����ʱ��(�����beginǰһ��Ԫ��)
	LinkList<T>& erase_back(iterator pos);//ɾ��posλ�ú����һ��Ԫ��,�����erase��������ʱ�����,ֻ��̶�ʱ��
	LinkList<T>& erase_back(iterator begin,iterator end);//ɾ��[begin+1,end)����Ԫ��,
														 //�����erase��������ʱ����٣�ֻ��̶�ʱ��

	iterator find(const T& t);//����Ԫ��,û�ҵ�����end(),���Ϊend(),iterator��ת��Ϊfalse,�������Ϊtrue
	iterator find(const T& t, iterator pos);//��pos��ʼ����,û�ҵ�����end(),���Ϊend(),iterator��ת��Ϊfalse,�������Ϊtrue
	
	/*
	������˵��:
			����������F���ƿ�ͷ��ģ�屻����������ʹ��,��template<class F> iterator find_if(F f),����FΪһԪν�ʡ�
	nԪν��:
			����n��T���Ͳ����ķ���ֵΪbool���͵ĺ�����(����ָ��,lambda���ʽ,��������)������ǰ���find_if��f��Ϊ:[](const 
		int& value){return value>10;}���������TΪint���ͣ�,����find_if�������ҵ���һ���������10��Ԫ�����ڵĵ�������
			��:template<class Fj,class Fd> LinkList<T>& sort_by(F f),����fΪ��Ԫν�ʣ�����TΪstring�����bool deal(const
		string& value1,const string& value2){return value1.size()<value2.size();},�ɽ�deal����deal_if�Ĳ���,��ʱFΪbool (*)
		(const string&,const string&)���ͣ���һ����Ԫν�ʵĺ���ָ�����ͣ����˺�������deal_if�����ᰴ��string�ĳ���������
	*/

	template<class F>
	iterator find_if(F f);//FΪһԪν��(����һ��������bool���ͺ���),����Ϊture�ĵ�һ��Ԫ�صĵ�����,���򷵻�end()
	template<class F>
	iterator find_if(F f,iterator pos);//��posλ�ÿ�ʼ����
									//FΪһԪν��(����һ��������bool���ͺ���),����Ϊture�ĵ�һ��Ԫ�صĵ�����,���򷵻�end()

	template<class F>
	LinkList<T>& sort_by(F f);//��������fΪ��Ԫν��(����2��������bool���ͺ���),Ϊtrueʱ�ж�Ϊ��һ��Ԫ��С�ڵڶ���Ԫ��
	LinkList<T>& sort();//��������Ҫ��T������ operator< 
	
	template<class F>
	LinkList<T>& unique_if(F f);//fΪ��Ԫν��,Ϊtrueʱ�����ڶ���Ԫ��
	LinkList<T>& unique();//���������ظ�Ԫ�� (����ʱ��),һ����sort��unique�����������ظ�Ԫ��
	
	template<class F>
	LinkList<T>& remove_if(F f);//f��һ��һԪν��(����һ��������bool���ͺ���),Ϊtrueʱɾ����Ԫ��
	LinkList<T>& remove(const T& value);//ɾ������ֵΪvalue��Ԫ��,Ҫ��T������ operator==

	
	template<class Fj,class Fd>
	LinkList<T>& deal_if(Fj fj, Fd fd);//fj(һԪν��)Ϊtrueʱ�Ը�Ԫ�ؽ���fd(data)����
	template<class Fj,class Fd>
	LinkList<T>& deal_if(iterator begin, iterator end, Fj fj, Fd fd);//[begin,end)��Χ��fj(һԪν��)Ϊtrueʱ�Ը�Ԫ�ؽ���fd(data)����
	template<class Fj, class Fd>
	LinkList<T>& deal_if(iterator begin, Fj fj, Fd fd);//[begin,end())��Χ��fj(һԪν��)Ϊtrueʱ�Ը�Ԫ�ؽ���fd(data)����

	template<class F>
	LinkList<T>& replace_if(F f, const T& newValue);//fΪһԪν��,Ϊtrueʱ�滻��Ԫ��ΪnewValue
	LinkList<T>& replace(const T& oldValue, const T& newValue);//������oldValue�滻ΪnewValue

	//β��������ͷ������
	iterator begin() { return iterator(*this,0); };
	iterator end() { return iterator(nullptr, len); };

	LinkList<T> reserve(bool mode=false);//���ط�ת������(������Ӱ��),���modeΪtrue����Ӱ�챾��
	LinkList<T>& swap(LinkList<T>& ls);//��ls����,ֻ����ָ�룬ʱ��̶�
	//�ж�==
	bool operator==(const LinkList<T>& ls) {
		return head == ls.head;//ͷ�ڵ���ȼ����
	}

	//����(����ʱ��,index������ܻ�ȽϺ�ʱ)
	T& operator[](int index);//����,�����Խ����Ϊ
	const T& operator[](int index) const;//��������,�����Խ��
	T& at(int index);//���Խ����Ϊ,���Խ�磬���׳�һ���쳣����ֹ����
	const T& at(int index) const;//��������,���Խ����Ϊ�����Խ�磬���׳�һ���쳣����ֹ����

	//�������
	void show();//������չʾ
	int show(int with,Baseder& baseder,int y,int x);//����withʱ����
};

template<class T>
inline LinkList<T>::LinkList(std::initializer_list<T> il) 
{
	len = 0;
	head = tail = nullptr;
	for (auto p = il.begin(); p != il.end(); ++p) {
		push_back(*p);
	}
}

template<class T>
inline LinkList<T>::LinkList(const T& t)
{
	head = new Node<T>(t);
	len = 1;
	tail = head;
}

template<class T>
inline LinkList<T>::LinkList(int num,const T& value)
{
	len = 0;
	head = tail = nullptr;
	for (int i = 0; i < num; ++i) {
		push_back(value);
	}
}

template<class T>
inline LinkList<T>::LinkList(int num,int&& value)
{
	len = 0;
	head = tail = nullptr;
	for (int i = 0; i < num; ++i) {
		push_back(value);
	}
}

template<class T>
inline LinkList<T>::LinkList(const LinkList<T>& t)
{
	len = 0;//push_back������len
	head = tail = nullptr;
	for (Node<T>* i = t.head; i != nullptr; i = i->next) {
		push_back(i->data);
	}
}

template<class T>
inline LinkList<T>::LinkList(LinkList<T>&& t)
{
	head = t.head;
	tail = t.tail;
	len = t.len;
	t.head = t.tail = nullptr;
	t.len = 0;
}

template<class T>
inline LinkList<T>& LinkList<T>::operator=(LinkList<T>& t)
{
	if (t == *this) {
		return *this;//�Լ���ֵ�Լ�
	}
	clear();//���ͷ�
	for (Node<T>* i = t.head; i != nullptr; i = i->next) {
		push_back(i->data);
	}
	// TODO: �ڴ˴����� return ���
	return *this;
}


template<class T>
inline LinkList<T>::~LinkList()
{
	clear();
}

template<class T>
inline LinkList<T>& LinkList<T>::push_back(const T& t)
{
	++len;
	if (head == nullptr) {
		head = new Node<T>(t);
		tail = head;
	}
	else {
		tail->next = new Node<T>(t);
		tail = tail->next;
	}

	// TODO: �ڴ˴����� return ���
	return *this;
}

template<class T>
inline LinkList<T>& LinkList<T>::emplace_back(std::initializer_list<T> ls) {
	for (auto p = ls.begin(); p != ls.end(); ++p) {
		push_back(*p);
	}
	return *this;
}

template<class T>
inline LinkList<T>& LinkList<T>::push_front(const T& t)
{
	++len;
	Node<T>* p = new Node<T>(t);
	p->next = head;
	head = p;
	if (tail == nullptr) {
		//ֻ��һ���ڵ�
		tail = head;
	}

	// TODO: �ڴ˴����� return ���
	return *this;
}

template<class T>
inline LinkList<T>& LinkList<T>::emplace_front(std::initializer_list<T> ls) {
	for (auto p = ls.begin(); p != ls.end(); ++p) {
		push_front(*p);
	}
	return *this;
}

template<class T>
inline LinkList<T>& LinkList<T>::pop_back()
{
	if (empty()) {
		return *this;//Ϊ��ʱ
	}
	--len;
	Node<T>* p;
	for (p = head; p->next != tail&&p->next!=nullptr; p = p->next) {
		;//�����κβ���
	}
	if (head==tail) {//ֻ��һ���ڵ�
		delete head;
		head = tail = nullptr;
	}
	else if (p == head) {//�����ڵ�
		delete tail;
		head->next = nullptr;
		tail = head;
	}
	else {
		delete tail;
		p->next = nullptr;
		tail = p;
	}
	
	// TODO: �ڴ˴����� return ���
	return *this;
}
template<class T>
inline LinkList<T>& LinkList<T>::pop_front() {
	if (empty()) {
		return *this;
	}
	--len;
	if (len == 0) {
		delete head;
		head = tail = nullptr;
	}
	else {
		auto p = head;
		head = head->next;
		delete p;
	}
	return *this;
}

template<class T>
inline LinkList<T>& LinkList<T>::clear()
{
	Node<T>* p;
	Node<T>* t;
	for (p = head; p != nullptr;	) {
		t = p;
		p = p->next;
		delete t;
	}
	head = tail = nullptr;
	len = 0;

	// TODO: �ڴ˴����� return ���
	return *this;
}

template<class T>
inline MyIterator<T> LinkList<T>::insert(const iterator& pos, const T& value) {//���뵽pos����
	if (pos.p == nullptr) {
		push_back(value);
		return pos;
	}
	++len;
	Node<T>* later = pos.p->next;
	Node<T>* temp = new Node<T>(value);
	pos.p->next = temp;
	temp->next = later;
	return pos;
}

template<class T>
LinkList<T>& LinkList<T>::insert(const iterator& pos, int num, const T& value) {
	for (int i = 0; i < num; ++i) {
		insert(pos, value);
	}
	return *this;
}

template<class T>
template<class It>
inline LinkList<T>& LinkList<T>::insert(const iterator& pos,const It begin,const It end)
{
	if (pos.p == nullptr) {//β�ڵ�����
		for (auto p = begin; p != end; ++p) {
			push_back(*p);
		}
		return *this;
	}

	int i = 0;
	iterator temp = pos;
	for (auto p = begin; p != end; ++p) {
		insert(temp, *p);//�����len
		++temp;
	}
	// TODO: �ڴ˴����� return ���
	return *this;
}

template<class T>
LinkList<T>& LinkList<T>::emplace(const iterator& pos,std::initializer_list<T> ls) {
	insert(pos, ls.begin(), ls.end());
	return *this;
}

template<class T>
LinkList<T>& LinkList<T>::erase(iterator pos) {
	if (pos.p == nullptr||empty()) {
		return *this;
	}
	--len;
	//ͷ�ڵ�
	if (pos == begin()) {
		head = head->next;
		delete pos.p;
		pos.p = nullptr;
	}
	else {
		iterator itTemp = iterator(*this, pos.index - 1);
		(itTemp.p)->next = (pos.p)->next;
		delete pos.p;
		pos.p = nullptr;
	}
	return *this;
}

template<class T>
LinkList<T>& LinkList<T>::erase(iterator begin,iterator end) {
	for (int i = 0; i < end - begin; ++i) {
		erase(iterator(*this, begin.index));
	}
	return *this;
}

template<class T>
LinkList<T>& LinkList<T>::erase_back(iterator pos) {
	
	if (pos.p ==nullptr ) {//����endλ��,ֱ��return
		return *this;
	}
	iterator it = pos + 1;
	if (it.p == nullptr) {//ɾ��tail���null,ֱ��return
		return *this;
	}
	pos.p->next = it.p->next;
	delete it.p;
	--len;

	return *this;
}

template<class T>
LinkList<T>& LinkList<T>::erase_back(iterator begin,iterator end) {
	Node<T>* p = begin.p->next;
	Node<T>* t = p;
	begin.p->next = end.p;
	while(p!=end.p){
		t = p;
		p = p->next;
		--len;
		delete t;
	}

	return *this;
}

template<class T>
MyIterator<T> LinkList<T>::find(const T& t) {
	MyIterator<T> p = begin();
	for ( ; p.p!=nullptr&& * p != t; ++p) {
		;//����Ҫ�κβ���
	}
	return p;
}

template <class T>
MyIterator<T> LinkList<T>::find(const T& t, iterator pos) {
	for (; pos.p!=nullptr &&*pos != t; ++pos) {
		;//����Ҫ�κβ���
	}
	return pos;
}

template<class T>
template<class F>
MyIterator<T> LinkList<T>::find_if(F f) {
	MyIterator<T> p = begin();
	for (; p.p != nullptr && !f(*p); ++p) {
		;//����Ҫ�κβ���
	}
	return p;
}

template<class T>
template<class F>
MyIterator<T> LinkList<T>::find_if(F f, iterator pos) {
	for (; pos.p != nullptr && !f(*pos); ++pos) {
		;//����Ҫ�κβ���
	}
	return pos;
}

template<class T>
template<class F>
LinkList<T>& LinkList<T>::sort_by(F f) {
	for (int i = 1; i < len; ++i) {
		int j = 0;
		for (Node<T>* p2 = head; j < len - i; p2 = p2->next) {
			if ( f(p2->data,p2->next->data) ) {
				T t = p2->data;
				p2->data = p2->next->data;
				p2->next->data = t;
			}
			++j;
		}
	}

	return *this;
}

template<class T>
LinkList<T>& LinkList<T>::sort() {
	for (int i = 1; i < len;++i) {
		int j = 0;
		for (Node<T>* p2 = head; j<len-i ; p2 = p2->next) {
			if ((p2->next->data) < p2->data) {
				T t = p2->data;
				p2->data = p2->next->data;
				p2->next->data = t;
			}
			++j;
		}
	}

	return *this;
}

template<class T>
template<class F>
LinkList<T>& LinkList<T>::unique_if(F f) {
	int index = 0;
	if (empty()) {
		return *this;
	}
	for (Node<T>* p = head; p->next != nullptr; ) {
		if (f(p->data,p->next->data)) {
			erase_back(iterator(p, index));
			continue;
		}
		++index;
		p = p->next;
	}

	return *this;
}

template<class T>
LinkList<T>& LinkList<T>::unique() {
	int index = 0;
	if (empty()) {
		return *this;
	}
	for (Node<T>* p = head; p->next != nullptr; ) {
		if (p->data == p->next->data) {
			erase_back(iterator(p, index));
			continue;
		}
		++index;
		p = p->next;
	}
	
	return *this;
}

template<class T>
template<class F>
LinkList<T>& LinkList<T>::remove_if(F f) {
	int index = 0;
	while(head) {//head��Ϊnullptr
		if (f(head->data)) {
			pop_front();
		}
		else {
			break;
		}
	}
	if (empty()) {//������nullptr������������next�ǰ�ȫ��
		return *this;
	}
	for (Node<T>* p = head; p->next!= nullptr; ) {
		if (f(p->next->data)) {
			erase_back(iterator(p, index));
			continue;
		}
		++index;
		p = p->next;
	}
	return *this;
}

template<class T>
LinkList<T>& LinkList<T>::remove(const T& value) {
	int index = 0;
	while (head) {
		if (head->data == value) {
			pop_front();
		}
		else {
			break;
		}

	}
	if (empty()) {//������nullptr������������next�ǰ�ȫ��
		return *this;
	}
	for (Node<T>* p = head; p->next != nullptr; ) {
		if (p->next->data == value) {
			erase_back(iterator(p, index));
			continue;
		}
		++index;
		p = p->next;
	}
	return *this;
}

template<class T>
template<class Fj,class Fd>
LinkList<T>& LinkList<T>::deal_if(Fj fj,Fd fd) {
	for (iterator it = begin(); it != end(); ++it) {
		if (fj(*it)) {
			fd(*it);
		}
	}
	return *this;
}

template<class T>
template<class Fj, class Fd>
LinkList<T>& LinkList<T>::deal_if(iterator begin,iterator end,Fj fj, Fd fd) {
	for (iterator it = begin; it != end; ++it) {
		if (fj(*it)) {
			fd(*it);
		}
	}
	return *this;
}

template<class T>
template<class Fj, class Fd>
LinkList<T>& LinkList<T>::deal_if(iterator begin, Fj fj, Fd fd) {
	return deal_if(begin, end(), fj, fd);
}

template<class T>
template<class F>
LinkList<T>& LinkList<T>::replace_if(F f, const T& newValue) {
	for (iterator it = begin(); it != end(); ++it) {
		if (f(*it)) {
			*it = newValue;
		}
	}
	return *this;
}

template<class T>
LinkList<T>& LinkList<T>::replace(const T& oldValue, const T& newValue) {
	for (iterator it = begin(); it != end(); ++it) {
		if (*it == oldValue) {
			*it = newValue;
		}
	}
	return *this;
}

template<class T>
LinkList<T> LinkList<T>::reserve(bool mode) {
	LinkList<T> temp;
	for (Node<T>* p = head; p != nullptr; p = p->next) {
		temp.push_front(p->data);
	}
	if (mode) {
		*this = temp;
	}
	return temp;
}

template<class T>
LinkList<T>& LinkList<T>::swap(LinkList<T>& ls) {
	Node<T>* temp = this->head;
	this->head = ls.head;
	ls.head = temp;

	temp = this->tail;
	this->tail = ls.tail;
	ls.tail = temp;

	int t = this->len;
	this->len=ls.len;
	ls.len= t;

	return *this;
}

template<class T>
inline T& LinkList<T>::operator[](int index)
{
	Node<T>* p;
	int i = 0;
	for (p = head; i < index; ++i) {
		p = p->next;
	}
	// TODO: �ڴ˴����� return ���
	return p->data;
}

template<class T>
inline const T& LinkList<T>::operator[](int index) const
{
	Node<T>* p;
	int i = 0;
	for (p = head; i < index; ++i) {
		p = p->next;
	}
	// TODO: �ڴ˴����� return ���
	return const_cast<const T>(p->data);
}

template<class T>
inline T& LinkList<T>::at(int index)
{
	if (index >= len || index < 0) {
		throw std::out_of_range("atԽ��");
	}
	Node<T>* p;
	int i = 0;
	for (p = head; i < index; ++i) {
		p = p->next;
	}

	// TODO: �ڴ˴����� return ���
	return p->data;
}

template<class T>
inline const T& LinkList<T>::at(int index) const
{
	if (index >= len || index<0) {
		throw std::out_of_range("atԽ��");
	}
	Node<T>* p;
	int i = 0;
	for (p = head; i < index; ++i) {
		p = p->next;
	}

	// TODO: �ڴ˴����� return ���
	return const_cast<const T>(p->data);
}

template<class T>
inline void LinkList<T>::show()
{ 
	for (Node<T>* p = head; p != nullptr; p = p->next) {
		std::cout << p->data << ' ';
	}
	std::cout << std::endl;
}

template<class T>
template<class It>
inline LinkList<T>::LinkList(const It begin,const It end)
{
	len = 0;
	for (auto p = begin; p != end; ++p) {
		push_back(*p);
	}
}

template <class T>
inline int LinkList<T>::show(int with,Baseder& baseder,int y,int x) {
	using namespace std;
	baseder.gotoxy(y, x);
	std::cout << "(head)";
	int temp=with - 6;
	int col = 0;
	for (Node<T>* p = head; p != nullptr; p = p->next) {
		if (temp < 8) {
			baseder.gotoxy(++y, x);
			temp = with;
			++col;
			if (col >= 5) {
				cout << "...  ->";
				break;
			}
		}
		std::cout.width(6);
		std::cout <<left<< p->data;
		std::cout << "->";
		temp -= 8;
	}
	if (temp < 7 ) {
		baseder.gotoxy(++y, x);
	}
	std::cout << "nullptr" << std::endl;
	return y;
}
#endif