#include <iostream>
#include <random>
#include <thread>
#include <chrono>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> temp_dist(20.0, 30.0); // 20°C - 30°C

    for (int i = 0; i < 5; ++i) { // 5 readings
        double temperature = temp_dist(gen);
        std::cout << "Current temperature: " << temperature << " °C\n";
        std::this_thread::sleep_for(std::chrono::seconds(1)); // wait 1 second
    }

    return 0;
}
