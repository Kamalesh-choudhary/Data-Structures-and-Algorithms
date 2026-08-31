use std::io::{self, Read};
 
fn main(){
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    
    let mut iter = input.split_whitespace();
 
    let n: usize = iter.next().unwrap().parse().unwrap();
 
    let vector: Vec<i32> = (0..n)
        .map(|_| iter.next().unwrap().parse().unwrap())
        .collect();
 
    let mut last = vector.len()-1;
    let mut first = 0;
    let mut sereja = 0;
    let mut dima = 0;
    
    let mut counter = 0;
 
    while first <= last{
        if counter&1 == 0{
            if vector[first] > vector[last]{
                sereja += vector[first];
                first += 1;
            }
            else{
                sereja += vector[last];
                if last == 0{
                    break;
                }
                last -= 1;
 
            }
        }
        else{
            if vector[first] > vector[last]{
                dima += vector[first];
                first += 1;
            }
            else{
                dima += vector[last];
                if last == 0{
                    break;
                }
                last -= 1;
 
            }
        }
        counter += 1;
    }
    println!("{sereja} {dima}");    
}