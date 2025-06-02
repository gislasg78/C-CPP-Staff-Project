#include <stdio.h>
#include <stdarg.h> //For the functions: va_list, va_start, va_arg, va_end
#include <stdlib.h> //For the use of the functions: 'malloc' and 'free'.

/* Symbolic work constants. */
#define	V_TWO	2
#define	V_ONE	1
#define	V_ZERO	0

/* Type definitions for clearer usage (optional but useful) */
typedef void* (*va_arg_ptr_type)(va_list);	//This is more complex than necessary here.

//Enumeration with type entry variables and its reseting.
enum enm_type_entry
	{
		enm_type_entry_char = V_ONE,
		enm_type_entry_double,
		enm_type_entry_float,
		enm_type_entry_int,
		enm_type_entry_long,
		enm_type_entry_short
	} enm_type_value;

/*****************************************************************
 ** Function:		void *void_my_addition			**
 **				(enum enm_type_entry		**
 **					enm_type_value, ...)	**
 **								**
 ** Explanation:	Function to add a variable number of	**
 **			arguments of type 'void *' that are	**
 **			passed as formal parameters to this	**
 **			function.				**
 **								**
 ** Parameters:							**
 **			'enm_type_entry': Receives an		**
 **			enumerated type indicating		**
 **			the data type of the subsequent		**
 **			arguments:				**
 **								**
 **			- A variable number of pointers of type **
 **			'void' pointing to the values ​​to be	**
 **			added. It is assumed, by default, that	**
 **			all pointers of type 'void' will be	**
 **			converted to the same type.		**
 **								**
 **			- The list must be terminated with a	**
 **			NULL pointer to indicate the end of the	**
 **			list of formal parameters to this	**
 **			function.				**
 ** Input Parms:	enum enm_type_entry enm_type_value.	**
 ** Output Parms:	Variable arguments of the type (void *)	**
 ** Result:		- Returns:				**
 **			A pointer of type 'void' pointing	**
 **			to the result of the addition.		**
 **			The result is dynamically stored in	**
 **			memory, so the caller of this function	**
 **			is responsible for freeing it with the	**
 **			'free()' instruction.			**
 **								**
 **			Returns NULL if there is an error in	**
 **			the chosen option or in the dynamic	**
 **			memory allocation.			**
 ****************************************************************/
