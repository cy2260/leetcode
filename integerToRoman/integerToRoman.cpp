class Solution {
public:
    string intToRoman(int num) {
	string res = "";
	map<int, char> m;
	m[1]    = 'I';
	m[5]    = 'V';
	m[10]   = 'X';
	m[50]   = 'L';
	m[100]  = 'C';
	m[500]  = 'D';
	m[1000] = 'M';

	int scale = 1000; //max scale 3999
	
	while( num && scale ) {
	    int temp = num/scale;

	    if( temp > 0 && temp <= 3 ) {
	        res.append( temp, m[scale] );
	    }
	    else if( temp == 4 ) {
	        res.append( 1, m[scale] );
		res.append( 1, m[5*scale] );
	    }
	    else if( temp == 5 ) {
	        res.append( 1, m[5*scale] );
	    }
	    else if( temp > 5 && temp < 9 ) {
	        res.append( 1, m[5*scale] );
	        res.append( temp-5, m[scale] );
            }
	    else {
	        res.append( 1, m[10*scale] );
	    }

	    num   = num % scale;
	    scale = scale / 10;
	}
        return res;
    }
};
