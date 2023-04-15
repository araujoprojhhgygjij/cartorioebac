#include <stdio.h> //biblioteca de comunicação com usarios
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h>  //biblioteca responsavel por cuidar da string


int registro() //Função responsalvel por cadrastar os usuarios no sistema
 {
 	//inicio criação de variaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   	//final criação de variaveis/string
   
   printf("Digite o CPF a ser cadrastrado: "); //coletando informação do usuario
   scanf("%s", cpf); //%s refese-se a string	
   
   strcpy(arquivo, cpf); //responsalvel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadrastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
    printf("Digite o sobrenome a ser cadrastrado:");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadrastrado");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
 }  


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system ("pause");
	}
	   
    
}

int main()
{
	int opcao=0; //Definindo variaveis
	
	int laco=1;
	
	for(laco=1;laco=1;) 
	{
		
		system("cls");
		
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
	printf("Escolha a opção desejada no menu:\n\n");
	printf("\t1 -Registrar nomes\n");
	printf("\t2 -Consultar nomes\n");
	printf("\t3 -Deletar nomes\n\n"); //fim do menu
	printf("opção");
	
    scanf("%d", &opcao); //Armazenando a escolha do usuario
    
    system("cls"); //responsalvel por lipmar a tela
    
    switch(opcao)
   {
	   case 1:
	   	registro(); //chamada de funçoes
	    break;
	 
	    case 2:
	 	consulta();
    	break;
    	
    	case 3:
    	deletar();
   	     break;
   	        
   	    default:
   	    	printf("Essa opção não esta disponivel\n"); 
   	        system("pause");
    		break;
   }
	 
}
   
     
}
