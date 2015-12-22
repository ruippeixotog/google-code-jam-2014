#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

#define N 1000

using namespace std;

int arr[N];

int calcScore() {
  int score = 0;
  for(int i = 0; i < N; i++) {
    if(arr[i] <= i) score++;
  }
  return score;
}

int simBadBias(int iters) {
  int scoreSum = 0;

  for(int k = 0; k < iters; k++) {
    for(int i = 0; i < N; i++)
      arr[i] = i;

    for(int i = 0; i < N; i++) {
      swap(arr[i], arr[rand() % N]);
    }
    scoreSum += calcScore();
  }

  return scoreSum / iters;
}

int main() {
  srand(time(0));
  int badBias = simBadBias(10000);

  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    bool good = calcScore() > (500 + badBias) / 2;
    cout << "Case #" << tc << ": " << (good ? "GOOD" : "BAD") << endl;
  }
  return 0;
}
