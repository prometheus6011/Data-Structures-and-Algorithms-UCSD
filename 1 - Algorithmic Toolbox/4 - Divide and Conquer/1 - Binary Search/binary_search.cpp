#include <iostream>
#include <vector>

using std::cout ;
using std::endl ;
using std::cin ;
using std::vector ;

vector<int> binary_search( int n, vector<int> nums, int k, vector<int> search )
{
    vector<int> res(k, -1) ;
    for ( int i = 0; i < k; i++ ) {
        int left = 0 ;
        int right = n - 1 ;

        while ( left <= right ) {
            int mid = left + (right - left) / 2 ;

            if ( nums[mid] == search[i] ) {
                res[i] = mid ;
                break ;
            }

            if ( nums[mid] > search[i] ) {
                right = mid - 1 ;
            } else {
                left = mid + 1 ;
            }
        }
    }

    return res ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;

    for ( int i = 0; i < n; i++ ) {
        cin >> nums[i] ;
    }

    int k = 0 ;
    cin >> k ;
    vector<int> search(k) ;
    for ( int i = 0; i < k; i++ ) {
        cin >> search[i] ;
    }

    vector<int> res = binary_search( n, nums, k, search ) ;
    for ( auto & r : res ) {
        cout << r << " " ;
    }
    cout << endl ;

    return 0 ;
}
