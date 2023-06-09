/*************************************************************************
** Programa:	Hanoi.c							**
** Autor:	Gustavo Islas Gálvez.					**
** Fecha:	Viernes 09 de Junio de 2023.				**
** Descripción:	Este programa realiza las iteraciones necesarias	**
** 		para desplazar determinado número de discos de un pilar	**
**		hacia otro siguiendo el algoritmo del enigma de las	**
** 		Torres de Hanoi.					**
**************************************************************************/
/* Librerías estándar de trabajo. */
#include <stdio.h>

/* Constantes simbólicas numéricas de trabajo. */
#define ZERO_V		0
#define ONE_V		1
#define TWO_V		2
#define ONE_HUNDRED_V	100

/* Constantes simbólicas tipo carácter de trabajo. */
#define NULL_CHARACTER	'\0'
#define FIRST_TOWER	'A'
#define SECOND_TOWER	'B'
#define THIRD_TOWER	'C'

/* Máxima cantidad de platillos en los pilares de las Torres de Hanoi. */
#define MAX_DISHES	28

/* Función 'potency' que devuelve un número elevado a
   a determinada potencia */
long potency(int int_x, int int_y)
	{
		long ret=ONE_V;

		for (int i=ZERO_V; i<int_y; i++)
			ret*=int_x;

		return ret;
	}


/* Función 'getpause' que devuelve el carácter presionado como parte de
   la pausa solicitada. */
char getpause (const char *str_Message)
    {
        static char chr_Car=NULL_CHARACTER;

	printf("%s", str_Message);
	scanf("%*c%c", &chr_Car);

        return (chr_Car);
    }

/* Función 'lng_HanoiTowers' para realizar y contabilizar las iteraciones
   de los discos entre las torres. */
long lng_HanoiTowers(const char n_ch_dishes,
		 const char ch_first_tower,
		 const char ch_second_tower,
		 const char ch_third_tower,
		 const long lng_n_maximum_cycles)
	{
		/* El movimiento de los aros empieza con tres torres,
		   numeradas de la primera (1ª) a la tercera (3ª)
		   y se contabilizan sus ciclos. */
		static long lng_n_loops_HanoiTowers=ZERO_V;
		float flt_perc_advantage=ZERO_V;

		/* Contabilizar el número de ciclos y su porcentaje que
		   se llevan de los cálculos de las Torres de Hanoi. */
		lng_n_loops_HanoiTowers++;
		flt_perc_advantage = (	(float) lng_n_loops_HanoiTowers /
					(float) (lng_n_maximum_cycles-ONE_V) )
							  * ONE_HUNDRED_V;

		/* Se valida para las recursiones si el número de discos
		   siempre es mayor de la unidad y menor
		   al máximo de ciclos calculados. */
		if (n_ch_dishes > ONE_V && lng_n_loops_HanoiTowers < lng_n_maximum_cycles)
			{
				/* -----------------------------------------------------*/
				/* Se invierten las astas de las que se van a extraer	*/
				/* los aros, ahora es de la 1ª, la 3ª y la 2ª.		*/
				/* -----------------------------------------------------*/
				lng_HanoiTowers(n_ch_dishes-ONE_V,
						ch_first_tower,
						ch_third_tower,
						ch_second_tower,
						lng_n_maximum_cycles);

				/* -----------------------------------------------------*/
				/* Este mensaje se imprime mientras haya aros encima	*/
				/* del asta actual a movilizarse.			*/
				/* -----------------------------------------------------*/
				printf("Movimiento: [%ld] de [%ld]. [%3.2f]%% realizado. Se traslada el aro [%2d] del asta [%c] al asta [%c]. \r",
					lng_n_loops_HanoiTowers,
					lng_n_maximum_cycles-ONE_V,
					flt_perc_advantage,
					n_ch_dishes,
					ch_first_tower,
					ch_third_tower);

				/* -----------------------------------------------------*/
				/* Se invierten las astas de las que se van a extraer	*/
				/* los aros, ahora es de la 2ª, la 1ª y la 3ª.		*/
				/* -----------------------------------------------------*/
				lng_HanoiTowers(n_ch_dishes-ONE_V,
						ch_second_tower,
						ch_first_tower,
						ch_third_tower,
						lng_n_maximum_cycles);
			}

		/* Este mensaje se imprime si se llegó al último aro del
		   bloque que se desea mover desde un asta específica. */
		printf("Movimiento: [%ld] de [%ld]. [%3.2f]%% realizado. Se traslada el aro [%2d] del asta [%c] al asta [%c]. \r",
			lng_n_loops_HanoiTowers,
			lng_n_maximum_cycles-ONE_V,
			flt_perc_advantage,
			n_ch_dishes,
			ch_first_tower,
			ch_third_tower);

		return (lng_n_loops_HanoiTowers);
	}


