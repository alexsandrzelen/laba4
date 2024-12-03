#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//void printMatrix(int* array, int size) {
//
//    for (int i = 0; i < size; ++i) {        
//            printf("%2d ", array[i]);                
//    }
//    printf("\n\n");
//}
//
//
//void scanf_input(int* input) {
//    
//    while (scanf_s("%d", input) != 1 || *input > 100 || *input < -100 || getchar() != '\n') {  /*Проверка на ввод значений*/
//        printf("Введите такое значение, чтобы -100<n<100\n");
//        rewind(stdin);
//    }
//}
//
//void inputZ(int* array, int input, int size) {
//    
//        for (int i = 0; i < size; i++) {
//            printf("Элемент %d: ", i+1);
//            scanf_input(&input);
//            array[i] = input;
//        }
//    
//}
//
//void scanf_size(int* size) {
//    printf("Введите размерность в массивах: ");
//    while (scanf_s("%d", size) != 1 || *size < 1 || getchar() != '\n' || *size > 50) {       /*Проверка на ввод значений*/
//        printf("Введите размерность в массиве (0 < array_size < 50)\n");
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
//}
//
//int sizearr(int* array1, int* array2, int size) {
//    int k = 0;
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            if (array1[i] == array2[j]) {
//                k++;
//                break;
//            }
//        }
//    }
//    return k;
//}
//
//int isPresent(int* arr, int size, int num) {
//    for (int i = 0; i < size; i++) {
//        if (arr[i] == num) {
//            return 1; // Число найдено в массиве
//        }
//    }
//    return 0; // Число не найдено
//}
//
//int main() {    
//    setlocale(LC_ALL, "Rus");
//    int size = 0, j = 0, k = 0, input = 0;
//    
//    while (1) {
//        scanf_size(&size);
//        int* array1 = malloc(size * sizeof(int));
//        int* array2 = malloc(size * sizeof(int));
//        printf("Введите значения для заполнения первого массива: \n");
//        inputZ(array1, input, size);
//        printf("\n\n");
//        printf("Введите значения для заполнения второго массива: \n");
//        inputZ(array2, input, size);
//        printf("\n\n");                               
//        printMatrix(array1, size);
//        printMatrix(array2, size);
//        k = size - sizearr(array1, array2, size)/*Кол-во элементов которые есть и в 1 и во 2 массиве*/;
//        int count = 0;
//        if (k == size) {
//            printf("Вот ваш новый массив: ");
//            printMatrix(array1, size);
//        }
//        else if (k==0){
//            printf("В новом массиве все элементы были удалены");
//        }
//        else {
//            int* array3 = calloc(k, sizeof(int));
//            if (array3 == NULL) {
//                printf("Ошибка при выделении памяти.\n");
//                return 1; // Завершение программы с ошибкой
//            }
//            for (int i = 0; i < size; i++) {
//                if (isPresent(array2, size, array1[i]) != 1) {
//                    array3[count] = array1[i];   // Добавляем элемент
//                    count++;
//                }
//            }
//            printf("Вот ваш новый массив: ");
//            printMatrix(array3, k);
//            free(array3);
//        }
//        
//        free(array1);
//        free(array2);
//        
//        printf("\n\n");
//        correctinput(&k);
//        if (k == 3) {
//            break;
//        }
//        else continue;
//    }
//}
//
//Задание 2

//void printMatrix(int** array, int strings, int columns) {
//
//    for (int i = 0; i < strings; i++) {
//        for (int j = 0; j < columns; j++) {
//            printf("%4d ", array[i][j]);
//        }
//        printf("\n\n");
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
//void randomMatrix(int** array, int strings, int columns) {
//    for (int i = 0; i != strings; i++) {
//        for (int j = 0; j != columns; j++) {
//            array[i][j] = 0 + rand() % 5;
//        }
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
//void correctinput(int* k) {
//    printf("\nЕсли хотите продолжить введите любое число, если хотите выйти введите 3: ");
//
//    while (scanf_s("%d", k) != 1 || getchar() != '\n') {
//        printf("Введите любое число если хотите продолжить (для выхода нажмите 3): \n");
//        rewind(stdin);
//    }
//}
//
//void scanf_input(int* input) {
//    
//    while (scanf_s("%d", input) != 1 || *input > 100 || *input < -100 || getchar() != '\n') {  /*Проверка на ввод значений*/
//        printf("Введите такое значение, чтобы -100<n<100\n");
//        rewind(stdin);
//    }
//}
//
//void inputZ(int strings, int columns, int** array, int input) {
//    for (int i = 0; i < strings; i++) {
//        for (int j = 0; j < columns; j++) {
//            printf("Введите arr[%d][%d]: ", i+1, j+1);
//            scanf_input(&input);
//            array[i][j] = input;
//        }
//    }
//}
//
// int chechzero(int** array, int strings, int columns) {
//    int col = 0;
//    int r = 0;
//    for (int i = 0; i < strings; i++) {
//        if (array[i][columns] == 0) {
//            col++;
//            if (col == 2) {
//                return 1;               
//            }            
//        }
//        else if (array[i][columns]!=0) {
//            col = 0;
//         }
//     }
//    return 0;
//}
//
//int ncolumns(int ** matrix, int strings, int columns) {
//    int cols = 0;
//
//
//    for (int j = 0; j < columns; j++) {
//        if (chechzero(matrix, strings, j) == 1) {
//            cols++;
//        }
//        else {
//
//        }
//    }
//    return cols;
//}
//
//
//
//void newmat(int** matrix, int** newmatrix, int strings, int columns) {
//    int newcol = 0;
//    for (int i = 0; i < columns; i++) {
//        if (chechzero(matrix, strings, i) == 0) {
//            for (int j = 0; j < strings; j++) {
//                newmatrix[j][newcol] = matrix[j][i];
//            }
//            newcol++;
//        }
//    }
//}
//
//int main() {
//    setlocale(LC_ALL, "Rus");
//    srand(time(NULL));
//    int strings = 0, columns = 0, choice = 0, input = 0, k = 0;
//    while (1) {
//        scanf_choice(&choice);
//        if (choice == 3) {
//            break;
//        }
//        if (choice == 1) {
//            scanf_strings(&strings);
//            scanf_columns(&columns);
//            int** matrix = malloc(strings * sizeof(int*));
//            for (int i = 0; i < strings; i++) {
//                matrix[i] = malloc(columns * sizeof(int));
//            }
//            inputZ(strings, columns, matrix, input);
//            printf("Вот ваша матрица размером %dx%d: \n", strings, columns);
//            printMatrix(matrix, strings, columns);
//
//            
//            int ncol = columns - ncolumns(matrix, strings, columns);          
//
//            if (ncol == 0) {
//                printf("Из старого массива были удалены все столбцы ");
//            }
//            
//            else {
//                int** newmatrix = malloc(strings * sizeof(int*));
//                for (int i = 0; i < strings; i++) {
//                    newmatrix[i] = malloc(ncol * sizeof(int));
//                }
//                
//                newmat(matrix, newmatrix, strings, columns);
//                printf("Вот ваша матрица размером %dx%d: \n", strings, ncol);
//                printMatrix(newmatrix, strings, ncol);
//                free(newmatrix);
//            }                                         
//            free(matrix);
//            
//        }
//        else if (choice == 2) {
//            scanf_strings(&strings);
//            scanf_columns(&columns);
//            int** matrix = malloc(strings * sizeof(int*));
//            for (int i = 0; i < strings; i++) {
//                matrix[i] = malloc(columns * sizeof(int));
//            }
//            randomMatrix(matrix, strings, columns);
//            printf("Вот ваша матрица размером %dx%d: \n", strings, columns);
//            printMatrix(matrix, strings, columns);
//
//            int ncol = columns - ncolumns(matrix, strings, columns);
//            if (ncol == 0) {
//                printf("Из старого массива были удалены все столбцы ");
//            }
//            else {
//                int** newmatrix = malloc(strings * sizeof(int*));
//                if (newmatrix == NULL) {
//                    printf("Ошибка выделения памяти");
//                    exit(1);
//                }
//                for (int i = 0; i < strings; i++) {
//                    newmatrix[i] = malloc(ncol * sizeof(int));
//                }
//
//                newmat(matrix, newmatrix, strings, columns);
//                printf("Вот ваша матрица размером %dx%d: \n", strings, ncol);
//                printMatrix(newmatrix, strings, ncol);
//                free(newmatrix);
//            }
//        }
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

// Задание 3 



// Функция для проверки, встречалось ли число ранее
//int isPresent(int* arr, int size, int num) {
//    for (int i = 0; i < size; i++) {
//        if (arr[i] == num) {
//            return 1; // Число найдено
//        }
//    }
//    return 0; // Число не найдено
//}
//
//// Функция для обработки массива
//void processArray(int** matrix, int rows, int K) {
//    for (int i = 0; i < rows; i++) {
//        int seen[] = { 0 }; // Массив для отслеживания встреченных чисел
//        int j = 0;
//
//        printf("Отфильтрованные числа в строке %d: ", i + 1);
//        while (matrix[i][j] != 0) { // Проходим до нуля
//            if (matrix[i][j] <= K && isPresent(seen, MAX_ROWS, matrix[i][j]==1)) {
//                printf("%d ", matrix[i][j]);
//                seen[j] = matrix[i][j]; // Запоминаем число
//            }
//            j++;
//        }
//        printf("\n");
//    }
//}

void input_check(int* input) {
    printf("Введите количество строк массива: ");
    while (scanf_s("%d", input) != 1 || getchar() != '\n' || *input <= 0) {
        printf("\nОшибка: требуется ввести целое положительное число число: ");
        rewind(stdin);
    }
}

void malloc_2d(int*** array, int strings) {
    *array = malloc(strings * sizeof(int*));
    if (*array == NULL) {
        printf("Ошибка выделения памяти для 2D массива.\n");
        exit(1);
    }
}

void malloc_int(int** array, int strings) {
    *array = malloc(strings * sizeof(int));
    if (*array == NULL) {
        printf("Ошибка выделения памяти для 2D массива.\n");
        exit(1);
    }
}

void manual_fill(int** array, int* colCount, int strings) {
    for (int i = 0; i < strings; i++) {
        printf("Введите количество элементов в строке %d: ", i + 1);
        while (scanf_s("%d", &colCount[i]) != 1 || getchar() != '\n' || colCount[i] <= 0) {
            printf("\nОшибка: требуется ввести целое положительное число число: ");
            rewind(stdin);
        }

        array[i] = calloc(colCount[i] + 1, sizeof(int));
        if (array[i] == NULL) {
            printf("Ошибка выделения памяти.\n");
            exit(1);
        }

        for (int j = 0; j < colCount[i]; j++) {
            printf("Введите элемент [%d][%d]: ", i + 1, j + 1);
            while (scanf_s("%d", &array[i][j]) != 1 || getchar() != '\n' || array[i][j] <= 0) {
                printf("\nОшибка: требуется ввести целое число: ");
                rewind(stdin);
            }
        }
    }
}

void random_fill(int** array, int* colCount, int strings) {
    srand(time(NULL));
    for (int i = 0; i < strings; i++) {
        printf("Введите количество элементов в строке %d: ", i + 1);
        while (scanf_s("%d", &colCount[i]) != 1 || getchar() != '\n' || colCount[i] <= 0) {
            printf("\nОшибка: требуется ввести целое положительное число число: ");
            rewind(stdin);
        }

        array[i] = calloc(colCount[i] + 1, sizeof(int));
        if (array[i] == NULL) {
            printf("Ошибка выделения памяти.\n");
            exit(1);
        }

        for (int j = 0; j < colCount[i]; j++) {
            array[i][j] = -10 + rand() % 21;
        }
    }
}

void newrandom_fill(int** array, int* colCount, int strings) {
    srand(time(NULL));

    for (int i = 0; i < strings; i++) {
        array[i] = calloc(colCount[i] + 1, sizeof(int));
        if (array[i] == NULL) {
            printf("Ошибка выделения памяти.\n");
            exit(1);
        }
    }
}           


void print_array(int** array, int* colCount, int strings) {
    printf("Зубчатый массив:\n");
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < colCount[i] + 1; j++) {
            printf("%4d ", array[i][j]);
        }
        printf("\n");
    }
}

