#include <bits/stdc++.h>

using namespace std;

int N, A = 0;
vector<int> positions;

int getNum(int start, int direction) {
	int radius = 1;
	int prev = start;

	while (true) {
		int next = prev;
		// Getting the furthest explosion index without exceeding the current radius
		while (next + direction >= 0 && next + direction < N 
			&& abs(positions[next + direction] - positions[prev]) <= radius) {
			next += direction;
		}

		// We didn't find a new haybale, so the chain explosion is over
		if (next == prev) {
			break;
		}

		// Update our previous explosion and increment radius
		prev = next;
		radius++;
	}
	return abs(prev - start);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//freopen("angry.in","r",stdin);
	//freopen("angry.out","w",stdout);

	cin >> N;
	positions.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> positions[i];
	}

	sort(positions.begin(), positions.end());
	for (int i = 0; i < N; i++) {
		// Computing answer
		A = max(A, getNum(i, -1) + getNum(i, 1) + 1);
	}   

	cout << A;
}