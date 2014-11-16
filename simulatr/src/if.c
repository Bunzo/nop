#include "processor.h"

Uint if_full(Uint pid)
{
	return PE(pid).plif.top-1 == PE(pid).plif.bot;
}

Uint if_empty(Uint pid)
{
	return PE(pid).plif.top == PE(pid).plif.bot;
}
