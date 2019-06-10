#include <stdio.h>
#include <stdlib.h>


__attribute__((constructor))
static void  load_preload( void)
{
   fprintf( stderr, "%s\n", __PRETTY_FUNCTION__);
}

