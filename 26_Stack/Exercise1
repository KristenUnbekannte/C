//Проверка правильности скобок => (,{,[

#include <iostream>
#include <cstring>
using namespace std;

const int size = 20;
struct LIFO
{
	char arr[size];
	int top;
};
void push(LIFO *lifo, char ch)
{
	if (lifo->top == size){//если указатель, то обращаемся через ->  если обычная переменная то через точку.
		cout << "Stack is overflow";
		return;
	}
	lifo->arr[lifo->top++] = ch;
}
char pop(LIFO *lifo)
{
	if (lifo->top == 0){
		cout << "Stack is empty";
		return 0;
	}
	return lifo->arr[--lifo->top];
}

int main()
{
	LIFO lifo;
	lifo.top = 0;

	char ch[20];
	cin >> ch;

	int i = 0, count = 0;
	if (strlen(ch) % 2 == 0)
	{
		while (ch[i])
		{

			if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[') push(&lifo, ch[i]);
			else
			{
				if (lifo.top == 0){ count++; break; }
				else if (ch[i] == ']')
				{
					if ('[' != pop(&lifo)) { count++; break; }
				}
				else if (ch[i] == ')')
				{
					if ('(' != pop(&lifo)) { count++; break; }
				}
				else if (ch[i] == '}')
				{
					if ('{' != pop(&lifo)) { count++; break; }
				}
			}
			i++;
		}
		if (count == 0 && lifo.top == 0) cout << "True\n";
		else cout << "False\n";
	}
	else cout << "False!\n";

	cout << endl;
	system("pause");
	return 0;
}
