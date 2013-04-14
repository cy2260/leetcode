
struct Interval {
    int start;
    int end;
public:
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator curr = intervals.begin();
        while( curr != intervals.end() ) {
            if( newInterval.end < curr->start ) {
                //just need to insert before the curr position and return
                intervals.insert( curr, newInterval );
                return intervals;
            }
            else if( newInterval.start > curr->end ) {
                //b/c it assumes that no overlapped interval, then just forward the iter
                ++curr;
            }
            else {
                //modify newInterval so that it can include the overlapped one
                //try to insert newInterval in next iteration and delete current one
                newInterval.start = min( newInterval.start, curr->start );
                newInterval.end   = max( newInterval.end,   curr->end   );
                intervals.erase( curr );
            }
        }
        //if newInterval's start is larger than the last interval's end, append it to the end
        intervals.push_back( newInterval );
        return intervals;
    }
};

