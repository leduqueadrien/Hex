
#ifndef VECTEUR_HPP
#define VECTEUR_HPP

template<typename T>
class Vecteur {
	private :
		int size;
		T * vecteur;

	public :
		Vecteur(int);
		int getSize();
		int getCell(int ,int);
		void setCell(int, int, int);
};

#endif