void *void_my_addition(enum enm_type_entry enm_type_value, ...)
	{
		/* Preliminary working variables. */
		va_list args_list;
		void *result_ptr = NULL;	//Pointer of type 'void *' to store the dynamically created result.

		/* Initializes the argument list, 'data_type' is the last fixed argument. */
		va_start(args_list, enm_type_value);

		/* Confirm the type of value you intend to convert from the type of variable sent. */
		switch (enm_type_value)
			{
				/* Verification of summation of 'char' types. */
				case enm_type_entry_char:
					{
						/* Transient double work variables. */
						char chr_summation = V_ZERO;
						char *current_val_ptr = NULL;

						/* Iterates until a NULL pointer is found (sentinel). */
						while ((current_val_ptr = va_arg(args_list, char *)))
							{
								chr_summation += *current_val_ptr; //Dereferences and adds the resulting char value.
							}

						/* Allocates dynamic memory for the obtained result and copies it into a 'void' type pointer. */
						if ((result_ptr = malloc(sizeof(char))))
							{
								*((char *) result_ptr) = chr_summation;
							}
						else
							{
								fprintf(stderr, "Fatal error! Dynamic memory could not be allocated to store the result of the char addition.\n");
							}
					}
					break;

				/* Verification of summation of 'double' types. */
				case enm_type_entry_double:
					{
						/* Transient double work variables. */
						double dbl_summation = V_ZERO;
						double *current_val_ptr = NULL;

						/* Iterates until a NULL pointer is found (sentinel). */
						while ((current_val_ptr = va_arg(args_list, double *)))
							{
								dbl_summation += *current_val_ptr; //Dereferences and adds the resulting double value.
							}

						/* Allocates dynamic memory for the obtained result and copies it into a 'void' type pointer. */
						if ((result_ptr = malloc(sizeof(double))))
							{
								*((double *) result_ptr) = dbl_summation;
							}
						else
							{
								fprintf(stderr, "Fatal error! Dynamic memory could not be allocated to store the result of the double addition.\n");
							}
					}
					break;

				/* Verification of summation of 'floating point' types. */
				case enm_type_entry_float:
					{
						/* Transient floating point work variables. */
						float flt_summation = V_ZERO;
						float *current_val_ptr = NULL;

						/* Iterates until a NULL pointer is found (sentinel). */
						while ((current_val_ptr = va_arg(args_list, float *)))
							{
								flt_summation += *current_val_ptr; //Dereferences and adds the resulting floating point value.
							}

						/* Allocates dynamic memory for the obtained result and copies it into a 'void' type pointer. */
						if ((result_ptr = malloc(sizeof(float))))
							{
								*((float *) result_ptr) = flt_summation;
							}
						else
							{
								fprintf(stderr, "Fatal error! Dynamic memory could not be allocated to store the result of the floating point addition.\n");
							}
					}
					break;

				/* Verification of summation of 'integer' types. */
				case enm_type_entry_int:
					{
						/* Transient integer work variables. */
						int int_summation = V_ZERO;
						int *current_val_ptr = NULL;

						/* Iterates until a NULL pointer is found (sentinel). */
						while ((current_val_ptr = va_arg(args_list, int *)))
							{
								int_summation += *current_val_ptr; //Dereferences and adds the resulting integer value.
							}

						/* Allocates dynamic memory for the obtained result and copies it into a 'void' type pointer. */
						if ((result_ptr = malloc(sizeof(int))))
							{
								*((int *) result_ptr) = int_summation;
							}
						else
							{
								fprintf(stderr, "Fatal error! Dynamic memory could not be allocated to store the result of the integer addition.\n");
							}
					}
					break;

				/* Verification of summation of 'long' types. */
				case enm_type_entry_long:
					{
						/* Transient long work variables. */
						long lng_summation = V_ZERO;
						long *current_val_ptr = NULL;

						/* Iterates until a NULL pointer is found (sentinel). */
						while ((current_val_ptr = va_arg(args_list, long *)))
							{
								lng_summation += *current_val_ptr; //Dereferences and adds the resulting long value.
							}

						/* Allocates dynamic memory for the obtained result and copies it into a 'void' type pointer. */
						if ((result_ptr = malloc(sizeof(long))))
							{
								*((long *) result_ptr) = lng_summation;
							}
						else
							{
								fprintf(stderr, "Fatal error! Dynamic memory could not be allocated to store the result of the long addition.\n");
							}
					}
					break;

				/* Verification of summation of 'short' types. */
				case enm_type_entry_short:
					{
						/* Transient short work variables. */
						short shrt_summation = V_ZERO;
						short *current_val_ptr = NULL;

						/* Iterates until a NULL pointer is found (sentinel). */
						while ((current_val_ptr = va_arg(args_list, short *)))
							{
								shrt_summation += *current_val_ptr; //Dereferences and adds the resulting short value.
							}

						/* Allocates dynamic memory for the obtained result and copies it into a 'void' type pointer. */
						if ((result_ptr = malloc(sizeof(short))))
							{
								*((short *) result_ptr) = shrt_summation;
							}
						else
							{
								fprintf(stderr, "Fatal error! Dynamic memory could not be allocated to store the result of the short addition.\n");
							}
					}
					break;

				default:
					fprintf(stderr, "Error! Unsupported data type for summing variable arguments. Value: [%d].\n", (int) enm_type_value);
					break;
			}

		/* Clean and purge the argument list obtained from this function. */
		va_end(args_list);

		/* Prepare the return of the return. */
		return result_ptr;
	}

