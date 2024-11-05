#include <iostream>
#include <vector>
typedef long long ll ;

ll sum_fibonacci( ll fib_idx ) 
{
    ll new_idx = fib_idx % 60 ;
    
    if ( new_idx <= 1 ) {
        return new_idx ;
    }

    int prev = 0 ;
    int curr = 1 ;
    int sum = 1 ;
    for ( ll i = 1; i < new_idx; i++ ) {
        int temp = curr ;
        curr = ( prev + curr ) % 10 ;
        prev = temp ;
        sum += curr ;
    }

    return sum % 10 ;
}

int main()
{
    ll fib_idx = 0 ;
    std::cin >> fib_idx ;

    std::cout << sum_fibonacci( fib_idx ) << std::endl ;

    return 0 ;
}
