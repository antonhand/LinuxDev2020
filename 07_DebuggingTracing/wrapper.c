#define _GNU_SOURCE
#include <dlfcn.h>
#include <string.h>
#include <errno.h>

int unlinkat(int dirfd, const char* pathname, int flags)
{
	typeof(&unlinkat) orig_unlinkat = (typeof(&unlinkat))dlsym(RTLD_NEXT, "unlinkat");
	if (strstr(pathname, "FIX") != NULL)
	{
		errno = EPERM;
		return -1;
	}
	return orig_unlinkat(dirfd, pathname, flags);    	
}	