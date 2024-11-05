#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

double max_value_of_loot( int num_items, int knapsack_capacity, std::vector<int> & values, std::vector<int> & weights )
{
    double res = 0.0 ;
    std::vector<std::pair<double, std::pair<int, int> > > mp(num_items) ;

    for ( int i = 0; i < num_items; i++ ) {
        mp[i].first = (double)values[i] / (double)weights[i] ;
        mp[i].second = std::make_pair(values[i], weights[i]) ;
    }

    auto comp = []( const std::pair<double, std::pair<int, int> > & a, const std::pair<double, std::pair<int, int> > & b ) {
        return a.first > b.first ;
    } ;

    std::sort( mp.begin(), mp.end(), comp ) ;

    int i = 0 ;
    while ( knapsack_capacity != 0 && i != num_items ) {
        std::pair<double, std::pair<int, int> > current_item = mp[i] ;
        if ( current_item.second.second <= knapsack_capacity) {
            knapsack_capacity -= current_item.second.second ;
            res += current_item.second.first ;
        } else {
            res += current_item.first * knapsack_capacity ;
            knapsack_capacity = 0 ;
        }
        i++ ;
    }

    return res ;
}

int main()
{
    int num_items = 0, capacity = 0 ;
    std::cin >> num_items >> capacity ;
    std::vector<int> values(num_items, 0), weights(num_items, 0) ;

    for ( int i = 0; i < num_items; i++ ) {
        std::cin >> values[i] >> weights[i] ;
    }

    
    std::cout << std::fixed << std::setprecision(4) << max_value_of_loot( num_items, capacity, values, weights ) << std::endl ;

    return 0 ;
}