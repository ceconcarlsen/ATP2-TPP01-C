#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>


//*********************************************************
void InserirManualmente(int *Vetor, int *Dim){
    system("cls");
    int j=0;

    printf("\n\n\t\tGERAÇÃO MANUAL"
           "\n\n\n\t Introduza a dimensão do conjunto: ");
           scanf("%i",Dim);

        if(*(Dim)<0){
            printf("\n\n\t O conjunto não tem tamanho definido !!!\n\n");
            return;
          }
        else if(*(Dim) == 0){
            printf("\n\n\t O conjunto é vazio !!!\n\n");
            return;
    }

         else{
            printf("\n\nDigite os valores: \n");
            for(j;j<*(Dim);j++){
            printf("\n [%i] = ",j);
            scanf("%i",(Vetor+j));
            }
         }

        OrdenacaoBolha(Vetor,*Dim);
        printf("\n\nO conjunto ordenado: \n");
        ImprimeValoresArray(Vetor,*Dim);
        printf("\n\n");
        system("pause");
        system("cls");

return;

}
//*********************************************************



//*********************************************************
void GerandoConjuntos(int *Vetor, int *Dim){
    system("cls");
    int i=0;

    printf("\n\n\t\tGERAÇÃO RANDOMICA\n"
           "\n\n\t Introduza a dimensão do conjunto: ");
           scanf("%i",Dim);


    if(*(Dim)<0){
        printf("\n\n\t O conjunto não tem tamanho definido !!!\n\n");
    }
    else if(*(Dim) == 0){
        printf("\n\n\t O conjunto é vazio !!!\n\n");
    }
    else{
        for(i;i<(*Dim);i++){
            *(Vetor+i)= rand();
        }
    }

    printf("\n\n O conjunto ordenado: \n");
    OrdenacaoBolha(Vetor,*Dim);
    ImprimeValoresArray(Vetor,*Dim);
    printf("\n\n");
    system("pause");
    system("cls");

 return;

}
//*********************************************************



//*********************************************************
void Troca1(int *S, int Ind1, int Ind2) {
int aux;

  aux =  *(S+Ind1);
  *(S+Ind1) =  *(S+Ind2);
  *(S+Ind2) = aux;

  return;

}
//*********************************************************



//*********************************************************
void OrdenacaoBolha(int *Elem, int Dim){ //ordem crescente
 int i=1, j, continua=1, exp1;

 while ( (i < Dim ) && continua ) { // controla o numero de varreduras
     continua = 0;
     exp1 = Dim-i;
     for (j = 0; j < exp1; j++) {  // aponta para as posicoes do array
	   if ( *(Elem+j) > *(Elem+j+1) ) {
             // permutando elementos
	     Troca1(Elem,j,j+1);
	     continua = 1;          // realizou uma troca
	   }
	 }
     i++;
   }
  return;

}
//*********************************************************



//*********************************************************
void ImprimeValoresArray(int *vetor,int Dim){
    int i=0;

    for(i;i<Dim;i++){
        printf("\n[%i] - %i",i,*(vetor+i));
    }
    printf("\n");

return;

}
//*********************************************************



//*********************************************************
void Uniao(int *A, int *B, int *DimA, int *DimB, int *C, int *DimC){
    int i=0, j=0, k=0;

    while((i<(*DimA))&&(j<(*DimB))){

        if(*(A+i)<(*(B+j))){
            *(C+k)=*(A+i);
            i++;
        }

        else if(*(B+j)<(*(A+i))){
            *(C+k)= *(B+j);
            j++;
        }

        else{
            *(C+k)= *(A+i);
            i++;
            j++;
    }
k++;
}
    while(i<(*DimA)){
        *(C+k)= *(A+i);
        i++;
        k++;
    }
    while(j<(*DimB)){
        *(C+k)= *(B+j);
        j++;
        k++;
    }
    *(DimC) = k;

return;

}
//*********************************************************



//*********************************************************
void Interseccao(int *A, int *B, int *DimA, int *DimB, int *C, int *DimC){
    int i=0,j,k=0;

    for(i;i<*(DimA);i++){
        for(j=0;j<*(DimB);j++){
            if(*(A+i) == *(B+j)){
                    *(C+k)= *(A+i);
                    k++;
            }
        }
    }

    *DimC=k;
return;

}
//*********************************************************



