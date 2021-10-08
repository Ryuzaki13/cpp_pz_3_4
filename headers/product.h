//
// Created by Алексей Афанасьев on 08.10.2021.
//

#ifndef PRODUCT_H
#define PRODUCT_H

/**
 * Описание продукта
 */
struct Product {
    Product();
    Product(const char*, float);
    // Наименование
    char *Name;
    // Цена
    float Price;
};

#endif //PRODUCT_H
