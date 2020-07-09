//
// Created by antwi on 06/07/2020.
//

#ifndef PROF_SAMUEL_CONTA_H
#define PROF_SAMUEL_CONTA_H
#include "cliente.h"
#include "agencia.h"

using namespace std;

class Conta{
public:
    int numero;
    Cliente titular;
    Agencia agencia;
    double saldo;
    double limite;
    static int quantidadeContas;

    Conta(Cliente& titular);
    Conta();
    ~Conta();

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta &c);
};

#endif //PROF_SAMUEL_CONTA_H
