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
//    cout << "ʳ������ ��������: ";
//    cin >> n;
//
//    vector<Student> students(n);
//
//    for (int i = 0; i < n; i++) {
//        cout << "�������: "; cin >> students[i].surname;
//        cout << "�����: "; cin >> students[i].group;
//        cout << "������: ";
//        for (int j = 0; j < 5; j++) cin >> students[i].grades[j];
//    }
//
//    cout << "³�������:" << E;
//    for (int i = 0; i < n; i++) {
//        if (countExcellent(students[i].grades) >= 4)
//            cout << students[i].surname << " (" << students[i].group << ")" << E;
//    }
//
//    cout << "�⳺�����:" << E;
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
        cout << "1. ������" << E;
        cout << "2. ��������" << E;
        cout << "3. ��������� �� ��������" << E;
        cout << "4. ��������� �� ��'��" << E;
        cout << "5. �����" << E;
        cout << "6. ����������" << E;
        cout << "7. ���������� �����" << E;
        cout << "8. �����" << E;
        cout << "����: "; cin >> choice;

        if (choice == 1) {
            Man newMan;
            cout << "�������: "; cin >> newMan.surname;
            cout << "��'�: "; cin >> newMan.name;
            cout << "³�: "; cin >> newMan.age;
            cout << "���� ����������: "; cin >> newMan.birthdate;
            people.push_back(newMan);
        }
        else if (choice == 2) {
            string surname;
            cout << "������� ��� ���������: "; cin >> surname;
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
            cout << "�������: "; cin >> surname;
            cout << "��'�: "; cin >> name;
            auto it = find_if(people.begin(), people.end(), [&](Man& man) { return man.surname == surname && man.name == name; });
            if (it != people.end()) cout << it->surname << " " << it->name << " " << it->age << " " << it->birthdate << E;
            else cout << "�� ��������!" << E;
        }
        else if (choice == 6) {
            string surname;
            cout << "������� ��� �����������: "; cin >> surname;
            auto it = find_if(people.begin(), people.end(), [&](Man& man) { return man.surname == surname; });
            if (it != people.end()) {
                cout << "���� ��'�: "; cin >> it->name;
                cout << "����� ��: "; cin >> it->age;
                cout << "���� ���� ����������: "; cin >> it->birthdate;
            }
            else cout << "�� ��������!" << E;
        }
        else if (choice == 7) {
            string month;
            cout << "̳����: "; cin >> month;
            for (auto& man : people) {
                if (man.birthdate.substr(3, 2) == month) cout << man.surname << " " << man.name << " " << man.birthdate << E;
            }
        }

    } while (choice != 8);

    return 0;
}
