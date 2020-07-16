//
// Created by antwi on 06/07/2020.
//
#ifndef PROF_SAMUEL_CLIENTE_H
#define PROF_SAMUEL_CLIENTE_H

#include <string>

using namespace std;

class ClientePJ{
private:
    string RazaoSocial;
    string cnpj;

public:
    ClientePJ();
    ~ClientePJ();
    void setRazaoSocial(string RazaoSocial);
    string getRazaoSocial();
    void setcnpj(string cnpj);
    string getcnpj();

};

class Cliente{
public:
    string nome;
    string cpf;
    static int quantidadeClientes;

    Cliente();
    ~Cliente();
};

#endif //PROF_SAMUEL_CLIENTE_H