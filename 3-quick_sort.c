#include "sort.h"

/**
 * quick_sort_rec - sorts an array by Selection sort algorithm/recursion
 * @array: ptr to array
 * @size: size of the array
 * @array_init: initial ptr to array
 * @size_init: initial size of the array
 * Return: void
 **/

void quick_sort_rec(int *array_init, size_t size_init, int *array, size_t size)
{
	size_t j, aux;
	int aux2;
	int i = -1, n, swich = array[size - 1];

	if (array && size > 1)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] < swich)
			{
				i++;
				aux = i;
				if (aux != j && array[j] != array[aux])
				{
					n = array[j];
					array[j] = array[i];
					array[i] = n;
					print_array(array_init, size_init);
				}
			}


		}
		aux2 = size;
		if (aux2 - 1 != i + 1 && array[aux2 - 1] != array[i + 1])
		{
			array[size - 1] = array[i + 1];
			array[i + 1] = swich;
			print_array(array_init, size_init);
		}
		if (i > 0)
		{
			quick_sort_rec(array_init, size_init, array, i + 1);
		}
		quick_sort_rec(array_init, size_init, array + i + 2,  size - (i + 2));
	}
}

/**
 * quick_sort - sorts an array by the Selection sort algorithm
 * @array: ptr to array
 * @size: size of the array
 * Return: void
**/

void quick_sort(int *array, size_t size)
{
	int *array_init;
	size_t size_init;

	if (array)
	{
		array_init = array;
		size_init = size;
		quick_sort_rec(array_init, size_init, array, size);
	}
}
