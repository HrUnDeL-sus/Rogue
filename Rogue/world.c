#include <stdio.h>
#define GREEN "\033[1;32m"
#define RESET "\033[0m"
struct map
{
	int type;
	int size_x;
	int size_y;
	int *array;
};
struct world {
	struct map maps[40];
};
struct world* my_world;
const int COUNT_MAP = 40;
char convert_id_to_char(int id) {

	switch (id)
	{
	case 0:
		return ' ';
	case 1:
		printf("%s", GREEN);
		return 'T';
	case 2:
		printf("%s", RESET);
		return 'S';
	}
}
void display_world_info() {
	for (size_t i = 0; i < COUNT_MAP; i++)
	{
		struct map* mapp = (my_world->maps + i);
		printf("size x:%d\nsize y:%d\ntype:%d\n", mapp->size_x, mapp->size_y, mapp->type);
	}
}
void generate_world() {
	my_world= (struct world*)malloc(sizeof(struct world));
	int type_map = 0;
	int size_x_map = 100;
	int size_y_map = 50;
	for (size_t i = 0; i < 40; i++)
	{
		my_world->maps[i].size_x = size_x_map;
		my_world->maps[i].size_y = size_y_map;
		my_world->maps[i].type = type_map;
		size_x_map += 10;
		if (i % 10 == 0) {
			type_map++;
		}
	}
}
void display_map() {
}
