#include <iostream>
#include <vector>
#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include "sorting\QuickSort.h"
#include "sorting\MergeSort.h"
#include "sorting\SelectionSort.h"
#include "sorting\BubbleSort.h"
#include "sorting\CountingSort.h"
#include "sorting\QuickSortRandPivot.h"

using namespace std;

long long BEGIN = 1000;
long long END = 100000;
long long STEP = 1000;

void fillArrayWithRandom(std::vector<long long> &arr, long long size, long long min, long long max)
{
    // Инициализация генератора случайных чисел
    std::random_device rd;                         // используется для получения случайного стартового значения
    std::mt19937 gen(rd());                        // Mersenne Twister 19937 для генерации случайных чисел
    std::uniform_int_distribution<> dis(min, max); // равномерное распределение чисел в диапазоне [min, max]

    // Заполнение массива случайными числами
    for (int i = 0; i < size; ++i)
    {
        arr.push_back(dis(gen)); // генерация случайного числа и добавление его в массив
    }
}

void GetData(std::ofstream &outputFile, void (&func)(std::vector<long long> &a, long long l, long long r), long long begin, long long end, long long step)
{
    vector<long long> list;
    // Запись данных в файл
    for (long long i{begin}; i < end; i += step)
    {
        srand(time(0));
        fillArrayWithRandom(list, i, -i, i);
        std::vector<long long> copylist = list;

        int l = 0;
        int r = list.size() - 1;
        auto startTime = chrono::steady_clock::now();
        func(list, l, r);
        auto endTime = chrono::steady_clock::now();
        if (outputFile.is_open())
        {
            // Запись данных в файл
            outputFile << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();

            if (i != end-step)
                outputFile << "," << std::endl;

            // Закрытие файла после записи данных
        }
        else
        {
            // Вывод сообщения об ошибке, если файл не удалось открыть
            std::cerr << "Ошибка: Не удалось открыть файл для записи." << std::endl;
        }

        sort(copylist.begin(), copylist.end());

        if (copylist != list)
            outputFile << "Error!!!!!!!!!!!" << std::endl;
        list.clear();
    }

    outputFile << "]," << std::endl;
}

int main()
{
    // Инициализация генератора случайных чисел с помощью текущего времени
    srand(time(0));

    vector<long long> list, l2, l3, l4, l5;
    std::ofstream outputFile("data.json");

    outputFile << "{\"QuickSort\": [";
    GetData(outputFile, QuickSort, BEGIN, END, STEP);

    outputFile << "\"MergeSort\": [";
    GetData(outputFile, MergeSort, BEGIN, END, STEP);

    outputFile << "\"CountingSort\": [";
    GetData(outputFile, CountingSort, BEGIN, END, STEP);

    outputFile << "\"QuickSortRandPivot\": [";
    GetData(outputFile, QuickSortRandPivot, BEGIN, END, STEP);

    outputFile << "\"BubbleSort\": [";
    GetData(outputFile, BubbleSort, BEGIN, END/10, STEP);
    

    outputFile << "\"SelectionSort\": [";
    GetData(outputFile, SelectionSort, BEGIN, END/10, STEP);

    // дабавляем размеры массивов
    outputFile << "\"size\": [";
    for (long long i{BEGIN}; i < END; i += STEP)
    {
        if (outputFile.is_open())
        {
            // Запись данных в файл
            outputFile << i;
            if (i != END-STEP)
                outputFile << "," << std::endl;
        }
        else
        {
            // Вывод сообщения об ошибке, если файл не удалось открыть
            std::cerr << "Ошибка: Не удалось открыть файл для записи." << std::endl;
        }
    }
    if (outputFile.is_open())
    {
        // Запись данных в файл
        outputFile << "]}" << std::endl;

        // Закрытие файла после записи данных
        outputFile.close();
        std::cout << "Данные успешно записаны в файл." << std::endl;
    }
}