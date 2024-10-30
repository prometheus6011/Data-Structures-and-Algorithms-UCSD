#include <iostream>
#include <vector>
typedef long long ll ;

std::vector<ll> pisano( ll mod ) 
{
    std::vector<ll> pisano_period ;
    pisano_period.push_back( 0 ) ;
    pisano_period.push_back( 1 ) ;

    for ( ll i = 2; i <= mod * mod; i++ ) {
        if ( pisano_period[i - 1] == 1 && pisano_period[i - 2] == 0 && i != 2 ) {
            break ;
        }
        pisano_period.push_back( ( pisano_period[i - 1] + pisano_period[i - 2] ) % mod ) ;
    }
    
    return pisano_period ;
}

ll huge_fibonacci( ll idx, ll mod )
{
    std::vector<ll> pisano_period = pisano( mod ) ;
    ll new_mod = idx % ( pisano_period.size() - 2 ) ;

    return pisano_period[new_mod] ;
}

int main()
{
    ll fib_idx = 0, mod = 0 ;
    std::cin >> fib_idx >> mod ;

    std::cout << huge_fibonacci( fib_idx, mod ) << std::endl ;

    return 0 ;
}
