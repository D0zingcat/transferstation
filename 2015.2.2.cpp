#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	int s;
	int e;
}p[102];

int cmp(struct node a, struct node b)
{
	if (a.e > b.e) return 0;
	else if (a.e == b.e) {
		if (a.s >= b.s)
			return 0;
		else return 1;
	}
	else 
		return 1;
}

int main()
{
	int n;
	int i;
	int t;
	int ans;
	while (cin >> n, n) {
		t = -1;
		ans = 0;
		for (i = 0; i < n; i ++)
			cin >> p[i].s >> p[i].e;
		sort(p, p + n, cmp);
		for (i = 0; i < n; i ++) {
			if (p[i].s >= t) {
				t = p[i].e;
				ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