//*********************************************************
void Diferenca(int *A,int *B,int DimA,int DimB,int *C,int *DimC){
    int i=0,j,k=0;

    for(i;i<DimA;i++){
        for(j=0;j<DimB;j++){
            if(*(A+i)==*(B+j)){
                break;
            }
            if(j==(DimB-1)){
                *(C+k)= *(A+i);
                k++;
            }

        }

    }

*(DimC)=k;
return;

}
//*********************************************************



//*********************************************************
short Verifica(int *Str, int Chave, int Dim) {
 int ini = 0,   // indice que indica a posicao inicial do intervalo
     meio,      // indice que indica a posicao central do intervalo
     fim = Dim-1; // indice que indica a posicao final do intervalo

  while ( ini <= fim) {
     meio = (ini+fim)/2;
     if ( *(Str+meio) == Chave ) return(1); // elemento pertence ao array
     else if ( Chave < *(Str+meio) ) fim = meio - 1;
     else ini = meio + 1;
    }

 return(0);// elemento nao pertence ao array

}  // Busca_Linear
//*********************************************************



//*********************************************************
int Repetidos(int *Vetor, int Dim){
    int i=0,j=1;

  for(i;i<Dim;i++){
   for(j;j<=Dim;j++){
    if(*(Vetor+i) == (*(Vetor+j))){
        return(1);
     }
    }
   }

  return(0);

}
//*********************************************************



//*********************************************************
void EliminaRepetidos(int *Vetor, int Dim, int *VetorF, int *DimF){
    int i=0,k=0;

    for(i;i<Dim;i++){
        if(*(Vetor+i)!= *(Vetor+(i+1))){
            *(VetorF+k)= *(Vetor+i);
            k++;
        }
    }


*(DimF)=k;

return;

}
//*********************************************************




//*********************************************************
int main(void){
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL)); //Srand para não deixar o rand() repetir os mesmos valores.

    int A[100]={0},B[100]={0},C[200]={0}; //Vetores inicializa-dos com 0, Vetor C[200] pois união(m+n) == 200.
    int DimA,DimB,DimC; //Dimensões dos veteores.
    int repete=0, repete2=0, repete3=0;
    int x,f,z,e;
    char q,t,u;


printf("TPP-01        Operações sobre Conjuntos                 *Gabriel Cecon Carlsen\n");
printf("                                                        *Ricardo de Moraes\n\n\n\n");



do{
        printf(
       "\n\n\n\t 1 - Introduzir os conjuntos (A e B) "
       "\n\t 0 - Sair"
       "\n\n\n\t Escolha uma opção: ");
        scanf("%i",&x);
        system("cls");

switch(x){

    case 0:break;

    case 1:
             do{
             printf("\n\n\t       INTRODUZINDO O CONJUNTO A "
             "\n\n\n\t 1 - Gerar randomicamnete o conjunto "
             "\n\t 2 - Gerar manualmente o conjunto"
             "\n\n\t Escolha uma opção: ");
             scanf("%i",&f);
             system("cls");


             switch(f){

                 case 1: GerandoConjuntos(A,&DimA);break;

                 case 2: InserirManualmente(A,&DimA);break;


                default: printf("\n\n\n\t\t\t\t\tERRO - OPÇÃO INVÁLIDA !!!\n\n\n");repete2=1;
             }


             printf("\n\n\t       INTRODUZINDO O CONJUNTO B "
             "\n\n\n\t 1 - Gerar randomicamnete o conjunto "
             "\n\t 2 - Gerar manualmente o conjunto"
             "\n\n\t Escolha uma opção: ");
             scanf("%i",&f);
             system("cls");

             switch(f){

                 case 1: GerandoConjuntos(B,&DimB);break;

                 case 2: InserirManualmente(B,&DimB);break;


                default: printf("\n\n\n\t\t\t\t\tERRO - OPÇÃO INVÁLIDA !!!\n\n\n");repete2=1;
             }

              }while(repete2);

                repete=0;
                break;


    default: printf("\n\n\n\t\t\t\t\tERRO - OPÇÃO INVÁLIDA !!!\n\n\n");repete=1;

 }

} while(repete);



  system("cls");


