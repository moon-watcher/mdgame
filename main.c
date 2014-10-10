#include <genesis.h>
#include "mpsg.h"
#include "mpad.h"
#include "gamedata.h"
#include "player.h"
#include "globals.h"

void gameloop(void)
{
	for (int y = 0; y < 32; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			
			map[y][x] = 0;
			if (y > 12 && (x > 37 || x < 3))
			{
				map[y][x] = 1;
			}
			if (y > 19 && x > 37)
			{
				map[y][x] = 0;
			}
	
			if (y == 27 && x > 8)
			{
				map[y][x] = 1;
			}
			
			if ((y == 18 || y == 19)&& x > 12 && x < 20)
			{
				map[y][x] = 1;
			}
			if (y == 24 && x > 5 && x < 10)
			{
				map[y][x] = 1;
			}
			if (y == 31)
			{
				map[y][x] = 1;
			}
		}
	}
	
	
	VDP_drawText("wot u think ur doin on my lawn",8,25);
	VDP_drawText("get of my fekin lawn u kids",4,26);
	
	VDP_drawText("WELCOME TO CHAMP CLAMPS ROUND TSU",5,1);
	
	player_init(&p1);
	player_init(&p2);
	
	p1.palette = 1;
	p2.palette = 2;
	p2.sprite_num = 1;
	p1.tile_index = 1;
	p2.tile_index = 1;
	ghetto_map_render();
	
	
	int i = 0;

	while (1)
	{
		i++;
		if (i % 8 == 0)
		{
			p1.tile_index = (i >> 2)%16;
			p2.tile_index = (i >> 2)%16;
		}
		p1.sprite_num = i % 2;
		p2.sprite_num = (i + 1) % 2;
		player_take_inputs(&p1,pad_read(0));
		player_take_inputs(&p2,pad_read(1));
		player_move(&p1);
		player_move(&p2);
		VDP_waitVSync();
		player_draw(&p1);
		player_draw(&p2);
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
