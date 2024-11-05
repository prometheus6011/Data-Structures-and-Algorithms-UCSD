#include <iostream>

int money_change( int change ) 
{
    int num_coins = 0 ;

    num_coins += change / 10 ;
    change %= 10 ;

    num_coins += change / 5 ;
    change %= 5 ;

    num_coins += change ;

    return num_coins ;
}

int main()
{
    int change = 0 ;
    std::cin >> change ;

    std::cout << money_change( change ) << std::endl ;

    return 0 ;
}