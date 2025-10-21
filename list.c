#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * Returns the tail of the linked list
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct ll_node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    } 
    return curr;
}

/**
 * Returns the number of nodes in a linked list
 */
int ll_size(struct ll_node *head) {
  int count = 0;
   struct ll_node *curr = head;
   while(curr != NULL) {
    count++;
    curr = curr->next; 
   }
   return count; 

}

/**
 * Finds the first node containing the given value
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
   struct ll_node *curr = head;
   while (curr != NULL) {
    if (curr->data == value){
        return curr;
    }
    curr = curr->next; 
    }
    return NULL;
   }

/**
 * Conbers the linked list to an array of integers
 */
int *ll_toarray(struct ll_node *head) {
    int size = ll_size(head);
    if (size == 0){
        return NULL;
    }
    int *arr = malloc(size * sizeof(int));
    if (arr == NULL){
        return NULL;
    }
    struct ll_node *curr = head;
    for (int i =0; i < size; i++){ 
        arr[i] = curr->data;
        curr = curr->next;
    }
   return arr; 
}

/**
 * Creates a new linekd list node with the given data
 */
struct ll_node *ll_create(int data) {
   struct ll_node *node = malloc(sizeof(struct ll_node));
   if (node == NULL) {
    return NULL; 
   }
   node->data = data;
   node->next = NULL;
   return node;
}

/**
 * Frees all mem used by the linked list
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *curr = head;
    while (curr != NULL) {
        struct ll_node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}

/**
 * Appends a new node with the given data to the end of the linked list
 */
void ll_append(struct ll_node *head, int data) {
    if (head == NULL) {
        return;
    }
    struct ll_node *tail = ll_tail(head);
    tail->next = ll_create(data);
}

/**
 * Creates a linked list from an array of integers
 */
struct ll_node *ll_fromarray(int* data, int len) {
    if (len <= 0){
        return NULL; 
    }
    struct ll_node *head = ll_create(data[0]);
    struct ll_node *curr = head;

    for (int i = 1; i < len; i++) {
        curr->next = ll_create(data[i]);
        curr = curr->next; 
    }
    return head;
}

/**
 * Removes the first node containg the given value
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    if (head == NULL){
        return NULL;
    }
    if (head->data == value){
        struct ll_node *temp = head->next;
        free(head);
        return temp;
    }

    struct ll_node *curr = head; 
    while (curr->next != NULL && curr->next->data != value) {
        curr = curr->next;
    }

    if (curr->next != NULL){
        struct ll_node *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
    }
    return head; 
}

