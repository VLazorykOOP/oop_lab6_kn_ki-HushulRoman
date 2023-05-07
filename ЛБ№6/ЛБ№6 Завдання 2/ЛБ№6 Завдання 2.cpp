/*Цей код містить визначення базового абстрактного класу Figure та його чотирьох похідних класів: Parallelepiped, Pyramid, Tetrahedron та Sphere,
які представляють різні геометричні фігури. Усі похідні класи містять метод volume(), який обчислює об'єм відповідної фігури.

У функції main створюється масив вказівників на об'єкти класу Figure, до яких потім присвоюються покажчики на об'єкти створені з використанням оператора new
і конструкторів похідних класів. Потім для кожного елементу масиву викликається метод volume() та результат виводиться на екран. В кінці програми відбувається звільнення пам'яті,
зарезервованої за допомогою оператора new, використовуючи оператор delete.
*/


#include <iostream>
#include <cmath>

// Абстрактний базовий клас "Фігура"
class Figure {
public:
    virtual double volume() const = 0;  // Віртуальна функція об'єму
};

// Похідний клас "Паралелепіпед"
class Parallelepiped : public Figure {
public:
    Parallelepiped(double a, double b, double c) : x(a), y(b), z(c) {}
    virtual double volume() const { return x * y * z; }
private:
    double x, y, z; // сторони паралелепіпеда
};

// Похідний клас "Піраміда"
class Pyramid : public Figure {
public:
    Pyramid(double a, double b, double h) : x(a), y(b), height(h) {}
    virtual double volume() const { return x * y * height / 3; }
private:
    double x, y;     // основа піраміди
    double height;   // висота піраміди
};

// Похідний клас "Тетраедр"
class Tetrahedron : public Figure {
public:
    Tetrahedron(double a) : side(a) {}
    virtual double volume() const { return std::pow(side, 3) * std::sqrt(2) / 12; }
private:
    double side; // сторона тетраедра
};

// Похідний клас "Куля"
class Sphere : public Figure {
public:
    Sphere(double r) : radius(r) {}
    virtual double volume() const { return 4 * M_PI * std::pow(radius, 3) / 3; }
private:
    double radius; // радіус кулі
};

int main() {
    const int N = 4; // Кількість об'єктів
    Figure* figures[N];
    figures[0] = new Parallelepiped(2, 3, 4);
    figures[1] = new Pyramid(3, 4, 5);
    figures[2] = new Tetrahedron(2);

    for (int i = 0; i < N; i++) {
        std::cout << "Об'єм фігури " << i + 1 << " = " << figures[i]->volume() << std::endl;
        delete figures[i]; //звільнити пам'ять
    }

return 0;
}