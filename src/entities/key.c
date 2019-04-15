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

#include "key.h"

static void tick(void);
static void touch(Entity *other);
static void save(cJSON *root);

void initKey(Entity *e)
{
	Key *k;
	
	k = malloc(sizeof(Key));
	memset(k, 0, sizeof(Key));
	
	e->type = ET_ITEM;
	e->data = k;
	e->texture = loadTexture("gfx/entities/key.png");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->flags = EF_WEIGHTLESS;
	e->tick = tick;
	e->touch = touch;
	
	e->save = save;
	
	stage.totalKeys++;
}

static void tick(void)
{
	Key *k;
	
	k = (Key*)self->data;
	
	k->bobValue += 0.1;
	
	self->y += sin(k->bobValue);
}

static void touch(Entity *other)
{
	if (self->health > 0 && other != NULL && (other->type == ET_PLAYER || other->type == ET_CLONE))
	{
		self->health = 0;
		
		playSound(SND_KEY, CH_ITEM);
		
		addPowerupParticles(self->x + self->w / 2, self->y + self->h / 2);
		
		stage.keys++;
	}
}

static void save(cJSON *root)
{
	cJSON_AddStringToObject(root, "type", "key");
}