#include <iostream>

typedef long long ll ;

ll gcd( ll a, ll b )
{
    if ( b == 0 ) {
        return a ;
    }

    return gcd( b, a % b ) ;
}

ll lcm( ll a, ll b ) {
    return ( a * b ) / gcd( a, b ) ;
}

int main() 
{
    ll a = 0, b = 0 ;
    std::cin >> a >> b ;
    std::cout << lcm( a, b ) << std::endl ;

    return 0 ;
}
