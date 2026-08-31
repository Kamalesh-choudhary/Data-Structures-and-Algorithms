use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let ar: Vec<i32> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
    let mut ans = vec![0;n+1];
    for i in 1..n+1{
        ans[ar[i-1] as usize] = i as i32;
    }
    ans[1..].iter().for_each(|x| print!("{} ", x));
    println!("");
}