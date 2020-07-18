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

fornecedor::fornecedor(){
    ifstream forne;
    forne.open("fornecedor.cvs");
    if(!forne.is_open()){       // Por algum motivo o arquivo não abre, já tentei de tudo e o tempo acabou
        cout << "Erro ao abrir arquivo do fornecedor" << endl;
    }
    int conta = 0;
    int quantidade;
    string linha;
    string reserva;
    while(!forne.eof()){
        getline(forne, linha);
        stringstream stream(linha);
        if(conta != 0){
            stream >> reserva;
            produtosfornecedor.push(reserva);
            stream >> quantidade;
            produtosfornecedor.pushQuant(quantidade);
        }
        conta++;
    }
    forne.close();
}
fornecedor::~fornecedor(){
}

void fornecedor::listarProdutos(){
    produtosfornecedor.listar();
}

void fornecedor::repassarProdutos(){
    string produto;
    int quantidade;
    cout << "Digite o nome do produto que quer reabastecer: ";
    cin >> produto;
    if(produtosfornecedor.find(produto) != "false"){
        cout << "Digite a quantidade do produto que quer reabastecer";
        cin >> quantidade;
        if(quantidade > produtosfornecedor.getQuantidade(produto) || produtosfornecedor.getQuantidade(produto) == -1){
        } else{
            //estabelecimento::reabastecer(produto, quantidade);
        }
    }
}

void estabelecimento::reabastecer(string produto, int quant){
    string checa = produtos.find(produto);
    if(checa == produto){
        for(int i = 0; i < quantia; i++){
            if(checa == produtosreserva[i]){
                quantidade[i] += quant;
                i = quantia;
            }
        }
    }
}

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
            produtos.push(reserva);
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
    cout << "Produtos Disponíveis: " << endl;
    string checa;
    int k = 0;
    for(int i = 1; i < quantia; i++){
        if(checa == produtos.get(k)){
        } else if(produtos.get(k) != "false"){
            cout << codigo[i] << "-" << produtos.get(k) << " Quantidade: " << quantidade[i] << endl;
        } else {
            cout << "Error ao listar produto!" << endl;
        }
        checa = produtos.get(k);
        k++;
    }
    cout << "\n";
}

void estabelecimento::venda(int cod){
    string produto;
    int aux;
    produto = produtosreserva[cod];
    string k;
    k = produtos.find(produto);
    if(k == produto){  //Checa se existe o produto no estoque
        for(int i = 0; i < quantia; i++){
            if(produtosreserva[i] == k){
                aux = i;
                i = quantia;
                if(quantidade[aux] > 0){ //Checa se o produto achado ainda tem no estoque
                    double aux2 = preco[aux];
                    int checa;
                    checa = cliente::compra(produto, aux2);
                    if(checa == 0){
                        quantidade[aux] -= 1;
                        vendido::produtosvendido[aux] = k;
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

