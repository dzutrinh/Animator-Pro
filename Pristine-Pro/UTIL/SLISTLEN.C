#include "linklist.h"

/***********************************************************/
int slist_len(register Slnode *list)
{
register int count = 0;

	while (list)
	{
		count++;
		list = list->next;
	}
	return(count);
}
