class MyCalendar {
    vector<pair<int,int>> booked;
public:
    MyCalendar() {

    }
    
    bool book(int startTime, int endTime) {
        for(auto &[s,e] : booked) {
            if(e>startTime && endTime>s) {
                return false;
            }
        }
        pair<int,int> calendarPair(startTime,endTime);
        booked.push_back(calendarPair);
        return true;
    }
};
