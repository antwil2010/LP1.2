//
// Created by antwi on 13/07/2020.
//

#include "funcionario.h"
#include <iostream>

using namespace std;

funcionario::funcionario(){

}
funcionario::~funcionario(){

}

void funcionario::setNome(string nome){
    this->nome = nome;
}
string funcionario::getNome(){
    return this->nome;
}

void funcionario::setSalario(double salario){
    this->salario = salario;
}
double funcionario::getSalario(){
    return this->salario;
}

void funcionario::setDataAdmissao(string dataAdmissao){
    this->dataAdmissao = dataAdmissao;
}
string funcionario::getDataAdmissao(){
    return this->dataAdmissao;
}

void funcionario::setDepartamento(string departamento){
    this->departamento = departamento;
}
string funcionario::getDepartamento(){
    return this->departamento;
}
