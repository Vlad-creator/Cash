#include "Hash_H.h"
#include "queue.h"



int check(int value, int cash_len, struct list_d* hash_t,struct node_t* knot, int* size) {
	struct list_d* node;
	if (check_in_hash(value, hash_t, cash_len) == 1) {
		//Если в хэшэ, то ищем в списке и увеличиваем частоту
		Find_Min(knot);
		return 1;
	}
	else
		// Если не в списке, то проверяем заполненость хэша и если заполнен, то удаляем и добавляем. Если нет то добавляем в хэш и добавляем ячейку, увеличивая размер заполнености
		if (*size < cash_len) {
			node = add_hash(hash_t, cash_len, value);
			push_list(knot, value);
			*size++;
		}
		else
			// Удаляем из хэша и добавляем новую ячейку
	return 0;
};

int main(void) {
	int cash_len, quest, value;
	int count = 0;
	struct list_d* hash_t;
	struct node_t knot;
	int size = 1;

	scanf("%d%d", &cash_len, &quest);
	create_hash(cash_len, &hash_t);

	while (scanf("%d", &value) == 1) {
		if (check(value,cash_len,hash_t,&knot,&size) == 1)
			count++;
	}
	printf("%d", count);
}
