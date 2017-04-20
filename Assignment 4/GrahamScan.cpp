#include <bits/stdc++.h>
using namespace std;
class mp{
	public:
	    int x, y;
	    bool operator < (mp b) {
	        if (y != b.y)
	            return y < b.y;
	        return x < b.x;
	    }
};
mp pivot;
int Orient(mp a, mp b, mp c) {
    int val = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
      if (val == 0)
        return 0;
    return (val > 0) ? -1 : 1;
}
int Dist_Sq(mp a, mp b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}
bool polar_order(mp a, mp b)  {
    int order = Orient(pivot, a, b);
    if (order == 0)
        return Dist_Sq(pivot, a) < Dist_Sq(pivot, b);
    return (order == -1);
}
int main(){  
   int n;cin>>n;
    mp array[n];
    for(int i=0;i<n;i++) cin>>array[i].x>>array[i].y;
    stack<mp> hull;
    if (n >= 3) {
	    int least_y = 0;
	    for (int i = 1; i < n; i++)
	        if (array[i] < array[least_y])
	            least_y = i;
	    mp temp = array[0];
	    array[0] = array[least_y];
	    array[least_y] = temp;
	    pivot = array[0];
	    sort(array + 1, array + n, polar_order);
	    hull.push(array[0]);
	    hull.push(array[1]);
	    hull.push(array[2]);
	    for (int i = 3; i < n; i++) {
	        mp top = hull.top();
	        hull.pop();
	        while (Orient(hull.top(), top, array[i]) != -1)   {
	            top = hull.top();
	            hull.pop();
	        }
	        hull.push(top);
	        hull.push(array[i]);
	    }
	}
    while (!hull.empty())   {
        mp p = hull.top();
        hull.pop();
		cout << "(" <<p.x << ", " <<p.y << ")\n";
    }
    return 0;
}
