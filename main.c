#include <stdio.h>

struct carte {
	int couleur;
	int numero;
	int type;
};

struct carte jeucarte[108] = {};


// couleurs : 0 = rouge, 1= vert, 2= bleu, 3= jaune
void cartes() {
	int index = 0;
	for (int numero = 1; numero <= 9; numero++) {
		for (int exemplaire = 0; exemplaire <= 1; exemplaire++) {
			for (int couleur = 0; couleur <= 3; couleur++) {
				jeucarte[index] = (struct carte){couleur, numero, 0};
				index = index + 1;
			}
		}
	}
	for (int couleur = 0; couleur <= 3; couleur++) {
		jeucarte[index] = (struct carte) {couleur, 0, 0};
		index = index + 1; 

// type : 0 = normal 1 = +2, 2 = inversion, 3 = passer, 4 = joker, 5= +4
	}
	for (int exemplaire = 0; exemplaire <= 1; exemplaire++) {
		for (int couleur = 0; couleur <= 3; couleur++) {
			for (int type = 1; type <= 3; type++) {
				jeucarte[index] = (struct carte){couleur, -1, type};
				index = index + 1;
			}
		}
	}
	for (int exemplaire = 0; exemplaire <= 3; exemplaire++) {
		for (int type = 4; type <= 5; type++) {
			jeucarte[index] = (struct carte){-1,-1,type}; 
			index = index + 1;
		}
	}
}

void melanger() {
	
}

int main()
{
	cartes();
	for (int i = 0; i < 108; i++) {
		printf("Carte %3d -> Couleur: %2d | Numero: %2d | Type: %d\n",
			i + 1, jeucarte[i].couleur, jeucarte[i].numero, jeucarte[i].type);
	}
	return 0;
}


