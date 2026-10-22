impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 1 {
            return 0;
        }

        let p = nums.iter().position(|&x| x == 0).unwrap();

        let mut asc = true;
        let mut desc = true;
        for i in 0..n {
            let v = nums[(p + i) % n] as usize;   // cast here
            if v != i {
                asc = false;
            }
            if v != (n - i) % n {
                desc = false;
            }
        }

        let mut best = i32::MAX;
        if asc {
            best = best.min(p.min(n - p + 2) as i32);
        }
        if desc {
            let m = (p + 1) % n;
            best = best.min((n - p).min(m + 1) as i32);
        }

        if best == i32::MAX { -1 } else { best }
    }
}