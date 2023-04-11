#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void recursivePrintList(Node *head){
    if(head == NULL) return;
    cout << head -> data << " ";
    recursivePrintList(head->next);
}

//Time complexity : O(1)
Node *insertAtBegin(Node *head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

void insertAtEnd(Node *head, int data){
    Node *newNode = new Node(data);
    Node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

Node *deleteBegin(Node *head) {
    if(head == NULL){
        return NULL;
    }
    Node *ptr = head->next;
    cout << "deleted node data is: " << head->data << endl;
    delete head;
    return ptr;
}

Node * deleteLast(Node *head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node *ptr = head;
    Node *prev = head;
    while(ptr->next != NULL){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    delete ptr;
    return head;
}

Node *insertMiddle(Node *head, int position, int data) {
    Node *ptr = head;
    Node *newNode = new Node(data);
    if(position == 0){
        newNode->next = head;
        return newNode;
    }
    Node *prev;
    int currIdx = 0;
    while(currIdx != position && ptr != NULL){
        prev = ptr;
        ptr = ptr->next;
        currIdx++;
    }
    newNode->next = prev->next;
    prev->next = newNode;
    return head;


}

int Search(Node *head, int x){
    Node *ptr = head;
    int pos = 1;
    while(ptr != NULL){
        if(ptr->data == x){
            return pos;
        }
        else{
            ptr = ptr->next;
            pos++;
        }
    }
    return -1;
}

int main(){
    Node *head = new Node(10);
    head = insertAtBegin(head, 20);
    head = insertAtBegin(head, 30);
    head = insertAtBegin(head, 40);
    printList(head);
    head = deleteBegin(head);
    printList(head);
    insertAtEnd(head, 50);
    printList(head);
    deleteLast(head);
    printList(head);
    head = insertMiddle(head, 3, 60);
    printList(head);
    cout << "search element" << Search(head, 10);
    return 0;
}