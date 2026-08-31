use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let temp: i64 = input.trim().parse().unwrap();
    if temp%2 == 0{
        println!("{}",temp/2);
    }
    else{
        println!("{}",(temp+1)/2*-1);
    }
}