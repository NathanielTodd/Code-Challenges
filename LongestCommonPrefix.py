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
            
        if(len(strs)==0): return "" 

        l = sys.maxsize
        for s in strs:
            if(len(s)==0): return ""
            elif(len(s)<l): l = len(s)
        
        i = 0
        for i in range(l):
            c = strs[0][i]
            for s in strs:
                if(s[i]==c):
                    continue
                else:
                    return strs[0][0:i]

        return strs[0][0:i+1]
