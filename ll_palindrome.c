#include <stdio>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;

void reverse(Node**);
bool compareList(Node *, Node *);

bool isPalindrome(Node *head)
{
	Node *slow_p = head, *fast_p = head;
	Node *second_half, *prev_of_slow_p = head;
	Node *midnode = NULL;
	bool res = true;
	if(head && head->next)
	{
		while(fast_p && fast_p->next)
		{
			prev_of_slow_p = slow_p;
			slow_p = slow_p->next;
			fast_p = fast_p->next->next;
		}

		if(fast_p)
		{
			midnode = slow_p;
			slow_p = slow_p->next;
		}

		second_half = slow_p;
		prev_of_slow_p->next = NULL;
		reverse(&second_half);
		res = compareList(head, second_half);
		reverse(&second_half);
		if(midnode)
		{
			prev_of_slow_p->next = midnode;
			midnode->next = second_half;
		}
		else
			prev_of_slow_p->next = second_half;
	}
	return res;
}