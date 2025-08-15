#include <stdio.h>
int main(void) {
itn x = 3, y = 7, z[5] = {2, 4, 6, 8, 10}, *ix;
printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4]\n", x, y, z[0], z[1], z[2], );
ix = &x;
y = *ix;
*ix = 1;
printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4]\n", x, y, z[0], z[1], z[2], );
ix = z;
*ix += 1;
y = *ix;
printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4]\n", x, y, z[0], z[1], z[2], );
ix = ix + 1;
y = *ix;
printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4]\n", x, y, z[0], z[1], z[2], );
ix += 1;
*ix += 1;
y = *ix;
printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4]\n", x, y, z[0], z[1], z[2], );
return 0;
}
