#include <iostream>
#include <stdio.h>
#include <Windows.h>
#define NALOG1 0.15 // тариф за первые 300$
#define NALOG2 0.20 // тариф за следующие 150$
#define NALOG3 0.25 // тариф за остальные (>450$) 
#define HOUR 40.0 // Количество часов
#define COEF 1.5 // Коэффициент за с/у
#define SUM1 300.0 // Первые 300$
#define SUM2 450.0 // Следующие 150$
#define STAVKA 10.0 // Тарифная ставка 10$/час

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double hour;  
    double sum = 0, sum1 = 0, nalog = 0, zp = 0;  
    printf("Введите количество часов работы.\n");
    scanf_s("%lf", &hour);  

    if (hour <= HOUR)
    {
        sum = STAVKA * hour;
        if (sum <= SUM1)
            nalog = sum * NALOG1;
        else
            nalog = sum * NALOG2;
    }
    zp = sum - nalog;

    if (hour > HOUR)
    {
        sum1 = (STAVKA * hour - STAVKA * HOUR) * COEF;
        sum = STAVKA * HOUR + sum1;

        if (sum <= SUM2)
            nalog = sum * NALOG2;
        else
            nalog = sum * NALOG3;
    }
    zp = sum - nalog;

    printf("За %.lf часов работы следующий расчет:\nСумма $%1.2f\n\
Налог $%1.2f\nЧистые $%1.2f.\n",hour, sum, nalog, zp);

    return 0;
}

