#include<stdio.h>
#include<stdlib.h>
#define MAX 20000

void binary_sum(int*a,int*b,int*c,int n)
{
	int carry=0;
	int i;
	for(i=n-1;i>0;i--)
	{
		c[i+1]=(a[i]+b[i]+carry)%2;
		if(a[i]+b[i]+carry>=2)
		{
			carry=1;
		}
		else
		{
			carry=0;
		}
	}
	c[i]=carry;
}

void inicializar(int*array,int n)
{
  int i;  
  printf("\nInicializar arreglo de numeros binarios\n");
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
    printf("%d",array[i]);
  }
  printf("\n");
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
      int*a=NULL;
      int*b=NULL;
      int*c=NULL;
      int op;//opcion del menu
      do{
        printf("MENU:\n\t");
        printf("0-Terminar programa\n\t");
        printf("1-Inicializar Numeros A y B:\n\t");
        printf("2-Eliminar Numeros A,B y C:\n\t");
        printf("3-Mostrar Numeros A y B:\n\t");
        printf("4-Binary_Sum:\n\t");
        printf("Ingreso opcion:");
        scanf("%d",&op);
        switch(op)
        {
          case 0:
            free(a);
	    free(b);
	    free(c);
            printf("\nFin del Programa\n");
            break;
          case 1:
            if(!a && !b)
            {
              a=(int*) malloc(n*sizeof(int));
	      b=(int*) malloc(n*sizeof(int));
	      printf("Numero binario A (Right-Left):\n");
              inicializar(a,n);
	      printf("Numero binario B (Right-Left):\n");
	      inicializar(b,n);
            }
            else
            {
              printf("\nLos arreglos ya esta inicializado\n");
            }
            break;
          case 2:
            free(a);
	    free(b);
	    free(c);
            a=NULL;
	    b=NULL;
	    c=NULL;
            break;
          case 3:
            if(!a && !b)
            {
              printf("\n Numeros no inicializados (Arreglos) \n");
            }
            else
            {
	      printf("\nNumero binario A:\n");
              mostrar(a,n);
              printf("\nNumero binario B:\n");
              mostrar(b,n);
            }
            break;
          case 4:
            if(!a && !b)
	    {
		printf("\nA y B no Inicializados\n");
	    }
	    else
	    {
   		c=(int*) malloc((n+1)*sizeof(int));
		binary_sum(a,b,c,n);
		printf("\nEl numero c es igual a:");
		mostrar(c,n+1);
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
