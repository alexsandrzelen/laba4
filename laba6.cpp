// Задание 1
//#include <stdio.h> 
//#include <stdlib.h> 
//#include <locale.h>
//
//// В одномерном массиве выполнить сортировку четных 
//// элементов методом Хоара 
//
//int* quick_sort(int* arr, int size)
//{
//    if (size < 2)
//        return arr;
//    else
//    {
//        int pivot = arr[0];
//
//        int less_count = 0;
//        int great_count = 0;
//
//        for (int i = 1; i < size; i++)
//        {
//            if (arr[i] >= pivot)
//                great_count++;
//            else
//                less_count++;
//        }
//
//        int i_less = 0;
//        int i_great = 0;
//        int* less=NULL;
//        int* great=NULL;
//        less = calloc(less_count, sizeof(int));
//        if (less == NULL) {
//            printf("Ошибка выделения памяти");
//            exit(1);
//        }
//        great = calloc(great_count, sizeof(int));
//        if (great == NULL) {
//            printf("Ошибка выделения памяти");
//            exit(1);
//        }
//        for (int i = 1; i < size; i++)
//        {
//            if (arr[i] >= pivot)
//            {
//                great[i_great] = arr[i];
//                i_great++;
//            }
//            else
//            {
//                less[i_less] = arr[i];
//                i_less++;
//            }
//        }
//
//        less = quick_sort(less, less_count);
//        great = quick_sort(great, great_count);
//
//        int* merged = (int*)malloc(size * sizeof(int));
//        if (merged == NULL) {
//            printf("Ошибка выделения памяти");
//            exit(1);
//        }
//        for (int i = 0; i < less_count; i++) {
//            merged[i] = less[i];
//        }         
//        merged[less_count] = pivot;
//        for (int i = 0; i < great_count; i++) {
//            merged[less_count + i + 1] = great[i];
//        }
//        free(less);
//        free(great);
//        return merged;
//    }
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Rus");   
//    int n;
//    printf("Введите длину массива: ");
//    while (scanf_s("%d", &n) != 1 || getchar()!='\n'|| n<0) {
//        printf("\nОшибка! Введите длину массива: ");
//        rewind(stdin);
//    }
//
//    int* arr = NULL;
//    arr = (int*)calloc(n, sizeof(int));
//    if (arr == NULL) {
//        printf("Ошибка выделения памяти");
//        exit(1);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        printf("Введите %d элемент: ", i + 1);
//        while (scanf_s("%d", &arr[i]) != 1 || getchar() != '\n') {
//            printf("Ошибка! Введите %d элемент: ", i + 1);
//            rewind(stdin);
//        }
//    }
//
//    int even_size = 0;
//    int i_even = 0;
//    int* even_arr = NULL;
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] % 2 == 0)
//            even_size++;
//    }
//    if (even_size == 0) {
//        printf("В массиве нет четных элементов");
//        return 0;
//    }
//    even_arr = (int*)calloc(even_size, sizeof(int));
//    if (even_arr == NULL) {
//        printf("Ошибка выделения памяти");
//        exit(1);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] % 2 == 0)
//        {
//            even_arr[i_even] = arr[i];
//            i_even++;
//        }
//    }
//
//    printf("Отсортированный массив четных элементов: ");
//    int* sorted = quick_sort(even_arr, even_size);
//    for (int i = 0; i < even_size; i++)
//    {
//        printf("%d ", sorted[i]);
//    }
//
//    return 0;
//}

// Задание 2 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// В матрице размером NxM выполнить сортировку строк по убыванию количества четных элементов методом вставок

void printMatrix(int** array, int strings, int columns) {

    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d ", array[i][j]);
        }
        printf("\n\n");
    }
}

void insertion_sort_rows(int** matrix, int strings, int* numb) {
    for (int i = 1; i < strings; i++) {
        int index = i;
        int count = numb[i]; // Количество четных элементов в строке
        int* string = matrix[i]; // Строка с инедксом i
        int j = i - 1;

        // Сдвигаем строки, которые имеют большее количество четных элементов
        while (j >= 0 && numb[j] < count) {
            numb[j + 1] = numb[j];
            matrix[j + 1] = matrix[j];
            j--;                                                                    // Метод вставок 
        }
        numb[j + 1] = count;
        matrix[j + 1] = string;
    }
}

void chet(int strings, int columns, int** matrix, int* numb) {
    for (int i = 0; i < strings; i++) {
        int a = 0;
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] % 2 == 0) {
                a++;                                                             // Подсчет четных элементов 
            }
        }
        numb[i] = a;
        a = 0;
    }
}


