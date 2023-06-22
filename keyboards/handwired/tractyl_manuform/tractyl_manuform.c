/* Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "tractyl_manuform.h"
#include "transactions.h"
#include <string.h>

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif  // CONSOLE_ENABLE

__attribute__((weak)) void matrix_init_sub_kb(void) {}
void                       matrix_init_kb(void) {

    matrix_init_sub_kb();
    matrix_init_user();
}

__attribute__((weak)) void matrix_scan_sub_kb(void) {}
void                       matrix_scan_kb(void) {
    matrix_scan_sub_kb();
    matrix_scan_user();
}