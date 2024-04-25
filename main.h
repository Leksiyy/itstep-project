#ifndef MAIN_H
#define MAIN_H

#include <string>

struct Prop {
    std::string name;
    std::string producer;
    unsigned int price;
    std::string group;
    struct Date{
        int day;
        int month;
        int year;
    };
    Date receivedDate;
    Date expirationDate;
};

int arrsize = 0;

Prop* products = new Prop[arrsize];

int arrIndex;

int showMenu();
void sortProduct();
void findProduct();
void replaceProduct();
void deleteProduct();
void addProduct(int* size, Prop* products);

#endif

