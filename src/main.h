/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _MAIN_H
#define _MAIN_H

#include <sys/cdefs.h>

__BEGIN_DECLS

int main (int argc, char *argv[]);
void quit (void);

void setup_proxy_uids (unsigned *uids, unsigned count, unsigned last_uid);

void setup_dns (const char *dns1, const char *dns2);
void setup_dns_proxy (const char *dns1, const char *dns2);
void setup_dns_for_net (unsigned netid, const char *dns1, const char *dns2);

__END_DECLS

#endif // _MAIN_H
