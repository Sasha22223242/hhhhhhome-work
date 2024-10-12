//#include <iostream>
//#include <Windows.h>
//#include <vector>
//using namespace std;
//
//#define E endl
//
//struct Student {
//    string surname, group;
//    int grades[5];
//};
//
//int countExcellent(int grades[5]) {
//    int count = 0;
//    for (int i = 0; i < 5; i++) if (grades[i] == 5) count++;
//    return count;
//}
//
//int countBad(int grades[5]) {
//    int count = 0;
//    for (int i = 0; i < 5; i++) if (grades[i] == 2 || grades[i] == 3) count++;
//    return count;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int n;
//    cout << "Кількість студентів: ";
//    cin >> n;
//
//    vector<Student> students(n);
//
//    for (int i = 0; i < n; i++) {
//        cout << "Прізвище: "; cin >> students[i].surname;
//        cout << "Група: "; cin >> students[i].group;
//        cout << "Оцінки: ";
//        for (int j = 0; j < 5; j++) cin >> students[i].grades[j];
//    }
//
//    cout << "Відмінники:" << E;
//    for (int i = 0; i < n; i++) {
//        if (countExcellent(students[i].grades) >= 4)
//            cout << students[i].surname << " (" << students[i].group << ")" << E;
//    }
//
//    cout << "Двієчники:" << E;
//    for (int i = 0; i < n; i++) {
//        if (countBad(students[i].grades) >= 3)
//            cout << students[i].surname << " (" << students[i].group << ")" << E;
//    }
//
//    return 0;
//}
//#2
#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

#define E endl

struct Man {
    string surname, name, birthdate;
    int age;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Man> people;
    int choice;

    do {
        cout << "1. Додати" << E;
        cout << "2. Видалити" << E;
        cout << "3. Сортувати за прізвищем" << E;
        cout << "4. Сортувати за ім'ям" << E;
        cout << "5. Пошук" << E;
        cout << "6. Редагувати" << E;
        cout << "7. Іменинники місяця" << E;
        cout << "8. Вийти" << E;
        cout << "Вибір: "; cin >> choice;

        if (choice == 1) {
            Man newMan;
            cout << "Прізвище: "; cin >> newMan.surname;
            cout << "Ім'я: "; cin >> newMan.name;
            cout << "Вік: "; cin >> newMan.age;
            cout << "Дата народження: "; cin >> newMan.birthdate;
            people.push_back(newMan);
        }
        else if (choice == 2) {
            string surname;
            cout << "Прізвище для видалення: "; cin >> surname;
            people.erase(remove_if(people.begin(), people.end(), [&](Man& man) { return man.surname == surname; }), people.end());
        }
        else if (choice == 3) {
            sort(people.begin(), people.end(), [](Man& a, Man& b) { return a.surname < b.surname; });
            for (auto& man : people) cout << man.surname << " " << man.name << " " << man.age << " " << man.birthdate << E;
        }
        else if (choice == 4) {
            sort(people.begin(), people.end(), [](Man& a, Man& b) { return a.name < b.name; });
            for (auto& man : people) cout << man.surname << " " << man.name << " " << man.age << " " << man.birthdate << E;
        }
        else if (choice == 5) {
            string surname, name;
            cout << "Прізвище: "; cin >> surname;
            cout << "Ім'я: "; cin >> name;
            auto it = find_if(people.begin(), people.end(), [&](Man& man) { return man.surname == surname && man.name == name; });
            if (it != people.end()) cout << it->surname << " " << it->name << " " << it->age << " " << it->birthdate << E;
            else cout << "Не знайдено!" << E;
        }
        else if (choice == 6) {
            string surname;
            cout << "Прізвище для редагування: "; cin >> surname;
            auto it = find_if(people.begin(), people.end(), [&](Man& man) { return man.surname == surname; });
            if (it != people.end()) {
                cout << "Нове ім'я: "; cin >> it->name;
                cout << "Новий вік: "; cin >> it->age;
                cout << "Нова дата народження: "; cin >> it->birthdate;
            }
            else cout << "Не знайдено!" << E;
        }
        else if (choice == 7) {
            string month;
            cout << "Місяць: "; cin >> month;
            for (auto& man : people) {
                if (man.birthdate.substr(3, 2) == month) cout << man.surname << " " << man.name << " " << man.birthdate << E;
            }
        }

    } while (choice != 8);

    return 0;
}
