#ifndef ESTADO_H
#define ESTADO_H

#include "IA/Transicion.h"
#include <cstdlib>
#include <vector>
using namespace std;
#include "IA/Estado.h"
#include <irrlicht.h>
using namespace irr;
using namespace core;

class Estado
{
public:
    vector<Transicion*>transiciones;
    Estado(vector<Transicion*>transiciones);
    Transicion* getNextTransicion(irr::core::map<stringw,stringw>*strings,
                                  irr::core::map<stringw,stringw>*strings_contrario,
                                  irr::core::map<stringw,int>*enteros,
                                  irr::core::map<stringw,int>*enteros_contrario
                                  );
};

#endif
