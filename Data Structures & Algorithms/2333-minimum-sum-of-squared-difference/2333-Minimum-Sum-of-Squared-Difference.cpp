class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        int mx = 0;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, d[i]);
        }

        vector<long long> cnt(mx + 1, 0);
        for (int x : d) cnt[x]++;

        for (int v = mx; v >= 1 && k > 0; v--) {
            if (cnt[v] == 0) continue;
            long long moved = min(k, cnt[v]);
            cnt[v] -= moved;
            cnt[v - 1] += moved;
            k -= moved;
        }

        long long total = 0;
        for (int v = 1; v <= mx; v++) {
            total += cnt[v] * (long long)v * v;
        }
        return total;
    }
};