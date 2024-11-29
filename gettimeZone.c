#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *tm_local, *tm_gmt;
    char time_buffer[80];

    // Get current time
    time(&now);

    // Get local time and convert to string
    tm_local = localtime(&now);
    strftime(time_buffer, sizeof(time_buffer), "%c", tm_local);
    printf("Local time: %s\n", time_buffer);

    // Get GMT time and convert to string
    tm_gmt = gmtime(&now);
    strftime(time_buffer, sizeof(time_buffer), "%c", tm_gmt);
    printf("GMT time: %s\n", time_buffer);

    // Example: Get time in specific time zones
    // You'll need to set the appropriate time zone names
    struct tm *tm_tokyo, *tm_newyork;
    setenv("TZ", "Asia/Tokyo", 1); // Set time zone to Tokyo
    tm_tokyo = localtime(&now);
    setenv("TZ", "America/New_York", 1); // Set time zone to New York
    tm_newyork = localtime(&now);

    strftime(time_buffer, sizeof(time_buffer), "%c", tm_tokyo);
    printf("Tokyo time: %s\n", time_buffer);

    strftime(time_buffer, sizeof(time_buffer), "%c", tm_newyork);
    printf("New York time: %s\n", time_buffer);

    return 0;
}
