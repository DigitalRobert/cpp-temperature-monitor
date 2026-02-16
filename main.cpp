#include <iostream>
#include <fstream>
#include <random>
#include <thread>
#include <chrono>
#include <string>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> temp_dist(20.0, 30.0);

    std::ofstream log_file("temperature.log", std::ios::app); // append mode
    if (!log_file) {
        std::cerr << "Cannot open temperature.log\n";
        return 1;
    }

    for (int i = 0; i < 5; ++i) {
        double temperature = temp_dist(gen);

        // Print to console
        std::cout << "Current temperature: " << temperature << " °C\n";

        // Write to file
        log_file << "Reading " << i+1 << ": " << temperature << " °C\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
