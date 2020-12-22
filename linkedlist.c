#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node {
  int value;
  struct Node* next;
};

//initailly head will be null
struct Node* head = NULL;

//inserting before head is pointing   
void insertAtBeginning(int data) {

  // Allocating memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the new node
  new_node->value = data;
  new_node->next = head;

  // Move head to new node
  head = new_node;
}

// Insert a node after head pointing node
void insertAfter(int data) {
  if (head == NULL) {
    printf("the given previous node cannot be NULL");
    return;
  }

  //llocating memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  
  //inserting new node.
  new_node->value = data;
  new_node->next = head->next;
  // in head next, new node address is set.
  head->next = new_node;
}

//inserting node at the last.
void insertAtEnd(int data) {
  //allocating memory to new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  // we have taken temp node pointer and set it to position of head pointing.
  struct Node* last = head;

  //insert new node as it is insert at last so its next will be null as it it not pointing to other node.
  new_node->value = data;
  new_node->next = NULL;

  //if head is null then we have insert at first.
  if (head == NULL) {
    head = new_node;
    return;
  }

  //traverse to last node as last node will contain next=null.
  while (last->next != NULL)
    last = last->next;

  //add the new node at last.
  last->next = new_node;
  return;
}

//delete the node. we have deleted the element the head node.
void deleteNode(int data) {

  //new tempopary pointer is taken to traverse and it is pointer to head node.
  struct Node *temp = head, *prev;

  //check if head node has given valve.
  if (temp != NULL && temp->value == data) {
    head = temp->next;
    free(temp);
    printf("\ndeleted node : %d\n", data);
    return;
  }
  //traverse through all node and find the key to be deleted
  while (temp != NULL && temp->value != data) {
    prev = temp;
    temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;
  free(temp);
  printf("\ndeleted node : %d\n", data);
}

void search(int value){

  //new tempopary pointer is taken to traverse and it is pointer to head node.
  struct Node *temp = head, *prev;

  //traverse through all node and find the node present or not.
  while (temp != NULL && temp->value != value) {
    prev = temp;
    temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL){
    printf("\nnode not found\n");
  }else{
    printf("\nnode founded\n");
  }

}

// Print the linked list
void printList() {

  //new tempopary pointer is taken to traverse and it is pointer to head node.
  struct Node *temp = head;
  while (temp != NULL) {
    printf(" %d ", temp->value);
    temp = temp->next;
  }
}

int main() {
 
  insertAtEnd(1);
  insertAtBeginning(2);
  insertAtBeginning(3);
  insertAtEnd(4);
  insertAfter(5);

  printf("Linked list: ");
  printList();

  deleteNode(3);
  printf("Linked list: ");
  printList();
  search(5);
}