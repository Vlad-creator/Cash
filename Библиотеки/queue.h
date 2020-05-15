#pragma once
struct node_t
{
	int age = 100;
	int data = 0;
	struct node_t* next = nullptr;
	
};

struct node_t* push_list(struct node_t* last, int tag); //добавление элемента в конец списка
struct node_t* create_node(int age); //создание первой ячейки списка
int Find_Min(struct node_t* head); //нахождение ячейки с наименьшим приоритетом


// Написать фунцкию, которая находит частоту  данного значения и увеличивает на единицу ИЛИ ДОБАВЛЯЕТ ЕГО В СПИСОК!
void Incr_freq(struct node_t* head, int value);

// Переписать Find_Min, чтобы возваращала int  с минимальным значением
