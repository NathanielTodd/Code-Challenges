/*
Author: Nathaniel Todd
Date Updated: 08/14/29

Problem Description:
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

Explanation:
In order to determine if an int is a palindrome, I isolate the digits and build a reversed
number. In reality, I only have to do this for the first half of the digits and compare it 
against the latter half of the digits.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        
        //If the input is negative or
        //a multiple of 10, it's not a plaindrome
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        //Isolate and reverse the lower half
        //of the digits, if there is an odd num
        //of digits add it to the revrsed half
        int rev = 0;
        while(x > rev){
            rev = rev * 10 + x % 10;
            x = x/10;
        }
        
        //return the test result of
        //the reversed half or
        //the reversed half without the
        // middle digits
        return x==rev || x==(rev/10);
    }
};
