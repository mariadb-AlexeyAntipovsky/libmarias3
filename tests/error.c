/* vim:expandtab:shiftwidth=2:tabstop=2:smarttab:
 * Copyright 2019 MariaDB Corporation Ab. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301  USA
 */

#include <yatl/lite.h>
#include <libmarias3/marias3.h>

/* Tests basic error handling */

int main(int argc, char *argv[])
{
  (void) argc;
  (void) argv;
  uint8_t *data;
  size_t length;

  ms3_st *ms3 = ms3_init("12345678901234567890", "1234567890123456789012345678901234567890", "us-east-1", NULL);

//  ms3_debug(true);
  ASSERT_NOT_NULL(ms3);
  const char *errmsg = ms3_error(255);
  ASSERT_STREQ(errmsg, "No such error code");
  errmsg = ms3_error(0);
  ASSERT_STREQ(errmsg, "No error");
  uint8_t res= ms3_get(ms3, "bad", "bad/file.txt", &data, &length);
  printf("%d\n", res);
  ASSERT_EQ(res, 8); // Bad auth
  ms3_deinit(ms3);
}