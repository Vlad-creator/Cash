#include <stdio.h>
#include <stdlib.h>

struct node_t
{
	int age;
	int* data;
	struct node_t* next;
};

struct node_t* push_list(struct node_t* last, int* data)
{
	struct node_t* new_last = last->next;

	last->next = (struct node_t*)calloc(1, sizeof(struct node_t));

	last->next->age = 1;
	last->next->data = data;
	last->next->next = new_last;
	return last->next;
};

struct node_t* create_node(int* data)
{
	struct node_t* head = (struct node_t*)calloc(1, sizeof(struct node_t));
	struct node_t* next = NULL;

	head->age = 1;
	head->data = data;
	head->next = next;
	return head;
};

void Find_Min(struct node_t* head, int new_data)
{
	int min = head->age;
	struct node_t* point = head;
	struct node_t* otvet = head;
	while (point != NULL)
	{
		if ((point->age) <= min)
		{
			min = (point->age);
			otvet = point;
		};
		point = point->next;
	};
	otvet->age = 1;
	*(otvet->data) = new_data;
};

void print_list(FILE* f, struct node_t* p)
{
	while (p != NULL)
	{
		fprintf(f, "%d - %d\n", p->age, *(p->data));
		p = p->next;
	}
}
