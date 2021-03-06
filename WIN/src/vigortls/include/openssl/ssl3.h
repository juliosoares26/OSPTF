/*
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */
/* ====================================================================
 * Copyright 2002 Sun Microsystems, Inc. ALL RIGHTS RESERVED.
 * ECC cipher suite support in OpenSSL originally developed by
 * SUN MICROSYSTEMS, INC., and contributed to the OpenSSL project.
 */

#ifndef HEADER_SSL3_H
#define HEADER_SSL3_H

#include <openssl/buffer.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Signalling cipher suite value from RFC 5746
 * (TLS_EMPTY_RENEGOTIATION_INFO_SCSV)
 */
#define SSL3_CK_SCSV                        0x030000FF

/*
 * Signalling cipher suite value from RFC 7507
 * (TLS_FALLBACK_SCSV)
 */
#define SSL3_CK_FALLBACK_SCSV               0x03005600

#define SSL3_CK_RSA_NULL_MD5                0x03000001
#define SSL3_CK_RSA_NULL_SHA                0x03000002
#define SSL3_CK_RSA_RC4_40_MD5              0x03000003
#define SSL3_CK_RSA_RC4_128_MD5             0x03000004
#define SSL3_CK_RSA_RC4_128_SHA             0x03000005
#define SSL3_CK_RSA_RC2_40_MD5              0x03000006
#define SSL3_CK_RSA_IDEA_128_SHA            0x03000007
#define SSL3_CK_RSA_DES_40_CBC_SHA          0x03000008
#define SSL3_CK_RSA_DES_64_CBC_SHA          0x03000009
#define SSL3_CK_RSA_DES_192_CBC3_SHA        0x0300000A

#define SSL3_CK_DH_DSS_DES_40_CBC_SHA       0x0300000B
#define SSL3_CK_DH_DSS_DES_64_CBC_SHA       0x0300000C
#define SSL3_CK_DH_DSS_DES_192_CBC3_SHA     0x0300000D
#define SSL3_CK_DH_RSA_DES_40_CBC_SHA       0x0300000E
#define SSL3_CK_DH_RSA_DES_64_CBC_SHA       0x0300000F
#define SSL3_CK_DH_RSA_DES_192_CBC3_SHA     0x03000010

#define SSL3_CK_EDH_DSS_DES_40_CBC_SHA      0x03000011
#define SSL3_CK_EDH_DSS_DES_64_CBC_SHA      0x03000012
#define SSL3_CK_EDH_DSS_DES_192_CBC3_SHA    0x03000013
#define SSL3_CK_EDH_RSA_DES_40_CBC_SHA      0x03000014
#define SSL3_CK_EDH_RSA_DES_64_CBC_SHA      0x03000015
#define SSL3_CK_EDH_RSA_DES_192_CBC3_SHA    0x03000016

#define SSL3_CK_ADH_RC4_40_MD5              0x03000017
#define SSL3_CK_ADH_RC4_128_MD5             0x03000018
#define SSL3_CK_ADH_DES_40_CBC_SHA          0x03000019
#define SSL3_CK_ADH_DES_64_CBC_SHA          0x0300001A
#define SSL3_CK_ADH_DES_192_CBC_SHA         0x0300001B

/* VRS Additional Kerberos5 entries */
#define SSL3_CK_KRB5_DES_64_CBC_SHA         0x0300001E
#define SSL3_CK_KRB5_DES_192_CBC3_SHA       0x0300001F
#define SSL3_CK_KRB5_RC4_128_SHA            0x03000020
#define SSL3_CK_KRB5_IDEA_128_CBC_SHA       0x03000021
#define SSL3_CK_KRB5_DES_64_CBC_MD5         0x03000022
#define SSL3_CK_KRB5_DES_192_CBC3_MD5       0x03000023
#define SSL3_CK_KRB5_RC4_128_MD5            0x03000024
#define SSL3_CK_KRB5_IDEA_128_CBC_MD5       0x03000025

#define SSL3_CK_KRB5_DES_40_CBC_SHA         0x03000026
#define SSL3_CK_KRB5_RC2_40_CBC_SHA         0x03000027
#define SSL3_CK_KRB5_RC4_40_SHA             0x03000028
#define SSL3_CK_KRB5_DES_40_CBC_MD5         0x03000029
#define SSL3_CK_KRB5_RC2_40_CBC_MD5         0x0300002A
#define SSL3_CK_KRB5_RC4_40_MD5             0x0300002B

