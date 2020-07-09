//
// Created by antwi on 06/07/2020.
//
#include <iostream>
#include "carro.h"
#include "conta.h"

using namespace std;

int main(){
    int escolha = 0;
    cout << "Escolha o programa:" << endl;
    cout << "1-Carro 2-Conta" << endl;
    cin >> escolha;
    if(escolha == 1){
        int escolha2 = 7;
        string tipo = "Sedan";
        Carro c(tipo);
        Motor c1;
        c.numPortas = 4;
        c.placa = "XYZ-0102";
        c.velocidade = 0;
        c.ligado = 0;
        c.marcha = 0;
        c.tanque = 100;
        c1.oleo = 10;
        while(escolha2 != 0){
            cout << "Digite a ação que quer fazer: " << endl;
            cout << "Características do carro: " << endl;
            cout << c.tipo << endl;
            cout << c.numPortas << endl;
            cout << c.placa << "Porta(s)" << endl;
            cout << "1-para ligar o carro" << endl;
            cout << "2-para acelerar o carro" << endl;
            cout << "3-para freiar o carro" << endl;
            cout << "4-para trocar a marcha do carro" << endl;
            cout << "5-para abastecer o tanque do carro" << endl;
            cout << "6-para trocar o oleo do carro" << endl;
            cout << "0-para fechar o programa" << endl;
            cin >> escolha2;
            if(escolha2 == 1){
                if(c.ligado = 0){
                    c.liga(c.ligado);
                } else if(c.ligado == 1) {
                    cout << "O carro já está ligado!" << endl;
                }
            } else if(escolha2 == 2){
                cout << "A velocidade atual é: " << c.velocidade << "KM/H" << endl;
                if(c.marcha == 0) {
                    cout << "O carro está no ponto morto, passe de marcha primeiro!" << endl;
                } else if(c.marcha == 1) {
                    c.limite = 30;
                    if(c.limite <= c.velocidade) {
                        cout << "O carro já passou da velocidade máxima da marcha, troque de marcha!" << endl;
                    } else {
                        c.acelera(20);
                        c.tanque -= 5;
                        c1.oleo -= 1;
                    }
                } else if(c.marcha == 2) {
                    c.limite = 50;
                    if(c.limite <= c.velocidade) {
                        cout << "O carro já passou da velocidade máxima da marcha, troque de marcha!" << endl;
                    } else {
                        c.acelera(20);
                        c.tanque -= 5;
                        c1.oleo -= 1;
                    }
                } else if(c.marcha == 3) {
                    c.limite = 70;
                    if(c.limite <= c.velocidade) {
                        cout << "O carro já passou da velocidade máxima da marcha, troque de marcha!" << endl;
                    } else {
                        c.acelera(20);
                        c.tanque -= 5;
                        c1.oleo -= 1;
                    }
                } else if(c.marcha == 4) {
                    c.limite = 100;
                    if(c.limite <= c.velocidade) {
                        cout << "O carro já passou da velocidade máxima da marcha, troque de marcha!" << endl;
                    } else {
                        c.acelera(20);
                        c.tanque -= 5;
                        c1.oleo -= 1;
                    }
                } else if(c.marcha == 5) {
                    c.limite = 200;
                    if(c.limite <= c.velocidade) {
                        cout << "O carro está na velocidade máxima!" << endl;
                    } else {
                        c.acelera(20);
                        c.tanque -= 5;
                        c1.oleo -= 1;
                    }
                }
            } else if(escolha2 == 3){
                if(c.velocidade == 0) {
                    cout << "O carro está parado!" << endl;
                } else if(c.velocidade < 0){
                    cout << "O carro está dando ré!" << endl;
                } else {
                    c.freia(20);
                    //Implementar depois voltar as marchas quando estiver freiando
                }
            } else if(escolha2 == 4){
                c.pegaMarcha(c.marcha, c.velocidade, c.limite);
            } else if(escolha2 == 5){
                c.abastecer(c.tanque);
            } else if(escolha2 == 6){
                c1.trocaOleo(c1.oleo);
            } else if(escolha2 != 0){
                cout << "Opção inválida, tente novamente!" << endl;
            }
        }
    } else if(escolha == 2){
        cout << "Bem-vindo ao banco" << endl;
        Cliente clC;
        Cliente clD;
        clC.nome = "João";
        clD.nome = "Maria";
        Conta a(clC);
        Conta c(clD);
        Conta e(c);
        cout << "Titular da conta C: " << a.titular.nome << endl;
        cout << "Titular da conta D: " << c.titular.nome << endl;
        cout << "Titular da conta E: " << e.titular.nome << endl;
        a.numero = 52634;
        a.agencia.nome = "Itau";
        a.agencia.numeroDaAgencia = "54321-5";
        a.saldo = 10000;
        a.limite = 20000;
        c.numero = 52635;
        c.agencia.nome = "Bradesco";
        c.agencia.numeroDaAgencia = "54321-6";
        c.saldo = 4000;
        c.limite = 10000;
        double valor;
        int escolha2 = 5;
        while(escolha2 != 0){
            cout << "Quantidade de contas: " << c.quantidadeContas << endl;
            cout << "Quantidade de clientes: " << clC.quantidadeClientes << endl;
            cout << "Digite a ação que quer fazer: " << endl;
            cout << "1-para sacar" << endl;
            cout << "2-para depositar" << endl;
            cout << "3-para transferir" << endl;
            cout << "4-para mostrar a agencia e o numero da agencia" << endl;
            cout << "0-para fechar o programa" << endl;
            cin >> escolha2;
            if(escolha2 == 1){
                cout << "Saldo da conta de " << a.titular.nome << ": " << a.saldo << endl;
                cout << "Digite o valor para sacar: " << endl;
                cin >> valor;
                if(valor > a.saldo){
                    cout << "Valor maior que o saldo disponível, tente novamente!" << endl;
                } else{
                    a.saca(valor);
                }
            } else if(escolha2 == 2){
                cout << "Limite disponível da conta de " << a.titular.nome << ": " << a.limite - a.saldo << endl;
                cout << "Digite o valor para depositar: " << endl;
                cin >> valor;
                if((valor + a.saldo) > a.limite){
                    cout << "Valor maior que o limite disponível da conta, tente novamente!" << endl;
                } else{
                    a.deposita(valor);
                }
            } else if(escolha2 == 3){
                cout << "Saldo da conta de " << a.titular.nome << ": " << a.saldo << endl;
                cout << "Limite disponível de " << c.titular.nome << ": " << c.limite - c.saldo << endl;
                cout << "Digite o valor para transferir: " << endl;
                cin >> valor;
                if(valor > a.saldo){
                    cout << "Valor indisponível para transferir, tente novamente!" << endl;
                } else if((valor + c.saldo) > c.limite){
                    cout << "Limite indisponível para receber o valor, tente novamente!" << endl;
                } else{
                    a.transfere(valor, c);
                }
            } else if(escolha2 == 4){
                cout << a.agencia.nome << "\n" << a.agencia.numeroDaAgencia << endl;
            } else if(escolha2 != 0){
                cout << "Opção inválida, tente novamente!" << endl;
            }
        }
    }
    return 0;
}

