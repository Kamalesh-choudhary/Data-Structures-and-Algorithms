use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
 
    let n: i64 = iter.next().unwrap().parse().unwrap();
    let k: i64 = iter.next().unwrap().parse().unwrap();
 
    let odd_count = (n+1)/2;
    
    if k > odd_count{
        println!("{}",2*(k-odd_count));
    }
    else{
        println!("{}",2*k-1);
    }
}