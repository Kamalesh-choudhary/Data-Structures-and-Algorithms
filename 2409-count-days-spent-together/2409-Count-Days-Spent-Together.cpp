class MonthDay {
public:
    int month,day;
    MonthDay(const string& s){
        month = stoi(s.substr(0,2));
        day = stoi(s.substr(3,2));
    }
    int dayOfYear() const {
        static const int daysBefore[] = {0, 31, 59, 90, 120, 151,181, 212, 243, 273, 304, 334};
        return daysBefore[month - 1] + day;
    }
};

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(MonthDay(arriveAlice).dayOfYear(), MonthDay(arriveBob).dayOfYear());
        int end   = min(MonthDay(leaveAlice).dayOfYear(),  MonthDay(leaveBob).dayOfYear());

        return max(0, end - start + 1);
    }
};