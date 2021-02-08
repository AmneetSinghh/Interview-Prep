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
	tr;
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


	Node* new_node=new Node();
	new_node->data=data;
	if(*head==NULL)
	{
		new_node->next=NULL;
		(*head)=new_node;
		return;
	}

	if(position==0){
		new_node->next=*head;
		(*head)=new_node;
		return;
		
	}
	// find the previous node;
	Node *current=*head;
	while(position-1>0){ //
		current=current->next;
		position--;
	}
	new_node->next=current->next;
	current->next=new_node;

}

void delete_given_key(Node** head, int key)
{
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        delete temp;
        return;
    }
     else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
     if (temp == NULL)
        return;
     prev->next = temp->next;
      delete temp;
    }
}



void swap_two_nodes(Node** head_ref,int x,int y)
{
	
if (x == y) return;  
Node *prevX = NULL, *currX = *head_ref;  
while (currX && currX->data != x)  
{  
    prevX = currX;  
    currX = currX->next;  
}  
  
// Search for y (keep track of prevY and CurrY  
Node *prevY = NULL, *currY = *head_ref;  
while (currY && currY->data != y)  
{  
    prevY = currY;  
    currY = currY->next;  
}  
  
// If either x or y is not present, nothing to do  
if (currX == NULL || currY == NULL)  
    return;  
  
// If x is not head of linked list  
if (prevX != NULL)  
    prevX->next = currY;  
else // Else make y as new head  
    *head_ref = currY;  
  
// If y is not head of linked list  
if (prevY != NULL)  
    prevY->next = currX;  
else // Else make x as new head  
    *head_ref = currX;  
  
// Swap next pointers  
Node *temp = currY->next;  
currY->next = currX->next;  
currX->next = temp; 
}

// iterative;
void reverse(Node **head)
{
	Node* current=*head;
	Node* pre=NULL;
	Node* next=NULL;
	while(current!=NULL)
	{
        next=current->next;// saving the next node;
        current->next=pre;// chnage it;
        pre=current;
        current=next;// for going forward;
    }
    *head=pre;
}


// recursive;
void rr(Node* pre,Node* cur,Node **head)
{
	if(!(cur->next)){
		*head=cur;
		cur->next=pre;
		return;
	}

	Node* next=cur->next;
	(cur)->next=pre;// current is null;
	rr(cur,next,head);
}

void reverse1(Node** head)
{
	if(!(*head))return;
	rr(NULL,*head,head);// previous,current,head_node;
}

Node* utility(Node* a,Node* b)
{
	Node *dummy=new Node();
	dummy->data=-1;
	dummy->next=NULL;
	Node *tail=dummy;

	while(a && b)
	{
		if(a->data<b->data)
		{
			tail->next=a;
			a=a->next;
		}
		else{
			tail->next=b;
			b=b->next;
		}

		tail=tail->next;
	}

	if(a==NULL)tail->next=b;
	if(b==NULL)tail->next=a;
	return dummy->next;// htis is hte first node;

}

Node* merge_two_sorted_lists(Node *a,Node* b)
{
	if(a==NULL)return b;
	if(b==NULL)return a;
	return utility(a,b);
}







int main(){
 Node* head=NULL;
 // insertions;
 insert_at_beginning(&head,1);
 insert_at_end(&head,2); 
 insert_at_end(&head,3);
 insert_at_end(&head,4);
 insert_at_end(&head,5);
 insert_at_end(&head,6);
//  insert_at_given_position(&head,12,2);// last is the given position;
// delete_given_key(&head,12);
// delete at given positions is the same approach like this , we not have to do that thing.
 // swap_two_nodes(&head,1,3);
 traverse(head);
 // swap_two_nodes(&head,3,4);
 // reverse1(&head);
 	// Node* res = NULL; 
  //   Node* a = NULL; 
  //   Node* b = NULL; 
 
    /* Let us create two sorted linked lists  
    to test the functions 
    Created lists, a: 5->10->15, b: 2->3->20 */
  //   insert_at_beginning(&a, 15); 
  //    insert_at_beginning(&a, 12); 
  //   insert_at_beginning(&a, 10); 
  //   insert_at_beginning(&a, 5); 
 	//  traverse(a);

  //   insert_at_beginning(&b, 20); 
  //      insert_at_beginning(&b, 8); 

  //   insert_at_beginning(&b, 3); 
  //   insert_at_beginning(&b, 2); 
  // traverse(b);

    /* Remove duplicates from linked list */
    res=merge_two_sorted_lists(a, b); 
    // cout << "Merged Linked List is: \n"; 
    // traverse(res); 





}