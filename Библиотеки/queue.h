struct node_t
{
	int age;
	struct node_t* next;
}

struct node_t* push_list(struct node_t* last , int tag); //добавление элемента в конец списка
struct node_t* create_node(int age); //создание первой ячейки списка
void Find_Min(struct node_t* head); //нахождение ячейки с наименьшим приоритетом
