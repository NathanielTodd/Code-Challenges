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
