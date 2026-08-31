use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
 
    for _ in 0..n{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut ar: Vec<i32> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
        ar.sort();
        let  sum: i32 = ar.iter().sum();
        let mut temp: i32 = 0;
        let mut count: i32 = 0;
        for i in (0..n).rev(){
            temp += ar[i];
            count += 1;
            if sum-temp < temp{
                println!("{}",count);
                return;
            }
        }
    }
}