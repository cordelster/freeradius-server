/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */
#ifndef _FR_PROCESS_H
#define _FR_PROCESS_H
/**
 * $Id$
 *
 * @file include/process.h
 * @brief State machine for a server to process packets.
 *
 * @author Arran Cudbard-Bell <a.cudbardb@freeradius.org>
 * @copyright  2012 The FreeRADIUS server project
 * @copyright  2012 Alan DeKok <aland@deployingradius.com
 */
RCSIDH(process_h, "$Id$")

#include <freeradius-devel/clients.h>
#include <freeradius-devel/listen.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum fr_state_action_t {	/* server action */
	FR_ACTION_INVALID = 0,
	FR_ACTION_RUN,
	FR_ACTION_DONE,			//!< Request is completed.  If a module is signalled
					///< with this, the module should stop processing
					///< the request and cleanup.
	FR_ACTION_DUP,			//!< A duplicate request was received.
} fr_state_action_t;

/*
 *  Function handler for requests.
 */
typedef	void (*fr_request_process_t)(REQUEST *, fr_state_action_t);

extern time_t fr_start_time;

/*
 *	More state machine helper functions.
 */
void request_delete(REQUEST *request);


#ifdef __cplusplus
}
#endif
#endif /* _FR_PROCESS_H */
