class Solution {
public:
    int reverse(int x) {
        
        int remainder = 0;
        int output = 0;
        bool negFlag = false;
        
        if(x==0) return 0;
        else if(x<0){
            negFlag = true;
            x = -1*x;
        }
        
        while(x>0){
            remainder = x%10;
            output = output*10 + remainder;
            x = x/10;
        }
        
        if(negFlag) output = -1*output;
        
        return output;
    }
};
