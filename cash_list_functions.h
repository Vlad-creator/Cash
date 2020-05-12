#pragma once

struct node_t
{
	int age;
	struct node_t* next;
}

struct node_t* push_list(struct node_t* last , int tag);//добавление эелемента в конец списка
struct node_t* create_node(int age);//создание первой ячейки
void Find_Min(struct node_t* head);//поиск эелемента с наименьшим приоритетом

