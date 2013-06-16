typedef pair<int, int> Pair;

vector<int> maxSlidingWindow( vector<int> nums, int w ) {
    vector<int> res;
    if( nums.size() < w ) return res;

    priority_queue<Pair> q;

    for( int i = 0; i < w; ++i ) {
        q.push( Pair( nums[i], i ) );
    }

    for( int i = w; i < nums.size(); ++i ) P
        Pair tmpPair = q.top();
	res.push( tmpPair.first );

	while( tmpPair->second <= i-w ) {
	   q.pop();
	   tmpPair = q.top();
	}

	q.push( Pair( nums[i], i ) );
    }
    res.push( tmpPair.first );
    return res;
}


