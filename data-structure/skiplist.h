
#define MAX_LEVEL (3)

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


/* skiplist is a group of node pointer */
typedef node** skiplist;


node* createNode(int);

skiplist createSkipList();

void insertValue(skiplist, int);

//void deleteNode(skiplist*, node*);
