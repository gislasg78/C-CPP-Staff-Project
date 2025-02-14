#include <stdio.h>

#define	NULL_CHARACTER	'\0'
#define	CARRIAGE_RETURN	'\n'

#define RANDOM_GENERATOR(s)	(((V_MULTIPLIER) * (s) + (V_INCREMENTER)) % (V_MODULUS))
#define	V_INCREMENTER		13849
#define V_MODULUS		65536
#define V_MULTIPLIER		25173
#define V_RESIDUAL_MODULUS	65535

#define	V_EIGHT			8
#define	V_ELEVEN		11
#define	V_FIVE			5
#define	V_FORTY_FIVE_ITEMS	45
#define	V_FOUR			4
#define	V_MINUS_ONE		-1
#define	V_NINE			9
#define	V_SEVEN			7
#define V_SIX			6
#define V_TEN			10
#define	V_THREE			3
#define	V_TWO			2
#define	V_ONE			1
#define	V_ZERO  		0

struct s_fruits
	{
		int numberoffruit;
		char *nameoffruit;
	}
	array_fruits[V_FORTY_FIVE_ITEMS] =
					{
					 {1, "Apple"}, {2, "Apricot"}, {3, "Avocado"}, {4, "Banana"}, {5, "Blackberry"},
					 {6, "Blueberry"}, {7, "Cherry"}, {8, "Coconut"}, {9, "Cranberry"}, {10, "Cucumber"},
					 {11, "Date"}, {12, "Dragon fruit"}, {13, "Elderberry"}, {14, "Fig"}, {15, "Grape"},
					 {16, "Grapefruit"}, {17, "Honeydew"}, {18, "Indian fig"}, {19, "Jackfruit"},
					 {20, "Kiwi"}, {21, "Lemon"}, {22, "Lime"}, {23, "Mandarin"}, {24, "Mango"},
					 {25, "Melon"}, {26, "Nectarine"}, {27, "Orange"}, {28, "Papaya"}, {29, "Passion fruit"},
					 {30, "Peach"}, {31, "Peer"}, {32, "Pineapple"}, {33, "Plantain"}, {34, "Plum"},
					 {35, "Pomegranate"}, {36, "Quince"}, {37, "Raspberry"}, {38, "Starfruit"}, {39, "Strawberry"},
					 {40, "Tangerine"}, {41, "Tomato"}, {42, "Ugli fruit"}, {43, "Vanilla"}, {44, "Watermelon"}, {45, "Yellow passion fruit"}
					},
	*pointer_array_fruits = array_fruits;

int BinarySearch(struct s_fruits *array_fruits, const int idx_begin, const int idx_end, const int data);
void BubbleSort(struct s_fruits array_fruits[], const int idx_begin, const int idx_end);
struct s_fruits GetFruitItemInfo(const struct s_fruits *array_fruits, const int num_item, const int all_info);
char GetPause(const char *str_Message);
int GetRandomInterval(int idx_begin, int idx_end, int *random_seed);
double GetRandomNumber(int *random_seed);
int GetValidateLimits(const int idx, int *idx_begin, int *idx_end);
int GetCheckedInput(int *value);
int GetVerifiedIndexes(int *idx_begin, int *idx_end, int *idx_max, int *idx_min);
void Heapify(struct s_fruits array_fruits[], const int idx_end, const int idx);
void HeapSort(struct s_fruits array_fruits[], const int idx_begin, const int idx_end);
void InsertionSort(struct s_fruits array_fruits[], int idx_begin, int idx_end);
void MainMenu(int *option);
int ObtainCodeKeyTable();
void QuickSort(struct s_fruits array_fruits[], int idx_begin, int idx_end);
void SeeItemNotFound(int idx, int idx_begin, int idx_end, const int data);
void SelectOption(int option);
void SelectionSort(struct s_fruits array_fruits[], int idx_begin, int idx_end);
int SequentialSearch(const struct s_fruits *array_fruits, const int idx_begin, const int idx_end, const int data);
void SwapRegisters(struct s_fruits array_fruits[], const int l_idx, const int r_idx);
void SwapValues(int *left_value, int *right_value);
void UnClutterTable(struct s_fruits *array_fruits, int idx_begin, int idx_end, int cycles, int *p_random);
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
		int bottom = idx_begin, middle = V_ZERO, top = idx_end;
		struct s_fruits s_fruit_item = {V_ZERO, NULL_CHARACTER};

		/* Binary search for an element within an array. */
		for (int idx_count = V_ZERO; bottom <= top && data != array_fruits[middle].numberoffruit; idx_count++)
			{
				middle = (bottom + top) / V_TWO;

				if (data > array_fruits[middle].numberoffruit)
					bottom = middle + V_ONE;

				if (data < array_fruits[middle].numberoffruit)
					top = middle + V_MINUS_ONE;
			}

		if (data == array_fruits[middle].numberoffruit)
			s_fruit_item = GetFruitItemInfo(array_fruits, middle, V_ZERO);
		else
			SeeItemNotFound(middle, idx_begin, idx_end, data);

		return middle;
	}

