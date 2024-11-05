#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll ;

ll dot_product( std::vector<ll> & a, std::vector<ll> & b, int n )
{
    ll dotp = 0 ;

    sort( a.rbegin(), a.rend() ) ;
    sort( b.rbegin(), b.rend() ) ;

    for ( int i = 0; i < n; i++ ) {
        dotp += (a[i] * b[i]) ;
    }

    return dotp ;
}

int main()
{
    int n = 0 ;
    std::cin >> n ;
    std::vector<ll> a(n, 0), b(n, 0) ;

    for ( int i = 0; i < n; i++ ) {
        std::cin >> a[i] ;
    }

    for ( int i = 0; i < n; i++ ) {
        std::cin >> b[i] ;
    }

    std::cout << dot_product( a, b, n ) << std::endl ;

    return 0 ;
}