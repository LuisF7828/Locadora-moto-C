#include <stdio.h>
#include <stdlib.h>

int i=0, j=0;
char tecla;

struct cadastro_cliente{
	int cod;
 	char nome [40];
	char rua [30];
 	int numero;
 	int cpf;
 	char bairro [30];
 	char cidade [30];
    int codicar;
   };
struct cadastro_cliente Cliente[1000000];
struct cadastro_moto
{
    int codcar;
    char modelo [20];
 	char marca [15];
 	char placa [15];
 	int status;

};
struct cadastro_moto moto[1000000];
	 int cad_cliente(void);
	 int list_cliente(void);
	 int cad_moto(void);
	 int loc_moto(void);
	 int mostra_clientes(void);
	 int devo_moto(void);
	 int cad_cliente (void)
{
        printf("Cadastro %d \n", j);

        if (j<1000000){
 		printf("Digite o codigo do Cliente: ");
 		scanf("%d", &Cliente[j].cod);
 		fflush(stdin);
 		printf("Digite o nome do Cliente: ");
 		gets(Cliente[j].nome);
 		printf("Digite o CPF do Cliente: ");
 		scanf("%d", &Cliente[j].cpf);
 		fflush(stdin);
 		printf("Digite o nome da Rua: ");
 		gets(Cliente[j].rua);
 		fflush(stdin);
 		printf("Digite o numero da casa: ");
 		scanf("%d", &Cliente[j].numero);
 		fflush(stdin);
 		printf("Digite o nome do Bairro: ");
 		gets(Cliente[j].bairro);
 		fflush(stdin);
 		printf("Digite o nome da Cidade: ");
 		gets(Cliente[j].cidade);
 		j++;
    }
}
int list_cliente (void){
int k=0;
if(Cliente[k].cod != 0)
{
 	printf("\nNome do Cliente: %s\n", Cliente[k].nome);
 	k++;
 	   }
         return (0);
 }

int cad_moto (void){
    printf("Cadastro de Motocicleta %d\n", i);

    if(i<1000000){
 	 printf("Digite o codigo do veiculo: ");
 	 scanf("%d", &moto[i].codcar);
 	 fflush(stdin);
 	 printf("Digite o modelo do veiculo: ");
 	 gets(moto[i].modelo);
 	 fflush(stdin);
 	 printf("Digite a marca do veiculo: ");
 	 gets(moto[i].marca);
 	 fflush(stdin);
 	 printf("Digite a placa do veiculo: ");
 	 gets(moto[i].placa);
 	 i++;
    }
}

int loc_moto (void)
{
     int k=0;
     char consulta[40];
     int resposta;
     int codi;
     fflush(stdin);
     printf("Digite o nome do cliente que quer locar um veiculo: ");
     scanf("%s",&consulta);


    	if(consulta == Cliente[j].nome) {
            printf("Cliente cadastrado, deseja locar veiculo 1- ss/2 - nn: ");
            scanf("%s", &resposta);

            switch(resposta){

            case '1':
                printf("Digite o codigo da Motocicleta: ");
                scanf("%d", &codi);

                if (moto[i].codcar == codi){
                printf("Locacao cadastrada com sucesso:");
                moto[k].status= 1;
                return 0;
                break;

 	  }
        }
            }


        else if(Cliente[k].codicar!=codi){
 		printf("Motocicleta nao encontrada no banco:");

          return 0;
 		  }

    if (consulta != Cliente[k].nome){
    printf("Cliente nao Cadastrado");
    }
    return 0;

}
 int mostra_clientes (void)
 {
 	   if(Cliente[j].cod != 0)
 		{
        for (j=0; j<1000000; j++){
            for(i=0; i<1000000; i++){
                printf("Cliente: %s", Cliente[j].nome);
                printf("Marca do veiculo: %s", moto[i].marca);
                i++;
                j++;
            }
        }

 	}if (Cliente[j].codicar == 0 ){
 	    printf("Nao ha clientes cadastrados!");
 	}
   return 0;
 }
 int devo_moto (void)
 {
   char dev, devolucao[40];
   printf("Digite o Nome do Cliente que vai devolver veiculo: ");
   scanf("%s", &devolucao);
   for (i=0; i<1000000; i++)
    {
 	if(devolucao == Cliente[i].nome)
 	  {
 		printf("Realizar devolucao s/n? ");
 		scanf("%s", &dev);
 		if (dev == 's')
 		  {
 			Cliente[i].codicar = Cliente[i].codicar - 1;;
 			moto[i].status = moto[i].status - 1;
 		  }
 	  }else{
 		  printf("\nAlgo de errado aconteceu verifique os dados e tente novamente");
 		  return 0;
 		  }
    }
   return 0;
 }

 int main (void)
{
   int opcao=0;
   while(opcao<8){
 	printf("\n\nLOCADORA DE MOTOCICLETAS\n");
 	printf("..................\n\n");
 	printf("1 - CADASTRAR CLIENTE\n");
 	printf("2 - LISTAR CLIENTES CADASTRADOS\n");
 	printf("3 - CADASTRAR MOTOCICLETA\n");
 	printf("4 - LOCAR MOTOCICLETA\n");
 	printf("5 - CLIENTES COM MOTOCLICLETAS LOCADAS\n");
 	printf("6 - DEVOLUCAO DE MOTOCICLETA\n");
 	printf("7 - SAIR\n\n");
 	printf("Escolha uma opcao:");
 	fflush(stdin);
    scanf("%d", &opcao);

 	switch(opcao) {
 		  case 1: cad_cliente(); break;
 		  case 2: list_cliente(); break;
 		  case 3: cad_moto(); break;
          case 4: loc_moto(); break;
 		  case 5: mostra_clientes(); break;
		  case 6: devo_moto(); break;
		  case 7: exit(0); break;
 		  default: printf("\nopcao invalida - tecle <enter>");
 		  fflush(stdin);
 		  break;
 	  }
   }
   return 0;
 }
