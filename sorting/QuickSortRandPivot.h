#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

long long partitionRandomPivot(vector<long long> &a, long long l, long long r)
{

    // Генерация случайного числа от l до r
    long long index = rand() % (r - l + 1) + l;
    // pivot берется случайным образом
    long long pivot = a[index];
    long long i = l;
    long long j = r;
    while (i <= j)
    {
        // ищем первый слева элемент не меньший pivot
        while (a[i] < pivot)
            i++;
        // ищем первый справа элемент не больший pivot
        while (a[j] > pivot)
            j--;
        if (i >= j)
            break;
        // меняем их местами
        swap(a[i++], a[j--]);
    }
    return j;
}

void QuickSortRandPivot(vector<long long> &a, long long l, long long r)
{
    if (l < r)
    {
        long long q = partitionRandomPivot(a, l, r);
        QuickSortRandPivot(a, l, q);
        QuickSortRandPivot(a, q + 1, r);
    }
}