#include <stdio.h>
#include <stdlib.h>


#define PLAYER_NUM 3
#define MAX_HAND_CARD_NUM 20

enum CARD_POINTS{
	POINT_NULL,
	POINT_1,
	POINT_2,
	POINT_3,
	POINT_4,
	POINT_5,
	POINT_6,
	POINT_7,
	POINT_8,
	POINT_9,
	POINT_10,
	POINT_11,
	POINT_12,
	POINT_13,
	POINT_BLACK_JOKER,
	POINT_RED_JOKER,
};


#define POINT_A 14 // real value of A


int g_pokers[PLAYER_NUM][MAX_HAND_CARD_NUM] = {0};

int t_pokers[MAX_HAND_CARD_NUM] = {
	3,4,5,6,7,
	4,5,6,7,8,
	10,11,12,13,1,
	9,10,11,12,3
};

struct straight {
	int len;
	int start;
};

static void stats_points(int *pokers, int *stats)
{
	int i;
	for ( i = 0; i < MAX_HAND_CARD_NUM; i++ )
	{
		stats[pokers[i]]++;
	}
}

static int get_straight(int *stats, struct straight *straight)
{
	int i = POINT_A;
	int s_i = 0;
	while (i >= POINT_7)
	{
		int l = 0;
		while ( stats[i-l] != 0)
			l++;
		if ( l >= 5 )
		{
			int j;
			straight[s_i].len = l;
			straight[s_i].start = i-l+1;
			s_i++;

			for( j = 0; j < l; j++)
				stats[i-j]--;
		}
		else 
			i -= l+1;
	}
	return s_i;
}

int system_init(int *pokers)
{

	int stats[POINT_RED_JOKER] = {0};
	struct straight straight[4] = {0};
	int num_straight = 0;
	stats_points(pokers, stats);
	// check 2, black joker and red joker;
	stats[POINT_A] = stats[POINT_1];
	stats[POINT_1] = 0;


	num_straight = get_straight(stats, straight);

	return 0;
}

int main(int argc, char **argv)
{


	system_init(t_pokers);

//	printf("Hello world!\n");
	return 0;
}