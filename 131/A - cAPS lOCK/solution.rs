use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let string: String = input.trim().to_string();
    
    if string.chars().skip(1).all(|c| c.is_uppercase()){
        let result: String = string.chars().map(|c| {
            if c.is_lowercase(){
                c.to_uppercase().to_string()
            }
            else{
                c.to_lowercase().to_string()
            }
        }).collect();
        println!("{}",result);
    }
    else{
        println!("{}",string);
    }
    
}