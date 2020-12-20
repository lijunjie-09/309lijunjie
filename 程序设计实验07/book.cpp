#include "book.h"
#include<string>
#include<iomanip>
#include<windows.h>
#include<algorithm>

long Book::BookId = 99999;

void Time::TimeShow()
{
	cout << "出版日期 " << this->year << "年 " << this->month << "月 " << this->day << "日 " << endl;
}

bool Time::Judge(int year1, int month1, int day1)
{
	bool flag1 = 0;//判断闰年 1是，0不是
	bool flag2 = 0;//判断天数是否正确 1是 0不是
	if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0) flag1 = 1;
	if (month1 >= 1 && month1 <= 12) {
		switch (month1) {
		case 1:if (day1 >= 1 && day1 <= 31) flag2 = 1; break;
		case 2: {
			if (flag1 == 1 && (day1 >= 1 && day1 <= 29)) flag2 = 1;
			else if (flag1 == 0 && (day1 >= 1 && day1 <= 28))flag2 = 1;
		}break;
		case 3:if (day1 >= 1 && day1 <= 31) flag2 = 1; break;
		case 4:if (day1 >= 1 && day1 <= 30) flag2 = 1; break;
		case 5:if (day1 >= 1 && day1 <= 31) flag2 = 1; break;
		case 6:if (day1 >= 1 && day1 <= 30) flag2 = 1; break;
		case 7:if (day1 >= 1 && day1 <= 31) flag2 = 1; break;
		case 8:if (day1 >= 1 && day1 <= 31) flag2 = 1; break;
		case 9:if (day1 >= 1 && day1 <= 30) flag2 = 1; break;
		case 10:if (day1 >= 1 && day1 <= 31) flag2 = 1; break;
		case 11:if (day1 >= 1 && day1 <= 30) flag2 = 1; break;
		case 12:if (day1 >= 1 && day1 <= 31) flag2 = 1; break;
		}
		if (flag2 == 1) return true;
		else return false;
	}
	else return false;
}

void Time::CinData()
{
	bool flag = 1, flag1 = 0; //flag2判断一次语句输入
	do{
		if (flag1 == 1) cout << "您的输入有实际不符，请核对信息！" << endl << "请重新输入(年 月 日）:" << endl;
		cin >> year >> month >> day;
		if (Judge(year, month, day)) { flag = 0; flag1 = 0; return; }
		else {
			flag1 = 1;
			flag = 1;
		}
	}while (flag);
}

Book::Book():amount(0)
{
	MyAdd();
	BookId_ = BookId;
}

long Book::GetId()
{
	return BookId_;
}

void Book::MySort()
{
	sort(Total_Book.begin(), Total_Book.end());
}

bool Book::operator == (const Book& cp) const
{
	if ((*this).BookId_ == cp.BookId_) return true;
	return false;
}

Book Book::operator = (const Book& cp)
{
	if ((*this) == cp) {
		cout << "自赋值错误！" << endl;
		return (*this);
	}
	Book linshi;
	linshi.amount = cp.amount;
	linshi.BookId = cp.BookId_;
	linshi.BookName = cp.BookName;
	linshi.BornPublish = cp.BornPublish;
	linshi.Writer = cp.Writer;
	linshi.year = cp.year;
	linshi.day = cp.day;
	linshi.month = cp.month;
	linshi.money = cp.money;
	linshi.n = cp.n;
	return linshi;
}

Book::Book(const Book& Book_Fuzhi)
{
	this->amount = Book_Fuzhi.amount;
	this->money = Book_Fuzhi.money;
	this->BookId_ = Book_Fuzhi.BookId_;
	this->BookName = Book_Fuzhi.BookName;
	this->BornPublish = Book_Fuzhi.BornPublish;
	this->year = Book_Fuzhi.year;
	this->month = Book_Fuzhi.month;
	this->day = Book_Fuzhi.day;
	this->Writer = Book_Fuzhi.Writer;
	this->n = Book_Fuzhi.n;
}

void Book::Show()
{
	typ it = Total_Book.begin();
	for (; it != Total_Book.end(); it++) {
		cout << "书籍编号：" << (*it).BookId_ << endl;
		cout << "书籍名称：" << (*it).BookName << endl;
		cout << "作者：" << (*it).Writer << endl;
		cout << "出版社：" << (*it).BornPublish << endl;
		it->TimeShow();
		cout << "藏书量：" << it->amount << endl;
		cout << "书籍单价：" << fixed << setprecision(2) << it->money << endl;
		cout << "----------------------------华丽的分割线----------------------------" << endl;
	}
	
}

