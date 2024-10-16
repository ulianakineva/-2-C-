#include <iostream>
#include <string>
#include <deque>
#include <limits>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <set>
#include <map>

using namespace std;

void task1() {
    int n;
    cout << "Введите четное количество элементов: ";
    while (!(cin >> n) || (n % 2 != 0)) {
        cout << "Некорректный ввод. Введите четное число: ";
        cin.clear();
    }

    deque<int> D;
    cout << "Введите " << n << " элементов: ";

    for (int i = 0; i < n; ) {
        int num;
        if (cin >> num) {
            D.push_back(num);
            i++;
        } else {
            cout << "Ошибка ввода. Пожалуйста, введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    if (D.size() != n) {
        cout << "Ошибка: Введено больше чисел, чем указано." << endl;
        return;
    }
    cout << "Первая половина в обратном порядке: ";
    for (auto it = D.rbegin() + n / 2; it != D.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Вторая половина в обратном порядке: ";
    for (auto it = D.rbegin(); it != D.rbegin() + n / 2; ++it) {
        cout << *it << " ";
    }
    cout << endl;


}

void task2() {
    int n;
    cout << "Введите количество элементов для вектора: ";
    while (!(cin >> n)) {
        cout << "Ошибка ввода. Введите целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if( n > 0) {
        vector<int> V(n);
        cout << "Введите " << n << " элементов для вектора: ";
        for (auto it = V.begin(); it != V.end(); ++it) {
            while (!(cin >> *it)) {
                cout << "Ошибка ввода. Введите целое число: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        for (auto i = V.begin(); i != V.end(); ) {
            i = V.insert(++i, -1); // Вставляем -1 после элемента, на который указывает i
            ++i; // Переходим к следующему элементу
        }

        // Вывод элементов вектора
        cout << "Вектор после вставки: ";
        for (auto it = V.begin(); it != V.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    else {
        cout << "Ошибка ввода. Введите положительное целое число. Количество элементов в векторе не может быть отрицательным. " << endl;

    }
}
void task3() {
    int n;
    cout << "Введите нечетное количество элементов для дека (не менее 3): ";
    while (!(cin >> n) || (n % 2 == 0) || (n < 3)) {
        cout << "Некорректный ввод. Введите нечетное число не менее 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    deque<int> D(n);
    cout << "Введите " << n << " элементов для дека: ";
    for (auto it = D.begin(); it != D.end(); ++it) {
        while (!(cin >> *it)) {
            cout << "Ошибка ввода. Введите целое число: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    auto it = D.begin() + (n - 1) / 2;
    D.erase(it);

    // Вывод элементов дека
    cout << "Дек после удаления среднего элемента: ";
    for (auto it = D.begin(); it != D.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int task4() {
    string name;
    int K;

    cout << "Введите имя текстового файла: ";
    cin >> name;

    cout << "Введите количество символов '*': ";
    cin >> K;
    if (K > 0) {

        ofstream outputFile(name);
        if (!outputFile) {
            cerr << "Ошибка открытия файла!" << endl;
            return 1;
        }

        fill_n(ostream_iterator<char>(outputFile), K, '*');

        cout << "Символы '*' записаны в файл " << name << endl;
    } else {cout << "Ошибка ввода. Введите положительное целое число. " << endl;}
    }



void task5() {
    int sizeV;
    cout << "Введите размер вектора V (четное число): ";
    while (!(cin >> sizeV) || (sizeV % 2 != 0)) {
        cout << "Ошибка: введите четное число! Попробуйте снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (sizeV > 0) {
        vector<int> V(sizeV);
        cout << "Введите элементы вектора V: ";
        for (int i = 0; i < sizeV; ++i) {
            while (!(cin >> V[i])) {
                cout << "Ошибка: введите целое число! Попробуйте снова: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }



        list<int> L;
        int element;
        cout << "Введите элементы списка L (введите 0 для завершения ввода): ";
        while (true) {
            if (!(cin >> element)) {
                cout << "Ошибка: введите целое число! Попробуйте снова: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (element == 0) {
                break;
            }
            L.push_back(element);
        }

        int middle = V.size() / 2;

        auto it = find_first_of(L.begin(), L.end(), V.begin(), V.begin() + middle);



        if (it != L.end()) {
            L.insert(++it, *it);
        }


        cout << "Список L после дублирования: ";
        for (int i : L) {
            cout << i << " ";
        }
        cout << endl;

} else {cout << "Ошибка ввода. Введите положительное целое число. " << endl;
}

}



void task6() {
    int k;
    cout << "Введите число K (0 < K < 10): ";
    cin >> k;

    // Проверка условия для K
    if (k <= 0 || k >= 10) {
        cout << "Ошибка: число K должно быть в диапазоне от 1 до 9!" << endl;
        return;
    }

    vector<int> L1(10);
    vector<int> L2(10);

    cout << "Введите элементы списка L1: ";
    for (int i = 0; i < 10; ++i) {
        cin >> L1[i];
    }

    cout << "Введите элементы списка L2: ";
    for (int i = 0; i < 10; ++i) {
        cin >> L2[i];
    }

    // Вывод исходных списков
    cout << "Список L1 перед сдвигом: ";
    for (int i : L1) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Список L2 перед сдвигом: ";
    for (int i : L2) {
        cout << i << " ";
    }
    cout << endl;

    // Сдвиг вправо для L1
    rotate(L1.begin(), L1.end() - k, L1.end());

    // Сдвиг влево для L2
    rotate(L2.begin(), L2.begin() + k, L2.end());

    // Вывод результатов
    cout << "Список L1 после сдвига вправо: ";
    for (int i : L1) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Список L2 после сдвига влево: ";
    for (int i : L2) {
        cout << i << " ";
    }
    cout << endl;
}



#include <iostream>
#include <vector>
#include <algorithm> // Для std::partial_sort

using namespace std;

void task7() {
    vector<int> V;
    int n;

    cout << "Введите количество элементов вектора: ";
    cin >> n;

    if (n < 3) {
        cout << "Вектор должен содержать не менее 3 элементов." << endl;
        return;
    }

    cout << "Введите элементы вектора: ";
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        V.push_back(element);
    }

    partial_sort(V.end(), V.end(), V.begin(), greater<int>());

    cout << "Три последних элемента вектора после сортировки (в порядке убывания): ";
    for (int i = V.size() - 1; i > V.size() - 4; --i) {
        cout << V[i] << " ";
    }
    cout << endl;
}


void task8() {

    list<int> L;
    int n;

    cout << "Введите количество элементов списка: ";
    cin >> n;

    if (n < 2) {
        cout << "Список должен содержать не менее 2 элементов." << endl;
        return;
    }

    cout << "Введите элементы списка: ";
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        L.push_back(element);
    }

    vector<double> V;
    adjacent_difference(L.begin(), L.end(), back_inserter(V),
                        [](int a, int b) { return static_cast<double>(a + b) / 2; });


    V.erase(V.begin());

    cout << "Вектор V (средние арифметические пар соседних элементов): ";
    for (double element : V) {
        cout << element << " ";
    }
    cout << endl;
}

int task9() {
    vector<int> V0;
    int N;

    cout << "Введите размер вектора V0: ";
    cin >> N;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();

        cout << "Не корректный ввод!" << endl;
        return -1;
    }
    if (N <= 0) {
        cout << "Размер вектора V0 должен быть больше 0." << endl;
        return -1;
    }

    cout << "Введите элементы вектора V0: ";
    for (int i = 0; i < N; ++i) {
        int element;
        cin >> element;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();

            cout << "Не корректный ввод!" << endl;
            return -1;
        }
        V0.push_back(element);
    }

    int count = 0;

    cout << "Введите количество векторов V1, ..., VN: ";
    cin >> N;
    if (cin.fail()) {
        cin.clear();
        cin.ignore();

        cout << "Не корректный ввод!" << endl;
        return -1;
    }
    if (N < 0) {
        cout << "Количество векторов не может быть меньше нуля." << endl;
        return -1;
    }
    for (int i = 1; i <= N; ++i) {
        int size;
        cout << "Введите размер вектора V" << i << ": ";
        cin >> size;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();

            cout << "Не корректный ввод!" << endl;
            return -1;
        }
        if (size < N) {
            cout << "Размер вектора V" << i << " должен быть не меньше размера V0." << endl;
            return -1;
        }

        vector<int> Vi(size);
        cout << "Введите элементы вектора V" << i << ": ";
        for (int j = 0; j < size; ++j) {
            cin >> Vi[j];
        }
        set<int> sV0(V0.begin(), V0.end());
        set<int> sVi(Vi.begin(), Vi.end());


        if (includes(sVi.begin(), sVi.end(), sV0.begin(), sV0.end())) {
            count++;
        }
    }

    cout << "Количество векторов VI, содержащих все элементы V0: " << count << endl;
    return 0;
}

void task10() {
    vector<string> V;
    int n;

    cout << "Введите количество элементов вектора: ";
    cin >> n;

    if (n <= 0) {
        cout << "Количество элементов вектора должно быть больше 0." << endl;
        return;
    }

    cout << "Введите элементы вектора (заглавные буквы): ";
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;

        if (!all_of(word.begin(), word.end(), ::isupper)) {
            cout << "Все слова должны быть набраны заглавными буквами." << endl;
            return;
        }

        V.push_back(word);
    }

    map<char, int> M;


    for (const auto& word : V) {
        M[word[0]] += word.size();
    }

    // Вывод результатов
    for (const auto& pair : M) {
        cout << pair.first << pair.second << " ";
    }
    cout << endl;
}

int main() {
    system("chcp 65001");
    cout << "Лабораторная номер 2" << endl;
    cout << "Вариант 6" << endl;

    int count;
    string name;
    int K;





    cout << "Введите номер задания от 1 до 10."<< endl;
    cin >> count;
    while (count != 0){
        switch (count) {
            case 1:

                task1();
            break;

            case 2:
                task2();
            break;

            case 3:
                task3();
                break;

            case 4:


                task4();

                break;

            case 5:

                task5();



                break;

            case 6:
                task6();
            break;



            case 7:
                task7();
            break;

            case 8:
                task8();
            break;

            case 9:
                task9();
            break;

            case 10:
                task10();
            break;

            default:
                cout << "Такого задания нет";
            break;
        }
        cout << "Введите номер задания от 1 до 20. Введите 0, чтобы закончить."<< endl;
        cin >> count;
    }
    return 0;
}
