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
	void Add();  //书籍的编号不可重复，其余无要求
	void Revise();
	void Delete();
	void Inquire();  //查询
	void MySort();
	long GetId();
	Book(const Book& Book_Fuzhi);  //复制构造函数
	Book operator = (const Book& cp) ; //重载=
	bool operator == (const Book& cp) const; //重载==
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
	tyb n;  //Total_Book的当前数量
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
	string key;  //密码
	string header;
};


class Screen:protected Administrative,protected Book
{
public:
	void menu1(); //登录
	void menu2(Administrative& s); //管理员
	void menu3(); //图书
};