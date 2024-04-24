
#include <vector>

using namespace std;

long long partition(vector<long long> &a, long long l, long long r)
{
   // в качестве pivot берем элемент из середины массива
   long long pivot = a[(l + r) / 2];
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

void QuickSort(vector<long long> &a, long long l, long long r)
{
   if (l < r)
   {
      long long q = partition(a, l, r);
      QuickSort(a, l, q);
      QuickSort(a, q + 1, r);
   }
}