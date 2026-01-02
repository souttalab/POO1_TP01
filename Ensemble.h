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
    
    enum crduEstInclus { NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICTE };
    crduEstInclus EstInclus (const Ensemble & unEnsemble ) const;

    enum crduAjouter { DEJA_PRESENT, PLEIN, AJOUTE };
    crduAjouter Ajouter (int aAjouter );
    bool retirer (int element);
    
protected :
    unsigned int cardinaliteMax, cardinaliteAct;
    int* elements[];
};

#endif
