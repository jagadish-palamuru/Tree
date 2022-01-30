#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int data)
    {
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};

void leftView(Node* root)
{
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);    
    
    while(!q.empty())
    {
    int n=q.size();

    for(int i=0;i<n;i++)
    {
        Node* node=q.front();
        q.pop();

        
            if(i==0)
                cout<<node->data<<" ";
            if(node->left)
            q.push(node->left);
            if(node->right)
            q.push(node->right);
        
        
    }}
}
void inOrder(Node* root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<"->";
    inOrder(root->right);
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);
    root->left->left=new Node(5);
    root->right->left=new Node(6);

    inOrder(root);
    cout<<"\nLEFT-VIEW: ";
    leftView(root);
    return 0;
}