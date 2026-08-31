use std::io;
use std::collections::HashMap;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let _n: usize = input.trim().parse().unwrap();
 
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let string: String = input.trim().to_string();
    let new_string = string.to_lowercase();
 
    let mut map = HashMap::new();
    for ch in new_string.chars(){
        *map.entry(ch).or_insert(0) += 1;
    }
    if map.len() == 26{
        println!("YES");
    }
    else{
        println!("NO");
    }
}