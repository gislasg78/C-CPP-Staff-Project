/**************************************************************************************************
 * Programa:    Letras.c									***
 * Autor:       Gustavo Islas Gálvez.								***
 * Fecha:       Domingo 01 de agosto de 2021.							***
 * Descripción: Este programa cuenta todas las letras que ingresen por teclado y  determina	***
 *		la frecuencia de las letras mayúsculas y minúsculas de un texto especificado.	***
 *************************************************************************************************/
/* Librería estándar de entrada y salida de C. */
#include <stdio.h>

/* Definición de constantes simbólicas de trabajo. */
#define N_ELEMENTS		('z'-'a')+1+('Z'-'A')+1	/* Número total de elementos del array. */
#define LOWERBOUND_UPPERCASES	'A'			/* Límite inferior de las mayúsculas.	*/
#define UPPERBOUND_UPPERCASES	'Z'			/* Límite superior de las mayúsculas.	*/
#define LOWERBOUND_LOWERCASES	'a'         		/* Límite inferior de las minúsculas.	*/
#define UPPERBOUND_LOWERCASES	'z'			/* Límite superior de las minúsculas.	*/
#define NULL_CHARACTER		'\0'		/* Carácter nulo para inicializar el arreglo.	*/
#define CARRIAGE_RETURN		'\n'	/* Carácter de retorno de carro más avance de línea.	*/

/* Definición de constantes simbólicaas numéricas de trabajo. */
#define ZERO_VALUE		0			/* Valor cero, por defecto.		*/
#define ONE_VALUE		1			/* Valor de la unidad, complementaria.	*/
#define EIGHT_VALUE		8			/* Valor ocho, complementario.		*/


/* Función 'getpause' que devuelve el carácter presionado como parte de la pausa solicitada. */
char getpause (const char *str_Message)
    {
        static char chr_Car=NULL_CHARACTER;

	printf("%s", str_Message);
	scanf("%*c%c", &chr_Car);

        return (chr_Car);
    }

/*************************************************************************************************/
/* Procedimiento 'getArrayCar' que captura una línea de caracteres y la almacena en un arreglo.	 */
/*************************************************************************************************/
int getArrayCar (char array_car[])
	{
		char idx_array_car=ZERO_VALUE;		/* índice carácter para el array de caracteres.	*/
		int  int_Counter_Array_Cars=ZERO_VALUE;	/* Contador del número de caracteres.	*/

		while ( (idx_array_car=getchar()) != CARRIAGE_RETURN )
		/* Si el carácter leído está entre los rangos de la 'A' y la 'Z' y la 'a' y la 'z',
		** incrementar y empatar el índice correspondiente. */
			{
				/* Para empatar del ASCII 065 al 090 le corresponden las posiciones 000 a 025. */
				if (idx_array_car >= LOWERBOUND_UPPERCASES && idx_array_car <= UPPERBOUND_UPPERCASES)
					{
						int_Counter_Array_Cars++;
						array_car[idx_array_car-LOWERBOUND_UPPERCASES]++;
					}

				/* Para empatar del ASCII 097 al 122 le corresponden las posiciones 026 a 051.*/
				if (idx_array_car >= LOWERBOUND_LOWERCASES && idx_array_car <= UPPERBOUND_LOWERCASES)
					{
						int_Counter_Array_Cars++;
						array_car[idx_array_car-LOWERBOUND_LOWERCASES+UPPERBOUND_LOWERCASES-LOWERBOUND_LOWERCASES+ONE_VALUE]++;
					}
			}

		return (int_Counter_Array_Cars);
	}

