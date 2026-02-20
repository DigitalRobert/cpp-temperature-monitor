#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <fstream>
#include <iomanip>
#include <ctime>

// simulate temperature sensor
double read_temperature()
{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(18.0, 30.0);
    return dist(rng);
}

// get current timestamp
std::string current_time()
{
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm *tm_ptr = std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(tm_ptr, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

int main()
{
    int readings;
    int interval_ms;
    double alarm_threshold = 28.0; // adjustable threshold

    std::cout << "Number of readings: ";
    std::cin >> readings;

    std::cout << "Interval (ms): ";
    std::cin >> interval_ms;

    std::cout << "Alarm threshold (C): ";
    std::cin >> alarm_threshold;

    std::ofstream log("temperature_log.txt", std::ios::app);

    std::cout << "\nStarting measurements...\n\n";

    for(int i = 0; i < readings; ++i)
    {
        double temp = read_temperature();
        std::string time = current_time();

        // Console + file output
        std::cout << time << " | " << temp << " C";
        log << time << " | " << temp << " C";

        // Check for alarm
        if(temp >= alarm_threshold)
        {
            std::cout << "  <-- WARNING: High temperature!";
            log << "  <-- WARNING: High temperature!";
        }

        std::cout << "\n";
        log << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(interval_ms));
    }

    std::cout << "\nFinished. Data saved to temperature_log.txt\n";
}
