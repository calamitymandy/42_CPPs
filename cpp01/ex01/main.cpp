#include "Zombie.hpp"

int main() {
    int N = 7;
    int i = 0;

    Zombie* horde = zombieHorde(N, "ZoOoMmbiiiEee")
    while (i < N) {
        horde[i].announce();
        i++;
    }
    // Deallocate the entire array at once
    delete[] horde;
    return 0;
}