void free_memory(int** array, int* colCount, int strings) {
    free(colCount);
    for (int i = 0; i < strings; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    setlocale(LC_ALL, "Rus");

    char choice;
    int strings;
    int check;
    input_check(&strings);

    int** array = NULL;
    malloc_2d(&array, strings);

    int* colCount = NULL;
    malloc_int(&colCount, strings);

    int** newarr = NULL;
    malloc_2d(&newarr, strings);

    int* checkarr = NULL;
    malloc_int(&checkarr, strings);
    for (int i = 0; i < strings; i++) {
        checkarr[i] = 0;
    }


    printf("Введите 'a', если хотите заполнить массив автоматически, любую другую клавишу для заполнения вручную: ");
    choice = getchar();
    switch (choice) {
    case 'a':
        random_fill(array, colCount, strings);
        newrandom_fill(newarr, colCount, strings);
        print_array(array, colCount, strings);
        
        printf("Введите число с которым мы будем сравнивать числа в зубчатом массиве: ");
        scanf_s("%d", &check);
        for (int i = 0; i < strings; i++) {
            for (int j = 0; j < colCount[i]; j++) {
                int num = array[i][j];
                if (num > check && checkarr[num] == 0) {
                    checkarr[num] = 1;
                    newarr[i][j] = num;
                }
            }
        }
        print_array(newarr, colCount, strings);
        break;

    default:
        manual_fill(array, colCount, strings);
        print_array(array, colCount, strings);
        printf("Введите число с которым мы будем сравнивать числа в зубчатом массиве: ");
        scanf_s("%d", &check);
        for (int i = 0; i < strings; i++) {
            for (int j = 0; j < colCount[i]; j++) {
                int num = array[i][j];
                if (num > check && checkarr[num] == 0) {
                    checkarr[num] = 1;
                    array[i][j] = num;
                }
            }
        }
        print_array(array, colCount, strings);
        break;
    }

    free_memory(array, colCount, strings);
    

    return 0;
}



