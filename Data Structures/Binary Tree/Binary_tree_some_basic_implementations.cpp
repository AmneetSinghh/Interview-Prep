/*  Binary Tree Some Basic Implementations */
#include<bits/stdc++.h>
using namespace std;
struct Node 
{ 
    int data; 
    Node* left, * right; 
}; 
  
Node* newNode(int data) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
int height(Node* root)
{
	if(root==NULL)return 0;
	return 1+(max(height(root->left),height(root->right)));

}
int diameter(Node* root)
{
   if(root==NULL) return 0;
   int option1=height(root->left)+height(root->right)+1;
   int option2=diameter(root->left);
   int option3=diameter(root->right);
   return max(option3,max(option1,option2));
}

Node* buildtree(int a[],Node* root,int i,int n)
{
	if(i<n)
	{
    Node* temp=newNode(a[i]);
	root=temp;
	root->left=buildtree(a,root->left,2*i+1,n);
	root->right=buildtree(a,root->right,2*i+2,n);
	}
	return root;
}

void inorder(Node* root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout << root->data <<" "; 
        inorder(root->right); 
    } 
} 

void inorder_iterative(Node* root)
{
	stack<Node*> s;
	Node* cur=root;
	while(!s.empty() || cur!=nullptr)
	{
		if(cur!=nullptr)
		{
			s.push(cur);
			cur=cur->left;
		}
		else
		{
			cur=s.top();
			s.pop();
			cout<<cur->data<<" ";
			cur=cur->right;
		}
	}
}



void preorder(Node* root) 
{ 
    if (root != NULL) 
    { 
    	cout << root->data <<" "; 
        preorder(root->left); 
        preorder(root->right); 
    } 
} 

void preorder_iterative(Node* root)
{
	stack<Node*> s;
	Node* cur=root;
	while(!s.empty() || cur!=nullptr)
	{
		if(cur!=nullptr)
		{
			cout<<cur->data<<" ";
			if(cur->right!=nullptr)s.push(cur->right);
			cur=cur->left;
		}
		else
		{
			cur=s.top();
			s.pop();
		}
	}

}


void postorder(Node* root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
        cout << root->data <<" "; 

    } 
} 

// Reversal Postorder using two stacks;
void postorder_iterative_using_two_stack(Node* root)
{
	stack<Node*> s;
	stack<int> out;
	s.push(root);
	Node* cur;
	while(!s.empty())
	{
		cur=s.top();
		s.pop();
		out.push(cur->data);
		if(cur->left)s.push(cur->left);
		if(cur->right)s.push(cur->right);
	}
	while(out.empty()==false)
	{
      cout<<out.top()<<" ";
      out.pop();
	}
}

// idea is push the root node two times into the stack;
void postorder_iterative_using_one_stack(Node* root)
{
	stack<Node*> s;
	Node* cur=root;
	while(true){
		while(cur!=nullptr)
		{
			s.push(cur);
			s.push(cur);
			cur=cur->left;
		}
		if(s.empty())return;
		cur=s.top();
		s.pop();
		if(s.top()==cur && s.empty()==false)cur=cur->right;
		else
		{
			cout<<cur->data<<" ";
			cur=nullptr;
			// return to the previoss call;
		}
	}

}






// check if the tree is balanced or not

// int getHeight(TreeNode* root) {
//     return root == NULL ? 0 : 1 +
//         max(getHeight(root->left), getHeight(root->right));
// }
// bool isBalanced(TreeNode* root) {
//         if (root == NULL) {
//             return true;
//         }
//         int left = getHeight(root->left);
//         int right = getHeight(root->right);
//         return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
//     }














int main()
{
	int a[]={1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(a[0]); 
	Node* root=buildtree(a,root,0,n);
    cout<<diameter(root)<<"\n";
 //    cout<<"\nRecursive\n";
	// inorder(root);
	// cout<<"\nIterative\n";
	// inorder_iterative(root);
	//   cout<<"\nRecursive\n";
	// preorder(root);
	// cout<<"\nIterative\n";
	// preorder_iterative(root);

	//   cout<<"\nRecursive\n";
	// postorder(root);
	// cout<<"\nIterative uisng two stacks (REversal postorder)\n";
	// postorder_iterative_using_two_stack(root);
	// cout<<"\nIterative using one stack push root node two times, for making visited;\n";
	// postorder_iterative_using_one_stack(root);

}