// Сортировка слиянием

// Данный алгоритм является хорошей демонстрацией принципа "Разделяй и властвуй" (так же как и quickSort).
// Сложность алгоритма Θ(N * log(N)), алгоритм Merge - на каждом уровне деления требует n операций. Всего
// уровней деления log2(N), т.к делим массив пополам. Алгоритм сортировки рекурсивный, а останавливаемся,
// когда подмассив уже состоит из одного элемента (ясно, что он уже отсортирован).
// Требует выделения доп массива O(N). Так же расходуется память на рекурсивные вызовы (поэтому встречаются
// итеративные реализации). Алгоритм устойчив.

// Алгоритм слияния
void merge(int *arr, int l, int m, int r) {
    // Доп массив размера подМассива arr
    int tempArr[r - l + 1];
    // Счетчик по arr[l .. m]
    int i = l;
    // Счетчик по arr[m + 1 .. r]
    int j = m + 1;
    
    // Цикл по доп. массиву, в него будут добавляться элементы из arr в правильном порядке
    for (int h = 0; h < r - l + 1; h++) {
        // Если j не дошел до конца, то тогда проверяем : если у нас дошел до середины i,
        // то просто добавляем уже весь массив начиная от текущего j; если i не дошел до середины, 
        // то находим мЕньший элемент и кидаем его. Если j дошел до конца, то кидаем весь массив 
        // с текущего i пока не дойдем до m + 1 
        if (j <= r && (i == m + 1 || arr[j] < arr[i])) {
            tempArr[h] = arr[j];
            j++;
        } else {
            tempArr[h] = arr[i];
            i++;
        }
    }

    // Теперь из доп массива перебросим все в основной массив
    for (int h = 0, i = l; h < r - l + 1; h++, i++) {
        arr[i] = tempArr[h];
    }
}

// Сама сортировка. Вызываем ее в main : mergeSort(arr, 0, n - 1);
// Функция похожа на quickSort (смотреть quickSort.cpp)
void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        // Средний элемент   
        int med = (l + r) / 2;
        // Вызываем рекурсивно сортировку для 2 половин
        mergeSort(arr, l, med);
        mergeSort(arr, med + 1, r);
        // Делаем слияние двух половин
        merge(arr, l, med, r);
    }
}