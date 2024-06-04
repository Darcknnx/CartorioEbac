#include <stdio.h> //biblioteca de comunica��o com usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar dos string

int registro() //Fun�ao responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever, ou seja ele vai escrever o que foi digitado pelo usuario
	
	fprintf(file,cpf); // Salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL)
	{
		printf("N�o foi possivel abrir o arquivo , n�o localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
		fclose(file);
		
	
	}	
		system("pause");
	
	
}

int deletar()
{
		char cpf[40];
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usuario n�o se encontra no sistema!.\n");
			system("pause");
		}
		
}
				
int main()
{
	int opcao=0; //Definindo as variaveis
	int x=1;
	
	for(x=1;x=1;) //La�o de repetica��o
	{
		system("cls");

    	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem
	    
    
	    printf("\t\t ### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	    printf("\tEscolha a op��o desejada do menu\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); //Fim do menu
	    printf("Op��o:"); //armazenando a escolha do usuario. 
	    
	    scanf("%d", &opcao); //Armazenando a escolha do usuario
	    
	    system("cls");// responsavel por limpar a tela
	    
	    switch(opcao) //op��o que substitui o if para menus, lembrar de colocar os dois pontos no final e o break para parar
	    {
	    	case 1:
	    	registro(); //chamada de fun��es
	    	break;
	    	
	    	case 2:
	    	consulta();
			break;
			
			case 3:
			deletar();		
			break;
				
			default:
			printf("Essa op��o n�o est� disponivel\n");
			system("pause");
			break;	
		}
	    
	   
	} // Fim do La�o
}    
