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
	    
	return 0;
}
