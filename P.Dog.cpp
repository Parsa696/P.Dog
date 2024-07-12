#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Dog {
public:
    // ویژگی‌ها
    string name;
    int birthYear;

    // سازنده‌ی کلاس
    Dog(string n, int bYear) : name(n), birthYear(bYear), score(0) {}

    // متود برای محاسبه سن
    int getAge() {
        time_t t = time(0);  // زمان فعلی را می‌گیرد
        struct tm *now = localtime(&t);
        int currentYear = now->tm_year + 1900;
        return currentYear - birthYear;
    }

    // متود برای پارس کردن سگ
    void bark() {
        cout << name << " says: Woof! Woof!" << endl;
    }

    // متود برای افزایش امتیاز
    void learn() {
        score++;
    }

    // متود برای نمایش اطلاعات سگ
    void showData() {
        cout << "Name: " << name << endl;
        cout << "Age: " << getAge() << " years old" << endl;
        cout << "Score: " << score << endl;
    }

private:
    // امتیاز که خصوصی است
    int score;
};

int main() {
    string name;
    int birthYear;
    int command;

    // دریافت اطلاعات اولیه سگ از کاربر
    cout << "Enter the name of the dog: ";
    getline(cin, name);
    cout << "Enter the birth year of the dog: ";
    cin >> birthYear;

    // ایجاد شیء سگ با اطلاعات وارد شده
    Dog myDog(name, birthYear);

    // حلقه برای دریافت دستورات از کاربر
    do {
        cout << "Enter 1 to bark, 2 to learn, 0 to exit and show data: ";
        cin >> command;

        if (command == 1) {
            myDog.bark();
        } else if (command == 2) {
            myDog.learn();
        }
    } while (command != 0);

    // نمایش اطلاعات نهایی سگ
    myDog.showData();

    return 0;
}
