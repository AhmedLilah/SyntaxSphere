#include <stdio.h>
#include <stdarg.h>

// count of the remaining arg
// remaining args
double average ( const int count, ...) {
        va_list ap;
        int i;
        double total = 0.0;

        va_start(ap, count);
        for (i = 0; i < count; ++ i) {
                total += va_arg(ap, double);
        }
        va_end(ap);
        return total / count;
}

// message works like printf , format plus args
// sends newline after message
int message(const char* fmt, ...) {
        va_list ap;
        va_start(ap, fmt);
        int rc = vfprintf(stdout, fmt, ap);
        puts ("");
        va_end (ap);
        return rc;

}

int main() {
        message("this is a message");
        message("average: %lf;", average(5, 25.0, 35.7, 50.1, 127.6, 75.0));
        message("average: %lf;", average(6, "name", "name", "name", "name", "name", "name"));
        return 0;
}
