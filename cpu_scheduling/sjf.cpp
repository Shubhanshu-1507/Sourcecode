#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Process {
  int pid;       // Process ID
  int burstTime; // Burst time
};

bool compareBurstTime(Process a, Process b) {
  return a.burstTime < b.burstTime;
}

void sjfScheduling(vector<Process> &processes) {
  sort(processes.begin(), processes.end(), compareBurstTime);

  vector<int> waitingTime(processes.size()), turnAroundTime(processes.size());

  // FCFS logic after sorting by burst time
  waitingTime[0] = 0;
  for (int i = 1; i < processes.size(); i++) {
    waitingTime[i] = processes[i - 1].burstTime + waitingTime[i - 1];
  }

  for (int i = 0; i < processes.size(); i++) {
    turnAroundTime[i] = processes[i].burstTime + waitingTime[i];
  }

  cout << "Processes    Burst Time    Waiting Time    Turn-Around Time\n";
  for (int i = 0; i < processes.size(); i++) {
    cout << "   " << processes[i].pid << "\t\t" << processes[i].burstTime
         << "\t\t" << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
  }
}

int main() {
  vector<Process> processes = {{1, 6}, {2, 8}, {3, 7}, {4, 3}};

  sjfScheduling(processes);
  return 0;
}
