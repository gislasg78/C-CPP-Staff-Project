#include <iostream>
#include <list>
#include <vector>

#define	RANDOM_GENERATOR(n_r)	((V_MULTIPLIER * (n_r) + V_INCREASER) % V_RESIDUAL_MODULUS)

#define	V_INCREASER		13849
#define	V_MULTIPLIER		25173
#define	V_RESIDUAL_MODULUS	65536

#define	V_LOWER_LIMIT_COLS	1
#define	V_LOWER_LIMIT_ROWS	1
#define	V_UPPER_LIMIT_COLS	11
#define	V_UPPER_LIMIT_ROWS	11

#define	V_ZERO			0

static size_t szt_rnd (size_t *ptr_szt_randomly)
	{
		return (*ptr_szt_randomly = RANDOM_GENERATOR(*ptr_szt_randomly));
	}

int main()
	{
		std::list<std::list<size_t>> lst_lst_matrix_szt_Items;
		std::vector<std::vector<size_t>> vec_vec_matrix_szt_Items;

		size_t szt_List_Counting = V_ZERO;
		size_t szt_Vector_Counting = V_ZERO;

		size_t szt_Columns = V_ZERO;
		size_t szt_Item = V_ZERO;
		size_t szt_List_Col = V_ZERO;
		size_t szt_List_Row = V_ZERO;
		size_t szt_Randomly = V_ZERO;
		size_t szt_Rows = V_ZERO;

		std::cout << "+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "|     Random Values Tables.    |" << std::endl;
		std::cout << "+---|----+---|----+---|----+---|" << std::endl;
		std::cout << "Initial random number seed: ";
		std::cin >> szt_Randomly;
		std::cout << "Rows    between [" << V_LOWER_LIMIT_ROWS << "] and [" << V_UPPER_LIMIT_ROWS << "]: ";
		std::cin >> szt_Rows;
		std::cout << "Columns between [" << V_LOWER_LIMIT_COLS << "] and [" << V_UPPER_LIMIT_ROWS << "]: ";
		std::cin >> szt_Columns;

		if (szt_Rows >= V_LOWER_LIMIT_ROWS && szt_Rows <= V_UPPER_LIMIT_ROWS)
			if (szt_Columns >= V_LOWER_LIMIT_COLS && szt_Columns <= V_UPPER_LIMIT_COLS)
				{
					std::cout << std::endl;

					for (size_t szt_Y = V_ZERO; szt_Y < szt_Rows; szt_Y++)
						{
							std::list<size_t> lst_columns_szt_Items;
							std::vector<size_t> vec_columns_szt_Items;

							for (size_t szt_X = V_ZERO; szt_X < szt_Columns; szt_X++)
								{
									szt_Item = szt_rnd(&szt_Randomly);

									lst_columns_szt_Items.push_back(szt_Item);
									vec_columns_szt_Items.push_back(szt_Item);
								}

							lst_lst_matrix_szt_Items.push_back(lst_columns_szt_Items);
							vec_vec_matrix_szt_Items.push_back(vec_columns_szt_Items);
						}

					for (auto it_lst_lst_matrix_szt_Items = std::begin(lst_lst_matrix_szt_Items);
						it_lst_lst_matrix_szt_Items != std::end(lst_lst_matrix_szt_Items);
						it_lst_lst_matrix_szt_Items++)
							{
								std::cout << "List #\t[" << szt_List_Row << "]." << std::endl;

								for (auto it_lst_lst_matrix_columns_szt_Items = std::begin(*it_lst_lst_matrix_szt_Items);
										it_lst_lst_matrix_columns_szt_Items != std::end(*it_lst_lst_matrix_szt_Items);
										it_lst_lst_matrix_columns_szt_Items++)
											std::cout << "# " << szt_List_Counting++ << "\t(" << szt_List_Row << ", " << szt_List_Col++ << ")\t:\t" << "[" << *it_lst_lst_matrix_columns_szt_Items << "]." << std::endl;

								std::cout << std::endl;

								szt_List_Row++;
								szt_List_Col = V_ZERO;
							}

					std::cout << "[" << szt_List_Counting << "] Generated list output logs." << std::endl << std::endl;

					for (size_t szt_row = V_ZERO; szt_row < szt_Rows; szt_row++)
						{
							std::cout << "Vector #\t[" << szt_row << "] of [" << szt_Rows << "]." << std::endl;

							for (size_t szt_col = V_ZERO; szt_col < szt_Columns; szt_col++)
								std::cout << "# " << szt_Vector_Counting++ << "\t(" << szt_row << ", " << szt_col << ")\t=\t[" << vec_vec_matrix_szt_Items[szt_row][szt_col] << "]." << std::endl;

							std::cout << std::endl;
						}

					std::cout << "[" << szt_Vector_Counting << "] Generated vector output logs." << std::endl;
				}
			else
				std::cout << "Error! [" << szt_Columns << "] Columns are not beetween [" << V_LOWER_LIMIT_COLS << "] and [" << V_UPPER_LIMIT_COLS << "]." << std::endl;
		else
			std::cout << "Error! [" << szt_Columns << "] Rows    are not beetween [" << V_LOWER_LIMIT_ROWS << "] and [" << V_UPPER_LIMIT_ROWS << "]." << std::endl;

		return V_ZERO;
	}
