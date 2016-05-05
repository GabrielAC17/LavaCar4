#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define sprio 7
typedef int bool;
#define true 1
#define false 0

typedef struct {
	char nome[50];
	char telefone[20];
	char placa[12];
	unsigned int tipo;
	int prioridade;
	bool impresso;
	unsigned int id;
	bool ativo;
	/*
	Significado da posição na variável de serviços (a verificar):
	posição 0:
	0 - Lavagem Completa
	1 - Lavagem Ecológica


	1 - Aspirador
	0 para não e 1 para sim
	*/
	int servicos[2];
}carros;

carros cars[50];
void menu1(),cadastro(),delCadastros(),prioridades(),printCadastro(int posi), eatExtraInput();
int pos = 0,i;

time_t now;
struct tm *now_tm;
int hour;

int main(){
	system("clear");
	printf("Bem vindo ao Lava Car Tabajara!\n\n\n");
	sleep(2);
	menu1();
}

void menu1(){
	int opcaoSel1;
	do{
		system("clear");
		now = time(NULL);
		now_tm = localtime(&now);
		hour = now_tm->tm_hour;

		printf("Menu Principal:\n1 - Cadastrar clientes\n2 - Deletar clientes cadastrados\n3 - Ordenar/listar prioridades e servicos contratados\n4 - Sair\n");
		setbuf(stdin, NULL);
		scanf(" %d",&opcaoSel1);
		if (opcaoSel1 == 1){
			if (hour < 12 && pos <50)
				cadastro();
			else if (hour >= 12){
				printf("Nao e possível cadastrar mais clientes pois passou do meio dia.\n\n");
				printf("\nPressione qualquer tecla para continuar.\n");
				getchar();
				getchar();
				continue;
			}
			else if (pos >= 50){
				printf("Sobrecarga do sistema, voce precisa de tantos clientes assim?\n\n");
				printf("\nPressione qualquer tecla para continuar.\n");
				getchar();
				getchar();
				continue;
			}
		}
		else if (opcaoSel1 == 2){
			delCadastros();
		}
		else if (opcaoSel1 == 3){
			prioridades();
		}
		else if (opcaoSel1 == 4){
			exit(0);
		}
	}while (opcaoSel1 != 1 ||opcaoSel1 != 2 || opcaoSel1 != 3 || opcaoSel1 != 4);
}

void cadastro(){
	int repeat;
	do{		
		system("clear");
		printf("Digite o nome do cliente:\n");
		setbuf(stdin, NULL);
		fgets(cars[pos].nome,50,stdin);
		cars[pos].nome[strlen(cars[pos].nome)-1] = '\0';
		eatExtraInput();
		//scanf("%s", &cars[pos].nome);
		
		system("clear");
		printf("Digite o telefone do cliente:\n");
		setbuf(stdin, NULL);
		fgets(cars[pos].telefone,20,stdin);
		cars[pos].telefone[strlen(cars[pos].telefone)-1] = '\0';
		eatExtraInput();
		//scanf("%s", &cars[pos].telefone);
	
		system("clear");
		printf("Digite a placa do veiculo:\n");
		setbuf(stdin, NULL);
		fgets(cars[pos].placa,12,stdin);
		cars[pos].placa[strlen(cars[pos].placa)-1] = '\0';
		eatExtraInput();
		//scanf("%s", &cars[pos].placa);
		do{
			system("clear");
			printf("Escolha o tipo do carro do cliente:\n\n");
			printf("1 - Carro Hatch \n2 - Carro Sedan \n3 - Moto \n4 - Van\n");
			setbuf(stdin, NULL);
			scanf(" %d",&cars[pos].tipo);
			if (cars[pos].tipo == 1 ||cars[pos].tipo == 2 || cars[pos].tipo == 3 || cars[pos].tipo == 4){
				break;
			}
		}while (1);
		
		do{
			system("clear");
			printf("Escolha o tipo de lavagem:\n\n");
			printf("1 - Lavagem Completa \n2 - Lavagem Ecologica\n");
			setbuf(stdin, NULL);
			scanf(" %d",&cars[pos].servicos[0]);
			if (cars[pos].servicos[0] == 1 ||cars[pos].servicos[0] == 2){
				break;
			}
		}while (1);

		do{
			system("clear");
			printf("Deseja aspirador?:\n\n");
			printf("0 - Não\n1 - Sim\n");
			setbuf(stdin, NULL);
			scanf(" %d",&cars[pos].servicos[1]);
			if (cars[pos].servicos[1] == 0 ||cars[pos].servicos[1] == 1){
				break;
			}
		}while (1);

		do{
			system("clear");
			printf("Cliente Cadastrado! Deseja cadastrar mais um?:\n\n");
			printf("0 - Não\n1 - Sim\n");
			setbuf(stdin, NULL);
			scanf(" %d",&repeat);
			if (repeat == 0 ||repeat == 1){
				break;
			}
		}while (1);

		cars[pos].prioridade = sprio;
		if (cars[pos].servicos[0] == 1)	cars[pos].prioridade -= 2;
		if (cars[pos].servicos[0] == 2)	cars[pos].prioridade += 1;
		if (cars[pos].servicos[1] == 1)	cars[pos].prioridade -= 1;
		if (cars[pos].tipo == 1)	cars[pos].prioridade -= 1;
		if (cars[pos].tipo == 2)	cars[pos].prioridade -= 2;
		if (cars[pos].tipo == 3)	cars[pos].prioridade += 1;
		if (cars[pos].tipo == 4)	cars[pos].prioridade -= 4;
		cars[pos].impresso = false;
		cars[pos].ativo = true;
		cars[pos].id = pos;
		pos++;
	}while (repeat != 0);
	
}

