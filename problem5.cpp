#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int max_from_right = arr[n - 1];
    arr[n - 1] = -1;

    for (int i = n - 2; i >= 0; --i) {
        int temp = arr[i];
        arr[i] = max_from_right;
        max_from_right = max(max_from_right, temp);
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