#define SSL3_TXT_RSA_NULL_MD5               "NULL-MD5"
#define SSL3_TXT_RSA_NULL_SHA               "NULL-SHA"
#define SSL3_TXT_RSA_RC4_40_MD5             "EXP-RC4-MD5"
#define SSL3_TXT_RSA_RC4_128_MD5            "RC4-MD5"
#define SSL3_TXT_RSA_RC4_128_SHA            "RC4-SHA"
#define SSL3_TXT_RSA_RC2_40_MD5             "EXP-RC2-CBC-MD5"
#define SSL3_TXT_RSA_IDEA_128_SHA           "IDEA-CBC-SHA"
#define SSL3_TXT_RSA_DES_40_CBC_SHA         "EXP-DES-CBC-SHA"
#define SSL3_TXT_RSA_DES_64_CBC_SHA         "DES-CBC-SHA"
#define SSL3_TXT_RSA_DES_192_CBC3_SHA       "DES-CBC3-SHA"

#define SSL3_TXT_DH_DSS_DES_40_CBC_SHA      "EXP-DH-DSS-DES-CBC-SHA"
#define SSL3_TXT_DH_DSS_DES_64_CBC_SHA      "DH-DSS-DES-CBC-SHA"
#define SSL3_TXT_DH_DSS_DES_192_CBC3_SHA    "DH-DSS-DES-CBC3-SHA"
#define SSL3_TXT_DH_RSA_DES_40_CBC_SHA      "EXP-DH-RSA-DES-CBC-SHA"
#define SSL3_TXT_DH_RSA_DES_64_CBC_SHA      "DH-RSA-DES-CBC-SHA"
#define SSL3_TXT_DH_RSA_DES_192_CBC3_SHA    "DH-RSA-DES-CBC3-SHA"

#define SSL3_TXT_EDH_DSS_DES_40_CBC_SHA     "EXP-EDH-DSS-DES-CBC-SHA"
#define SSL3_TXT_EDH_DSS_DES_64_CBC_SHA     "EDH-DSS-DES-CBC-SHA"
#define SSL3_TXT_EDH_DSS_DES_192_CBC3_SHA   "EDH-DSS-DES-CBC3-SHA"
#define SSL3_TXT_EDH_RSA_DES_40_CBC_SHA     "EXP-EDH-RSA-DES-CBC-SHA"
#define SSL3_TXT_EDH_RSA_DES_64_CBC_SHA     "EDH-RSA-DES-CBC-SHA"
#define SSL3_TXT_EDH_RSA_DES_192_CBC3_SHA   "EDH-RSA-DES-CBC3-SHA"

#define SSL3_TXT_ADH_RC4_40_MD5             "EXP-ADH-RC4-MD5"
#define SSL3_TXT_ADH_RC4_128_MD5            "ADH-RC4-MD5"
#define SSL3_TXT_ADH_DES_40_CBC_SHA         "EXP-ADH-DES-CBC-SHA"
#define SSL3_TXT_ADH_DES_64_CBC_SHA         "ADH-DES-CBC-SHA"
#define SSL3_TXT_ADH_DES_192_CBC_SHA        "ADH-DES-CBC3-SHA"

#define SSL3_TXT_KRB5_DES_64_CBC_SHA        "KRB5-DES-CBC-SHA"
#define SSL3_TXT_KRB5_DES_192_CBC3_SHA      "KRB5-DES-CBC3-SHA"
#define SSL3_TXT_KRB5_RC4_128_SHA           "KRB5-RC4-SHA"
#define SSL3_TXT_KRB5_IDEA_128_CBC_SHA      "KRB5-IDEA-CBC-SHA"
#define SSL3_TXT_KRB5_DES_64_CBC_MD5        "KRB5-DES-CBC-MD5"
#define SSL3_TXT_KRB5_DES_192_CBC3_MD5      "KRB5-DES-CBC3-MD5"
#define SSL3_TXT_KRB5_RC4_128_MD5           "KRB5-RC4-MD5"
#define SSL3_TXT_KRB5_IDEA_128_CBC_MD5      "KRB5-IDEA-CBC-MD5"

