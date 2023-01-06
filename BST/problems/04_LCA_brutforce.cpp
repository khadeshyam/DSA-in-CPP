 //NOT OPTIMISED 
 //TC:O(log n) like binary search
 //SC:O(log n) due to recursion stack
 
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case 
        if(root==NULL){
            return nullptr;
        }
        
         if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p,q);
        }
        else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p,q);
        }
        return root; 
}