#include <cstring>
#include <iostream>

#define SIZE 4

using namespace std;

bool chosen[SIZE * SIZE];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    memset(chosen, 0, sizeof(chosen));

    int r1; cin >> r1;

    for(int i = 0; i < SIZE; i++) {
      for(int j = 0; j < SIZE; j++) {
        int v; cin >> v;
        if(i + 1 == r1) chosen[v - 1] = true;
      }
    }

    int r2; cin >> r2;
    int sol = -1;

    for(int i = 0; i < SIZE; i++) {
      for(int j = 0; j < SIZE; j++) {
        int v; cin >> v;
        if(i + 1 == r2 && chosen[v - 1]) {
          if(sol == -1) sol = v;
          else sol = -2;
        }
      }
    }

    cout << "Case #" << tc << ": ";
    if(sol > 0) cout << sol;
    else cout << (sol == -1 ? "Volunteer cheated!" : "Bad magician!");
    cout << endl;
  }
  return 0;
}
