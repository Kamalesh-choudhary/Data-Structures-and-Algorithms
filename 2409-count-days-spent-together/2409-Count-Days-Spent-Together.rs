struct MonthDay {
    month: usize,
    day: i32,
}

impl MonthDay {
    fn new(s: &str) -> Self {
        MonthDay {
            month: s[0..2].parse().unwrap(), 
            day: s[3..5].parse().unwrap(),   
        }
    }

    fn day_of_year(&self) -> i32 {
        const DAYS_BEFORE: [i32; 12] = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334];
        DAYS_BEFORE[self.month - 1] + self.day
    }
}

impl Solution {
    pub fn count_days_together(arrive_alice: String,leave_alice: String,arrive_bob: String,leave_bob: String) -> i32 {

        let start = MonthDay::new(&arrive_alice).day_of_year().max(MonthDay::new(&arrive_bob).day_of_year());
        let end = MonthDay::new(&leave_alice).day_of_year().min(MonthDay::new(&leave_bob).day_of_year());

        (end - start + 1).max(0)
    }
}