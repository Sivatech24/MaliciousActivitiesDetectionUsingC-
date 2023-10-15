#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate the mean of a vector
double mean(const std::vector<double>& data) {
    double sum = 0;
    for (const double& value : data) {
        sum += value;
    }
    return sum / data.size();
}

// Function to calculate the standard deviation of a vector
double standardDeviation(const std::vector<double>& data, double mean) {
    double sum = 0;
    for (const double& value : data) {
        sum += (value - mean) * (value - mean);
    }
    return std::sqrt(sum / data.size());
}

// Function to detect abnormal activity using Z-score
bool detectAbnormalActivity(const std::vector<double>& data, double threshold) {
    double dataMean = mean(data);
    double dataStdDev = standardDeviation(data, dataMean);
    if (dataStdDev == 0) {
        return false; // Avoid division by zero
    }
    double zScore = (data.back() - dataMean) / dataStdDev;
    return std::abs(zScore) > threshold;
}

int main() {
    std::vector<double> cpuUsageData;

    // Simulate a history of CPU usage data (you should replace this with real data)
    cpuUsageData = {20.0, 21.0, 22.0, 25.0, 30.0, 120.0, 22.0, 21.0, 22.0, 25.0};

    double anomalyThreshold = 2.0; // You can adjust this threshold based on your system's characteristics

    bool isAbnormal = detectAbnormalActivity(cpuUsageData, anomalyThreshold);

    if (isAbnormal) {
        std::cout << "Abnormal activity detected!" << std::endl;
    } else {
        std::cout << "No abnormal activity detected." << std::endl;
    }

    return 0;
}
