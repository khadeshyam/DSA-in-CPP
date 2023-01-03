//using loops does not require any call stack (OPTIMISED)
//TC:O(log n) like binary search
//SC:O(1) no recursion stack

 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while(root){
             if(p->val < root->val && q->val < root->val){
               root = root ->left;
            }
            else if(p->val > root->val && q->val > root->val){
               root = root ->right;
            }
            else{                
              return root; 
            }
        }
      return nullptr;  
    }