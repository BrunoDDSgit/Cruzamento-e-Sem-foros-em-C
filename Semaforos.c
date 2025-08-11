#include <stdio.h>
#include <unistd.h> // sleep
#include <stdlib.h> // geração aleatoria rand()
#include <time.h> // geração aleatório da árvore por execução


int main() {
	int p = 100, numeroAleatorio, i=0, c, jo;
	char pista[3] = {'P','S','C'};
	int segundos[4] = {0, 0, 0, 0};
	int fluxo[4] = {0, 0, 0, 0};
	srand((unsigned)time(NULL)); 
	

	//Função numero aleatório
	int FuncaoNumeroAleatorio(int n) {
		return rand() % n;
	}

	//Função de fluxo 1 - Carros (fluxo alto)
	void FluxoC_A() {
		numeroAleatorio = 1 + FuncaoNumeroAleatorio(p);
		if (numeroAleatorio <= 50) {
			fluxo[0]++;
		}
	}


	//Função de fluxo 2 - Carros ( fluxo medio 30% )
	void FluxoC_M() {
		numeroAleatorio = 1 + FuncaoNumeroAleatorio(p);
		if (numeroAleatorio <= 30) {
			fluxo[1]++;
		}
	}

	//Função de fluxo - Pedestres ( menor fluxo C 15% )
	void FluxoC_Min() {
		numeroAleatorio = 1 + FuncaoNumeroAleatorio(p);
		if (numeroAleatorio <= 15) {
			fluxo[2]++;
		}
	}

	//Função de fluxo - Pedestres ( menor fluxo 5% )
	void FluxoP() {
		numeroAleatorio = 1 + FuncaoNumeroAleatorio(p);
		if (numeroAleatorio <= 20) {
			fluxo[3]++;
		}
	}

	void Atencao(int c) {
		segundos[0] = 4;
		printf("\n--------------------------------\n");
		if (c==0 || c ==1 || c==2) {
			printf("\nSemaforo %c: Amarelo\n", pista[jo]);
			while(segundos[0] >= 1){
				sleep(0);
				printf("\nSegundos restantes %i", segundos[0]);
				segundos[0]--;
			}
		}
		printf("\n--------------------------------\n");
	}

	void Delay(int c) {
		segundos[1] = 4;
		printf("\n-------------------------------\n");
		if(c==0 || c ==1 || c==2){
			printf("\nSemaforo %c: Vermelho(Delay)\n", pista[jo]);
			while(segundos[1] >= 1){
				sleep(0);
				printf("\nSegundos restantes %i", segundos[1]);
				segundos[1]--;
			}
		}

		printf("\n-------------------------------\n");
	}

	//Semaforo Fechado 1
	void Fechado(int c) { 
		segundos[2] = 26;
		printf("\n-------------------------------\n");
		if(c==0 || c ==1 || c==2) {
			printf("\nSemaforo %c: Vermelho\n", pista[jo]);
			while (segundos[2] > 0) {
				sleep(0);
				printf("\nSegundos restantes:%i", segundos[2]);
				segundos[2]--;
			}
		}

		printf("\n-------------------------------\n");
	}

	//Semaforo Fechado2
	void Fechado2(int c) { 
		segundos[2] = 26;
		printf("\n-------------------------------\n");
		if(c==0 || c ==1 || c==2) {
			printf("\nSemaforo %c: Vermelho\n", pista[jo]);
				while (segundos[2] > 0) {
				sleep(0);
				printf("\nSegundos restantes:%i", segundos[2]);
				segundos[2]--;
			}
		}
		printf("\n-------------------------------\n");
	}

	//Semaforo Aberto
	void Aberto(int c) {
		fluxo[jo] = 0;
		segundos[3] = 30;
		printf("\n-------------------------------\n");
		if(c==0 || c ==1 || c==2) {
			printf("Semaforo %c: Verde\n", pista[jo]);
			while(segundos[3] > 0) {
				sleep(0);
				if(pista[c]=='P'){
					FluxoC_A();
				}
				else if(pista[c]=='S'){
					FluxoC_M();
				}
				else if(pista[c]=='C'){
					FluxoC_Min();
				}
			printf("\nSegundos restantes %i | Contagem de Carros: %i", segundos[3], fluxo[jo]);
			segundos[3]--;
			}
		}
		printf("\n-------------------------------\n");
	}

	void Semaforo() {
		printf("\nCiclo de 90s Iniciado\n");
		printf("--------------------------\n");
		for(int j=0; j < 3; j++) {
			if (j==0){
			jo = j;
				Aberto(j);
				Atencao(j);
				Fechado(j);
				Fechado2(j);
				Delay(j);
			}
			else if (j==1){
			jo = j;
				Fechado(j);
				Delay(j);
				Aberto(j);
				Atencao(j);
				Fechado(j);
			}
			else if (j==2){
			jo = j;
				Fechado(j);
				Fechado2(j);
				Delay(j);
				Aberto(j);
				Atencao(j);
			}
		} 
		printf("\n--------------------------");
		printf("\nCiclo de 90s Completado\n");	
	}
	Semaforo();
}
