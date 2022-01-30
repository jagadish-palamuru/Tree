#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void preOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"->";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"->";
}

void inOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    inOrder(root->left);
    cout<<root->data<<"->";
    inOrder(root->right);
    
}

int countNodes(Node* root)
{
    if(root==NULL)
        return 0;
    return ((countNodes(root->left)) + (countNodes(root->right)) + 1);
}

int sumNodes(Node* root)
{
    if(root==NULL)
        return 0;
    return ((sumNodes(root->left)) + (sumNodes(root->right)) + root->data);
}

int height(Node* root)
{
    if(root==NULL)
        return 0;

    int lHeight=height(root->left);
    int rHeight=height(root->right);
    return max(lHeight,rHeight)+1;
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->right->left=new Node(5);
    root->right->right=new Node(4);
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"Count: "<<countNodes(root)<<endl;
    cout<<"SUM: "<<sumNodes(root)<<endl;
    cout<<"Height: "<<height(root)<<endl;
    return 0;
}