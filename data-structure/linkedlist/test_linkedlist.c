#include <assert.h>
#include <stdio.h>
#include "linkedlist.h"

void main()
{
	linkedlist ll = createLinkedList();

	/** test insertValue **/
	
	// test insert to empty
	insertValue(&ll, 5);
	assert(ll->value == 5);

	// test insert to non-empty
	insertValue(&ll, 10);
	assert(ll->value == 10);
	assert(ll->next->value == 5);


	/** test getValue **/
	node* n;

	// test value that exists
	n = getByValue(ll, 5);
	assert(n->value == 5);

	// test value that doesnt exist
	n = getByValue(ll, 11);
	assert(n == NULL);


	/** test deleteNode **/

	// test delete value in the middle
	deleteNode(&(ll->next));
	assert(ll->value == 10);

	// test delete value in the start
	deleteNode(&ll);
	assert(ll == NULL);

	// test delete empty list
	deleteNode(&ll);
	assert(ll == NULL);

	return;
}
