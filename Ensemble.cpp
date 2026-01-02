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

void Ensemble::Afficher() {
    cout << cardinaliteAct << endl;
    cout << cardinaliteMax << endl;

    for (unsigned int i = 0; i < cardinaliteAct; i++) {
        for (unsigned int j = i + 1; j < cardinaliteAct; j++) {
            if (elements[i] > elements[j]) {
                int temp = elements[i];
                elements[i] = elements[j];
                elements[j] = temp;
            }
        }
    }

    std::cout << "{";
    for (unsigned int i = 0; i < cardinaliteAct; i++) {
        std::cout << elements[i];
        if (i < cardinaliteAct - 1) {
            std::cout << ",";
        }
    }
    std::cout << "}\r\n";
}

bool Ensemble::EstEgal(const Ensemble &unEnsemble ) const {
    if (unEnsemble.cardinaliteAct != cardinaliteAct ) {
        return false;
    } 
    else {
        bool verif = false;
        for (unsigned int i=0; i<cardinaliteAct; i++) {
            for(unsigned int j=0; j<unEnsemble.cardinaliteAct; j++) {
                if (unEnsemble.elements[j] == elements[i]) {
                    verif = true;
                    break;
                }
            }
            if (verif == false) {
                return false; // Preuve d'inégalité 
            }
        }
    }
    return true;

} 

