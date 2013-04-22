
class Solution {
public:
    struct WordNode {
        string word;
        int    times;
        WordNode( string& s, int t ) { word = s; times = t; }
    };
    
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<WordNode> liveNodes;
        liveNodes.push( WordNode( start, 1 ) );
        
        unordered_set<string> wordsExpanded;
        
        while( !liveNodes.empty() ) {
            WordNode curNode = liveNodes.front();
            liveNodes.pop();
            
            if( curNode.word == end ) return curNode.times;
            
            vector<string> neighbors = findNeighbors( curNode.word, dict, wordsExpanded );
            
            for( int i = 0; i < neighbors.size(); ++i ) {
                liveNodes.push( WordNode( neighbors[i], curNode.times+1) );
            }
        }
         
        return 0;
    }
    
    vector<string> findNeighbors( string& curWord, unordered_set<string> &dict, unordered_set<string>& wordsExpanded ) {
        vector<string> neighbors;
        for( int i = 0; i < curWord.size(); ++i ) {
            string tempWord( curWord );
            for( char c = 'a'; c <= 'z'; ++c ) {
                tempWord[i] = c;
                if( dict.find( tempWord ) != dict.end() && wordsExpanded.find( tempWord ) == wordsExpanded.end() ) {
                    neighbors.push_back( tempWord );
                    wordsExpanded.insert( tempWord );
                }
            }
        }
        return neighbors;
    }
