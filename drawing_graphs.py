# Python скрипт для визуализации данных
import matplotlib.pyplot as plt
import json

# Чтение данных из файла
with open("data.json") as json_file:
    data = json.load(json_file)

# Визуализация данных
plt.style.use("ggplot")
plt.figure(figsize=(12, 10))

size = data["size"]

plt.plot(size, data["QuickSort"], color='magenta', label='QuickSort')
plt.plot(size, data["MergeSort"], color='r', label='MergeSort')
plt.plot(size, data["QuickSortRandPivot"], color='aqua', label='QuickSortRandPivot')
plt.plot(size, data["CountingSort"], color='lime', label='CountingSort')
plt.plot(size[:int(len(size)/10)], data["SelectionSort"], color='green', label='SelectionSort')

plt.plot(size[:5], data["BubbleSort"][:5], color='b', label='BubbleSort')


plt.xlabel('Size of array')
plt.ylabel('Time in microseconds')
plt.title('Data Visualization')
plt.legend()
plt.savefig('grafic.png')
plt.show()
