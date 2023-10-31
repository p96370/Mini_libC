#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
	struct timespec req, rem;
	req.tv_sec = (size_t)seconds;
	req.tv_nsec = 0;
	nanosleep(&req, &rem);
	return seconds;
}
//https://copyprogramming.com/howto/use-the-nanosleep-function-in-c
