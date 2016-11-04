typedef struct node
{
	int value;
	struct node* next;
} node;

/*
 * a linkedlist is a pointer to a node
 * thus, a NULL pointer is also a valid
 * linkedlist.
 */
typedef node* linkedlist;


linkedlist createLinkedList();

/*
 * insert a node into linkedlist, then
 * the new node is the first node.
 */
void insertNode(linkedlist*, node*);


void insertValue(linkedlist*, int);


node* getByValue(linkedlist, int);

/*
 * delete the first node whose value
 * equals the value given.
 */
void deleteNode(linkedlist*);
