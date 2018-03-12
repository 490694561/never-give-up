// never-give-up.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Qstack
{
	int date;
	Qstack *next;
};

int push(Qstack *in, int num)
{
	Qstack *q;
	q = (Qstack *)malloc(sizeof(Qstack));
	if (q == NULL)
	{
		cout << "Stack init falsed !" << endl;
		return 0;
	}
	q->next = NULL;
	q->date = num;
	q->next = in->next;
	in->next = q;
	return 1;
}

int pop(Qstack *in, int *num)
{
	Qstack *p = in->next;
	*num = p->date;
	in->next = p->next;
	cout << "You just pop a date : " << *num << endl;
	free(p);
	return 1;
}

void showstack(Qstack *in)
{
	Qstack *p = in->next;
	cout << "==================\t<-------The stack top" << endl;
	while (p != NULL)
	{
		cout << "||\t" << p->date << "\t||" << endl;
		p = p->next;
		cout << "==================" << endl;
	}
	p = NULL;
}

int main1()
{
	int choose, datenum, popdate;
	Qstack *in;
	in = (Qstack *)malloc(sizeof(Qstack));
	in->next = NULL;
	if (in == NULL) {
		cout << "Stack init falsed !" << endl;
		system("pause");
		return 0;
	}
	while (true)
	{
		cout << "1) Push date" << endl;
		cout << "2) Pop date" << endl;
		cout << "3) Show me all date" << endl;
		cout << "4) Exit" << endl;
		cout << "Please input your choose : ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Please input your date number : ";
			cin >> datenum;
			push(in, datenum);
			continue;
		case 2:
			if (in->next == NULL) {
				cout << "Stack have no date, please choose push !" << endl;
				continue;
			}
			pop(in, &popdate);
			continue;
		case 3:
			if (in->next == NULL) {
				cout << "Stack have no date, please choose push !" << endl;
				continue;
			}
			showstack(in);
			continue;
		case 4:
			cout << "This is a demo, wish you have a nice day !" << endl;
			system("pause");
			exit(0);
		default:
			continue;
		}
	}
    return 0;
}

