#include "IA/Estado.h"

Estado::Estado(vector<Transicion*>transiciones)
{
    this->transiciones=transiciones;
}

Transicion* Estado::getNextTransicion(irr::core::map<stringw,stringw>*strings,
                                      irr::core::map<stringw,stringw>*strings_contrario,
                           irr::core::map<stringw,int>*enteros,
                           irr::core::map<stringw,int>*enteros_contrario
                                      )
{
    vector<int>transiciones_validas;
    for(int i=0;i<(int)transiciones.size();i++)
    {
        if(transiciones[i]->cumpleCondiciones(strings,strings_contrario,enteros,enteros_contrario))
        {
            for(int j=0;j<(int)transiciones[i]->getRecompensa();j++)
                transiciones_validas.push_back(i);
        }
    }
    if(transiciones_validas.size()==0)
        return new Transicion("5","S",false);
    int r=std::rand()%transiciones_validas.size();
    return transiciones[transiciones_validas[r]];
}
