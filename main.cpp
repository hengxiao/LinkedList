#include <iostream>

using namespace std;

const static int kNumbersInList[] = {0, 1, 2, 3, 4};
const static int kListLength = 5;

struct Node {
    int value;
    Node *nextNode;
};

typedef Node* LinkedList;


LinkedList getList() {
    Node *startNode = NULL;
    Node *currentNode = NULL;
    Node *lastNode = NULL;
    for (int i = 0; i < kListLength; i++) {
        currentNode = new Node;
        currentNode->value = kNumbersInList[i];
        currentNode->nextNode = NULL;
        if (i == 0) startNode = currentNode;
        if (lastNode != NULL) lastNode->nextNode = currentNode;
        lastNode = currentNode;
    }
    return startNode;
}

void printList(LinkedList list) {
    Node *node = list;
    while (node != NULL) {
        cout << node->value << endl;
        node = node->nextNode;
    }
}

void freeList(LinkedList& list) {
    Node *currentNode = list;
    Node *nextNode = NULL;
    while (currentNode != NULL) {
        nextNode = currentNode->nextNode;
        delete currentNode;
        currentNode = nextNode;
    }
}

Node *firstNode(LinkedList list) {
    return list;
}

int main()
{
    LinkedList list = getList();
    printList(list);
    Node *firstNode = firstNode(list);
    freeList(list);
    return 0;
}

