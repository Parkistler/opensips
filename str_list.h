/*
 * Copyright (C) 2017 OpenSIPS Solutions
 *
 * This file is part of opensips, a free SIP server.
 *
 * opensips is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * opensips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */

#ifndef __STR_LIST__
#define __STR_LIST__

#include <stdlib.h>

#include "str.h"
#include "mem/mem.h"
#include "lib/osips_malloc.h"

struct str_list {
	str s;
	struct str_list *next;
};

static inline void _free_str_list(struct str_list *list,
                        osips_free_t free_item, osips_free_t free_str)
{
	struct str_list *prev;

	while (list) {
		prev = list;
		list = list->next;

		if (free_str)
			free_str(prev->s.s);

		if (free_item)
			free_item(prev);
	}
}

#define free_pkg_str_list(list) _free_str_list(list, pkg_free, pkg_free)
#define free_shm_str_list(list) _free_str_list(list, shm_free, shm_free)

#endif /* __STR_LIST__ */
