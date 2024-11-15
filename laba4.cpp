//Задание 1
//#include <stdio.h>
//#include <stdlib.h> 
//#include <locale.h>
//
//int columnCharacteristic(int array[100][100], int columns, int strings, int col) {
//    int sum = 0;
//
//    for (int i = 0; i < strings; i++) {
//        if (array[i][col] < 0 && array[i][col] % 2 != 0) {
//            sum += -array[i][col]; // Суммируем модули отрицательных нечетных элементов
//        }
//    }
//    return sum;
//}
//
//void sortColumns(int array[100][100], int strings, int columns) {
//    int characteristics[100];
//
//    // Вычисляем характеристики для каждого столбца
//    for (int col = 0; col < columns; col++) {
//        characteristics[col] = columnCharacteristic(array, columns, strings, col);
//    }
//
//    // Сортируем столбцы по характеристикам
//    for (int i = 0; i < columns - 1; i++) {
//        for (int j = i + 1; j < columns; j++) {
//            if (characteristics[i] > characteristics[j]) {
//                // Меняем местами столбцы
//                for (int k = 0; k < strings; k++) {
//                    int temp = array[k][i];
//                    array[k][i] = array[k][j];
//                    array[k][j] = temp;
//                }
//                // Меняем местами характеристики
//                int tempChar = characteristics[i];
//                characteristics[i] = characteristics[j];
//                characteristics[j] = tempChar;
//            }
//        }
//    }
//}
//
//void scanf_choice(int *choice) {
//
//    printf("Введите 1, если хотите заполнить массив вручную или введите 2 для автоматического заполнения (для выхода нажмите 3): ");
//    while (scanf_s("%d", choice) != 1 || getchar() != '\n' || *choice > 3 || *choice < 0) {
//        printf("Введите 1, если хотите заполнить массив вручную или введите 2 для автоматического заполнения (для выхода нажмите 3): \n");
//        rewind(stdin);
//    }
//}
//
//void printMatrix(int array[100][100], int strings, int columns) {
//    
//    for (int i = 0; i < strings; ++i) {
//        for (int j = 0; j < columns; j++) {
//            printf("%4d ", array[i][j]);
//        }
//        printf("\n\n");
//    }
//}
//
//void scanf_strings(int *strings) {
//    printf("Введите количество строк в массиве: ");
//    while (scanf_s("%d", strings) != 1 || *strings < 1 || getchar() != '\n' || *strings > 100) {       /*Проверка на ввод значений*/
//        printf("Введите количество строк в массиве (0 < array_size < 100)\n");
//        rewind(stdin);
//    }
//}
//
//void scanf_columns(int* columns) {
//    printf("Введите количество столбцов в массиве: ");
//    while (scanf_s("%d", columns) != 1 || *columns < 1 || getchar() != '\n' || *columns > 100) {       /*Проверка на ввод значений*/
//        printf("Введите количество столбцов в массиве (0 < array_size < 100)\n");
//        rewind(stdin);
//    }
//}
//void randomMatrix(int array[100][100], int strings, int columns) {
//    for (int i = 0; i != strings; i++) {
//        for (int j = 0; j != columns; j++) {
//            array[i][j] = -100 + rand() % 201;
//        }
//    }
//}
//void scanf_input(int* input) {
//    printf("Введите значение для заполнения массива: ");
//    while (scanf_s("%d", input) != 1 || *input > 100 || *input < -100 || getchar() != '\n') {  /*Проверка на ввод значений*/
//        printf("Введите такое значение, чтобы -100<n<100\n");
//        rewind(stdin);
//    }
//}
//void inputZ(int strings, int columns, int array[100][100], int input) {
//    for (int i = 0; i < strings; i++) {
//        for (int j = 0; j < columns; j++) { 
//            scanf_input(&input);
//            array[i][j] = input;
//        }
//    }
//}
//void correctinput(int* k) {
//    printf("\nЕсли хотите продолжить введите любое число, если хотите выйти введите 3: ");
//
//    while (scanf_s("%d", k) != 1 || getchar() != '\n') {
//        printf("Введите любое число если хотите продолжить (для выхода нажмите 3): \n");
//        rewind(stdin);
//    }    
//}
//
//
//void sumel(int array[100][100], int hasNegative[100], int strings, int columns) {
//    for (int j = 0; j < columns; j++) {
//        hasNegative[j] = 0;
//    }
//    for (int i = 0; i < strings; i++) {
//        for (int j = 0; j < columns; j++) {
//            if (array[i][j] < 0) {
//                hasNegative[j] = 1;
//            }
//        }
//    }
//    for (int j = 0; j < columns; j++) {
//        if (hasNegative[j]) {
//            int columnSum = 0; // Сумма для текущего столбца
//            for (int i = 0; i < strings; i++) {
//                columnSum += array[i][j];
//            }
//            printf("Сумма элементов в столбце %d: %d\n", j + 1, columnSum);
//        }
//    }
//}
//
//
//
//int main() {
//    setlocale(LC_ALL, "Rus");
//    srand(time(0));
//    int array[100][100];
//    int choice = 0, strings = 0, columns = 0;
//    int input = 0;
//    int k = 0;
//    int sum = 0;
//    int hasNegative[100];
//    while (1) {
//
//
//        scanf_choice(&choice);
//        if (choice == 3) {
//            break;
//        }
//        if (choice == 1) {
//            scanf_strings(&strings);
//            scanf_columns(&columns);
//            inputZ(strings, columns, array, input);
//            printf("Вот ваш начальный массив:\n");
//            printMatrix(array, strings, columns);
//            sortColumns(array, strings, columns);
//            printf("Вот ваш конечный массив:\n");
//            printMatrix(array, strings, columns);
//            sumel(array, hasNegative, strings, columns);           
//        }
//        else if (choice == 2) {
//            scanf_strings(&strings);
//            scanf_columns(&columns);
//            printf("Вот ваш начальный массив:\n");
//            randomMatrix(array, strings, columns);           
//            printMatrix(array, strings, columns);
//            sortColumns(array, strings, columns);
//            printf("Вот ваш конечный массив:\n");
//            printMatrix(array, strings, columns);
//            sumel(array, hasNegative, strings, columns);
//            correctinput(&k);          
//            if (k == 3) {
//                break;
//            }
//            else {
//                continue;
//            }
//        }
//        return 0;
//    }
//}

