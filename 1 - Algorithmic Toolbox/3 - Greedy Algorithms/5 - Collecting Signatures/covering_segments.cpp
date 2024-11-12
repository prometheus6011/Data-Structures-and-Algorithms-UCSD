#include <iostream>
#include <vector>
#include <algorithm>

using std::cout ;
using std::endl ;
using std::cin ;
using std::vector ;
using std::sort ;
using std::min ;

class Segment {
public:
    int start ;
    int end ;

    Segment(int a, int b) {
        start = a ;
        end = b ;
    }
} ;

vector<int> covering_segments(vector<Segment*>& segments) 
{
    vector<int> res ;
    
    auto comp = [](Segment* seg_1, Segment* seg_2) {
        return seg_1->end < seg_2->end ;
    } ;
    
    sort(segments.begin(), segments.end(), comp) ;
    
    int x = segments[0]->end ;
    res.push_back(x) ;
    
    for ( size_t i = 1; i < segments.size(); i++ ) {
        if ( x < segments[i]->start ) {
            x = segments[i]->end ;
            res.push_back(x) ;
        }
    }
    
    return res ;
}

int main() 
{
    int n = 0 ;
    cin >> n ;
    vector<Segment*> segments(n) ;
    
    int a = 0, b = 0 ;
    for ( int i = 0; i < n; i++ ) {
        cin >> a >> b ;
        segments[i] = new Segment(a, b) ;
    }
    
    vector<int> res = covering_segments(segments) ;
    
    cout << res.size() << endl ;
    for ( auto& r : res ) {
        cout << r << " " ;
    }
    cout << endl ;
    
    for ( auto& segment : segments ) {
        delete segment ;
    }
    
    return 0 ;
}