use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();
    let mut count : i32 = 0;
    for _ in 0..t{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let s = input.trim();
 
        if s=="++X" || s =="X++"{
            count += 1;
        }
        else{
            count -= 1;
        }
    }
    println!("{}",count);
}