#define SSL3_TXT_KRB5_DES_40_CBC_SHA        "EXP-KRB5-DES-CBC-SHA"
#define SSL3_TXT_KRB5_RC2_40_CBC_SHA        "EXP-KRB5-RC2-CBC-SHA"
#define SSL3_TXT_KRB5_RC4_40_SHA            "EXP-KRB5-RC4-SHA"
#define SSL3_TXT_KRB5_DES_40_CBC_MD5        "EXP-KRB5-DES-CBC-MD5"
#define SSL3_TXT_KRB5_RC2_40_CBC_MD5        "EXP-KRB5-RC2-CBC-MD5"
#define SSL3_TXT_KRB5_RC4_40_MD5            "EXP-KRB5-RC4-MD5"

#define SSL3_SSL_SESSION_ID_LENGTH 32
#define SSL3_MAX_SSL_SESSION_ID_LENGTH 32

#define SSL3_MASTER_SECRET_SIZE 48
#define SSL3_RANDOM_SIZE 32
#define SSL3_SEQUENCE_SIZE 8
#define SSL3_SESSION_ID_SIZE 32
#define SSL3_RT_HEADER_LENGTH 5
#define SSL3_CIPHER_VALUE_SIZE 2

#define SSL3_HM_HEADER_LENGTH 4

#define SSL3_ALIGN_PAYLOAD 8

/*
 * This is the maximum MAC (digest) size used by the SSL library.
 * Currently maximum of 20 is used by SHA1, but we reserve for
 * future extension for 512-bit hashes.
 */

#define SSL3_RT_MAX_MD_SIZE 64

/* Maximum block size used in all ciphersuites. Currently 16 for AES.
 */

#define SSL_RT_MAX_CIPHER_BLOCK_SIZE 16

#define SSL3_RT_MAX_EXTRA (16384)

/* Maximum plaintext length: defined by SSL/TLS standards */
#define SSL3_RT_MAX_PLAIN_LENGTH 16384
/* Maximum compression overhead: defined by SSL/TLS standards */
#define SSL3_RT_MAX_COMPRESSED_OVERHEAD 1024

/*
 * The standards give a maximum encryption overhead of 1024 bytes.
 * In practice the value is lower than this. The overhead is the maximum
 * number of padding bytes (256) plus the mac size.
 */
#define SSL3_RT_MAX_ENCRYPTED_OVERHEAD (256 + SSL3_RT_MAX_MD_SIZE)

/*
 * OpenSSL currently only uses a padding length of at most one block so
 * the send overhead is smaller.
 */

#define SSL3_RT_SEND_MAX_ENCRYPTED_OVERHEAD \
    (SSL_RT_MAX_CIPHER_BLOCK_SIZE + SSL3_RT_MAX_MD_SIZE)

/* If compression isn't used don't include the compression overhead */
#define SSL3_RT_MAX_COMPRESSED_LENGTH SSL3_RT_MAX_PLAIN_LENGTH
#define SSL3_RT_MAX_ENCRYPTED_LENGTH \
    (SSL3_RT_MAX_ENCRYPTED_OVERHEAD + SSL3_RT_MAX_COMPRESSED_LENGTH)
#define SSL3_RT_MAX_PACKET_SIZE \
    (SSL3_RT_MAX_ENCRYPTED_LENGTH + SSL3_RT_HEADER_LENGTH)

#define SSL3_MD_CLIENT_FINISHED_CONST "\x43\x4C\x4E\x54"
#define SSL3_MD_SERVER_FINISHED_CONST "\x53\x52\x56\x52"

#define SSL3_VERSION        0x0300
#define SSL3_VERSION_MAJOR  0x03
#define SSL3_VERSION_MINOR  0x00

#define SSL3_RT_CHANGE_CIPHER_SPEC  20
#define SSL3_RT_ALERT               21
#define SSL3_RT_HANDSHAKE           22
#define SSL3_RT_APPLICATION_DATA    23
#define TLS1_RT_HEARTBEAT           24

/* Pseudo content types to indicate additional parameters */
#define TLS1_RT_CRYPTO                  0x1000
#define TLS1_RT_CRYPTO_PREMASTER        (TLS1_RT_CRYPTO | 0x1)
#define TLS1_RT_CRYPTO_CLIENT_RANDOM    (TLS1_RT_CRYPTO | 0x2)
#define TLS1_RT_CRYPTO_SERVER_RANDOM    (TLS1_RT_CRYPTO | 0x3)
#define TLS1_RT_CRYPTO_MASTER           (TLS1_RT_CRYPTO | 0x4)

