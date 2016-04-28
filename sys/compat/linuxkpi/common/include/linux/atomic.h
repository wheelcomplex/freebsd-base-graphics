#ifndef _LINUX___ATOMIC_H_
#define _LINUX___ATOMIC_H_
#include <machine/atomic.h>

#define smp_rmb() rmb()
#define smb_wmb() wmb()
#define smb_mb() mb()

#define smp_mb__before_atomic() smb_mb()

#endif
