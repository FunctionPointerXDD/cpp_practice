#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)

using ll = long long;
using matrix = vector<vector<ll>>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vb = vector<bool>;

int n, k;
vi x, y, xs, ys;
const int INF = 1e9;

// n<=50의 크기는 모든 포인트를 O(n4) 해도 충분한 시간 복잡도이다. 
// p1, p2, p3가 정해졌을 때 가장 최단 거리로 i번째 위치의 거리를 반환하고 그 값의 max를 취한다.
int calc(int p1, int p2, int p3) {
    int ans = 0;
    for(int i=0; i<n; ++i) {
        ans = max(ans, min({abs(x[i]-x[p1]) + abs(y[i]-y[p1]), abs(x[i]-x[p2]) + abs(y[i]-y[p2]), abs(x[i]-x[p3]) + abs(y[i]-y[p3])}));
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    x = vi(n), y = vi(n);
    for(int i=0; i<n; ++i) cin >> x[i] >> y[i];
    
    int ans = INF;
    // 1, 2, 3일 경우를 나누어 3단 for loop 진행
    // 1, 2, 3일 때로 calc함수를 나누어 짜지 않고 간단하게 인자를 동일시 시키는 방법을 택함 
    if(k==1) {
        for(int i=0; i<n; ++i) ans = min(ans, calc(i, i, i));
    }
    else if(k==2) {
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                ans = min(ans, calc(i, j,j));
            }
        }
    }   
    else if(k==3) {
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                for(int k=j; k<n; ++k) {
                    ans = min(ans, calc(i, j,k));
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}
