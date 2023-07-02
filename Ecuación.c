/****** Calcular las raíces de una ecuación de segundo grado. *****/
#include <stdio.h>
#include <math.h>

#define DENOMINATOR(c_a)		( 2 * (a) )
#define DISCRIMINATE(c_a, c_b, c_c)	( ( (b) * (b) ) - ( 4 * (a) * (c) ) )
#define SINGLE_ROOT(c_a, c_b)		( (-b) / ( 2 * (a) ) )
#define UNIQUE_ROOT(c_b, c_c)		( (-c) / (b) )
#define V_ZERO  0

//Módulo principal.
int main (int argc, char *argv[])
	{
		double a=V_ZERO, b=V_ZERO, c=V_ZERO;
		double d=V_ZERO;
		double re=V_ZERO, im=V_ZERO;

		printf("+---+----+---+----+---+----+---+----+---\n");
		printf("| Solución de una ecuación cuadrática. |\n");
		printf("+---+----+---+----+---+----+---+----+---\n");
		printf("Coeficiente 'a' : ");
		scanf("%lf", &a);
		printf("Coeficiente 'b' : ");
		scanf("%lf", &b);
		printf("Coeficiente 'c' : ");
		scanf("%lf", &c);

		printf("\n");

		//Si 'a' es igual a cero, el tratamiento o es de degeneración o de raíz única.
		if (a==V_ZERO)
			if (b==V_ZERO)
				printf("La ecuación está degenerada.\n") ;
			else
				printf("La única raíz posible es: [%1f].\n", UNIQUE_ROOT(b, c));
		else
			{
				//Cálculos preliminares para validación.
				re = SINGLE_ROOT(a, b);     //Valor real obtenido.
				d = DISCRIMINATE(a, b, c);  //Discriminante o determinante.
				im = sqrt(fabs(d)) / DENOMINATOR(a);

				//Validar discriminante sí y sólo si 'a' es distinto de cero.
				printf("Discriminante 'd' : [%lf].\n\n", d);

				//Sólo se valida el determinante sí y sólo si 'a' es distinto de cero.
				//Si el determinante es mayor que o igual a cero, sus raíces son reales.
				if (d >= V_ZERO)
					{
						printf ("Raíces reales:\n");
						printf ("'x1' = [%lf].\n", re + im);
						printf ("'x2' = [%lf].\n", re - im);
					}

			        //Si el determinante es menor que cero, sus raíces son complejas.
				if (d < V_ZERO)
					{
						printf ("Raíces complejas:\n");
						printf ("'x1' = Real: [%lf]. Imaginario: +[%lf]'i'.\n", re, fabs(im));
						printf ("'x2' = Real: [%lf]. Imaginario: -[%lf]'i'.\n", re, fabs(im));
					}
			}

		return V_ZERO;
	}