#define TLS1_RT_CRYPTO_READ             0x0000
#define TLS1_RT_CRYPTO_WRITE            0x0100
#define TLS1_RT_CRYPTO_MAC              (TLS1_RT_CRYPTO | 0x5)
#define TLS1_RT_CRYPTO_KEY              (TLS1_RT_CRYPTO | 0x6)
#define TLS1_RT_CRYPTO_IV               (TLS1_RT_CRYPTO | 0x7)
#define TLS1_RT_CRYPTO_FIXED_IV         (TLS1_RT_CRYPTO | 0x8)

/* Pseudo content type for SSL/TLS header info */
#define SSL3_RT_HEADER                  0x100

#define SSL3_AL_WARNING 1
#define SSL3_AL_FATAL   2

#define SSL3_AD_CLOSE_NOTIFY            0
#define SSL3_AD_UNEXPECTED_MESSAGE      10 /* fatal */
#define SSL3_AD_BAD_RECORD_MAC          20 /* fatal */
#define SSL3_AD_DECOMPRESSION_FAILURE   30 /* fatal */
#define SSL3_AD_HANDSHAKE_FAILURE       40 /* fatal */
#define SSL3_AD_NO_CERTIFICATE          41
#define SSL3_AD_BAD_CERTIFICATE         42
#define SSL3_AD_UNSUPPORTED_CERTIFICATE 43
#define SSL3_AD_CERTIFICATE_REVOKED     44
#define SSL3_AD_CERTIFICATE_EXPIRED     45
#define SSL3_AD_CERTIFICATE_UNKNOWN     46
#define SSL3_AD_ILLEGAL_PARAMETER       47 /* fatal */

#define TLS1_HB_REQUEST  1
#define TLS1_HB_RESPONSE 2

#ifndef OPENSSL_NO_SSL_INTERN

typedef struct ssl3_record_st {
    /*r */ int type;            /* type of record */
    /*rw*/ unsigned int length; /* How many bytes available */
    /*r */ unsigned int off;    /* read/write offset into 'buf' */
    /*rw*/ uint8_t *data;       /* pointer to the record data */
    /*rw*/ uint8_t *input;      /* where the decode bytes are */
    /*r */ unsigned long epoch; /* epoch number, needed by DTLS1 */
    /*r */ uint8_t seq_num[8];  /* sequence number, needed by DTLS1 */
} SSL3_RECORD;

typedef struct ssl3_buffer_st {
    uint8_t *buf; /* at least SSL3_RT_MAX_PACKET_SIZE bytes,
                   * see ssl3_setup_buffers() */
    size_t len;   /* buffer size */
    int offset;   /* where to 'copy from' */
    int left;     /* how many bytes left */
} SSL3_BUFFER;

#endif

#define SSL3_CT_RSA_SIGN            1
#define SSL3_CT_DSS_SIGN            2
#define SSL3_CT_RSA_FIXED_DH        3
#define SSL3_CT_DSS_FIXED_DH        4
#define SSL3_CT_RSA_EPHEMERAL_DH    5
#define SSL3_CT_DSS_EPHEMERAL_DH    6
#define SSL3_CT_FORTEZZA_DMS        20
/*
 * SSL3_CT_NUMBER is used to size arrays and it must be large
 * enough to contain all of the cert types defined either for
 * SSLv3 and TLSv1.
 */
#define SSL3_CT_NUMBER 9

#define SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS   0x0001
#define SSL3_FLAGS_DELAY_CLIENT_FINISHED    0x0002
#define SSL3_FLAGS_POP_BUFFER               0x0004
#define TLS1_FLAGS_TLS_PADDING_BUG          0x0008
#define TLS1_FLAGS_SKIP_CERT_VERIFY         0x0010
#define TLS1_FLAGS_KEEP_HANDSHAKE           0x0020
/*
 * Set when the handshake is ready to process peer's ChangeCipherSpec message.
 * Cleared after the message has been processed.
 */
#define SSL3_FLAGS_CCS_OK 0x0080

#ifndef OPENSSL_NO_SSL_INTERN

