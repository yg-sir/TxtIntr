#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept> // Для std::invalid_argument
using namespace std;

bool isNumber(const string& str) {
    try {
        std::stod(str); // Попытка преобразовать строку в число
        return true;
    } catch (const std::invalid_argument&) {
        return false; // Если не удалось преобразовать, значит это не число
    } catch (const std::out_of_range&) {
        return false; // Если число выходит за пределы диапазона
    }
}

int main(int argc, char* argv[])
{
    if (argc < 7 || argc > 9) {
        cout << "Справочный материал." << endl <<
        "Использование: ./calculator -o operation n1 n2 n3 [n4] [n5] [n6]" << endl <<
        "Где operation может быть:" << endl <<
        "  add - для сложения всех операндов" << endl <<
        "  sub - для вычитания (из первого операнда всех остальных)" << endl;
        return 1; // Завершение программы с кодом ошибки
    }

    string operation = argv[2];

    // Проверка на корректность операции
    if (operation != "add" && operation != "sub") {
        cout << "Ошибка: '" << operation << "' Не является допустимой операцией." << endl;
        return 1; // Завершение программы с кодом ошибки
    }

    // Проверка на корректность чисел
    for (int i = 3; i < argc; ++i) {
        if (!isNumber(argv[i])) {
            cout << "Ошибка: '" << argv[i] << "' Не является числом." << endl;
            return 1; // Завершение программы с кодом ошибки
        }
    }

    if (operation == "add") {
        double sum = 0;
        for (int i = 3; i < argc; ++i) {
            sum += atof(argv[i]);
        }
        cout << "Сумма: " << sum << endl;
    } else if (operation == "sub") {
        double result = atof(argv[3]);
        for (int i = 4; i < argc; ++i) {
            result -= atof(argv[i]);
        }
        cout << "Результат вычитания: " << result << endl;
    }

    return 0;
}
