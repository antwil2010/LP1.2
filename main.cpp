//
// Created by antwi on 13/07/2020.
//

#include <iostream>
#include <string>
#include "empresa.h"

using namespace std;

int main(){
    char opcao = 'z';
    empresa x;
    while(opcao != 'd'){
        cout << "a-Adicionar funcionario à empresa" << endl;
        cout << "b-Aumentar salário dos funcionarios de um determinado departamento" << endl;
        cout << "c-Listar Funcionarios da empresa" << endl;
        cout << "d-Encerrar o programa" << endl;
        cin >> opcao;
        if(opcao == 'a'){
            x.adicionarFuncionario();
        } else if(opcao == 'b'){
            x.aumentarSalario();
        } else if(opcao == 'c') {
            x.listarFuncionario();
        } else if(opcao == 'd'){
                opcao = 'd';
        } else{
            cout << "opção inválida, tente novamente!" << endl;
        }
    }
    return 0;
}

