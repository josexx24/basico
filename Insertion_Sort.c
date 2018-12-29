#include<stdio.h>
#include<stdlib.h>
#define MAX 20000

void insertion_sort(int*array,int n)
{
  int i,j,key;
  for(j=1;j<n;j++)
  {
    key=array[j];
    i=j-1;
    while(i>=0 && array[i]>key)
    {
      array[i+1]=array[i];
      i--;
    }
    array[i+1]=key;
  }
}

void inicializar(int*array,int n)
{
  int i;  
  printf("\nInicializar arreglo\n");
  for(i=0;i<n;i++)
  {
    printf("Ingrese un numero entero;");
    scanf("%d",&array[i]);
  }
}

void mostrar(int*array,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("A[%d]=%d\n",i+1,array[i]);
  }
}

int main(int argc,char*argv[])
{
  if(argc==2)
  {
    int n=atoi(argv[1]);
    if(n>MAX || n<1)
    {
      printf("El Largo n deber ser mayor a 0 y menor a %d",MAX);
    }
    else
    {
      int*array;
      int op;//opcion del menu
      do{
        printf("MENU:\n\t");
        printf("0-Terminar programa\n\t");
        printf("1-Inicializar arreglo\n\t");
        printf("2-Eliminar arreglo\n\t");
        printf("3-Mostrar arreglo\n\t");
        printf("4-Insertion_Sort\n\t");
        printf("Ingreso opcion:");
        scanf("%d",&op);
        switch(op)
        {
          case 0:
            free(array);
            printf("\nFin del Programa\n");
            break;
          case 1:
            if(!array)
            {
              array=(int*) malloc(n*sizeof(int));
              inicializar(array,n);
            }
            else
            {
              printf("\nEl arreglo ya esta inicializado\n");
            }
            break;
          case 2:
            free(array);
            array=NULL;
            break;
          case 3:
            if(!array)
            {
              printf("\n Arreglo vacio \n");
            }
            else
            {
              mostrar(array,n);
            }
            break;
          case 4:
            insertion_sort(array,n);
            break;
          default:
            printf("\n Opcion no Valida \n");
            break;
        }
      }while(op);
    }
  }
  else
  {
    printf("\n Entrada no valida\n");
    printf("Formato de Entrada:%s n\n(N is the large of array)\n",argv[0]);
  }
  return 0;
}
 
