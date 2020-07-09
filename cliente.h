//
// Created by antwi on 06/07/2020.
//
#ifndef PROF_SAMUEL_CLIENTE_H
#define PROF_SAMUEL_CLIENTE_H

#include <string>

using namespace std;

class Cliente{
public:
    string nome;
    int cpf;
    static int quantidadeClientes;

    Cliente();
    ~Cliente();
};

#endif //PROF_SAMUEL_CLIENTE_H