use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut n: i32 = input.trim().parse().unwrap();
    let mut count: i32 = 0;
 
    while n>0{
        if n>=100{
            n -= 100;
        }
        else if n>=20{
            n -= 20;
        }
        else if n>=10{
            n -= 10;
        }
        else if n>=5{
            n -= 5;
        }
        else{
            n -= 1;
        }
        count += 1;
    }
    println!("{}",count);
}