#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsavel por cadastrar os usuarios no sistema
{
	// inicio criação de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: ");// coletando informação do usuario
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file= fopen(arquivo,"w"); //abre o arquivo e o w significa escrever
	fprintf(file,cpf);// salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, ",");// salva o valor
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");// coletando informação do usuario
	scanf("%s", nome);// %s refere-se a string
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, nome);// salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, ",");// salva o valor
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");// coletando informação do usuario
	scanf("%s", sobrenome);// %s refere-se a string
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, sobrenome);// salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, ",");// salva o valor
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");// coletando informação do usuario
	scanf("%s", cargo);// %s refere-se a string
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, cargo);// salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file= fopen(arquivo, "a");//abre o arquivo e o a significa atualizar
	fprintf(file, ",");// salva o valor da variável
	fclose(file);//fecha o arquivo
	
	system("pause");//responsavel por dar uma pausa na execução
}

int consulta()// Função responsavel por consultar os usuarios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem
	// inicio criação de variaveis
	char cpf[40];
	char conteudo[200];
	// fim criação de variaveis
	
	printf("Digite o cpf a ser consultado: ");// coletando informação do usuario
	scanf("%s", cpf);// %s refere-se a string
	
	FILE *file;//cria o arquivo
	file= fopen(cpf,"r");//abre o arquivo e o r significa ler
	
	if(file == NULL)//vericação de existencia de usuario
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//retorna os usuario cadastrados
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	 
	 system("pause");//responsavel por dar uma pausa na execução
}

int deletar()// Função responsavel por deletar os usuarios no sistema
{
	char cpf[40];//criação de variavel
	
	printf("Digite o cpf a ser deletado: ");// coletando informação do usuario
	scanf("%s", cpf);// %s refere-se a string
	
	remove(cpf);//responsavel por deletar o usuario
	
	FILE *file;//cria o arquivo
	file= fopen(cpf,"r");//abre o arquivo e o r significa ler
	
	if(file == NULL)//vericação de existencia de usuario
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
}

int main()
{
	// inicio criação das variáveis
	int opcao=0; 
	int laco=1;
	// fim criação das variáveis
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem
		
		printf("### Cartório da EBAC ### \n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); // armazenando a escolha do usuário
		
		system("cls"); //responsavel limpar tela
		
		//seleção com switch case
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
				printf("Essa opção não está disponível!\n");
				system("pause");
			break;
		}
		
		//seleção com if
		/*
		if(opcao==1) // inicio da seleção
		{
			printf("Você escolheu o registro de nomes!\n");
			system("pause");
		}
		if(opcao==2)
		{
			printf("Você escolheu consultar os nomes!\n");
		}
		if(opcao==3)
		{
			printf("Você escolheu deletar nomes!\n");
		}
		if(opcao>=4||opcao<=0)
		{
			printf("Essa opção não está disponível\n");
		} //fim da seleção
		*/
	}
	
}
