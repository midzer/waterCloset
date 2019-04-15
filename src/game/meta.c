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

#include "meta.h"

static void countCoinsItems(void);
static void countItemTextures(void);

void initStageMetaData(void)
{
	countCoinsItems();
	
	countItemTextures();
}

static void countCoinsItems(void)
{
	char filename[MAX_FILENAME_LENGTH], *json, *type;
	int n, exists;
	cJSON *root, *node;
	StageMeta *s, *tail;
	
	tail = &game.stageMetaHead;
	
	n = 1;
	
	do
	{
		sprintf(filename, "data/stages/%03d.json", n);
		
		exists = fileExists(filename);
		
		if (exists)
		{
			json = readFile(filename);
				
			root = cJSON_Parse(json);
			
			s = malloc(sizeof(StageMeta));
			memset(s, 0, sizeof(StageMeta));
			tail->next = s;
			tail = s;
			
			s->num = n;
			
			for (node = cJSON_GetObjectItem(root, "entities")->child ; node != NULL ; node = node->next)
			{
				type = cJSON_GetObjectItem(node, "type")->valuestring;
				
				if (strcmp(type, "coin") == 0)
				{
					s->coins++;
				}
				else if (strcmp(type, "item") == 0)
				{
					s->items++;
				}
			}
			
			free(json);
			
			cJSON_Delete(root);
			
			n++;
		}
		
	} while (exists);
}

static void countItemTextures(void)
{
	char filename[MAX_FILENAME_LENGTH];
	
	game.numItemTextures = 0;
	
	do
	{
		sprintf(filename, "gfx/entities/item%02d.png", ++game.numItemTextures);
	}
	while (fileExists(filename));
	
	/* one fewer */
	game.numItemTextures--;
}