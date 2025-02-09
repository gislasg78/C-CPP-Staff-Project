#include <stdio.h>

#define	NULL_CHARACTER	'\0'

#define RANDOM_GENERATOR(s)	(V_MULTIPLIER * (s) + V_INCREMENTER) % V_MODULUS
#define	V_INCREMENTER		13849
#define V_MODULUS		65536
#define V_MULTIPLIER		25173
#define V_RESIDUAL_MODULUS	65535

#define	V_EIGHT			8
#define	V_FIVE			5
#define	V_FOUR			4
#define	V_MINUS_ONE		-1
#define	V_NINE			9
#define	V_SEVEN			7
#define V_SIX			6
#define V_TEN			10
#define	V_THIRTY_FIVE		35
#define	V_THREE			3
#define	V_TWO			2
#define	V_ONE			1
#define	V_ZERO  		0

struct s_fruits
	{
		int numberoffruit;
		char *nameoffruit;
	}
	array_fruits[V_THIRTY_FIVE] =	{
					 {1, "Apple"}, {2, "Apricot"}, {3, "Avocado"}, {4, "Banana"}, {5, "Blackberry"},
					 {6, "Blueberry"}, {7, "Cherry"}, {8, "Coconut"}, {9, "Cranberry"}, {10, "Cucumber"},
					 {11, "Dragon fruit"}, {12, "Grape"}, {13, "Grapefruit"}, {14, "Jackfruit"}, {15, "Kiwi"},
					 {16, "Lemon"}, {17, "Lime"}, {18, "Mandarin"}, {19, "Mango"}, {20, "Melon"},
					 {21, "Nectarin"}, {22, "Orange"}, {23, "Papaya"}, {24, "Passion fruit"}, {25, "Peach"},
					 {26, "Peer"}, {27, "Pineapple"}, {28, "Plantain"}, {29, "Plum"}, {30, "Pomegranate"},
					 {31, "Raspberry"}, {32, "Starfruit"}, {33, "Strawberry"}, {34, "Tomato"}, {35, "Watermelon"},
					};

int BinarySearch(struct s_fruits *array_fruits, const int idx_begin, const int idx_end, const int data);
void BubbleSort(struct s_fruits array_fruits[], const int idx_begin, const int idx_end);
double GetRandomNumber(int *random_seed);
struct s_fruits GetFruitItemInfo(const struct s_fruits *array_fruits, const int num_item);
void InsertionSort(struct s_fruits array_fruits[], int idx_begin, int idx_end);
void MainMenu(int *option);
void QuickSort(struct s_fruits array_fruits[], int idx_begin, int idx_end);
void SelectOption(int option);
void SelectionSort(struct s_fruits array_fruits[], int idx_begin, int idx_end);
int SequentialSearch(const struct s_fruits *array_fruits, const int idx_begin, const int idx_end, const int data);
void SwapRegisters(struct s_fruits array_fruits[], const int l_idx, const int r_idx);
void SwapValues(int *l_value, int *r_value);
void UnClutterTable(struct s_fruits *array_fruits, int idx_begin, int idx_end, int cycles, int *p_random);
int ValidateLimits(const int idx, int *idx_begin, int *idx_end);
int ViewItems(struct s_fruits *array_fruits, const int idx_begin, const int idx_end);

int main()
	{
		int option = V_ZERO;

		printf("\nTracking items in a table.\n");

		MainMenu(&option);

		return V_ZERO;
	}

int BinarySearch(struct s_fruits *array_fruits, const int idx_begin, const int idx_end, const int data)
	{
		int idx_count = V_ZERO;
		int bottom = V_ZERO, middle = V_ZERO, top = V_ZERO;
		int maximum_idx = V_ZERO, minimum_idx = V_ZERO;
		struct s_fruits s_fruit_item = {V_ZERO, NULL_CHARACTER};

		/* Binary search for an element within an array. */
		if (ValidateLimits(idx_begin, &minimum_idx, &maximum_idx) && ValidateLimits(idx_end, &minimum_idx, &maximum_idx))
			{
				bottom = (idx_begin > idx_end) ? idx_end : idx_begin;
				top = (idx_end < idx_begin) ? idx_begin : idx_end;

				for (idx_count = V_ZERO; bottom <= top && data != array_fruits[middle].numberoffruit; idx_count++)
					{
						middle = (bottom + top) / V_TWO;

						if (data > array_fruits[middle].numberoffruit)
							bottom = middle + V_ONE;

						if (data < array_fruits[middle].numberoffruit)
							top = middle + V_MINUS_ONE;
					}

				if (data == array_fruits[middle].numberoffruit)
					s_fruit_item = GetFruitItemInfo(array_fruits, middle);
				else
					{
						printf("Item code not found     : [%d].\n", data);
						printf("Search index reached    : [%d].\n", middle);
						printf("Maximum of items tracked: [%d].\n", idx_end);
					}
			}
		else
			printf("The lower bound: [%d] and upper bound: [%d] are not valid for binary search.\n", idx_begin, idx_end);

		return middle;
	}

