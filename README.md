## Сортировка слиянием

Сортировка слиянием — алгоритм сортировки, который упорядочивает списки или другие структуры данных в определенном порядке. Это пример использования принципа "разделяй и властвуй". Вот основные шаги алгоритма:

1. Разделение: Сортируемый массив разбивается на две примерно равные части.
2. Сортировка: Каждая из получившихся частей сортируется отдельно, например, тем же самым алгоритмом.
3. Слияние: Два упорядоченных массива половинного размера соединяются в один.

### Шаги алгоритма более подробно:

1. Рекурсивное разбиение: Задача разбивается на меньшие подзадачи до тех пор, пока размер массива не станет равным 1 (массив длины 1 считается упорядоченным).

2. Соединение двух упорядоченных массивов в один: На каждом шаге берется меньший из двух первых элементов подмассивов и записывается в результирующий массив. При этом счетчики номеров элементов результирующего массива и подмассива, из которого был взят элемент, увеличиваются на 1.

3. "Прицепление" остатка: Когда один из подмассивов заканчивается, все оставшиеся элементы второго подмассива добавляются в результирующий массив.

Этот алгоритм эффективен и устойчив к различным типам входных данных, что делает его популярным методом сортировки.
