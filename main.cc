#include "Hash_H.h"
#include "queue.h"



int check(int value, int cash_len, struct list_d* hash_t,struct node_t* knot, int* size) {
	struct list_d* node;
	if (check_in_hash(value, hash_t, cash_len) == 1) {
		//Если в хэшэ, то ищем в списке и увеличиваем частоту
		Incr_freq(knot,value);
		return 1;
	}
	else
		// Если не в списке, то проверяем заполненость хэша и если заполнен, то удаляем и добавляем. Если нет то добавляем в хэш и добавляем ячейку, увеличивая размер заполнености
		if (*size < cash_len) {
			// Добавить ячейку с нужным значением
			add_hash(hash_t, cash_len, value);
			// Создать привязку к частоте
			push_list(knot, value);
			*size+=1;
		}
		else {
			// Удалить ячейку с наименьшим приорететом
			hash_del(hash_t, Find_Min(knot), cash_len);
			// Добавить ячейку с нужным значением
			add_hash(hash_t, cash_len, value);
			// Увеличить частоту добавленного значения ИЛИ УВЕЛИЧИТЬ ЧАСТОТУ СУЩЕСТВУЕЩЕГО! ДОПИСАТЬ ТУТ!
			Incr_freq(knot,value);
		}

	return 0;
};

int main(void) {
	int cash_len, quest, value;
	int count = 0;
	struct list_d* hash_t;
	struct node_t* knot = (node_t*) calloc(1, sizeof(node_t));
	knot->age = 100; // костыли
	knot->data = 100; // костыли
	knot->next = NULL;
	int size = 0;
	
	// Читаем длину кэша и кол-во запросов
	scanf("%d%d", &cash_len, &quest);

	// Создаем пустую хэш таблицы
	create_hash(cash_len, &hash_t);

	for (int i = 0; i < quest;i++) {
		scanf("%d", &value);
		if (check(value,cash_len,hash_t,knot,&size) == 1)
			count++;
	}
	printf("%d", count);
}
