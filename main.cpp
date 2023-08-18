#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

// Define the traffic signal states
enum TrafficSignalState {
    RED,
    YELLOW,
    GREEN
};

// Function to display the current state of the traffic signals
void displayTrafficSignals(TrafficSignalState signalState) {
    switch (signalState) {
        case RED:
            cout << "RED" << endl;
            break;
        case YELLOW:
            cout << "YELLOW" << endl;
            break;
        case GREEN:
            cout << "GREEN" << endl;
            break;
    }
}

// Function to update the traffic signal states based on a predefined logic
void updateTrafficSignals(TrafficSignalState& signalState) {
    switch (signalState) {
        case RED:
            signalState = GREEN;
            break;
        case GREEN:
            signalState = YELLOW;
            break;
        case YELLOW:
            signalState = RED;
            break;
    }
}

int main() {
    TrafficSignalState signalState = RED;
    bool isRunning = true;

    while (isRunning) {
        displayTrafficSignals(signalState);

        // Wait for a specific duration before updating the signal state
        this_thread::sleep_for(seconds(5));

        updateTrafficSignals(signalState);
}
return 0;
}