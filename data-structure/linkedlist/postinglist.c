#include <stdlib.h>
#include "linkedlist.h"
#include "postinglist.h"


postinglist createPostingList()
{
	return (postinglist)createLinkedList();
}


void insert(postinglist* plptr, int value)
{
	if ((*plptr) == NULL || (*plptr)->value > value)
		insertValue(plptr, value);
	else if ((*plptr)->value < value)
		insert(&((*plptr)->next), value);
	else if ((*plptr)->value == value)
		return;
}


node* get(postinglist pl, int value)
{}


void delete(postinglist pl, int value)
{}
