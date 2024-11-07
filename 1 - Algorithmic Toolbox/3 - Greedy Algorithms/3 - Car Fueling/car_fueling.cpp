#include <iostream>
#include <vector>

using std::cout ;
using std::cin ;
using std::endl ;
using std::vector ;

typedef long long ll ;

ll car_fueling( ll distance, ll full_tank, ll n, vector<ll> & stops )
{
    if ( full_tank > distance ) {
        return 0 ;
    }

    ll num_stops = 0 ;
    stops.push_back(distance) ;
    ll tank_left = full_tank ;

    ll prev_stop = 0 ;
    for ( ll i : stops ) {
        ll dist = i - prev_stop ;

        if ( dist <= tank_left ) {
            tank_left -= dist ;
        } else {
            if ( dist > full_tank ) {
                return -1 ;
            } else {
                num_stops++ ;
                tank_left = full_tank - dist ;
            }
        }

        prev_stop = i ;
    }

    return num_stops ;
}

int main()
{
    ll distance = 0, full_tank = 0, n = 0 ;
    cin >> distance >> full_tank >> n ;
    vector<ll> stops(n) ;

    for ( int i = 0; i < n; i++ ) {
        cin >> stops[i] ;
    }

    cout << car_fueling( distance, full_tank, n, stops ) << endl ;

    return 0 ;
}
