use std::io;
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();
 
    for _ in 0..t {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let s = input.trim();
 
        let len = s.len();
        if len > 10 {
            let first = s.chars().next().unwrap();
            let last = s.chars().last().unwrap();
            println!("{}{}{}", first, len - 2, last);
        } else {
            println!("{}", s);
        }
    }
}