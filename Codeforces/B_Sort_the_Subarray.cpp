#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <iomanip>
#include <utility>

using namespace std;
#define ll long long

int main()
{
	ll t;
	cin >> t; // Read the number of test cases
	while (t--) {
		ll n;
		cin >> n; // Read the size of the array
		ll arr[n];
		ll arr2[n];

		// Read the original array
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		// Read the modified array
		for (int i = 0; i < n; i++) {
			cin >> arr2[i];
		}

		int change1 = -1, change2 = -1;

		// Find the first and last positions where the arrays differ
		for (int i = 0; i < n; i++) {
			if (arr[i] != arr2[i]) {
				if (change1 == -1) {
					change1 = i; // First differing position
				} else {
					change2 = i; // Last differing position
					break;
				}
			}
		}

		// Extend the left boundary of the subarray if possible
		int i = change1 - 1;
		while (i >= 0) {
			if (arr2[i] <= arr2[i + 1]) {
				i--;
			} else {
				break;
			}
		}
		change1 = i + 1;

		// If no second change was found, assume the end of the array
		if (change2 == -1) {
			change2 = n - 1;
		}

		// Extend the right boundary of the subarray if possible
		int j = change2 + 1;
		while (j < n) {
			if (arr2[j] >= arr2[j - 1]) {
				j++;
			} else {
				break;
			}
		}
		change2 = j - 1;

		// Output the 1-based indices of the subarray
		cout << change1 + 1 << " " << change2 + 1 << endl;
	}

	// Time Complexity (TC): O(n)
	// Space Complexity (SC): O(n)
}
