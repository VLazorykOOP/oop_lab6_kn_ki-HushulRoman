/*Клас ZooPark містить інформацію про зоопарк, таку як його назву, місцезнаходження та контактну інформацію. Клас Keeper містить інформацію про працівника зоопарку, таку як ім'я,
контактну інформацію та досвід роботи. Клас Storage успадковує від Keeper та містить інформацію про ємність зберігання. Клас Attraction містить інформацію про атракціони в зоопарку, 
такі як їх назву та тривалість. Клас Animal містить інформацію про тварин, таку як їх ім'я, вид та вік.

Клас Elephant успадковує від Animal та Attraction та містить додаткову інформацію про поведінку слона при катанні на ньому.
Клас Rhinoceros успадковує від Animal та містить інформацію про поведінку носорога.

Функція printInfo() в кожному класі виводить інформацію про об'єкт на екран.

У функції main() створюються об'єкти кожного класу з відповідною інформацією та викликаються їх функції printInfo() для виведення інформації на екран.*/



#include <iostream>
#include <string>

class ZooPark {
protected:
    std::string name;
    std::string location;
    std::string contact;

public:
    ZooPark(std::string n, std::string l, std::string c) : name(n), location(l), contact(c) {}

    void printInfo() {
        std::cout << "ZooPark name: " << name << std::endl;
        std::cout << "Location: " << location << std::endl;
        std::cout << "Contact info: " << contact << std::endl;
        std::cout << std::endl;
    }
};

class Keeper {
protected:
    std::string name;
    std::string contact;
    int experience;

public:
    Keeper(std::string n, std::string c, int e) : name(n), contact(c), experience(e) {}

    void printInfo() {
        std::cout << "Keeper name: " << name << std::endl;
        std::cout << "Contact info: " << contact << std::endl;
        std::cout << "Experience: " << experience << " years" << std::endl;
        std::cout << std::endl;
    }
};

class Storage : public Keeper {
protected:
    int capacity;

public:
    Storage(std::string n, std::string c, int e, int cap) : Keeper(n, c, e), capacity(cap) {}

    void printInfo() {
        Keeper::printInfo();
        std::cout << "Capacity: " << capacity << " items" << std::endl;
        std::cout << std::endl;
    }
};

class Attraction {
protected:
    std::string name;
    int duration;

public:
    Attraction(std::string n, int d) : name(n), duration(d) {}

    void printInfo() {
        std::cout << "Attraction name: " << name << std::endl;
        std::cout << "Duration: " << duration << " minutes" << std::endl;
    }
};

class Animal {
protected:
    std::string name;
    std::string species;
    int age;

public:
    Animal(std::string n, std::string s, int a) : name(n), species(s), age(a) {}

    void printInfo() {
        std::cout << "Animal name: " << name << std::endl;
        std::cout << "Species: " << species << std::endl;
        std::cout << "Age: " << age << " years" << std::endl;
        std::cout << std::endl;
    }
};

class Elephant : public Animal, public Attraction {
protected:
    std::string behavior;

public:
    Elephant(std::string n, std::string s, int a, std::string b) : Animal(n, s, a), Attraction("Elephant ride", 30), behavior(b) {}

    void printInfo() {
        Animal::printInfo();
        Attraction::printInfo();
        std::cout << "Behavior: " << behavior << std::endl;
        std::cout << std::endl;
    }
};

class Rhinoceros : public Animal {
protected:
    std::string behavior;

public:
    Rhinoceros(std::string n, std::string s, int a, std::string b) : Animal(n, s, a), behavior(b) {}

    void printInfo() {
        Animal::printInfo();
        std::cout << "Behavior: " << behavior << std::endl;
        std::cout << std::endl;
    }
};

int main() {
    ZooPark zoo("Twelfth Months", "Kyiv", "+380943571491");
    zoo.printInfo();
    Keeper keeper("Dmytro", "dmytro@example.com", 5);
    keeper.printInfo();

    Storage storage("Vladyslav", "vlad@example.com", 7, 100);
    storage.printInfo();

    Attraction attraction("Labyrinth", 60);
    attraction.printInfo();

    Animal animal("Leo", "Lion", 3);
    animal.printInfo();

    Elephant elephant("Dumbo", "Asian elephant", 10, "Friendly");
    elephant.printInfo();

    Rhinoceros rhino("Rhino", "Black rhinoceros", 5, "Aggressive");
    rhino.printInfo();

}
