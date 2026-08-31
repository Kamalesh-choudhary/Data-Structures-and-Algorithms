use std::io;
 
fn main(){
    let mut s1 = String::new();
    let mut s2 = String::new();
    io::stdin().read_line(&mut s1).unwrap();
    io::stdin().read_line(&mut s2).unwrap();
    let original = s1.trim();
    let reversed = s2.trim();
 
    if original.chars().rev().eq(reversed.chars()){
        println!("YES");
    }
    else{
        println!("NO");
    }
    
}