#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

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
	cout << "Choose the student:\n";
	for (int i = 0; i < counter; ++i)
	{
		cout << i + 1 << ". " << st[i].fio << endl;
	}
	int choose;
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
int main()
{
	Student student[size];
	int choose;
	cout << "Choose the point of menu:\n\
	1.Add new student;\n\
	2.Add marks;\n\
	3.Overall average score;\n\
	4.Average students score;\n\
	5.Total list;\n\
	6.High achiever;\n\
	7.Debtors;\n\
	8.Exit.\n";

	cin >> choose;

	while (choose != 8)
	{
		int quan;
		int id;
		if (choose == 1)
		{
			cout << "How much students want you add? - ";
			cin >> quan;
			for (int i = 0; i < quan;++i)
				push_st(&student[size]);
		}
		if (choose == 2)
		{
			id = lastname(&student[size]);
			cout << "How much marks want you add? - ";
			cin >> quan;
			push_m(&student[size], quan, id);
		}
		if (choose == 3)
		{
			cout << "\nTotal averade score = " << average_all(&student[size], quan) << endl;
		}
		if (choose == 4)
		{
			id = lastname(&student[size]);
			cout << "\nAverade score " << student[0].fio <<" = "<< average(&student[size], quan, id) << endl;
		}
		if (choose == 5)
		{
			all(&student[size], quan);
		}
		if (choose == 6)
		{
			all(&student[size], quan);
		}
		if (choose == 7)
		{
			all(&student[size], quan);
		}
		cout << "Choose the point of menu:\n\
		1.Add new student;\n\
		2.Add marks;\n\
		3.Total average score;\n\
		4.Average students score;\n\
		5.Total list;\n\
		6.High achiever;\n\
		7.Debtors;\n\
		8.Exit.\n";

		cin >> choose;
	}
	exit;
	return 0;
}