void delCadastros(){
	unsigned int searchid;
	if (pos == 0){
		printf("Nenhum cliente cadastrado.\n");
		printf("\nPressione qualquer tecla para continuar.\n");
		getchar();
		getchar();
		return;
	}
	do{
		system("clear");
		printf("Digite o id do cliente do qual deseja excluir:\n");
		printf("ID's não cadastrados ainda são considerados inválidos.\n");
		setbuf(stdin, NULL);
		scanf(" %d",&searchid);
		printf("\n");
		if (searchid >= 0 && searchid < pos){
			break;
		}
		else {
			printf("Valor inválido.\n\n");
			printf("\nPressione qualquer tecla para continuar.\n");
			getchar();
			getchar();
			return;
		}
	}while (1);
	cars[searchid].ativo = false;
	printf("\nCliente ID %d excluído.\n", searchid);
	printf("\nPressione qualquer tecla para continuar.\n");
	getchar();
	getchar();
}

void prioridades(){
	unsigned int listo;
	int ma, posma;
	bool noPrioLeft = true,startFlag = false;

	system("clear");
	if (pos == 0){
		printf("Nenhum cliente cadastrado.\n");
		printf("\nPressione qualquer tecla para continuar.\n");
		getchar();
		getchar();
	}
	else{
		do{
			printf("Deseja listar por maior ou menor prioridade?\n\n");
			printf("1 - Maior\n2 - Menor\n");
			setbuf(stdin, NULL);
			scanf(" %d",&listo);
			printf("\n");
			if (listo == 1 ||listo == 2){
				break;
			}
		}while (1);

		if (listo == 1){
			do{
				noPrioLeft = true;
				startFlag = false;
				for (i=0;i<pos;i++){
					if (cars[i].impresso == false && startFlag == false){
						ma = cars[i].prioridade;
						posma = i;
						startFlag = true;
					}
					if (cars[i].prioridade > ma && cars[i].impresso == false){
						ma = cars[i].prioridade;
						posma = i;
					}
				}
				if (cars[posma].ativo == true)
					printCadastro(posma);
				cars[posma].impresso = true;
				for (i=0;i<pos;i++){
					if (cars[i].impresso == false){
						noPrioLeft = false;
					}
				}
			}while (noPrioLeft == false);
		}

		else if (listo == 2){
			do{
				noPrioLeft = true;
				startFlag = false;
				for (i=0;i<pos;i++){
					if (cars[i].impresso == false && startFlag == false){
						ma = cars[i].prioridade;
						posma = i;
						startFlag = true;
					}
					if (cars[i].prioridade < ma && cars[i].impresso == false){
						ma = cars[i].prioridade;
						posma = i;
					}
				}
				if (cars[posma].ativo == true)
					printCadastro(posma);
				cars[posma].impresso = true;
				for (i=0;i<pos;i++){
					if (cars[i].impresso == false){
						noPrioLeft = false;
					}
				}
			}while (noPrioLeft == false);
		}

		for (i=0;i<pos;i++){
			cars[i].impresso = false;
		}

		printf("\nPressione qualquer tecla para continuar.\n");
		getchar();
		getchar();
		//getchar();

		/*for (i=0;i<pos;i++){
			printCadastro(i);
		}
		*/
	} 
}

void printCadastro(int posi){
	printf("ID %d - Nome: %s\n", cars[posi].id, cars[posi].nome);
	printf("Telefone: %s\n", cars[posi].telefone);
	printf("Placa: %s\n", cars[posi].placa);
	switch (cars[posi].tipo){
		case 1:
			printf("Carro hatch.\n");
			break;
		case 2:
			printf("Carro sedan.\n");
			break;
		case 3:
			printf("Moto.\n");
			break;
		case 4:
			printf("Van.\n");
			break;
		default:
			printf("Erro ao ler o tipo de veículo.\n");
			break;
	}
	switch (cars[posi].servicos[0]){
		case 1:
			printf("Lavagem completa.\n");
			break;
		case 2:
			printf("Lavagem Ecologica.\n");
			break;
		default:
			printf("Erro ao ler o tipo de Lavagem.\n");
			break;
	}
		switch (cars[posi].servicos[1]){
		case 0:
			printf("Sem aspirador.\n");
			break;
		case 1:
			printf("Com aspirador.\n");
			break;
		default:
			printf("Erro ao ler o tipo de aspirador.\n");
			break;
	}
	printf("Prioridade = %d", cars[posi].prioridade);
	printf("\n\n");
}

void eatExtraInput()
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF){
		if (ch < 0)
			exit(EXIT_FAILURE);
	}
}
