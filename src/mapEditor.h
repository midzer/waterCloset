/*
Copyright (C) 2019 Parallel Realities

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "common.h"
#include "json/cJSON.h"

enum
{
	MODE_TILE,
	MODE_ENT,
	MODE_PICK
};

extern void blit(SDL_Texture *texture, int x, int y, int center);
extern void cleanup(void);
extern int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
extern void doInput(void);
extern void drawEntities(int background);
extern void drawMap(void);
extern void drawRect(int x, int y, int w, int h, int r, int g, int b, int a);
extern void drawText(int x, int y, int size, int align, SDL_Color color, const char *format, ...);
extern int fileExists(const char *filename);
extern Entity **initAllEnts(int *numEnts);
extern void initGame(void);
extern void initSDL(void);
extern void loadStage(int randomTiles);
extern SDL_Texture *loadTexture(char *filename);
extern void prepareScene(void);
extern void presentScene(void);
extern Entity *spawnEntity(void);
extern int writeFile(const char *filename, const char *data);

App app;
Entity *player;
Entity *self;
Game game;
Stage stage;