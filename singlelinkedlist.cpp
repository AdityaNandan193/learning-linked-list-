
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

   Node* converttoll(vector<int> & arr){
        Node* head = new Node(arr[0]);
        Node* mover = head;
        for(int i=1; i<arr.size();i++){
            Node* temp = new Node(arr[i]);
            mover -> next = temp;
            mover = temp;
        }
        return head;
    }
    void print(Node* head){
        Node* temp = head;
        
        while(temp != nullptr){
            cout<< temp -> data;
            temp = temp-> next;
        }
    }
    int size(Node* head){
        Node* temp = head;
        int count = 0;
        while(temp != nullptr){
            count++;
            temp = temp-> next;
        }
        return count;
    }
    // deleting the element of kth position 
    Node* deletek(Node* head, int k){
        Node* temp = head;
        Node* prev = head;
        int count = 1;
        
        while(temp != nullptr && count != k ){
            prev = temp;
            temp = temp->next;
            count++;
        }
        prev -> next = temp->next;
        delete temp;
        
        return head;
    }
    // inserting at the head of the linkedlist
    Node* insertathead(Node* head , int k){
        Node* temp = new Node(k);
        temp -> next = head;
        head = temp;
        return head;
    }
    // inserting at the tail of the linkedlist
    Node* insertattail(Node*head, int k){
        Node* temp = new Node(k);
        Node* curr = head;
        while(curr -> next != nullptr){
            curr = curr -> next;
        }
        curr -> next = temp;
        return head;
    }
    // inserting at  a given position 
    Node* insertatpos(Node* head, int p, int k){
        int count = 1;
        Node* curr = head;
        Node* prev = nullptr;

        while(curr != nullptr && count!=p){
            prev = curr;
            curr = curr -> next;
            count++;
        }
        Node* temp = new Node(k);
        prev -> next = temp;
        temp -> next = curr;

        return head;
    }
    // inserting before a given available element
    Node* insertbefore(Node* head, int v, int k){
        Node* curr = head;
        Node* prev = nullptr;
        while(curr != nullptr){
            if(curr -> data == v){
                Node* temp = new Node(k);
                prev -> next = temp;
                temp -> next = curr;
            }
            prev = curr;
            curr = curr -> next; 
        }
        return head;
    }
    
    
int main() {
    // Write C++ code here
    vector<int> arr= {2,3,4,5,6};
    Node* head = converttoll(arr);
    // cout << head->data;
    print(head);
    cout<<endl;

    cout<<"size of the linked list is "<<size(head) <<endl;
    head = deletek(head,3);
    cout<<"the new linked list after removing kth element: "<<endl;
    print(head);
    cout << endl;

    // inserting an element at head of the linkedlist
    cout<<"the new linkedlist after inserting element 4 at head is: "<<endl;
    
    head = insertathead(head, 4);
    print(head);
    
    // inserting an element at the tail of the linkedlist
    cout<<"the new linkedlist after inserting at tail"<<endl;
    head = insertattail(head,8);
    print(head);
    cout<<endl;
    
    // inserting an element at the kth position
    cout<<"the new linkedlist after inserting the element at 3rd position : "<<endl;
    head = insertatpos(head,3,9);
    print(head);
    cout<<endl;

    // inserting an element befor an already available element 
    cout<<"the new linkedlist after insertion is: " <<endl;
    head = insertbefore(head,9, 1);
    print(head);
    cout<<endl;




    return 0;
}