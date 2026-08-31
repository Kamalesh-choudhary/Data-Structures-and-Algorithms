use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut iter = input.split_whitespace();
 
    let  n: usize = iter.next().unwrap().parse().unwrap();
    let  t: usize = iter.next().unwrap().parse().unwrap();
 
    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let  string = input.trim();
    let mut vec_string: Vec<char> = string.chars().collect();
    for _ in 0..t{
        let mut i = 0;
        while i<n-1{
            if vec_string[i] == 'B' && vec_string[i+1] == 'G'{
                vec_string.swap(i,i+1);
                i+=2;
            }
            else{
                i+=1;
            }
        }
    }
    let result: String = vec_string.into_iter().collect();
    println!("{}",result);
}