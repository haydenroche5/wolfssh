/* ossh_certs.h
 *
 * Copyright (C) 2014-2022 wolfSSL Inc.
 *
 * This file is part of wolfSSH.
 *
 * wolfSSH is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * wolfSSH is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with wolfSSH.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _WOLFSSH_OSSH_CERTS_H_
#define _WOLFSSH_OSSH_CERTS_H_

#ifdef WOLFSSH_OSSH_CERTS

#ifdef WOLFSSL_USER_SETTINGS
#include <wolfssl/wolfcrypt/settings.h>
#else
#include <wolfssl/options.h>
#endif
#include <wolfssl/wolfcrypt/types.h>
#include <wolfssl/wolfcrypt/sha256.h>

#include <wolfssh/settings.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    MAX_OSSH_PRINCIPAL_MAX_NAME_SZ = 32
};

struct WOLFSSH_OSSH_PRINCIPAL {
    byte name[MAX_OSSH_PRINCIPAL_MAX_NAME_SZ];
    word32 nameSz;
    struct WOLFSSH_OSSH_PRINCIPAL* next;
} ;
typedef struct WOLFSSH_OSSH_PRINCIPAL WOLFSSH_OSSH_PRINCIPAL;

typedef struct {
    byte type;
    void* pubKey;
    byte caKeyFingerprint[WC_SHA256_DIGEST_SIZE];
    WOLFSSH_OSSH_PRINCIPAL* principals;
} WOLFSSH_OSSH_CERT;

WOLFSSH_LOCAL WOLFSSH_OSSH_CERT* OsshCertNew(void* heap);
WOLFSSH_LOCAL void OsshCertFree(WOLFSSH_OSSH_CERT* cert, void* heap);
WOLFSSH_LOCAL int ParseOsshCert(byte* in, word32 inSz, WOLFSSH_OSSH_CERT** out,
                                byte side, void* heap);

#ifdef __cplusplus
}
#endif

#endif /* WOLFSSH_OSSH_CERTS */

#endif /* _WOLFSSH_OSSH_CERTS_H_ */
