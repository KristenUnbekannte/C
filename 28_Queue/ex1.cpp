#include<iostream>
#include<ctime>
using namespace std;
const int size1 = 5;
const int size2 = 10;

struct Node
{
	int data;
	Node *next;
};
struct FIFO
{
	Node *head;
	Node *tail;
};
void init(FIFO *q)
{
	q->head = NULL;
	q->tail = NULL;
}
void push(FIFO *q, int value)
{
	Node *cur = (Node*)malloc(sizeof(Node));
	cur->data = value;
	cout << value << " ";
	cur->next = NULL;

	if (q->tail)
		q->tail->next = cur;

	q->tail = cur;
	if (q->head == NULL)
		q->head = q->tail;
}
int pop(FIFO *q)
{
	if (q->head == NULL)
		return 0;
	Node *cur = q->head;
	int temp = q->head->data;
	q->head = cur->next;
	free(cur);
	return temp;
}
int main()
{
	srand((unsigned)time(0));
	FIFO q1,q2,q3;
	init(&q1);
	init(&q2);
	init(&q3);
	for (int i = 0; i < size1; ++i)
		push(&q1, rand() % 9);
	cout << endl;

	for (int i = 0; i < size2; ++i)
		push(&q2, rand() % 9);
	cout << endl;

	for (int i = 0; i < size1; ++i)
	{
		push(&q3, pop(&q1) + pop(&q2));
		pop(&q3);
	}
	cout << endl;
	return 0;
}
