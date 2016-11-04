/** a posinting list implemented by single linked list **/
#include "linkedlist.h"

typedef linkedlist postinglist;


postinglist createPostingList();


void insert(postinglist*, int);


node* get(postinglist, int);


void delete(postinglist*, int);
