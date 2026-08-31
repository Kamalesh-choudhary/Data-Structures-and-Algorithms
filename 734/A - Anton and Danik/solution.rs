use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let stirng = input.trim().to_string();
    let mut anton: i32 = 0;
    let mut danik: i32 = 0;
    for ch in stirng.chars(){
        if ch == 'A'{
            anton += 1;
        }
        else{
            danik += 1;
        }
    }
    if anton > danik{
        println!("Anton");
    }
    else if danik > anton{
        println!("Danik");
    }
    else{
        println!("Friendship");
    }
}