#include "llx.h"

int main()
{
	t_llx	*llx;

	llx = llx_init();
	if (!llx)
		return (1);
	return (llx_exec(llx));
}
