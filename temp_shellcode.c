 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <net/if.h>
 #include <netinet/in.h>
 #include <linux/can.h>
 #include <string.h>

int main(int argc, char *argv[]){
    int s;
    struct sockaddr_can addr;

    struct ifreq ifr;
    struct can_frame frame;

    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

    strcpy(ifr.ifr_name, "vcan0");
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    bind(s, (struct sockaddr *)&addr, sizeof(addr));

    frame.can_id = 0x510;
    frame.can_dlc = 8;
    frame.data[1] = 0xFF;
    while(1) {
        write(s, &frame, sizeof(struct can_frame));
        usleep(500000);
    }
}
