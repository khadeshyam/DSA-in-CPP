//Find TC and SC

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


bool searchBST(Node* root, int data) {
        //using loops reduces SC to O(1)
        Node* temp = root;
        while(temp){
             if(data== temp->data){
                 return true;
             }else if(data<temp->data){
                  temp = temp->left;
             }else{
                temp = temp->right;
             }
        }

  return false;
}

Node* minValue(Node* root){
    if(root==NULL){
        return nullptr;
    }
    Node* temp = root;
    while(temp->left){
         temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* root, int key) {
        //base case 
        if(root == NULL){
            return nullptr;
        }

        if(root->data == key){
           //0 child
           if(root->left==NULL && root->right==NULL){
               delete root;
               return NULL;
           }

           //1 child
           //left child
            if(root->left!=NULL && root->right==NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            } 

           //right child
           if(root->left==NULL && root->right!=NULL){
               Node* temp = root->right;
                delete root;
                return temp;
           }

           //2 child
           if(root->left!=NULL && root->right!=NULL){
               int mini= minValue(root->right)->data;
               root->data = mini;
               root->right = deleteNode(root->right,mini);
               return root;
           }
        }

       //left part call
        if(key<root->data){
           root->left = deleteNode(root->left,key);
           return root;
        }
        //right part call
        else{
             root->right = deleteNode(root->right,key);
             return root;
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
    cout<<"Enter the element to be deleted"<<endl;
    cin>>ele;
    deleteNode(root,ele); 

    inorder(root);
    cout<<"\n";
}
