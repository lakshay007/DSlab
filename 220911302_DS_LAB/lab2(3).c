#include <stdio.h>

struct time {
    int hour;
    int min;
    int sec;
};

struct time addTime(struct time t1, struct time t2) {
    struct time result;
    int carry = 0;

    result.sec = t1.sec + t2.sec;
    if (result.sec >= 60) {
        result.sec -= 60;
        carry = 1;
    }

    result.min = t1.min + t2.min + carry;
    carry = 0;
    if (result.min >= 60) {
        result.min -= 60;
        carry = 1;
    }

    result.hour = t1.hour + t2.hour + carry;
    if (result.hour >= 24) {
        result.hour -= 24;
    }

    return result;
}

struct time differenceTime(struct time t1, struct time t2) {
    struct time result;

    if (t1.sec < t2.sec) {
        t1.sec += 60;
        t1.min--;
    }
    result.sec = t1.sec - t2.sec;

    if (t1.min < t2.min) {
        t1.min += 60;
        t1.hour--;
    }
    result.min = t1.min - t2.min;

    result.hour = t1.hour - t2.hour;

    return result;
}

void displayTime(struct time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

struct time readTime() {
    struct time t;
    printf("Enter time (hh:mm:ss): ");
    scanf(" %d: %d: %d", &t.hour, &t.min, &t.sec);
    return t;
}

int main() {
    printf("Enter the first time:\n");
    struct time time1 = readTime();

    printf("Enter the second time:\n");
    struct time time2 = readTime();

    struct time sum = addTime(time1, time2);
    struct time diff = differenceTime(time1, time2);

    printf("Sum of times: ");
    displayTime(sum);

    printf("Difference of times: ");
    displayTime(diff);

    return 0;
}
