/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*This program is designed and developed by rakesh sharma(rockey36@gmail.com)*/

#include <iostream>
using namespace std;

/* structure of tree node */
struct BstNode {
    int      data;
    BstNode *left;
    BstNode *right;
};

/*to add the node in tree at the time of insertion */
BstNode *getNewNode(int data)
{
    BstNode*  newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*function to insert node in balanced binary search tree  */
BstNode* Insert(BstNode *root, int data)
{
    if(root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data < root->data)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
    }
    
    return root;
}
/*function to get the minimum value node from right subtree*/
BstNode*  minValueNode(BstNode* root)
{
    BstNode* current = root;
    
    while(current->left != NULL)
        current = current->left;
    
    return current;
}

/*function to delete a node from the binary search tree*/
BstNode*  DeleteNode(BstNode* root, int data)
{
    if(root  ==  NULL)
        return root;
        
    if(data < root->data )
        root->left = DeleteNode(root->left,data);
    else if(data > root->data )
        root->right = DeleteNode(root->right,data);
    else
    {
        if(root->left == NULL)
        {
            BstNode* temp = root->right;
            free(root);
            return temp;
        }
        else if( root->right == NULL)
        {
            BstNode* temp = root->left;
            free(root);
            return temp;
        }
        
        BstNode* temp = minValueNode(root->right);
        root->data = temp->data;
        
        root->right = DeleteNode(root->right,temp->data);
    }
    
    return root;
    
}

/*function to search the element in binary search tree with O(logn) time complexity */
bool Search(BstNode *root, int data)
{
    if(root == NULL )
        return false;
    else if(root->data == data)
        return true;
    else if (data < root->data)
        Search(root->left,data);
    else
        Search(root->right,data);
}

/*function to inorder traversal of binary search tree (BST) */
void Inorder(BstNode *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d \n", root->data);
        Inorder(root->right);
    }
}

int main() {
    
	BstNode *root = NULL;
	root = Insert(root, 15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	Inorder (root);
	
	if (Search(root,20))
	    cout<<"found";
	else
	    cout<<"not found";
    
    root = DeleteNode(root,20);
    Inorder (root);
    
	return 0;
}