typedef struct ssl3_state_st {
    long flags;
    int delay_buf_pop_ret;

    uint8_t read_sequence[SSL3_SEQUENCE_SIZE];
    int read_mac_secret_size;
    uint8_t read_mac_secret[EVP_MAX_MD_SIZE];
    uint8_t write_sequence[SSL3_SEQUENCE_SIZE];
    int write_mac_secret_size;
    uint8_t write_mac_secret[EVP_MAX_MD_SIZE];

    uint8_t server_random[SSL3_RANDOM_SIZE];
    uint8_t client_random[SSL3_RANDOM_SIZE];

    /* flags for countermeasure against known-IV weakness */
    int need_empty_fragments;
    int empty_fragment_done;

    /* The value of 'extra' when the buffers were initialized */
    int init_extra;

    SSL3_BUFFER rbuf; /* read IO goes into here */
    SSL3_BUFFER wbuf; /* write IO goes into here */

    SSL3_RECORD rrec; /* each decoded record goes in here */
    SSL3_RECORD wrec; /* goes out from here */

    /*
     * storage for Alert/Handshake protocol data received but not
     * yet processed by ssl3_read_bytes:
     */
    uint8_t alert_fragment[2];
    unsigned int alert_fragment_len;
    uint8_t handshake_fragment[4];
    unsigned int handshake_fragment_len;

    /* partial write - check the numbers match */
    unsigned int wnum; /* number of bytes sent so far */
    int wpend_tot;     /* number bytes written */
    int wpend_type;
    int wpend_ret; /* number of bytes submitted */
    const uint8_t *wpend_buf;

    /* used during startup, digest all incoming/outgoing packets */
    BIO *handshake_buffer;
    /*
     * When set of handshake digests is determined, buffer is hashed
     * and freed and MD_CTX-es for all required digests are stored in
     * this array
     */
    EVP_MD_CTX **handshake_dgst;
    /*
     * Set whenever an expected ChangeCipherSpec message is processed.
     * Unset when the peer's Finished message is received.
     * Unexpected ChangeCipherSpec messages trigger a fatal alert.
     */
    int change_cipher_spec;

    int warn_alert;
    int fatal_alert;
    /*
     * we allow one fatal and one warning alert to be outstanding,
     * send close alert via the warning alert
     */
    int alert_dispatch;
    uint8_t send_alert[2];

    /*
     * This flag is set when we should renegotiate ASAP, basically when
     * there is no more data in the read or write buffers
     */
    int renegotiate;
    int total_renegotiations;
    int num_renegotiations;

    int in_read_app_data;

    struct {
        /* actually only needs to be 16+20 */
        uint8_t cert_verify_md[EVP_MAX_MD_SIZE * 2];

        /* actually only need to be 16+20 for SSLv3 and 12 for TLS */
        uint8_t finish_md[EVP_MAX_MD_SIZE * 2];
        int finish_md_len;
        uint8_t peer_finish_md[EVP_MAX_MD_SIZE * 2];
        int peer_finish_md_len;

        unsigned long message_size;
        int message_type;

        /* used to hold the new cipher we are going to use */
        const SSL_CIPHER *new_cipher;
        DH *dh;

        EC_KEY *ecdh; /* holds short lived ECDH key */

        /* used when SSL_ST_FLUSH_DATA is entered */
        int next_state;

        int reuse_message;

        /* used for certificate requests */
        int cert_req;
        int ctype_num;
        char ctype[SSL3_CT_NUMBER];
        STACK_OF(X509_NAME) *ca_names;

        int use_rsa_tmp;

        int key_block_length;
        uint8_t *key_block;

        const EVP_CIPHER *new_sym_enc;
        const EVP_AEAD *new_aead;
        const EVP_MD *new_hash;
        int new_mac_pkey_type;
        int new_mac_secret_size;
        int cert_request;
    } tmp;

    /* Connection binding to prevent renegotiation attacks */
    uint8_t previous_client_finished[EVP_MAX_MD_SIZE];
    uint8_t previous_client_finished_len;
    uint8_t previous_server_finished[EVP_MAX_MD_SIZE];
    uint8_t previous_server_finished_len;
    int send_connection_binding; /* TODOEKR */

    /*
     * Set if we saw the Next Protocol Negotiation extension from our peer.
     */
    int next_proto_neg_seen;

    /*
     * ALPN information
     * (we are in the process of transitioning from NPN to ALPN).
     */

    /*
     * In a server these point to the selected ALPN protocol after the
     * ClientHello has been processed. In a client these contain the
     * protocol that the server selected once the ServerHello has been
     * processed.
     */
    uint8_t *alpn_selected;
    unsigned int alpn_selected_len;
} SSL3_STATE;

