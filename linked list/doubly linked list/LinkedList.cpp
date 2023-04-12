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

    void insertNode(int);
    void deleteNode(int);
    void printList();
};

void LinkedList::insertNode(int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    Node *prevNode = NULL;
    while(temp->next != NULL){
        temp->prev = prevNode;
        prevNode = temp; 
        temp = temp->next;
    }
    temp->next = newNode;
    temp->prev = prevNode;

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
    list.insertNode(10);
    list.insertNode(20);
    list.insertNode(30);
    list.insertNode(40);
    list.insertNode(50);
    list.insertNode(60);
    list.printList();
    return 0;
}