#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

# define MAX_LEVEL (3)
// 0, 1, 2, 3

typedef struct node
{
	int isHeader;
	int value;
	int level;
	int _;
	int __;
	int ___; // alignemnt in 64bit machine
	struct node *skip[1];
} node;

typedef node* skiplist;


void printSkipList(skiplist);


# define LEVEL_LEN 15
int levels[LEVEL_LEN] = {0, 1, 0, 2, 0, 3, 1, 0, 2, 0, 0 ,1, 0, 0, 1};
static int _ri = 0;

int randomLevel()
{
	if (_ri > LEVEL_LEN)
		_ri = 0;
	return levels[_ri++];
}


node* createNode(int value, int level)
{
	int l;
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

void releaseNode(node* n)
{
	free(n);
}


node* skipInLevel(node* n, int level)
{
	return n->skip[level];
}


node* searchPos(skiplist sl, int v, int l)
{
	// search for the first node that is just lt value v, in level l
	//assert(sl != NULL);
	node *r, *next = skipInLevel(sl, l);

	if (next == NULL)
	{
		return sl;
	}
	if (next->value < v)
	{
		r = searchPos(next, v, l);
		if (r == NULL)
			return sl;
		else
			return r;
	}
	else if (next->value >= v)
	{
		return sl;
	}
}


node* getNode(skiplist sl, int value)
{
	int i;
	node* n = sl;
	for (i = MAX_LEVEL; i >= 0; i--)
	{
		n = searchPos(n, value, i);
	}
	return n;
}


void insertNode(skiplist sl, node* n)
{
	int l = MAX_LEVEL, i;
	node* _n = sl;
	for (i = l; i >= 0; i--)
	{
		_n = searchPos(_n, n->value, i);
		if (i <= n->level)
		{
			n->skip[i] = _n->skip[i];
			_n->skip[i] = n;
		}
	}
}


void insertValue(skiplist sl, int value)
{
	int level;
	node* n;
	//n = getNode(sl, value);
	//if (n != NULL && skipInLevel(n, 0)->value == value) return;
	level = randomLevel();
	n = createNode(value, level);
	insertNode(sl, n);
}


void deleteValue(skiplist sl, int value)
{
	int l = MAX_LEVEL, i;
	node* n = sl;
	node* next;
	for (i = l; i >= 0; i--)
	{
		n = searchPos(n, value, l);
		next = skipInLevel(n, i);
		if (next != NULL && next->isHeader == 0 && next->value == value) {
			n->skip[i] = next->skip[i];
			releaseNode(next);
		}
	}
}


skiplist createSkipList()
{
	node* n = createNode(0, MAX_LEVEL);
	n->isHeader = 1;
	return n;
}


void printSkipList(skiplist sl)
{
	node* n = skipInLevel(sl, 0);
	do {
		printf("%d ", n->value);
		n = skipInLevel(n, 0);
	} while (n);
	printf("\n");
}


void main()
{
	skiplist sl = createSkipList();
	insertValue(sl, 4);
	insertValue(sl, 5);
	insertValue(sl, 8);
	insertValue(sl, 6);
	insertValue(sl, 2);
	insertValue(sl, 10);
	insertValue(sl, 4);
	insertValue(sl, 22);
	insertValue(sl, 10);
	insertValue(sl, 19);
	printSkipList(sl);
}
