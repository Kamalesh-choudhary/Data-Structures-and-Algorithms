use std::io;
 
fn main(){
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();
    let mut count: i32 = 0;
 
    for _ in 0..t {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
 
        let a: i32 = iter.next().unwrap().parse().unwrap();
        let b: i32 = iter.next().unwrap().parse().unwrap();
        let c: i32 = iter.next().unwrap().parse().unwrap();
 
        if (a+b+c) >= 2{
            count+= 1;
        }
    }
    println!("{}",count);
 
}