#include <iostream>
#include <vector>
typedef long long ll ;

ll sum_fibonacci( ll start_fib_idx, ll end_fib_idx )
{
    int new_start_idx = start_fib_idx % 60 ;
    int new_end_idx = end_fib_idx % 60 ;

    if ( new_start_idx > new_end_idx ) {
        new_end_idx += 60 ;
    }

    std::vector<int> period(60, 0) ;
    period[1] = 1 ;

    for ( int i = 2; i < 60; i++ ) {
        period[i] = (period[i - 1] + period[i - 2]) % 10 ;
    }

    int sum = 0 ;
    for ( int i = new_start_idx; i <= new_end_idx; i++ ) {
        sum += period[i % 60] ;
        sum %= 10 ;
    }

    return sum % 10 ;
}

int main()
{
    ll start_fib_idx = 0, end_fib_idx = 0 ;
    std::cin >> start_fib_idx >> end_fib_idx ;

    std::cout << sum_fibonacci( start_fib_idx, end_fib_idx ) << std::endl ;

    return 0 ;
}
