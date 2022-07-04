#include <unistd.h>

using namespace std;

int main() {
    char buf[14];

    int w = 0;
    int h = 0;
    read(0, buf, 14);
    auto* ptr = buf;
    while (*ptr != ' ') {
        w *= 10;
        w += *ptr++ - '0';
    }
    ++ptr;
    while (*ptr != '\n') {
        h *= 10;
        h += *ptr++ - '0';
    }
    
    auto result = w * h - 1;
    ptr = buf + 13;
    *ptr-- = '\n';
    if (result == 0) {
        *ptr-- = '0';
    } else {
        while (result > 0) {
            *ptr-- = result % 10 + '0';
            result /= 10;
        }
    }

    write(1, ptr + 1, buf + 13 - ptr - 1);
    return 0;
}
