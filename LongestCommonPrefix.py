# Author: Nathaniel Todd
# Date: 08/16/2019

# Write a function to find the longest common prefix string amongst an array of strings.
#
# If there is no common prefix, return an empty string "".
#
# Example 1:
# Input: ["flower","flow","flight"]
# Output: "fl"
#
# Example 2:
# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
#
# Note:
# All given inputs are in lowercase letters a-z.

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
            
        #if list is empty return an empty string
        if(len(strs)==0): return "" 
        
        # only need to iterate up to the shortest string length
        # if any of the strings are empty reutrn an empty string
        l = sys.maxsize
        for s in strs:
            if(len(s)==0): return ""
            elif(len(s)<l): l = len(s)
        
        i = 0
        # iterate through and check each character
        for i in range(l):
            
            # return the substring prefix up to that point if a mismatch is found
            c = strs[0][i]
            for s in strs:
                if(s[i]!=c):
                    return strs[0][0:i]
                
        #otherwise return the shortest string as the prefix
        return strs[0][0:i+1]