/* Programa Principal que desplaza los platillos entre las astas
   que componen el algoritmo del enigma de las Torres de Hanoi. */
int main()
    {
		/* Declaración de variables. */
		char n_ch_dishes=ZERO_V;
		long lng_n_loops_HanoiTowers=ZERO_V;
		long lng_n_maximum_cycles_HanoiTowers=ZERO_V;

   		printf("****************************************************\n");
		printf("**  Algoritmo para resolver las Torres de Hanoi.  **\n");
   		printf("****************************************************\n");
		printf("Número de aros a desplazar [%d-%d]: ", ONE_V, MAX_DISHES);
   		scanf("%d%*c", &n_ch_dishes);

		/* Se valida que el número de discos esté en un rango
		   permisible y tolerable por el procesador. */
		if (n_ch_dishes>=ONE_V && n_ch_dishes<=MAX_DISHES)
			{
				/* Se determina el número máximo de ciclos del procesador
				   para resolver las Torres de Hanoi con 'n' discos. */
				lng_n_maximum_cycles_HanoiTowers=potency(TWO_V,n_ch_dishes); //(2^N)

				/* Se avisa en pantalla la cantidad de movimientos que se
				   requieren para trasladar los distintos discos. */
				printf("Se necesitan [%ld] movimientos para resolver\n"
					"el enigma de las Torres de Hanoi con [%d] discos.\n",
					lng_n_maximum_cycles_HanoiTowers-ONE_V,
					n_ch_dishes);
				getpause("Presione la tecla ENTRAR para comenzar el programa...");

				/* ---------------------------------------------------- */
				/* Se llama a la función 'HanoiTowers' y se devuelve	*/
				/* como resultado el número de ciclos para resolverlas. */
				/* -----------------------------------------------------*/
				lng_n_loops_HanoiTowers=lng_HanoiTowers(n_ch_dishes,
									FIRST_TOWER,
									SECOND_TOWER,
									THIRD_TOWER,
									lng_n_maximum_cycles_HanoiTowers);

				/* Se visualiza en pantalla cuántos movimientos efectivos
				   se realizaron con el número de discos especificado. */
				printf("\n[%ld] movimientos realizados para resolver\n"
					"el enigma de las Torres de Hanoi y\n"
					"[%d] discos desplazados.\n",
					lng_n_loops_HanoiTowers,
					n_ch_dishes);
			}
		else
			/* El valor introducido está fuera del rango permitido.
			   Mientras más discos, mayor es la probabilidad
			   de que nunca termine el proceso del algoritmo. */
			printf("El valor introducido [%d] está fuera del rango permitido.\n"
				"Sólo se permiten desde [%d] hasta [%d] discos. \n",
					 n_ch_dishes, ONE_V, MAX_DISHES);

		/* Pausa para terminar el programa. */
		getpause("\nEste programa ha terminado con éxito.\n"
			"Presione la tecla ENTRAR para finalizarlo...");

    	return(lng_n_maximum_cycles_HanoiTowers);
    }
