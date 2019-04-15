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

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define STRNCPY(dest, src, n) strncpy(dest, src, n); dest[n - 1] = '\0'

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

#define FPS   60

#define MAX_TILES    255

#define TILE_SIZE    48

#define MAP_WIDTH    108
#define MAP_HEIGHT   15

#define MAP_RENDER_WIDTH    27
#define MAP_RENDER_HEIGHT   15

#define PLAYER_MOVE_SPEED 6

#define MAX_TIPS    12

#define MAX_NAME_LENGTH           32
#define MAX_DESCRIPTION_LENGTH    256
#define MAX_LINE_LENGTH           1024
#define MAX_FILENAME_LENGTH       256
#define MAX_PATH_LENGTH           4096

#define MAX_KEYBOARD_KEYS   350
#define MAX_MOUSE_BUTTONS   6

#define MAX_SND_CHANNELS 16

#define NUM_ATLAS_BUCKETS 32

#define EF_NONE            0
#define EF_WEIGHTLESS      (2 << 0)
#define EF_SOLID           (2 << 1)
#define EF_PUSH            (2 << 2)
#define EF_NO_WORLD_CLIP   (2 << 3)
#define EF_SHIELDED        (2 << 4)

enum
{
	ET_PLAYER,
	ET_CLONE,
	ET_TOILET,
	ET_ITEM,
	ET_STRUCTURE,
	ET_BULLET,
	ET_TRAP,
	ET_SWITCH
};

enum
{
	WT_FADE_IN,
	WT_WIPE_IN,
	WT_WIPE_OUT
};

enum
{
	TEXT_LEFT,
	TEXT_CENTER,
	TEXT_RIGHT
};

enum
{
	FACING_LEFT,
	FACING_RIGHT
};

enum
{
	SND_JUMP,
	SND_COIN,
	SND_FLUSH,
	SND_PLUNGER,
	SND_KEY,
	SND_DEATH,
	SND_CLONE,
	SND_NUDGE,
	SND_TELEPORT,
	SND_WIPE,
	SND_SPIT,
	SND_SPIT_HIT,
	SND_MANHOLE_COVER,
	SND_CLOCK,
	SND_EXPIRED,
	SND_NEGATIVE,
	SND_FANFARE,
	SND_DOOR,
	SND_TRAFFIC_LIGHT,
	SND_ITEM,
	SND_FAIL,
	SND_TIP,
	SND_MAX
};

enum
{
	CH_PLAYER,
	CH_CLONE,
	CH_COIN,
	CH_ITEM,
	CH_SPIT,
	CH_HIT,
	CH_CLOCK,
	CH_SWITCH,
	CH_STRUCTURE
};

enum
{
	SS_INCOMPLETE,
	SS_COMPLETE,
	SS_FAILED
};
