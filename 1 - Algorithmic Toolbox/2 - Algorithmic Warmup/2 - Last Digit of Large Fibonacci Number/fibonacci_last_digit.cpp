#include <iostream>

int fib_last_digit( int n )
{
    if ( n <= 1 ) {
        return n ;
    }

    int prev = 0 ;
    int curr = 1 ;
    for ( int i = 1; i < n; i++ ) {
        int temp = prev % 10 ;
        prev = curr % 10 ;
        curr += temp ;
    }

    return curr % 10 ;
}

int main(  )
{
    int n = 0 ;
    std::cin >> n ;

    std::cout << fib_last_digit( n ) << std::endl ;

    return 0 ;
}