void BubbleSort(struct s_fruits array_fruits[], int idx_begin, int idx_end)
	{
		for (int ind = idx_begin; ind <= idx_end + V_MINUS_ONE; ind++)
			for (int idx = ind + V_ONE; idx <= idx_end; idx++)
				if ((array_fruits[ind].numberoffruit > (array_fruits + idx)->numberoffruit))
					SwapRegisters(array_fruits, ind, idx);
	}

int GetCheckedInput(int *value)
	{
		char chr_char = V_ZERO;
		int number = V_ZERO;

		if (scanf("%d", &number))
			//An integer was read successfully.
			printf("\nEntry: [%d]. OK!\n", number);
		else
			{
				//Discard invalid input.
				printf("\nInvalid entry. Please try again.\n");

				//We clear the buffer in case there are extra characters.
				scanf("%*[^\n]%*c");
				while ((chr_char = getchar()) != CARRIAGE_RETURN && chr_char != EOF);
			}

		if (value) *value = number;

		return number;
	}

char GetPause(const char *str_Message)
	{
		char chr_Char = NULL_CHARACTER;

		printf("%s", str_Message);

		if (scanf("%c", &chr_Char))
			{
				scanf("%*[^\n]%*c");
				while ((chr_Char = getchar()) != CARRIAGE_RETURN && chr_Char != EOF);
			};

		return chr_Char;
	}

int GetRandomInterval(int idx_begin, int idx_end, int *random_seed)
	{
		return ((int) ((idx_end - idx_begin) * GetRandomNumber(random_seed) + idx_begin));
	}

double GetRandomNumber(int *random_seed)
	{
		return ((double) (*random_seed = RANDOM_GENERATOR(*random_seed)) / (double) V_RESIDUAL_MODULUS);
	}

