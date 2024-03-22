#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int minDistance(const vector<int>& arr_n, int x_n, int y_n) {
    int min_dist_n = INT_MAX;
    int prev_n = -1;

    for (int i_n = 0; i_n < arr_n.size(); ++i_n) {
        if (arr_n[i_n] == x_n || arr_n[i_n] == y_n) {
            if (prev_n != -1 && arr_n[i_n] != arr_n[prev_n]) {
                min_dist_n = min(min_dist_n, i_n - prev_n);
            }
            prev_n = i_n;
        }
    }
    return min_dist_n;
}

int main() {
    int n_n;
    cin >> n_n;

    vector<int> arr_n(n_n);
    for (int i_n = 0; i_n < n_n; ++i_n) {
        cin >> arr_n[i_n];
    }

    int x_n, y_n;
    cin >> x_n >> y_n;

    cout << minDistance(arr_n, x_n, y_n) << endl;

    return 0;
}
