use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
 
    let mut n = iter.next().unwrap().to_string();
    let k: usize = iter.next().unwrap().parse().unwrap();
 
    for _ in 0..k{
        let last = n.chars().last().unwrap();
        let temp: i32 = n.parse().unwrap();
        if last == '0'{
            n = (temp/10).to_string();
        }
        else{
            n = (temp-1).to_string();
        }
    }
    println!("{}",n);
}