struct s_fruits GetFruitItemInfo(const struct s_fruits *array_fruits, const int num_item, const int all_info)
	{
		char chr_key = V_ZERO;

		if (all_info)
			{
				printf("\n");
				printf("+===+====+===+====+===+====+===+====+\n");
				printf("|   Retrieved record information.   |\n");
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("| Structures arrangement directions.|\n");
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("| Address : [%p] = [%p].\n", array_fruits, &array_fruits[V_ZERO]);
				printf("|         : [%p].\n", array_fruits + V_ZERO);
				printf("|         : [%p] = [%p].\n", pointer_array_fruits, &pointer_array_fruits[V_ZERO]);
				printf("|         : [%p].\n", pointer_array_fruits + V_ZERO);
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("|     Item under consultation.      |\n");
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("| Index   : [%d].\n", num_item);
				printf("| Address : [%p] = [%p].\n", &array_fruits[num_item], array_fruits + num_item);
				printf("|         : [%p] = [%p].\n", &pointer_array_fruits[num_item], pointer_array_fruits + num_item);
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("|     Detailed item information.    |\n");
				printf("+---+----+---+----+---+----+---+----+\n");
				printf("| Code    : [%d] = [%d].\n", array_fruits[num_item].numberoffruit, (array_fruits + num_item)->numberoffruit);
				printf("|         : [%d] = [%d].\n", pointer_array_fruits[num_item].numberoffruit, (pointer_array_fruits + num_item)->numberoffruit);
				printf("| Address : [%p] = [%p].\n", &array_fruits[num_item].numberoffruit, &(array_fruits + num_item)->numberoffruit);
				printf("|         : [%p] = [%p].\n", &pointer_array_fruits[num_item].numberoffruit, &(pointer_array_fruits + num_item)->numberoffruit);
				printf("+------------------------------+----+\n");
				printf("| Name    : [%s] = [%s].\n", array_fruits[num_item].nameoffruit, (array_fruits + num_item)->nameoffruit);
				printf("|         : [%s] = [%s].\n", pointer_array_fruits[num_item].nameoffruit, (pointer_array_fruits + num_item)->nameoffruit);
				printf("| Address : [%p] = [%p].\n", &array_fruits[num_item].nameoffruit, &(array_fruits + num_item)->nameoffruit);
				printf("|         : [%p] = [%p].\n", &pointer_array_fruits[num_item].nameoffruit, &(pointer_array_fruits + num_item)->nameoffruit);
				printf("+===+====+===+====+===+====+===+====+\n");
			}

		printf("\n");
		printf("+---+----+---+----+---+----+---+----+\n");
		printf("|      Exact item information.      |\n");
		printf("+---+----+---+----+---+----+---+----+\n");
		printf("| Index   : [%d].\n", num_item);
		printf("+------------------------------+----+\n");
		printf("| Code    : [%d].\n", array_fruits[num_item].numberoffruit);
		printf("| Name    : [%s].\n", array_fruits[num_item].nameoffruit);
		printf("+---+----+---+----+---+----+---+----+\n");

		chr_key = GetPause("Press the ENTER key to continue...");

		return array_fruits[num_item];
	}

int GetValidateLimits(const int idx, int *idx_begin, int *idx_end)
	{
		const int max_idx = V_FORTY_FIVE_ITEMS + V_MINUS_ONE;
		const int min_idx = V_ZERO;

		printf("\n");
		printf("* Get Validate Limits.\tIndex: [%d].\tBegin: [%d].\tEnd: [%d]. *\n", idx, *idx_begin, *idx_end);

		*idx_begin = (*idx_begin) ? *idx_begin : min_idx;
		*idx_end = (*idx_end) ? *idx_end : max_idx;

		*idx_begin = (*idx_begin >= min_idx && *idx_begin <= max_idx) ? *idx_begin : min_idx;
		*idx_end = (*idx_end >= min_idx && *idx_end <= max_idx) ? *idx_end : max_idx;

		if (*idx_begin >= *idx_end || *idx_end <= *idx_begin) SwapValues(idx_begin, idx_end);

		printf("+ Get Validate Limits.\tIndex: [%d].\tBegin: [%d].\tEnd: [%d]. +\n", idx, *idx_begin, *idx_end);

		return ((idx >= *idx_begin && idx <= *idx_end) && (*idx_begin >= min_idx && *idx_begin <= max_idx) && (*idx_end >= min_idx && *idx_end <= max_idx));
	}

int GetVerifiedIndexes(int *idx_begin, int *idx_end, int *idx_max, int *idx_min)
	{
		printf("\n");
		printf("Index positions beetween: [%d] and [%d].\n", V_ZERO, V_FORTY_FIVE_ITEMS + V_MINUS_ONE);
		printf("* Start position  : ");
		*idx_begin = GetCheckedInput(idx_begin);
		printf("* Finish position : ");
		*idx_end = GetCheckedInput(idx_end);

		printf("\n");
		printf("* Get Verified Indexes.\tBegin: [%d].\tEnd: [%d]. *\n", *idx_begin, *idx_end);

		if ((*idx_begin > *idx_end) || (*idx_end < *idx_begin)) SwapValues(idx_begin, idx_end);

		printf("+ Get Verified Indexes.\tBegin: [%d].\tEnd: [%d]. +\n", *idx_begin, *idx_end);

		return (GetValidateLimits(*idx_begin, idx_max, idx_min) && GetValidateLimits(*idx_end, idx_max, idx_min));
	}

