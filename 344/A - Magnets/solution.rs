use std::io;
use std::cmp;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut ans: i32 = 1;
    let mut left: i32 = 0;
    let mut right: i32 = 0;
    for _ in 0..n{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let  string = input.trim();
        if string == "10"{
            left += 1;
            if right != 0{
                right = 0;
                ans += 1;
            }
        }
        else if string == "01"{
            right += 1;
            if left != 0{
                left = 0;
                ans += 1;
            }
        }
    }
    println!("{}",ans);
}
 