//
// Created by ������� ��������� on 08.10.2021.
//

#ifndef PRODUCT_H
#define PRODUCT_H

/**
 * �������� ��������
 */
struct Product {
    Product();
    Product(const char*, float);
    // ������������
    char *Name;
    // ����
    float Price;
};

#endif //PRODUCT_H