void Heapify(struct s_fruits array_fruits[], const int idx_end, const int idx)
	{
		int largest = idx;
		int left = V_TWO * idx + V_ONE;
		int right = V_TWO * idx + V_TWO;

		if (left < idx_end && array_fruits[left].numberoffruit > array_fruits[largest].numberoffruit)
			largest = left;

		if (right < idx_end && array_fruits[right].numberoffruit > array_fruits[largest].numberoffruit)
			largest = right;

		if (largest != idx)
			{
				SwapRegisters(array_fruits, idx, largest);
				Heapify(array_fruits, idx_end, largest);
			}
	}

void HeapSort(struct s_fruits array_fruits[], const int idx_begin, const int idx_end)
	{
		for (int idx = (idx_end + V_ONE) / V_TWO - V_ONE; idx >= idx_begin; idx--)
			Heapify(array_fruits, idx_end + V_ONE, idx);

		for (int idx = (idx_end + V_ONE) - V_ONE; idx > idx_begin; idx--)
			{
				SwapRegisters(array_fruits, idx_begin, idx);
				Heapify(array_fruits, idx, idx_begin);
			}
	}

void InsertionSort(struct s_fruits array_fruits[], int idx_begin, int idx_end)
	{
		int idx = V_ZERO, jdx = V_ZERO;
		struct s_fruits s_key_fruit_item = {V_ZERO, NULL_CHARACTER};

		for (idx = (idx_begin + V_ONE); idx <= idx_end; idx++)
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
				printf("| [06]. Heap sort.             |\n");
				printf("| [07]. Insertion sort.        |\n");
				printf("| [08]. Quick sort.            |\n");
				printf("| [09]. Selection sort.        |\n");
				printf("| [10]. View all items.        |\n");
				printf("| [11]. Exit this program.     |\n");
				printf("+---+----+---+----+---+---+----+\n");
				printf("Enter your choice: ");
				*option = GetCheckedInput(option);

				printf("\nThe chosen option was: [%d].\n", *option);

				SelectOption(*option);
			}
		while (*option != V_ELEVEN);
	}

int ObtainCodeKeyTable()
	{
		int data = V_ZERO;

		printf("\nEnter a code key data fruit to search for: ");
		data = GetCheckedInput(&data);

		return data;
	}

