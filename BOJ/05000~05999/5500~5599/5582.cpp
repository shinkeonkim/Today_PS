#include <bits/stdc++.h>

#define for1(s,n) for(int i = s; i < n; i++)
#define for1j(s,n) for(int j = s; j < n; j++)
#define foreach(k) for(auto i : k)
#define foreachj(k) for(auto j : k)
#define pb(a) push_back(a)
#define sz(a) a.size()

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector <int> iv1;
typedef vector <vector<int>> iv2;
typedef vector <ll> llv1;
typedef unsigned int uint;
typedef vector <ull> ullv1;
typedef vector <vector <ull>> ullv2;

string a,b;
int D[4400][4400];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    for(int x=0; x<a.length(); x++) {
        for(int y=0; y<b.length(); y++) {
            if(a[x] == b[y]) {
                D[x+1][y+1] = D[x][y] + 1;
                ans = max(ans,D[x+1][y+1]);
            }
        }
    }    
    cout << ans;
}   