//Main function.
int main()
	{
		/* Preliminary working variables. */
		int quantity = V_ZERO, value_type = V_ZERO;
		void *void_summation_ptr = NULL;
		void **void_ptr_ptr_variables = NULL;

		/* Header messages. */
		printf("Automatic generator of various numerical variables to be added consecutively.\n");

		/* Get the number of values ​​to capture. */
		printf("How many variables do you want to create to be summed? : ");
		scanf("%d", &quantity);

		/* An array of pointers of type 'void *' is generated with the indicated quantity. */
		if ((quantity > V_ZERO) && (void_ptr_ptr_variables = (void **) malloc(quantity * sizeof(void *))))
			{
				printf("What type of variables will be added?\n");
				printf("[1]. Char. [2]. Double. [3]. Float. [4]. Int. [5]. Long. [6]. Short.\n");
				printf("Choose your option: ");
				scanf("%i", &value_type);

				enm_type_value = (enum enm_type_entry) value_type;

				if (enm_type_value >= enm_type_entry_char && enm_type_value <= enm_type_entry_short)
					{
						/* Capture a value of the specified type at each memory location created. */
						for (int idx = V_ZERO; idx < quantity; idx++)
							{
								if ((void_ptr_ptr_variables[idx] = (void *) malloc(sizeof(void))))
									{
										printf("Enter the value #: [%d] of: [%d]. : ", idx + V_ONE, quantity);

										switch(enm_type_value)
											{
												case enm_type_entry_char:
													scanf(" %c", (char *) void_ptr_ptr_variables[idx]);

													if ((void_summation_ptr = void_my_addition(enm_type_entry_char, void_ptr_ptr_variables[idx], NULL)))
														{
															printf("Amount made: [%d].\n", *((char *) void_summation_ptr));
															free(void_summation_ptr);
														}
													else
														{
															fprintf(stderr, "Fatal error! The variables could not be added because dynamic memory could not be allocated for their addition.\n");
														}
													break;

												case enm_type_entry_double:
													scanf("%lf", (double *) void_ptr_ptr_variables[idx]);

													if ((void_summation_ptr = void_my_addition(enm_type_entry_double, void_ptr_ptr_variables[idx], NULL)))
														{
															printf("Amount made: [%lf].\n", *((double *) void_summation_ptr));
															free(void_summation_ptr);
														}
													else
														{
															fprintf(stderr, "Fatal error! The variables could not be added because dynamic memory could not be allocated for their addition.\n");
														}
													break;

												case enm_type_entry_float:
													scanf("%f", (float *) void_ptr_ptr_variables[idx]);

													if ((void_summation_ptr = void_my_addition(enm_type_entry_float, void_ptr_ptr_variables[idx], NULL)))
														{
															printf("Amount made: [%f].\n", *((float *) void_summation_ptr));
															free(void_summation_ptr);
														}
													else
														{
															fprintf(stderr, "Fatal error! The variables could not be added because dynamic memory could not be allocated for their addition.\n");
														}
													break;

												case enm_type_entry_int:
													scanf("%d", (int *) void_ptr_ptr_variables[idx]);

													if ((void_summation_ptr = void_my_addition(enm_type_entry_int, void_ptr_ptr_variables[idx], NULL)))
														{
															printf("Amount made: [%d].\n", *((int *) void_summation_ptr));
															free(void_summation_ptr);
														}
													else
														{
															fprintf(stderr, "Fatal error! The variables could not be added because dynamic memory could not be allocated for their addition.\n");
														}
													break;

												case enm_type_entry_long:
													scanf("%ld", (long *) void_ptr_ptr_variables[idx]);

													if ((void_summation_ptr = void_my_addition(enm_type_entry_long, void_ptr_ptr_variables[idx], NULL)))
														{
															printf("Amount made: [%ld].\n", *((long *) void_summation_ptr));
															free(void_summation_ptr);
														}
													else
														{
															fprintf(stderr, "Fatal error! The variables could not be added because dynamic memory could not be allocated for their addition.\n");
														}
													break;

												case enm_type_entry_short:
													scanf("%hi", (short *) void_ptr_ptr_variables[idx]);

													if ((void_summation_ptr = void_my_addition(enm_type_entry_short, void_ptr_ptr_variables[idx], NULL)))
														{
															printf("Amount made: [%hi].\n", *((short *) void_summation_ptr));
															free(void_summation_ptr);
														}
													else
														{
															fprintf(stderr, "Fatal error! The variables could not be added because dynamic memory could not be allocated for their addition.\n");
														}
													break;

												default:
													fprintf(stderr, "The option: [%d] for item: [%d] of: [%d] is not recognized. Please correct it.\n", (int) enm_type_value, idx + V_ONE, quantity);
													break;
											}
									}
								else
									fprintf(stderr, "It was a pain. I can't store a value for position [%d] of [%d] in an array of pointers of type 'void *'.\n", idx + V_ONE, quantity);
							}


						/* Freeing the memory allocated in each element of the array of pointers of type 'void *'. */
						printf("\nDeallocation of dynamically generated memory.\n");

						for (int idx = V_ZERO; idx < quantity; idx++)
							{
								printf("\tElement #: [%d] of: [%d].\n", idx + V_ONE, quantity);
								free(void_ptr_ptr_variables[idx]);
							}
					}
				else
					fprintf(stderr, "The type of variable to be stored is incorrect. Please correct it!\n");

				printf("Freeing memory allocated to the pointer array...\n");
				free(void_ptr_ptr_variables);
			}
		else
			fprintf(stderr, "It was a pain! Could not allocate dynamic memory for the pointer array of type 'void *'.\n");

		return EXIT_SUCCESS;
	}
