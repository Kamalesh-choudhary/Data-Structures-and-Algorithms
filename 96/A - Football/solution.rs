use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let string: String = input.trim().to_string();
    let mut zeroes: i32 = 0;
    let mut ones: i32 = 0;
 
    for ch in string.chars(){
        if ch == '0'{
            ones = 0;
            zeroes += 1;
        }
        else{
            zeroes = 0;
            ones += 1;
        }
        if ones == 7 || zeroes == 7{
            println!("YES");
            return;
        }
    }
    println!("NO");
}