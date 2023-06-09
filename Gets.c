/*************************************************************************
** Programa: 	Gets.c							**
** Autor:	Gustavo Islas Gálvez.					**
** Fecha:	Domingo 01 de agosto de 2021.				**
** Descripción:	Reemplaza a la antigua función 'gets' con una versión	**
**		personalizada que captura carácter a carácter una	**
**		cadena de caracteres y la guarda en una zona de memoria	**
**		contigua.						**
*************************************************************************/
/* Librerías estándar de trabajo. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constantes simbólicas numéricas de trabajo. */
#define ZERO_V			0
#define ONE_V			1

/* Constantes simbólicas tipo 'carácter' de trabajo. */
#define NULL_CHARACTER		'\0'
#define CARRIAGE_RETURN		'\n'


/* Función 'getpause' que devuelve el carácter presionado como parte de la pausa solicitada. */
char getpause (const char *str_Message)
    {
        static char chr_Car=NULL_CHARACTER;

	printf("%s", str_Message);
	scanf("%*c%c", &chr_Car);

        return (chr_Car);
    }

/**************************************************************************
** Función 'gets' que devuelve una cadena de caracteres, cuyos caracteres**
** en una región contigua de memoria definida por el usuario.		 **
**************************************************************************/
char *gets(int int_nChars, char ch_ExitChar)
	{
		/* Variables de trabajo de ámbito local de la función.	*/
		char ch_OneCharGetty=NULL_CHARACTER;
		char *ptr_StringNew=NULL;
		int  int_nChar=ZERO_V;

		/* Asignar un área de memoria contigua para la cadena de caracteres.	*/
		/* Se calcula la longitud dada por 'int_nChars' más la unidad.		*/
		if ( (ptr_StringNew=(char*)malloc((int_nChars+ONE_V)*sizeof(char))) != NULL )
			{
				/* Ciclo mientras el carácter capturado sea distinto de un carácter de salida.	*/
				/* Se utiliza la notación de arreglos para el apuntador creado dinámicamente.	*/
				while ( ((ch_OneCharGetty=getchar()) != ch_ExitChar) && (int_nChar<int_nChars) )
					ptr_StringNew[int_nChar++]=ch_OneCharGetty;

				/* Colocar al final de la cadena de caracteres creada un carácter nulo.	*/
				ptr_StringNew[int_nChar]=NULL_CHARACTER;
			}

		return (ptr_StringNew);
	}


/* Función principal. */
int main()
	{
		/* Variables de trabajo para alojar la cadena y su longitud máxima. */
		char *ptr_String_New=NULL;
		int  int_n_Chars=ZERO_V;

		printf("*************************************************************\n");
		printf("** Capturar una cadena de caracteres de longitud variable. **\n");
		printf("*************************************************************\n");
		printf("Introduzca la longitud máxima de una cadena de caracteres: ");
		scanf("%d%*c", &int_n_Chars);

		/* Capturar desde el teclado la cadena de caracteres con una longitud dada.	*/
		printf("\nIntroduzca enseguida una cadena de máximo [%d] caracteres: \n", int_n_Chars);
		printf("==> ");

		/* Se captura la cadena de caracteres, carácter a carácter en un búfer dinámico. */
		ptr_String_New=gets(int_n_Chars, CARRIAGE_RETURN);
		printf("\nDirección:\t[%p].\nLongitud:\t[%d].\nCadena:\t\t[%s].\n", ptr_String_New, strlen(ptr_String_New), ptr_String_New);

		/* Pausa para terminar el programa. */
		getpause("\nEste programa ha terminado con éxito.\nPresione la tecla ENTRAR para finalizarlo...");

		return (ZERO_V);
	}
