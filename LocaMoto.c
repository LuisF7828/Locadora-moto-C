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
   int codigocar;
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
 int cad_cliente (void){
    printf("Cadastro %d de 1 milhao\n", j);
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
    return(0);
 }
 int list_cliente (void){
   int k=0;
   if(Cliente[k].cod != 0)
 	   {
 	k++;
 	printf("\nNome do Cliente: %s\n", Cliente[k].nome);
 	getch();
 	   }
   return (0);
 }
 int cad_moto (void){
   printf("Cadastro de Motocicleta %d de 1 milhao\n", i);
   if(i<1000000){
 	 printf("Digite o codigo do veiculo: ");
 	 scanf("%d", &moto[i].codcar);
 	 fflush(stdin);
 	 printf("Digite o modelo do carro: ");
 	 gets(moto[i].modelo);
 	 fflush(stdin);
 	 printf("Digite a marca do carro: ");
 	 gets(moto[i].marca);
 	 fflush(stdin);
 	 printf("Digite a placa do carro: ");
 	 gets(moto[i].placa);
 	 i++;
 	}
   return(0);
 }
 int loc_moto (void)
 {
   int k=0;
   char consulta[40];
   char resposta;
   int codi;
   fflush(stdin);
   printf("Digite o nome do cliente que quer locar um veiculo: ");
   gets(consulta);
   for(k=0; k<100000; k++){
 	if(consulta == Cliente[k].nome){
 	  printf("Cliente cadastrado, deseja locar veiculo s/n: ");
 	  scanf("%s", &resposta);
 	  if(resposta == 's')
 		{
 		  printf("Digite o codigo da Motocicleta: ");
 		  scanf("%d", &codi);
 		  if(Cliente[k].codigocar==codi){
             printf("Locacao cadastrada com sucesso:");
             moto[k].status= 1;
             return 0;
 		  }
 		  else
             if(Cliente[k].codigocar!=codi){
 		  printf("Motocicleta nao encontrada no banco:");
             return 0;
 		  }
 		}
 	 }
    }
    printf("Cliente nao Cadastrado");
    return 0;
 }
 int mostra_clientes (void)
 {
 	for (j=0; j<50; j++)
 	{
 	   if(Cliente[j].codigocar != 0)
 		{
 		   printf("Cliente: %s", Cliente[i].nome);
 		   printf("Marca do veiculo: %s", moto[i].marca);
 	   i++;
 		}
 	}
   return(0);
 }
 int devo_moto (void)
 {
   char dev, devolucao[40];
   printf("Digite o Nome do Cliente que vai devolver veiculo: ");
   scanf("%c", &devolucao);
   for (i=0; i<1000000; i++)
    {
 	if(devolucao == Cliente[i].nome)
 	  {
 		printf("Realizar devolucao s/n? ");
 		scanf("%c", &dev);
 		if (dev == 's')
 		  {
 			Cliente[i].codigocar=0 ;
 			moto[i].status=0;
 		  }
 	  }
    }
   return(0);
 }
 
 int main (void)
 {
   int opcao=0;
   while(opcao<8)
   {
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
 	switch(opcao)
 	  {
 		  case 1: cad_cliente(); break;
 		  case 2: list_cliente(); break;
 		  case 3: cad_moto(); break;
  	  case 4: loc_moto(); break;
 		  case 5: mostra_clientes(); break;
 
		  case 6: devo_moto(); break;
		  case 7: exit(0); break;
 		  default: printf("\nop‡Æo invalida - tecle <enter>");
 		  fflush(stdin);
 		  while ((tecla=getchar())!='\r')
 		  break;
 	  }
   }
   getch();
   return(0);
 }
