use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
 
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let ar: Vec<i32> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut sum: i32 = 0;
    for i in 0..n{
        sum += ar[i];
    }
    println!("{:.12}",sum as f64/n as f64 );
 
}