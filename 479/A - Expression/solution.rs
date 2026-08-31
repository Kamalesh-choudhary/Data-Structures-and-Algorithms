use std::io;
use std::cmp;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let a: i32 = input.trim().parse().unwrap();
 
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let b: i32 = input.trim().parse().unwrap();
 
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let c: i32 = input.trim().parse().unwrap();
 
    let mut ans: i32 = -1;
    ans = cmp::max(a*b*c,cmp::max(a+b+c,cmp::max(a*(b+c),cmp::max((a+b)*c,cmp::max(a+(b*c),cmp::max((a*b)+c,ans))))));
    println!("{}",ans);
 
}