#include <iostream>
#include <vector>
#include <string>

struct EBook {
    std::string firm;
    float screenSize;
    bool backlight;
};

void inputEBook(EBook* book) {
    std::cout << "Введите фирму-производителя: ";
    std::cin >> book->firm;
    std::cout << "Введите размер экрана (в дюймах): ";
    std::cin >> book->screenSize;
    std::cout << "Есть ли подсветка экрана (1 - да, 0 - нет): ";
    std::cin >> book->backlight;
}

void displayEBook(const EBook* book) {
    std::cout << "Фирма-производитель: " << book->firm << "\n";
    std::cout << "Размер экрана: " << book->screenSize << " дюймов\n";
    std::cout << "Подсветка экрана: " << (book->backlight ? "да" : "нет") << "\n";
}

void addEBook(std::vector<EBook*>& library) {
    EBook* newBook = new EBook;
    inputEBook(newBook);
    library.push_back(newBook);
}

void displayLibrary(const std::vector<EBook*>& library) {
    for (size_t i = 0; i < library.size(); ++i) {
        std::cout << "Электронная книга " << (i + 1) << ":\n";
        displayEBook(library[i]);
        std::cout << std::endl;
    }
}

int main() {
    std::vector<EBook*> library;
    int choice;

    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить электронную книгу\n";
        std::cout << "2. Показать все книги\n";
        std::cout << "3. Выход\n";
        std::cout << "Выбрите пункт меню: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addEBook(library);
                break;
            case 2:
                displayLibrary(library);
                break;
            case 3:
                std::cout << "Ухади.\n";
                break;
            default:
                std::cout << "Я сьем твою собаку.\n";
        }
    } while (choice != 3);

    for (EBook* book : library) {
        delete book;
    }
    
    return 0;
}
