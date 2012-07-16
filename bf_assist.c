#import "bf.h"

void
initZero (char *array, long length)
{
  long i;
  for (i = 0; i < length; i++, array++)
    *array = 0;
}
