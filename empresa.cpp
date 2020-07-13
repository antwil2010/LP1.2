//
// Created by antwi on 13/07/2020.
//

#include "empresa.h"
#include <iostream>

using namespace std;

int empresa::qtdFuncionario;

empresa::empresa(){
    cout << "Digite o nome da empresa: ";
    string nome;
    cin >> nome;
    setNome(nome);
    cout << "Digite o cnpj da empresa: ";
    string cnpj;
    cin >> cnpj;
    setcnpj(cnpj);
    cout << "Digite a capacidade de funcionarios da empresa: ";
    int qtdFuncionario;
    cin >> qtdFuncionario;
    setQtdFuncionario(qtdFuncionario);
    cout << "Empresa " << getNome() << " criada com sucesso" << endl;
}
empresa::~empresa(){
}

void empresa::setNome(string nome){
    this->nome = nome;
}
string empresa::getNome(){
    return this->nome;
}

void empresa::setcnpj(string cnpj){
    this->cnpj = cnpj;
}
string empresa::getcnpj(){
    return this->cnpj;
}

void empresa::setQtdFuncionario(int qtdFuncionario){
    this->qtdFuncionario = qtdFuncionario;
}
int empresa::getQtdFuncionario(){
    return this->qtdFuncionario;
}

void empresa::adicionarFuncionario(){
    Funcionario = new funcionario[this->qtdFuncionario];
    cout << "Digite a quantidade de funcionarios que quer contratar: ";
    int contratar, conta = 0;
    cin >> contratar;
    if(contratar > this->qtdFuncionario){
        cout << "Quantidade maior do que a capacidade de funcionarios da empresa" << endl;
        return;
    } else{
        while(conta < contratar){
            cout << "Digite o nome do funcionario: ";
            string nome;
            cin >> nome;
            Funcionario[conta].setNome(nome);
            cout << "Digite o salario do funcionario: ";
            double salario;
            cin >> salario;
            Funcionario[conta].setSalario(salario);
            cout << "Digite a data de admissão do funcionario: ";
            string dataAdmissao;
            cin >> dataAdmissao;
            Funcionario[conta].setDataAdmissao(dataAdmissao);
            cout << "Digite o departamento do funcionaro: ";
            string departamento;
            cin >> departamento;
            Funcionario[conta].setDepartamento(departamento);
            cout << "Funcionario: " << Funcionario[conta].getNome() << " Adicionado" << endl;
            conta++;
        }
    }
}

void empresa::aumentarSalario(){
    string departamento;
    cout << "Digite o departamento dos funcionarios que deseja aumentar o salário: ";
    cin >> departamento;
    cout << endl; //Pula linha para evitar problemas com formatação(estava juntando linhas)
    for(size_t i = 0; i < this->qtdFuncionario; i++){
        if(Funcionario[i].getDepartamento() == departamento){
            double aumento;
            aumento = Funcionario[i].getSalario() + (Funcionario[i].getSalario() / 10);
            cout << "Salario de " << Funcionario[i].getNome() << " era: " << Funcionario[i].getSalario();
            Funcionario[i].setSalario(aumento);
            cout << " agora é: " << Funcionario[i].getSalario() << endl;
        }
    }
}

void empresa::listarFuncionario(){
    cout << "Funcionarios da empresa: " << endl;
    for(size_t i = 0; i < this->qtdFuncionario; i++){
        if(Funcionario[i].getSalario() != 0){
            cout << "Nome: " << Funcionario[i].getNome() << endl;
            cout << "Salario: " << Funcionario[i].getSalario() << endl;
            cout << "Data de Admissão: " << Funcionario[i].getDataAdmissao() << endl;
            cout << "Departamento: " << Funcionario[i].getDepartamento() << endl;
        }

    }
}

