#include <stdio.h>
#define SIZE_MAP_X 100
#define SIZE_MAP_Y 30
#define GREEN "\033[1;32m"
#define RESET "\033[0m"
#define START_Y 10
int map_array[SIZE_MAP_X][SIZE_MAP_Y];
int get_rand_range_int(int, int);
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
int math_next_y(int y, int x) {
	if (map_array[x + 1][y] == 1) return y;
	if (map_array[x + 1][y - 1] == 1) return y - 1;
	if (map_array[x + 1][y + 1] == 1) return y + 1;
}
void generate_grass() {
	int y = START_Y;
	int rand_number = 0;
	for (int x = 1; x < SIZE_MAP_X-1; x++)
	{
		map_array[x+1][y] = 1;
		map_array[x-1][y] = 1;
		map_array[x][y] = 1;
		rand_number = get_rand_range_int(0, 10);
		if (rand_number == 0) y++;
		else if (rand_number == 1) y--;
	}
}
void generate_stone() {
	int y = START_Y;
	int next_y = y;
	for (int x = 0; x < SIZE_MAP_X; x++)
	{
		while (y != SIZE_MAP_Y-10) {
			y++;
			map_array[x][y] = 2;
		}
		y = math_next_y(next_y, x);
		next_y = y;
	}
}
void generate_map() {
	generate_grass();
	generate_stone();
}
void display_map() {
		for (int y = 0; y < SIZE_MAP_Y; y++)
		{
			for (int x = 0; x < SIZE_MAP_X; x++)
			{
				printf("%c", convert_id_to_char(map_array[x][y]));
			}
			printf("\n");
		}
}
