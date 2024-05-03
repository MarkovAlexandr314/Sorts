#include<vector>

void GnomeSort(std::vector<long long>& arr, long long, long long) {
    int index = 0;
    int n = arr.size();

    while (index < n) {
        if (index == 0 || arr[index] >= arr[index - 1]) {
            index++;
        } else {
            std::swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}