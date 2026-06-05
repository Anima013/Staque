#include <iostream>
#include "Staque.h"
#include <random>
int main() {
    std::default_random_engine dre;
    std::uniform_int_distribution<int> dis(1, 100);
    Staque S;
    for (int i = 0; i < 50; ++i) {
        int val = dis(dre);
        S.push(val);
    }

    // Add elements
    std::cout << "Push test:\n"
              << S << "\n\n";
    
    // delete 10 even and 10 odd elements
    std::cout << "Deleting 10 even and 10 odd elements:\n";
    S.deleteElements(10, 0, 0);
    S.deleteElements(0, 10, 0);
    std::cout << S << "\n\n";

    // Delete 20 odd elements
    std::cout << "Deleting 20 odd elements:\n";
    S.deleteElements(0, 20, 0);
    std::cout << S << "\n\n";

    // Delete 30 elements with LIFO
    std::cout << "Deleting 30 elements with LIFO:\n";
    S.deleteElements(0, 0, 30);
    std::cout << S << "\n\n";

    return 0;
}