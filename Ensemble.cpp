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

crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble) const {

    for (unsigned int i = 0; i < cardinaliteAct; i++) {
        bool trouve = false;
        for (unsigned int j = 0; j < unEnsemble.cardinaliteAct; j++) {
            if (elements[i] == unEnsemble.elements[j]) {
                trouve = true;
                break; 
            }
        }

        if (!trouve) {
            return NON_INCLUSION; 
        }
    }

    if (cardinaliteAct == unEnsemble.cardinaliteAct) {
        return INCLUSION_LARGE; 
    }
    
    return INCLUSION_STRICTE; 
}

crduAjouter Ensemble::Ajouter (int aAjouter ) {
    bool present = false;
    for (unsigned int i=0; i<cardinaliteAct; i++ ){
        if (elements[i] == aAjouter ) {
            present = true;
            break;
        }
    }
    if (present ){ 
        return DEJA_PRESENT;
    }

    if (cardinaliteAct == cardinaliteMax ) {
        return PLEIN;
    }
    else {
        elements[cardinaliteAct] = aAjouter;
        cardinaliteAct++;
        return AJOUTE;
    }
}

bool Ensemble::Retirer(int element) {
    bool present = false;
    unsigned int indiceTrouve = 0;

    for (unsigned int i = 0; i < cardinaliteAct; i++) {
        if (elements[i] == element) {
            present = true;
            indiceTrouve = i;
            break;
        }
    }

    unsigned int nouvelleCard = present ? (cardinaliteAct - 1) : cardinaliteAct;

    int* nvelements = NULL;
    if (nouvelleCard > 0) {
        nvelements = new int[nouvelleCard];
        unsigned int k = 0;
        for (unsigned int i = 0; i < cardinaliteAct; i++) {
            if (present && i == indiceTrouve) {
                continue; 
            }
            nvelements[k++] = elements[i];
        }
    }

    delete[] elements;      
    elements = nvelements;  
    cardinaliteAct = nouvelleCard;
    cardinaliteMax = nouvelleCard;

    return present;
}

