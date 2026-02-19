#include <iostream>
#include <thread>
#include <chrono>
#include <random>

// simulate temperature sensor
double read_temperature()
{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(18.0, 30.0);
    return dist(rng);
}

int main()
{
    int readings = 5;
    int interval_ms = 1000;

    std::cout << "Number of readings: ";
    std::cin >> readings;

    std::cout << "Interval (ms): ";
    std::cin >> interval_ms;

    std::cout << "\nStarting measurements...\n\n";

    for(int i = 0; i < readings; ++i)
    {
        double temp = read_temperature();
        std::cout << "Reading " << i+1 << ": " << temp << " C\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
    }

    std::cout << "\nFinished.\n";
}

