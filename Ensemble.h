#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#define CARD_MAX 5

class Ensemble {
public :
    Ensemble (unsigned int cardMax= CARD_MAX );
    Ensemble (int t[], unsigned int nbElements );
    virtual ~Ensemble ();

    void Afficher (void);
    bool EstEgal (const Ensemble &unEnsemble ) const;


protected :
    unsigned int cardinaliteMax, cardinaliteAct;
    int* elements[];
};

#endif
