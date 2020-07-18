//
// Created by antwi on 09/07/2020.
//

#ifndef PROVA1_CLIENTE_HPP
#define PROVA1_CLIENTE_HPP

#include <string>
#include <vector>
#include <iostream>
#include "vector_supermercado.hpp"

using namespace std;

class cliente{
public:
    static double saldo;
    static vectorsupermercado<string> sacola;
    static int contacliente;

    static int compra(string produto, double aux);
    static void verSacola();
    static void registro();
    cliente();
    ~cliente();
};

#endif //PROVA1_CLIENTE_HPP
