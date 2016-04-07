#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[30];
	unsigned int telefone;
	char placa[7];
	unsigned int tipo;
	int prioridade;
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
	
}

void lerCadastros(){
	
}

void prioridades(){
	
}
