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
typedef vector <vector<int> > iv2;
typedef vector <ll> llv1;
typedef unsigned int uint;
typedef vector <ull> ullv1;
typedef vector <vector <ull> > ullv2;

ll N, ar[1100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for1(0, N) {
        cin >> ar[i];
    }

    ll crt = 0;
    for1(0, N) {
        ll count = ar[crt];
        ar[crt] = 0;
        cout << crt + 1 << " ";
        if(i == N-1) break;
        if(count < 0) {
            count *= -1;
            while(count > 0) {
                crt--;
                crt = (crt + N)%N;
                if(ar[crt] != 0) count--;
            }
        }
        else {
            while(count > 0) {
                crt++;
                crt%=N;
                if(ar[crt] != 0) count--;
            }
        }
    }

}