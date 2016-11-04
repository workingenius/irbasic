#include <stdio.h>
#include <assert.h>
#include "postinglist.h"


void main()
{
	postinglist pl = createPostingList();
	node* n;

	// get from empty pl
	n = get(pl, 5);
	assert(n == NULL);

	// delete from empty pl
	delete(&pl, 5);
	assert(n == NULL);

	// insert into empty posting list
	insert(&pl, 5);
	assert(pl->value == 5);

	// get a exist value
	n = get(pl, 5);
	assert(n->value == 5);

	// insert a smaller value
	insert(&pl, 4);
	assert(pl->value == 4);
	assert(pl->next->value == 5);

	// insert a exist value
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

	// get a exist value
	n = get(pl, 6);
	assert(n->value == 6);

	// get a non-exist value
	n = get(pl, 100);
	assert(n == NULL);

	// delete a exist value
	delete(&pl, 5);
	assert(pl->value == 4);
	assert(pl->next->value == 6);
	assert(pl->next->next->value == 7);

	// delete a non-exist value
	delete(&pl, 100);
	assert(pl->value == 4);
	assert(pl->next->value == 6);
	assert(pl->next->next->value == 7);

}
