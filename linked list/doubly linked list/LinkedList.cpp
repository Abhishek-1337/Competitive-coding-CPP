#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(){
            data = 0;
            next = NULL;
            prev = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
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

void LinkedList::insertAtEnd(int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

}

void LinkedList::insertAtBegin(int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return;
}

void LinkedList::deleteAtBegin(){
    Node *newHead = head->next;
    Node *temp = head;
    newHead->prev = NULL;
    head = newHead;
    delete temp;
}

void LinkedList::deleteAtEnd(){
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node *prevNode = temp->prev;
    prevNode->next = NULL;
    delete temp;
}

void LinkedList::printList(){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << "\n";
        temp = temp -> next;
    }
}

int main(){
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    list.insertAtEnd(60);
    list.insertAtBegin(5);
    list.insertAtBegin(4);
    list.deleteAtBegin();
    list.deleteAtEnd();
    list.printList();
    return 0;
}