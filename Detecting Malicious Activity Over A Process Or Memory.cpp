#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>

// Function to check if a process is running by name
bool isProcessRunning(const std::string& processName) {
    std::string command = "ps aux | grep " + processName + " | grep -v grep";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return false;
    }

    char buffer[128];
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr) {
            pclose(pipe);
            return true;
        }
    }

    pclose(pipe);
    return false;
}

int main() {
    std::string targetProcessName = "malicious_process_name"; // Replace with the name of the process you want to check

    if (isProcessRunning(targetProcessName)) {
        std::cout << "Malicious process (" << targetProcessName << ") is running." << std::endl;
    } else {
        std::cout << "No malicious process found." << std::endl;
    }

    return 0;
}
