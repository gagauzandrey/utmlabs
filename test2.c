/*
Подключние рабочих библиотек:
    <stdio.h> - библиотека ввода/вывода
*/
#include <stdio.h>

int main(int argc, char* argv[])
{
    /* Именованная константа, определяющая количество элементов массива */
    const    MAX_ELEMENTS = 8;

    /* Объявление и инициализация переменных */
    float    m[MAX_ELEMENTS];
    float    sum = 0;
    float    result = 1;
    int      iMax, iMin;
    int      i;

    /* Запрашиваем ввод данных с клавиатуры */
    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        printf("m[%d] = ", i);
        scanf("%f", &m[i]);
    }

/* Принимаем индексы максимального и минимального массива равными 0 */
    iMin = iMax = 0;
    for (i = 0; i < MAX_ELEMENTS; i++)
    {
        /* Вычисляем сумму отрицательных элементов массива */
        if (m[i] < 0) sum += m[i];

        /* Находим индексы максимального и минимального элементов массива */
        if (m[i] > m[iMax]) iMax = i;
        if (m[i] < m[iMin]) iMin = i;
    }

    /* Находим произведение элементов массива, находящихся между минимальным и максимальными элементами */
    for (i = ((iMax < iMin) ? iMax : iMin);
        i <= ((iMax > iMin) ? iMax : iMin);
        result *= m[i++]);

    /* Выводим на экран результат вычислений */
    printf("iMax = %d", iMax);
    printf("\nСумма отрицательных элементов = %.2f\n", sum);
    printf("Результат = %.2f\n\n", result);

    /* Сортировка элементов массива по возрастанию */
    for (i = 0; i < MAX_ELEMENTS; i++)
    {
        for (int j = i + 1; j < MAX_ELEMENTS; j++)
        {
            if (m[i] > m[j])
            {
                result = m[i];
                m[i] = m[j];
                m[j] = result;
            }
        }
    }

    /* Вывод на экран отсортированного по возрастанию массива */
    printf("Отсортированный массив:\n");
    for (i = 0; i < MAX_ELEMENTS; printf("%.2f ", m[i++]));

    return 0;
}
