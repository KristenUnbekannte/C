#include<iostream>
#include<cstring>
using namespace std;

const int size = 40;

struct LIFO
{
	char stack[size];
	int top;
};
void push(LIFO *st, char h)
{
	if (st->top == size)
	{
		cout << "Stack is overflow."<<endl;
		return;
	}
	st->stack[st->top++] = h;
}
char pop(LIFO *st)
{
	if (st->top == 0)
	{
		cout << "Stack is empty."<<endl;
		return 0;
	}
	return st->stack[--st->top];
}
int maxs(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}
int mins(int a, int b)
{
	if (a < b)
		return a;
	else return b;
}
int main()
{
	LIFO lifo;
	lifo.top = 0;
	char str[size];
	char str1[3];

	cout << "Input the expression: ";
	cin >> str;

	int count = 0;
	while (str[count])
	{
		if (str[count] == 'a' || str[count] == 'i' || isdigit(str[count]))
			push(&lifo, str[count]);
		else if (str[count] == ')')
		{
			for (int i = 0; i < 3; ++i)
				str1[i] = pop(&lifo);
			if (str1[2] == 'a')
			{
				push(&lifo, maxs(str1[0],str1[1]));
			}
			else if (str1[2] == 'i')
				push(&lifo, mins(str1[0], str1[1]));

		}
		count++;
	}
	cout << endl;
	cout << str << " = " << pop(&lifo) << endl;
	system("pause");
}