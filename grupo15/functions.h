
// Functions

int case6(int Array[][16]){
	printf("\nVocê possui %i pontos.", Array[0][6]);
	printf("\nTerritórios com aldeias:");
	for(int j = 0 ; j < 16 ; j++ ) {
		if (Array[1][j] == 1){
			printf(" %i,", j);
		}
	}
	printf("\nTerritórios com cidades:");
	for(int j = 0 ; j < 16 ; j++ ) {
		if (Array[1][j] == 2){
			printf(" %i,", j);
		}
	}
	printf("\nMateriais: %i Wool, %i Brick, %i Lumber, %i Grain, %i Iron.\n", Array[0][1], Array[0][2], Array[0][3], Array[0][4], Array[0][5]);
	return 0;
}

int case5(int Array[][16]){
	int material;
	printf("\nMateriais disponiveis:\n<1> Wool\n<2> Brick\n<3> Lumber\n<4> Grain\n<5> Iron\nMaterial a dar: ");
	scanf("%i", &material);
	if(Array[0][material] < 4){
		printf("Lamento, mas não tem material suficiente.\n");
	}else{
		Array[0][material] -= 4;
		printf("Material a receber: ");
		scanf("%i", &material);
		Array[0][material] += 1;
		printf("Troca efetuada!\n");
  	}
	return 0;
}

int case4(int Array[][16]){
	int material;
	printf("\nMateriais disponiveis:\n<1> Wool\n<2> Brick\n<3> Lumber\n<4> Grain\n<5> Iron\n\nMaterial a dar: ");
	scanf("%i", &material);
	if(Array[0][material] < 10){
		printf("Lamento, mas não tem material suficiente.\n");
	}else{
		Array[0][material] -= 10;
		Array[0][6] += 1;
		printf("\n *** RECEBESTE 1 PONTO! *** \n");
	}
	return 0;
}

int case3(int Array[][16]){
	int opcao = 0;
	if(Array[0][4] >= 2 && Array[0][5] >= 3){
		printf("\nSelecione a aldeia que deseja evoluir: ");
		scanf("%d", &opcao);
		if(Array[1][opcao] == 1){
			Array[0][4] -= 2;
			Array[0][5] -= 3;
			Array[0][6] += 2;
			Array[1][opcao] = 2;
			printf("\nEvolução completa! Agora tem uma cidade!\n");
			printf("\n *** RECEBESTE 2 PONTOS! *** \n");

		}else{
			printf("Não é possivel evoluir esta aldeia!\n");
		}

	}else{
		printf("Lamento, mas não tem os materiais necessários\n");
	}
	return 0;
}

int case2(int Array[][16], int pArray[][16]){
	int opcao;

	if(Array[0][1] >= 1 && Array[0][2] >= 1 && Array[0][3] >= 1 && Array[0][4] >= 1){
		printf("\nSelecione onde criar a aldeia adjacente: ");
		scanf("%i", &opcao);
		for(int j = 0 ; j < 16 ; j++){
			if ((Array[1][j] == 1 || Array[1][j] == 2) && (opcao == j+1 || opcao == j-1 || opcao == j-4 || opcao == j+4) && (pArray[1][opcao] != 1 && pArray[1][opcao] != 2)){
				Array[1][opcao] = 1;
				Array[0][1] -= 1;
				Array[0][2] -= 1;
				Array[0][3] -= 1;
				Array[0][4] -= 1;
				Array[0][6] += 1;
				printf("\nCriação completa! Agora tem mais uma aldeia!\n");
				printf("\n *** RECEBESTE 1 PONTO! *** \n");
			}
		}
	}else{
		printf("\nRecursos insuficientes!\n");
	}
	if (Array[1][opcao] != 1){
		printf("\nNão é possível estabelecer uma aldeia nessa posição.\n");
	}
	return 0;
}

int dices1(){

	srand(time(NULL));
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	int dices = dice1 + dice2;

	return dices;
}

