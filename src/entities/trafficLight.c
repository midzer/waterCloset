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

#include "trafficLight.h"

static void toggle(void);
static void touch(Entity *other);
static void load(cJSON *root);
static void save(cJSON *root);

static SDL_Texture *goTexture;
static SDL_Texture *stopTexture;

void initTrafficLight(Entity *e)
{
	TrafficLight *t;
	
	goTexture = loadTexture("gfx/entities/trafficLightGo.png");
	stopTexture = loadTexture("gfx/entities/trafficLightStop.png");
	
	t = malloc(sizeof(TrafficLight));
	memset(t, 0, sizeof(TrafficLight));
	
	e->type = ET_SWITCH;
	e->data = t;
	e->texture = stopTexture;
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->touch = touch;
	
	e->load = load;
	e->save = save;
}

static void touch(Entity *other)
{
	Clone *c;
	Player *p;
	
	if (other != NULL)
	{
		if (other->type == ET_PLAYER)
		{
			p = (Player*)other->data;
			
			if (p->action)
			{
				p->action = 0;
				
				toggle();
			}
		}
		else if (other->type == ET_CLONE)
		{
			c = (Clone*)other->data;
			
			if (isValidCloneFrame(c) && c->data.action)
			{
				c->data.action = 0;
				
				toggle();
			}
		}
	}
}

static void toggle(void)
{
	TrafficLight *t;
	
	t = (TrafficLight*)self->data;
	
	t->on = !t->on;
	
	activeEntities(t->targetName, t->on);
	
	if (t->on)
	{
		self->texture = goTexture;
	}
	else
	{
		self->texture = stopTexture;
	}
	
	playSound(SND_TRAFFIC_LIGHT, CH_SWITCH);
}

static void load(cJSON *root)
{
	TrafficLight *t;
	
	t = (TrafficLight*)self->data;
	
	t->on = cJSON_GetObjectItem(root, "on")->valueint;
	STRNCPY(t->targetName, cJSON_GetObjectItem(root, "targetName")->valuestring, MAX_NAME_LENGTH);
	
	if (t->on)
	{
		self->texture = goTexture;
	}
	else
	{
		self->texture = stopTexture;
	}
}

static void save(cJSON *root)
{
	TrafficLight *t;
	
	t = (TrafficLight*)self->data;
	
	cJSON_AddStringToObject(root, "type", "trafficLight");
	cJSON_AddStringToObject(root, "targetName", t->targetName);
	cJSON_AddNumberToObject(root, "on", t->on);
}