void QuickSort(struct s_fruits array_fruits[], int idx_begin, int idx_end)
	{
		int left_idx = idx_begin, right_idx = idx_end, middle_idx = V_ZERO;

		middle_idx = array_fruits[(left_idx + right_idx) / V_TWO].numberoffruit;

		do
			{
				while (array_fruits[left_idx].numberoffruit < middle_idx && left_idx < idx_end)
					left_idx++;

				while (array_fruits[right_idx].numberoffruit > middle_idx && right_idx > idx_begin)
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

void SeeItemNotFound(int idx, int idx_begin, int idx_end, const int data)
	{
		char chr_key = NULL_CHARACTER;

		printf("\n");
		printf("+---+----+---+----+---+----+\n");
		printf("|     Item not located.    |\n");
		printf("+---+----+---+----+---+----+\n");
		printf("| Lower limit index  : [%d].\n", idx_begin);
		printf("| Upper limit index  : [%d].\n", idx_end);
		printf("+--------------------------+\n");
		printf("| Indicated position : [%d].\n", idx);
		printf("| Searched item code : [%d].\n", data);
		printf("+---+----+---+----+---+----+\n");

		chr_key = GetPause("Press the ENTER key to continue...");
	}

void SelectionSort(struct s_fruits array_fruits[], int idx_begin, int idx_end)
	{
		int idx = V_ZERO, jdx = V_ZERO, min_idx = V_ZERO;

		for (idx = idx_begin; idx <= idx_end + V_MINUS_ONE; idx++)
			{
				min_idx = idx;

				for (jdx = idx + V_ONE; jdx <= idx_end; jdx++)
					if (array_fruits[jdx].numberoffruit < array_fruits[min_idx].numberoffruit)
						min_idx = jdx;

				SwapRegisters(array_fruits, min_idx, idx);
			}
	}

void SelectOption(int option)
	{
		int c_cycles = V_ZERO, p_random = V_ZERO;
		int data = V_ZERO, pos = V_ZERO;
		int idx = V_ZERO, idx_begin = V_ZERO, idx_end = V_ZERO;
		int idx_max = V_ZERO, idx_min = V_ZERO;
		struct s_fruits s_fruit_item = {V_ZERO, NULL_CHARACTER};

		switch (option)
			{
				case V_ONE:
					printf("\nBinary Search.\n");
					data = ObtainCodeKeyTable();

					if (GetVerifiedIndexes(&idx_begin, &idx_end, &idx_max, &idx_min))
						pos = BinarySearch(array_fruits, idx_begin, idx_end, data);
					else
						printf("Binary Search. Indexes out of bounds.\n");
					break;

				case V_TWO:
					printf("\nSequential Search.\n");
					data = ObtainCodeKeyTable();

					if (GetVerifiedIndexes(&idx_begin, &idx_end, &idx_max, &idx_min))
						pos = SequentialSearch(array_fruits, idx_begin, idx_end, data);
					else
						printf("Sequential Search. Indexes out of bounds.\n");
					break;

				case V_THREE:
					printf("\nLocate Directly.\n");
					printf("Enter a index position (%d - %d) to locate: ", V_ZERO, V_FORTY_FIVE_ITEMS + V_MINUS_ONE);
					idx = GetCheckedInput(&idx);

					if (GetValidateLimits(idx, &idx_begin, &idx_end))
						s_fruit_item = GetFruitItemInfo(array_fruits, idx, V_ZERO);
					else
						printf("Locate directly. Index out of bounds.\n");
					break;

				case V_FOUR:
					printf("\nUnclutter Table.\n");

					if (GetVerifiedIndexes(&idx_begin, &idx_end, &idx_max, &idx_min))
						{
							printf("\n");
							printf("Enter a random starting seed: ");
							p_random = GetCheckedInput(&p_random);
							printf("How many cycles do you want to shuffle the order of the records? : ");
							c_cycles = GetCheckedInput(&c_cycles);

							UnClutterTable(array_fruits, idx_begin, idx_end, c_cycles, &p_random);
						}
					else
						printf("Unclutter Table. Indexes out of bounds.\n");
					break;

				case V_FIVE:
					printf("\nBubble sort...\n");

					if (GetVerifiedIndexes(&idx_begin, &idx_end, &idx_max, &idx_min))
						BubbleSort(array_fruits, idx_begin, idx_end);
					else
						printf("Bubble Sort. Indexes out of bounds.\n");
					break;

				case V_SIX:
					printf("\nHeap Sort...\n");
					if (GetVerifiedIndexes(&idx_begin, &idx_end, &idx_max, &idx_min))
						HeapSort(array_fruits, idx_begin, idx_end);
					else
						printf("Heap Sort. Indexes out of bounds.\n");
					break;

				case V_SEVEN:
					printf("\nInsertion Sort...\n");

					if (GetVerifiedIndexes(&idx_begin, &idx_end, &idx_max, &idx_min))
						InsertionSort(array_fruits, idx_begin, idx_end);
					else
						printf("Insertion Sort. Indexes out of bounds.\n");
					break;

				case V_EIGHT:
					printf("\nQuick Sort...\n");

					if (GetVerifiedIndexes(&idx_begin, &idx_end, &idx_max, &idx_min))
						QuickSort(array_fruits, idx_begin, idx_end);
					else
						printf("Quick Sort. Indexes out of bounds.\n");
					break;

				case V_NINE:
					printf("\nSelection Sort...\n");

					if (GetVerifiedIndexes(&idx_begin, &idx_end, &idx_max, &idx_min))
						SelectionSort(array_fruits, idx_begin, idx_end);
					else
						printf("Selection Sort. Indexes out of bounds.\n");
					break;

				case V_TEN:
					printf("\nView All Items...\n");

					if (GetVerifiedIndexes(&idx_begin, &idx_end, &idx_max, &idx_min))
						pos = ViewItems(array_fruits, idx_begin, idx_end);
					else
						printf("View Items. Indexes out of bounds.\n");
					break;

				case V_ELEVEN:
					printf("\nLeaving this program...\n");
					break;

				default:
					printf("The chosen option: [%d] is incorrect. Please correct it!\n", option);
					break;

		}
	}

int SequentialSearch(const struct s_fruits *array_fruits, const int idx_begin, const int idx_end, const int data)
	{
		int idx = V_ZERO;
		struct s_fruits s_fruit_item = {V_ZERO, NULL_CHARACTER};

		for (idx = idx_begin; idx <= idx_end && array_fruits[idx].numberoffruit != data; idx++);

		if ((idx >= idx_begin && idx <= idx_end) && (array_fruits[idx].numberoffruit == data))
			s_fruit_item = GetFruitItemInfo(array_fruits, idx, V_ZERO);
		else
			SeeItemNotFound(idx, idx_begin, idx_end, data);

		return (idx);
	}

void SwapRegisters(struct s_fruits *array_fruits, const int l_idx, const int r_idx)
	{
		int maximum = V_ZERO, minimum = V_ZERO;
		struct s_fruits s_fruit_item_aux = {V_ZERO, NULL_CHARACTER};

		if (GetValidateLimits(l_idx, &minimum, &maximum) && GetValidateLimits(r_idx, &minimum, &maximum))
			{
				s_fruit_item_aux = *(array_fruits + l_idx);
				*(array_fruits + l_idx) = *(array_fruits + r_idx);
				*(array_fruits + r_idx) = s_fruit_item_aux;
			}
		else
			printf("Swap Registers. Incorrect! Lower limit: [%d]. Upper limit: [%d].\t\r", l_idx, r_idx);
	}

void SwapValues(int *left_value, int *right_value)
	{
		int aux_value = V_ZERO;

		aux_value = *left_value;
		*left_value = *right_value;
		*right_value = aux_value;
	}

void UnClutterTable(struct s_fruits *array_fruits, int idx_begin, int idx_end, int cycles, int *p_random)
	{
		printf("\nUnordering the table at the specified ranges...\n");

		for (int idx = V_ZERO; idx < cycles; idx++)
			{
				int left_idx = V_ZERO, right_idx = V_ZERO;

				left_idx = GetRandomInterval(idx_begin, idx_end, p_random);
				right_idx = GetRandomInterval(idx_begin, idx_end, p_random);

				printf("\n#:[%10d].\tSeed:\t[%5d].\tValues:\t(Left:\t[%2d],\tRight:\t[%2d]).\n", idx, *p_random, left_idx, right_idx);

				SwapRegisters(array_fruits, left_idx, right_idx);
			}

		printf("\n");
	}

int ViewItems(struct s_fruits *array_fruits, const int idx_begin, const int idx_end)
	{
		struct s_fruits s_fruit_item = {V_ZERO, NULL_CHARACTER};

		for (int idx = idx_begin; idx <= idx_end; idx++)
			s_fruit_item = GetFruitItemInfo(array_fruits, idx, V_ZERO);

		return (idx_end - idx_begin + V_ONE);
	}
