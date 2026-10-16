const int MOD = 1e9 + 7;

class SegmentTree {
private:
    struct Node {
        long long cnt = 0;
        long long sq_cnt = 0;
        long long lazy = 0;
    };

    int n;
    vector<Node> tree;

    void apply(int node, int st, int en, long long x) {
        long long len = en - st + 1;
        long long oldCnt = tree[node].cnt;

        tree[node].sq_cnt = (tree[node].sq_cnt+ 2LL * x % MOD * oldCnt % MOD + x * x % MOD * len % MOD) % MOD;

        tree[node].cnt = (oldCnt + len * x) % MOD;

        tree[node].lazy = (tree[node].lazy + x) % MOD;
    }

    void push(int node, int st, int en) {
        if (tree[node].lazy == 0 || st == en)
            return;

        int mid = st + (en - st) / 2;
        long long x = tree[node].lazy;

        apply(2 * node, st, mid, x);
        apply(2 * node + 1, mid + 1, en, x);

        tree[node].lazy = 0;
    }

    void merge(int node) {
        tree[node].cnt = (tree[2 * node].cnt + tree[2 * node + 1].cnt) % MOD;

        tree[node].sq_cnt = (tree[2 * node].sq_cnt + tree[2 * node + 1].sq_cnt) % MOD;
    }

    void update(int node, int st, int en, int ql, int qr) {
        if (qr < st || en < ql)
            return;

        if (ql <= st && en <= qr) {
            apply(node, st, en, 1);
            return;
        }

        push(node, st, en);

        int mid = st + (en - st) / 2;

        update(2 * node, st, mid, ql, qr);
        update(2 * node + 1, mid + 1, en, ql, qr);

        merge(node);
    }

public:
    SegmentTree(int n) : n(n), tree(4 * n) {}

    void update(int l, int r) {
        if (l <= r)
            update(1, 0, n - 1, l, r);
    }

    long long getSumOfSquares() const {
        return tree[1].sq_cnt;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        const int MAX_VAL = 100001;

        vector<int> last_seen(MAX_VAL, -1);
        SegmentTree seg(n);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int st = last_seen[nums[i]] + 1;
            last_seen[nums[i]] = i;

            seg.update(st, i);

            ans = (ans + seg.getSumOfSquares()) % MOD;
        }

        return ans;
    }
};