//
// Created by Алексей Афанасьев on 08.10.2021.
//

#include <cstring>
#include "product.h"

Product::Product() {
    this->Name = new char[] {"Product name"};
    this->Price = 0.0f;
}

Product::Product(const char *name, float price) {
    size_t len = strlen(name);

    this->Name = new char[len+1];
    strcpy(this->Name, name);

    this->Price = price;
}
