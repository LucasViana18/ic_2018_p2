#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "functions.h"

/**
* Trabalho realizado por: Guilherme Saturno a21700118
*			Lucas Viana a21805095
*			Rita Saraiva a21807278
*/

/**
* ######################################  ATTENTION  #####################################################
* In order to read this code clearly, you have to understand the following logic of Matrix Arrengement:
* In p1Array[2][16] and p2Array[2][16]:
*	- Column 0 represents player's materials.
*	- Lines represents which material.
*		- Example:
*			Array[0][0] = Wool
*			Array[0][1] = Wool
*			Array[0][2] = Brick
*			Array[0][3] = Lumber
*			Array[0][4] = Grain
*			Array[0][5] = Iron
*			Array[0][6] = Pontos
*	- Column 1 represents the domain's
*	- Lines represents each domain
*	- The value of the variable indicate what the player have in the respective area
*		- Example:
*			Array[1][0] = "0" #In the map's(1) area #0 the player has nothing(0)
*			Array[1][1] = "1" #In the map's(1) area #1 the player has a village(1)
*			Array[1][2] = "2"	#In the map's(1) area #2 the player has a city(2)
* In mapArray[16][6]:
*	- Columns represents the position in the map.
*	- Lines represents it's productible materials and respective numbers.
*		- Example:
*			mapArray[0][2] = 4 #The area #0 shall produce Brick(2) if dices is = 4
*			mapArray[1][5] = 6 #The area #1 shall produce Iron(5) if dices is = 6
*			mapArray[2][4] = 9 #The area #2 shall produce Grain(4) if dices is = 9
* ##########################################################################################################
*/

int main(void)
{
// Declaração de variaveis
	int mapArray[16][6];
	int p1Array[2][16];
	int p2Array[2][16];
	int l, c, posicao, escolha, dices;
	bool swap = true;

	printf("*** SETTLERS OF CATAN ***\n\n");

	map();
//Ciclos for para atribuir valor 0 a todos os pontos da matriz
	for(l = 0 ; l < 16 ; l++ ){
		for(c = 0 ; c < 5 ; c++ ){
			mapArray[l][c] = 0;
		}
	}

	for(l = 0 ; l < 3 ; l++ ){
		for(c = 0 ; c < 16 ; c++ ){
			p1Array[l][c] = 0;
		}
	}

	for(l = 0 ; l < 3 ; l++ ){
		for(c = 0 ; c < 16 ; c++ ){
			p2Array[l][c] = 0;
		}
	}

//GROUND PROPERTIES #0
	mapArray[0][2] = 4;
	mapArray[0][3] = 11;
//GROUND PROPERTIES #1
	mapArray[1][5] = 6;
	mapArray[1][1] = 12;
	mapArray[1][3] = 11;
//GROUND PROPERTIES #2
	mapArray[2][2] = 5;
	mapArray[2][4] = 9;
	mapArray[2][1] = 12;
//GROUND PROPERTIES #3
	mapArray[3][1] = 10;
	mapArray[3][4] = 9;
//GROUND PROPERTIES #4
	mapArray[4][2] = 4;
	mapArray[4][4] = 3;
//GROUND PROPERTIES #5
	mapArray[5][5] = 6;
	mapArray[5][3] = 3;
	mapArray[5][1] = 10;
//GROUND PROPERTIES #6
	mapArray[6][2] = 5;
	mapArray[6][4] = 11;
	mapArray[6][1] = 10;
//GROUND PROPERTIES #7
	mapArray[7][1] = 10;
	mapArray[7][3] = 4;
//GROUND PROPERTIES #8
	mapArray[8][4] = 3;
	mapArray[8][2] = 8;
//GROUND PROPERTIES #9
	mapArray[9][3] = 3;
	mapArray[9][1] = 10;
	mapArray[9][0] = 9;
//GROUND PROPERTIES #10
	mapArray[10][4] = 11;
	mapArray[10][1] = 10;
	mapArray[10][0] = 9;
//GROUND PROPERTIES #11
	mapArray[11][3] = 4;
	mapArray[11][5] = 3;
//GROUND PROPERTIES #12
	mapArray[12][2] = 8;
	mapArray[12][5] = 5;
//GROUND PROPERTIES #13
	mapArray[13][1] = 10;
	mapArray[13][4] = 2;
	mapArray[13][5] = 5;
//GROUND PROPERTIES #14
	mapArray[14][1] = 10;
	mapArray[14][3] = 6;
	mapArray[14][4] = 2;
//GROUND PROPERTIES #15
  	mapArray[15][5] = 3;
  	mapArray[15][3] = 6;

	p1Array[0][7] = -1;
	p2Array[0][7] = -1;

	posicao = 0;
	while (p1Array[0][7] < 0 || p1Array[0][7] >15){
		printf("\n--------------------PLAYER1---------------------\nEscolhe a posição da sua aldeia: ");
		scanf("%d", &posicao);
		p1Array[0][7] = posicao;
	}

	while ((p2Array[0][7] < 0 || p2Array[0][7] >15) || (p2Array[0][7] == p1Array[0][7])){
		printf("\n--------------------PLAYER2---------------------\nEscolhe a posição da sua aldeia: ");
		scanf("%d", &posicao);
		p2Array[0][7] = posicao;
	}

	p1Array[1][p1Array[0][7]] = 1;
	p2Array[1][p2Array[0][7]] = 1;

	comandos();

	while(p1Array[0][6] < 6 && p2Array[0][6] < 6){

		if(swap == true){
			printf("\n--------------------PLAYER1--------------------\nEscolha um comando(<8> para Comandos): ");
		}else{
			printf("\n--------------------PLAYER2--------------------\nEscolha um comando(<8> para Comandos): ");
		}

		scanf("%d", &escolha);

		switch(escolha){

							// Lançar os dados e passar a vez
			case 1:	dices = dices1();
					printf("\nO número que calhou foi: %d\n", dices);
					case1(mapArray, p1Array, dices, "Player 1");
					case1(mapArray, p2Array, dices, "Player 2");
					if(swap == true){
						swap = false;
					}else{
						swap = true;
					}
					break;

							// Criar uma aldeia adjacente
			case 2:	if(swap == true){
					case2(p1Array, p2Array);
				}else{
					case2(p2Array, p1Array);
				}
				break;

							// Evoluir aldeia para cidade
			case 3: if(swap == true){
					case3(p1Array);
				}else{
					case3(p2Array);
				}
				break;

							// Trocar 10 materiais por 1 ponto
			case 4: if(swap == true){
					case4(p1Array);
				}else{
					case4(p2Array);
				}
				break;

							// Trocar 4 materiais por 1 material à escolha
			case 5:	if(swap == true){
					case5(p1Array);
				}else{
					case5(p2Array);
				}
				break;

							// Stats/Info
			case 6: if(swap == true){
					case6(p1Array);
				}else{
					case6(p2Array);
				}
				break;

							// Mapa
			case 7: map();
				break;

							// Comandos
			case 8: comandos();
				break;

							// Regras
			case 9: regras();
				break;

							// Sair
			case 10:p1Array[0][6] = 6;
				p2Array[0][6] = 6;
				break;

			default: printf("\nPressione um comando existente!\n");
		}
	}
	printf("\n*** OBRIGADO POR JOGAR! ***\n");

	return 0;
}
