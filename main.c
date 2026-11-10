struct carte {
	int couleur;
	int numero;
	int type;
};

struct carte jeucarte[108] = {

};


// couleurs : 0 = rouge, 1= vert, 2= bleu, 3= jaune
void cartes() {
	int b = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int k = 0; k <= 3; k++) {
				jeucarte[b] = (struct carte){k, i, 0};
				b = b + 1;
			}
		}
	}
	for (int k = 0; k <= 3; k++) {
		jeucarte[b] = (struct carte) {k, 0, 0};
		b = b + 1; 
// type : 0 = +2, 1 = inversion, 2 = passer
	}
	for (int i = 0; i <= 1; i++) {
		for (int k = 0; k <= 3; k++) {
			for (int j = 0; j <= 3; j++) {
			jeucarte[b] = (struct carte){k, 67, j}
			}
		}
	}
}

int main()
{
   
}


