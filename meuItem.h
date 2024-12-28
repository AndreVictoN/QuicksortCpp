/*
 * meuItem.h
 *
 *  Created on: Oct 15, 2024
 *      Author: Revii
 */

#ifndef MEUITEM_H_
#define MEUITEM_H_

#include "item.h"
#include <sstream>

template <class TipoChave>
class MeuItem : public Item<TipoChave>{
public:
	TipoChave chave;

	MeuItem(TipoChave chave);
	virtual int compara(const Item<TipoChave> *item) const;
	virtual void alteraChave(TipoChave chave);
	virtual TipoChave recuperaChave() const;
	virtual string toString() const;
	~MeuItem(){};
};

template <class TipoChave>
MeuItem<TipoChave>::MeuItem(TipoChave chave) {this->chave = chave;}

template <class TipoChave>
int MeuItem<TipoChave>::compara(const Item<TipoChave> *item) const{
	//MeuItem *it = (MeuItem *)item;
	const MeuItem<TipoChave> *it = dynamic_cast<const MeuItem<TipoChave>*>(item);

	if(this->chave < it->chave) return -1;
	else if(this->chave > it->chave) return 1;

	return 0;
}

template <class TipoChave>
void MeuItem<TipoChave>::alteraChave(TipoChave chave) {this->chave = chave;}

template <class TipoChave>
TipoChave MeuItem<TipoChave>::recuperaChave() const {return this->chave;}

template <class TipoChave>
string MeuItem<TipoChave>::toString() const{
	std::ostringstream oss;

	oss << this->chave;

	return oss.str();
}

#endif /* MEUITEM_H_ */
