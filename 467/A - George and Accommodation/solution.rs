use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut count: i32 = 0;
    for _ in 0..n{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
 
        let p: i32 = iter.next().unwrap().parse().unwrap();
        let q: i32 = iter.next().unwrap().parse().unwrap();
 
        if (q-p)>=2{
            count += 1;
        }
    }
    println!("{}",count);
}