/*
 * Copyright (C) 2006 The Android Open Source Project
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

#ifndef __CUTILS_SOCKETS_H
#define __CUTILS_SOCKETS_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <sys/socket.h>

#define ANDROID_SOCKET_ENV_PREFIX "ANDROID_SOCKET_"
#define ANDROID_SOCKET_DIR "/dev/socket"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * android_get_control_socket - simple helper function to get the file
 * descriptor of our init-managed Unix domain socket. `name' is the name of the
 * socket, as given in init.rc. Returns -1 on error.
 *
 * This is inline and not in libcutils proper because we want to use this in
 * third-party daemons with minimal modification.
 */
static inline int
android_get_control_socket (const char *name)
{
    char key[64];
    snprintf (key, sizeof (key), ANDROID_SOCKET_ENV_PREFIX "%s", name);

    const char *val = getenv (key);
    if (!val) {
        return -1;
    }

    errno = 0;
    int fd = strtol (val, NULL, 10);
    if (errno) {
        return -1;
    }

    return fd;
}

#ifdef __cplusplus
}
#endif

#endif /* __CUTILS_SOCKETS_H */
