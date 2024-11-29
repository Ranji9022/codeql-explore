#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>

int main() {
    int s;
    struct ifreq ifr;

    // Specify the network interface name (e.g., "eth0", "wlan0")
    char *interface = "eth0";

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        perror("Socket creation failed");
        return 1;
    }

    strncpy(ifr.ifr_name, interface, IFNAMSIZ-1);
    if (ioctl(s, SIOCGIFHWADDR, &ifr) < 0) {
        perror("ioctl failed");
        close(s);
        return 1;
    }

    close(s);

    unsigned char *mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;
    printf("MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
           mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

    return 0;
}
