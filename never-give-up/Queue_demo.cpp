// Queue_demo.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Tqueue
{
	int date;
	Tqueue *next;
};

struct Qcount
{
	Tqueue *first;
	Tqueue *final;
};

Qcount qcount_init()
{
	Qcount *q1 = (Qcount *)malloc(sizeof(Qcount));
	if (q1 == NULL)
	{
		cout << "Count init false !" << endl;
		system("pause");
		exit(0);
	}
	q1->first = q1->final = NULL;
	return *q1;
}

void enqueue(Qcount *in, int date)
{
	Tqueue *q1 = (Tqueue *)malloc(sizeof(Tqueue));
	if (q1 == NULL)
	{
		cout << "enQueue falsed !" << endl;
	}
	q1->next = NULL;
	q1->date = date;
	if (in->first == NULL)
	{
		in->first = in->final = q1;
	}
	else
	{
		in->final->next = q1;
		in->final = q1;
	}
	return;
}

void dequeue(Qcount *in)
{
	int date;
	if (in->first == NULL)
	{
		cout << "Queue is empty !" << endl;
		return;
	}
	Tqueue *de = in->first;
	date = de->date;
	in->first = de->next;
	free(de);
	cout << "You just DeQueue date : " << date << endl;
	de->next = NULL;
}

void showalldate(Qcount *in)
{
	if (in->first == NULL)
	{
		cout << "Queue is empty !" << endl;
		return;
	}
	Tqueue *show = in->first;
	while (show->next != NULL)
	{
		cout << "| " << show->date << " ";
		show = show->next;
	}
	cout << "| " << show->date << " |" << endl;
	cout << " ↑" << endl;
	cout << " First" << endl;
	return;
}

int main()
{
	int date, choose;
	Qcount count = qcount_init();

	while (true)
	{
		cout << "1) enQueue date" << endl;
		cout << "2) deQueue date" << endl;
		cout << "3) show me all date" << endl;
		cout << "4) Exit" << endl;
		cout << "Please input your choose : ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Please input a date : ";
			cin >> date;
			enqueue(&count, date);
			continue;
		case 2:
			dequeue(&count);
			continue;
		case 3:
			showalldate(&count);
			continue;
		case 4:
			cout << "Wish you have a nice day !" << endl;
			system("pause");
			exit(0);
		default:
			continue;
		}
	}
	return 0;
}
