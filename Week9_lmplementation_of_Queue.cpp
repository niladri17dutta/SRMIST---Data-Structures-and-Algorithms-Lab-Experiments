#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to calculate waiting time for each process
void calculateWaitingTime(vector<int> burstTimes, vector<int> &waitingTimes, int quantum) {
    int n = burstTimes.size();
    queue<int> q;
    vector<int> remainingBurstTimes = burstTimes;
    int time = 0;

    // Initial fill of the queue
    for (int i = 0; i < n; ++i) {
        q.push(i);
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        if (remainingBurstTimes[idx] > quantum) {
            remainingBurstTimes[idx] -= quantum;
            time += quantum;
            q.push(idx);
        } else {
            time += remainingBurstTimes[idx];
            waitingTimes[idx] = time - burstTimes[idx];
            remainingBurstTimes[idx] = 0;
        }
    }
}

// Function to calculate turnaround time for each process
void calculateTurnaroundTime(const vector<int> &burstTimes, const vector<int> &waitingTimes, vector<int> &turnaroundTimes) {
    int n = burstTimes.size();
    for (int i = 0; i < n; ++i) {
        turnaroundTimes[i] = burstTimes[i] + waitingTimes[i];
    }
}

// Function to print the results
void printResults(const vector<int> &burstTimes, const vector<int> &waitingTimes, const vector<int> &turnaroundTimes) {
    int n = burstTimes.size();
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << "\t" << burstTimes[i] << "\t\t" << waitingTimes[i] << "\t\t" << turnaroundTimes[i] << endl;
    }
}

int main() {
    int n, quantum;
    
    cout << "Enter number of processes: ";
    cin >> n;
    
    vector<int> burstTimes(n);
    cout << "Enter burst times for the processes:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> burstTimes[i];
    }
    
    cout << "Enter time quantum: ";
    cin >> quantum;
    
    vector<int> waitingTimes(n, 0);
    vector<int> turnaroundTimes(n, 0);
    
    // Calculate waiting times
    calculateWaitingTime(burstTimes, waitingTimes, quantum);
    
    // Calculate turnaround times
    calculateTurnaroundTime(burstTimes, waitingTimes, turnaroundTimes);
    
    // Print results
    printResults(burstTimes, waitingTimes, turnaroundTimes);
    
    return 0;
}