#endif

/* SSLv3 */
/*client */
/* extra state */
#define SSL3_ST_CW_FLUSH                    (0x100 | SSL_ST_CONNECT)
/* write to server */
#define SSL3_ST_CW_CLNT_HELLO_A             (0x110 | SSL_ST_CONNECT)
#define SSL3_ST_CW_CLNT_HELLO_B             (0x111 | SSL_ST_CONNECT)
/* read from server */
#define SSL3_ST_CR_SRVR_HELLO_A             (0x120 | SSL_ST_CONNECT)
#define SSL3_ST_CR_SRVR_HELLO_B             (0x121 | SSL_ST_CONNECT)
#define DTLS1_ST_CR_HELLO_VERIFY_REQUEST_A  (0x126 | SSL_ST_CONNECT)
#define DTLS1_ST_CR_HELLO_VERIFY_REQUEST_B  (0x127 | SSL_ST_CONNECT)
#define SSL3_ST_CR_CERT_A                   (0x130 | SSL_ST_CONNECT)
#define SSL3_ST_CR_CERT_B                   (0x131 | SSL_ST_CONNECT)
#define SSL3_ST_CR_KEY_EXCH_A               (0x140 | SSL_ST_CONNECT)
#define SSL3_ST_CR_KEY_EXCH_B               (0x141 | SSL_ST_CONNECT)
#define SSL3_ST_CR_CERT_REQ_A               (0x150 | SSL_ST_CONNECT)
#define SSL3_ST_CR_CERT_REQ_B               (0x151 | SSL_ST_CONNECT)
#define SSL3_ST_CR_SRVR_DONE_A              (0x160 | SSL_ST_CONNECT)
#define SSL3_ST_CR_SRVR_DONE_B              (0x161 | SSL_ST_CONNECT)

/* write to server */
#define SSL3_ST_CW_CERT_A                   (0x170 | SSL_ST_CONNECT)
#define SSL3_ST_CW_CERT_B                   (0x171 | SSL_ST_CONNECT)
#define SSL3_ST_CW_CERT_C                   (0x172 | SSL_ST_CONNECT)
#define SSL3_ST_CW_CERT_D                   (0x173 | SSL_ST_CONNECT)
#define SSL3_ST_CW_KEY_EXCH_A               (0x180 | SSL_ST_CONNECT)
#define SSL3_ST_CW_KEY_EXCH_B               (0x181 | SSL_ST_CONNECT)
#define SSL3_ST_CW_CERT_VRFY_A              (0x190 | SSL_ST_CONNECT)
#define SSL3_ST_CW_CERT_VRFY_B              (0x191 | SSL_ST_CONNECT)
#define SSL3_ST_CW_CHANGE_A                 (0x1A0 | SSL_ST_CONNECT)
#define SSL3_ST_CW_CHANGE_B                 (0x1A1 | SSL_ST_CONNECT)
#define SSL3_ST_CW_NEXT_PROTO_A             (0x200 | SSL_ST_CONNECT)
#define SSL3_ST_CW_NEXT_PROTO_B             (0x201 | SSL_ST_CONNECT)
#define SSL3_ST_CW_FINISHED_A               (0x1B0 | SSL_ST_CONNECT)
#define SSL3_ST_CW_FINISHED_B               (0x1B1 | SSL_ST_CONNECT)
/* read from server */
#define SSL3_ST_CR_CHANGE_A                 (0x1C0 | SSL_ST_CONNECT)
#define SSL3_ST_CR_CHANGE_B                 (0x1C1 | SSL_ST_CONNECT)
#define SSL3_ST_CR_FINISHED_A               (0x1D0 | SSL_ST_CONNECT)
#define SSL3_ST_CR_FINISHED_B               (0x1D1 | SSL_ST_CONNECT)
#define SSL3_ST_CR_SESSION_TICKET_A         (0x1E0 | SSL_ST_CONNECT)
#define SSL3_ST_CR_SESSION_TICKET_B         (0x1E1 | SSL_ST_CONNECT)
#define SSL3_ST_CR_CERT_STATUS_A            (0x1F0 | SSL_ST_CONNECT)
#define SSL3_ST_CR_CERT_STATUS_B            (0x1F1 | SSL_ST_CONNECT)

