use std::io;
use std::cmp;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut ans: i32 = 0;
    let mut max_capacity: i32 = 0;
    for _ in 0..n{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
 
        let  a: i32 = iter.next().unwrap().parse().unwrap();
        let  b: i32 = iter.next().unwrap().parse().unwrap();
 
        max_capacity -= a;
        max_capacity += b;
        ans = cmp::max(ans,max_capacity);
 
    }
    println!("{}",ans);
}