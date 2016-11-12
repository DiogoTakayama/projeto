/* Prototico da funçao vendas do projeto budega IMD
Falta melhorar
*/

//Bibliotecas utilizadas

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Declaração das variáveis ​​do tipo globais
FILE * ptr;//Ponteiro para o Arquivo
short z,x=14,y=12,f=0,quantcompra=0;
char clientefatura[50];
int a;

//Uma estrutura para cada campo da fatura

struct registroVendas{

    char nomeCliente[20];// Vai pegar o nome do Cliente
    float quantidade;// Quantidade de Produtos
    char nomeArtigo[20];// Nomme do artigo
    float preco;//Preço de cada Artigo
   float total;//O Total
    float totalaPagar;// Total a pagar

}fatura[100];


//Esta funcção serve salvar a fatura, quando o usuário aceita a opção
void salvarfatura(){

    // Cria un arquivo .txt coo nome do cliente
    ptr = fopen(clientefatura,"a+");/*Esse "a" Abre o arquivo para escrita no final do arquivo e leitura.
                                        Se fosse só "a" Abriria o arquivo para escrita no final do arquivo.
                                        Não apaga o conteúdo pré-existente.
                                     (O a vem do inglês append, adicionar, apender) */

    if (ptr==NULL){ // Condição feita caso o arquivo não possa ser aberto
            system("cls");
        printf("Error de arquivo");
        return;
    }else{


            for (f=0;f<quantcompra;f++){
            fwrite(&fatura[f],sizeof(fatura[f]),1,ptr);

            /*fwrite é uma função que envolve os conceitos de ponteiro e vetor.
             O Prótotico dela eh:
             unsigned fwrite(void *buffer,int numero_de_bytes,int count,FILE *fp)
           Ela retorna o número de itens escritos.*/
            }






        fclose(ptr);//Fecha o arquivo

        system("cls");

        printf("Fatura Salva! ...");
        printf("Obrigado pela  compra!..");


    system("cls||clear");// Serve para limpar a tela de saída do programa

    main();


    }





}

//Esta função fatura tudo, e também  calcular o total
void faturar(){
    short cont=1,grfatura,opcfatura,quantnom;
    float acumulador=0;

    system("cls||clear");

    printf("\nBudega IMD\n");

    fflush(stdin);
    printf("\nNome cliente: ");
   scanf("%[^\n]s",&fatura[0].nomeCliente);

    printf("quantidade\t");

    printf("\tartigo ");

    printf("\tPreco ");

    printf("\tTotal\n ");

   // Nesta variável Eu estou guuardando o número de caracteres que têm o nome do cliente, em seguida, usar o for
    quantnom=strlen(fatura[0].nomeCliente);

    //este for é para fazer uma cópia do nome do cliente.
    for(z=0;z<=quantnom;z++){
        clientefatura[z]=fatura[0].nomeCliente[z];

    }

    //com esta função concateno a copia do nome em "Fatura.txt"
    strcat(clientefatura,"Fatura.txt");

        f=0;
        quantcompra=0;
        x=14;
        y=12;

    while(cont>=1){
/*Para limpar o buffer em Windows, usa-se: fflush(stdin)
Para limpar o buffer em Linux, use: __fpurge(stdin)
surgiu  umaa duvida qual seria a melhor forma de  fazer isso
ou seria dando um getchar?*/
        printf("            ");
        fflush(stdin);

        scanf("%f",&fatura[f].quantidade);
         fflush(stdin);

        scanf("%[^\n]s",&fatura[f].nomeArtigo);
         fflush(stdin);

        scanf("%f",&fatura[f].preco);
         fflush(stdin);

          fatura[f].total=fatura[f].quantidade*fatura[f].preco;
          printf("%.2f",fatura[f].total);
        acumulador+=fatura[f].total;

        fflush(stdin);
        fatura[f].totalaPagar=acumulador;


       printf("\nMAIS ARTIGOS?(1/0):\n ");
        scanf("%d",&cont);
        f++;
    quantcompra++;
        y+=2;


    }




    printf("\nTotal a pagar: %.2f\n",acumulador);

    printf("SALVAR  FATURA?(1/0): ");
    scanf("%d",&grfatura);


     y=12;

    if (grfatura>=1){
        salvarfatura();
    }else{
        system("cls||clear");

        printf("Deseja voltar a fazer outra fatura?\nSim(1) ou Nao (0): ");
        scanf("%d",&opcfatura);
        if (opcfatura>=1){
                system("cls");
                faturar();

            }else{
                system("cls||clear");
                main();


            }
    }

}

