use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
 
    let n: i64 = iter.next().unwrap().parse().unwrap();
    let m: i64 = iter.next().unwrap().parse().unwrap();
    let a: i64 = iter.next().unwrap().parse().unwrap();
 
    let temp: i64 = (n+a-1)/a;
    let temp2: i64 = (m+a-1)/a;
 
    println!("{}",temp*temp2);
}