void BubbleSort(struct s_fruits array_fruits[], int idx_begin, int idx_end)
	{
		for (int ind = idx_begin; ind < idx_end + V_MINUS_ONE; ind++)
			for (int idx = ind + V_ONE; idx < idx_end; idx++)
				if ((array_fruits[ind].numberoffruit > (array_fruits + idx)->numberoffruit))
					SwapRegisters(array_fruits, ind, idx);
	}

double GetRandomNumber(int *random_seed)
	{
		return ((double) (*random_seed = RANDOM_GENERATOR(*random_seed)) / (double) V_RESIDUAL_MODULUS);
	}

struct s_fruits GetFruitItemInfo(const struct s_fruits *array_fruits, const int num_item)
	{
		char chr_key = NULL_CHARACTER;
		int maximum = V_THIRTY_FIVE + V_MINUS_ONE;
		int minimum = V_ZERO;
		struct s_fruits s_fruit_item = {V_ZERO, NULL_CHARACTER};

		if (ValidateLimits(num_item, &minimum, &maximum))
			{
				printf("\n");
				printf("+---+----+---+----+---+----+---+\n");
				printf("| Retrieved record information.|\n");
				printf("+---+----+---+----+---+----+---+\n");
				printf("| Index : [%d].\n", num_item);
				printf("+------------------------------+\n");
				printf("| Code  : [%d].\n", array_fruits[num_item].numberoffruit);
				printf("| Name  : [%s].\n", array_fruits[num_item].nameoffruit);
				printf("+---+----+---+----+---+----+---+\n");
				printf("Press the ENTER key to continue...");
				scanf("%*c%c", &chr_key);

				s_fruit_item = array_fruits[num_item];
			}
		else
			printf("Item code not found     : [%d].\n", num_item);

		return s_fruit_item;
	}

void InsertionSort(struct s_fruits array_fruits[], int idx_begin, int idx_end)
	{
		int idx = V_ZERO, jdx = V_ZERO;
		struct s_fruits s_key_fruit_item = {V_ZERO, NULL_CHARACTER};

		idx_begin = (idx_begin > idx_end) ? idx_end : idx_begin;
		idx_end = (idx_end < idx_begin) ? idx_begin : idx_end;

		for (idx = (idx_begin + V_ONE); idx < idx_end; idx++)
			{
				s_key_fruit_item = array_fruits[idx];
				jdx = idx + V_MINUS_ONE;

				while (jdx >= idx_begin && array_fruits[jdx].numberoffruit > s_key_fruit_item.numberoffruit)
					{
						array_fruits[jdx + V_ONE] = array_fruits[jdx];
						jdx = jdx + V_MINUS_ONE;
					}

				array_fruits[jdx + V_ONE] = s_key_fruit_item;
			}
	}

void MainMenu(int *option)
	{
		do
			{
				printf("\n");
				printf("+---+----+---+----+---+---+----+\n");
				printf("|         Option Menu.         |\n");
				printf("+---+----+---+----+---+---+----+\n");
				printf("| [01]. Binary Search.         |\n");
				printf("| [02]. Sequential Search.     |\n");
				printf("| [03]. Locate directly.       |\n");
				printf("| [04]. Unclutter table.       |\n");
				printf("| [05]. Bubble sort.           |\n");
				printf("| [06]. Insertion sort.        |\n");
				printf("| [07]. Selection sort.        |\n");
				printf("| [08]. Quick sort.            |\n");
				printf("| [09]. View all items.        |\n");
				printf("| [10]. Exit this program.     |\n");
				printf("+---+----+---+----+---+---+----+\n");
				printf("Enter your choice: ");
				scanf("%d", option);

				printf("\nThe chosen option was: [%d].\n", *option);

				SelectOption(*option);
			}
		while (*option != V_TEN);
	}

void QuickSort(struct s_fruits array_fruits[], int idx_begin, int idx_end)
	{
		int left_idx = V_ZERO, right_idx = V_ZERO;
		int middle = V_ZERO;
		struct s_fruits s_key_fruit_item = {V_ZERO, NULL_CHARACTER};

		left_idx = (idx_begin > idx_end) ? idx_end : idx_begin;
		right_idx = (idx_end < idx_begin) ? idx_begin : idx_end;

		middle = array_fruits[(left_idx + right_idx) / V_TWO].numberoffruit;

		do
			{
				while (array_fruits[left_idx].numberoffruit < middle && left_idx < idx_end)
					left_idx++;

				while (array_fruits[right_idx].numberoffruit > middle && right_idx > idx_begin)
					right_idx--;

				if (left_idx <= right_idx)
					{
						SwapRegisters(array_fruits, left_idx, right_idx);
						left_idx++; right_idx--;
					}
			}
		while (left_idx <= right_idx);

		if (idx_begin < right_idx) QuickSort(array_fruits, idx_begin, right_idx);
		if (left_idx < idx_end) QuickSort(array_fruits, left_idx, idx_end);
	}

