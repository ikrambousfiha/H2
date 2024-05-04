#include <iostream>
using namespace std;

int main() {
    int totalChickens = 100;
    int totalMoney = 100;
    int roosterPrice = 5;
    int henPrice = 3;

    // Solve the system of equations
    for (int roosters = 0; roosters <= totalMoney / roosterPrice; ++roosters) {
        for (int hens = 0; hens <= totalMoney / henPrice; ++hens) {
            int chicks = totalChickens - roosters - hens;
            int totalPrice = roosters * roosterPrice + hens * henPrice + chicks;
            if (totalPrice == totalMoney && chicks >= 0) {
                cout << "Roosters: " << roosters << ", Hens: " << hens << ", Chicks: " << chicks << endl;
                return 0; // Exit after finding the solution
            }
        }
    }

    cout << "No solution found." << endl;
    return 0;
}
