#include <bits/stdc++.h>

#define for1(s,n) for(int i = s; i < n; i++)
#define for1j(s,n) for(int j = s; j < n; j++)
#define foreach(k) for(auto i : k)
#define foreachj(k) for(auto j : k)
#define pb(a) push_back(a)
#define sz(a) a.size()
#define INF 123456789

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector <int> iv1;
typedef vector <vector<int>> iv2;
typedef vector <ll> llv1;
typedef unsigned int uint;
typedef vector <ull> ullv1;
typedef vector <vector <ull>> ullv2;

ll N, M, ans = 0;
ll ar[1100][1100];
ll D[1100][1100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for1(0, N)
        for1j(0, M) {
            cin >> ar[i][j];
            if(ar[i][j] == 0) D[i][j] = 1;
            else D[i][j] = -INF;
            ans = max(ans, D[i][j]);
        }

    for1(1, N) {
        for1j(1, M) {
            if(ar[i][j] == 0) {
                D[i][j] = max(D[i][j], min(D[i-1][j-1],min(D[i-1][j], D[i][j-1]))+1);
                ans = max(ans,D[i][j]);
            }            
        }
    }

    cout << ans;
    
}