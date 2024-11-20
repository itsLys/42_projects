#include "ft_printf.h"


// |0x55f447d8d004|
// | 0x55f447d8d004|
// |(nil)|
// |(nil)|
// |                         (nil)|
// |      0x55f447d8d004|
// |0x55f447d8d004      |
// |     +0x55f447d8d004|
// |0x00000055f447d8d004|
// |+0x0000055f447d8d004|
// |+0x0000000055f447d8d004|
// |        0x0000000055f447d8d004|
// |                 +0x0000000055f447d8d004|
// if zero_flag exist
// 	print 0x, width - 2, and addr
// if !zero_flag 
// 	print width, and addr
// if left adjusted
// 	print addr and width
// if precision exist
// 	print 0x and 0s and addrs precision times
// if force sign
// 	prefix '+'
// if space 
// 	prefix ' '
// if ptr == null
// 	print (nil)

// TODO: Only printing is remaining, keep going
