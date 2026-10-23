impl Solution {
    pub fn sort_permutation(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut sorted = true;
        for i in 0..n {
            if nums[i] as usize != i {
                sorted = false;
            }
        }
        if sorted {
            return 0;
        }

        let mut ans = 0;
        for bit in 0..32 {
            let mut yes = true;
            for i in 0..n {
                if nums[i] as usize != i && (nums[i]&(1<<bit) == 0) {
                    yes = false;
                }
            }
            if yes {
                ans |= (1<<bit);
            }
        }
        ans
    }
}