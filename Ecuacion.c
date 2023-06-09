/*************************************************************************
** Programa: 	Ecuación.c						**
** Autor:	Gustavo Islas Gálvez.					**
** Fecha:	Domingo 01 de agosto de 2021.				**
** Descripción:	Solución de una ecuación de segundo grado dados sus	**
**		coeficientes.						**
*************************************************************************/
/* Librerías de uso estándar */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Constantes simbólicas de trabajo. */
#define ZERO_V		0
#define TWO_V		2
#define FOUR_V		4

/* Constante simbólica de tipo 'carácter'. */
#define NULL_CHARACTER	'\0'


/* Función 'getpause' que devuelve el carácter presionado como parte de la pausa solicitada. */
char getpause (const char *str_Message)
    {
        static char chr_Car=NULL_CHARACTER;

	printf("%s", str_Message);
	scanf("%*c%c", &chr_Car);

        return (chr_Car);
    }


/* Programa Principal que obtiene las raíces de una ecuación de segundo grado. */
int main()
	{
		/* Definición de los coeficientes de la ecuación cuadrática o de segundo grado. */
		double a=ZERO_V, b=ZERO_V, c=ZERO_V;
		double d=ZERO_V, x1=ZERO_V, x2=ZERO_V;

		/* Entrada de datos. */
		printf("********************************************************************************\n");
		printf("** Solución de una ecuación de segundo grado por medio de la fórmula general. **\n");
		printf("********************************************************************************\n");
		printf("Introducir los coeficientes <a> <b> <c> separados por espacios en blanco: ");
		scanf("%lf %lf %lf", &a, &b, &c);

		/* Comprobar si las raíces son reales a través de la fórmula general. */
		if ( (d=pow(b,TWO_V)-FOUR_V*a*c) >= ZERO_V )
			{
				/* Mostrar las raíces obtenidas de la ecuación de segundo grado. */
				printf("\n");
				printf("Las raíces reales de la ecuación son:\n");
				printf("+----|----+----|----+----|----+----|----+\n");

				/* Cálculo de las soluciones aplicando la raíz cuadrada. */
				d=sqrt(d);

				/* Primera y segunda raíces obtenidas de la ecuación cuadrática. */
				x1=(-b+d)/(TWO_V*a);
				x2=(-b-d)/(TWO_V*a);

				/* Escribir los resultados obtenidos de la ecuación de segundo grado. */
				printf("Valor de comprobación <d>=[%lf].\n", d);
				printf("+----|----+----|----+----|----+----|----+\n");
				printf("x1=[%g].\n", x1);
				printf("x2=[%g].\n", x2);
			}
		else
			{
				/* Los coeficientes de la ecuación cuadrática dan una raíz compleja. */
				printf("\n");
				printf("Valor de comprobación <d>=[%lf].\n", d);
				printf("+----|----+----|----+----|----+----|----+\n");
				printf("La solución de las raíces tiene lugar en los números complejos.\n");
			}

		/* Pausa para terminar el programa. */
		getpause("\nEste programa ha terminado con éxito.\nPresione la tecla ENTRAR para finalizarlo...");

		return (ZERO_V);
	}
