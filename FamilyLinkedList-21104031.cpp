// Linked List Assignment 1: Doubly Linked Lists
#include<bits/stdc++.h>
using namespace std;

// Creation of node
class Node{
public:
    string name;
    int age;
    Node* prev;
    Node* next;
    Node(string n,int a){
        name = n;
        age = a;
        next = NULL;
        prev = NULL;
    }
};

// Function to add elemets in the list
void pushBack(Node*& head,Node*& current){
    if(head==NULL){
        head = current;
        return;
    }
    // If no head, set new node as head
    Node* temp = head;
    // if next not none (tail) continue traversing
    while(temp->next!=NULL){
        temp = temp->next;
    }
    // if tail, add to end
    temp->next = current;
    // set prev pointer to current node
    current->prev = temp;
    return;
}

// Function to display the list
void printFamily(Node* head){
    // Start at head and check if next is not tail
    while(head!=NULL){
        // Display current node of list and traverse forward
        cout<<head->name<<" "<<head->age<<endl;
        head = head->next;
    }
    return;
}

// Maine function
int main(){
    Node* head = NULL;
    int n;
    cout<<"Enter the number of family members: ";
    cin>>n;
    int i=0;
    while(i<n){
        string s;
        int a;
        cout<<"Enter name: ";
        cin>>s;
        cout<<"Enter age: ";
        cin>>a;
        Node* current = new Node(s,a);
        pushBack(head,current);
        i++;
    }
    printFamily(head);
    return 0;
}
