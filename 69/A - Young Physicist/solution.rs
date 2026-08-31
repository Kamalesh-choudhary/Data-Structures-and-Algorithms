use std::io;
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut x_axis: i32 = 0;
    let mut y_axis: i32 = 0;
    let mut z_axis: i32 = 0;
    for _ in 0..n{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
 
        let x: i32 = iter.next().unwrap().parse().unwrap();
        let y: i32 = iter.next().unwrap().parse().unwrap();
        let z: i32 = iter.next().unwrap().parse().unwrap();
 
        x_axis += x;
        y_axis += y;
        z_axis += z;
    }
    if x_axis==0 && y_axis==0 && z_axis==0{
        println!("YES");
    }
    else{
        println!("NO");
    }
}