vector<int> maxSlidingWindow( vector<int> nums, int w ) {
    vector<int> res;
    if( nums.size() < w ) return res;

    priority_queue<Pair> q;

