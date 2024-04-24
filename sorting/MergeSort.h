#include <vector>

using namespace std;

void Merge(vector<long long> &list, long long l, long long mid, long long r)
{
    long long List[r - l + 1];
    long long it1 = 0;
    long long it2 = 0;

    while ((l + it1) <= mid && (mid + 1 + it2) <= r)
    {
        if (list[l + it1] <= list[mid + 1 + it2])
        {
            List[it1 + it2] = list[l + it1];
            ++it1;
        }
        else
        {
            List[it1 + it2] = list[mid + 1 + it2];
            ++it2;
        }
    }

    while ((l + it1) <= mid)
    {
        List[it1 + it2] = list[l + it1];
        ++it1;
    }

    while ((mid + 1 + it2) <= r)
    {
        List[it1 + it2] = list[mid + 1 + it2];
        ++it2;
    }

    for (size_t i = 0; i < (it2 + it1); i++)
    {
        list[l + i] = List[i];
    }
}

void MergeSort(vector<long long> &list, long long left, long long right)
{
    if (left >= right)
        return;
    long long mid = (left + right) / 2;
    MergeSort(list, left, mid);
    MergeSort(list, mid + 1, right);
    Merge(list, left, mid, right);
}