#include <iostream>
#include <vector>

using namespace std;

int find_majority_element(vector<int>& arr) {
    int candidate = -1;
    int count = 0;

    for (int num : arr) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }

    count = 0;
    for (int num : arr) {
        if (num == candidate) {
            count++;
        }
    }

    if (count > arr.size() / 2) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = find_majority_element(arr);
    if (result != -1) {
        cout << "Majority element: " << result << endl;
    } else {
        cout << "No majority element" << endl;
    }

    return 0;
}
