/* Host machine description for Motorola Delta 88 system, for GDB.
   Copyright 1986, 1987, 1988, 1989, 1990, 1991 Free Software Foundation, Inc.

This file is part of GDB.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

#define HOST_BYTE_ORDER BIG_ENDIAN

#if !defined (USG)
#define USG 1
#endif

#define MAXPATHLEN 1024

#include <sys/param.h>
#include <sys/time.h>

#define HAVE_TERMIO

/*#define USIZE 2048*/
#define NBPG NBPC
#define UPAGES USIZE

/* Get rid of any system-imposed stack limit if possible.  */

/*#define SET_STACK_LIMIT_HUGE*/

/* This is the amount to subtract from u.u_ar0
   to get the offset in the core file of the register values.  */

/* Since registers r0 through r31 are stored directly in the struct ptrace_user,
   (for m88k BCS)
   the ptrace_user offsets are sufficient and KERNEL_U_ADDRESS can be 0 */

#define KERNEL_U_ADDR 0

#define REGISTER_U_ADDR(addr, blockend, regno) \
        (addr) = m88k_register_u_addr ((blockend),(regno));

#define FETCH_INFERIOR_REGISTERS

/* Address of end of stack space (in core files).  */

#define STACK_END_ADDR 0xF0000000
