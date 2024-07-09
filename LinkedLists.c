#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* initialise (int number) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = number;
    node->next = NULL; 
    return node;
}

void print_linked_list (Node* current) {
    if (current->next == NULL) {
        printf("%d\n", current->value);
        return;
    }
    printf("%d\n", current->value);
    print_linked_list(current->next);
}

void append (Node* LL, int number) {
    Node* current = LL;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (Node*)malloc(sizeof(Node));
    current->next->value = number;
    current->next->next = NULL;
}

void removeByValue(Node** LL, int value) {
    Node* current = *LL;
    Node* prev = NULL;
    if (current != NULL && current->value == value) {
        *LL = current->next;
        free(current); 
        return;
    }
    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        return;
    }
    prev->next = current->next;
    free(current);
}

void pop (Node* LL) {
   Node* current = LL;
   if (current->next == NULL) {
        free(current);
        current->next = NULL;
        return;
   }
   while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

int main () {
    Node* ll = initialise(12);
}

