/*

#include <stdio.h>
#include <random>

#define NGAMES		10'000'000

int roll_dice(void)
{
	static std::mt19937 eng;
	static std::uniform_int_distribution<int> dist(1, 6);
	int dice_1 = dist(eng);
	int dice_2 = dist(eng);

	return dice_1 + dice_2;
}

//1 --> player wins
//0 --> player loses

int game_(int dice)
{
	int new_dice;

	for (;;) {
		new_dice = roll_dice();
		if (new_dice == dice)
			return 1;
		if (new_dice == 7)
			return 0;
	}
}

int game(void)
{
	int dice = roll_dice();

	switch (dice) {
	case 7:
	case 11: return 1;
	case 2:
	case 3:
	case 12: return 0;
	default: return game_(dice);
	}
}

int main()
{
	int win_count = 0;

	for (int i = 0; i < NGAMES; ++i) {
		win_count += game();
	}

	printf("Kazanma olasiligi = %f\n", (double)win_count / NGAMES);
}

*/
