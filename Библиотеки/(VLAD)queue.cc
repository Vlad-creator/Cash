#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "heap_functions.h"

struct node_t* create_queue(int N)
{
	struct node_t* top = (struct node_t*)calloc(N , sizeof(struct node_t));
	return top;
};

int size(struct node_t* top , int N)
{
	for (int i = 0 ; i < N ; i++)
	{
		if (((top + i) -> age) == 0)
			return i;
	};
	return N;
};

struct node_t* min_t(struct node_t* left , struct node_t* right)
{
	if ((left -> age) <= (right -> age))
		return left;
	else
		return right;
};

void swap (struct node_t* a , struct node_t* b)
{
	struct node_t per = *a;
	a -> age = b -> age;
	b -> age = per.age;
	a -> data = b -> data;
	b -> data = per.data;
};

void shift_down (struct node_t* top , int i , int N)
{
	int pright = 0;
	int pleft = 0;
	int sizet = size(top , N);
	while (right(i) < sizet)
	{
		int new_i = 0;
		pright = right(i);
		pleft = left(i);
		struct node_t* pmin = min_t((top + pleft) , (top + pright));
		if ((pmin -> age) == ((top + pright) -> age))
			new_i = pright;
		else
			new_i = pleft;
		swap((top + i) , (top + new_i));
		i = new_i;
	};
	if (left(i) < sizet)
		swap((top + i) , (top + left(i)));
};
		
		
		
	

void shift_up(struct node_t* top , int i)
{
	if (i == 0)
		return;
	int new_i = parent(i);
	if (((top + i) -> age) < ((top + new_i) -> age))
	{
		swap(top + i , (top + new_i));
		shift_up(top , new_i);
	};
};

void delete_min(struct node_t* top , int N)
{
	swap(top , (top + N - 1));
	((top + N - 1) -> age) = 0;
	((top + N - 1) -> data) = NULL;
};	

int check(struct node_t* top , int* data_t , int sizet)
{
	for (int i = 0 ; i < sizet ; i++)
	{
		if (*((top + i) -> data) == *data_t)
			return i;
	};
	return (-10);
};

void push(struct node_t* top , int i , int* data_t)
{
	((top + i) -> age)++;
	((top + i) -> data) = data_t;
};
	
void Incr_freq(struct node_t* top , int* data_t , int* N)
{
	int p = check(top , data_t , *N - 1);	
	if (p == -1)
	{
		int sizet = size(top , *N);
		if (sizet < *N)
		{
			push(top , sizet  , data_t);
			shift_up(top , sizet);
		}
		else
			if (sizet == N)
				{
					*N = *N + 1000;
					top = (struct node_t*)realloc(top , *N);
					push(top , sizet , data_t);
					shift_up(top , sizet);
				};
	}
	else
	{
		((top + p) -> age)++;
		shift_up(top , p);
		shift_down(top , p , *N);
	};
};

int Find_min(struct node_t* top , int N)
{
	return *(top -> data);
};

