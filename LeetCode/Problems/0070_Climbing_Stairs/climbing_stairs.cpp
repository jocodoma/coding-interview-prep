class Solution {
public:
    int climbStairs(int n) {
        // return recursive(n);
        // return dynamicProgramming(n);
        return fibonacci(n);
    }

    int recursive(int n){
        if(n < 0) return 0;
        if(n < 3) return n;
        return recursive(n-1) + recursive(n-2);
    }

    int dynamicProgramming(int n){
        if(n < 0) return 0;
        if(n < 3) return n;
        int sol[n+1] = {};
        sol[1] = 1;
        sol[2] = 2;
        for(int i = 3; i < (n+1); i++){
            sol[i] = sol[i-1] + sol[i-2];
        }
        return sol[n];
    }

    int fibonacci(int n){
        if(n < 0) return 0;
        if(n < 3) return n;
        int sol = 0, one_b4 = 2, two_b4 = 1;
        for(int i = 3; i < (n+1); i++){
            sol = one_b4 + two_b4;
            two_b4 = one_b4;
            one_b4 = sol;
        }
        return sol;
    }
};
