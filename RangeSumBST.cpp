// Solution written by Nathaniel Todd

// Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).

// The binary search tree is guaranteed to have unique values.

 

// Example 1:

// Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
// Output: 32
// Example 2:

// Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
// Output: 23
 

// Note:

// The number of nodes in the tree is at most 10000.
// The final answer is guaranteed to be less than 2^31.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
// In worst case the solution is O(N) where N is the number of nodes
// However, this worst case only occurs when all node values are in
// L and R. In practice, the runtime will be better than this because
// the solution leverages the BST structure to not search sub trees where
// no number between L and R exists.

// Assuming the BST is balanced the solution is O(log(N)) because the maximum number
// of recursive calls is limited to the depth of the tree. When the depth of the BST
// is reached, it will return from a recursive call before adding more calls.
// However, if BST is not balanced D = N and the memory usage coud be O(N) as well.
 
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        if(root==NULL){
            
            return 0;
            
        } else if(root->val<L){
            
            return rangeSumBST(root->right,L,R);
            
        } else if(root->val>R){
            
            return rangeSumBST(root->left,L,R);
            
        } else{
            
            return root->val + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
            
        }
        
    }
};