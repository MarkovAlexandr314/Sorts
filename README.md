## Сортировка слиянием

Сортировка слиянием — алгоритм сортировки, который упорядочивает списки или другие структуры данных в определенном порядке. Это пример использования принципа "разделяй и властвуй". Вот основные шаги алгоритма:

1. Разделение: Сортируемый массив разбивается на две примерно равные части.
2. Сортировка: Каждая из получившихся частей сортируется отдельно, например, тем же самым алгоритмом.
3. Слияние: Два упорядоченных массива половинного размера соединяются в один.

Чтобы оценить время работы этого алгоритма, составим рекуррентное соотношение. Пускай T(n)
 — время сортировки массива длины n
, тогда для сортировки слиянием справедливо T(n)=2T(n/2)+O(n)

O(n)
 — время, необходимое на то, чтобы слить два массива длины n
. Распишем это соотношение:

T(n)=2T(n/2)+O(n)=4T(n/4)+2O(n)=⋯=T(1)+log(n)O(n)=O(nlog(n))

Tребуется дополнительно O(n)
 памяти
.

### Шаги алгоритма более подробно:

1. Рекурсивное разбиение: Задача разбивается на меньшие подзадачи до тех пор, пока размер массива не станет равным 1 (массив длины 1 считается упорядоченным).

2. Соединение двух упорядоченных массивов в один: На каждом шаге берется меньший из двух первых элементов подмассивов и записывается в результирующий массив. При этом счетчики номеров элементов результирующего массива и подмассива, из которого был взят элемент, увеличиваются на 1.

3. "Прицепление" остатка: Когда один из подмассивов заканчивается, все оставшиеся элементы второго подмассива добавляются в результирующий массив.

Этот алгоритм эффективен и устойчив к различным типам входных данных, что делает его популярным методом сортировки.

## Быстрая сортировка
Быстрая сортировка (сортировка Хоара) — один из самых известных и широко используемых алгоритмов сортировки. Среднее время работы O(nlogn)
, что является асимптотически оптимальным временем работы для алгоритма, основанного на сравнении. Хотя время работы алгоритма для массива из n
 элементов в худшем случае может составить Θ(n2)
, на практике этот алгоритм является одним из самых быстрых.
### Алгоритм
Быстрый метод сортировки функционирует по принципу "разделяй и властвуй".
Массив a[l…r]
 типа T
 разбивается на два (возможно пустых) подмассива a[l…q]
 и a[q+1…r]
, таких, что каждый элемент a[l…q]
 меньше или равен a[q]
, который в свою очередь, не превышает любой элемент подмассива a[q+1…r]
. Индекс вычисляется в ходе процедуры разбиения.
Подмассивы a[l…q]
 и a[q+1…r]
 сортируются с помощью рекурсивного вызова процедуры быстрой сортировки.
Поскольку подмассивы сортируются на месте, для их объединения не требуются никакие действия: весь массив a[l…r]
 оказывается отсортированным.
 ## Сортировка подсчётом
 Сортировка подсчётом (англ. counting sort) — алгоритм сортировки целых чисел в диапазоне от 0
 до некоторой константы k
 или сложных объектов, работающий за линейное время.
 Это простейший вариант алгоритма.

### Описание
Исходная последовательность чисел длины n
, а в конце отсортированная, хранится в массиве A
. Также используется вспомогательный массив C
 с индексами от 0
 до k−1
, изначально заполняемый нулями.

Последовательно пройдём по массиву A
 и запишем в C[i]
 количество чисел, равных i
.
Теперь достаточно пройти по массиву C
 и для каждого number∈{0,...,k−1}
 в массив A
 последовательно записать число C[number]
 раз.
 
 В алгоритме первые два цикла работают за Θ(k)
 и Θ(n)
, соответственно; двойной цикл за Θ(n+k)
. Алгоритм имеет линейную временную трудоёмкость Θ(n+k)
. Используемая дополнительная память равна Θ(k)
.
## Сортировка пузырьком
Сортировка простыми обменами, сортировка пузырьком (англ. bubble sort) — один из квадратичных алгоритмов сортировки.
Алгоритм состоит в повторяющихся проходах по сортируемому массиву. На каждой итерации последовательно сравниваются соседние элементы, и, если порядок в паре неверный, то элементы меняют местами. За каждый проход по массиву как минимум один элемент встает на свое место, поэтому необходимо совершить не более n−1
 проходов, где n
 размер массива, чтобы отсортировать массив.

 Можно заметить, что после i
-ой итерации внешнего цикла i
 последних элементов уже находятся на своих местах в отсортированном порядке, поэтому нет необходимости производить их сравнения друг с другом. Следовательно, внутренний цикл можно выполнять не до n−2
, а до n−i−2
.
Также заметим, что если после выполнения внутреннего цикла не произошло ни одного обмена, то массив уже отсортирован, и продолжать что-то делать бессмысленно. Поэтому внутренний цикл можно выполнять не n−1
 раз, а до тех пор, пока во внутреннем цикле происходят обмены.
 
 В данной сортировке выполняются всего два различных вида операции: сравнение элементов и их обмен. Поэтому время всего алгоритма T=T1+T2
, где T1
 — время, затрачиваемое на сравнение элементов, а T2
 — время, за которое мы производим все необходимые обмены элементов.

Так как в алгоритме меняться местами могут только соседние элементы, то каждый обмен уменьшает количество инверсий на единицу. Следовательно, количество обменов равно количеству инверсий в исходном массиве вне зависимости от реализации сортировки. Максимальное количество инверсий содержится в массиве, элементы которого отсортированы по убыванию. Несложно посчитать, что количество инверсий в таком массиве n(n−1)2
. Получаем, что T2=O(n2)
.

В неоптимизированной реализации на каждой итерации внутреннего цикла производятся n−1
 сравнений, а так как внутренний цикл запускается также n−1
 раз, то за весь алгоритм сортировки производятся (n−1)2
 сравнений.

В оптимизированной версии точное количество сравнений зависит от исходного массива. Известно, что худший случай равен n(n−1)2
, а лучший — n−1
. Следовательно, T1=O(n2)
.

В итоге получаем T=T1+T2=O(n2)+O(n2)=O(n2)
.


