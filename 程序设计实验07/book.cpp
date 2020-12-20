#include "book.h"
#include<string>
#include<iomanip>
#include<windows.h>
#include<algorithm>

long Book::BookId = 99999;

void Time::TimeShow()
{
	cout << "�������� " << this->year << "�� " << this->month << "�� " << this->day << "�� " << endl;
}

bool Time::Judge(int year1, int month1, int day1)
{
	bool flag1 = 0;//�ж����� 1�ǣ�0����
	bool flag2 = 0;//�ж������Ƿ���ȷ 1�� 0����
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
	bool flag = 1, flag1 = 0; //flag2�ж�һ���������
	do{
		if (flag1 == 1) cout << "����������ʵ�ʲ�������˶���Ϣ��" << endl << "����������(�� �� �գ�:" << endl;
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
		cout << "�Ը�ֵ����" << endl;
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
		cout << "�鼮��ţ�" << (*it).BookId_ << endl;
		cout << "�鼮���ƣ�" << (*it).BookName << endl;
		cout << "���ߣ�" << (*it).Writer << endl;
		cout << "�����磺" << (*it).BornPublish << endl;
		it->TimeShow();
		cout << "��������" << it->amount << endl;
		cout << "�鼮���ۣ�" << fixed << setprecision(2) << it->money << endl;
		cout << "----------------------------�����ķָ���----------------------------" << endl;
	}
	
}

void Book::Show1()
{
	cout << "�鼮��ţ�" << BookId_ << endl;
	cout << "�鼮���ƣ�" << BookName << endl;
	cout << "���ߣ�" << Writer << endl;
	cout << "�����磺" << BornPublish << endl;
	TimeShow();
	cout << "��������" << amount << endl;
	cout << "�鼮���ۣ�" << fixed << setprecision(2) << money << endl;
	cout << "----------------------------�����ķָ���----------------------------" << endl;
}

void Book::Add()
{
	Book LinshiBook;
	getchar();
	cout << "�������鼮���ƣ� ";
	getline(cin, LinshiBook.BookName);
	cout << "���������������� ";
	getline(cin, LinshiBook.Writer);
	cout << "���������������: ";
	getline(cin, LinshiBook.BornPublish);
	cout << "������������ڣ��꣬�£��գ�: ";
	LinshiBook.CinData();
	cout << "�鼮�۸�";
	cin >> LinshiBook.money;
	cout << "�����뵱ǰ������: ";
	cin >> LinshiBook.amount;
	Total_Book.push_back(LinshiBook);
	n = Total_Book.size();
	MySort();  //��ǰ�鼮����
	cout << "----------------------------��Ϣ����ɹ���----------------------------" << endl;
	
}

void Book::Revise()
{
	bool flag;
	int number;
	cout << "1.������        2.�鼮����        3.��������" << endl;
	cout << "4.������        5.��������        6.�鼮����  " << endl;
	cout << "7.���� " << endl;
	do{
		cout << "��ѡ��������Ҫ�޸ĵ�����(������ż��ɣ�" << endl;
		cin >> number;
		flag = 0;
		switch (number) {
		case 1: {
			cout << "�������޸ĵĲ�����: ";
			cin >> amount;
		}break;
		case 2: {
			cout << "�������޸ĵ��鼮����: ";
			getline(cin, BookName);
		}break;
		case 3: {
			cout << "�������޸ĵ���������: ";
			getline(cin, Writer);
		}break;
		case 4: {
			cout << "�������޸ĵĳ���������: ";
			getline(cin, BornPublish);
		}break;
		case 5: {
			cout << "�������޸ĵĳ������ڣ��꣬�£��գ�: ";
			CinData();
		}break;
		case 6: {
			cout << "�鼮����: ";
			cin >> money;
		}break;
		case 7: flag = 1; break;
		default: {
			cout << "�޷�ʶ�������������ʵ�иò�����" << endl;
		}break;
		}
		if (flag == 1) break;
	}while (!flag);
}

