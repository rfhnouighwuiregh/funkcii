#include <iostream>
#include <cmath>
using namespace std;


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}


int calculateDateDifference(int day1, int month1, int year1, int day2, int month2, int year2) {
    const int daysInYear = 365;
    int totalDays1 = 0, totalDays2 = 0;

   
    for (int y = 0; y < year1; ++y) {
        totalDays1 += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month1; ++m) {
        totalDays1 += getDaysInMonth(m, year1);
    }
    totalDays1 += day1;

    
    for (int y = 0; y < year2; ++y) {
        totalDays2 += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 1; m < month2; ++m) {
        totalDays2 += getDaysInMonth(m, year2);
    }
    totalDays2 += day2;

    
    return abs(totalDays2 - totalDays1);
}
double calculateAverage(const int array[], int size) {
    if (size == 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum / size;
}
void countElements(const int array[], int size, int& positiveCount, int& negativeCount, int& zeroCount) {
    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; ++i) {
        if (array[i] > 0) {
            ++positiveCount;
        }
        else if (array[i] < 0) {
            ++negativeCount;
        }
        else {
            ++zeroCount;
        }
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    // Задание 1
    int day1 = 1, month1 = 1, year1 = 2000;
    int day2 = 1, month2 = 1, year2 = 2025;
    cout << "Разница между датами: "
        << calculateDateDifference(day1, month1, year1, day2, month2, year2)
        << " дней.\n";

    // Задание 2
    int array1[] = { 1, 2, 3, 4, 5 };
    int size1 = sizeof(array1) / sizeof(array1[0]);
    cout << "Среднее арифметическое массива: "
        << calculateAverage(array1, size1) << "\n";

    // Задание 3
    int array2[] = { 1, -2, 0, 3, -4, 0, 5 };
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int positiveCount, negativeCount, zeroCount;
    countElements(array2, size2, positiveCount, negativeCount, zeroCount);
    cout << "Положительных элементов: " << positiveCount << "\n";
    cout << "Отрицательных элементов: " << negativeCount << "\n";
    cout << "Нулевых элементов: " << zeroCount << "\n";

    return 0;
}
