typedef struct node
{
	int value;
	struct node* next;
} node;

typedef node* linkedlist;


linkedlist createLinkedList();
void insertNode(linkedlist*, node*);
void insertValue(linkedlist*, int);
node* getByValue(linkedlist, int);
void deleteNode(linkedlist*);
