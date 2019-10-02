// You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

// The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

// Example 1:

// Input: J = "aA", S = "aAAbbbb"
// Output: 3
// Example 2:

// Input: J = "z", S = "ZZ"
// Output: 0
// Note:

// S and J will consist of letters and have length at most 50.
// The characters in J are distinct.

/**
 * Note: the below big-oh analysis ignores the given
 * fact that either string is at most 50 characters in
 * length.
 *
 * With this constraint, it's difficult to say which will be faster.
 * Asymtoptically, the latter is faster but has an initialization of
 * a size 256 bool array in addition to a linear iteration over each string
 * Since the input are so small, this overhead could have a substantial impact
 */

/**
 *Naive but memory efficient implementation.
 *O(JS) in time complexity and O(1) in memory complexity
 */
class NaiveSolution {
  public:
      int numJewelsInStones(string J, string S) {
          
          int jewelCount = 0;
          for(int i=0;i<J.size();i++){
              
              char c = J[i];
              for(int j=0;j<S.size();j++){
                  if(c==S[j])
                      jewelCount++;
              }
          }
          
          return jewelCount;
      }
};

/**
 * Faster solution
 * O(J+S)
 */
class FastSolution {
  public:
    int numJewelsInStones(string J, string S) {
        
        bool jewels[256] = {false};
        int jewelCount = 0;
        for(int i=0;i<J.size();i++){
            jewels[(int)J[i]] = true;
        }
        
        for(int i=0;i<S.size();i++){
            if(jewels[(int)S[i]])
                jewelCount++;
        }
        
        return jewelCount;
    }
};