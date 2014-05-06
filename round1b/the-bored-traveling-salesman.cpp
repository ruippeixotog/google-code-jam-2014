#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define ll long long
#define siterator set<int>::iterator
#define miterator map<int, set<int> >::iterator

#define MAXN 8
#define INF 1e9

using namespace std;

int codes[MAXN];
map<int, set<int> > adjs;
map<int, int> numConnections;

vector<int> sol;
set<int> used;

set<int> seen;
bool dfsReachable(int from, int to, int parent) {
  if(seen.count(from)) return false;
  if(from == to) return true;
  seen.insert(from);

  set<int>& cityAdjs = adjs[from];
  for(siterator it = cityAdjs.begin(); it != cityAdjs.end(); it++) {
    if(*it != parent && dfsReachable(*it, to, from)) return true;
  }
  return false;
}

void dfs(int city, int parentUpper) {
  used.insert(city);
  // cerr << "city: " << city << " - upper is " << parentUpper << endl;
  sol.push_back(city);

  set<int>& cityAdjs = adjs[city];

  int lastMandatory = -1;
  for(siterator it = cityAdjs.begin(); it != cityAdjs.end(); it++) {
    int adj = *it;
    if(used.count(adj)) continue;

    // if(numConnections[adj] == 1)
    //   lastMandatory = adj;

    seen.clear();
    if(!dfsReachable(adj, city, city)) {
      lastMandatory = adj;
    }
  }

  int childUpper = max(parentUpper, lastMandatory);

  for(siterator it = cityAdjs.begin(); it != cityAdjs.end(); it++) {
    int adj = *it;
    if(used.count(adj)) continue;

    seen.clear();
    if(adj <= childUpper || !dfsReachable(adj, city, city)) { // WARN
      siterator nextIt = it; nextIt++;
      int upper = childUpper;
      if(nextIt != cityAdjs.end())
        upper = min(upper, *nextIt);

      dfs(adj, upper);
    }

    numConnections[adj]--;
  }
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    int n, m; cin >> n >> m;

    cerr << n << " " << m << endl;

    adjs.clear();
    numConnections.clear();
    sol.clear();
    used.clear();

    for(int i = 0; i < n; i++)
      cin >> codes[i];

    for(int i = 0; i < m; i++) {
      int a, b; cin >> a >> b;
      --a; --b;
      adjs[codes[a]].insert(codes[b]);
      adjs[codes[b]].insert(codes[a]);
    }

    for(int i = 0; i < n; i++)
      numConnections[codes[i]] = adjs[codes[i]].size();

    dfs(adjs.begin()->first, INF);

    if((int) sol.size() != n) {
      cerr << "FAIL" << endl;
      break;
    }

    cout << "Case #" << tc << ": ";
    for(int i = 0; i < (int) sol.size(); i++)
      cout << sol[i];
    cout << endl;
  }
  return 0;
}
