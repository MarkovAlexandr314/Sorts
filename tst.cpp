#include <iostream>
#include <vector>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
// #include "QuickSort.h"
#include <algorithm>
#include <random>
#include <vector>
using namespace std;
// #include "MergeSort.h"
// #include "CountingSort.h"

long long partitionRandomPivot(vector<long long> &a, long long l, long long r)
{
    // Инициализация генератора случайных чисел с помощью текущего времени

    // Генерация случайного числа от 0 до RAND_MAX
    int index = rand() % a.size();

    long long pivot = a[index];
    long long i = l;
    long long j = r;
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i >= j)
            break;
        swap(a[i++], a[j--]);
    }
    return j;
}

void QuickSortRandomPivot(vector<long long> &a, long long l, long long r)
{
    if (l < r)
    {
        long long q = partitionRandomPivot(a, l, r);
        QuickSortRandomPivot(a, l, q);
        QuickSortRandomPivot(a, q + 1, r);
    }
}

int main()
{
    srand(time(0));
    vector<long long> l1{1, 5, 3, 2, 5, -6};
    // vector<int> l2{4, 5, 6};
    QuickSortRandomPivot(l1, 0, l1.size()-1);
    for (auto i : l1)
    {
        cout << i << ' ';
    }
}