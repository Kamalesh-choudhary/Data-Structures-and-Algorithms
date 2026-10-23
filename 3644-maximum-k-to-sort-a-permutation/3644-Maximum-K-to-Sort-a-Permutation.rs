impl Solution {
    pub fn sort_permutation(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut sorted = true;
        let mut ans = -1;
        for i in 0..n {
            if(nums[i] != i as i32){
                sorted = false;
                ans &= nums[i];
            }
        }
        if sorted {
            0
        }
        else{
            ans
        }
    }
}