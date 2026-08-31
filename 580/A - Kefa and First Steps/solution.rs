use std::io;
use std::cmp;
 
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
 
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let ar: Vec<i32> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut ans: i32 = 1;
    let mut count: i32 = 1;
 
    for i in 0..n-1{
        if ar[i] <= ar[i+1]{
            count += 1;
        }
        else{
            count = 1;
        }
        ans = cmp::max(ans,count); 
    }
    println!("{}",ans);
}