use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: i32 = input.trim().parse().unwrap();
    
    let lucky_numbers: Vec<i32> = vec![4,7,44,47,74,77,444,447,474,477,744,747,774,777];
    if lucky_numbers.iter().any(|&lucky| n%lucky ==0){
        println!("YES");
    }
    else{
        println!("NO");
    }
}