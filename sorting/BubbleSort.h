#include <vector>

using namespace std;

void BubbleSort(vector<long long> &list, long long, long long)
{
    size_t count = list.size();
    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = 0; j < count - 1 - i; j++)
        {
            // сравниваются соседние элементы, и, если порядок в паре неверный, то элементы меняют местами
            if (list[j] > list[j + 1])
            {
                swap(list[j], list[j + 1]);
            }
        }
    }
}