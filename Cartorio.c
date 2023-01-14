#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o responsavel por cadastrar os usuarios no sistema
{
	// inicio cria��o de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: ");// coletando informa��o do usuario
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file= fopen(arquivo,"w"); //abre o arquivo e o w significa escrever
	fprintf(file,cpf);// salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, ",");// salva o valor
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");// coletando informa��o do usuario
	scanf("%s", nome);// %s refere-se a string
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, nome);// salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, ",");// salva o valor
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");// coletando informa��o do usuario
	scanf("%s", sobrenome);// %s refere-se a string
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, sobrenome);// salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, ",");// salva o valor
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");// coletando informa��o do usuario
	scanf("%s", cargo);// %s refere-se a string
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, cargo);// salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, ",");// salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	system("pause");//responsavel por dar uma pausa na execu��o
}

int consulta()// Fun��o responsavel por consultar os usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem
	// inicio cria��o de variaveis
	char cpf[40];
	char conteudo[200];
	// fim cria��o de variaveis
	
	printf("Digite o cpf a ser consultado: ");// coletando informa��o do usuario
	scanf("%s", cpf);// %s refere-se a string
	
	FILE *file;//cria o arquivo
	file= fopen(cpf,"r");//abre o arquivo e o r significa ler
	
	if(file == NULL)//verica��o de existencia de usuario
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//retorna os usuario cadastrados
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	 
	 system("pause");//responsavel por dar uma pausa na execu��o
}

int deletar()// Fun��o responsavel por deletar os usuarios no sistema
{
	char cpf[40];//cria��o de variavel
	
	printf("Digite o cpf a ser deletado: ");// coletando informa��o do usuario
	scanf("%s", cpf);// %s refere-se a string
	
	remove(cpf);//responsavel por deletar o usuario
	
	FILE *file;//cria o arquivo
	file= fopen(cpf,"r");//abre o arquivo e o r significa ler
	
	if(file == NULL)//verica��o de existencia de usuario
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	// inicio cria��o das vari�veis
	int opcao=0; 
	int laco=1;
	// fim cria��o das vari�veis
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem
		
		printf("### Cart�rio da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
		
		system("cls"); //responsavel limpar tela
		
		//sele��o com switch case
		switch(opcao)
		{
			case 1:
				registro();
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
			break;
		}
		
		//sele��o com if
		/*
		if(opcao==1) // inicio da sele��o
		{
			printf("Voc� escolheu o registro de nomes!\n");
			system("pause");
		}
		if(opcao==2)
		{
			printf("Voc� escolheu consultar os nomes!\n");
		}
		if(opcao==3)
		{
			printf("Voc� escolheu deletar nomes!\n");
		}
		if(opcao>=4||opcao<=0)
		{
			printf("Essa op��o n�o est� dispon�vel\n");
		} //fim da sele��o
		*/
	}
	
}
