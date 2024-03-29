# Программа, находящая геодезическую цепь между двумя вершинами в графе. Поиск производится алгоритмом Дейкстры. Результатом работы является маршрут между вершинами, заданный списком рёбер, и длина маршрута. 

---

## Использованы библиотеки:

1. Graphviz
2. Opencv

---

## Задание:

Входные данные для работы программы задаются следующими ключами
с параметрами:
1. -e "edges_list_file_path"
2. -m "adjacency_matrix_file_path"
3. -l "adjacency_list_file_path"

Одновременно может указываться только один из этих ключей. Если
указано более одного – выдать сообщение об ошибке.

Алгоритм для расчёта задаётся следующими ключами:
1. -d – алгоритм Дейкстры
2. -b – алгоритм Беллмана-Форда-Мура
3. -t – алгоритм Левита

Если граф/орграф не удовлетворяет требованиям алгоритма к входным
данным, выдать пользователю соответствующее предупреждение.
Начальная вершина задаётся следующим ключом:
1. -n begin_vertex_number
Данный ключ является обязательным.

Результаты работы выводятся на экран, либо в файл при указании
следующего ключа:
-o "output_file_path"
Также должна быть доступна справка, в которой указывается: автор
работы, группа, список ключей с кратким описанием. Справка вызывается
при помощи ключа -h. При этом, если указаны остальные ключи, они
игнорируются.

---

## Описание входных данных:

1. Граф, заданный списком рёбер. Каждое ребро хранится отдельной
строкой. В строке три числа, разделённых пробелом: исходящая
вершина, входящая вершина, вес ребра. Номера вершин представляют
собой натуральные числа с нулём. Размерность графа определяется
автоматически (от 0 вершины до вершины с наибольшим номером).
2. Граф, заданный списками смежности. Номер строки представляет собой
номер вершины графа, в строке через пробел перечислены номера
смежных вершин.
3. Граф, заданный матрицей смежности. Значения в строках разделены
пробелами.

---

## Для работы с графом используются следующие открытые функции:

1. **конструктор класса** – принимает путь к файлу, в котором хранится
граф и тип файла;
2. **size** – возвращает количество вершин в графе/орграфе;
3. **weight** – принимает номера двух вершин, возвращает вес ребра/дуги,
связывающего их;
4. **is_edge** – принимает номера двух вершин и возвращает True, если в
графе/орграфе есть соответствующее ребро/дуга, False, если
ребра/дуги нет;
5. **adjacency_matrix** – возвращает матрицу смежности графа/орграфа;
6. **adjacency_list** – принимает номер вершины, возвращает список
вершин, смежных данной вершине в графе / исходящих из данной
вершины в орграфе;
7. **list_of_edges** – без аргументов возвращает список всех рёбер графа;
с аргументом – номер вершины, возвращает список рёбер графа,
инцидентных данной вершине / дуг, исходящих из данной вершины.
8. **is_directed** – возвращает True, если граф ориентированный, False,
если граф простой.

---

### Класс содержит следующие открытые функции:

1. **конструктор класса** – принимает путь к файлу;
2. **индексатор** – принимает номер строки и столбца, возвращает значение
высоты в точке;
3. **size** – возвращает число строк и столбцов в матрице, представляющей
карту;
4. **neighbors** – принимает номер строки и столбца, возвращает список
соседних клеток.