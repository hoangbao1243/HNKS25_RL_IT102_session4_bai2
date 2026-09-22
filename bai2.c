#include <stdio.h>

int main() {
    int n, topping, member;
    int valid = 0, error = 0;
    char size;
    long long price, total = 0, max = 0;

    scanf("%d", &n);

    if (n <= 0) {
        printf("0 0 0 0");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%lld %c %d %d", &price, &size, &topping, &member);

        if (topping < 0) {
            break;
        }

        if (price <= 0 || (size != 'S' && size != 's' &&
            size != 'M' && size != 'm' &&
            size != 'L' && size != 'l')) {
            error++;
            continue;
        }

        if (size == 'M' || size == 'm')
            price += 6000;
        else if (size == 'L' || size == 'l')
            price += 10000;

        price += topping * 8000;

        if (member == 1)
            price = price * 90 / 100;

        total += price;
        valid++;

        if (price > max)
            max = price;
    }

    printf("%d %d %lld %lld", valid, error, total, max);

    return 0;
}