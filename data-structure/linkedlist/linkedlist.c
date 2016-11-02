#include <stdlib.h>
#include "linkedlist.h"


node* createNode(int value)
{
	node* n = (node*)malloc(sizeof(node));
	n->value = value;
	return n;
}


linkedlist createLinkedList()
{
	return NULL;
}


void insertNode(linkedlist* llptr, node* n)
{
	n->next = *llptr;
	*llptr = n;
}


void deleteNode(linkedlist* llptr)
{
	// delete first node in ll
	if (*llptr != NULL)
	{
		node* n = *llptr;
		*llptr = (*llptr)->next;
		free(n);
	}
}


void insertValue(linkedlist* llptr, int value)
{
	node* n = createNode(value);
	insertNode(llptr, n);
}


node* getByValue(linkedlist ll, int value)
{
	// return first node that match
	if (ll == NULL)
	{
		return NULL;
	}
	if (ll->value == value)
	{
		return ll;
	}
	else
	{
		return getByValue(ll->next, value);
	}
}
