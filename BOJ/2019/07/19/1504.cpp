#include <iostream>
#include <vector>
#define ll long long
#define Mx 999999999
using namespace std;

struct st1
{
    ll n, c;
};

ll N, M, check1, check2, check[2000], minc[2000], answer1,answer2;
vector<st1> cost[2000];

ll A, B, C;
st1 ZZ;

ll f(int start, int end)
{
    for (int x = 1; x <= N; x++)
    {
        minc[x] = Mx;
        check[x] = 0;
    }
        
    minc[start] = 0;

    for (int x = 1; x <= N; x++)
    {
        ll S = 0, Min = Mx;

        for (int y = 1; y <= N; y++)
        {
            if (check[y] == 0 && Min > minc[y])
            {
                Min = minc[y];
                S = y;
            }
        }
        for (int y = 0; y < cost[S].size(); y++)
        {
            if (minc[cost[S][y].n] > minc[S] + cost[S][y].c)
            {
                minc[cost[S][y].n] = minc[S] + cost[S][y].c;
            }
        }
        check[S] = 1;
    }

    return minc[end];
}

int main()
{
    cin >> N >> M;

    for (int x = 1; x <= M; x++)
    {
        cin >> A >> B >> C;
        ZZ.n = B;
        ZZ.c = C;
        cost[A].push_back(ZZ);
        ZZ.n = A;
        cost[B].push_back(ZZ);
    }

    cin >> check1 >> check2;
    
    long long answer1 = 0,answer2=0;
    if(1!= check1) answer1+=f(1, check1);
    if(check1!=check2) answer1+=f(check1, check2);
    if(N!=check2) answer1+=f(check2, N);

    if(1!= check2) answer2+=f(1, check2);
    if(check1!=check2) answer2+=f(check2, check1);
    if(N!=check1) answer2+=f(check1, N);

    if (min(answer1,answer2) >= Mx)
    {
        cout << -1;
    }
    else
    {
        cout << min(answer1,answer2);
    }
}
