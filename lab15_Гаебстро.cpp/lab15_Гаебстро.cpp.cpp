// lab15_Гаебстро.cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

bool hasUniqueDigits(int num) {
    bool digits[10] = { false };

    while (num > 0) {
        int digit = num % 10;
        if (digits[digit]) {
            return false;
        }
        digits[digit] = true;
        num /= 10;
    }
    return true;
}

int fillArray(int arr[]) {
    int count = 0;
    for (int i = 100; i <= 999; ++i) {
        if (hasUniqueDigits(i)) {
            arr[count++] = i;
        }
    }
    return count;
}

void sortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr");

    const int MAX_SIZE = 900;
    int uniqueDigitNumbers[MAX_SIZE];

    int actualSize = fillArray(uniqueDigitNumbers);

    std::cout << "Масив чисел з унікальними цифрами: ";
    for (int i = 0; i < actualSize; ++i) {
        std::cout << uniqueDigitNumbers[i] << " ";
    }
    std::cout << std::endl;

    sortDescending(uniqueDigitNumbers, actualSize);

    std::cout << "Відсортований масив у порядку убування: ";
    for (int i = 0; i < actualSize; ++i) {
        std::cout << uniqueDigitNumbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}