#include <genesis.h>
#include "mpsg.h"
#include "mpad.h"
#include "gamedata.h"
#include "player.h"
#include "globals.h"

const u16 octs[] =  {0,1,1, 1, 1, 1, 1,1,1,1,1,1 ,0,0, 1,1 ,0,0 ,0 ,1,1 ,0 ,0,0 ,0,0 ,0 ,0 ,0 ,0 ,0 ,0 ,13};
const u16 notes[] = {7,0,12,12,12,12,2,4,5,4,0,12,7,12,0,12,7,10,12,0,12,10,9,12,7,12,12,12,12,12,12,12,13};

const u16 oct2[] = {1,2,2,3,3,2,2,3,3,2,2,3,3,2,2,3,3,1,1,2,2,1,1,2,2,1,2,1,2,1,2,1,2,1,};
const u16 not2[] = {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,7,7,9,9,10,10,11,11};



void gameloop(void)
{
	for (int y = 0; y < 28; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			map[y][x] = 0;
	
			if (y == 27)
			{
				map[y][x] = 1;
			}
			
			if (y == 18 && x > 12 && x < 20)
			{
				map[y][x] = 1;
			}
		}
	}
	
	int i = 0;
	
	player_init(&p1);
	ghetto_map_render();	
	
	p1.grounded = 0;

	while (1)
	{
		player_take_inputs(&p1,pad_read(0));
		player_move(&p1);
		player_draw(&p1,0);
		VDP_waitVSync();
	}
}

int main(void)
{
	VDP_init();
	gameloop();
	while(1)
	{
		VDP_waitVSync();
	}
	return (0);	
}
