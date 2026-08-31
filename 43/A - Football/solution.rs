use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut team1: String = String::new();
    let mut team2: String = String::new();
    let mut first: u32 = 0;
    let mut second: u32 = 0;
    for _ in 0..n{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let string: String = input.trim().to_string();
        if team1 == ""{
            team1.push_str(&string);
            first += 1;
        }
        else if team2 == "" && string != team1{
            team2.push_str(&string);
            second += 1;
        }
        else{
            if string == team1{
                first += 1;
            }
            else{
                second += 1;
            }
        }
    }
    if first > second{
        println!("{}",team1);
    }  
    else{
        println!("{}",team2);
    }
}