#ifndef COORDONNEES_H
#define COORDONNEES_H

#include "Vecteur.h"

class Coordonees
{
public:
    static void initialiserEspace(int longueur, int hauteur); // m�thode static car l�espace sera le m�me pour tous les objets Coordonnees
    static inline int getLongueurEspace() { return longueurEspace; };
    static inline int getHauteurEspace() { return hauteurEspace; };
    Coordonees();
    Coordonees(float px, float py);

    // inline pour plus de performance, revient en terme de performance � un acc�s direct � l�attribut
    inline float getX() const { return x; };
    inline float getY() const { return y; };

    void operator+=(Vecteur const& vecteur);

    float calculerDistance(Coordonees const& autre) const;

private:
    void recalculer(); // recalcule les coordonn�es pour qu�elles soient dans les limites ; inutile d�y acc�der de l�ext�rieur, donc priv�e
    float x{ longueurEspace / 2.f };
    float y{ hauteurEspace / 2.f };

    // longueur et hauteur de l�espace sont static, partag�s par tous les objets Coordonnees
    static int longueurEspace;
    static int hauteurEspace;
};

#endif // COORDONNEES_H


