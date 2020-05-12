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
	int value = NO_VALUE;
	int* ptr; //Указатель на твою структуру из частот
};

// Создает ячейку
struct list_d create_node(struct list_d parent) {
	struct list_d son = calloc(1, struct list_d);
	son.parent = *parent;
	son.value = NO_VALUE;

};

// Удаляем ячейку
struct list_d del_node(struct list_d parent) {
	parent.son = NULL;
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

//Удаляем из хэша значение
void hash_del(struct list_d* hash_t, int value, int cash_len) {
	//Находим ячейку в кэшэ
	int key = hash_f(value, cash_len);
	list_d node = hash_t[key];

	while (node.son != NULL || node.value != value)
		node = *node.son;
	node.value = NO_VALUE;

	// Перевязыаем сына удаляемой ячейки к отцу.
	node.son.parent = node.parent;

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
