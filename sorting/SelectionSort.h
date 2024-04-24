#include <vector>

using namespace std;

void SelectionSort(vector<long long> &list, long long, long long)
{
    for (size_t i = 0; i < list.size(); i++)
    {
        // ищем минимальный элемент в еще не отсортированной части массива и ставим его в конец отсортированной части
        long long min = i;
        for (size_t j = i + 1; j < list.size(); j++)
        {
            // ищем min элемент
            if (list[min] > list[j])
            {
                min = j;
            }
        }
        // ставим min в конец отсортированной части
        swap(list[i], list[min]);
    }
}