void scanf_strings(int* strings) {
    printf("Введите количество строк в массиве: ");
    while (scanf_s("%d", strings) != 1 || *strings < 1 || getchar() != '\n' || *strings > 100) {       /*Проверка на ввод значений*/
        printf("Введите количество строк в массиве (0 < array_size < 100)\n");
        rewind(stdin);
    }
}

void scanf_columns(int* columns) {
    printf("Введите количество столбцов в массиве: ");
    while (scanf_s("%d", columns) != 1 || *columns < 1 || getchar() != '\n' || *columns > 100) {       /*Проверка на ввод значений*/
        printf("Введите количество столбцов в массиве (0 < array_size < 100)\n");
        rewind(stdin);
    }
}

void randomMatrix(int** array, int strings, int columns) {
    for (int i = 0; i != strings; i++) {
        for (int j = 0; j != columns; j++) {                                      // Функция для рандомного заполнения от 0 до 5
            array[i][j] = 0 + rand() % 6;
        }
    }
}

void scanf_choice(int* choice) {

    printf("Введите 1, если хотите заполнить массив вручную или введите 2 для автоматического заполнения (для выхода нажмите 3): ");
    while (scanf_s("%d", choice) != 1 || getchar() != '\n' || *choice > 3 || *choice < 0) {
        printf("Введите 1, если хотите заполнить массив вручную или введите 2 для автоматического заполнения (для выхода нажмите 3): \n");     /*Проверка на ввод значений*/
        rewind(stdin);
    }
}

void correctinput(int* k) {
    printf("\nЕсли хотите продолжить введите любое число, если хотите выйти введите 3: ");

    while (scanf_s("%d", k) != 1 || getchar() != '\n') {                                              /*Проверка на ввод значений*/
        printf("Введите любое число если хотите продолжить (для выхода нажмите 3): \n");
        rewind(stdin);
    }
}

void scanf_input(int* input) {

    while (scanf_s("%d", input) != 1 || *input > 100 || *input < -100 || getchar() != '\n') {  /*Проверка на ввод значений*/
        printf("Введите такое значение, чтобы -100<n<100\n");
        rewind(stdin);
    }
}

void inputZ(int strings, int columns, int** array, int input) {
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Введите arr[%d][%d]: ", i + 1, j + 1);                   /*Проверка на ввод значений и ввод значений*/
            scanf_input(&input);
            array[i][j] = input;
        }
    }
}


int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int strings = 0, columns = 0, choice = 0, input = 0, k = 0;
    while (1) {
        scanf_choice(&choice);
        if (choice == 3) {
            break;
        }
        if (choice == 1) {
            scanf_strings(&strings);
            scanf_columns(&columns);
            int** matrix = NULL;
            matrix = malloc(strings * sizeof(int*));
            if (matrix == NULL) {
                return 1;
            }
            for (int i = 0; i < strings; i++) {
                matrix[i] = malloc(columns * sizeof(int));
            }         
            inputZ(strings, columns, matrix, input);
            printf("Вот ваша матрица размером %dx%d: \n", strings, columns);
            printMatrix(matrix, strings, columns);
        
            int* numb = NULL;
            numb = calloc(strings, sizeof(int));
            if (numb == NULL) {
                return 1;
            }
            chet(strings, columns, matrix, numb);
            insertion_sort_rows(matrix, strings, numb);
            printf("Вот ваша преобразованная матрица %dx%d: \n", strings, columns);
            printMatrix(matrix, strings, columns);                                 
            free(matrix);
            free(numb);
        }
        else if (choice == 2) {
            scanf_strings(&strings);
            scanf_columns(&columns);
            int** matrix = NULL;
            matrix = malloc(strings * sizeof(int*));
            if (matrix == NULL) {
                return 1;
            }
            for (int i = 0; i < strings; i++) {
                matrix[i] = malloc(columns * sizeof(int));
            }            
            randomMatrix(matrix, strings, columns);
            printf("Вот ваша матрица размером %dx%d: \n", strings, columns);
            printMatrix(matrix, strings, columns);
            int* numb = NULL;
            numb = calloc(strings, sizeof(int));
            if (numb == NULL) {
                return 1;
            }

            chet(strings, columns, matrix, numb);
            insertion_sort_rows(matrix, strings, numb);
            printf("Вот ваша преобразованная матрица %dx%d: \n", strings, columns);
            printMatrix(matrix, strings, columns);
            free(matrix);          
            free(numb);
            
        }
        correctinput(&k);
        if (k == 3) {
            break;
        }
        else {
            continue;
        }
    }
    return 0;
}



   


