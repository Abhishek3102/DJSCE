#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

struct Node *node, *start=NULL, *q, *temp;

// creating node and allocating memory
struct Node *createNode(int info) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = info;
    node->next = NULL;
    return node;
}

// adding at start of list
void addStart(int info) {
    node = createNode(info);
    if (start == NULL) {
        start = node;
        node->next = start; // Make the last node point to the first for circularity
    }
    else {
        node->next = start;
        start = node;
    }
}

// adding at end of list
void addEnd(int info) {
    temp = createNode(info);
    q = start;
    while (q->next != start) {
        q = q->next;
    }
    q->next = temp;
    temp->next = start; // Make the last node point to the first for circularity
}

// add after element
void addAfter(int info, int val) {
    temp = createNode(info);
    q = start;
    while (q->data != val) {
        q = q->next;
    }
    temp->next = q->next;
    q->next = temp;
}

// add before element
void addBefore(int info, int val) {
    temp = createNode(info);
    q = start;
    while (q->next->data != val) {
        q = q->next;
    }

    if (q->next=start){
        addStart(info);
    }
    else{
        temp->next = q->next;
        q->next = temp;
    }
}


void addPosition(int info, int pos) {
    int i;
    temp = createNode(info);
    q = start;
    if(pos==1){
        addStart(info);
    }
    else{
        for (i = 0; i < pos - 1; i++) {
            q = q->next;
        }
        temp->next = q->next;
        q->next = temp;
    }
}

// display and count nodes - c
void display() {
    int c = 0;
    if (start == NULL) {
        printf("LIST IS EMPTY");
    } else {
        printf("CIRCULAR LINKED LIST: ");
        q = start;
        do {
            printf("%d -> ", q->data);
            q = q->next;
            c++;
        } while (q != start);
        printf(" (Total Nodes: %d)\n", c);
    }
}

// delete at start - c
void deleteStart() {
    if (start == NULL) {
        printf("LIST IS EMPTY");
    } else {
        q = start;
        while (q->next != start) {
            q = q->next;
        }
        temp=q->next;
        q->next = start->next;
        start = start->next;
        printf("DELETED NODE: %d", temp->data);
        free(temp);
    }
}

// delete at end - c
void deleteEnd() {
    if (start == NULL) {
        printf("LIST IS EMPTY");
    } else if (start->next == start) {
        free(start);
        start = NULL;
    } else {
        q = start;
        while (q->next->next != start) {
            q = q->next;
        }
        temp = q->next;
        q->next = start;
        printf("DELETED NODE: %d", temp->data);
        free(temp);
    }
}

// delete at position - c
void deletePosition(int pos) {
    if (start == NULL) {
        printf("LIST IS EMPTY");
    } else if (pos == 1) {
        deleteStart();
    } else {
        q = start;
        for (int i = 0; i < pos - 2; i++) {
            q = q->next;
        }
        temp = q->next;
        q->next = temp->next;
        printf("DELETED NODE: %d", temp->data);
        free(temp);
    }
}

// search node using value - c
int search(int val) {
    q = start;
    int c = 1;
    do {
        if (q->data == val) {
            return c;
        } else {
            c++;
            q = q->next;
        }
    } while (q != start);
    return -1;
}

// search and delete version 1 
void searchAndDelete(int val) {
    q = start;
    do {
        if (q->next->data == val) {
            temp = q->next;
            q->next = temp->next;
            printf("DELETED NODE: %d", temp->data);
            free(temp);
            return;
        }
        q = q->next;
    } while (q != start);
}

// search and delete version 2 - c
void searchDelete(int val) {
    int pos = search(val);
    deletePosition(pos);
}

int main() {
    // Example usage
    addStart(3);
    addEnd(5);
    addAfter(7, 3);
    addBefore(2, 5);
    addPosition(9, 3);
    display();
    deleteStart();
    deleteEnd();
    deletePosition(2);
    display();

    return 0;
}