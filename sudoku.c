#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  //por fila 
  for(int i = 0 ; i < 9 ; i++){
    int esta[10] = {0} ; 

    for(int k = 0 ; k < 9 ; k++){
      int num = n->sudo[i][k] ; 
      
      if(num == 0 ) continue;
      if(esta[num]) return 0 ; //el numero ya estaba en la matriz 
      esta[num] = 1 ; //es como si vieramos cada numero 1 ,...,9 para ver si esta en la posicion
      //como jugar el battleship mas o menos pero con una posicion en vez de barcos y todos son 1x1 
      // y no los undes si no que los marcas con 1 , para que si aparece otro en la fila  la funcion  , if(esta[num]) return 0  , va a funcionar 
      //porque esta del numero va a ser 1 , poque ya lo vimos antes 
    }
  }

  //por columna 
    for(int i = 0 ; i < 9 ; i++){
    int esta[10] = {0} ; 

    for(int k = 0 ; k < 9 ; k++){
      int num = n->sudo[k][i] ; // al revez que arriba para ahora recorrer columnas 
      
      if(num == 0 ) continue;
      if(esta[num]) return 0 ; 
      esta[num] = 1 ;
    }
  }
  
  //sub matrices
  for(int k = 0 ; k < 9 ; k++){
    int esta[10] = {0} ; 

    for(int p = 0;p < 9 ; p++){
      int i=3*(k/3) + (p/3) ;
      int j=3*(k%3) + (p%3) ;
      int num = n->sudo[i][j] ; 
      if(num == 0 ) continue;
      if(esta[num]) return 0 ; 
      esta[num] = 1 ;
    }
  }

    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    for(int i  = 0 ; i < 9 ; i++){
      for(int k  = 0 ; k < 9 ; k++){
        if(n->sudo[i][k] != 0 ) continue;


        for(int l = 1 ; l < 10 ; l++){
          Node* nodeAux = copy(n) ; 
          nodeAux->sudo[i][k] = l ;
          if(is_valid(nodeAux)) pushBack(list , nodeAux) ; 
          else free(nodeAux) ;
        }
        
        return list;

      }
    }
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/