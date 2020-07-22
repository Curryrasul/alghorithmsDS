// Алгоритм сортировки пузырьком

// Так же как и в сортировке вставками массив делится на отсортированную часть
// и неотсортированную. Называется сортировкой пузырьком, т.к при каждой итерации 
// самый "тяжелый" элемент из подпоследовательности "улетает" вверх. Алгоритм устойчив.
// Сложность O(n^2). 

void bubbleSort(int *array, int len) {
    
    // Доп переменная, определяющая позицию, после которой все элементы отсортированы.
    int t = len - 1;
    
    // Если t = 0, то очевидно что после 0 уже все отсортировано)
    while (t > 0) {
        // Запомним границу подпоследовательности на текущий момент, т.к t мы будем менять.
        int bound = t;
        
        // Приравняем нулю, а далее если будем делать обмен, то изменим t
        // Если же обмена не произойдет, то очевидно что все отсортировано, и 
        // граница будет равна нулю.
        t = 0;

        // Идем циклом по подпоследовательности
        for (int i = 0; i < bound; i++) {
            
            // Если следующий элемент больше текущего, то меняем местами
            // И присваиваем t индекс последней измененной позиции
            if (array[i + 1] < arr[i]) {
                std::swap(arr[i], arr[i + 1]);
                t = i;  
            }
        }
    }
}