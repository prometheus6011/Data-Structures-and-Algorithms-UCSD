#include <iostream>

int fibonacci_number( int n )
{
    if ( n <= 1 ) {
        return n ;
    }

    int prev = 0 ;
    int curr = 1 ;

    for ( int i = 1; i < n; i++ ) {
        int temp = prev ;
        prev = curr ;
        curr += temp ;
    }

    return curr ;
}

int main()
{
    int n = 0 ;
    std::cin >> n ;

    std::cout << fibonacci_number( n ) << std::endl ;

    return 0 ;
}
