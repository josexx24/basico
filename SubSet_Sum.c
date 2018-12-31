#include<stdio.h>
#include<stdlib.h>
#define MAX 20000

void merge(int*array,int p,int q,int r)
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

void merge_sort(int*array,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		merge_sort(array,p,q);
		merge_sort(array,q+1,r);
		merge(array,p,q,r);
	}
}

int binary_search_R(int*array,int v,int low,int high)
{
	
	if(low>high)
	{
		return -1;
	}
	int mid=(low+high)/2;
	if(v==array[mid])
	{
		return mid;
	}
	else if(v>array[mid])
	{
		binary_search_R(array,v,mid+1,high);
	}
	else
	{
		binary_search_R(array,v,low,mid-1);
	}
	
}

int*subset_sum(int*array,int n,int x)
{
	merge_sort(array,0,n-1);
	int aux;//
	int indice;
	for(int i=0;i<n-1;i++)
	{
		aux=x-array[i];
		indice=binary_search_R(array,aux,i+1,n-1);
		if(indice>-1)
		{
			return (int[2]){array[i],array[indice]};
		}
	}
	return NULL;
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
      int v;
      int result;
      do{
        printf("MENU:\n\t");
        printf("0-Terminar programa\n\t");
        printf("1-Inicializar arreglo\n\t");
        printf("2-Eliminar arreglo\n\t");
        printf("3-Mostrar arreglo\n\t");
        printf("4-SubSet_Sum \n\t");
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
            if(!array)
	    {
		printf("\nArreglo Vacio\n");
	    }
	    else
	    {
		int*sss;//subsetsum
   		printf("Ingrese un numero entero:");
		scanf("%d",&v);
		sss=subset_sum(array,n,v);
		if(!sss)
		{
			printf("\n El numero %d no tiene 2 elementos en el arreglo cuya suma es igual a %d \n",v);
		}
		else
		{
			printf("\n El numero %d tiene una suma de dos elementos en el arregglo que son:[%d,%d]\n",v,sss[0],sss[1]);
		}
            }
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
