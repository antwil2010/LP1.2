//
// Created by antwi on 09/07/2020.
//
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>
#include "Estabelecimento.hpp"
#include "Cliente.hpp"
#include <iomanip>

using namespace std;

double cliente::saldo;
int cliente::contacliente;

int main(){
    cout << "Escolha o estabelecimento:" << endl;
    cout << "1-Supermercado 2-Restaurante" << endl;
    int escolha;
    cin >> escolha;
    if(escolha == 1){
        Supermercado a1;
        cliente::saldo = 50;
        int opcao = 10;
        int aux;
        cout << "Bem-vindo ao SuperMercado" << endl;
        a1.consultar();
        fornecedor b1;
        for(int j = 0;j < a1.quantia; j++){
            vendido::quantidadevendida[j] = 0;
        }
        vendido::vendas = 0;
        while(opcao != 0){
            cout << "1-Ver produtos do estoque" << endl;
            cout << "2-Comprar produto do estoque" << endl;
            cout << "3-Ver produtos da sacola" << endl;
            cout << "4-Adicionar saldo do cliente" << endl;
            cout << "5-Listar os produtos do fornecedor" << endl;
            cout << "6-Reabastecer estoque do estabelecimento" << endl;
            cout << "7-Terminar de comprar" << endl;
            cin >> opcao;
            if(opcao == 1){
                a1.listar();
            } else if(opcao == 2){
                int code;
                cout << "Escreva o codigo do produto ao qual você quer comprar: ";
                cin >> code;
                int checacodigo = 1;
                if(code == a1.codigo[code]) {
                    checacodigo = 0;
                }
                if(checacodigo == 0) {
                    a1.venda(a1.codigo[code]);
                } else{
                    cout << "Código de Produto não encontrado, tente novamente" << endl;
                }
            } else if(opcao == 3){
                cliente::verSacola();
            } else if(opcao == 4){
                cout << "Digite a quantidade que você deseja adicionar ao saldo: ";
                double aumentasaldo;
                cin >> aumentasaldo;
                cliente::saldo += aumentasaldo;
                cout << "Novo saldo: " << fixed << setprecision(2) << cliente::saldo << endl;
            } else if(opcao == 5){
                b1.listarProdutos();
            } else if(opcao == 6){
                string produto;
                cout << "Digite o nome do produto que quer reabastecer: ";
                cin >> produto;
                int quantidade = b1.repassarProdutos(produto);
                if(quantidade == -2){
                    cout << "Produto não encontrado, tente novamente!" << endl;
                } else{
                    a1.reabastecer(produto, quantidade);
                }
            } else if(opcao == 7){
                cout << "Deseja atender um novo cliente? 1-sim 2-nao" << endl;
                int opcao2;
                cin >> opcao2;
                a1.caixa();
                cliente::registro();
                if(opcao2 == 1){
                    cliente::sacola.clear();
                    cliente::saldo = 50;
                    cliente::contacliente += 1;
                } else if(opcao2 == 2){
                    ofstream estoque2;
                    estoque2.open("estoque.csv");
                    for(size_t i = 0; i < a1.quantia; i++){
                        if(i == 0){
                            estoque2 << "COD PRODUTO UNIDADE-DE-MEDIDA PREÇO QUANTIDADE" << endl;
                        } else if(a1.preco[i] != 0){
                            estoque2 << a1.codigo[i] << " " << a1.produtosreserva[i] << " " << a1.unidadeMedida[i] << " R$ " << fixed << setprecision(2) << a1.preco[i] << " " << a1.quantidade[i] << endl;
                        }
                    }
                    estoque2.close();
                    ofstream caixa;
                    caixa.open("caixa-supermercado.csv");
                    for(int i = 0;i <= a1.quantia; i++){
                        if(i == 0){
                            caixa << "COD PRODUTO PREÇO QUANTIDADE-VENDIA" << endl;
                        } else if(!vendido::produtosvendido[i].empty() && vendido::quantidadevendida[i] != 0 && vendido::quantidadevendida[i] < 50){
                            caixa << vendido::codigovendido[i] << " " << vendido::produtosvendido[i] << " " << fixed << setprecision(2) << vendido::precovendido[i] << " " << vendido::quantidadevendida[i] << endl;
                        }
                    }
                    caixa << "QUANTIDADE DE VENDAS: " << vendido::vendas << " " << "VALOR TOTAL DAS VENDAS: R$ " << fixed << setprecision(2) << vendido::total << endl;
                    caixa.close();
                    opcao = 0;
                } else{
                    cout << "opcao invalida, tente novamente" << endl;
                }
            } else{
                cout << "Opcao inválida, tente novamente!" << endl;
            }
        }
        delete[] a1.codigo;
        delete[] a1.unidadeMedida;
        delete[] a1.preco;
        delete[] a1.quantidade;
        delete[] a1.produtosreserva;
        delete[] vendido::produtosvendido;
        delete[] vendido::codigovendido;
        delete[] vendido::precovendido;
        delete[] vendido::quantidadevendida;
    } else if(escolha == 2){
        cout << "Bem-Vindo ao McDonalds" << endl;
        cliente::saldo = 50;
        Restaurante a1;
        int opcao = 10;
        vendido::total = 0;
        vendido::vendas = 0;
        while(opcao != 0){
            cout << "1-Fazer pedido" << endl;
            cout << "2-Ver menu de opcões" << endl;
            cout << "3-Adicionar saldo ao cliente" << endl;
            cout << "4-Terminar de pedir" << endl;
            cin >> opcao;
            if(opcao == 1){
                cout << "Digite o nome do Item que deseja: ";
                string item;
                cin >> item;
                a1.venda(item);
            } else if(opcao == 2){
                a1.listar();
            } else if(opcao == 3){
                cout << "Digite a quantidade que você deseja adicionar ao saldo: ";
                double aumentasaldo;
                cin >> aumentasaldo;
                cliente::saldo += aumentasaldo;
                cout << "Novo saldo: " << fixed << setprecision(2) << cliente::saldo << endl;
            } else if(opcao == 4){
                a1.caixa();
                cliente::registro();
                ofstream caixa;
                caixa.open("caixa-restaurante.csv");
                caixa << "ITEM PREÇO QUANTIDADE-VENDIDA" << endl;
                for(int i = 0;i <= a1.quantia; i++){
                    if(!vendido::produtosvendido[i].empty() && vendido::quantidadevendida[i] != 0 && vendido::quantidadevendida[i] < 50){
                        caixa << vendido::produtosvendido[i] << " " << fixed << setprecision(2) << vendido::precovendido[i] << " " << vendido::quantidadevendida[i] << endl;
                    }
                }
                caixa << "QUANTIDADE DE VENDAS: " << vendido::vendas << " " << "VALOR TOTAL DAS VENDAS: R$ " << fixed << setprecision(2) << vendido::total << endl;
                caixa.close();
                opcao = 0;
            } else{
                cout << "Opcão inválida, tente novamente" << endl;
            }
        }
        delete[] a1.preco;
        delete[] vendido::produtosvendido;
        delete[] vendido::precovendido;
        delete[] vendido::quantidadevendida;
    } else{
        cout << "Escolha inválida, tente novamente!" << endl;
        return 1;
    }
    return 0;
}

