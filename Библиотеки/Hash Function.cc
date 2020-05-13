#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#pragma warning (disable:4996)
int NO_VALUE = 1;
// Пишу здесь хэш функцию: массив из структур двухсвязных списков

// Одна ячейка двухсвязного списка
struct list_d {
	struct list_d* parent = NULL;
	struct list_d* son = NULL;
	int value = NO_VALUE;
	int* ptr; //Указатель на твою структуру из частот
};

// Создает ячейку
void create_node(struct list_d* node) {
	struct list_d* son = (struct list_d*) calloc(1, sizeof(struct list_d));
	son->parent = node;
	son->value = NO_VALUE;

};

// Удаляем ячейку
void del_node(struct list_d* parent) {
	parent->son = NULL;
	free(parent);
};

// Хэш функция. Берет число, длину кэша и вычислят значение
int hash_f(int x, int cash_len) {
	return ((37 * x + 34) % 7) % cash_len;
}

// Создаем хэш таблицу и заполняем нулями
void create_hash(int cash_len, struct list_d** hash_t) {
	*hash_t = (struct list_d*)calloc(cash_len, sizeof(struct list_d));
}

//Удаляем из хэша значение (НЕ РАБОТАЕТ)
void hash_del(struct list_d* hash_t, int value, int cash_len) {
	//Находим ячейку в кэшэ
	int key = hash_f(value, cash_len);
	list_d node = hash_t[key];

	while (node.son != NULL || node.value != value)
		node = *node.son;
	node.value = NO_VALUE;

	// Перевязыаем сына удаляемой ячейки к отцу.
	node.son->parent = node.parent;

	del_node(&node);
	// Здесь нужно удалить частоты
}

// Добавляем в кэш новое значени и сдвигаем все предыдущие. (НЕ РАБОТАЕТ)
struct list_d* add_hash(struct list_d* hash_t, int cash_len, int value) {

	//Находим ячейку в кэшэ
	int key = hash_f(value, cash_len);
	list_d node = hash_t[key];

	//Проверка на коллизии
	if (node.value == NULL) {
		node.value = value;
		//Здесь нужно привязать к частотам
		create_node(&node);
	}
	else {
		while (node.son != NULL)
			node = *node.son;
		node.value = value;
		// Здесь нужно привязать к частотам
		create_node(&node);
	}
	return &node;
	
}
// Проверяем есть ли в кэшэ значение искомое. Если есть возвращает 1, если нет то 0.
int check_in_hash(int value, struct list_d* hash_t, int cash_len) {
	int key = hash_f(value, cash_len);
	list_d node = hash_t[key];
	while (node.value == 0 || node.son != NULL)
		node = *node.parent;
	if (node.value != 0)
		return 1;
	else
		return 0;
}
