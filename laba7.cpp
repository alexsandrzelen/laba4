#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

char* removeExtraSpaces(const char* str) {
    char* result = malloc(strlen(str) + 1); // выделяю еще один байт для завершающего нулевого символа 
                   /*возвращает длину строки*/
    if (result==0) return NULL; 

    char* src = str;
    char* dst = result;      // Указатель для записи результата
    int inWord = 0;         

    while (*src) {
        // если текущий символ не пробел
        if (isspace(*src)==0) {
            *dst++ = *src; // Копируем символ
            inWord = 1;    
        }
        else if (inWord) {
            // Если мы находимся в слове и встретили пробел
            *dst++ = ' ';  // Копируем один пробел
            inWord = 0;    // Сбрасываем флаг
        }
        src++; // Переходим к следующему символу
    }

    if (dst != result && (dst - 1) == ' ') {
        dst--;
    }

    *dst = '\0'; 
    return result; // Возвращаем указатель на новую строку
}

int main() {
    setlocale(LC_ALL, "Rus");
    char str[1000]; 
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin); 

    char* cleanedStr = removeExtraSpaces(str);
    if (cleanedStr!=0) {
        printf("Результат: %s\n", cleanedStr);
        free(cleanedStr); 
    }
    else {
        printf("Ошибка выделения памяти.\n");
    }

    return 0;
}
