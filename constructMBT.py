# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> TreeNode:
                
        if(not nums):
            
            return None
        
        elif(len(nums)==1):
            
            return TreeNode(nums[0])
        
        else:
            
            iMax = 0;
            for i in range(1,len(nums)):
                if(nums[iMax]<nums[i]): iMax = i
                    
            maxTree = TreeNode(nums[iMax])
            maxTree.left = self.constructMaximumBinaryTree(nums[0:iMax])
            maxTree.right = self.constructMaximumBinaryTree(nums[iMax+1:])
            
            return maxTree