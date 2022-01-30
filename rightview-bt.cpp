#include<iostream>
#include<queue>
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

void levelOrder(Node* root)
{
    if(root==NULL)
        return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);


    //left-view in comments
    //cout<<q.front()->data<<" ";
    while(!q.empty())
    {
        Node* node=q.front();
        q.pop();

        if(node!=NULL)
        {
            if(q.front()==NULL)
                cout<<node->data<<" ";

            if(node->left)
                q.push(node->left);
            
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty())
        {
            //cout<<q.front()->data<<" ";
            q.push(NULL);
        }
       
          
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
/*void rightView(Node* root)
{
    if(root==NULL)
        return;
    rightView(root->right);
    cout<<root->data<<" "; 
}*/

/*void sumReplacement(Node* root)
{
    if(root==NULL)
        return;
    sumReplacement(root->left);
    sumReplacement(root->right);

    if(root->left!=NULL)
        root->data+=root->left->data;
    if(root->right!=NULL)
        root->data+=root->right->data;   
}*/
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(4);
    root->right=new Node(3);
    root->right->left=new Node(5);
    root->right->left->left=new Node(7);
    root->right->right=new Node(6);

    inOrder(root);
    cout<<endl<<"LEVEL-ORDER: ";
    levelOrder(root);
    //cout<<"\nRIGHTVIEW: ";
    //rightView(root);
    //cout<<"\nSUM-Replacement: ";
    //sumReplacement(root);
    //cout<<"\nsum: ";
    
}