#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 20000

void mostrar(int*array,int n)
{
  int i;
  printf("\n");
  for(i=0;i<n;i++)
  {
    printf("A[%d]=%d\t",i+1,array[i]);
  }
  printf("\n");
}
void mostrar2(int*array,int p,int n)
{
  int i;
  printf("\n");
  for(i=p;i<n;i++)
  {
    printf("A[%d]=%d\t",i+1,array[i]);
  }
  printf("\n");
}
void merge2(int*array,int p,int q,int r)
{
  int n1,n2,i,j,k;
  n1=q-p+1;
  n2=r-q;
  int *L=(int*) calloc(n1,sizeof(int));
  int *R=(int*) calloc(n2,sizeof(int));
  for(i=0;i<n1;i++)
  {
	  L[i]=array[p+i];
  }
  for(j=0;j<n2;j++)
  {
	  R[j]=array[q+j+1];
  }
  i=0;
  j=0;
  k=p;
  while(i<n1 && j<n2)
  {
    if(L[i]<=R[j])
    {
      array[k]=L[i];
      i++;
    }
    else
    {
      array[k]=R[j];
      j++;
    }
    k++;
  }
  if(i==n1)
  {
    while(j<n2)
    {
      array[k]=R[j];
      j++;
      k++;
    }
  }
  else
  {
    while(i<n1)
    {
      array[k]=L[i];
      i++;
      k++;
    }
  }
  free(L);
  free(R);

}
void merge2(int*array,int p,int q,int r)// 
{
  int n1,n2,i,j,k;
  n1=q-p+1;
  n2=r-q;
  int *L=(int*) calloc(n1+1,sizeof(int));
  int *R=(int*) calloc(n2+1,sizeof(int));
  for(i=0;i<n1;i++)
  {
	L[i]=array[p+i];
  }
  for(j=0;j<n2;j++)
  {
	R[j]=array[q+j+1];
  }
  L[n1]=INT_MAX;
  R[n2]=INT_MAX;
  i=0;
  j=0;
  for(k=p;k<=r;k++)
  {
	if(L[i]<=R[j])
	{
		array[k]=L[i];
		i++;
	}
	else
	{
		array[k]=R[j];
		j++;
	}
  }
  free(L);
  free(R);
}

void merge_sort(int*array,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		merge_sort(array,p,q);
		merge_sort(array,q+1,r);
		merge2(array,p,q,r);
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
        printf("4-Merge_Sort\n\t");
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
            merge_sort(array,0,n-1);
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
 
