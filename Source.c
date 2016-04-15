#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[30];
	char telefone[15];
	char placa[7];
	unsigned int tipo;
	int prioridade;
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
void menu1(),cadastro(),delCadastros(),prioridades();
int pos = 0,i;

int main(){
	printf("Bem vindo ao Lava Car Tabajara!\n\n\n");
	menu1();
}

void menu1(){
	int opcaoSel1;
	do{
		printf("Menu 1:\n1 - Cadastrar clientes\n2 - Deletar clientes cadastrados\n3 - Ordenar e listar prioridades\n4 - Sair\n");
		scanf("%d",&opcaoSel1);
		if (opcaoSel1 == 1){
			cadastro();
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
		fflush(stdin);
		getchar();
		fgets(cars[pos].nome,30,stdin);
		//scanf("%s", &cars[pos].nome);
		
		system("clear");
		printf("Digite o telefone do cliente:\n");
		fflush(stdin);
		getchar();
		fgets(cars[pos].telefone,15,stdin);
		//scanf("%s", &cars[pos].telefone);
	
		system("clear");
		printf("Digite a placa do veiculo:\n");
		fflush(stdin);
		getchar();
		fgets(cars[pos].placa,7,stdin);
		//scanf("%s", &cars[pos].placa);
		
		fflush(stdin);
		getchar();
		do{
			system("clear");
			printf("Escolha o tipo do carro do cliente:\n\n");
			printf("1 - Carro Hatch \n2 - Carro Sedan \n 3 - Moto \n 4 - Van\n");
			scanf("%d",&cars[pos].tipo);
		}while (cars[pos].tipo != 1 ||cars[pos].tipo != 2 || cars[pos].tipo != 3 || cars[pos].tipo != 4);
		
		do{
			system("clear");
			printf("Escolha o tipo de lavagem:\n\n");
			printf("1 - Lavagem Completa \n2 - Lavagem Ecologica\n");
			scanf("%d",&cars[pos].servicos[0]);
		}while (cars[pos].servicos[0] != 1 ||cars[pos].servicos[0] != 2);

		do{
			system("clear");
			printf("Deseja aspirador?:\n\n");
			printf("0 - Não\n1 - Sim\n");
			scanf("%d",&cars[pos].servicos[1]);
		}while (cars[pos].servicos[1] != 0 ||cars[pos].servicos[1] != 1);

		do{
			system("clear");
			printf("Cliente Cadastrado! Deseja cadastrar mais um?:\n\n");
			printf("0 - Não\n1 - Sim\n");
			scanf("%d",&repeat);
		}while (repeat != 0 ||repeat != 1);

	}while (repeat != 0);
	pos++;
}

void delCadastros(){
	
}

void prioridades(){
	system("clear");
	if (pos == 0){
		printf("Nenhum cliente cadastrado.\n");
	}
	else{
		for (i=0;i<pos-1;i++){
			printf("Nome: %s", cars[i].nome);
			printf("Telefone: %s", cars[i].telefone);
			printf("Placa: %s", cars[i].placa);
			switch (cars[i].tipo){
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
			switch (cars[i].servicos[0]){
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

			switch (cars[i].servicos[1]){
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
			printf("\n\n");
		}
		system("read -rsp $'Pressione Enter para continuar...\n'");
	} 
	
	
}
