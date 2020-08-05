#include <iostream>
using namespace std;

// (x^y)%p 구하기
int power(int x, unsigned int y, int p) {
    int ret = 1;
    x = x % p;
    while(y>0) {
        if(y & 1) ret = (ret * x) % p;
        y = y>>1;
        x = (x*x)%p;
    }
    return ret;
}

// 나머지 연산의 곱셈 역원
int modInverse(int a, int p) {
    return power(a,p-2,p);
}

int modFact(int n, int p) {
    if(p<=n) return 0;
    int ret = (p-1);
    for(int i =n+1; i<p; i++) {
        ret = (ret * modInverse(i,p))%p;
    }
    return ret;
}

int main() {
    int N,P;
    cin >> N >> P;
    cout << modFact(N,P);
}
