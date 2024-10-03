#include <iostream>
#include <vector>
using namespace std;

void seive(long long n) {
  vector<char> arr(n + 1, true);
  arr[0] = arr[1] = false;
  for (long long i = 2; i * i <= n; i++) {
    if (arr[i] == true) {
      for (long long j = 2 * i; j <= n; j += i) {
        arr[j] = false;
      }
    }
  }
  for (long long i = 0; i < n + 1; i++) {
    if (arr[i] == true)
      cout << i << " ";
  }
}
int main() {
  long long n;
  cin >> n;
  seive(n);
  return 0;
}