//Задача 2 
//#include <stdio.h>
//#include <stdlib.h> 
//#include <locale.h>
//
//void printMatrix(int array[100][100], int strings, int columns) {
//    for (int i = 0; i < strings; i++) {
//        for (int j = 0; j < columns; j++) {
//            printf("%4d ", array[i][j]);
//        }
//        printf("\n\n");
//    }
//}
//
//void scanf_choice(int* choice) {
//
//    printf("Введите 1, если хотите заполнить массив вручную или введите 2 для автоматического заполнения (для выхода нажмите 3): ");
//    while (scanf_s("%d", choice) != 1 || getchar() != '\n' || *choice > 3 || *choice < 0) {
//        printf("Введите 1, если хотите заполнить массив вручную или введите 2 для автоматического заполнения (для выхода нажмите 3): \n");
//        rewind(stdin);
//    }
//}
//
//void scanf_strings(int* strings) {
//    printf("Введите количество строк в массиве: ");
//    while (scanf_s("%d", strings) != 1 || *strings < 1 || getchar() != '\n' || *strings > 100) {       /*Проверка на ввод значений*/
//        printf("Введите количество строк в массиве (0 < array_size < 100)\n");
//        rewind(stdin);
//    }
//}
//
//void scanf_columns(int* columns) {
//    printf("Введите количество столбцов в массиве: ");
//    while (scanf_s("%d", columns) != 1 || *columns < 1 || getchar() != '\n' || *columns > 100) {       /*Проверка на ввод значений*/
//        printf("Введите количество столбцов в массиве (0 < array_size < 100)\n");
//        rewind(stdin);
//    }
//}
//
//void correctinput(int* k) {
//    printf("\nЕсли хотите продолжить введите любое число, если хотите выйти введите 3: ");
//
//    while (scanf_s("%d", k) != 1 || getchar() != '\n') {
//        printf("Введите любое число если хотите продолжить (для выхода нажмите 3): \n");
//        rewind(stdin);
//    }
//
//}
//
//void randomMatrix(int array[100][100], int strings, int columns) {
//    for (int i = 0; i != strings; i++) {
//        for (int j = 0; j != columns; j++) {
//            array[i][j] = -100 + rand() % 201;
//        }
//    }
//}
//void scanf_input(int* input) {
//    printf("Введите значение для заполнения массива: ");
//    while (scanf_s("%d", input) != 1 || *input > 100 || *input < -100 || getchar() != '\n') {  /*Проверка на ввод значений*/
//        printf("Введите такое значение, чтобы -100<n<100\n");
//        rewind(stdin);
//    }
//}
//
//void inputZ(int strings, int columns, int array[100][100], int input) {
//    for (int i = 0; i < strings; i++) {
//        for (int j = 0; j < columns; j++) {
//            scanf_input(&input);
//            array[i][j] = input;
//        }
//    }
//}
//
//int checkmatrix(int array[100][100], int strings, int columns) {
//    int checknumbers=0;
//    for (int j =0 ; j < columns; j++) {
//        for (int i = 0; i < strings; i++) {
//            if (array[j][i] > 0) {
//                checknumbers++;
//                break;
//            }
//        }
//    }
//    return checknumbers;
//}
//
//void replacementMatrix(int array[100][100], int strings, int columns) {
//    for (int i = 0; i < strings; i++) {
//        for (int j = 0; j < columns; j++) {
//            array[i][j] = -array[i][j];
//        }
//    }
//}
//
//void checkmass(int array[100][100], int strings, int columns) {
//    int check = checkmatrix(array, strings, columns);
//
//    if (check == strings) {
//        replacementMatrix(array, strings, columns);
//    }
//}
//int main() {
//    setlocale(LC_ALL, "Rus");
//    srand(time(0));
//    int array[100][100];
//    int choice = 0, strings = 0, columns = 0;
//    int input = 0;
//    int k = 0;
//
//    while (1) {
//        scanf_choice(&choice);
//        if (choice == 3) {
//            break;
//        }
//        if (choice == 1) {
//            scanf_strings(&strings);
//            scanf_columns(&columns);
//            inputZ(strings, columns, array, input);
//            printf("Вот ваш начальный массив:\n");
//            printMatrix(array, strings, columns);
//            checkmass(array, strings, columns);
//            printf("Вот ваш конечный массив:\n");
//            printMatrix(array, strings, columns);
//            continue;
//
//        }
//        else if (choice == 2) {
//            scanf_strings(&strings);
//            scanf_columns(&columns);
//            randomMatrix(array, strings, columns);
//            printf("Вот ваш начальный массив:\n");
//            printMatrix(array, strings, columns);
//            checkmass(array, strings, columns);
//            printf("Вот ваш конечный массив:\n");
//            printMatrix(array, strings, columns);
//            correctinput(&k);
//
//            if (k == 3) {
//                break;
//            }
//            else {
//                continue;
//            }
//        }
//        return 0;
//    }
//}