void Book::Delete()
{
	if (Total_Book.empty()) {
		cout << "�鼮�����鼮���ǰΪ0�������Ƿ��������" << endl;
		return;
	}
	cout << "ע���ò�����ͨ���鼮��Ž��У�" << endl;
	string str;
	bool flag2 = 0;   //�ж��Ƿ���ɾ����ǰ������鼮��ŷ�������
	while (flag2 == 0) {
		cout << "��������Ҫɾ�����鼮���" << endl;
		long Id;
		cin >> Id;
		bool flag = 0;
		typ it = Total_Book.begin();
		for (; it != Total_Book.end();) {
			if ((*it).GetId()==Id) {
				cout << "����Ҫɾ�����Ƿ�Ϊ�����鼮��" << endl;
				cout << "�鼮���: " << (*it).BookId_ << " " << "�鼮����: " << (*it).BookName << endl;
				cout << "��˶��Ƿ�ɾ������:(��:y  ��:n��" << endl;
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
			cout<<"�������������� 1������ɾ�������� 2"<<endl;
			int x;
			cin >> x;
			if (x == 2) flag2 = 0;
			continue;
		}
		else if (flag == 1 && flag2 == 0) cout << "�����ɹ�!" << endl;
		else if (flag2 == 0) cout << "���޴��飬��˶��鼮���" << endl;
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
			cout << "Ѱ�ҳɹ�" << endl;
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
	cout << "��ѡ���ѯ��ʽ('i':�鼮���   'n':�鼮����   ):" << endl;
	char way;
	cin >> way;
	if (way == 'i') {
		cout << "����������ѯ���鼮���:" << endl;
		long str1;
		cin >> str1;
		if (!Inquire_Way1(str1)) flag = 0;
	}
	else if (way == 'n') {
		cout << "����������ѯ���鼮����:" << endl;
		string str2;
		getchar();
		getline(cin, str2);
		if (!Inquire_Way2(str2)) flag = 0;
	}
	if (flag == 0) {
		cout << "���޴��飬��˶���Ϣ��" << endl;
	}
}

void Administrative::ReverseInformation()
{
	cout << "�����������û���: ";
	string name;
	getchar();
	getline(cin, name);
	header = name;
	string key1, key2;
	while (1) {
		cout << "�������µ�����: ";
		cin >> key1;
		if (key1.length() > 0 && key1.length() < 6 || key1.length() > 14) {
			printf("�������볤�ȣ������볤��6~14��\n");
			continue;
		}
		break;
	}
	while (1) {
		cout << "������һ�����룺";
		cin >> key2;
		if (key1 == key2) {
			key = key1;
			system("cls");
			printf("ע��ɹ���\n");
			break;
		}
		else {
			printf("����������������룺\n");
		}
	}
}

bool Setting(Administrative& s)
{
	cout << "����Ա�����֤��" << endl;
	cout << "��ʼ�û�����Dell                  ��ʼ���룺111111" << endl;
	while (1) {
		getchar();
		cout << "���������Ա�û���: ";
		string str;
		getline(cin, str);
		cout << "����������:";
		string key1;
		cin >> key1;
		if (str == s.GetHeader() && key1 == s.GetKey()) {
			cout << "�����֤�ɹ���������ת...." << endl;
			Sleep(1200);
			system("cls");
			return true;
		}
		else {
			cout << "�û������������! ����������!" << endl;
		}
	}
}

void Screen::menu1()
{
	cout << "��ӭ����ͼ�����ϵͳ����ѡ����Ҫ���еĲ�����" << endl;
	cout << "1.����Ա��¼" << endl;
	cout << "2.�˳�" << endl;
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
		cout << "����ǰ���ڹ���״̬��" << endl
			<< "�������²����ɽ���!" << endl
			<< "1.�˺���Ϣ�޸�" << endl
			<< "2.ͼ�����" << endl
			<< "3.�˳�" << endl
			<< "��ѡ�����Ĳ���:" << endl;
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
		cout << "                   ��ӭʹ�ñ�ϵͳ�� " << endl;
		cout << "          ��ϵͳ��ǰΪ���ṩ���в�����ף��ʹ�����! " << endl;
		while (1) {
			cout<< "                   1.�鼮����" << endl
				<< "                   2.�鼮Ŀ¼�޸�" << endl
				<< "                   3.�鼮����ɾ��" << endl
				<< "                   4.�鼮��Ϣ��ѯ" << endl
				<< "                   5.�鼮Ŀ¼���" << endl
				<< "                   6.�����˳�" << endl;
			cout << "��ѡ����Ҫ���еĲ�����";
			flag = 0;
			int x;
			cin >> x;
			switch (x) {
			case 1:Add(); break;
			case 2:{
				bool flag2;
				do {
					flag2 = 0;
					cout << "�������������в������鼮��ţ� ";
					long Id;
					cin >> Id;
					typ it = Total_Book.begin();
					for (; it != Total_Book.end(); it++) {
						if ((*it).GetId() == Id) {
							it->Revise();
							flag2 = 1;
						}
					}
					if (flag2 == 0) cout << "��Ϣ����ʧ�ܣ���˶���Ϣ���������룡" << endl;
					char c;
					cout << "������������������'n',������������'y' " << endl;
					cin >> c;
					if (c == 'n' || c == 'N') flag2 = 1;
				} while (!flag2);
			} break;
			case 3:Delete(); break;
			case 4:Inquire(); break;
			case 5:Show(); break;
			case 6: {flag = 1; system("cls"); } break;
			default:cout << "����ղ���Ŀ¼��" << endl; break;
			}
			if (flag == 1) break;
		}
		if (flag == 1) break;
	}
}