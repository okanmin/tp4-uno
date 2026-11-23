#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct carte {
	int couleur;
	int numero;
	int type;
};

struct joueur {
	struct carte main[108];
	int nbCartes;
	int estHumain;
};

struct joueur joueurs[4];
int indexPioche = 0;
struct carte carteActuelle;
int couleurActuelle;

struct carte jeucarte[108];


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
	struct carte temp;
	for (int i = 0; i < 108; i++) {
		int j = rand() % 108;
		temp = jeucarte[j];
		jeucarte[j] = jeucarte[i];
		jeucarte[i] = temp;
	}
}

void afficherCarte(struct carte c) {
	if (c.type == 0) {
		printf("%d",c.numero);
	}
	else if (c.type == 1){
		printf("+2");
	}
	else if (c.type == 2) {
		printf("RV");
	}
	else if (c.type == 3) {
		printf("PS");
	}
	else if (c.type == 4) {
		printf("JJ");
	}
	else if (c.type == 5) {
		printf("+4");
	}
	if (c.couleur == 0) {
		printf(" R");
	}
	else if (c.couleur == 1) {
		printf(" V");
	}
	else if (c.couleur == 2) {
		printf(" B");
	}
	else if (c.couleur == 3) {
		printf(" J");
	}
	else if (c.couleur == -1) {
		printf(" N");
	}
}

void distribuer() {
	for (int joueur = 0; joueur < 4; joueur++) {
		joueurs[joueur].nbCartes = 0;
		for (int compte = 0; compte < 7; compte++) {
			joueurs[joueur].main[joueurs[joueur].nbCartes] = jeucarte[indexPioche];
			joueurs[joueur].nbCartes++;
			indexPioche++;
		}
	}
	joueurs[0].estHumain = 1;
	joueurs[1].estHumain = 0;
	joueurs[2].estHumain = 0;
	joueurs[3].estHumain = 0;
	carteActuelle = jeucarte[indexPioche];
	indexPioche++;
	couleurActuelle = carteActuelle.couleur;
	if (couleurActuelle == -1) {
		couleurActuelle = rand() % 4;
	}
}

int estJouable(struct carte c) {
	if (c.type == 4 || c.type == 5) {
		return 1;
	}
	if (c.couleur == couleurActuelle) {
		return 1;
	}
	if (c.type == 0 && carteActuelle.type == 0 && c.numero == carteActuelle.numero) {
		return 1;
	}
	if (c.type != 0 && c.type == carteActuelle.type) {
		return 1;
	}
	return 0;
}

void piocher (struct joueur *j){
	j->main[j->nbCartes] = jeucarte[indexPioche];
	j->nbCartes++;
	indexPioche++;
}

void retirerCarte(struct joueur* j, int indexCarte) {
	for (int i = indexCarte; i < j->nbCartes - 1; i++) {
		j->main[i] = j->main[i + 1];
	}
	j->nbCartes--;
}

void jouer() {

}

int main()
{
	srand(time(NULL));
	cartes();
	melanger();
	distribuer();
	afficherCarte(carteActuelle);
	printf("\n");
	for (int i = 0; i < joueurs[0].nbCartes; i++) {
		printf("%d : ", i + 1);
		afficherCarte(joueurs[0].main[i]);
		printf("\n");
	}
	return 0;
}


