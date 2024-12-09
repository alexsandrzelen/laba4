#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

char* removeExtraSpaces(const char* str) {
    char* result = malloc(strlen(str) + 1); // Выделяем память (максимально возможный размер)
                   /*возвращает длину строки*/
    if (result==0) return NULL; // Проверка на успешное выделение памяти

    char* src = str; // Исходный указатель
    char* dst = result;      // Указатель для записи результата
    int inWord = 0;         // Флаг, указывающий, находимся ли мы внутри слова

    while (*src) {
        // Если текущий символ не пробел
        if (isspace(*src)==0) {
            *dst++ = *src; // Копируем символ
            inWord = 1;    // Устанавливаем флаг "внутри слова"
        }
        else if (inWord) {
            // Если мы находимся в слове и встретили пробел
            *dst++ = ' ';  // Копируем один пробел
            inWord = 0;    // Сбрасываем флаг
        }
        src++; // Переходим к следующему символу
    }

    // Удаляем возможный последний пробел
    if (dst != result && (dst - 1) == ' ') {
        dst--;
    }

    *dst = '\0'; // Завершаем строку
    return result; // Возвращаем указатель на новую строку
}

int main() {
    setlocale(LC_ALL, "Rus");
    char str[10000]; // Размер входной строки
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin); // Читаем строку

    char* cleanedStr = removeExtraSpaces(str);
    if (cleanedStr!=0) {
        printf("Результат: %s\n", cleanedStr);
        free(cleanedStr); // Освобождаем выделенную память
    }
    else {
        printf("Ошибка выделения памяти.\n");
    }

    return 0;
}
