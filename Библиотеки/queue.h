struct node_t
{
	int age;
	struct node_t* next;
}

struct node_t* push_list(struct node_t* last , int tag);
struct node_t* create_node(int age);
void Find_Min(struct node_t* head);
