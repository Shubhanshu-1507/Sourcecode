#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Process {
  int pid;       // Process ID
  int burstTime; // Burst time
  int priority;  // Priority of the process
};

bool comparePriority(Process a, Process b) {
  return a.priority < b.priority; // Higher priority processes come first
}

void priorityScheduling(vector<Process> &processes) {
  sort(processes.begin(), processes.end(), comparePriority);

  vector<int> waitingTime(processes.size()), turnAroundTime(processes.size());

  waitingTime[0] = 0;
  for (int i = 1; i < processes.size(); i++) {
    waitingTime[i] = processes[i - 1].burstTime + waitingTime[i - 1];
  }

  for (int i = 0; i < processes.size(); i++) {
    turnAroundTime[i] = processes[i].burstTime + waitingTime[i];
  }

  cout << "Processes    Burst Time    Priority    Waiting Time    Turn-Around "
          "Time\n";
  for (int i = 0; i < processes.size(); i++) {
    cout << "   " << processes[i].pid << "\t\t" << processes[i].burstTime
         << "\t\t" << processes[i].priority << "\t\t" << waitingTime[i]
         << "\t\t" << turnAroundTime[i] << endl;
  }
}

int main() {
  vector<Process> processes = {{1, 10, 3}, {2, 5, 1}, {3, 8, 2}};

  priorityScheduling(processes);
  return 0;
}
