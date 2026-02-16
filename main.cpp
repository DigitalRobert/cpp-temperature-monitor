#include <iostream>
#include <random>

int main() {
    // magical sensor simulation
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> temp_dist(20.0, 30.0); // 20°C - 30°C

    double temperature = temp_dist(gen);

    std::cout << "Current temperature: " << temperature << " °C\n";

    return 0;
}
