#include <sys/timerfd.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void) {
        int fd = timerfd_create(CLOCK_REALTIME, 0);
        timerfd_settime(fd, TFD_TIMER_ABSTIME | TFD_TIMER_CANCEL_ON_SET,
                        &(struct itimerspec){ .it_value = { .tv_sec = INT_MAX } },
                        NULL);
        printf("Waiting\n");
        char buffer[10];
        if (-1 == read(fd, &buffer, 10)) {
                if (errno == ECANCELED)
                        printf("Timer cancelled - system clock changed\n");
                else
                        perror("error");
        }
        close(fd);
        return 0;
}

