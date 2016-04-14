#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[30];
	unsigned int telefone;
	char placa[7];
	unsigned int tipo;
	int prioridade;
	int carroHatch;
	int carroSedan;
	int moto;
	int van;
	/*
	Significado da posição na variável de serviços (a verificar):
	0 - Lavagem Completa
	1 - Lavagem Ecológica
	2 - Aspirador
	3 - ?
	4 - ?
	
	0 para não e 1 para sim
	*/
	int servicos[5];
	int lavagemEco;
	int lavagemComp;
	int aspirador;
	
}carros;

carros cars[50];
void menu1(),cadastro(),lerCadastros(),prioridades();

int main(){
	printf("Bem vindo ao Lava Car Tabajara!\n\n\n");
	menu1();
}

void menu1(){
	int opcaoSel1;
	do{
		printf("Menu 1:\n1 - Cadastrar clientes\n2 - Verificar clientes cadastrados\n3 - Ordenar prioridades\n4 - Sair\n");
		scanf("%d",&opcaoSel1);
		if (opcaoSel1 == 1){
			cadastro();
		}
		else if (opcaoSel1 == 2){
			lerCadastros();
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

		printf("Cadastro de clientes.\n");
		printf("Informe completo do cliente:\n");
		scanf("%c",&nome);
		printf("Informe o telefone do cliente:");
		scanf("%d",&telefone);
		printf("Informe a placa do veiculo:");
		scanf("%c",&placa);
			do{
				printf("Escolha o tipo do carro do cliente:");
				printf("1 -> Carro Hatch \n2 2 -> Carro Sedan \n 3 -> Moto \n 4 -> Van");
				scanf("%d",&tipo);
				if (tipo == 1){
					carroHatch;
				}
				else if (tipo == 2){
					carroSedan;
				}
				else if (tipo == 3){
					moto;
				}
				else if (tipo == 4){
					van;
				}
				else if (tipo == 5){
					exit(0);
				}
			}while (tipo != 1 ||tipo != 2 || tipo != 3 || tipo != 4 || tipo != 5);
}
		
		/*printf("Qual é a prioridade do veiculo?"); - Definir o calculo da prioridade e colocar no menu!
		scanf("%c",prioridade); */

			do{
				printf("Escolha quais os serviços vão ser realizados no veliculo:");
				printf("1 -> lavagem Ecológica \n2 2 -> Lavagem Completa \n 3 -> Aspirador \n");
				scanf("%d",&servicos);
				if (tipo == 1){
					lavagemEco;
				}
				else if (servicos == 2){
					lavagemComp;
				}
				else if (servicos == 3){
					aspirador;
				}
				else if (servicos == 4){
					exit;
								}
			}while (tipo != 1 ||tipo != 2 || tipo != 3 || tipo != 4);
		

		
			
}

void lerCadastros(){
	
}

void prioridades(){
	
}


























