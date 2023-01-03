#include <bits/stdc++.h>
using namespace std;
#include <queue>
#include <vector>
using namespace std;


class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
       this->data = d;
       this->left = NULL;
       this->right = NULL;
    }
};

vector<vector<int>> levelOrderTraversal(Node *root) {
  if (!root) {
    return {};
  }
  vector<int> row;
  vector<vector<int>> result;
  queue<Node *> q;
  q.push(root);
  int count = 1;

  while (!q.empty()) {
    if (q.front()->left) {
      q.push(q.front()->left);
    }
    if (q.front()->right) {
      q.push(q.front()->right);
    }
    row.push_back(q.front()->data);
    q.pop();
    if (--count == 0) {
      result.push_back(row), row.clear();
      count = q.size();
    }
  }
  return result;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout<<root->data<<" ";
}

Node* insertIntoBST(Node* root,int d){
  
   //base case
   if(root==NULL){
     root = new Node(d);
     return root;
   }

  if(d>root->data){
    //right part
     root->right = insertIntoBST(root->right,d);
  }
  else{
    //left part
    root->left = insertIntoBST(root->left,d);
  }
   return root;   
}

void takeInput(Node* &root){
   int data;
   cin>>data;

   while(data!=-1){
     root = insertIntoBST(root,data);
     cin>>data;
   } 
}




bool searchInBST(Node* root, int x) {
    // Write your code here.
    if(root==NULL){
      return false;   
    }
    
    if(x < root->data){
        return searchInBST(root->left,x);
    }
    else if( x > root->data){
        return searchInBST(root->right,x);
    }
    else{
        return true;
    }
}


int main() {
   Node* root = NULL;
  
   cout<<"enter data to create BST"<<endl;
   takeInput(root);

   cout<<"printing BST"<<endl;
   inorder(root);
   cout<<"\n";

    int ele;
    cout<<"Enter the element to be searched"<<endl;
    cin>>ele;
    if(searchInBST(root,ele)){
        cout<<"Element present"<<endl;  
    }else{
        cout<<"Element absent"<<endl; 
    }

  
}

