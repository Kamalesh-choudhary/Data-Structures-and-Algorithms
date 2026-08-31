use std::io;
use std::collections::HashMap;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let q: usize = input.trim().parse().unwrap();
 
    for _ in 0..q{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let n: usize = input.trim().parse().unwrap();
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
 
        let first: String = iter.next().unwrap().to_string();
        let second: String = iter.next().unwrap().to_string();
        let mut first_hmap: HashMap<String,i32> = HashMap::new();
        let mut second_hmap: HashMap<String,i32> = HashMap::new();
        for ch in first.chars(){
            *first_hmap.entry(ch.to_string()).or_insert(0) += 1;
        }
        for ch in second.chars(){
            *second_hmap.entry(ch.to_string()).or_insert(0) += 1;
        }
        if first_hmap == second_hmap{
            println!("YES");
        }
        else{
            println!("NO");
        }
    }
}   