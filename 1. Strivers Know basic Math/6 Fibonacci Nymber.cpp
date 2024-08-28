class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; ++i) {
            c = a + b;  // c s teh next number here in FIbonacci Series
            a = b;      // update a to be previous value of b
            b = c;      // update b to be the new vlue of c
        }
        return b;
    }
};
