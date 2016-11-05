#include <stdlib.h>
#include "skiplist.h"

#define bool	int
#define true	1
#define false	0


# define LEVEL_LEN 15
int levels[LEVEL_LEN] = {0, 1, 0, 2, 0, 3, 1, 0, 2, 0, 0 ,1, 0, 0, 1};
static int _ri = 0;

static int randomLevel()
{
	if (_ri > LEVEL_LEN)
		_ri = 0;
	return levels[_ri++];
}


node* createNode(int value)
{
	int l;
	int level = randomLevel();
	node* n = (node*)malloc(sizeof(node) + level * sizeof(node*));
	n->isHeader = 0;
	n->value = value;
	n->level = level;
	for (l = 0; l <= level; l++)
	{
		n->skip[l] = NULL;
	}
	return n;
}


skiplist createSkipList()
{
	skiplist sl = (skiplist)malloc((MAX_LEVEL+1) * sizeof(node*));
	int i;
	for (i=0; i<=MAX_LEVEL; i++)
		sl[i] = NULL;
	return sl;
}


static bool _insertValue(int level, skiplist sl, node* new_node)
{
	node* n = sl[level];
	bool r;
	if (n == NULL)
	{
		if (level > new_node->level)
			return _insertValue(level-1, sl, new_node);
		else if (level <= new_node->level)
		{
			if (level > 0)
			{
				r = _insertValue(level-1, sl, new_node);
				if (r) sl[level] = new_node;
				return r;
			}
			else
			{
				sl[level] = new_node;
				return true;
			}
		}
	}
	else if (n->value > new_node->value)
	{
		if (level >= 0)
		{
			r = _insertValue(level-1, sl, new_node);
			if (r && level >= new_node->level)
			{
				(new_node->skip)[level] = sl[level];
				sl[level] = new_node;
			}
			return r;
		}
		else
		{
			(new_node->skip)[level] = sl[level];
			sl[level] = new_node;
			return true;
		}
	}
	else if (n->value == new_node->value)
		return false;
	else if (n->value < new_node->value)
		return _insertValue(level, (skiplist)(&(n->skip)), new_node);
}


void insertValue(skiplist sl, int value)
{
	node* new_node = createNode(value);
	_insertValue(MAX_LEVEL, sl, new_node);
}


void main()
{
	skiplist sl = createSkipList();
	insertValue(sl, 1);
	insertValue(sl, 1);
	insertValue(sl, 5);
	insertValue(sl, 9);
	insertValue(sl, 8);
	insertValue(sl, 4);
	insertValue(sl, 7);
	insertValue(sl, 6);
	insertValue(sl, 7);
}

#undef bool
#undef true
#undef false
