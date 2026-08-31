use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();
 
    for _ in 0..t{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut n: i64 = input.trim().parse().unwrap();
        let mut two_count: i32 = 0;
        let mut three_count: i32 = 0;
        while n%2 == 0{
            n /= 2;
            two_count += 1;
        }
        while n%3 == 0{
            n /= 3;
            three_count += 1;
        }
        if n==1 && two_count <= three_count{
            println!("{}",2*three_count-two_count);
        }
        else{
            println!("{}",-1);
        }
    }
}