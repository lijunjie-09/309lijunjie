#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;

class Time
{
public:
	Time() :year(0), month(0), day(0) {}
	void CinData();
	bool Judge(int year1, int month1, int day1);
	void TimeShow();
protected:
	int year;
	int month;
	int day;
};

class Book :protected Time
{
public:

	typedef vector<Book>::size_type tyb;
	typedef vector<Book>::iterator typ;
	static void MyAdd() { BookId++; }
	Book();
	void Show();
	void Show1();
	void Add();  //�鼮�ı�Ų����ظ���������Ҫ��
	void Revise();
	void Delete();
	void Inquire();  //��ѯ
	void MySort();
	long GetId();
	Book(const Book& Book_Fuzhi);  //���ƹ��캯��
	Book operator = (const Book& cp) ; //����=
	bool operator == (const Book& cp) const; //����==
	bool Inquire_Way1(long &Way_BookId);
	bool Inquire_Way2(string& Way_BookName);
	bool operator <(const Book cp) const {
		if (BookId == cp.BookId) {
			if (BookName == cp.BookName) return Writer < cp.Writer;
			return BookName < cp.BookName;
		}
		return BookId < cp.BookId;
	}
	
protected:
	static long BookId;
	long BookId_;
	string BookName;
	string Writer;
	string BornPublish;
	int amount;
	double money;
	vector<Book> Total_Book;
	tyb n;  //Total_Book�ĵ�ǰ����
};

class Administrative
{
public:
	friend bool Setting(Administrative& s);
	string GetHeader() { return header; }
	string GetKey() { return key; }
	Administrative() { key = "111111"; header = "Dell"; }
	void ReverseInformation();
protected:
	string key;  //����
	string header;
};


class Screen:protected Administrative,protected Book
{
public:
	void menu1(); //��¼
	void menu2(Administrative& s); //����Ա
	void menu3(); //ͼ��
};