#include "sort.h"

/**
 * selection_sort - sorts an array using Selection sort algorithm
 * @array: ptr to array
 * @size: size of the array
 * Retuen: void
 **/

void selection_sort(int *array, size_t size)
{
	size_t i, j, k, n;
	int aux, f;

	if (array)
	{
		for (i = 0; i < size; i++)
		{
			aux = array[i];
			f = 0;
			for (j = i; j < size ; j++)
			{
				if (array[j] < aux)
				{
					k = j;
					aux = array[j];
					f = 1;
				}
			}
			if (f == 1)
			{
				n = array[i];
				array[i] = array[k];
				array[k] = n;
				print_array(array, size);
			}
		}
	}
}
