use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let _n: usize = input.trim().parse().unwrap();
    
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let mut ar: Vec<i32> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
    ar.sort();
    for x in &ar{
        print!("{} ",x);
    }
    println!("");
}       