#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 2e5 + 9;
int pre[MAXN];

struct edge{
    int left,right;
    long long val;
}bian[MAXN];

void init(int n , int m){
    for(int i = 1 ; i <= n ; i++) pre[i] = i;
    for(int i = 1 ; i <= m ; i++) cin >> bian[i].left >> bian[i].right >> bian[i].val;
}

int root(int x)
{
    return pre[x] == x ? x : root(pre[x]);
}

int kruskal(int n , int m)
{   
    int ans = 0 ;
    int total = 0 ;
    for(int i = 1 ; i <= m; i++)
    {
        int u=root(bian[i].left);
        int v=root(bian[i].right);
        if(u == v) continue;
        else{
            ans += bian[i].val;
            pre[u] = v;
            total++;
            if(total == n-1) break;
        }
    }
    if(total != n - 1){
        ans = -1;
    }
    return ans;
}

bool cmp(edge a,edge b)
{
    return a.val<b.val;
}

void solve()
{
    int n , m ;cin >> n >> m;
    init(n , m);
    sort(bian+1,bian+m+1,cmp);  //快排边长,小的在上面
    int ans = kruskal(n , m);
    cout << (ans == -1 ? "orz" : to_string(ans)) << endl ;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    while(T--){
        solve();
    }
    return 0;
}