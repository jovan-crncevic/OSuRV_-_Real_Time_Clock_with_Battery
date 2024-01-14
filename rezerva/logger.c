#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main() {
    // Open the connection to the system logger
    openlog("MyProgram", LOG_PID | LOG_CONS, LOG_USER);

    // Log a message with priority LOG_INFO
    syslog(LOG_INFO, "This is an informational message.");

    // Log a message with priority LOG_ERR
    syslog(LOG_ERR, "This is an error message.");

    // Close the connection to the system logger
    closelog();

    return 0;
}

