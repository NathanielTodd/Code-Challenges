// Given the root of a binary search tree with distinct values, modify it so that every node has a new value equal to the sum of the values of the original tree that are greater than or equal to node.val.

// As a reminder, a binary search tree is a tree that satisfies these constraints:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.


// Note:

// The number of nodes in the tree is between 1 and 100.
// Each node will have value between 0 and 100.
// The given tree is a binary search tree.

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
    
    stack<TreeNode*> nodes;
    
    TreeNode* bstToGst(TreeNode* root){
        
        int sum = 0;

        toStack(root);
        while(!nodes.empty()){
            
                if(nodes.top() != NULL){
                    sum += nodes.top()->val;
                    nodes.top()->val = sum;
                }
            
                nodes.pop();
        }
        
        return root;
    }
    
    TreeNode* toStack(TreeNode* root){
        
            if(root == NULL){
                    return NULL;
            }
        
            if(root->left != NULL){
                    nodes.push(toStack(root->left));
            }
        
            nodes.push(root);
        
            if(root->right != NULL){
                    nodes.push(toStack(root->right));
            }
        
            return NULL;
    }
};