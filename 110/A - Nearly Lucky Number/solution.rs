use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let string = input.trim();
    let mut first: i32 = 0;
    let mut second: i32 = 0; 
    for ch in string.chars(){
        if ch == '4'{
            first += 1;
        }
        else if ch == '7'{
            second += 1;
        }
    }
    let temp: i32 = first+second;
    if temp == 4 || temp ==7{
        println!("YES");
    }
    else{
        println!("NO");
    }
}