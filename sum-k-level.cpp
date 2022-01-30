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

void levelOrder(Node* root,int l)
{
    if(root!=NULL)
    {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        int c=0,sum=0;
        while(!q.empty())
        {
            Node* node=q.front();
            q.pop();

            if(node!=NULL)
            {
                //
                if(c==l)
                {    cout<<node->data<<"-";
                    sum+=node->data;
                }

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            else if(!q.empty())
            {
                q.push(NULL);
                //
                c++;
            }
        }
        cout<<endl<<"SUM: "<<sum<<endl;
    }
    
}
void inOrder(Node* root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    
    inOrder(root->right);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    inOrder(root);
    cout<<endl;
    levelOrder(root,2);
    return 0;
}