/*
 * ordenacao.h
 *
 *  Created on: Oct 15, 2024
 *      Author: Revii
 */

#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <vector>
#include "item.h"
#include "meuItem.h"

template <class TipoChave> class Ordenacao{
private:
	typedef struct LimiteParticoes{int i, j;} LimiteParticoes;
	static LimiteParticoes particao(std::vector<Item<TipoChave>*>& v, int esq, int dir);
	static void ordena(std::vector<Item<TipoChave>*>& v, int esq, int dir);
public:
	static void quicksort(std::vector<Item <TipoChave>*>& v, int n);
};

#endif /* ORDENACAO_H_ */