void Book::Show1()
{
	cout << "书籍编号：" << BookId_ << endl;
	cout << "书籍名称：" << BookName << endl;
	cout << "作者：" << Writer << endl;
	cout << "出版社：" << BornPublish << endl;
	TimeShow();
	cout << "藏书量：" << amount << endl;
	cout << "书籍单价：" << fixed << setprecision(2) << money << endl;
	cout << "----------------------------华丽的分割线----------------------------" << endl;
}

void Book::Add()
{
	Book LinshiBook;
	getchar();
	cout << "请输入书籍名称： ";
	getline(cin, LinshiBook.BookName);
	cout << "请输入作者姓名： ";
	getline(cin, LinshiBook.Writer);
	cout << "请输入出版社名称: ";
	getline(cin, LinshiBook.BornPublish);
	cout << "请输入出版日期（年，月，日）: ";
	LinshiBook.CinData();
	cout << "书籍价格：";
	cin >> LinshiBook.money;
	cout << "请输入当前藏书量: ";
	cin >> LinshiBook.amount;
	Total_Book.push_back(LinshiBook);
	n = Total_Book.size();
	MySort();  //当前书籍排序
	cout << "----------------------------信息载入成功！----------------------------" << endl;
	
}

void Book::Revise()
{
	bool flag;
	int number;
	cout << "1.藏书量        2.书籍名称        3.作者姓名" << endl;
	cout << "4.出版社        5.出版日期        6.书籍单价  " << endl;
	cout << "7.返回 " << endl;
	do{
		cout << "请选择你所需要修改的内容(输入序号即可）" << endl;
		cin >> number;
		flag = 0;
		switch (number) {
		case 1: {
			cout << "请输入修改的藏书量: ";
			cin >> amount;
		}break;
		case 2: {
			cout << "请输入修改的书籍名称: ";
			getline(cin, BookName);
		}break;
		case 3: {
			cout << "请输入修改的作者姓名: ";
			getline(cin, Writer);
		}break;
		case 4: {
			cout << "请输入修改的出版社名称: ";
			getline(cin, BornPublish);
		}break;
		case 5: {
			cout << "请输入修改的出版日期（年，月，日）: ";
			CinData();
		}break;
		case 6: {
			cout << "书籍单价: ";
			cin >> money;
		}break;
		case 7: flag = 1; break;
		default: {
			cout << "无法识别操作，请重新实行该操作！" << endl;
		}break;
		}
		if (flag == 1) break;
	}while (!flag);
}

void Book::Delete()
{
	if (Total_Book.empty()) {
		cout << "书籍库内书籍类别当前为0，请检查是否操作错误！" << endl;
		return;
	}
	cout << "注：该操作仅通过书籍编号进行！" << endl;
	string str;
	bool flag2 = 0;   //判断是否多次删除或当前输入的书籍编号发生错误
	while (flag2 == 0) {
		cout << "输入你所要删除的书籍编号" << endl;
		long Id;
		cin >> Id;
		bool flag = 0;
		typ it = Total_Book.begin();
		for (; it != Total_Book.end();) {
			if ((*it).GetId()==Id) {
				cout << "您所要删除的是否为下列书籍：" << endl;
				cout << "书籍编号: " << (*it).BookId_ << " " << "书籍名称: " << (*it).BookName << endl;
				cout << "请核对是否删除此书:(是:y  否:n）" << endl;
				char c;
				cin >> c;
				if (c == 'y' || c == 'Y') {
					Total_Book.erase(it++);
					n--;
					flag = 1;
					break;
				}
				else {
					flag2 = 1;
					break;
				}
			}
			else ++it;
		}
		if (flag2 == 1){
			cout<<"结束操作请输入 1，重新删除请输入 2"<<endl;
			int x;
			cin >> x;
			if (x == 2) flag2 = 0;
			continue;
		}
		else if (flag == 1 && flag2 == 0) cout << "操作成功!" << endl;
		else if (flag2 == 0) cout << "查无此书，请核对书籍编号" << endl;
		break;
	}
}

bool Book::Inquire_Way1(long & Way_Book)
{
	bool flag = 0;
	typ it = Total_Book.begin();
	for (; it != Total_Book.end(); ++it) {
		if (it->GetId() == Way_Book) {
			it->Show1();
			cout << "寻找成功" << endl;
			flag = 1;
			break;
		}
	}
	return flag;
}

bool Book::Inquire_Way2(string& Way_Book)
{
	bool flag = 0;
	typ it = Total_Book.begin();
	for (; it != Total_Book.end(); ++it) {
		if ((*it).BookName == Way_Book) {
			it->Show1();
			flag = 1;
		}
	}
	return flag;
}

