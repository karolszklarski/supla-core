/*
 Copyright (C) AC SOFTWARE SP. Z O.O.

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "gpio.h"
#include "log.h"
#include "tools.h"

void gpio_wait(TGpioPort *port, int count, int usec, _func_gpio_portvalue on_portvalue) {
  const int max = 80;
  char buffer[max];
  sleep(1);
  while (1) {
    int numRead = read(0, buffer, max);
    if (numRead <= 0) {
      break;
    }
    buffer[numRead - 1] = 0;
    int gpio, value;
    if (sscanf(buffer, "%d %d", &gpio, &value) != 2) {
      supla_log(LOG_INFO, "sscanf problem: '%s'", buffer);
      break;
    }
    supla_log(LOG_INFO, "gpio %i value %i", gpio, value);
    for (int a = 0; a < count; a++) {
      if (port[a].number == gpio) {
        port[a].value = value > 0 ? 1 : 0;
        on_portvalue(&port[a]);
        break;
      }
    }
  }
}

char gpio_set_value(unsigned char port_number, char value) {
  supla_log(LOG_INFO, "gpio_set_value port %i value %i", port_number, value);
  return 0;
}

char gpio_get_value(unsigned char port_number, char *value) {
  *value = 1;
  supla_log(LOG_INFO, "gpio_get_value port %i value %i", port_number, *value);
  return 0;
}

char gpio_port_init(unsigned char port_number, unsigned char in, char value) {
  supla_log(LOG_INFO, "gpio_port_init port %i in %i value %i", port_number, in, value);
  fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
  return 1;
}