//Esta função mostrar o historico de compras de um cliente

    void VerFatura(){

    short quantn,cont=0,outrocliente;
    char nom[20],nomcliente[50];

    system("cls||clear");

    printf("voce escolheu a opcao de ver faturas.");

    printf("\nDigite o nome do cliente:\n ");
    fflush(stdin);
    scanf("%[^\n]s",nom);

    quantn= strlen(nom);//Determina o tamanho de uma string.

    for (z=0;z<quantn;z++){
        nomcliente[z]=nom[z];

    }

    strcat(nomcliente,"Fatura.txt");
    printf("\n");


    ptr=fopen(nomcliente,"r");
    if (ptr==NULL){
            system("cls||clear");

       printf("Error ao ler, a fatura esse cliente nao existe!...");

       system("cls||clear");
       main();

    }else{

        system("cls");

        f=0;
        x=14;
        y=12;

         while(!feof(ptr)){
/*feof
EOF ("End of file") indica o fim de um arquivo.*/

             cont= fread(&fatura[f],sizeof(fatura[f]),1,ptr);
            /* Le em conteudo o valor da variável armazenada anteriormente */

             if (cont==1){



                printf("\nFatura do cliente:\n %s",nom);

                printf("\nquantidade\n ");

                printf("\n%.2f\n",fatura[f].quantidade);

                printf("\nArtigo\n ");

                printf("\n%s\n",fatura[f].nomeArtigo);

                printf("\nPreco\n ");

                printf("\n%.2f\n",fatura[f].preco);

                printf("\nTotal \n");

                printf("\n%.2f\n",fatura[f].totalaPagar);
                f++;
                y+=2;
             }




    }



        fclose(ptr);

        fflush(stdin);
       printf("Ver outro cliente?\n Sim(1) Nao (0): ");
        scanf("%d",&outrocliente);

            if (outrocliente>=1){

                system("cls||clear");
                VerFatura();

            }else{

                system("cls");
                main();

            }



    }






}

//Esta função remove o arquivo de um cliente, bastando somente digitar o seu Nome
void excluirFatura(){


    char excluirfatu[20],excluirdir[10]="erase \\ ";

system("cls||clear");


printf("Digite o cliente que deseja excluir: ");
fflush(stdin);
scanf("%[^\n]s",&excluirfatu);

strcat(excluirdir,excluirfatu);
strcat(excluirdir,"Fatura.txt");




if (system(excluirdir)==NULL){
        system("cls");

        printf("A Fatura foi excluida...");

        system("cls||clear");
        main();

    }else{

        system("cls||clear");

        printf("Não foi eliminada ...");

        system("cls");
        main();

        }


    }

//Função simples para sair
void sair(){
    system("cls||clear");

    printf("\nVoce optou por sair, ate mais!..\n");


}

// Função principal,
main(){

short opcoes;

system("color a");

//setlocale(LC_ALL, "Portuguese");


printf("Bem-vindo ao sistema de vendas Budega IMD!\n");

printf("\n1- Criar fatura\n");

printf("\n2- Ver fatura\n");

printf("\n3- Excluir fatura\n");

printf("\n4- Sair\n");

printf("\n Escolha uma opcao: \n");
scanf("%d",&opcoes);

switch(opcoes){

case 1: faturar(); break;
case 2: VerFatura(); break;
case 3 : excluirFatura(); break;
default: sair();

}


getch();
}
