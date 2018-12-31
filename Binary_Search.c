#include<stdio.h>
#include<stdlib.h>
#define MAX 20000

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

int binary_search_I(int*array,int v,int low,int high)
{
	int mid;
	while(low<=high)
	{
		mid=(low + high)/2;
		if(v==array[mid])
		{
			return mid;
		}
		else if(v>array[mid])
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return -1;
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
        printf("4-Binary_Search Iterativo (Arreglo debe estar ordenado)\n\t");
	printf("5-Binary_Search Recursivo (Arreglo debe estar ordenado)\n\t");
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
   		printf("Ingrese el numero entero que desea buscar:");
		scanf("%d",&v);
		result=binary_search_I(array,v,0,n-1);
		if(result==-1)
		{
			printf("\n El numero %d no esta en el arreglo \n",v);
		}
		else
		{
			printf("\n El numero %d esta en el arreglo en la posicion:%d\n",v,result+1);
		}
            }
            break;
	  case 5:
            if(!array)
	    {
		printf("\nArreglo Vacio\n");
	    }
	    else
	    {
   		printf("Ingrese el numero entero que desea buscar:");
		scanf("%d",&v);
		result=binary_search_R(array,v,0,n-1);
		if(result==-1)
		{
			printf("\n El numero %d no esta en el arreglo \n",v);
		}
		else
		{
			printf("\n El numero %d esta en el arreglo en la posicion:%d\n",v,result+1);
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
