#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include "main.h"

using namespace std;

string formatDate(const Prop::Date& date) {
    string formattedDate;

    if (date.day < 10) {
        formattedDate += "0";
    }
    formattedDate += to_string(date.day) + ".";

    if (date.month < 10) {
        formattedDate += "0";
    }
    formattedDate += to_string(date.month) + ".";

    formattedDate += to_string(date.year);

    return formattedDate;
}

void printProduct(const Prop& product) {
    cout << "Імʼя: " << product.name << endl;
    cout << "Виробник: " << product.producer << endl;
    cout << "Ціна: " << product.price << " UAH" << endl;
    cout << "Група: " << product.group << endl;
    cout << "Дата отримання: " << formatDate(product.receivedDate) << endl;
    cout << "Вжити до: " << formatDate(product.expirationDate) << endl;
    cout << "---------------------------" << endl << endl;
}

void printProducts() {
    for (int i = 0; i < arrsize; ++i) {
        printProduct(products[i]);
    }
    int choose;
    cout << "Головне меню (1), або завершення программи (2): " << endl;
    cin >> choose;
    if (choose == 1) {
        showMenu();
    } else exit(0);
}

void inputDate(Prop::Date& date, const string& dateType) {
    cout << "Введіть " << dateType << " (день місяць рік): ";
    cin >> date.day >> date.month >> date.year;

    if (date.month < 1 || date.month > 12) {
        cout << "Помилка: Невалідний місяць" << endl;
        return;
    }

    if (date.day < 1 || date.day > 31) {
        cout << "Помилка: Невалідний день" << endl;
        return;
    }
}

void addProduct() {
    cout << "Для додавання товару потрібно вказати: імʼя, виробника, ціна, группу, дату надходження та термін придатності." << endl;

    Prop newProduct;

    cout << "Введіть: " << endl;

    cout << "Імʼя: " << endl;
    cin >> newProduct.name;
    cout << "Виробника: " << endl;
    cin >> newProduct.producer;
    cout << "Ціну: " << endl;
    cin >> newProduct.price;
    cout << "Группу: " << endl;
    cin >> newProduct.group;
    inputDate(newProduct.receivedDate, "Дату надходження: ");
    inputDate(newProduct.expirationDate, "Термін придатності: ");

    arrsize += 1;

    Prop* newProducts = new Prop[arrsize];

    for (int i = 0; i < arrsize - 1; ++i) {
        newProducts[i] = products[i];
    }

    newProducts[arrsize - 1] = newProduct;

    delete[] products;

    products = newProducts;
};

void deleteProduct() {

    cout << "Введіть індекс продукту який ви хочете видалити:" << endl;
    cin >> arrIndex;

    arrsize -= 1;
    Prop* newProducts = new Prop[arrsize];

    for (int i = 0; i < arrsize; ++i) {
        if (i != arrIndex) {
            products[i] = newProducts[i];
        }
    }

    delete[] products;

    products = newProducts;

    cout << "Видалення успішне!" << endl;
    showMenu();
};

void replaceProduct() {
    int replaceIndex;
    cin >> replaceIndex;
    cin >> arrIndex;

    Prop* newProducts = new Prop[arrsize];

    for (int i = 0; i < arrsize; ++i) {
        if (i != replaceIndex && i != arrIndex) {
            newProducts[i] = products[i];
        } else {
            products[arrIndex] = newProducts[replaceIndex];
            products[replaceIndex] = newProducts[arrIndex];
        }
    }

    delete[] products;

    products = newProducts;

    cout << "Заміна відбулась успішно!" << endl;
    showMenu();
};

