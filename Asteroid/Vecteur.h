#pragma once
struct Vecteur // tout est public par défaut pour struct
{
	void operator+=(Vecteur const& autre);
	void operator-=(Vecteur const& autre);
	Vecteur operator*(float coefficient) const;
	
	
	float x{ 0.f };
	float y{ 0.f };

	static Vecteur creerDepuisAngle(float taille, float angleEnDegree);
	
	static void afficherVecteur(Vecteur vecteur);
};

