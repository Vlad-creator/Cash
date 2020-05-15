#include <stdio.h>
#include <stdlib.h>

struct node_t
{
	int age = 100;
	int data = 0;
	struct node_t* next = NULL;
};






struct node_t* push_list(struct node_t* head, int data) {
	struct node_t* new_last = head;
	while (new_last->next != NULL)
		new_last = new_last->next;

	struct node_t* new_node = (struct node_t*)calloc(1, sizeof(struct node_t));
	new_last->next= new_node;

	new_last->next->age = 1;
	new_last->next->data = data;
	new_last->next->next = NULL;
	return new_last->next;
};

void Incr_freq(struct node_t* head, int value) {
	struct node_t* point = head;
	struct node_t* otvet = head;
	while (point->next != NULL) {
		if (point->data == value) {
			++point->age;
			return;
		}
		point = point->next;
	}
	push_list(head, value);

}

struct node_t* create_node(int data)
{
	struct node_t* head = (struct node_t*)calloc(1, sizeof(struct node_t));
	struct node_t* next = NULL;

	head->age = 1;
	head->data = data;
	head->next = next;
	return head;
};

int Find_Min(struct node_t* head)
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
	return otvet->data;
};

void print_list(FILE* f, struct node_t* p)
{
	while (p != NULL)
	{
		fprintf(f, "%d - %d\n", p->age, (p->data));
		p = p->next;
	}
}