void findProduct(int choose) {
    switch (choose) {
        case 1: {
            string searchRequest;
            cout << "Введіть шуковане імʼя: " << endl;
            cin >> searchRequest;

            for (int i = 0; i < arrsize; ++i) {
                if (products[i].name == searchRequest) {
                    cout << products[i].name << endl;
                }
            }
            cout << "Меню (1), завершення программи (2):" << endl;
            int chooseMenu;
            cin >> chooseMenu;
            if (choose == 1) {
                showMenu();
            } else exit(0);

        }
        case 2: {
            string searchRequest;
            cout << "Введіть шуковану группу: " << endl;
            cin >> searchRequest;

            for (int i = 0; i < arrsize; ++i) {
                if (products[i].producer == searchRequest) {
                    cout << products[i].producer << endl;
                }
            }
            cout << "Меню (1), завершення программи (2):" << endl;
            int chooseMenu;
            cin >> chooseMenu;
            if (choose == 1) {
                showMenu();
            } else exit(0);
        }
        case 3: {
            unsigned int searchRequest;
            cout << "Введіть шуковану ціну: " << endl;
            cin >> searchRequest;

            for (int i = 0; i < arrsize; ++i) {
                if (products[i].price == searchRequest) {
                    cout << products[i].price << endl;
                }
            }
            cout << "Меню (1), завершення программи (2):" << endl;
            int chooseMenu;
            cin >> chooseMenu;
            if (choose == 1) {
                showMenu();
            } else exit(0);
        }
        case 4: {
            string searchRequest;
            cout << "Введіть шуковану групу: " << endl;
            cin >> searchRequest;

            for (int i = 0; i < arrsize; ++i) {
                if (products[i].group == searchRequest) {
                    cout << products[i].group << endl;
                }
            }
            cout << "Меню (1), завершення программи (2):" << endl;
            int chooseMenu;
            cin >> chooseMenu;
            if (choose == 1) {
                showMenu();
            } else exit(0);
        }
        case 5: {
            Prop::Date searchRequest{};
            inputDate(searchRequest, "Введіть шуковану дату надходження: ");

            for (int i = 0; i < arrsize; ++i) {
                if (products[i].expirationDate.day == searchRequest.day && products[i].expirationDate.month == searchRequest.month && products[i].expirationDate.year == searchRequest.year) {
                    cout << products[i].expirationDate.day << " " << products[i].expirationDate.month << " " << products[i].expirationDate.year << " " << endl;
                }
            }
            cout << "Меню (1), завершення программи (2):" << endl;
            int chooseMenu;
            cin >> chooseMenu;
            if (choose == 1) {
                showMenu();
            } else exit(0);
        }
        case 6: {
            Prop::Date searchRequest{};
            inputDate(searchRequest, "Введіть шукований термін придатності: ");


            for (int i = 0; i < arrsize; ++i) {
                if (products[i].expirationDate.day == searchRequest.day && products[i].expirationDate.month == searchRequest.month && products[i].expirationDate.year == searchRequest.year) {
                    cout << products[i].expirationDate.day << " " << products[i].expirationDate.month << " " << products[i].expirationDate.year << " " << endl;
                }
            }
            cout << "Меню (1), завершення программи (2):" << endl;
            int chooseMenu;
            cin >> chooseMenu;
            if (choose == 1) {
                showMenu();
            } else exit(0);
        }
        default: {
            cout << "Ну сюди воно просто не зможе дойти із-за перевірки на рівні вище, але я повинен додати кейс за замовчуванням" << endl;
            exit(1);
        }
    }
};

