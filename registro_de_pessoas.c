#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas string

int adicionar()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo ou condi��o a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int excluir()
{
	printf ("Voc� escolheu excluir nomes!\n");
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Este n�mero de CPF n�o est� registrado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int x=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("##Registro de Alunos EBAC##\n\n");
	printf ("Login de administrador.\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao=strcmp(senhadigitada, "admin");
	
	if(comparacao==0)
	{
	
	
		for(x=1;x=1;)
		{
			
			system("cls");
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("##Registro de Alunos EBAC##\n\n"); //In�cio do menu
			printf ("Escolha uma op��o no menu: \n\n");
			printf ("\t1 - Adicionar nomes \n");
			printf ("\t2 - Consultar nomes \n");
			printf ("\t3 - Excluir nomes \n\n");
			printf ("\t4 - Sair do sistema \n\n");
			printf ("Op��o: ");//Fim do menu
	
			scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
			system("cls");
	
		
			switch(opcao)
			{
				case 1:
				adicionar();
				break;
			
				case 2:
				consultar ();
				break;
			
				case 3:
				excluir();
				break;
			
				case 4:
				printf ("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Op��o n�o dispon�vel!\n");
				system("pause");
				break;
			
			} //fim da sele��o
		

		}
		
	}
	
	else
		printf("Senha incorreta!");
}
