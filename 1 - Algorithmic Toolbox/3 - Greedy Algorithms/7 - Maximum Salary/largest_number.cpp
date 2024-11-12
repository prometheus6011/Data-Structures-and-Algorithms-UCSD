#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin ;
using std::cout ;
using std::endl ;
using std::vector ;
using std::string ;
using std::to_string ;
using std::sort ;

string largest_number( int n, vector<int> & nums )
{
    string res ;
    vector<string> str_nums(n) ;

    for ( int i = 0; i < n; i++ ) {
        str_nums[i] = to_string(nums[i]) ;
    }

    auto comp = []( string & a, string & b ) {
        return a + b > b + a ;
    } ;

    sort(str_nums.begin(), str_nums.end(), comp) ;

    for ( const auto & s : str_nums ) {
        res += s ;
    }

    return res ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n, 0) ;

    for ( int i = 0; i < n; i++ ) {
        cin >> nums[i] ;
    }

    cout << largest_number( n, nums ) << endl ;

    return 0 ;
}