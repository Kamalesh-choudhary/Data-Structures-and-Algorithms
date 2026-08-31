use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let first = input.trim().to_string();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let second = input.trim();
    for (c1,c2) in first.chars().zip(second.chars()){
        if c1 == c2{
            print!("{}",'0');
        }
        else{
            print!("{}",'1');
        }
    }
    println!("");
}