use std::io;
 
fn valid(chars: &str)->bool{
    let  year: Vec<char> = chars.chars().collect();
    let n: usize = year.len();
    for i in 0..n{
        for j in (i+1)..n{
            if year[i]== year[j]{
                return false;
            }
        }
    }
    return true;
}
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut year: i32 = input.trim().parse().unwrap();
    year += 1;
    loop {
        if valid(&year.to_string()){
            println!("{}",year);
            return;
        }
        else{
            year += 1;
        }    
    }
}