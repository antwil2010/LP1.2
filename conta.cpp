//
// Created by antwi on 06/07/2020.
//
#include "conta.h"

void Conta::saca(double valor){
    this->saldo -= valor;
}

void Conta::deposita(double valor){
    this->saldo += valor;
}

void Conta::transfere(double valor, Conta &c){
    this->saldo -= valor;
    c.deposita(valor);
}

