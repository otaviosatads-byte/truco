#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 11
#define MAO 6
#define RODADA 4

void preparaMesa(int mesa[TAM][TAM], int marcaTento[12][6], int marcadorRodadas[2][5]) {
	/* prepara a mesa para a partida*/
	int i, j;
	for(i = 0; i < TAM; i+= 1) {
		for(j = 0; j < TAM; j += 1) {
			mesa[i][j] = 0;
			marcaTento[i][j] = 0;
		}
	}
	marcaTento[0][1] = 23;
	marcaTento[0][4] = 23;

	/*constroi o marcador de ponts*/
	marcaTento[0][0] = 20;
	marcaTento[0][5] = 21;
	for(i = 1; i < 12; i += 1) {
		marcaTento[i][0] = i;
	}
	for(i = 1; i < 12; i += 1) {
		marcaTento[i][5] = i;
	}
	
	for(i = 0; i < 2; i += 1){ 
	    for(j = 0; j < 5; j += 1){ 
	        marcadorRodadas[i][j] = 0;
	    }
	}
	marcadorRodadas[0][0] = 1;
	marcadorRodadas[0][2] = 1;
	marcadorRodadas[0][4] = 1;
	
}
void marcarPontos(int pontosEles, int pontosNos, int marcaTento[12][6]){
	int i;
	/*Apaga o posição do antigo tento*/
	for(i = 0; i < 12; i+= 1){
		if(marcaTento[i][1] == 23){
			marcaTento[i][1] = 0;
		}
	}
	/* coloca o tento na sua nova posição*/
	for(i = 0; i < 12; i+= 1){
		if(i == pontosEles){
			marcaTento[i][1] = 23;
		}
	}
	for(i = 0; i < 12; i+= 1){
		if(marcaTento[i][4] == 23){
			marcaTento[i][4] = 0;
		}
	}

	for(i = 0; i < 12; i+= 1){
		if(i == pontosNos){
			marcaTento[i][4] = 23;
		}
	}

}
void distribuirCartas(int eles1[MAO], int eles2[MAO], int nos1[MAO], int nos2[MAO], int naipes[4]) {
	int verificador, contador, i;
	int exemplar[2];
	verificador = 0;
	contador = 0;

	while(contador < 4) {
		if(verificador < 2) {
			/* distribui as cartas ao eles1*/
			if(contador == 0) {
				for(i = 0; i < MAO; i += 1) {
					if(i % 2 == 0) {
						eles1[i] = (rand() % 10) + 1;
					}
					else {
						eles1[i] = naipes[rand() % 4];
					}
				}
				/*verifica se a cartas repetidas em eles1*/
				for(i = 0; i < MAO; i += 1) {
					if(i == 0) {
						exemplar[0] = eles1[0];
					}
					else if(i == 1) {
						exemplar[1] = eles1[1];
						if(exemplar[0] == eles1[2] && exemplar[1] == eles1[3]) {
							verificador = 2;
						}
						if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
							verificador = 2;
						}
					}
					else if(i == 2) {
						exemplar[0] = eles1[2];
					}
					else if(i == 3) {
						exemplar[1] = eles1[3];

						if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
							verificador = 2;
						}
					}
				}
				contador += 1;
			}

			else if(contador == 1) {
				/* distrubiu as cartas para eles2*/
				for(i = 0; i < MAO; i += 1) {
					if(i % 2 == 0) {
						eles2[i] = (rand() % 10) + 1;
					}
					else {
						eles2[i] = naipes[rand() % 4];
					}
				}
				/*verifica se a cartas repetidas em eles2*/
				for(i = 0; i < MAO; i += 1) {
					if(i == 0) {
						exemplar[0] = eles2[0];
					}
					else if(i == 1) {
						exemplar[1] = eles2[1];
						if(exemplar[0] == eles2[2] && exemplar[1] == eles2[3]) {
							verificador = 2;
						}
						if(exemplar[0] == eles2[4] && exemplar[1] == eles2[5]) {
							verificador = 2;
						}
					}
					else if(i == 2) {
						exemplar[0] = eles2[2];
					}
					else if(i == 3) {
						exemplar[1] = eles2[3];

						if(exemplar[0] == eles2[4] && exemplar[1] == eles2[5]) {
							verificador = 2;
						}
					}
				}
				/*verifica a 1º carta da mão eles2 com a mão eles1*/
				exemplar[0] = eles2[0];
				exemplar[1] = eles2[1];

				if(exemplar[0] == eles1[0] && exemplar[1] == eles1[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[2] && exemplar[1] == eles1[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
					verificador = 2;
				}

				/*verifica a 2º carta da mão eles2 com a mão eles1*/
				exemplar[0] = eles2[2];
				exemplar[1] = eles2[3];

				if(exemplar[0] == eles1[0] && exemplar[1] == eles1[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[2] && exemplar[1] == eles1[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
					verificador = 2;
				}

				/*verifica a 3º carta da mão eles2 com a mão eles1*/
				exemplar[0] = eles2[4];
				exemplar[1] = eles2[5];

				if(exemplar[0] == eles1[0] && exemplar[1] == eles1[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[2] && exemplar[1] == eles1[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
					verificador = 2;
				}
				contador += 1;
			}

			if(contador == 2) {
				/*distrubiu as cartas para a mao nos2*/
				for(i = 0; i < MAO; i += 1) {
					if(i % 2 == 0) {
						nos2[i] = (rand() % 10) + 1;
					}
					if(i % 2 != 0) {
						nos2[i] = naipes[rand() % 4];
					}
				}
				/* verifica as cartas repetidas na mão nos2 */
				for(i = 0; i < MAO; i += 1) {
					if(i == 0) {
						exemplar[i] = nos2[0];
					}
					else if(i == 1) {
						exemplar[i] =  nos2[1];
						if(exemplar[0] == nos2[2] && exemplar[1] == nos2[3]) {
							verificador = 2;
						}
						if(exemplar[0] == nos2[4] && exemplar[1] == nos2[5]) {
							verificador = 2;
						}
					}
					else if(i == 2) {
						exemplar[0] = nos2[2];
					}
					else if(i == 3) {
						exemplar[1] = nos2[3];

						if(exemplar[0] == nos2[4] && exemplar[1] == nos2[5]) {
							verificador = 2;
						}
					}
				}
				/* verifica a 1º carta da mão nos2 com as da mão eles1 */
				exemplar[0] = nos2[0];
				exemplar[1] = nos2[1];

				if(exemplar[0] == eles1[0] && exemplar[1] == eles1[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[2] && exemplar[1] == eles1[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
					verificador = 2;
				}
				/* verifica a 2º carta da mão nos2 com as da mãoo eles1*/
				exemplar[0] = nos2[2];
				exemplar[1] = nos2[3];

				if(exemplar[0] == eles1[0] && exemplar[1] == eles1[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[2] && exemplar[1] == eles1[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
					verificador = 2;
				}
				/* verifica a 3º carta da mão nos2 com as da mãoo eles1*/
				exemplar[0] = nos2[4];
				exemplar[1] = nos2[5];

				if(exemplar[0] == eles1[0] && exemplar[1] == eles1[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[2] && exemplar[1] == eles1[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
					verificador = 2;
				}

				/* verifica a 1º carta da mão nos2 com as da mão eles2 */
				exemplar[0] = nos2[0];
				exemplar[1] = nos2[1];

				if(exemplar[0] == eles2[0] && exemplar[1] == eles2[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[2] && exemplar[1] == eles2[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[4] && exemplar[1] == eles2[5]) {
					verificador = 2;
				}

				/* verifica a 2º carta da mão nos2 com as da mãoo eles2*/
				exemplar[0] = nos2[2];
				exemplar[1] = nos2[3];

				if(exemplar[0] == eles2[0] && exemplar[1] == eles2[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[2] && exemplar[1] == eles2[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[4] && exemplar[1] == eles2[5]) {
					verificador = 2;
				}
				/* verifica a 3º carta da mão nos2 com as da mãoo eles2*/
				exemplar[0] = nos2[4];
				exemplar[1] = nos2[5];

				if(exemplar[0] == eles2[0] && exemplar[1] == eles2[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[2] && exemplar[1] == eles2[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[4] && exemplar[1] == eles2[5]) {
					verificador = 2;
				}
				contador += 1;
			}
			if(contador == 3) {
				/*distrubiu as cartas para a mao nos1*/
				for(i = 0; i < MAO; i += 1) {
					if(i % 2 == 0) {
						nos1[i] = (rand() % 10) + 1;
					}
					if(i % 2 != 0) {
						nos1[i] = naipes[rand() % 4];
					}
				}
				/* verifica as cartas repetidas na mão nos1 */
				for(i = 0; i < MAO; i += 1) {
					if(i == 0) {
						exemplar[0] = nos1[0];
					}
					else if(i == 1) {
						exemplar[1] =  nos1[1];
						if(exemplar[0] == nos1[2] && exemplar[1] == nos1[3]) {
							verificador = 2;
						}
						if(exemplar[0] == nos1[4] && exemplar[1] == nos1[5]) {
							verificador = 2;
						}
					}
					else if(i == 2) {
						exemplar[0] = nos1[2];
					}
					else if(i == 3) {
						exemplar[1] = nos1[3];

						if(exemplar[0] == nos1[4] && exemplar[1] == nos1[5]) {
							verificador = 2;
						}
					}
				}
				/* verifica a 1º carta da mão nos1 com as da mão eles1 */
				exemplar[0] = nos1[0];
				exemplar[1] = nos1[1];

				if(exemplar[0] == eles1[0] && exemplar[1] == eles1[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[2] && exemplar[1] == eles1[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
					verificador = 2;
				}

				/* verifica a 2º carta da mão nos1 com as da mãoo eles1*/
				exemplar[0] = nos1[2];
				exemplar[1] = nos1[3];

				if(exemplar[0] == eles1[0] && exemplar[1] == eles1[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[2] && exemplar[1] == eles1[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
					verificador = 2;
				}
				/* verifica a 3º carta da mão nos1 com as da mãoo eles1*/
				exemplar[0] = nos1[4];
				exemplar[1] = nos1[5];

				if(exemplar[0] == eles1[0] && exemplar[1] == eles1[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[2] && exemplar[1] == eles1[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles1[4] && exemplar[1] == eles1[5]) {
					verificador = 2;
				}
				/* verifica a 1º carta da mão nos1 com as da mão eles2 */
				exemplar[0] = nos1[0];
				exemplar[1] = nos1[1];

				if(exemplar[0] == eles2[0] && exemplar[1] == eles2[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[2] && exemplar[1] == eles2[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[4] && exemplar[1] == eles2[5]) {
					verificador = 2;
				}

				/* verifica a 2º carta da mão nos1 com as da mãoo eles2*/
				exemplar[0] = nos1[2];
				exemplar[1] = nos1[3];

				if(exemplar[0] == eles2[0] && exemplar[1] == eles2[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[2] && exemplar[1] == eles2[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[4] && exemplar[1] == eles2[5]) {
					verificador = 2;
				}

				/* verifica a 3º carta da mão nos1 com as da mãoo eles2*/
				exemplar[0] = nos1[4];
				exemplar[1] = nos1[5];

				if(exemplar[0] == eles2[0] && exemplar[1] == eles2[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[2] && exemplar[1] == eles2[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == eles2[4] && exemplar[1] == eles2[5]) {
					verificador = 2;
				}
				/* verifica a 1º carta da mão nos1 com as da mão nos2 */
				exemplar[0] = nos1[0];
				exemplar[1] = nos1[1];

				if(exemplar[0] == nos2[0] && exemplar[1] == nos2[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == nos2[2] && exemplar[1] == nos2[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == nos2[4] && exemplar[1] == nos2[5]) {
					verificador = 2;
				}

				/* verifica a 2º carta da mão nos1 com as da mão nos2 */
				exemplar[0] = nos1[2];
				exemplar[1] = nos1[3];

				if(exemplar[0] == nos2[0] && exemplar[1] == nos2[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == nos2[2] && exemplar[1] == nos2[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == nos2[4] && exemplar[1] == nos2[5]) {
					verificador = 2;
				}
				/* verifica a 3º carta da mão nos1 com as da mão nos2 */
				exemplar[0] = nos1[4];
				exemplar[1] = nos1[5];

				if(exemplar[0] == nos2[0] && exemplar[1] == nos2[1]) {
					verificador = 2;
				}
				else if(exemplar[0] == nos2[2] && exemplar[1] == nos2[3]) {
					verificador = 2;
				}
				else if(exemplar[0] == nos2[4] && exemplar[1] == nos2[5]) {
					verificador = 2;
				}
				contador += 1;
			}
		}

		/* caso tenha cartas repetidas em cada mão */
		else {
			verificador = 0;
			if(contador == 0) {
				for(i = 0; i < MAO; i += 1) {
					eles1[i] = 0;
				}
				contador = 0;
			}
			else if(contador == 1) {
				for(i = 0; i < MAO; i += 1) {
					eles2[i] = 0;
				}
				contador = 1;
			}

			else if(contador == 2) {
				for(i = 0; i < MAO; i += 1) {
					nos2[i] = 0;
				}
				contador = 2;
			}
			else if(contador == 3) {
				for(i = 0; i < MAO; i += 1) {
					nos1[i] = 0;
				}
				contador = 3;
			}
		}
	}
}

void posicionaCartas(int (*mesa)[TAM], int (*eles1)[MAO], int (*eles2)[MAO], int (*nos1)[MAO], int (*nos2)[MAO]) {
	int j, i;
	/*Distribui as cartas as mesa*/

	j = 1;
	for(i = 4; i != 7; i += 1) {
		mesa[i][0] = (*eles1)[j];
		j += 2;
	}
	j = 0;
	for(i = 4; i != 7; i += 1) {
		mesa[i][1] = (*eles1)[j];
		j += 2;
	}
	j = 1;
	for(i = 4; i != 7; i += 1) {
		mesa[0][i] = (*nos2)[j];
		j += 2;
	}
	j = 0;
	for(i = 4; i != 7; i += 1) {
		mesa[1][i] = (*nos2)[j];
		j += 2;
	}
	j = 1;
	for(i = 4; i != 7; i += 1) {
		mesa[i][10] = (*eles2)[j];
		j += 2;
	}
	j = 0;
	for(i = 4; i != 7; i += 1) {
		mesa[i][9] = (*eles2)[j];
		j += 2;
	}
	j = 1;
	for(i = 4; i != 7; i += 1) {
		mesa[8][i] = (*nos1)[j];
		j += 2;
	}
	j = 0;
	for(i = 4; i != 7; i += 1) {
		mesa[9][i] = (*nos1)[j];
		j += 2;
	}
}

void mostrarRodada(int marcadorRodadas[2][5]){ 
    int i, j;
    	printf("===Marca rodada===\n");

    for(i = 0; i < 2; i+= 1){ 
        for(j = 0; j < 5; j += 1){ 
            if(marcadorRodadas[i][j] == 1){ 
                printf("R");
            }
            else if(marcadorRodadas[i][j] == 2){ 
                printf("N");
            }
            else if(marcadorRodadas[i][j] == 3){ 
                printf("E");
            }
            else{ 
                printf("%d", marcadorRodadas[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}


void mostrarMesa(int mesa[TAM][TAM], int manilha, int marcaTento[12][6]) {
	int i, j;
	printf("===Marca tento===\n");
	for(i = 0; i < 12; i += 1) {
		for(j = 0; j < 6; j  += 1) {
			if(marcaTento[i][j] == 20) {
				printf("N");
			}
			else if(marcaTento[i][j] ==  21) {
				printf("E");
			}
			else if(marcaTento[i][j] ==  23) {
				printf("*");
			}
			else {
				printf("%d", marcaTento[i][j]);
			}
		}
		printf("\n");
	}
	/* mostra a mesa */
	printf("=======Mesa=========\n");
	for(i = 0; i < TAM; i += 1) {
		for(j = 0; j < TAM; j += 1) {

			if(mesa[i][j] == 1 || mesa[i][j] == 11) {
				printf("A");
			}
			else if(mesa[i][j] == 12) {
				printf("2");
			}
			else if(mesa[i][j] == 13) {
				printf("3");
			}
			else if(mesa[i][j] <= 7) {
				printf("%d", mesa[i][j]);
			}
			else if(mesa[i][j] == 8) {
				printf("Q");
			}
			else if(mesa[i][j] == 9) {
				printf("J");
			}
			else if(mesa[i][j] == 10) {
				printf("K");
			}
			else if (mesa[i][j] == 14) {
				if(manilha == 1) {
					printf("A");
				}
				else if(manilha == 2) {
					printf("2");
				}
				else if(manilha == 3) {
					printf("3");
				}
				else if(manilha == 4) {
					printf("4");
				}
				else if(manilha == 5) {
					printf("5");
				}
				else if(manilha == 6) {
					printf("6");
				}
				else if(manilha == 7) {
					printf("7");
				}
				else if(manilha == 8) {
					printf("Q");
				}
				else if(manilha == 9) {
					printf("J");
				}
				else if(manilha == 10) {
					printf("K");
				}
			}
			else if (mesa[i][j] == 15) {
				if(manilha == 1) {
					printf("A");
				}
				else if(manilha == 2) {
					printf("2");
				}
				else if(manilha == 3) {
					printf("3");
				}
				else if(manilha == 4) {
					printf("4");
				}
				else if(manilha == 5) {
					printf("5");
				}
				else if(manilha == 6) {
					printf("6");
				}
				else if(manilha == 7) {
					printf("7");
				}
				else if(manilha == 8) {
					printf("Q");
				}
				else if(manilha == 9) {
					printf("J");
				}
				else if(manilha == 10) {
					printf("K");
				}
			}
			else if (mesa[i][j] == 16) {
				if(manilha == 1) {
					printf("A");
				}
				else if(manilha == 2) {
					printf("2");
				}
				else if(manilha == 3) {
					printf("3");
				}
				else if(manilha == 4) {
					printf("4");
				}
				else if(manilha == 5) {
					printf("5");
				}
				else if(manilha == 6) {
					printf("6");
				}
				else if(manilha == 7) {
					printf("7");
				}
				else if(manilha == 8) {
					printf("Q");
				}
				else if(manilha == 9) {
					printf("J");
				}
				else if(manilha == 10) {
					printf("K");
				}
			}
			else if (mesa[i][j] == 17) {
				if(manilha == 1) {
					printf("A");
				}
				else if(manilha == 2) {
					printf("2");
				}
				else if(manilha == 3) {
					printf("3");
				}
				else if(manilha == 4) {
					printf("4");
				}
				else if(manilha == 5) {
					printf("5");
				}
				else if(manilha == 6) {
					printf("6");
				}
				else if(manilha == 7) {
					printf("7");
				}
				else if(manilha == 8) {
					printf("Q");
				}
				else if(manilha == 9) {
					printf("J");
				}
				else if(manilha == 10) {
					printf("K");
				}
			}
			else if(mesa[i][j] == 80) {
				printf("P");
			}
			else if(mesa[i][j] == 67) {
				printf("C");
			}
			else if(mesa[i][j] == 69) {
				printf("E");
			}
			else if(mesa[i][j] == 79) {
				printf("O");
			}
			else if(mesa[i][j] == 94) {
				printf("^");
			}

		}
		printf("\n");
	}

}
void partida(int mesa[TAM][TAM], int seta, int (*nos1)[MAO], int manilha, int (*eles2)[MAO], int (*eles1)[MAO], int (*nos2)[MAO], int *contador, int (*roda)[3], int marcaTento[12][6], int *pontosEles, int *pontosNos, int marcadorRodadas[2][5]
)
{
	int i, j, escolhaJogador, botEles1,botEles2, botNos2, rodadaNos, rodadaEles, contadorRodadas;
	char opcao;
	opcao = '0';
	rodadaEles = 0;
	rodadaNos = 0;
	contadorRodadas = 1;
	while(opcao != 'e' || opcao != 'E') {
		botNos2 = 0;
		botEles1 = 0;
		/* encontrar  posição do incice*/
		for(i = 0; i < TAM; i+= 1) {
			for(j = 0; j < TAM; j += 1) {
				/*Vez do Jogador*/

				if(mesa[i][j] == 94) {
					printf("====================\n");
					printf("Digite A e D para andar para direita e esquerda\n");
					printf("E digite E para escolher a carta\n");
					scanf(" %c", &opcao);
					printf("====================\n");

					if(opcao == 'a' || opcao == 'A') {
						printf("\a");
						mesa[i][j] = 0;
						j -= 1;
						mesa[i][j] = seta;
						mostrarMesa(mesa, manilha, marcaTento);
					}
					else if(opcao == 'd' || opcao == 'D') {
						printf("\a");
						mesa[i][j] = 0;
						j += 1;
						mesa[i][j] = seta;
						mostrarMesa(mesa, manilha, marcaTento);
					}
					else if(opcao == 'e' || opcao == 'E') {
						printf("\a");
						if(i == 10 && j == 4) {
							mesa[6][5] = (*nos1)[0];
							(*nos1)[0] = 0;
							mesa[7][5] = (*nos1)[1];
							(*nos1)[1] = 0;
						}
						else if(i == 10 && j == 5) {
							mesa[6][5] = (*nos1)[2];
							(*nos1)[2] = 0;
							mesa[7][5] = (*nos1)[3];
							(*nos1)[3] = 0;
						}
						else if(i == 10 && j == 6) {
							mesa[6][5] = (*nos1)[4];
							(*nos1)[4] = 0;
							mesa[7][5] = (*nos1)[5];
							(*nos1)[5] = 0;
						}
						mostrarMesa(mesa, manilha, marcaTento);
						if(mesa[6][5] == manilha) {
							/* verifca a força da carta do jogador */
							if(mesa[6][5] == manilha && mesa[7][5] == 80) {
								escolhaJogador = 17;
							}
							else if(mesa[6][5] == manilha && mesa[7][5] == 67) {
								escolhaJogador = 16;
							}
							else if(mesa[6][5] == manilha && mesa[7][5] == 69) {
								escolhaJogador = 15;
							}
							else if(mesa[6][5] == manilha && mesa[7][5] == 79) {
								escolhaJogador = 14;
							}
						}
						else {
							if(mesa[6][5] == 1) {
								escolhaJogador = 11;
							}
							else if(mesa[6][5] == 2) {
								escolhaJogador = 12;
							}
							else if(mesa[6][5] == 3) {
								escolhaJogador = 13;
							}
							else if(mesa[6][5] == 4) {
								escolhaJogador = 4;
							}
							else if(mesa[6][5] == 5) {
								escolhaJogador = 5;
							}
							else if(mesa[6][5] == 6) {
								escolhaJogador = 6;
							}
							else if(mesa[6][5] == 7) {
								escolhaJogador = 7;
							}
							else if(mesa[6][5] == 8) {
								escolhaJogador = 8;
							}
							else if(mesa[6][5] == 9) {
								escolhaJogador = 9;
							}
							else if(mesa[6][5] == 10) {
								escolhaJogador = 10;
							}
						}
						mostrarMesa(mesa, manilha, marcaTento);

						goto saida;
					}
				}
			}
		}
	}
saida:
	for(i = 0; i < MAO; i += 2) {
		if((*eles2)[i] == manilha) {
			for(j = i + 1; j < MAO; j += 2) {
				if(j == 1 && (*eles2)[i] == manilha) {
					if((*eles2)[j] == 80) {
						(*eles2)[i] = 17;
						goto saida10Eles2;
					}
					else if((*eles2)[j] == 67) {
						(*eles2)[i] = 16;
						goto saida10Eles2;
					}
					else if((*eles2)[j] == 69) {
						(*eles2)[i] = 15;
						goto saida10Eles2;
					}
					else if((*eles2)[j] == 79 ) {
						(*eles2)[i] = 14;
						goto saida10Eles2;
					}
				}
				else if(j == 3 && (*eles2)[i] == manilha) {
					if((*eles2)[j] == 80) {
						(*eles2)[i] = 17;
						goto saida10Eles2;
					}
					else if((*eles2)[j] == 67) {
						(*eles2)[i] = 16;
						goto saida10Eles2;
					}
					else if((*eles2)[j] == 69) {
						(*eles2)[i] = 15;
						goto saida10Eles2;
					}
					else if((*eles2)[j] == 79 ) {
						(*eles2)[i] = 14;
						goto saida10Eles2;
					}
				}
				else if(j == 5 && (*eles2)[i] == manilha) {
					if((*eles2)[j] == 80) {
						(*eles2)[i] = 17;
						goto saida10Eles2;
					}
					else if((*eles2)[j] == 67) {
						(*eles2)[i] = 16;
						goto saida10Eles2;
					}
					else if((*eles2)[j] == 69) {
						(*eles2)[i] = 15;
						goto saida10Eles2;
					}
					else if((*eles2)[j] == 79 ) {
						(*eles2)[i] = 14;
						goto saida10Eles2;
					}
				}
			}
		}
		else {
			if((*eles2)[i] == 1) {
				(*eles2)[i] = 11;
			}
			else if((*eles2)[i] == 2) {
				(*eles2)[i] = 12;
			}
			else if((*eles2)[i] == 3) {
				(*eles2)[i] = 13;
			}
		}
saida10Eles2:
	}
	botEles2 = 0;
	/* bot eles2 esta escolhendo a carta */
	/* Se todas as cartas forem menores*/
	if((*eles2)[0] < escolhaJogador && (*eles2)[2] < escolhaJogador && (*eles2)[4] < escolhaJogador) {
		/* escolhe a menor carta */
		botEles2 = 17;
		for(i = 0; i <MAO; i += 2) {
			if((*eles2)[i] < botEles2 && (*eles2)[i] != 0)
				botEles2 = (*eles2)[i];

		}  /*encontrar a posição da carta escolhida*/
		for(i = 0; i < MAO; i += 2) {
			if((*eles2)[i] == botEles2)
				goto saida1BotEles2;
		}
saida1BotEles2:

		/*bot jogou a carta*/

		mesa[5][6] = (*eles2)[i];
		mesa[5][7] = (*eles2)[i + 1];
		(*eles2)[i] = 0;
		(*eles2)[i + 1] = 0;

		/*encontrar a posição da carta escolhida na mesa*/
		for(i = 4; i < 7; i += 1) {
			if(mesa[i][9] == botEles2)
				goto saida2BotEles2;
		}
saida2BotEles2:
		mesa[i][9] = 0;
		mesa[i][10] = 0;
	}
	/* se o bot tiver alguma carta maior que o adversario*/
	else if ((*eles2)[0] > escolhaJogador || (*eles2)[2] > escolhaJogador || (*eles2)[4] > escolhaJogador) {
	    			botEles2 =  0;
		for(i = 0; i < MAO; i += 2) {
			/* Caso a difença seja pequena*/
			if((*eles2)[i] - escolhaJogador <= 3 && (*eles2)[i] - escolhaJogador > 0)
				botEles2 = (*eles2)[i];
			/* Casa a diferença não seja pequana*/
			else if ((*eles2)[i] - escolhaJogador <= 5 && (*eles2)[i] - escolhaJogador > 0)
				botEles2 = (*eles2)[i];

			else if ((*eles2)[i] - escolhaJogador <= 7 && (*eles2)[i] - escolhaJogador > 0)
				botEles2 = (*eles2)[i];

			else if ((*eles2)[i] - escolhaJogador <= 10 && (*eles2)[i] - escolhaJogador > 0)
				botEles2 = (*eles2)[i];
		}
		for(i = 0; i < MAO; i += 2) {
			if((*eles2)[i] == botEles2) {
				goto saida3BotEles2;
			}
		}
saida3BotEles2:
		/*bot jogou a carta*/

		mesa[5][6] = (*eles2)[i];
		mesa[5][7] = (*eles2)[i + 1];
		(*eles2)[i] = 0;
		(*eles2)[i + 1] = 0;
		/*encontrar a posição da carta escolhida na mesa*/
		for(i = 4; i < 7; i += 1) {
			if(mesa[i][9] == botEles2)
				goto saida4BotEles2;
		}

saida4BotEles2:
		mesa[i][9] = 0;
		mesa[i][10] = 0;
	}
	/* verifica se bot nos2 tem manilha */
	for(i = 0; i < MAO; i += 2) {
		if((*nos2)[i] == manilha) {
			for(j = i + 1; j < MAO; j += 2) {
				if(j == 1) {
					if((*nos2)[j] == 80) {
						(*nos2)[i] = 17;
						goto saida10BotNos2;
					}
					else if((*nos2)[j] == 67) {
						(*nos2)[i] = 16;
						goto saida10BotNos2;
					}
					else if((*nos2)[j] == 69) {
						(*nos2)[i] = 15;
						goto saida10BotNos2;
					}
					else if((*nos2)[j] == 79) {
						(*nos2)[i] = 14;
						goto saida10BotNos2;
					}
				}
				if(j == 3) {
					if((*nos2)[j] == 80) {
						(*nos2)[i] = 17;
						goto saida10BotNos2;
					}
					else if((*nos2)[j] == 67) {
						(*nos2)[i] = 16;
						goto saida10BotNos2;
					}
					else if((*nos2)[j] == 69) {
						(*nos2)[i] = 15;
						goto saida10BotNos2;
					}
					else if((*nos2)[j] == 79) {
						(*nos2)[i] = 14;
						goto saida10BotNos2;
					}
				}
				else if(j == 5) {
					if((*nos2)[j] == 80) {
						(*nos2)[i] = 17;
						goto saida10BotNos2;
					}
					else if((*nos2)[j] == 67) {
						(*nos2)[i] = 16;
						goto saida10BotNos2;
					}
					else if((*nos2)[j] == 69) {
						(*nos2)[i] = 15;
						goto saida10BotNos2;
					}
					else if((*nos2)[j] == 79) {
						(*nos2)[i] = 14;
						goto saida10BotNos2;
					}
				}
			}
		}
		else {
			if((*nos2)[i] == 1) {
				(*nos2)[i] = 11;
			}
			else if((*nos2)[i] == 2) {
				(*nos2)[i] = 12;
			}
			else if((*nos2)[i] == 3) {
				(*nos2)[i] = 13;
			}
		}
saida10BotNos2:
	}
	/* bot nos2 esta escolhendo a carta */
	/* Se Parceiro estiver fazendo a rodada*/
	if(escolhaJogador > botEles2) {
		botNos2 = 17;
		/* escolhe o valor da menor carta */
		for(i = 0; i < MAO; i += 1) {
			if((*nos2)[i] < botNos2 && (*nos2)[i] != 0)
				botNos2 = (*nos2)[i];
		}
		/* encontra a carta*/
		for(i = 0; i < MAO; i += 2) {
			if(botNos2 == (*nos2)[i])
				goto saida1BotNos2;
		}
saida1BotNos2:

		/*bot jogou a carta*/

		mesa[4][5] = (*nos2)[i];
		mesa[3][5] = (*nos2)[i + 1];
		(*nos2)[i] = 0;
		(*nos2)[i + 1] = 0;

		/* procura a posição da carta escolhida na mesa*/
		for(i = 4; i < 7; i += 1) {
			if(mesa[1][i] == botNos2)
				goto saida2BotNos2;
		}
saida2BotNos2:
		/*apaga a carta na mesa*/
		mesa[1][i] = 0;
		mesa[0][i] = 0;
	}
	/* Se o adiversairo estiver fazendo a parrtida*/
	else if(botEles2 > escolhaJogador) {
		/*caso o bot nos2 tenha alguma carta mais forte*/
		if((*nos2)[0] > botEles2 || (*nos2)[2] > botEles2 || (*nos2)[4] > botEles2 ) {
			botNos2 = 0;
			/* procura a carta maior que botEles2*/
			for(i = 0; i <  MAO; i += 2) {
				if((*nos2)[i] > botNos2) {
					/*diferença de carta pequena */
					if((*nos2)[i] - botEles2 <= 3 && (*nos2)[i] - botEles2	> 0) {
						botNos2 = (*nos2)[i];
					}
					/*diferença de carta ggrande */
					else if((*nos2)[i] - botEles2 <= 5 && (*nos2)[i] - botEles2	> 0) {
						botNos2 = (*nos2)[i];
					}
					else if((*nos2)[i] - botEles2 <= 7 && (*nos2)[i] - botEles2	> 0) {
						botNos2 = (*nos2)[i];
					}
					else if((*nos2)[i] - botEles2 <= 10 && (*nos2)[i] - botEles2	> 0) {
						botNos2 = (*nos2)[i];
					}
				}
			}
			for(i = 0; i < MAO; i += 2) {
				if(botNos2 == (*nos2)[i])
					goto  saida3BotNos2;
			}
saida3BotNos2:
			/*bot jogou a carta*/

			mesa[4][5] = (*nos2)[i];
			mesa[3][5] = (*nos2)[i + 1];
			(*nos2)[i] = 0;
			(*nos2)[i + 1] = 0;

			for(i = 4; i < 7; i += 1) {
				if(mesa[1][i] == botNos2)
					goto saida4BotNos2;
			}
saida4BotNos2:
			mesa[1][i] = 0;
			mesa[0][i] = 0;
		}/* caso o bot nos2 nao tenha nenhuma carta maior que a escolha do jogador */
		else if((*nos2[0]) < botEles2 && (*nos2[2]) < botEles2 && (*nos2)[4] < botEles2) {
			botNos2 = 17;
			/*procura  menor carta */
			for(i = 0; i < MAO; i += 2) {
				if(botNos2 > (*nos2)[i] && (*eles1)[i] != 0) {
					botNos2 = (*nos2)[i];
				}
			}
			/* encotra a menor posição da carta */
			for(i = 0; i < MAO; i += 2) {
				if(botNos2 == (*nos2)[i]) {
					goto saida5BotNos2;
				}
			}
saida5BotNos2:
			/* coloca a carta escolhida na mesa */
			mesa[4][5] = (*nos2)[i];
			mesa[3][5] = (*nos2)[i + 1];
			(*nos2)[i] = 0;
			(*nos2)[i + 1] = 0;
			for(i = 4; i < 7; i += 1) {
				if(mesa[1][i] == botNos2) {
					goto saida6BotNos2;
				}
			}
saida6BotNos2:
			mesa[1][i] = 0;
			mesa[0][i] = 0;
		}
	}
	/*verefica se o bot eles1 tem manilha*/
	for(i = 0; i < MAO; i += 2) {
		if((*eles1)[i] == manilha) {
			for(j = 1; j < MAO; j += 2) {
				if((*eles1)[i] == 80) {
					(*eles1)[i] = 17;
				}
				else if((*eles1)[i] == 67) {
					(*eles1)[i] = 16;
				}
				else if((*eles1)[i] == 69) {
					(*eles1)[i] = 15;
				}
				else if((*eles1)[i] == 79 ) {
					(*eles1)[i] = 14;
				}
			}
		}
		else {
			if((*eles1)[i] == 1) {
				(*eles1)[i] = 11;
			}
			else if((*eles1)[i] == 2) {
				(*eles1)[i] = 12;
			}
			else if((*eles1)[i] == 3) {
				(*eles1)[i] = 13;
			}
		}
	}
	/* caso o adiversario estiver ganhado*/
	if(botEles2 < escolhaJogador || botEles2 < botNos2) {
		/* Se a escolha do jogador estiver fazendo a rodada*/
		if(escolhaJogador > botNos2) {
			/* caso o bot eles1 não tiver nenhuma carta maior*/
			if(escolhaJogador > (*eles1)[0] && escolhaJogador > (*eles1)[2] && escolhaJogador > (*eles1)[4]) {
				botEles1 = 17;
				for(i = 0; i < MAO; i += 2) {
					if((*eles1)[i] < botEles1 && (*eles1)[i] != 0)
						botEles1 = (*eles1)[i];
				}
				for(i = 0; i < MAO; i += 2) {
					if((*eles1)[i] == botEles1) {
						goto saida1BotEles1;
					}
				}
saida1BotEles1:
				/*bot jogou a carta*/
				mesa[5][4] = (*eles1)[i];
				mesa[5][3] = (*eles1)[i + 1];
				(*eles1)[i] = 0;
				(*eles1)[i + 1] = 0;

				for(i = 4; i < 7; i += 1) {
					if(mesa[i][1] == botEles1) {
						goto saida2BotEles1;
					}
				}
saida2BotEles1:
				mesa[i][1] = 0;
				mesa[i][0] = 0;
			}
			/*Caso o eles1 tenha alguma carta maior*/
			else if((*eles1)[0] >= escolhaJogador || (*eles1)[2] >= escolhaJogador || (*eles1)[4] >= escolhaJogador) {
				botEles1 = 0;
				for(i = 0; i < MAO; i += 2) {
					if((*eles1)[i] - escolhaJogador <= 3 && (*eles1)[i] - escolhaJogador > 0) {
						botEles1 = (*eles1)[i];
					}
					else if((*eles1)[i] - escolhaJogador <= 5 && (*eles1)[i] - escolhaJogador > 0) {
						botEles1 = (*eles1)[i];
					}
				}
				for(i = 0; i < MAO; i += 2) {
					if((*eles1)[i] == botEles1) {
						goto  saida3BotEles1;
					}
				}
saida3BotEles1:
				mesa[5][4] = (*eles1)[i];
				mesa[5][3] = (*eles1)[i + 1];
				(*eles1)[i] = 0;
				(*eles1)[i] = 0;
				for(i = 4; i < 7; i+= 1) {
					if(mesa[i][1] == botEles1) {
						goto saida4BotEles1;
					}
				}
saida4BotEles1:
				mesa[i][1] = 0;
				mesa[i][0] = 0;

			}
			/*caso a escolha do bot nos2 estiver fazendo a rodada*/
		}
		else if(botNos2 > escolhaJogador) {
			/* caso o bot eles1 não tiver nenhuma carta maior*/
			if((*eles1)[0] < botNos2 && (*eles1)[2] < botNos2 && (*eles1)[4] < botNos2) {
				botEles1 = 17;
				for(i = 0; i < MAO; i += 2) {
					if((*eles1)[i] < botEles1 && (*eles1)[i] != 0) {
						botEles1 = (*eles1)[i];
					}
				}
				for(i = 0; i < MAO; i += 2) {
					if(botEles1 == (*eles1)[i]) {
						goto saida5BotEles1;
					}
				}
saida5BotEles1:
				mesa[5][4] = (*eles1)[i];
				mesa[5][3] = (*eles1)[ i + 1];
				(*eles1)[i] = 0;
				(*eles1)[i + 1] = 0;

				for(i = 4; i < 7; i += 1) {
					if(mesa[i][1] == botEles1) {
						goto saida6BotEles1;
					}
saida6BotEles1:
					mesa[i][1] = 0;
					mesa[i][0] = 0;
				}
				/* Caso tenha uma carta maior que Nos2*/
				if((*eles1)[0] >= botNos2 || (*eles1)[2] >= botNos2 || (*eles1)[4] >= botNos2) {
					for(i = 0; i < MAO; i += 2) {
						if((*eles1)[i] - botNos2 <= 3 && (*eles1)[i] - botNos2 > 0)
							botEles1 = (*eles1)[i];
						else if((*eles1)[i] - botNos2 <= 5 && (*eles1)[i] - botNos2 > 0)
							botEles1 = (*eles1)[i];
					}
				}
				/*encotrar a posição da carta no tabuleiro*/
				for(i = 0; i < MAO; i += 1) {
					if(botEles1 == (*eles1)[i]) {
						goto saida7BotEles1;
					}
				}
saida7BotEles1:
				mesa[5][4] = (*eles1)[i];
				mesa[5][3] = (*eles1)[i + 1];
				(*eles1)[i] = 0;
				(*eles1)[i + 1] = 0;

				for(i = 4; i < 7; i += 1) {
					if(mesa[1][i] == botEles1)
						goto saida8BotEles1;
				}
saida8BotEles1:
				mesa[1][i] = 0;
				mesa[0][i] = 0;
			}
		}
	}
	/*Caso o time do bot eles1 esteja vencendo a rodada*/
	else if(botEles2 > escolhaJogador && botEles2 > botNos2) {
		botEles1 = 17;
		for(i = 0; i < MAO; i += 2) {
			if((*eles1)[i] < botEles1 && (*eles1)[i] != 0) {
				botEles1 = (*eles1)[i];
			}
		}
		for(i = 0; i < MAO; i += 2) {
			if((*eles1)[i] == botEles1) {
				goto saida9BotEles1;
			}
		}
saida9BotEles1:
		mesa[5][4] = (*eles1)[i];
		mesa[5][3] = (*eles1)[i + 1];
		(*eles1)[i] = 0;
		(*eles1)[i + 1] = 0;


		for(i = 4; i < 7; i += 1) {
			if(mesa[i][1] == botEles1) {
				goto saida10BotEles1;
			}
		}
saida10BotEles1:
		mesa[i][1] = 0;
		mesa[i][0] = 0;
	}
/* autaliza o mostrador de rodada*/
	if(botEles1 > escolhaJogador && botEles1 > botNos2) {
		(*roda)[*contador] = 1;
		if(contadorRodadas == 1){ 
		    marcadorRodadas[1][0] = 3;
		}
		else if(contadorRodadas == 2){
		    marcadorRodadas[1][2] = 3;
		}
		else if(contadorRodadas == 3){ 
		    marcadorRodadas[1][4] = 3;
		}
	}
	else if(botEles2 > escolhaJogador && botEles2 > botNos2) {
		(*roda)[*contador] = 1;
		if(contadorRodadas == 1){ 
		    marcadorRodadas[1][0] = 3;
		}
		else if(contadorRodadas == 2){
		    marcadorRodadas[1][2] = 3;
		}
		else if(contadorRodadas == 3){ 
		    marcadorRodadas[1][4] = 3;
		}
	}
	else if(escolhaJogador > botEles1 && escolhaJogador > botEles2) {
		(*roda)[*contador] = 2;
		if(contadorRodadas == 1){ 
		    marcadorRodadas[1][0] = 2;
		}
		else if(contadorRodadas == 2){
		    marcadorRodadas[1][2] = 2;
		}
		else if(contadorRodadas == 3){ 
		    marcadorRodadas[1][4] = 2;
		}
	}
	else if(botNos2 > botEles1 && botNos2> botEles2) {
		(*roda)[*contador] = 2;
		if(contadorRodadas == 1){ 
		    marcadorRodadas[1][0] = 2;
		}
		else if(contadorRodadas == 2){
		    marcadorRodadas[1][2] = 2;
		}
		else if(contadorRodadas == 3){ 
		    marcadorRodadas[1][4] = 2;
		}
	}
	mostrarRodada(marcadorRodadas);

    for(i = 0; i < 3; i += 1){ 
        if((*roda)[i] == 1){ 
            rodadaEles += 1;
        }
        else if((*roda)[i] == 2){ 
            rodadaNos += 1;
        }
    }
    
    if(rodadaEles == 2){
        *pontosEles += 1;
        *contador = 3;
    }
	if(rodadaNos == 2){
		*pontosNos += 1;
		*contador = 3;
	}
    contadorRodadas += 1;
	*contador += 1;

}
int main()
{	int mesa[TAM][TAM];
	int marcaTento[12][6];
	int marcadorRodadas[2][5];
	int eles1[MAO];
	int eles2[MAO];
	int nos1[MAO];
	int nos2[MAO];
	int naipes[4] = {80, 67, 69, 79}; //  Paus, Copas, Espadas, Ouro
	int roda[3] = {0, 0, 0};
	srand(time(NULL));
	int naipe, i, j, manilha, seta, pontosNos, pontosEles, contador;
	seta = 94;
	pontosEles = 0;
	pontosNos = 0;

	/* prepara a mesa para a partida*/
	preparaMesa(mesa, marcaTento, marcadorRodadas);
	mesa[10][5] = seta;


	while(pontosNos < 12 && pontosEles < 12) {
		/*escolhe manilha */
		manilha = (rand() % 10) + 1;
		if(manilha == 11) {
			manilha = 1;
		}
		mesa[5][5] = manilha;
		manilha += 1;
		/*Distribui as cartas para os jogadores e verifica se não a cartas repetidas*/
		distribuirCartas(eles1, eles2, nos1, nos2, naipes);
		contador = 0;
		for(i = 0; i < 3; i += 1) {
			roda[i] = 0;
		}
		for(i = 0; i < 5; i += 2){
    		marcadorRodadas[1][i]= 0;
		}
		while(contador < 3) {

			/*Distribui as cartas as mesa*/
			posicionaCartas(mesa, &eles1, &eles2, &nos1, &nos2);

			/*mostra as cartas na mesa e Partida começa*/
			mostrarMesa(mesa, manilha, marcaTento);

			partida(mesa, seta,  &nos1, manilha, &eles2, &eles1, &nos2, &contador, &roda, marcaTento, &pontosEles, &pontosNos, marcadorRodadas);
		
		}

		marcarPontos(pontosEles, pontosNos, marcaTento);
		
        mostrarRodada(marcadorRodadas);

	}
	return 0;
}