if(x){
do{
  if(x){
  printf("Os conjuntos A e B são respectivamente: \n");
              ImprimeValoresArray(A,DimA);
              ImprimeValoresArray(B,DimB);
  }
    printf("\n\t\t\t MENU [OPERAÇÃO SOBRE CONJUNTOS]  \n\n"
           "\t  1 - Interseção entre os conjuntos A e B \n"
           "\t  2 - União entre os conjuntos A e B \n"
           "\t  3 - Diferença entre os conjuntos A e B \n"
           "\t  4 - Diferença entre os conjuntos B e A \n"
           "\t  5 - Verificar se um elemento pertence ao conjunto \n"
           "\t  6 - Verificar se há elementos repetidos nos conjuntos A ou B \n"
           "\t  7 - Eliminar os elementos repetidos de um conjunto \n" // aplicar na intersecção
           "\t  8 - Verificar se um conjunto é vazio \n"
           "\t  9 - Determinar a quantidade de elementos do conjunto \n"
           "\t  0 - Sair \n\n"
           "\t  Escolha uma opção: ");
    scanf("%i", &z);



    switch(z){

        case 0:repete3=0;break;

        case 1: Interseccao(A,B,&DimA,&DimB,C,&DimC);
                 if(DimC==0){
                    printf("\nA intersecção entre os conjuntos A e B: CONJUNTO VAZIO !!! \n");
                 }
                 else{
                 printf("\nA intersecção entre os conjuntos A e B: \n");
                 OrdenacaoBolha(C,DimC);
                 ImprimeValoresArray(C,DimC);
                 }
                 printf("\n\n");
                 break;


        case 2: Uniao(A,B,&DimA,&DimB,C,&DimC);
                 printf("\nA união entre os conjuntos A e B: \n");
                 ImprimeValoresArray(C,DimC);
                 printf("\n\n");
                 break;

        case 3: Diferenca(A,B,DimA,DimB,C,&DimC);
                if(DimC == 0){
                  printf("\nA diferença entre os conjuntos A e B: CONJUNTO VAZIO !!!\n");
                }
                else{
                OrdenacaoBolha(C,DimC);
                printf("\nA diferença entre os conjuntos A e B: \n");
                ImprimeValoresArray(C,DimC);
                }

                 printf("\n\n");
                 break;

        case 4: Diferenca(B,A,DimB,DimA,C,&DimC);
                if(DimC == 0){
                  printf("\nA diferença entre os conjuntos B e A: CONJUNTO VAZIO !!!\n");
                }
                else{
                OrdenacaoBolha(C,DimC);
                printf("\nA diferença entre os conjuntos B e A: \n");
                ImprimeValoresArray(C,DimC);
                }

                 printf("\n\n");
                 break;

        case 5: system("cls");
                 printf("\n\n\t\t\tPERTENCE AO CONJUNTO ? \n\n\n"
                        "\t Introduza o elemento (inteiro) a ser verificado: ");
                        scanf("%i",&e);
                 printf("\n\n");
                 printf("\t Agora introduza o conjunto (A ou B): ");
                 scanf("%c",&t);
                 scanf("%c",&t);
                 printf("\n\n");
                 if(t=='A'){
                      if(Verifica(A,e,DimA)){
                          printf("\n\n\n\n\n\t\t\t\t O elemento %i PERTENCE ao conjunto %c !!!",e,t);
                      }
                      else{
                         printf("\n\n\n\\n\n\t\t\t\t O elemento %i NÃO PERTENCE ao conjunto %c !!!",e,t);
                      }

                 }
                 else{
                      if(Verifica(B,e,DimB)){
                        printf("\n\n\n\\n\n\t\t\t\t O elemento %i PERTENCE ao conjunto %c !!!",e,t);
                      }
                      else{
                        printf("\n\n\n\\n\n\t\t\t\t O elemento %i NÃO PERTENCE ao conjunto %c !!!",e,t);
                      }
                 }
                 printf("\n\n\n\n\n\n\n\n\n\n\n");
                 break;

        case 6: system("cls");
                 printf("\n\n\t\tCONTÊM ELEMENTOS REPETIDOS ?\n\n\n"
                        "\t Introduza o conjunto a ser verificado (A ou B): ");
                        scanf("%c",&u);
                        scanf("%c",&u);
                        printf("\n\n");

                    if(u == 'A'){
                       if(Repetidos(A,DimA)){
                         printf("\n\n\n\n\n\t\t\t\t O conjunto %c CONTÉM elementos repetidos !!!",u);
                       }
                       else{
                         printf("\n\n\n\n\n\t\t\t\t O conjunto %c NÃO CONTÉM elementos repetidos !!!",u);
                       }
                    }

                    else{
                        if(Repetidos(B,DimB)){
                         printf("\n\n\n\n\n\t\t\t\t O conjunto %c CONTÉM elementos repetidos !!!",u);
                       }
                       else{
                         printf("\n\n\n\n\n\t\t\t\t O conjunto %c NÃO CONTÉM elementos repetidos !!!",u);
                       }
                    }

                       printf("\n\n\n\n\n\n\n\n\n\n\n");
                       break;

            case 7: system("cls");
                        printf("\n\n\t\tELIMINAR ELEMENTOS REPETIDOS\n\n\n"
                        "\t Introduza o conjunto a ser alterado (A ou B): ");
                        scanf("%c",&u);
                        scanf("%c",&u);
                        printf("\n\n");

                        if(u == 'A'){
                            EliminaRepetidos(A,DimA,C,&DimC);
                            OrdenacaoBolha(C,DimC);
                            printf("\nO conjunto %c sem elementos repetidos: \n",u);
                            ImprimeValoresArray(C,DimC);
                        }
                        else{
                            EliminaRepetidos(B,DimB,C,&DimC);
                            OrdenacaoBolha(C,DimC);
                            printf("\nO conjunto %c sem elementos repetidos: \n",u);
                            ImprimeValoresArray(C,DimC);
                        }
                    printf("\n\n\n\n\n\n\n\n\n\n\n");
                    break;

            case 8: system("cls");
                        printf("\n\n\t\tO CONJUNTO É VAZIO ?\n\n\n"
                        "\t Introduza o conjunto a ser verificado (A ou B): ");
                         scanf("%c",&u);
                         scanf("%c",&u);
                         printf("\n\n");

                         if(u == 'A'){
                            if(DimA<0){
                                printf("\n\n\n\n\n\t\t\t\t O conjunto %c É VAZIO !!!",u);
                            }
                            else{
                                printf("\n\n\n\n\n\t\t\t\t O conjunto %c NÃO É VAZIO !!!",u);
                            }
                         }

                         else{
                            if(DimB<0){
                                printf("\n\n\n\n\n\t\t\t\t O conjunto %c É VAZIO !!!",u);
                            }
                             else{
                                printf("\n\n\n\n\n\t\t\t\t O conjunto %c NÃO É VAZIO !!!",u);
                            }
                         }

                       printf("\n\n\n\n\n\n\n\n\n\n\n");
                       break;

            case 9: system("cls");
                        printf("\n\n\t\tQUNATIDADE DE ELENTOS DO CONJUNTO ?\n\n\n"
                               "\t Introduza o conjunto a ser verificado (A ou B): ");
                               scanf("%c",&u);
                               scanf("%c",&u);
                               printf("\n\n");

                         if(u == 'A'){
                            printf("\n\n\n\n\n\t\t\t\t O conjunto %c contém %i elementos !!!",u,DimA);
                         }
                         else{
                            printf("\n\n\n\n\n\t\t\t\t O conjunto %c contém %i elementos !!!",u,DimB);
                         }

                       printf("\n\n\n\n\n\n\n\n\n\n\n");
                       break;


   default: printf("\n\n\n\t\t\t\t\tERRO - OPÇÃO INVÁLIDA !!!\n\n\n");repete3=1;

    }


    if(z){
    printf("\t\t\t\t Deseja efetuar outra operação ? (s/n): ");
                 scanf("%c",&q);
                 scanf("%c",&q);
                 printf("\n");

                 if(q == 's' || q == 'S'){ // Repetindo o MENU
                    repete3=1;
                    system("cls");
                 }
                 else{
                    repete3=0;
                 }


    }

}while(repete3);

}

  system("cls");
  printf("\n\n\n\n\n\t\t\t\t\t(FIM DO PROGRAMA)\n\n");
  printf("\n\n\n");
  system("Pause");
  return(0);

}
//*********************************************************
