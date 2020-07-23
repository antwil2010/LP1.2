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

estabelecimento::estabelecimento(){
}
estabelecimento::~estabelecimento(){
}
void estabelecimento::caixa(){
    cout << "Produtos Vendidos:" << endl;
    for(int i = 0;i <= quantia; i++){
        if(!vendido::produtosvendido[i].empty() && vendido::quantidadevendida[i] != 0 && vendido::quantidadevendida[i] < 50){
            cout << vendido::produtosvendido[i] << " Quantidade Vendida: " << vendido::quantidadevendida[i] << endl;
        }
    }
    cout << "Total Ganho nas Vendas: R$ " << fixed << setprecision(2) << vendido::total << endl;
}


void Supermercado::reabastecer(string produto, int quant){
    string checa = produtos.find(produto);
    if(checa == produto){
        for(int i = 0; i < quantia; i++){
            if(checa == produtosreserva[i]){
                quantidade[i] += quant;
                i = quantia;
            }
        }
    } else{
        cout << "Erro ao checar igualdade dos produtos em reabastecer" << endl;
    }
}
void Supermercado::consultar(){
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
            stream >> quantidade[count];
        }
        count++;
    }
    estoque.close();
}
void Supermercado::listar(){
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
void Supermercado::venda(int cod){
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


Restaurante::Restaurante(){
    ifstream estoque;
    estoque.open("menu.csv");
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
    preco = new double[conta];
    vendido::quantidadevendida = new int[conta];
    vendido::produtosvendido = new string[conta];
    vendido::precovendido = new double[conta];
    for(int i = 0; i < conta; i++){
        vendido::quantidadevendida[i] = 0;
    }
    quantia = conta;
    int count = 0, y = 0;
    estoque.open("menu.csv");
    string reserva;
    if(!estoque.is_open()){
        cout << "Erro ao abrir arquivo!" << endl;
    }
    while(!estoque.eof()){
        getline(estoque, discard);
        stringstream stream(discard);
        if(count != 0) {
            stream >> reserva;
            produtos.push(reserva);
            stream >> discard;
            stream >> preco[y];
            y++;
        }
        count++;
    }
    estoque.close();
}
Restaurante::~Restaurante(){
}
void Restaurante::venda(string produto){
    int aux;
    string k;
    k = produtos.find(produto);
    if(k == produto){  //Checa se existe o produto no estoque
        aux = produtos.findI(produto);
        if(aux == -1){
            cout << "erro ao encontrar índice" << endl;
        } else {
            double aux2 = preco[aux];
            int checa;
            checa = cliente::compra(produto, aux2);
            if (checa == 0) {
                vendido::produtosvendido[aux] = k;
                vendido::precovendido[aux] = aux2;
                vendido::quantidadevendida[aux] += 1;
                vendido::total += aux2;
                vendido::vendas += 1;
            } else{
                cout << "erro ao finalizar compra" << endl;
            }
        }
    } else if(k == "false"){
        cout << "produto não encontrado, tente novamente!" << endl;
    } else{
        cout << "problema ao tentar encontrar produto no cardápio!" << endl;
    }
}
void Restaurante::listar(){
    cout << "Cardápio:" << endl;
    string checa;
    int k = 0;
    for(int i = 0; i < quantia; i++){
        if(checa == produtos.get(k)){
        } else if(produtos.get(k) != "false"){
            cout << produtos.get(k) << endl;
        }
        checa = produtos.get(k);
        k++;
    }
    cout << "\n";
}

fornecedor::fornecedor(){
    ifstream forne;
    forne.open("fornecedor.csv");
    if(!forne.is_open()){
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
int fornecedor::repassarProdutos(string produto){
    int quantidade;
    string produtoreserva;
    if(produtosfornecedor.find(produto) != "false"){
        cout << "Digite a quantidade do produto que quer reabastecer: ";
        cin >> quantidade;
        if(quantidade > produtosfornecedor.getQuantidade(produto) || produtosfornecedor.getQuantidade(produto) == -1){
            cout << "Quantidade exigida maior que a quantidade disponível, tente novamente" << endl;
            return -1;
        } else if(produtosfornecedor.getQuantidade(produto) == -1){
            cout << "Erro ao achar quantidade do produto!" << endl;
            return -1;
        } else{
            produtosfornecedor.CutQuantidade(produto, quantidade);
            ofstream fornecedor;
            fornecedor.open("fornecedor.csv");
            if(!fornecedor.is_open()){
                cout << "Erro ao abrir arquivo fornecedor" << endl;
            } else{
                fornecedor << "PRODUTO QUANTIDADE" << endl;
                int conta = produtosfornecedor.sizeOf();
                for(int i = 0; i < conta; i++){
                    produtoreserva = produtosfornecedor.get(i);
                    fornecedor << produtoreserva << " " << produtosfornecedor.getQuantidade(produtoreserva) << endl;
                }
            }
            return quantidade;
        }
    } else{
        return -2;
    }
}


