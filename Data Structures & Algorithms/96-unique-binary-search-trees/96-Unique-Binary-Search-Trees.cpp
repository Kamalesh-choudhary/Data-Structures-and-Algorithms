class Solution {
public:
    long long countTreesMemo(int n, vector<long long>& memo) {
    if (n <= 1) {
        return 1;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    long long totalTrees = 0;
    
    // Recursive formula: C_n = sum(C_i * C_{n-1-i}) for i from 0 to n-1
    for (int i = 0; i < n; ++i) {
        totalTrees += countTreesMemo(i, memo) * countTreesMemo(n - 1 - i, memo);
    }

    return memo[n] = totalTrees;
}
    int numTrees(int n) {
        vector<long long> memo(n + 1, -1);
        return countTreesMemo(n,memo);
    }
};