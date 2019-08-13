class Solution {
public:
    int reverse(int x) {
        
        int rem = 0;
        int out = 0;
        
        while(x!=0){
            rem = x%10;
            if (out > INT_MAX/10 || (out == INT_MAX / 10 && rem > 7)) return 0;
            if (out < INT_MIN/10 || (out == INT_MIN / 10 && rem < -8)) return 0;
            x = x/10;
            out = 10 * out + rem;
        }
        
        return out;
    }
};
