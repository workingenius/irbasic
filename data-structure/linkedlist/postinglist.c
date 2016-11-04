#include <stdlib.h>
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
{
	if (pl == NULL) return NULL;
	if (pl->value < value) return get(pl->next, value);
	if (pl->value == value) return (node*)pl;
	if (pl->value > value) return NULL;
}


void delete(postinglist* pl, int value)
{
	if ((*pl) == NULL) return;
	else if ((*pl)->value < value) delete(&((*pl)->next), value);
	else if ((*pl)->value == value) deleteNode(&(*pl));
	else if ((*pl)->value > value) return;
}
