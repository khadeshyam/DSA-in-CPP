 bool isBST(TreeNode* root, long min,long max) {
        if(root==NULL){
             return true;
         }
        
        //if root's value is not in range
        if(root->val <= min || root->val >= max){
                 return false; 
         }

       //if it's in the range check the left and right subtrees
        bool left =  isBST(root->left,min,root->val);
        bool right =  isBST(root->right,root->val,max);
        return left && right; 
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
}