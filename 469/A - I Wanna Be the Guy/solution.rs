use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let arr1: Vec<i32> = input.split_whitespace().skip(1).map(|x| x.parse().unwrap()).collect();
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let arr2: Vec<i32> = input.split_whitespace().skip(1).map(|x| x.parse().unwrap()).collect();
    let mut checker = vec![false;n+1];
    let x: usize = arr1.len();
    let y: usize = arr2.len();
 
    for i in 0..x{
        if checker[arr1[i] as usize] == false{
            checker[arr1[i] as usize] = true;
        }
    }
    for j in 0..y{
        if checker[arr2[j] as usize] == false{
            checker[arr2[j] as usize] = true;
        }
    }
 
    for i in 1..n+1{
        if checker[i] == false{
            println!("Oh, my keyboard!");
            return;
        }
    }
    println!("I become the guy.");
}