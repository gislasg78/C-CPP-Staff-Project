/*************************************************************************
** Autor:	Gustavo Islas Gálvez.					**
** Fecha:	Domingo 01 de agosto de 2021.				**
** Programa:	Fourier.c						**
** Descripción: Calcula la Transformada Discreta de Fourier para una	**
**		serie de números reales (de punto flotante) dados.	**
*************************************************************************/
/* Librerías estándares de trabajo. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Definición de constantes simbólicas de trabajo. */
#define ZERO_V		0
#define ONE_V		1
#define TWO_V		2
#define NULL_CHARACTER	'\0'


/* Función 'getpause' que devuelve el carácter presionado como parte de la pausa solicitada. */
char getpause (const char *str_Message)
    {
        static char chr_Car=NULL_CHARACTER;

	printf("%s", str_Message);
	scanf("%*c%c", &chr_Car);

        return (chr_Car);
    }

/* Estructura de datos para un tipo definido de un número complejo determinado. */
typedef struct
	strct_ComplexNumber
	{
          double real=ZERO_V,
		 imag=ZERO_V;
	} tpydf_strct_ComplexNumber;


/* Función 'addComplexNumbers' que adiciona números complejos determinados. */
tpydf_strct_ComplexNumber addComplexNumbers(tpydf_strct_ComplexNumber a, tpydf_strct_ComplexNumber b)
	{
		tpydf_strct_ComplexNumber goal_ComplexNumber;

		goal_ComplexNumber.real = a.real + b.real;
		goal_ComplexNumber.imag = a.imag + b.imag;

		return (goal_ComplexNumber);
	}

/* Función 'multiplyComplexNumbers' que multiplica números complejos determinados. */
tpydf_strct_ComplexNumber multiplyComplexNumbers(tpydf_strct_ComplexNumber a, tpydf_strct_ComplexNumber b)
	{
		tpydf_strct_ComplexNumber goal_ComplexNumber;

		goal_ComplexNumber.real = a.real * b.real - a.imag * b.imag;
		goal_ComplexNumber.imag = a.real * b.imag + a.imag * b.real;

		return (goal_ComplexNumber);
	}

/* Procedimiento 'getDFT' que captura desde el teclado cada elemento que compone el arreglo de números reales. */
void getDFT(tpydf_strct_ComplexNumber *X, double *x, int N)
	{
		int n=ZERO_V;

		for (n=ZERO_V; n<N; n++)
			{
				/* Se realiza una inicialización preventiva por elemento. */
				x[n]=ZERO_V;

				/* Solicitud de captura de cada valor del arreglo de números reales. */
				printf("Valor real de punto flotante a introducir #[%d] de [%d]: ", n+ONE_V, N);
				scanf("%lf", &x[n]);
			}
	}

/* Procedimiento 'doDFT' para obtener la Transformada Discreta de FOURIER. */
void doDFT(tpydf_strct_ComplexNumber *X, double *x, int N)
	{
		/* Declaración de variables de ámbito local. */
		int 	n=ZERO_V, k=ZERO_V;
		double 	t=ZERO_V;
		tpydf_strct_ComplexNumber a, b;

		/* Ciclos para el cálculo de cada valor real obtenido en el arreglo capturado de números reales. */
		for (k=ZERO_V; k<N; k++)
			{
				X[k].real=ZERO_V;
				X[k].imag=ZERO_V;

				for (n=ZERO_V; n<N; n++)
					{
						/* El real de 'tpydf_strct_ComplexNumber' es el real pasado como argumento actual */
						a.real=x[n];
						a.imag=ZERO_V;

						/* El valor 'k' se multiplica por 2, por PI y dicho resultado se divide
						   entre el producto de N x n. */
						t=k*TWO_V*M_PI/N*n;

						/* El nuevo 'tpydf_strct_ComplexNumber' tiene como real el coseno '-t' y
						   en el imaginario el seno '-t'.*/
						b.real=cos(-t);
						b.imag=sin(-t);

						/* Multiplicación y sumatoria de los números 'tpydf_strct_ComplexNumbers' obtenidos. */
						b=multiplyComplexNumbers(a,b);
						X[k]=addComplexNumbers(X[k], b);
					}
			}
	}

/* Función viewDFT que visualiza en pantalla los resultados de los cálculos obtenidos de la Transformada. */
void viewDFT(tpydf_strct_ComplexNumber *X, double *x, int N)
	{
		int n=ZERO_V;

		/* Imprimir en pantalla los resultados obtenidos del cálculo con los números reales. */
		printf("\n");
		printf("Resultados:\n");
		printf("+----|----+----|----+----|----+----|----+----|----+----|----+----|\n");

		/* Visualizar en pantalla propiamente los resultados de los arreglos calculados. */
		for (n=ZERO_V; n<N; n++)
			printf("Valor #[%d] de [%d] \t Capturado: [%8.4lf] \t Real: [%8.4g] \t Imaginario: [%+8.4g] \t <j> \n", n+ONE_V, N, x[n], X[n].real, X[n].imag);

	}


/* Programa Principal de la Transformada Discreta de Fourier. */
int main()
	{
		/* Variables de trabajo de ámbito local en el programa principal. */
		tpydf_strct_ComplexNumber *X=NULL;

		double	*x=NULL;
		int	N=ZERO_V;
		int	int_exit_CODE=ZERO_V;

		/* Mensajes principales de pantalla de presentación de este programa. */
		printf("*****************************************************************\n");
		printf("** Programa para calcular la Transformada Discreta de Fourier. **\n");
		printf("*****************************************************************\n");
		printf("¿Cuántos valores reales desea introducir?: ");
		scanf("%d", &N);

		/* Asignar memoria para el arreglo de números tpydf_strct_ComplexNumbers 'X'. */
		if ( (X = (tpydf_strct_ComplexNumber *) malloc(N * sizeof(tpydf_strct_ComplexNumber)) ) != NULL )
			{
				/* Asignar memoria para el arreglo (vector) que almacenará la secuencia de números reales 'x'. */
				if ( (x = (double *) malloc(N * sizeof(double)) ) != NULL )
					{
						/*****************************************************************************/
						/* Bloque de sentencias que generan los arreglos, su captura y sus cálculos. */
						/*****************************************************************************/
						/* Introducir la secuencia de números reales contenida en el arreglo del mismo tipo 'x'. */
						getDFT(X, x, N);

						/* Calcular la transformada discreta de Fourier y devolverla en el arreglo complejo 'X'. */
						doDFT(X, x, N);

						/* Mostrar en pantalla los resultados obtenidos de la Transformada Discreta de Fourier. */
						viewDFT(X, x, N);
					}
				else
					{
						getpause("\nInsuficiente memoria para asignación del arreglo a capturar de números reales.\nPresione ENTRAR para finalizar...");
						int_exit_CODE=TWO_V;
					}
			}
		else
			{

				getpause("\nInsuficiente memoria para asignación del arreglo a calcular de números 'tpydf_strct_ComplexNumbers'.\nPresione ENTRAR para finalizar...");
				int_exit_CODE=ONE_V;
			}


		/* Hacer una pausa y presionar la tecla ENTRAR para continuar si el programa terminó satisfactoriamente. */
		if (int_exit_CODE==ZERO_V)
			/* Pausa para terminar el programa. */
			getpause("\nEste programa ha terminado con éxito.\nPresione la tecla ENTRAR para finalizarlo...");

		/* Finalización por código de salida para este programa. */
		return(int_exit_CODE);
	}
