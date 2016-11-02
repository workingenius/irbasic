#include <stdio.h>
#include <assert.h>
#include "linkedlist.h"
#include "postinglist.h"

void main()
{
	postinglist pl = createPostingList();

	/** test insert **/
	insert(pl, 5);
	assert(pl->value == 5);
}