int case1(int mArray[][6], int pArray[][16], int dices, char plr[]){
	for(int j = 0 ; j < 16 ; j++ ) {
		if (pArray[1][j] == 1 || pArray[1][j] == 2){
			for(int c = 0 ; c < 6 ; c++ ){
				if(mArray[j][c] == dices && pArray[1][j] == 1){
					if(c == 0){
						pArray[0][1] += 1;
						printf("%s recebeste +1 de Wool!\n", plr);
					}else{
						pArray[0][c] += 1;
					}
					if(c == 1){
						printf("%s recebeste +1 de Wool!\n", plr);
					}else if (c == 2){
						printf("%s recebeste +1 de Brick!\n", plr);
					}else if (c == 3){
						printf("%s recebeste +1 de Lumber!\n", plr);
					}else if (c == 4){
						printf("%s recebeste +1 de Grain!\n", plr);
					}else if (c == 5){
						printf("%s recebeste +1 de Iron!\n", plr);
					}
				}
				if(mArray[j][c] == dices && pArray[1][j] == 2) {
					pArray[0][c] += 2;
					if (c == 1){
						printf("%s recebeste +2 de Wool!\n", plr);
					}else if (c == 2){
						printf("%s recebeste +2 de Brick!\n", plr);
					}else if (c == 3){
						printf("%s recebeste +2 de Lumber!\n", plr);
					}else if (c == 4){
						printf("%s recebeste +2 de Grain!\n", plr);
					}else if (c == 5){
						printf("%s recebeste +2 de Iron!\n", plr);
					}
				}
			}
		}
	}
	return 0;
}

void map(){
	printf("+----------+----------+----------+----------+\n");
	printf("|    #0    |    #1    |    #2    |    #3    |\n");
	printf("| N: D     | N: D     | N: D     | N: D     |\n");
	printf("| S: B (4) | S: I (6) | S: B (5) | S: W (10)|\n");
	printf("| E: L (11)| E: W (12)| E: G (9) | E: D     |\n");
	printf("| W: D     | W: L (11)| W: W (12)| W: G (9) |\n");
	printf("+----------+----------+----------+----------+\n");
	printf("|    #4    |    #5    |    #6    |    #7    |\n");
	printf("| N: B (4) | N: I (6) | N: B (5) | N: W (10)|\n");
	printf("| S: G (3) | S: L (3) | S: G (11)| S: L (4) |\n");
	printf("| E: D     | E: W (10)| E: D     | E: D     |\n");
	printf("| W: D     | W: D     | W: W (10)| W: D     |\n");
	printf("+----------+----------+----------+----------+\n");
	printf("|    #8    |    #9    |    #10   |    #11   |\n");
	printf("| N: G (3) | N: L (3) | N: G (11)| N: L (4) |\n");
	printf("| S: B (8) | S: W (10)| S: W (10)| S: I (3) |\n");
	printf("| E: D     | E: W (9) | E: D     | E: D     |\n");
	printf("| W: D     | W: D     | W: W (9) | W: D     |\n");
	printf("+----------+----------+----------+----------+\n");
	printf("|    #12   |    #13   |   #14    |   #15    |\n");
	printf("| N: B (8) | N: W (10)| N: W (10)| N: I (3) |\n");
	printf("| S: D     | S: D     | S: D     | S: D     |\n");
	printf("| E: I (5) | E: G (2) | E: L (6) | E: D     |\n");
	printf("| W: D     | W: I (5) | W: G (2) | W: L (6) |\n");
	printf("+----------+----------+----------+----------+\n");

}

void comandos(){
	printf("\nComandos:\n");
	printf(" <1> Lançar dados.\n <2> Construir uma aldeia adjacente.\n <3> Evoluir uma aldeia para cidade.\n <4> Trocar 10 materiais por 1 ponto.\n <5> Trocar 4 materiais por 1 material à escolha.\n <6> Stats.\n <7> Mapa.\n <8> Comandos.\n <9> Regras.\n <10> Sair.\n");
}

void regras(){
	printf("\nRegras:\n -O jogo começa quando ambos os players escolherem a sua primeira aldeia\n -Recebes os recursos quando a soma dos dados é igual a um ou mais numeros da aldeia e os seus terrenos adjacentes\n -Só podes construir aldeias em terrenos adjacentes\n -Só podes construir cidades numa aldeia\n -Podes trocar 4 cartas do mesmo recurso por uma do recurso\n -Quando tens uma cidade recebes 2x os recursos\n -O objetivo do jogo é chegar a 6 Pontos\n\n");
	printf("Como Ganhar Pontos:\n -Ganhas 1 Ponto ao construires uma aldeia\n -Ganhas 2 Pontos ao contruires uma cidade\n -Podes trocar 10 cartas do mesmo recurso por 1 Ponto  ");
	printf("\n\nAldeia: B + L + G + W\nCidade: G + G + I + I + I\n");
	printf("\nNo lançar do dado existem diferentes probabilidades de numeros calharem não te esqueças, por isso escolhe cuidadosamente ;) \n\n");
}
