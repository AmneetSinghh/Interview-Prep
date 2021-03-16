#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int val;
  Node* next;
  Node(int val)
  {
    this->val=val;
    next=NULL;
  }
};



class MyLinkedList {
public:
    /** Initialize your data structure here. */
      int size=0;
      Node* head=new Node(0);// push many things after this node;
      MyLinkedList() { }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=size) return -1;
        Node* temp=head->next;
        for(int i=0;i<index;i++) temp=temp->next;
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        // head of the linked list is 0;
        Node* temp=head->next;// 0-> new->1-> 2
        head->next=new Node(val);
        head->next->next=temp;
        size++;

    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
         Node* temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new Node(val);
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
         if(index>size) return;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        Node* temp1=temp->next;
        temp->next=new Node(val);
        temp->next->next=temp1;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=size) return;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        Node* temp1=temp->next;
        temp->next=temp1->next;
        temp1->next=NULL;
        size--;
        delete temp1;
    }

    void print()
    {
        while(head)
        {
            cout<<head->val<<" -> ";
            head=head->next;
        }
    }

    
};



int main(){
MyLinkedList* linked_list=new MyLinkedList();
linked_list->addAtHead(10);
linked_list->addAtHead(12);
linked_list->addAtHead(13);
linked_list->addAtHead(14);// 0 is at the front of the head;
linked_list->print();
cout<<linked_list->size<<"\n";

}




