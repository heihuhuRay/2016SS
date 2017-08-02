#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#define false 0
#define true 1


/*
 * List element data type.
 * This stores integer an value.
 *
 */
typedef struct _node {
  int val;
  struct _node* next;
} node_t;




/*
 *  List data type.
 *
 *  It uses two dummy elements, one head and one tail of the list. 
 *  These dummy elements are ignored in the implementation.
 */
typedef struct _list {
  node_t *head;
  node_t *tail;
  int *head;
} list_t;


/* 
 *  Add an element to the list, while keeping the list sorted.
 */
int list_add(list_t* list, int item) {

  node_t *pred = list->head;

  /* ignore head element    */
  node_t* curr = pred->next;
  
  while(item < curr->val && curr->next  != list->tail) {
    pred = curr;
    curr = curr->next;
  }
  
  if (curr->val == item) {
    return false;
  }

  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  new_node->val = item;
  new_node->next = curr;
  pred->next = new_node;
  return true;
}


/* 
 *  Remove an element from the list.
 */
int list_remove(list_t *list, int item) {

  node_t *pred = NULL;
  node_t *curr = NULL;
  
  pred=list->head;
  curr=pred->next;
  
  while(item < curr->val && curr->next  != list->tail) {
    pred=curr;
    curr =curr->next;
  }
  
  if (item == curr->val) {
    pred->next=curr->next;
    free(curr);
    return true;
  }
  return false;
}


/*
 * Find an element in the list.
 *
 */
int list_find(list_t *list, int item) {

  node_t *pred=NULL;
  node_t *curr=NULL;
  
  pred=list->head;
  curr=pred->next;
  
  while(item < curr->val && curr->next  != list->tail) {
    pred=curr;
    curr =curr->next;
  }
  
  if (item == curr->val) 
    return true;
  
  return false;
}


/* 
 *  Print the list.
 */ 

int print_list(list_t *list) {
  node_t *d;
  if (list->head == NULL || list->tail == NULL) 
    return 0;
  
  for(d=list->head; d != NULL; d=d->next) {
    printf("%d ",d->val);
  }
  printf("\n");
}


/*
 *  Check that the list is sorted.
 */


int check_list(list_t *list) {

  int v=list->head->val;
  node_t *d;
  if (list->head == NULL || list->tail== NULL) 
    return 0;
  
  for(d=list->head->next; d != list->tail; d=d->next) {
    assert(v < d->val);
  }
}


int main(int argc, char **argv) {

  int i;
  
  /* Allocate the list data structure */
  list_t *list = (list_t*)calloc(1, sizeof(list_t));
  
  /* Add head and tail elements */
  list->head = (node_t*)calloc(1,sizeof(node_t));
  
  list->tail = (node_t*)calloc(1,sizeof(node_t));
  
  list->head->next = list->tail;
  

  /*  pre-fill the data structure  */
  for(i=0; i < 1000; i++) {
    int r = rand();
	
    list_add(list,r);
  }


  /* This loop has to be parallelized    */
  for(i=0; i < 1000000; i++) {
    int r=rand();
   
    list_add(list,r);
   
    list_find(list,r);
   
    list_remove(list,r);
   
  }

  return EXIT_SUCCESS;
}
