
#ifndef _BIT_MATH_
#define _BIT_MATH_

#define SET_BIT(Reg,BitNo)   Reg |= (1<<BitNo)
#define CLR_BIT(Reg,BitNo)   Reg &= (~(1<<BitNo))
#define TOG_BIT(Reg,BitNo)   Reg ^= (1<<BitNo)
#define GET_BIT(Reg,BitNo)   ((Reg>>BitNo)&1)


#endif