#include <bits/stdc++.h>
using namespace std;
struct mp{
        int x, y;
};
typedef vector< vector<int> > vvi;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
int Orient(mp p, mp q, mp r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}
void hull(mp array[], int n){
    if (n < 3)
        return;
    int nextPoint[n];
    for (int i = 0; i < n; i++)
        nextPoint[i] = -1;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (array[i].x < array[l].x)
            l = i;
    int p = l, q;
    do{
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
            if (Orient(array[p], array[i], array[q]) == 2)
                q = i;
        nextPoint[p] = q;
        p = q;
    }while (p != l);
    for (int i = 0; i < n; i++){
        if (nextPoint[i] != -1)
            cout << "(" << array[i].x << ", " << array[i].y << ")\n";
    }
}
int main(){
    int n;cin>>n;
    ,p array[n];
    for(int i=0;i<n;i++) cin>>array[i].x>>array[i].y;
    hull(array, n);
    return 0;
}
