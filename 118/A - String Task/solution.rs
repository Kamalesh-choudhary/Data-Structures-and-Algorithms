use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let  string = input.trim();
    let mut ans = String::new();
    let vowels = ['A','O','Y','E','U','I','a','o','y','e','u','i'];
 
    for c in string.chars(){
        if vowels.contains(&c){
            continue;
        }
        else{
            ans.push_str(".");
            if c.is_lowercase(){
                ans.push(c);
            }
            else{
                ans.push(c.to_lowercase().next().unwrap());
            }
        }
    }
    println!("{}",ans);
}