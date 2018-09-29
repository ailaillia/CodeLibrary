
#include "stdio.h"

static int Exchange(int *array, int IndexA, int IndexB);
static int Sort_Once(int *array, int length);
extern int Fast_Sort(int *array, int length);

//快速排序
extern int Fast_Sort(int *array, int length)
{
	return Sort_Once(array, length);
}

//一次排序
static int Sort_Once(int *array, int length)
{
	int key = array[length - 1];
	int i = 0, j = length - 1;
	if (length <= 0) { return 0; }

	while (i != j)
	{
		while (i != j)
		{
			if (array[i] > key)  {
				Exchange(array, i, j);
				j = j - 1;
				break;
			}
			else {
				i = i + 1;
			}
		}
		while (i != j)
		{
			if (array[j] < key)  {
				Exchange(array, i, j);
				i = i + 1;
				break;
			}
			else {
				j = j - 1;
			}
		}
	}
	Sort_Once(array, i);
	Sort_Once(array + i + 1, length - i - 1);
	return i;
}

//交换数组的元素值
static int Exchange(int *array, int IndexA, int IndexB)
{
	int tmp = 0;
	tmp = *(array + IndexA);
	*(array + IndexA) = *(array + IndexB);
	*(array + IndexB) = tmp;

	return 0;
}