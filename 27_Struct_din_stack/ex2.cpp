//Вычислить значение выражения записанного в постфиксной записи используя динамическую структуру данных стек
#include<iostream>
#include<cstring>
using namespace std;

struct LIFO
{
	double data;
	LIFO *ptr;
};
LIFO *push(LIFO *struc, double num)
{
	LIFO *cur = (LIFO*)malloc(sizeof(LIFO));
	cur->data = num;
	cur->ptr = struc;
	struc = cur;
	return struc;
}
double pop(LIFO **struc)
{
	double temp;
	LIFO *cur = *struc;
	if (*struc == NULL)
		return 0;
	temp = (*struc)->data;
	*struc = cur->ptr;
	free(cur);
	return temp;
}
int main()
{
	LIFO *lifo = NULL;

	char str[15];
	cout << "Input expression: ";
	cin >> str;

	int count = 0;
	while (str[count])
	{
		if (isdigit(str[count]))
			lifo = push(lifo, str[count] -'0');
		else
		{
			double a = pop(&lifo);
			double b = pop(&lifo);

			if (str[count] == '+')
				lifo = push(lifo, a+b);

			if (str[count] == '-')
				lifo = push(lifo, b-a);

			if (str[count] == '*')
				lifo = push(lifo, a*b);

			if (str[count] == '/')
				lifo = push(lifo, b/a);
		}
	++count;
	}
	cout << str << " = " << pop(&lifo) << endl;
	system("pause");
}
