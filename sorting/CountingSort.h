#include <vector>

using namespace std;

void CountingSort(vector<long long> &list, long long, long long)
{
    long long mx = list[0];
    long long mn = list[0];

    for (size_t i = 0; i < list.size(); i++)
    {
        // поиск максимального и мимального элемента
        if (list[i] > mx)
            mx = list[i];
        if (list[i] < mn)
            mn = list[i];
    }

    vector<long long> tmp(mx - mn + 1);
    for (size_t i = 0; i < list.size(); i++)
    {
        // подсчет кол-ва вхождений кахдого элемента в исходный массив
        tmp[list[i] - mn]++;
    }

    long long size = list.size();
    list.clear();
    list.resize(size);
    long long k = 0;
    for (long long i = mn; i <= mx; i++)
    {
        // добавляем элемент столько раз, сколько он встретился в исходном массиве
        for (long long j = 0; j < tmp[i - mn]; j++)
        {
            list[k++] = i;
        }
    }
}