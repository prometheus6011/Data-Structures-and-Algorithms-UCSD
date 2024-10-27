#include <iostream>
#include <vector>

int main()
{
    int n = 0 ;

    std::cin >> n ;
    std::vector<int> a(n) ;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i] ;
    }

    int max_idx_1 = -1 ;
    for (int i = 0; i < n; i++) {
        if (max_idx_1 == -1 || a[i] > a[max_idx_1]) {
            max_idx_1 = i ;
        }
    }

    int max_idx_2 = -1 ;
    for (int i = 0; i < n; i++) {
        if (i != max_idx_1 && (max_idx_2 == -1 || a[i] > a[max_idx_2])) {
            max_idx_2 = i ;
        }
    }

    std::cout << (long long)a[max_idx_1] * (long long)a[max_idx_2] << std::endl ;

    return 0 ;
}