void sortProduct(int choose) {
    if (choose == 1) {
        bool swapped;
        for (int i = 0; i < arrsize - 1; i++) {
            swapped = false;
            for (int j = 0; j < arrsize - i - 1; j++) {
                if (products[j].price > products[j + 1].price) {
                    Prop temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    } else {
        bool swapped;
        for (int i = 0; i < arrsize - 1; i++) {
            swapped = false;
            for (int j = 0; j < arrsize - i - 1; j++) {
                if (products[j].group > products[j + 1].group) {
                    Prop temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
    showMenu();
};

void findMenu() {
    cout << "1. За назвою." << endl;
    cout << "2. За виробником." << endl;
    cout << "3. За ціною." << endl;
    cout << "4. За групою товару (наприклад, «Мінеральна вода» або «Консерви»)." << endl;
    cout << "5. За датою надходження на склад." << endl;
    cout << "6. За терміном придатності." << endl;
    cout << "7. Назад." << endl;

    int choose = 0;

    cin >> choose;

    if (choose < 1 || choose > 7) {
        cout << "Не правильний ввід, спробуйте ще раз (введіть 1), або повернітсья назад у меню (введіть 2): " << endl;

        int your_choose = 0;

        cin >> your_choose;

        if (your_choose == 1) {
            findMenu();
        } else if (your_choose == 2) {
            showMenu();
        }

    } else if (choose >= 1 && choose <= 6) {
        findProduct(choose);
    } else if (choose == 7) {
        showMenu();
    } else {
        cout << "Incorrect input.";
        delete[] products;
        exit(1);
    };
};

void sortMenu() {
    cout << "1. За ціною." << endl;
    cout << "2. За групою товару." << endl;
    cout << "3. Назад." << endl;

    int choose;
    cin >> choose;

    if (choose < 1 || choose > 3) {
        cout << "Не правильний ввід, спробуйте ще раз (введіть 1), або повернітсья назад у меню (введіть 2): " << endl;

        int your_choose = 0;

        cin >> your_choose;

        if (your_choose == 1) {
            sortMenu();
        } else if (your_choose == 2) {
            showMenu();
        }
    } else if (choose == 1 || choose == 2) {
        sortProduct(choose);
    } else if (choose == 3) {
        showMenu();
    } else {
        cout << "Incorrect input.";
        delete[] products;
        exit(1);
    }
};

void filePut() {
    FILE* file = fopen("products.txt", "w");
    if (file == nullptr) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "ARRSIZE %d\n", arrsize);

    for (int i = 0; i < arrsize; i++) {
        fprintf(file, "PROP START\n");

        fprintf(file, "NAME %s\n", products[i].name.c_str());
        fprintf(file, "PRODUCER %s\n", products[i].producer.c_str());
        fprintf(file, "PRICE %u\n", products[i].price);
        fprintf(file, "GROUP %s\n", products[i].group.c_str());

        fprintf(file, "RECEIVED %d %d %d\n", products[i].receivedDate.day, products[i].receivedDate.month, products[i].receivedDate.year);
        fprintf(file, "EXPIRATION %d %d %d\n", products[i].expirationDate.day, products[i].expirationDate.month, products[i].expirationDate.year);

        fprintf(file, "PROP END\n");
    }

    fclose(file);

    cout << "Успішно збережено!" << endl;
    showMenu();
}

void fileGet() {
    FILE* file = fopen("products.txt", "r");
    if (file == nullptr) {
        perror("Error opening file for reading");
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "ARRSIZE", 7) == 0) {
            sscanf(line, "ARRSIZE %d", &arrsize);
            break;
        }
    }

    delete[] products;
    products = new Prop[arrsize];

    int currentIndex = -1;
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "PROP START", 10) == 0) {
            currentIndex++;
        } else if (strncmp(line, "NAME", 4) == 0) {
            products[currentIndex].name = std::string(line + 5).substr(0, strlen(line) - 6);
        } else if (strncmp(line, "PRODUCER", 8) == 0) {
            products[currentIndex].producer = std::string(line + 9).substr(0, strlen(line) - 10);
        } else if (strncmp(line, "PRICE", 5) == 0) {
            sscanf(line, "PRICE %u", &products[currentIndex].price);
        } else if (strncmp(line, "GROUP", 5) == 0) {
            products[currentIndex].group = std::string(line + 6).substr(0, strlen(line) - 7);
        } else if (strncmp(line, "RECEIVED", 8) == 0) {
            sscanf(line, "RECEIVED %d %d %d", &products[currentIndex].receivedDate.day, &products[currentIndex].receivedDate.month, &products[currentIndex].receivedDate.year);
        } else if (strncmp(line, "EXPIRATION", 10) == 0) {
            sscanf(line, "EXPIRATION %d %d %d", &products[currentIndex].expirationDate.day, &products[currentIndex].expirationDate.month, &products[currentIndex].expirationDate.year);
        }
    }

    fclose(file);

    cout << "Успішно завантажено!" << endl;
    showMenu();
}

int showMenu() {

    system("clear");

    cout << "Оберіть пункт меню: " << endl;
    cout << "1. Додавання товару на склад." << endl;
    cout << "2. Видалення товару зі складу." << endl;
    cout << "3. Заміна товару." << endl;
    cout << "4. Пошук товару: " << endl;
    cout << "5. Сортування товару: " << endl;
    cout << "6. Показати всі товари." << endl;
    cout << "7. Зберегти товари локально." << endl;
    cout << "8. Завантажити товари з локалиного сховища." << endl;
    cout << "9. Вихід." << endl;

    int choose = 0;

    cin >> choose;

    switch (choose) {
        case 1: {
            addProduct();
            break;
        }
        case 2: {
            deleteProduct();
            break;
        }
        case 3: {
            replaceProduct();
            break;
        }
        case 4: {
            findMenu();
            break;
        }
        case 5: {
            sortMenu();
            break;
        }
        case 6: {
            printProducts();
        }
        case 7: {
            filePut();
        }
        case 8: {
            fileGet();
        }
        case 9: {
            exit(0);
        }
        default: {
            cout << "Не правильний ввід, спробуйте ще раз (введіть 1), або завершіть программу (введіть 2): " << endl;
            int your_choose;
            cin >> your_choose;
            if (your_choose != 1 && your_choose != 2) {
                cout << "Incorrect input.";
                exit(1);
            } else {
                if (your_choose == 1) {
                    showMenu();
                } else {
                    cout << "Завершення программи..." << endl;
                    delete[] products;
                    exit(0);
                }
            }
        }
    }

    return choose;
};

int main() {

    while(true) {

        int choose = showMenu();

        if (choose == 6) {
            break;
        }

    }
    return 0;
}