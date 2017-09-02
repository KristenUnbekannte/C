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

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
const int size = 12;
int counter = 0;

struct Account
{
	int num_account;
	int id_account;
	char fio[15];
	int money;
	char date[10];
	int rate;
};
void push(Account *ac)
{
	cout << "\nInput account number: ";
	cin >> ac[counter].num_account;
	cout << "\nInput account id: ";
	cin >> ac[counter].id_account;
	cout << "\nInput lastname: ";
	cin >> ac[counter].fio;
	cout << "\nInput amount: ";
	cin >> ac[counter].money;
	cout << "\nInput date: ";
	cin >> ac[counter].date;
	cout << "\nInput interest rate: ";
	cin >> ac[counter].rate;
	++counter;
}
int lastname(Account *ac)
{
	cout << "\nChoose the client:\n";
	for (int i = 0; i < counter; ++i)
	{
		cout << i + 1 << ". " << ac[i].fio << endl;
	}
	int choose;
	cout << "Your choice :";
	cin >> choose;
	return choose - 1;
}
int account_number(Account *ac)
{
	cout << "\nChoose the account number:\n";
	for (int i = 0; i < counter; ++i)
	{
		cout << i + 1 << ". " << ac[i].num_account << endl;
	}
	int choose;
	cout << "Your choice :";
	cin >> choose;
	return choose - 1;
}
int account_id(Account *ac)
{
	cout << "\nChoose the account code:\n";
	for (int i = 0; i < counter; ++i)
	{
		cout << i + 1 << ". " << ac[i].id_account << endl;
	}
	int choose;
	cout << "Your choice :";
	cin >> choose;
	return choose - 1;
}
void add(Account *ac, int id)
{
	int quantity;
	cout << "\nInput amount you want to add? - ";
	cin >> quantity;
	ac[id].money += quantity;
	cout << "\nAmount on the account is " << ac[id].money << endl;
}
void decrease(Account *ac, int id)
{
	int quantity;
	cout << "\nInput amount you want to take away? -";
	cin >> quantity;
	if (quantity>ac[id].money)
		cout << "\nNot enough money on the account!\n";
	else
	{
		ac[id].money -= quantity;
		cout << "\nAmount on the account is " << ac[id].money << endl;
	}
}
void search(Account *ac, int id)
{
	cout << "\nAccount number: "<<ac[id].num_account;
	cout << "\nAccount id: " << ac[id].id_account;
	cout << "\nLastname: "<<ac[id].fio;
	cout << "\nAmount: "<<ac[id].money;
	cout << "\nDate: "<<ac[id].date;
	cout << "\nInterest rate: " << ac[id].rate;
}
void delete_inf(Account *ac, int id)
{
	for (int i = id; i < counter; ++i)
	{
		ac[i].num_account = ac[i+1].num_account;
		ac[i].id_account = ac[i + 1].id_account;
		strcpy(ac[i].fio,ac[i + 1].fio);
		ac[i].money = ac[i + 1].money;
		strcpy(ac[i].date,ac[i + 1].date);
		ac[i].rate = ac[i + 1].rate;
	}
	--counter;
}
void exchange(Account *ac, int i, int j)
{
	int temp;
	char str[15];

	temp = ac[j].num_account;
	ac[j].num_account = ac[i].num_account;
	ac[i].num_account = temp;

	temp = ac[j].id_account;
	ac[j].id_account = ac[i].id_account;
	ac[i].id_account = temp;

	strcpy(str, ac[j].fio);
	strcpy(ac[j].fio, ac[i].fio);
	strcpy(ac[i].fio, str);

	temp = ac[j].money;
	ac[j].money = ac[i].money;
	ac[i].money = temp;

	strcpy(str, ac[j].date);
	strcpy(ac[j].date, ac[i].date);
	strcpy(ac[i].date, str);

	temp = ac[j].rate;
	ac[j].rate = ac[i].rate;
	ac[i].rate = temp;
}
void sort_code(Account *ac)
{
	for (int i = 1; i < counter; ++i)
		for (int j = 0; j < i; ++j)
		{
			if (ac[j].id_account > ac[i].id_account)
				exchange(ac, i, j);
		}
}
void sort_owner(Account *ac)
{
	for (int i = 1; i < counter; ++i)
		for (int j = 0; j < i; ++j)
		{	
			if (strcmp(ac[j].fio, ac[i].fio) > 0)
				exchange(ac, i, j);
		}
}
void all(Account *ac)
{
	for (int i = 0; i < counter; ++i)
	{
		cout << i + 1 << ". account number: " << ac[i].num_account << ": id: " << ac[i].id_account << "; lastname:" << ac[i].fio << "; amount: " << ac[i].money << "; date: " << ac[i].date << "; rate: " << ac[i].rate<<endl;
	}
}
int main()
{
	setlocale(0, "");
	Account account[size];

	int choose;
	cout << "Choose the point of menu:\n\
	1.Add new client;\n\
	2.Add money to an account;\n\
	3.Debit money from an account;\n\
	4.Search by account number;\n\
	5.Search by account code;\n\
	6.Search by owner;\n\
	7.Sort by owner;\n\
	8.Sort by account code;\n\
	9.Delete information by owner;\n\
	10.Delete information account code;\n\
	11.All information;\n\
	12.Exit.\n\
  Your choice: ";
	cin >> choose;

	while (choose != 12)
	{
		int quan;
		int id;
		if (choose == 1)
		{
			cout << "\nHow much clients want you add? - ";
			cin >> quan;
			for (int i = 0; i < quan; ++i)
				push(&account[size]);
		}
		if (choose == 2)
		{
			id = lastname(&account[size]);
			add(&account[size], id);
		}
		if (choose == 3)
		{
			id = lastname(&account[size]);
			decrease(&account[size], id);
		}
		if (choose == 4)
		{
			id = account_number(&account[size]);
			search(&account[size], id);
		}
		if (choose == 5)
		{
			id = account_id(&account[size]);
			search(&account[size], id);
		}
		if (choose == 6)
		{
			id = lastname(&account[size]);
			search(&account[size], id);
		}
		if (choose == 7)
			sort_owner(&account[size]);

		if (choose == 8)
			sort_code(&account[size]);

		if (choose == 9)
		{
			id = lastname(&account[size]);
			delete_inf(&account[size], id);
		}
		if (choose == 10)
		{
			id = account_id(&account[size]);
			delete_inf(&account[size], id);
		}
		if (choose == 11)
			all(&account[size]);

		cout << "\nChoose the point of menu:\n\
	1.Add new client;\n\
	2.Add money to an account;\n\
	3.Debit money from an account;\n\
	4.Search by account number;\n\
	5.Search by account code;\n\
	6.Search by owner;\n\
	7.Sort by owner;\n\
	8.Sort by account code;\n\
	9.Delete information by owner;\n\
	10.Delete information account code;\n\
	11.All information;\n\
	12.Exit.\n\
  Your choice: ";
		cin >> choose;
	}
	exit;
	return 0;
}
