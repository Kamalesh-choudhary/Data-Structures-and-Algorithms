use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let string = input.trim();
    let target = "hello";
    let mut target_chars = target.chars();
    let mut current_target = target_chars.next();
 
    for ch in string.chars() {
        // If the input char matches the current letter we're looking for
        if Some(ch) == current_target {
            // Move to the next letter in "hello"
            current_target = target_chars.next();
        }
    }
    if current_target.is_none(){
        println!("YES");
    }
    else{
        println!("NO");
    }
}