#include <gpiod.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define CONSUMER "BlinkLED"
#define GPIO_PIN 22

int main() {
    struct gpiod_chip* chip;
    struct gpiod_line* line;

    chip = gpiod_chip_open_by_name("gpiochip0");
    if (!chip) {
        perror("Open gpiochip0 failed");
        exit(1);
    }

    line = gpiod_chip_get_line(chip, GPIO_PIN);
    if (!line) {
        perror("Get GPIO line failed");
        gpiod_chip_close(chip);
        exit(1);
    }

    if (gpiod_line_request_output(line, CONSUMER, 0) < 0) {
        perror("Request line as output failed");
        gpiod_chip_close(chip);
        exit(1);
    }

    // 🔁 Loop ตลอดไป
    while (1) {
        gpiod_line_set_value(line, 1); // ON
        sleep(1);
        gpiod_line_set_value(line, 0); // OFF
        sleep(1);
    }

    // จะไม่มาถึงตรงนี้ แต่เขียนไว้เผื่อ future enhancement
    gpiod_line_release(line);
    gpiod_chip_close(chip);
    return 0;
}
