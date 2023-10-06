class Solution {
public:
    int helper(int n, int idx)
    {
       if(n == 0 or idx == 0) return 1;
        
       if(idx > n) return helper(n, idx - 1);
      
       return max((idx * helper(n - idx, idx)), helper(n , idx - 1));
    }
    
    int integerBreak(int n)
    {
       return helper(n, n - 1);
    }
};