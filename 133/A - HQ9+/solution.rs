use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let string: String = input.trim().to_string();
 
    for ch in string.chars(){
        if ch == 'H' || ch == 'Q' || ch == '9'{
            println!("YES");
            return;
        }
    }
    println!("NO");
}