impl Solution {
    pub fn defang_i_paddr(address: String) -> String {
        let mut ans = String::new();
        for ch in address.chars(){
            if ch == '.'{
                ans.push_str("[.]");
            }
            else{
                ans.push(ch);
            }
        }
        ans
    }
}