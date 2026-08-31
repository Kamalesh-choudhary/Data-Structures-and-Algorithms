use std::io::{self, Write, stdout};
 
fn main(){
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let t: usize = input.trim().parse().unwrap();
    let mut writer = io::BufWriter::new(stdout().lock());
    
    for _ in 0..t{
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
 
        let n: usize = iter.next().unwrap().parse().unwrap();
        let q: usize = iter.next().unwrap().parse().unwrap();
 
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let string: Vec<char> = input.trim().chars().collect();
 
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let ar: Vec<i64> = input.split_whitespace().map(|x| x.parse().unwrap()).collect();
        
        let count_B: i64 = string.iter().filter(|&&c| c == 'B').count() as i64;
 
        for &a in &ar{
            if count_B == 0 {
                writeln!(writer, "{}", a).unwrap();
            } else {
                let mut curr = a;
                let mut ans = 0i64;
                
                while curr > 0 {
                    for &ch in &string {
                        if curr == 0 {
                            break;
                        }
                        ans += 1;
                        if ch == 'A' {
                            curr -= 1;
                        } else {
                            curr /= 2;
                        }
                    }
                }
                
                writeln!(writer, "{}", ans).unwrap();
            }
        }
    }
    writer.flush().unwrap();
}