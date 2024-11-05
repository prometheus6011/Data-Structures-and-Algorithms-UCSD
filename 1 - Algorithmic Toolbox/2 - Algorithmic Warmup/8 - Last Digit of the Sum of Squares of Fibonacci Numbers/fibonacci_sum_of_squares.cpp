#include <iostream>

typedef long long ll ;

ll fib_sum_squares( ll fib_idx ) 
{
    fib_idx %= 60 ;

    if ( fib_idx <= 1 ) {
        return fib_idx ;
    }

    int curr = 1 ;
    int prev = 0 ;
    int temp = 0 ;
    ll sum = 1 ;

    for ( int i = 1; i < fib_idx; i++ ) {
        temp = curr ;
        curr = (curr + prev) % 10 ;
        prev = temp ;
        sum += (curr * curr) ;
    }

    return sum % 10 ;
}


int main()
{
    ll fib_idx = 0 ;
    std::cin >> fib_idx ;

    std::cout << fib_sum_squares( fib_idx ) << std::endl ;

    return 0 ;
}