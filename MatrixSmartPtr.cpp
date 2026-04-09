/* This program uses intelligent dynamic pointers to create arrays
   with a variable number of rows and columns,
   but with each row having a fixed number of columns. */

#include <iostream>
#include <memory>

constexpr std::size_t V_ZERO = 0;

int main()
{
	/* Preliminary working variables. */
	int counter = V_ZERO;
	std::size_t n_rows{}, n_cols{};

	std::cout << "Smart Pointers." << std::endl;
	std::cout << "+ Number of rows: ";
	std::cin >> n_rows;
	std::cout << "+ Number of columns: ";
	std::cin >> n_cols;

	std::cout << std::endl << "List of generated values." << std::endl;

	/* Generate the matrix initially. */
	std::unique_ptr<std::unique_ptr<std::size_t[]>[]> matrix = std::make_unique<std::unique_ptr<std::size_t[]>[]>(n_rows);

	/* Assign each row a specific number of fixed columns. */
	for (size_t r = V_ZERO; r < n_rows; r++)
		matrix[r] = std::make_unique<std::size_t[]>(n_cols);

	/* Load the array with a series of default values. */
	for (size_t r = V_ZERO; r < n_rows; r++)
		for (size_t c = V_ZERO; c < n_cols; c++)
			matrix[r][c] = r * c;

	/* Display of loaded and calculated values. */
	for (size_t r = V_ZERO; r < n_rows; r++)
	{
		for (size_t c = V_ZERO; c < n_cols; c++)
			std::cout << "# " << counter++ << " : (" << r << ", " << c << ") = {" << matrix[r][c] << "}." << '\n';

		std::cout << std::endl;
	}

	std::cout <<"[" << counter << "] Output results generated." << std::endl;

	return V_ZERO;
}
