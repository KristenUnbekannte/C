/*1.	Счет в банке представляет собой структуру с полями:
•	номер счета, 
•	код счета, 
•	фамилия владельца, 
•	сумма на счете, 
•	дата открытия счета, 
•	годовой процент начисления.
 Реализовать поиск в массиве структур по номеру счета, по коду счета и по владельцу.
Реализовать сортировку по фамилии владельца и по номеру счета.
Реализовать удаление в массиве структур по коду счета и по владельцу.*/

#include<iostream>
#include <stdlib.h>
using namespace std;
const int size = 10;
int counter = 0;

struct Student
{
	char fio[12];
	int grup;
	int book;
	int mas[5];
};
void push_st(Student *st)
{
	cout << "\nInput students lastname: ";
	cin >> st[counter].fio;
	cout << "\nInput number of grupp: ";
	cin >> st[counter].grup;
	cout << "\nInput number of book: ";
	cin >> st[counter].book;
	++counter;
}
void push_m(Student *st, int quan, int id)
{
	int j;
	for (int i = 0; i < quan; ++i)
	{
		cout << "\nInput mark: ";
		cin >> j;
		st[id].mas[i]=j;
	}
}
int lastname(Student *st)
{
	cout << "\nChoose the student:\n";
	for (int i = 0; i < counter; ++i)
	{
		cout << i + 1 << ". " << st[i].fio << endl;
	}
	int choose;
	cout << "Your choice :";
	cin >> choose;
	return choose - 1;
}
double average(Student *st, int quan, int id)
{
	double av = 0;
	for (int i = 0; i < quan; ++i)
	{
		av += st[id].mas[i];
	}
	return av/quan;
}
double average_all(Student *st, int quan)
{
	double av = 0;
	for (int i = 0; i < counter;++i)
		for (int j = 0; j < quan; ++j)
			av += st[i].mas[j];
	return av / (quan*counter);
}
void all(Student *st,int quan)
{
	for (int c = 0; c < counter;++c)
		cout << st[c].fio << " " << st[c].grup << " " << st[c].book << " " << average(st, quan, c)<< endl;
}
void high_achiever(Student *st, int quan)
{
	for (int i = 0; i < counter; ++i)
	{
		int count = 0;
		for (int j = 0; j < quan; ++j)
		{
			if (st[i].mas[j] < 9)
			{
				count++; break;
			}
		}
		if (count == 0)
			cout << st[i].fio << endl;
	}
}
void debitors(Student *st, int quan)
{
	for (int i = 0; i < counter; ++i)
	{
		int count = 0;
		for (int j = 0; j < quan; ++j)
		{
			if (st[i].mas[j] < 4)
			{
				count++; break;
			}
		}
		if (count != 0)
			cout << st[i].fio << endl;
	}
}
int main()
{
	setlocale(0, " ");
	Student student[size];
	int choose=0;
	int quan;
	int id;

	while (choose != 8)
	{
		cout << "Choose the point of menu:\n\
	1.Add new student;\n\
	2.Add marks;\n\
	3.Total average score;\n\
	4.Average students score;\n\
	5.Total list;\n\
	6.High achiever;\n\
	7.Debtors;\n\
	8.Exit.\n\
  Your choice: ";
		cin >> choose;

		if (choose == 1)
		{
			cout << "\nHow much students want you add? - ";
			cin >> quan;
			for (int i = 0; i < quan;++i)
				push_st(&student[size]);
		}
		else if (choose == 2)
		{
			id = lastname(&student[size]);
			cout << "\nHow much marks want you add? - ";
			cin >> quan;
			push_m(&student[size], quan, id);
		}
		else if(choose == 3)
		{
			cout << "\nTotal averade score = " << average_all(&student[size], quan) << endl;
		}
		else if(choose == 4)
		{
			id = lastname(&student[size]);
			cout << "\nAverade score = "<< average(&student[size], quan, id) << endl;
		}
		else if(choose == 5)
		{
			all(&student[size], quan);
		}
		else if(choose == 6)
		{
			cout << "High achievers:\n";
			high_achiever(&student[size], quan);
		}
		else if(choose == 7)
		{
			cout << "Debitors:\n";
			debitors(&student[size], quan);
		}
	}
	return 0;
}
