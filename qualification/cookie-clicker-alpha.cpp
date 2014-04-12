#include <cstdio>
#include <cstring>
#include <iostream>

#define SIZE 4

using namespace std;

bool chosen[SIZE * SIZE];

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    double c, f, x; cin >> c >> f >> x;

    double rate = 2.0, time = 0.0;
    while(x / rate > (c / rate + (x / (rate + f)))) {
      time += c / rate;
      rate += f;
    }
    time += x / rate;

    cout << "Case #" << tc << ": ";
    printf("%.7lf\n", time);
  }
  return 0;
}
