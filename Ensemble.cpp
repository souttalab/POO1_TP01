#include <iostream>
using namespace std;
#include "Ensemble.h"

Ensemble::Ensemble(unsigned int cardMax) {
    cardinaliteMax=cardMax;
    cardinaliteAct=0;

    if (cardMax>0 ) {
        elements= new int[cardMax];
    }
    else {
        elements = NULL;
    }
}

Ensemble::Ensemble(int t[], unsigned int nbElements ) {
    unsigned int elementRajoute=0;
    if (nbElements>0) {
        elements = new int[nbElements];
        for(unsigned int i=0; i<nbElements; i++ ) {
            bool dejavu=false;
            for(unsigned int j=0; j<elementRajoute; j++ ) {
                if(elements[j]==t[i]) {
                    dejavu=true;
                    break;
                }
            }
        if (!dejavu) {
            elements[elementRajoute]=t[i];
            elementRajoute++;
        }
    }
    }
    else {
        elements=NULL;
    }
    
    cardinaliteMax=nbElements;
    cardinaliteAct=elementRajoute;
}

Ensemble::~Ensemble() {
    delete[] elements;
}

