use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
 
    for i in 0..n{
        if ((i+1)%2) != 0{
            print!("I hate ",);
        }
        else{
            print!("I love ");
        }
        if i+1 == n{
            print!("it ");
        }
        else{
            print!("that ");
        }
    }
    println!("");
}