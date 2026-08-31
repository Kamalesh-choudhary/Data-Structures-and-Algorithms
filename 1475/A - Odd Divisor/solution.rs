use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();
    for _ in 0..t{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let n: i64 = input.trim().parse().unwrap();
        if n&(n-1) == 0{
            println!("NO");
        }
        else{
            println!("YES");
        }
    }
}