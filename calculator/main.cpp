#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 4 || argc > 7) {
        cout << "Справочный материал." << endl <<
        "Использование: ./calculator -o operation n1 n2 n3 [n4] [n5] [n6]" << endl <<
        "Где operation может быть:" << endl <<
        "  add - для сложения всех операндов" << endl <<
        "  sub - для вычитания (из первого операнда всех остальных)" << endl;
        exit(0);
    }

    string operation = argv[2];

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
    } else {
        cout << "Неизвестная операция. Используйте 'add' или 'sub'." << endl;
    }

    return 0;
}
