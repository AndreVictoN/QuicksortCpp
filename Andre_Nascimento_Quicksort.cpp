/*
 * Andre_Nascimento_Quicksort.cpp
 *
 *  Created on: 29 de out. de 2024
 *      Author: user
 */

#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cctype>
#include <chrono>
#include "ordenacao.h"
#include "meuItem.h"

using namespace std;

template<class TipoChave>

typename Ordenacao<TipoChave>::LimiteParticoes
Ordenacao<TipoChave>::particao(vector<Item<TipoChave>*>& v, int esq, int dir)
{
	LimiteParticoes p;
	p.i = esq;
	p.j = dir;

	Item<TipoChave> *x = v[(p.i + p.j) / 2]; //Obtém pivo x

	do{
		while(x->compara(v[p.i]) > 0) p.i++;
		while(x->compara(v[p.j]) < 0) p.j--;

		if(p.i <= p.j){
			Item<TipoChave> *w = v[p.i];
			v[p.i] = v[p.j];
			v[p.j] = w;

			p.i++;
			p.j--;
		}
		cout << "Pivô: " << x->recuperaChave()	 << endl;

		for(int cont = 0; cont < dir + 1; cont++){
			cout << v.at(cont)->recuperaChave() << endl;
		}
		cout << endl;
	}while(p.i <= p.j);

	return p;
}

template<class TipoChave>

void Ordenacao<TipoChave>::ordena(vector<Item<TipoChave>*>& v, int esq, int dir){
	LimiteParticoes p = particao(v, esq, dir);

	if(esq < p.j) ordena(v, esq, p.j);
	if(p.i < dir) ordena(v, p.i, dir);
}

template<class TipoChave>

void Ordenacao<TipoChave>::quicksort(vector<Item<TipoChave>*>& v, int n){
	cout << endl << "Ordenação: " << endl;

	ordena(v, 0, n - 1);
}

void arquivoQuicksort(){
	string linha;
	string nomeAr;
	string nomeArOrd;

	vector<string> nomes;
	vector<Item<string>*> chaves;

	cout << "Digite o arquivo que deseja abrir: " << endl;
	getline(cin, nomeAr);

	ifstream ar(nomeAr);

	if(nomeAr == "turma.csv"){
		nomeArOrd = "chamada.csv";
	}else if(nomeAr == "Paises.csv"){
		nomeArOrd = "PaisesOrdenados.csv";
	}else if(nomeAr == "Grammys.csv"){
		nomeArOrd = "MusicasOrdenadas.csv";
	}else{
		return;
	}

	ofstream ordenado(nomeArOrd);

	if(!ar.is_open()){
		cout << "Erro ao abrir o arquivo." << endl;

		return;
	}

	if(!ordenado.is_open()){
		cout << "Erro ao abrir o arquivo." << endl;

		return;
	}

	while(getline(ar, linha)){
		if(isalpha(linha[0])){
			nomes.push_back(linha);
		}
	}

	for(size_t i = 0; i < nomes.size(); i++){
		cout << nomes.at(i) << endl;
	}

	int size = nomes.size();

	cout << endl;

	for(int i = 0; i < size; i++){
		MeuItem<string> *item = new MeuItem<string>(nomes.at(i));

		chaves.push_back(item);
	}

	cout << "Desordenado: " << endl;
	for(int i = 0; i < size; i++)
		cout << chaves.at(i)->recuperaChave() << endl;
	cout << endl;

	auto start = chrono::high_resolution_clock::now();

	Ordenacao<string>::quicksort(chaves, size);

	auto end = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::nanoseconds>(end-start);

	cout << "Ordenado: ";
	for(int i = 0; i < size; i++){
		cout << chaves.at(i)->recuperaChave() << endl;
	}
	cout << endl;

	for(int i = 0; i < size; i++){
		ordenado << chaves.at(i)->recuperaChave() << endl;
	}

	cout << "Tempo para ordenar: " << duration.count() << "ns" << endl;

	for(auto item : chaves){
		delete item;
	}

	ordenado.close();
	ar.close();
}

int main(int argc, char **argv) {
	cout << "Leitura e orgnização de arquivos: " << endl;
	arquivoQuicksort();

	return 0;
}
