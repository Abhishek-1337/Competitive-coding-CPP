#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(){
            data = 0;
            next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    Node *head;

    public:
        LinkedList() {
            head = NULL;
        } 

    void insertAtEnd(int);
    void insertAtBegin(int);
    void deleteAtBegin();
    void deleteAtEnd();
    void printList();

};

//This is efficient solution which insert in O(1) complexity other way is to traverse to the tail then insert there.
void LinkedList::insertAtBegin(int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }
    newNode->next = head->next;
    head->next = newNode;
    int val = newNode->data;
    newNode->data = head->data;
    head->data = val;
}

void LinkedList::insertAtEnd(int data){
    Node *newNode = new Node(data);
    if(head ==  NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }
    newNode->next = head->next;
    head->next = newNode;
    int val = newNode->data;
    newNode->data = head->data;
    head->data = val;
    head = newNode;
}

void LinkedList::printList(){
    Node *curr = head;
    cout << curr->data << " ";
    while(curr->next != head){
        curr = curr->next;
        cout << curr->data << " ";
    }
    cout << "\n";
}

int main(){
    LinkedList list;
    list.insertAtBegin(30);
    list.insertAtBegin(20);
    list.insertAtBegin(10);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.printList();
    return 0;
}