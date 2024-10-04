#include <iostream>
#include <vector>

using namespace std;

struct Process {
  int pid;       // Process ID
  int burstTime; // Burst time
};

void findWaitingTime(vector<Process> &processes, vector<int> &waitingTime) {
  waitingTime[0] = 0; // First process has no waiting time

  for (int i = 1; i < processes.size(); i++) {
    waitingTime[i] = processes[i - 1].burstTime + waitingTime[i - 1];
  }
}

void findTurnAroundTime(vector<Process> &processes, vector<int> &waitingTime,
                        vector<int> &turnAroundTime) {
  for (int i = 0; i < processes.size(); i++) {
    turnAroundTime[i] = processes[i].burstTime + waitingTime[i];
  }
}

void fcfsScheduling(vector<Process> &processes) {
  vector<int> waitingTime(processes.size()), turnAroundTime(processes.size());

  findWaitingTime(processes, waitingTime);
  findTurnAroundTime(processes, waitingTime, turnAroundTime);

  cout << "Processes    Burst Time    Waiting Time    Turn-Around Time\n";
  for (int i = 0; i < processes.size(); i++) {
    cout << "   " << processes[i].pid << "\t\t" << processes[i].burstTime
         << "\t\t" << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
  }
}

int main() {
  vector<Process> processes = {{1, 10}, {2, 5}, {3, 8}};

  fcfsScheduling(processes);
  return 0;
}
