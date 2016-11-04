#include <stdio.h>
#include <assert.h>
#include "linkedlist.h"
#include "postinglist.h"

void main()
{
	postinglist pl = createPostingList();

	/** test insert **/
	// insert into empty posting list
	insert(&pl, 5);
	assert(pl->value == 5);

	// insert a smaller value
	insert(&pl, 4);
	assert(pl->value == 4);
	assert(pl->next->value == 5);

	// insert a existed value
	insert(&pl, 4);
	assert(pl->value == 4);
	assert(pl->next->value == 5);

	insert(&pl, 5);
	assert(pl->value == 4);
	assert(pl->next->value == 5);

	// insert a larger value
	insert(&pl, 7);
	assert(pl->value == 4);
	assert(pl->next->value == 5);
	assert(pl->next->next->value == 7);

	insert(&pl, 6);
	assert(pl->value == 4);
	assert(pl->next->value == 5);
	assert(pl->next->next->value == 6);
	assert(pl->next->next->next->value == 7);

}
