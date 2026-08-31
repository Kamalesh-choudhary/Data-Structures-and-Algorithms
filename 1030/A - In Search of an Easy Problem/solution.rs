use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let  arr: Vec<i32> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
 
    for i in 0..n{
        if arr[i] == 1{
            println!("Hard");
            return;
        }
    }
    println!("Easy");
}