void Book::Inquire()
{
	bool flag = 1;
	cout << "请选择查询方式('i':书籍编号   'n':书籍名称   ):" << endl;
	char way;
	cin >> way;
	if (way == 'i') {
		cout << "请输入所查询的书籍编号:" << endl;
		long str1;
		cin >> str1;
		if (!Inquire_Way1(str1)) flag = 0;
	}
	else if (way == 'n') {
		cout << "请输入所查询的书籍名称:" << endl;
		string str2;
		getchar();
		getline(cin, str2);
		if (!Inquire_Way2(str2)) flag = 0;
	}
	if (flag == 0) {
		cout << "查无此书，请核对信息！" << endl;
	}
}

void Administrative::ReverseInformation()
{
	cout << "请输入您的用户名: ";
	string name;
	getchar();
	getline(cin, name);
	header = name;
	string key1, key2;
	while (1) {
		cout << "请输入新的密码: ";
		cin >> key1;
		if (key1.length() > 0 && key1.length() < 6 || key1.length() > 14) {
			printf("请检查密码长度！（密码长度6~14）\n");
			continue;
		}
		break;
	}
	while (1) {
		cout << "请再输一遍密码：";
		cin >> key2;
		if (key1 == key2) {
			key = key1;
			system("cls");
			printf("注册成功！\n");
			break;
		}
		else {
			printf("密码错误！请重新输入：\n");
		}
	}
}

bool Setting(Administrative& s)
{
	cout << "管理员身份验证！" << endl;
	cout << "初始用户名：Dell                  初始密码：111111" << endl;
	while (1) {
		getchar();
		cout << "请输入管理员用户名: ";
		string str;
		getline(cin, str);
		cout << "请输入密码:";
		string key1;
		cin >> key1;
		if (str == s.GetHeader() && key1 == s.GetKey()) {
			cout << "身份认证成功！正在跳转...." << endl;
			Sleep(1200);
			system("cls");
			return true;
		}
		else {
			cout << "用户名或密码错误! 请重新输入!" << endl;
		}
	}
}

void Screen::menu1()
{
	cout << "欢迎进入图书管理系统，请选择您要进行的操作！" << endl;
	cout << "1.管理员登录" << endl;
	cout << "2.退出" << endl;
	int number;
	cin >> number;
	if (number == 1) {
		Administrative s;
		if (Setting(s)) {
			menu2(s);
		}
	}
	else {
		return;
	}
}

void Screen::menu2(Administrative& s)
{
	while (1) {
		cout << "您当前处于管理状态！" << endl
			<< "您有以下操作可进行!" << endl
			<< "1.账号信息修改" << endl
			<< "2.图书管理" << endl
			<< "3.退出" << endl
			<< "请选择您的操作:" << endl;
		int number;
		cin >> number;
		if (number == 1) {
			s.ReverseInformation();
		}
		else if (number == 2) {
			menu3();
		}
		else {
			return;
		}
	}
}

void Screen::menu3()
{
	bool flag = 0;
	while (1) {
		cout << "                   欢迎使用本系统！ " << endl;
		cout << "          本系统当前为你提供下列操作，祝你使用愉快! " << endl;
		while (1) {
			cout<< "                   1.书籍导入" << endl
				<< "                   2.书籍目录修改" << endl
				<< "                   3.书籍整理删除" << endl
				<< "                   4.书籍信息查询" << endl
				<< "                   5.书籍目录浏览" << endl
				<< "                   6.程序退出" << endl;
			cout << "请选择您要进行的操作：";
			flag = 0;
			int x;
			cin >> x;
			switch (x) {
			case 1:Add(); break;
			case 2:{
				bool flag2;
				do {
					flag2 = 0;
					cout << "请输入你所进行操作的书籍编号： ";
					long Id;
					cin >> Id;
					typ it = Total_Book.begin();
					for (; it != Total_Book.end(); it++) {
						if ((*it).GetId() == Id) {
							it->Revise();
							flag2 = 1;
						}
					}
					if (flag2 == 0) cout << "信息查找失败，请核对信息后重新输入！" << endl;
					char c;
					cout << "若放弃操作，请输入'n',继续操作输入'y' " << endl;
					cin >> c;
					if (c == 'n' || c == 'N') flag2 = 1;
				} while (!flag2);
			} break;
			case 3:Delete(); break;
			case 4:Inquire(); break;
			case 5:Show(); break;
			case 6: {flag = 1; system("cls"); } break;
			default:cout << "请参照操作目录！" << endl; break;
			}
			if (flag == 1) break;
		}
		if (flag == 1) break;
	}
}