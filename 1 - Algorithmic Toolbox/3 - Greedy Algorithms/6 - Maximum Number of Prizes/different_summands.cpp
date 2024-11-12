#include <iostream>
#include <vector>

using std::cin ;
using std::cout ;
using std::endl ;
using std::vector ;

vector<int> different_summands( int n )
{
    vector<int> nums ;
    if ( n == 2 ) {
        nums.push_back(n) ;
        return nums ;
    }

    int a = 1 ;
    while ( a <= n ) {
        nums.push_back(a) ;
        n -= a ;
        a++ ;
    }
    nums[nums.size() - 1] += n ;

    return nums ;
}

int main()
{
    int n ;
    cin >> n ;

    vector<int> nums = different_summands( n ) ;
    
    cout << nums.size() << endl ;
    for ( auto & num : nums ) {
        cout << num << " " ;
    }
    cout << endl ;

    return 0 ;
}