/* server */
/* extra state */
#define SSL3_ST_SW_FLUSH                    (0x100 | SSL_ST_ACCEPT)
/* read from client */
/* Do not change the number values, they do matter */
#define SSL3_ST_SR_CLNT_HELLO_A             (0x110 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_CLNT_HELLO_B             (0x111 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_CLNT_HELLO_C             (0x112 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_CLNT_HELLO_D             (0x115 | SSL_ST_ACCEPT)
/* write to client */
#define DTLS1_ST_SW_HELLO_VERIFY_REQUEST_A  (0x113 | SSL_ST_ACCEPT)
#define DTLS1_ST_SW_HELLO_VERIFY_REQUEST_B  (0x114 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_HELLO_REQ_A              (0x120 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_HELLO_REQ_B              (0x121 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_HELLO_REQ_C              (0x122 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_SRVR_HELLO_A             (0x130 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_SRVR_HELLO_B             (0x131 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_CERT_A                   (0x140 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_CERT_B                   (0x141 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_KEY_EXCH_A               (0x150 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_KEY_EXCH_B               (0x151 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_CERT_REQ_A               (0x160 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_CERT_REQ_B               (0x161 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_SRVR_DONE_A              (0x170 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_SRVR_DONE_B              (0x171 | SSL_ST_ACCEPT)
/* read from client */
#define SSL3_ST_SR_CERT_A                   (0x180 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_CERT_B                   (0x181 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_KEY_EXCH_A               (0x190 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_KEY_EXCH_B               (0x191 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_CERT_VRFY_A              (0x1A0 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_CERT_VRFY_B              (0x1A1 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_CHANGE_A                 (0x1B0 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_CHANGE_B                 (0x1B1 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_NEXT_PROTO_A             (0x210 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_NEXT_PROTO_B             (0x211 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_FINISHED_A               (0x1C0 | SSL_ST_ACCEPT)
#define SSL3_ST_SR_FINISHED_B               (0x1C1 | SSL_ST_ACCEPT)
/* write to client */
#define SSL3_ST_SW_CHANGE_A                 (0x1D0 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_CHANGE_B                 (0x1D1 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_FINISHED_A               (0x1E0 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_FINISHED_B               (0x1E1 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_SESSION_TICKET_A         (0x1F0 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_SESSION_TICKET_B         (0x1F1 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_CERT_STATUS_A            (0x200 | SSL_ST_ACCEPT)
#define SSL3_ST_SW_CERT_STATUS_B            (0x201 | SSL_ST_ACCEPT)

#define SSL3_MT_HELLO_REQUEST       0
#define SSL3_MT_CLIENT_HELLO        1
#define SSL3_MT_SERVER_HELLO        2
#define SSL3_MT_NEWSESSION_TICKET   4
#define SSL3_MT_CERTIFICATE         11
#define SSL3_MT_SERVER_KEY_EXCHANGE 12
#define SSL3_MT_CERTIFICATE_REQUEST 13
#define SSL3_MT_SERVER_DONE         14
#define SSL3_MT_CERTIFICATE_VERIFY  15
#define SSL3_MT_CLIENT_KEY_EXCHANGE 16
#define SSL3_MT_FINISHED            20
#define SSL3_MT_CERTIFICATE_STATUS  22
#define SSL3_MT_NEXT_PROTO          67

#define DTLS1_MT_HELLO_VERIFY_REQUEST 3

#define SSL3_MT_CCS 1

/* These are used when changing over to a new cipher */
#define SSL3_CC_READ                    0x01
#define SSL3_CC_WRITE                   0x02
#define SSL3_CC_CLIENT                  0x10
#define SSL3_CC_SERVER                  0x20
#define SSL3_CHANGE_CIPHER_CLIENT_WRITE (SSL3_CC_CLIENT | SSL3_CC_WRITE)
#define SSL3_CHANGE_CIPHER_SERVER_READ  (SSL3_CC_SERVER | SSL3_CC_READ)
#define SSL3_CHANGE_CIPHER_CLIENT_READ  (SSL3_CC_CLIENT | SSL3_CC_READ)
#define SSL3_CHANGE_CIPHER_SERVER_WRITE (SSL3_CC_SERVER | SSL3_CC_WRITE)

#ifdef __cplusplus
}
#endif
#endif
