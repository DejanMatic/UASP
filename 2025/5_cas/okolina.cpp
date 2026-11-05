#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, d;
	cin >> n >> d;

	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	sort(begin(v), end(v));

	int l = 0, r = 0, sol = 0;
	int solv = v[0];
	for(int i = 0; i < n; i++) {
		while(v[i] - v[l] > d)
			l++;
		while(r < n && v[r] - v[i] <= d)
			r++;
		if(r - l > sol) {
			sol = r - l;
			solv = v[i];
		}
	}

	cout << solv << ' ' << sol << endl;

	return 0;
}

