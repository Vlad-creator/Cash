#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#pragma warning (disable:4996)

int NO_VALUE = 0;
// Пишу здесь хэш функцию: массив из структур двухсвязных списков

// Одна ячейка двухсвязного списка
struct list_d {
	struct list_d* parent = NULL;
	struct list_d* son = NULL;
	int value;
	int* ptr; //Указатель на твою структуру из частот
};

// Создает ячейку
struct list_d create_node(struct list_d parent) {};

// Удаляем ячейку
struct list_d del_node(struct list_d parent) {};

// Хэш функция. Берет число, длину кэша и вычислят значение
int hash_f(int x, int cash_len) {
	return ((37 * x + 34) % 7) % cash_len;
}

// Создаем хэш таблицу и заполняем нулями
void create_hash(int cash_len, struct list_d** hash_t) {
	*hash_t = (struct list_d*)calloc(cash_len, sizeof(struct list_d));
}

//Удаляем из хэша значение
void hash_del(struct list_d* hash_t, int value, int cash_len) {
	//Находим ячейку в кэшэ
	int key = hash_f(value, cash_len);
	list_d node = hash_t[key];

	// Проверка на коллизии
	if (node.value == NULL) {
		node.value = NO_VALUE;
		del_node(node);
		//Здесь нужно удалить частоты
	}
	else {
		while (node.son != NULL)
			node = *node.son;
		node.value = NO_VALUE;
		del_node(node);
		// Здесь нужно удалить частоты
	}
};

// Добавляем в кэш новое значени и сдвигаем все предыдущие
int add_hash(struct list_d* hash_t, int cash_len, int value) {
	//Находим ячейку в кэшэ
	int key = hash_f(value, cash_len);
	list_d node = hash_t[key];

	//Проверка на коллизии
	if (node.value == NULL) {
		node.value = value;
		//Здесь нужно привязать к частотам
		create_node(node);
	}
	else {
		while (node.son != NULL)
			node = *node.son;
		node.value = value;
		// Здесь нужно привязать к частотам
		create_node(node);
	}

}


// Ищем в кэше элемент. Возвращает номер элемента либо -1.
int proc_val(int value, list_d* hash_t, int cash_len) {
}

int main (void) {


	int cash_len = 0;
	int req_len = 0; 
	int value = 0;
	int cash_miss = 0;
	int cash_catch = 0;
	struct list_d *hash_t = nullptr;

	//1. Input
	scanf("%d %d", &cash_len, &req_len);

	//2. Create Hash table
	create_hash(cash_len, &hash_t);

	//3. Full cash and hash table
	for (int i = 0; i < req_len; i++) {

		assert(scanf("%d", &value) == 1);
		
		// Проверка, есть ли в кэшэ нужное значение, или нет
		if (proc_val(value, hash_t, cash_len) == -1)
			cash_miss++;
		else
			cash_catch++;
	}

	//4. Answer
	printf("%d", cash_catch);

	return 0;
}
юююююю
