class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        digits = {
            "0":0,
            "1":1,
            "2":2,
            "3":3,
            "4":4,
            "5":5,
            "6":6,
            "7":7,
            "8":8,
            "9":9
        }
        
        max_int = 2147483647
        min_int = -2147483648
        
        out = 0
        sign = 1
        sign_flag = True
        for i,c in enumerate(str):
            
            if(sign_flag and c==' '):
                continue
               
            
            elif(sign_flag and c == '-'):
                sign = -1
                sign_flag = False
            
            elif(sign_flag and c=='+'):
                sign = 1
                sign_flag = False
                
            elif(c.isdigit()):
                out = (out*10)+digits[c]
                sign_flag = False
                
            else:
                break
            
            if(sign*out>=max_int):
                return max_int
                    
            elif(sign*out<=min_int):
                return min_int
        
        return sign*out