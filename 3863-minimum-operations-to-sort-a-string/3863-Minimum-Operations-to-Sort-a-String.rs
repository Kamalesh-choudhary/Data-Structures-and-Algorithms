impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let n = s.len();
        let s = s.as_bytes();

        let mut flag = true;
        for i in 0..n {
            if i>0 && s[i] < s[i-1] {
                flag = false;
                break;
            }
        }

        if flag {
            return 0;
        }

        if n==2 {
            return -1;
        }

        let mut minchar = b'z';
        let mut maxchar = b'a';
        
        for &ch in s {
            minchar = minchar.min(ch);
            maxchar = maxchar.max(ch);
        }

        if minchar == s[0] || maxchar == s[n-1] {
            return 1;
        }

        for i in 1..n-1{
            if s[i] == minchar || s[i] == maxchar {
                return 2;
            }
        }

        3
    }
}