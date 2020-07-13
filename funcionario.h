//
// Created by antwi on 13/07/2020.
//

#ifndef EMPRESA_FUNCIONARIO_H
#define EMPRESA_FUNCIONARIO_H

#include <string>

using namespace std;

class funcionario {
private:
    string nome;
    double salario;
    string dataAdmissao;
    string departamento;

public:
    funcionario();
    ~funcionario();
    void setNome(string nome);
    string getNome();
    void setSalario(double salario);
    double getSalario();
    void setDataAdmissao(string dataAdmissao);
    string getDataAdmissao();
    void setDepartamento(string departamento);
    string getDepartamento();

};


#endif //EMPRESA_FUNCIONARIO_H
