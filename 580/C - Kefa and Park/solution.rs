use std::io::{self, Read, Write};
 
struct Solution {
    n: usize,
    m: i32,
    ar: Vec<i32>,
    adj: Vec<Vec<usize>>,
}
 
impl Solution {
    fn dfs(&self, v: usize, parent: usize, cnt: i32) -> i64 {
        if cnt > self.m {
            return 0;
        }
        if self.adj[v].len() == 1 && v != 1 {
            return 1; // leaf restaurant
        }
 
        let mut temp: i64 = 0;
        for &u in &self.adj[v] {
            if u == parent {
                continue;
            }
            let next_cnt = if self.ar[u] == 1 { cnt + 1 } else { 0 };
            temp += self.dfs(u, v, next_cnt);
        }
        temp
    }
 
    fn solve(&self) -> i64 {
        if self.n == 1 {
            return 1;
        }
        let start = if self.ar[1] == 1 { 1 } else { 0 };
        self.dfs(1, 0, start)
    }
}
 
fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input
        .split_ascii_whitespace()
        .map(|x| x.parse::<i64>().unwrap());
 
    let n = it.next().unwrap() as usize;
    let m = it.next().unwrap() as i32;
 
    let mut ar = vec![0i32; n + 1];
    for i in 1..=n {
        ar[i] = it.next().unwrap() as i32;
    }
 
    let mut adj = vec![Vec::new(); n + 1];
    for _ in 0..n.saturating_sub(1) {
        let x = it.next().unwrap() as usize;
        let y = it.next().unwrap() as usize;
        adj[x].push(y);
        adj[y].push(x);
    }
 
    let sol = Solution { n, m, ar, adj };
    let result = sol.solve();
 
    let stdout = io::stdout();
    let mut out = stdout.lock();
    writeln!(out, "{}", result).unwrap();
}