// Implementations of linked list



#include<bits/stdc++.h>
using namespace std;
#define tr cout<<"\n"

class Node
{
	public:
	int data;
	Node *next;
};
void traverse(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
void insert_at_beginning(Node **head,int data)
{
   Node* new_node = new Node();
   new_node->data=data;
   new_node->next=(*head);
   (*head)=new_node;
}

void insert_at_end(Node **head,int data)
{
   Node* new_node = new Node();
   new_node->data=data;
   new_node->next=NULL;
   // this is hte pointer for the previos of the ending;
   Node* last=*head;
   if(*head==NULL){
   	*head=new_node;
   	return;
   }

   while(last->next!=NULL)last=last->next;
   last->next=new_node;
   return;
}
// Insertions insert at beg, insert at end, insert at mid, or insert at gien position;
void insert_at_given_position(Node **head,int data,int position){
	
}

int main(){
 Node* head=NULL;
 insert_at_beginning(&head,1);
 insert_at_end(&head,2);
 insert_at_given_position(&head,3,2);// last is the given position;
 traverse(head);





}