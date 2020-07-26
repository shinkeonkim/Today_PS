#include <bits/stdc++.h>

#define for1(s,n) for(int i = s; i < n; i++)
#define for1j(s,n) for(int j = s; j < n; j++)
#define pb(a) push_back(a)
#define sz(a) a.size()

#define MAX 3300
#define INF (ll)1e18

using namespace std;
typedef long long ll;


struct edge {
	int to, cost;
};

int n;
vector<edge> v[MAX];
ll D[MAX];
bool bellman_ford(ll start_point){
    fill(D,D+n+1, INF);
    D[start_point] = 0;

	bool isCycle = false;
	for1(1, n+1) {
		for1j(1, n+1) {
		for(int k=0; k<sz(v[j]); k++) {
			edge p = v[j][k];
			int end = p.to;
			ll dist = D[j] + p.cost;
				if (D[end] > dist) {
					D[end] = dist;
					if (i == n) isCycle = true;
				}
			}
		}
	}
	return isCycle;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int m,k;
        int start, end, cost;

        cin >> n >> m >> k;

        for1(1, m+1) {
            cin >> start >> end >> cost;
            v[start].push_back({end, cost});
            v[end].push_back({start, cost});

        }
        for1(1, k+1) {
            cin >> start >> end >> cost;
            v[start].push_back({end, -cost});
        }

        if(bellman_ford(1)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        
        for1(0, n+1) {
            v[i].clear();   
        }
    }
}