void SelectionSort(struct s_fruits array_fruits[], int idx_begin, int idx_end)
	{
		int idx = V_ZERO, jdx = V_ZERO, min_idx = V_ZERO;

		idx_begin = (idx_begin > idx_end) ? idx_end : idx_begin;
		idx_end = (idx_end < idx_begin) ? idx_begin : idx_end;

		for (idx = idx_begin; idx < idx_end + V_MINUS_ONE; idx++)
			{
				min_idx = idx;

				for (jdx = idx + V_ONE; jdx < idx_end; jdx++)
					if (array_fruits[jdx].numberoffruit < array_fruits[min_idx].numberoffruit)
						min_idx = jdx;

				SwapRegisters(array_fruits, min_idx, idx);
			}
	}

void SelectOption(int option)
	{
		int c_cycles = V_ZERO, p_random = V_ZERO;
		int data = V_ZERO, pos = V_ZERO;
		int idx_begin = V_ZERO, idx_end = V_ZERO;
		struct s_fruits s_fruit_item = {V_ZERO, NULL_CHARACTER};

		switch (option)
			{
				case V_ONE:
					printf("\nBinary Search.\n");
					printf("Enter a code data (%d - %d) to search for: ", V_ONE, V_THIRTY_FIVE);
					scanf("%d", &data);
					printf("Enter a index start  position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_begin);
					printf("Enter a index finish position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_end);

					pos = BinarySearch(array_fruits, idx_begin, idx_end, data);
					break;

				case V_TWO:
					printf("\nSequential Search.\n");
					printf("Enter a code data (%d - %d) to search for: ", V_ONE, V_THIRTY_FIVE);
					scanf("%d", &data);
					printf("Enter a index start  position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_begin);
					printf("Enter a index finish position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_end);

					pos = SequentialSearch(array_fruits, idx_begin, idx_end, data);
					break;

				case V_THREE:
					printf("\nLocate Directly.\n");
					printf("Enter a index position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_begin);

					s_fruit_item = GetFruitItemInfo(array_fruits, idx_begin);
					break;

				case V_FOUR:
					printf("\nUnclutter Table.\n");
					printf("Enter a index start  position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_begin);
					printf("Enter a index finish position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_end);
					printf("Enter a random starting seed: ");
					scanf("%d", &p_random);
					printf("How many cycles do you want to shuffle the order of the records? : ");
					scanf("%d", &c_cycles);

					UnClutterTable(array_fruits, idx_begin, idx_end, c_cycles, &p_random);
					break;

				case V_FIVE:
					printf("\nBubble sort...\n");
					printf("Enter a index start  position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_begin);
					printf("Enter a index finish position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_end);

					BubbleSort(array_fruits, idx_begin, idx_end);
					break;

				case V_SIX:
					printf("\nInsertion Sort...\n");
					printf("Enter a index start  position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_begin);
					printf("Enter a index finish position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_end);

					InsertionSort(array_fruits, idx_begin, idx_end);
					break;

				case V_SEVEN:
					printf("\nSelection Sort...\n");
					printf("Enter a index start  position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_begin);
					printf("Enter a index finish position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_end);

					SelectionSort(array_fruits, idx_begin, idx_end);
					break;

				case V_EIGHT:
					printf("\nQuick Sort...\n");
					printf("Enter a index start  position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_begin);
					printf("Enter a index finish position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_end);

					QuickSort(array_fruits, idx_begin, idx_end);
					break;

				case V_NINE:
					printf("\nView All Items...\n");
					printf("Enter a index start  position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_begin);
					printf("Enter a index finish position (%d - %d) to locate: ", V_ZERO, V_THIRTY_FIVE + V_MINUS_ONE);
					scanf("%d", &idx_end);

					pos = ViewItems(array_fruits, idx_begin, idx_end);
					break;

				case V_TEN:
					printf("\nLeaving this program...\n");
					break;

				default:
					printf("The chosen option: [%d] is incorrect. Please correct it!\n", option);
					break;

		}
	}

int SequentialSearch(const struct s_fruits *array_fruits, const int idx_begin, const int idx_end, const int data)
	{
		int bottom = V_ZERO, top = V_ZERO;
		int idx = V_ZERO;
		int maximum = V_ZERO, minimum = V_ZERO;
		struct s_fruits s_fruit_item = {V_ZERO, NULL_CHARACTER};

		if (ValidateLimits(idx_begin, &minimum, &maximum) && ValidateLimits(idx_end, &minimum, &maximum))
			{
				bottom = (idx_begin > idx_end) ? idx_end : idx_begin;
				top = (idx_end < idx_begin) ? idx_begin : idx_end;

				for (idx = bottom; idx <= top && array_fruits[idx].numberoffruit != data; idx++);

				if (idx >= bottom && idx <= top)
					if (array_fruits[idx].numberoffruit == data)
						s_fruit_item = GetFruitItemInfo(array_fruits, idx);
					else ;
				else
					{
						printf("Item code not found     : [%d].\n", data);
						printf("Search index reached    : [%d].\n", idx);
						printf("Minimum of items tracked: [%d].\n", bottom);
						printf("Maximum of items tracked: [%d].\n", top);
					}
			}

		return (idx);
	}

void SwapRegisters(struct s_fruits *array_fruits, const int l_idx, const int r_idx)
	{
		int maximum = V_ZERO, minimum = V_ZERO;
		struct s_fruits s_fruit_item_aux = {V_ZERO, NULL_CHARACTER};

		if (ValidateLimits(l_idx, &minimum, &maximum) && ValidateLimits(r_idx, &minimum, &maximum))
			{
				s_fruit_item_aux = *(array_fruits + l_idx);
				*(array_fruits + l_idx) = *(array_fruits + r_idx);
				*(array_fruits + r_idx) = s_fruit_item_aux;
			}
		else
			printf("\nIncorrect! Lower limit: [%d]. Upper limit: [%d].\n", l_idx, r_idx);
	}

void SwapValues(int *l_value, int *r_value)
	{
		int aux_value = V_ZERO;

		aux_value = *l_value;
		*l_value = *r_value;
		*r_value = aux_value;
	}

void UnClutterTable(struct s_fruits *array_fruits, int idx_begin, int idx_end, int cycles, int *p_random)
	{
		int maximum = V_ZERO, minimum = V_ZERO;

		if (ValidateLimits(idx_begin, &maximum, &minimum) && ValidateLimits(idx_end, &maximum, &minimum))
			{
				printf("\nUnordering the table at the specified ranges...\n");

				for (int idx = V_ZERO; idx < cycles; idx++)
					{
						int left_idx = V_ZERO, right_idx = V_ZERO;
						left_idx = (idx_begin > idx_end) ? idx_end : idx_begin;
						right_idx = (idx_end < idx_begin) ? idx_begin : idx_end;

						left_idx = (idx_end - idx_begin) * GetRandomNumber(p_random) + idx_begin;
						printf("#: [%d].\n", idx);
						printf("- Seed: [%d].\tLeft Value : [%d].\n", *p_random, left_idx);

						right_idx = (idx_end - idx_begin) * GetRandomNumber(p_random) + idx_begin;
						printf("- Seed: [%d].\tRight Value: [%d].\n", *p_random, right_idx);
						printf("\n");

						SwapRegisters(array_fruits, left_idx, right_idx);
					}
			}
	}

int ValidateLimits(const int idx, int *idx_begin, int *idx_end)
	{
		const int max_idx = V_THIRTY_FIVE + V_MINUS_ONE;
		const int min_idx = V_ZERO;

		*idx_begin = (*idx_begin) ? *idx_begin : min_idx;
		*idx_end = (*idx_end) ? *idx_end : max_idx;

		*idx_begin = (*idx_begin >= min_idx && *idx_begin <= max_idx) ? *idx_begin : min_idx;
		*idx_end = (*idx_end >= min_idx && *idx_end <= max_idx) ? *idx_end : max_idx;

		if (*idx_begin >= *idx_end || *idx_end <= *idx_begin) SwapValues(idx_begin, idx_end);

		return ((idx >= *idx_begin && idx <= *idx_end) && (*idx_begin >= min_idx && *idx_begin <= max_idx) && (*idx_end >= min_idx && *idx_end <= max_idx));
	}

int ViewItems(struct s_fruits *array_fruits, const int idx_begin, const int idx_end)
	{
		int bottom = V_ZERO, top = V_ZERO;
		int maximum = V_THIRTY_FIVE + V_MINUS_ONE;
		int minimum = V_ZERO;
		struct s_fruits s_fruit_item = {V_ZERO, NULL_CHARACTER};

		if (ValidateLimits(idx_begin, &minimum, &maximum) && ValidateLimits(idx_end, &minimum, &maximum))
			{
				bottom = (idx_begin > idx_end) ? idx_end : idx_begin;
				top = (idx_end < idx_begin) ? idx_begin : idx_end;

				for (int idx = bottom; idx <= top; idx++)
					s_fruit_item = GetFruitItemInfo(array_fruits, idx);
			}
		else
			printf("\nIncorrect! Lower limit: [%d]. Upper limit: [%d].\n", bottom, top);

		return (idx_end - idx_begin + V_ONE);
	}
