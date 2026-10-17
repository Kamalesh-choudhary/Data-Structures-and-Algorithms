impl Solution {
    fn digit_sum(mut n: i32) -> i32 {
        let mut total: i32 = 0;
        while n>0{
            total += n%10;
            n /= 10;
        }
        total
    }
    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        let n: usize = nums.len();
        let mut v: Vec<(i32,usize)> = (0..n).map(|i| (nums[i],i)).collect();
        v.sort_by(|a,b|{
            let a_sum = Self::digit_sum(a.0);
            let b_sum = Self::digit_sum(b.0);
            if a_sum == b_sum {
                a.0.cmp(&b.0)
            }
            else{
                a_sum.cmp(&b_sum)
            }
        });

        let mut vis = vec![false;n];
        let mut swaps = 0;
        for i in 0..n {
            if(vis[i] || v[i].1 == i){
                continue;
            }
            let mut cycle = 0;
            let mut j = i;
            while !vis[j] {
                vis[j] = true;
                j = v[j].1;
                cycle += 1;
            }
            swaps += (cycle-1) as i32;
        }
        swaps
    }
}