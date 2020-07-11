//
// Created by antwi on 09/07/2020.
//
#include "Estabelecimento.hpp"
#include "Cliente.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
#include <iomanip>

using namespace std;

double vendido::total;
string* vendido::produtosvendido;
int* vendido::codigovendido;
double* vendido::precovendido;
int* vendido::quantidadevendida;
int vendido::vendas;

void estabelecimento::consultar(){
    ifstream estoque;
    estoque.open("estoque.csv");
    string discard;
    string prod;
    int conta = 0;
    if(!estoque.is_open()){
        cout << "Erro ao abrir arquivo!" << endl;
    }

    while(!estoque.eof()){
        getline(estoque, prod);
        conta++;
    }
    estoque.close();
    codigo = new int[conta];
    produtosreserva = new string[conta];
    unidadeMedida = new string[conta];
    preco = new double[conta];
    quantidade = new int[conta];
    vendido::codigovendido = new int[conta];
    vendido::produtosvendido = new string[conta];
    vendido::precovendido = new double[conta];
    vendido::quantidadevendida = new int[conta];
    quantia = conta;
    int count = 0;
    estoque.open("estoque.csv");
    string reserva;
    if(!estoque.is_open()){
        cout << "Erro ao abrir arquivo!" << endl;
    }
    while(!estoque.eof()){
        getline(estoque, discard);
        stringstream stream(discard);
        if(count != 0){
            stream >> codigo[count];
            stream >> reserva;
            produtosreserva[count] = reserva;
            produtos.push_back(reserva);
            stream >> unidadeMedida[count];
            stream >> discard;
            stream >> preco[count];
            //stream >> discard;
            stream >> quantidade[count];
        }
        count++;
    }
    estoque.close();
}

void estabelecimento::listar(){
    list<string>::iterator k;
    cout << "Produtos Disponíveis: " << endl;
    int i = 1;
    string checa;
    for(k = produtos.begin(); k != produtos.end(); k++){
        if(checa == *k){
        } else{
            cout << codigo[i] << "-" << *k << " Quantidade: " << quantidade[i] << endl;
        }
        i++;
        checa = *k;
    }
    cout << "\n";
}

void estabelecimento::venda(int cod){
    string produto;
    int aux;
    produto = produtosreserva[cod];
    list<string>::iterator k;
    k = find(produtos.begin(), produtos.end(), produto);
    if(*k == produto){  //Checa se existe o produto no estoque
        for(int i = 0; i < quantia; i++){
            if(produtosreserva[i] == *k){
                aux = i;
                i = quantia;
                if(quantidade[aux] > 0){ //Checa se o produto achado ainda tem no estoque
                    double aux2 = preco[aux];
                    int checa;
                    checa = cliente::compra(produto, aux2);
                    if(checa == 0){
                        quantidade[aux] -= 1;
                        vendido::produtosvendido[aux] = *k;
                        vendido::codigovendido[aux] = aux;
                        vendido::precovendido[aux] = aux2;
                        vendido::quantidadevendida[aux] += 1;
                        vendido::total += aux2;
                        vendido::vendas += 1;
                    }
                } else{
                    cout << "O estoque do produto acabou" << endl;
                }
            }
        }
    }
}

void estabelecimento::caixa(){
    for(int i = 0;i <= quantia; i++){
        if(i == 0){
            cout << "Produtos Vendidos:" << endl;
        } else if(!vendido::produtosvendido[i].empty() && vendido::quantidadevendida[i] != 0 && vendido::quantidadevendida[i] < 50){
            cout << vendido::produtosvendido[i] << " Quantidade Vendida: " << vendido::quantidadevendida[i] << endl;
        }
    }
    cout << "Total Ganho nas Vendas: R$ " << fixed << setprecision(2) << vendido::total << endl;
}

estabelecimento::estabelecimento(){

}

estabelecimento::~estabelecimento(){

}

