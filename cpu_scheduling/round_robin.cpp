#include <iostream>
#include <vector>

using namespace std;

struct Process {
  int pid;       // Process ID
  int burstTime; // Burst time
};

void roundRobinScheduling(vector<Process> &processes, int quantum) {
  vector<int> remainingTime(processes.size());
  vector<int> waitingTime(processes.size(), 0);
  vector<int> turnAroundTime(processes.size());

  for (int i = 0; i < processes.size(); i++) {
    remainingTime[i] = processes[i].burstTime;
  }

  int time = 0;
  bool done;

  do {
    done = true;
    for (int i = 0; i < processes.size(); i++) {
      if (remainingTime[i] > 0) {
        done = false;
        if (remainingTime[i] > quantum) {
          time += quantum;
          remainingTime[i] -= quantum;
        } else {
          time += remainingTime[i];
          waitingTime[i] = time - processes[i].burstTime;
          remainingTime[i] = 0;
        }
      }
    }
  } while (!done);

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
  vector<Process> processes = {{1, 10}, {2, 5}, {3, 8}};
  int quantum = 2;

  roundRobinScheduling(processes, quantum);
  return 0;
}
