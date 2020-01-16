


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
            
        if(d==1){
            
            TreeNode *out = new TreeNode(v);
            out->left = root;
         
            return out;
            
        } else{
            
          return addOneRow_Recurse(root, v, d, 1);
            
        }
        
    }
    
    TreeNode* addOneRow_Recurse(TreeNode* root, int v, int d, int curr) {
        
        if(curr==d-1 && root!=NULL){
            
            TreeNode *temp;
            
            temp = root->left;
            root->left = new TreeNode(v);
            root->left->left = temp;
            
            temp = root->right;
            root->right = new TreeNode(v);
            root->right->right = temp;
        
        } else if(root!=NULL){
            
            addOneRow_Recurse(root->left, v, d, curr+1);
            addOneRow_Recurse(root->right, v, d, curr+1);
            
        }
        
        return root;
    }
};