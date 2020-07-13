//
// Created by antwi on 13/07/2020.
//

#ifndef EMPRESA_EMPRESA_H
#define EMPRESA_EMPRESA_H
#include "funcionario.h"
#include <string>

using namespace std;

class empresa {
private:
    string nome;
    string cnpj;
    static int qtdFuncionario;
    funcionario* Funcionario;

public:
    empresa();
    ~empresa();
    void setNome(string nome);
    string getNome();
    void setcnpj(string cnpj);
    string getcnpj();
    void setQtdFuncionario(int qtdFuncionario);
    int getQtdFuncionario();
    void adicionarFuncionario();
    void aumentarSalario();
    void listarFuncionario();
};


#endif //EMPRESA_EMPRESA_H
