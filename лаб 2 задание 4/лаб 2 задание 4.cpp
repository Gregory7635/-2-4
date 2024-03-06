#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
double calculateAverage(std::vector<int> numbers) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers[i] > 0 && (i + 1) % 3 == 0) {
            sum += numbers[i];
            count++;
        }
    }

    return sum / count;
}

int main() {
    setlocale(LC_ALL, "RU");
    ifstream file("b.txt");
    if (!file.is_open()) {
        cout << "Ошибка" << endl;
    }
    cout << "Исходный файл: " << endl;
    int r;
    while (file >> r) {
        cout << r << endl;
    }
    file.close();
    file.open("b.txt");
    vector<int> numbers;
    int num;
    while (file >> num) {
        numbers.push_back(num);
    }

    file.close();

    double average = calculateAverage(numbers);

    cout << "среднее значение среди положительных значений файла, номера которых кратны трем : " << average << endl;

    return 0;
}