use std::io;
use std::cmp;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
 
    let n: usize = iter.next().unwrap().parse().unwrap();
    let m: usize = iter.next().unwrap().parse().unwrap();
 
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let mut ar: Vec<i32> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut ans = i32::MAX;
    ar.sort();
 
    for low in 0..=(m-n){
        let current_dif = ar[low+n-1]-ar[low];
        ans = cmp::min(ans,current_dif);
    }
    println!("{}",ans);
 
}