#include <iostream>

using namespace std;

struct Node{

    int data;
    Node* next;

    Node(int data){
        next = nullptr;
        Node::data = data;
    }
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

};

void push_back(Node*& head, int value){
    // Create a new node
    Node* newNode = new Node(value);

    // Replaced with constructor
    //newNode->data = value;
    //newNode->next = nullptr;

    if ( head == nullptr){ // If linked list is empty
        head = newNode;
    }

    // "walk the list"
    Node* currentNode = head;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

void deleteList(Node*& head){
    while (head != nullptr){
        Node* temp = head;
        head = head-> next;
        delete temp;
    }
}

void insert(Node*& head, int index, int data){
    if(index == 0 ){
        head = new Node(data, head);
    }

    Node* currentNode = head;
    int currentIndex = 0;
    while(currentIndex != (index - 1)){
        currentNode = currentNode->next;
        currentIndex++;
    }
    Node* oldNext = currentNode->next;
    currentNode->next = new Node(data, oldNext);
}

int main(){

    Node* head = nullptr;



    deleteList(head);


    return 0;
}