// Задача 3

//#include <stdio.h>
//#include <stdlib.h> 
//#include <locale.h>
//
//void scanf_size(int* size) {
//    printf("Введите размерность в массиве(NxN): ");
//    while (scanf_s("%d", size) != 1 || *size < 1 || getchar() != '\n' || *size > 50) {       /*Проверка на ввод значений*/
//        printf("Введите размерность в массиве(NxN) (0 < array_size < 50)\n");
//        rewind(stdin);
//    }
//}
//
//void printMatrix(int array[100][100], int size) {
//    for (int i = 1; i < size+1; i++) {
//        for (int j = 1; j < size+1; j++) {
//            printf("%4d ", array[i][j]);
//        }
//        printf("\n\n");
//    }
//}
//
//void scanf_input(int* input) {
//            
//            while (scanf_s("%d", input) != 1 || *input > 100 || *input < -100 || getchar() != '\n') {  /*Проверка на ввод значений*/
//                printf("Введите такое значение, чтобы -100<n<100\n");
//                rewind(stdin);
//            }           
//        }
//    
//void randomMatrix(int array[100][100], int size) {
//    for (int i = 1; i != size+1; i++) {
//        for (int j = 1; j != size+1; j++) {
//            array[i][j] = -100 + rand() % 201;
//        }
//    }
//}
//
//void inputZ(int size, int array[100][100], int input) {
//    for (int i = 1; i < size+1; i++) {
//        for (int j = 1; j < size+1; j++) {
//            printf("Введите значение для заполнения массива array[%d][%d]: ", i, j);
//            scanf_input(&input);
//            array[i][j] = input;
//        }
//    }
//}
//
//void sumelem1(int size, int sum2, int array[100][100]) {       
//    int s = (size / 2) + 1;
//    for (int p = 1 ; p < s; p++) {
//        for (int k = size; k > size / 2; k--) {
//            sum2 += array[p][k];
//        }
//    }
//    printf("Сумма элементов в области 2 равна: %d\n", sum2);        
//}
//
//void sumelem2(int size, int sum2, int array[100][100]) {
//    int s = (size +1)/2;
//    for (int p = 1; p <= s; p++) {
//        for (int k = size; k >= s; k--) {
//            sum2 += array[p][k];
//        }
//    }
//    printf("Сумма элементов в области 2 равна: %d\n", sum2);
//}
//
//void sumelem3(int size, int sum2, int array[100][100]) {
//    if (size == 1) {
//        sum2 = array[1][1];
//        printf("Сумма элементов в области 2 равна: %d\n", sum2);
//    }
//    else {
//        int s = (size - 1) / 2;
//        for (int p = 1; p <= s; p++) {
//            for (int k = size; k > (size+1)/2; k--) {
//                sum2 += array[p][k];
//            }
//        }
//        printf("Сумма элементов в области 2 равна: %d\n", sum2);
//    }
//}
//
//void scanf_choice(int* choice) {
//
//    printf("Введите 1, если хотите заполнить массив размерностью NxN вручную или введите 2 для автоматического заполнения (для выхода нажмите 3): ");
//    while (scanf_s("%d", choice) != 1 || getchar() != '\n' || *choice > 3 || *choice < 0) {
//        printf("Введите 1, если хотите заполнить массив размерностью NxN вручную или введите 2 для автоматического заполнения (для выхода нажмите 3): \n");
//        rewind(stdin);
//    }
//}
//
//void choose_f(int* choose) {
//    printf("Учитывать ли пересечение чисел сторонами квадрата? Если да, то введите 1, если не учитывать введите 0: ");
//    while (scanf_s("%d", choose) != 1 || getchar() != '\n' || *choose > 1 || *choose < 0) {
//        printf("error\n");
//        rewind(stdin);
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Rus");
//    int size;
//    int array[100][100];
//    int choice = 0;
//    int input = 0;
//    int sum2 = 0;
//    int sum1 = 0;
//    int choose = 0;
//    srand(time(0));
//    while (1) {
//        scanf_choice(&choice);
//        if (choice == 3) {
//            break;
//        }
//        scanf_size(&size);
//        if (choice == 1) {
//            inputZ(size, array, input);
//            printMatrix(array, size);
//            if (size % 2 == 0) {
//                sumelem1(size, sum2, array);
//            }
//            else {
//                choose_f(&choose);
//                if (choose == 1) {
//                    sumelem2(size, sum2, array);
//                }
//                else {
//                    sumelem3(size, sum2, array);
//                }
//            }
//
//        }
//        else if (choice == 2) {
//            randomMatrix(array, size);
//            printMatrix(array, size);
//            if (size % 2 == 0) {
//                sumelem1(size, sum2, array);
//            }
//            else {
//                choose_f(&choose);
//                if (choose == 1) {
//                    sumelem2(size, sum2, array);
//                }
//                else {
//                    sumelem3(size, sum2, array);
//                }
//            }
//        }
//    }
//}
















