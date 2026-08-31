use std::io;
 
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let  result = input.trim().split("WUB").filter(|s| !s.is_empty()).collect::<Vec<&str>>().join(" ");
    println!("{}",result);
}