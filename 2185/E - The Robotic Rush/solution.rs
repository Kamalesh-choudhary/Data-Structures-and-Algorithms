use std::io;
 
fn solve() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();
 
    for _ in 0..t {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let nums: Vec<usize> = input.split_whitespace()
            .map(|s| s.parse().unwrap()).collect();
        let n = nums[0];
        let m = nums[1];
        let k = nums[2];
 
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let a: Vec<i64> = input.split_whitespace()
            .map(|s| s.parse().unwrap()).collect();
 
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut b: Vec<i64> = input.split_whitespace()
            .map(|s| s.parse().unwrap()).collect();
 
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let s = input.trim();
 
        b.sort_unstable();
        let mut reach_l = vec![-1i32; k + 1];
        let mut reach_r = vec![-1i32; k + 1];
        let mut current_pos = 0i64;
        let mut max_l = 0i64;
        let mut max_r = 0i64;
 
        for (idx, ch) in s.chars().enumerate() {
            let time = (idx + 1) as i32;
            if ch == 'L' { current_pos -= 1; } 
            else { current_pos += 1; }
 
            if -current_pos > max_l {
                max_l = -current_pos;
                if max_l <= k as i64 { reach_l[max_l as usize] = time; }
            }
            if current_pos > max_r {
                max_r = current_pos;
                if max_r <= k as i64 { reach_r[max_r as usize] = time; }
            }
        }
 
        let mut death_counts = vec![0; k + 1];
        for pos in a {
            let res = b.binary_search(&pos);
            let right_idx = match res {
                Ok(idx) => idx,
                Err(idx) => idx,
            };
 
            let mut time_to_die = i32::MAX;
            if right_idx < m {
                let dist = b[right_idx] - pos;
                if dist <= k as i64 && reach_r[dist as usize] != -1 {
                    time_to_die = time_to_die.min(reach_r[dist as usize]);
                }
            }
            if right_idx > 0 {
                let dist = pos - b[right_idx - 1];
                if dist <= k as i64 && reach_l[dist as usize] != -1 {
                    time_to_die = time_to_die.min(reach_l[dist as usize]);
                }
            }
 
            if time_to_die != i32::MAX {
                death_counts[time_to_die as usize] += 1;
            }
        }
        let mut alive = n;
        for i in 1..=k {
            alive -= death_counts[i];
            print!("{} ", alive);
        }
        println!(); 
    }
}
 
fn main() {
    solve();
}