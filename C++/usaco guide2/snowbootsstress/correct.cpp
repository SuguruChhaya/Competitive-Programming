#include <iostream>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

//ifstream cin("snowboots.in");
//ofstream cout("snowboots.out");

ll n, b;
ll f[1000];
pii boots[1000];
bool visited[1000];

int main() {
  cin >> n >> b;
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  for (int i = 0; i < b; i++) {
    cin >> boots[i].first >> boots[i].second;
  }
  visited[0] = true;
  for (int i = 0; i < b; i++) {
    for (int j = 0; j < n; j++) {
      if (!visited[j]) continue;
      if (f[j] > boots[i].first) continue;
      for (int k = j; k <= min(j + boots[i].second, n-1); k++) {
        if (f[k] <= boots[i].first) {
          visited[k] = true;
          j = k;
          if (k == n-1) {
            cout << i << endl;
            return 0;
          }
        }
      }
    }
  }
}