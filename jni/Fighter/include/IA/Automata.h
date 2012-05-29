#ifndef AUTOMATA_H
#define AUTOMATA_H


#include "IA/Estado.h"
#include "TinyXml/tinyxml.h"
#include <irrlicht.h>
using namespace irr;
using namespace core;
#include <vector>
using namespace std;

class Automata
{
    irr::core::map<stringw,Estado*> estados;
    stringw estado_actual;
    int wait;
public:
Transicion *transicion_a_recompenzar;
    Automata(char* archivo,char* archivo_default);
    Estado* getEstadoInicial();
    stringw getNextInput(irr::core::map<stringw,stringw>*strings,
                         irr::core::map<stringw,stringw>*strings_contrario,
                         irr::core::map<stringw,int>*enteros,
                         irr::core::map<stringw,int>*enteros_contrario
                         );
    void cargarDesdeXML(char* archivo,char* archivo_default);
};

#endif
