#include <iostream>
#include <list>
#include <string>

#define literator list<string>::iterator

#define ll long long

#define MOD 1000000007

using namespace std;

ll fact(ll x) {
  return (x == 0 ? 1 : x * fact(x - 1) % MOD);
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n; cin >> n;

    list<string> strs;
    for(int i = 0; i < n; i++) {
      string str; cin >> str;
      strs.push_back(str);
    }

    ll count = 1;

    for(char c = 'a'; c <= 'z'; c++) {
      int pure = 0;
      string s0, s1;

      for(literator it = strs.begin(); it != strs.end();) {
        int idx = (*it).find(c);
        if(idx == -1) { it++; continue; }

        string str = *it;
        it = strs.erase(it);

        if(str.find_first_not_of(c) == -1) pure++;
        else {
          while(idx < str.length() && str[idx] == c) idx++;
          if(str.find(c, idx) != -1) { count = 0; break; }

          if(s0 == "") s0 = str;
          else if(s1 == "") s1 = str;
          else { count = 0; break; }
        }
      }
      if(count == 0) break;

      count = (count * fact(pure)) % MOD;

      if(s0 != "") {
        if(s1 == "") strs.push_back(s0);
        else if(s1[0] == c && s0[s0.length() - 1] == c) strs.push_back(s0 + s1);
        else if(s0[0] == c && s1[s1.length() - 1] == c) strs.push_back(s1 + s0);
        else { count = 0; break; }
      } else {
        if(pure > 0) strs.push_back(string(1, c));
      }
    }

    count = (count * fact(strs.size())) % MOD;
    cout << "Case #" << tc << ": " << count << endl;
  }
  return 0;
}