/*************************************************************************************************/
/* Función 'viewArrayCar' que visualiza el arreglo de caracteres y su respectiva contabilización.*/
/*************************************************************************************************/
void viewArrayCar(char array_car[])
	{
		char idx_array_car=NULL_CHARACTER;	/* índice para el arreglo de caracteres. */

		/* Mensaje de la tabla de frecuencias a visualizar en pantalla. */
		printf("\nTablas de distribución de frecuencias:\n");

		/**---------------------------------------------------------------------------------------------**/
		/** Marquesina inicial de apertura para visualizar las tablas de distribución de frecuencias.	**/
		/**---------------------------------------------------------------------------------------------**/
		/* Visualizar una marquesina inicial para mejorar la visualización de las tablas de frecuencias. */
		for (idx_array_car=ZERO_VALUE; idx_array_car<EIGHT_VALUE; idx_array_car++)
			printf("+====|====");


		/*************************************************************************************************/
		/* Visualizar en pantalla la tabla de distribución de frecuencias de las Letras Mayúsculas.	**/
		/*************************************************************************************************/
		/* Avance de línea. */
		printf("\n");

		/* Letras MAYÚSCULAS. */
		printf("\nLetras Mayúsculas:\n");

		/* Visualizar una regleta para mejorar la visualización de la tabla de frecuencias.	*/
		for (idx_array_car=ZERO_VALUE; idx_array_car<EIGHT_VALUE; idx_array_car++)
			printf("+----|----");

		/* Avance de línea. */
		printf("\n");

		/* Volcar en pantalla las Letras Mayúsculas. */
		for (idx_array_car=LOWERBOUND_UPPERCASES; idx_array_car<=UPPERBOUND_UPPERCASES; idx_array_car++)
			printf("  %c", idx_array_car);

		/* Avance de línea. */
		printf("\n");

		/* Visualizar una regleta para mejorar la visualización de la tabla de frecuencias.	*/
		for (idx_array_car=ZERO_VALUE; idx_array_car<EIGHT_VALUE; idx_array_car++)
			printf("+----|----");

		/* Avance de línea. */
		printf("\n");

		/* Escribir la tabla de distribución de frecuencias de las Letras Mayúsculas.		*/
		for (idx_array_car=LOWERBOUND_UPPERCASES; idx_array_car<=UPPERBOUND_UPPERCASES; idx_array_car++)
			printf("%3d", array_car[idx_array_car-LOWERBOUND_UPPERCASES]);

		/* Avance de línea. */
		printf("\n");

		/* Visualizar una regleta para mejorar la visualización de la tabla de frecuencias.	*/
		for (idx_array_car=ZERO_VALUE; idx_array_car<EIGHT_VALUE; idx_array_car++)
			printf("+----|----");

		/* Avance de línea. */
		printf("\n");


		/*************************************************************************************************/
		/* Visualizar en pantalla la tabla de distribución de frecuencias de las letras minúsculas.	**/
		/*************************************************************************************************/
		/* Avance de línea. */
		printf("\n");

		/* Letras minúsculas. */
		printf("Letras minúsculas:");

		/* Avance de línea. */
		printf("\n");

		/* Visualizar una regleta para mejorar la visualización de la tabla de frecuencias.	*/
		for (idx_array_car=ZERO_VALUE; idx_array_car<EIGHT_VALUE; idx_array_car++)
			printf("+----|----");

		/* Avance de línea. */
		printf("\n");

		/* Volcar en pantalla las letras minúsculas. */
		for (idx_array_car=LOWERBOUND_LOWERCASES; idx_array_car<=UPPERBOUND_LOWERCASES; idx_array_car++)
			printf("  %c", idx_array_car);

		/* Avance de línea. */
		printf("\n");

		/* Visualizar una regleta para mejorar la visualización de la tabla de frecuencias.	*/
		for (idx_array_car=ZERO_VALUE; idx_array_car<EIGHT_VALUE; idx_array_car++)
			printf("+----|----");

		/* Avance de línea. */
		printf("\n");

		/* Escribir la tabla de distribución de frecuencias de las letras minúsculas.		*/
		for (idx_array_car=LOWERBOUND_LOWERCASES; idx_array_car<=UPPERBOUND_LOWERCASES; idx_array_car++)
			printf("%3d", array_car[idx_array_car-LOWERBOUND_LOWERCASES+UPPERBOUND_LOWERCASES-LOWERBOUND_LOWERCASES+ONE_VALUE]);

		/* Avance de línea. */
		printf("\n");

		/* Visualizar una regleta para mejorar la visualización de la tabla de frecuencias.	*/
		for (idx_array_car=ZERO_VALUE; idx_array_car<EIGHT_VALUE; idx_array_car++)
			printf("+----|----");

		/* Avance de línea. */
		printf("\n");

		/**---------------------------------------------------------------------------------------------**/
		/** Marquesina final de cierre para visualizar las tablas de distribución de frecuencias.	**/
		/**---------------------------------------------------------------------------------------------**/
		/* Avance de línea. */
		printf("\n");

		/* Visualizar una marquesina final para mejorar la visualización de las tablas de frecuencias. */
		for (idx_array_car=ZERO_VALUE; idx_array_car<EIGHT_VALUE; idx_array_car++)
			printf("+====|====");

		/* Avance de línea. */
		printf("\n");

	}


/*****************************************************************************************************************/
/* Programa principal que se encarga de contar las letras minúsculas y empatarlas con un arreglo.		**/
/*****************************************************************************************************************/
int main()
	{
		/* Inicialización de valores en su declaración para el programa de captura de letras.		*/
		static char	array_car[N_ELEMENTS]={ZERO_VALUE};	/* array de caracteres tipo 'car'.	*/
		char		ch_idx_array_car=NULL_CHARACTER;	/* índice para el arreglo de tipo 'car'.*/

		/* Entrada de datos, cálculo y visualización de la tabla de frecuencias. */
		printf("**********************************************************************************\n");
		printf("**   Programa que contabiliza caracteres alfabéticos 'A'-'Z' y de la 'a'-'z'.   **\n");
		printf("**********************************************************************************\n");
		printf("Introduzca letras o texto. Para finalizar este programa, presione la tecla ENTRAR.\n");
		printf("=> ");
		printf("\n[%d] caracteres alfabéticos capturados en una misma línea.\n", getArrayCar(array_car));

		/* Visualizar los conteos realizados de los caracteres alfabéticos obtenidos. */
		viewArrayCar(array_car);

		/* Desplegar el tamaño del arreglo generado y el número de elementos disponibles */
		printf("\n");
		printf("Tamaño del índice de caracteres:\t\t[%3d].\n", sizeof(ch_idx_array_car));
		printf("Tamaño de un carácter en este equipo:\t\t[%3d].\n", sizeof(char));
		printf("Tamaño del arreglo de caracteres:\t\t[%3d].\n", sizeof(array_car));
		printf("Número de elementos del arreglo de caracteres:\t[%3d].\n", sizeof(array_car)/sizeof(char));

		/* Pausa para terminar el programa. */
		getpause("\nEste programa ha terminado con éxito.\nPresione la tecla ENTRAR para finalizarlo...");

		return(ZERO_VALUE);
	}
