/*
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2016 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <openssl/err.h>
#include <openssl/pkcs7.h>

/* BEGIN ERROR CODES */
#ifndef OPENSSL_NO_ERR

# define ERR_FUNC(func) ERR_PACK(ERR_LIB_PKCS7, func, 0)
# define ERR_REASON(reason) ERR_PACK(ERR_LIB_PKCS7, 0, reason)

static ERR_STRING_DATA PKCS7_str_functs[] = {
    { ERR_FUNC(PKCS7_F_B64_READ_PKCS7), "B64_READ_PKCS7" },
    { ERR_FUNC(PKCS7_F_B64_WRITE_PKCS7), "B64_WRITE_PKCS7" },
    { ERR_FUNC(PKCS7_F_DO_PKCS7_SIGNED_ATTRIB), "DO_PKCS7_SIGNED_ATTRIB" },
    { ERR_FUNC(PKCS7_F_I2D_PKCS7_BIO_STREAM), "I2D_PKCS7_BIO_STREAM" },
    { ERR_FUNC(PKCS7_F_PKCS7_ADD0_ATTRIB_SIGNING_TIME),
     "PKCS7_ADD0_ATTRIB_SIGNING_TIME" },
    { ERR_FUNC(PKCS7_F_PKCS7_ADD_ATTRIB_SMIMECAP), "PKCS7_ADD_ATTRIB_SMIMECAP" },
    { ERR_FUNC(PKCS7_F_PKCS7_ADD_CERTIFICATE), "PKCS7_ADD_CERTIFICATE" },
    { ERR_FUNC(PKCS7_F_PKCS7_ADD_CRL), "PKCS7_ADD_CRL" },
    { ERR_FUNC(PKCS7_F_PKCS7_ADD_RECIPIENT_INFO), "PKCS7_ADD_RECIPIENT_INFO" },
    { ERR_FUNC(PKCS7_F_PKCS7_ADD_SIGNATURE), "PKCS7_ADD_SIGNATURE" },
    { ERR_FUNC(PKCS7_F_PKCS7_ADD_SIGNER), "PKCS7_ADD_SIGNER" },
    { ERR_FUNC(PKCS7_F_PKCS7_BIO_ADD_DIGEST), "PKCS7_BIO_ADD_DIGEST" },
    { ERR_FUNC(PKCS7_F_PKCS7_COPY_EXISTING_DIGEST),
     "PKCS7_COPY_EXISTING_DIGEST" },
    { ERR_FUNC(PKCS7_F_PKCS7_CTRL), "PKCS7_CTRL" },
    { ERR_FUNC(PKCS7_F_PKCS7_DATADECODE), "PKCS7_DATADECODE" },
    { ERR_FUNC(PKCS7_F_PKCS7_DATAFINAL), "PKCS7_DATAFINAL" },
    { ERR_FUNC(PKCS7_F_PKCS7_DATAINIT), "PKCS7_DATAINIT" },
    { ERR_FUNC(PKCS7_F_PKCS7_DATASIGN), "PKCS7_DATASIGN" },
    { ERR_FUNC(PKCS7_F_PKCS7_DATAVERIFY), "PKCS7_DATAVERIFY" },
    { ERR_FUNC(PKCS7_F_PKCS7_DECRYPT), "PKCS7_DECRYPT" },
    { ERR_FUNC(PKCS7_F_PKCS7_DECRYPT_RINFO), "PKCS7_DECRYPT_RINFO" },
    { ERR_FUNC(PKCS7_F_PKCS7_ENCODE_RINFO), "PKCS7_ENCODE_RINFO" },
    { ERR_FUNC(PKCS7_F_PKCS7_ENCRYPT), "PKCS7_ENCRYPT" },
    { ERR_FUNC(PKCS7_F_PKCS7_FINAL), "PKCS7_FINAL" },
    { ERR_FUNC(PKCS7_F_PKCS7_FIND_DIGEST), "PKCS7_FIND_DIGEST" },
    { ERR_FUNC(PKCS7_F_PKCS7_GET0_SIGNERS), "PKCS7_GET0_SIGNERS" },
    { ERR_FUNC(PKCS7_F_PKCS7_RECIP_INFO_SET), "PKCS7_RECIP_INFO_SET" },
    { ERR_FUNC(PKCS7_F_PKCS7_SET_CIPHER), "PKCS7_SET_CIPHER" },
    { ERR_FUNC(PKCS7_F_PKCS7_SET_CONTENT), "PKCS7_SET_CONTENT" },
    { ERR_FUNC(PKCS7_F_PKCS7_SET_DIGEST), "PKCS7_SET_DIGEST" },
    { ERR_FUNC(PKCS7_F_PKCS7_SET_TYPE), "PKCS7_SET_TYPE" },
    { ERR_FUNC(PKCS7_F_PKCS7_SIGN), "PKCS7_SIGN" },
    { ERR_FUNC(PKCS7_F_PKCS7_SIGNATUREVERIFY), "PKCS7_SIGNATUREVERIFY" },
    { ERR_FUNC(PKCS7_F_PKCS7_SIGNER_INFO_SET), "PKCS7_SIGNER_INFO_SET" },
    { ERR_FUNC(PKCS7_F_PKCS7_SIGNER_INFO_SIGN), "PKCS7_SIGNER_INFO_SIGN" },
    { ERR_FUNC(PKCS7_F_PKCS7_SIGN_ADD_SIGNER), "PKCS7_SIGN_ADD_SIGNER" },
    { ERR_FUNC(PKCS7_F_PKCS7_SIMPLE_SMIMECAP), "PKCS7_SIMPLE_SMIMECAP" },
    { ERR_FUNC(PKCS7_F_PKCS7_VERIFY), "PKCS7_VERIFY" },
    { ERR_FUNC(PKCS7_F_SMIME_READ_PKCS7), "SMIME_READ_PKCS7" },
    { ERR_FUNC(PKCS7_F_SMIME_TEXT), "SMIME_TEXT" },
    { 0, NULL }
};

static ERR_STRING_DATA PKCS7_str_reasons[] = {
    { ERR_REASON(PKCS7_R_CERTIFICATE_VERIFY_ERROR), "certificate verify error" },
    { ERR_REASON(PKCS7_R_CIPHER_HAS_NO_OBJECT_IDENTIFIER),
     "cipher has no object identifier" },
    { ERR_REASON(PKCS7_R_CIPHER_NOT_INITIALIZED), "cipher not initialized" },
    { ERR_REASON(PKCS7_R_CONTENT_AND_DATA_PRESENT), "content and data present" },
    { ERR_REASON(PKCS7_R_CTRL_ERROR), "ctrl error" },
    { ERR_REASON(PKCS7_R_DECODE_ERROR), "decode error" },
    { ERR_REASON(PKCS7_R_DECRYPTED_KEY_IS_WRONG_LENGTH),
     "decrypted key is wrong length" },
    { ERR_REASON(PKCS7_R_DECRYPT_ERROR), "decrypt error" },
    { ERR_REASON(PKCS7_R_DIGEST_FAILURE), "digest failure" },
    { ERR_REASON(PKCS7_R_ENCRYPTION_CTRL_FAILURE), "encryption ctrl failure" },
    { ERR_REASON(PKCS7_R_ENCRYPTION_NOT_SUPPORTED_FOR_THIS_KEY_TYPE),
     "encryption not supported for this key type" },
    { ERR_REASON(PKCS7_R_ERROR_ADDING_RECIPIENT), "error adding recipient" },
    { ERR_REASON(PKCS7_R_ERROR_SETTING_CIPHER), "error setting cipher" },
    { ERR_REASON(PKCS7_R_INVALID_MIME_TYPE), "invalid mime type" },
    { ERR_REASON(PKCS7_R_INVALID_NULL_POINTER), "invalid null pointer" },
    { ERR_REASON(PKCS7_R_INVALID_SIGNED_DATA_TYPE), "invalid signed data type" },
    { ERR_REASON(PKCS7_R_MIME_NO_CONTENT_TYPE), "mime no content type" },
    { ERR_REASON(PKCS7_R_MIME_PARSE_ERROR), "mime parse error" },
    { ERR_REASON(PKCS7_R_MIME_SIG_PARSE_ERROR), "mime sig parse error" },
    { ERR_REASON(PKCS7_R_MISSING_CERIPEND_INFO), "missing ceripend info" },
    { ERR_REASON(PKCS7_R_NO_CONTENT), "no content" },
    { ERR_REASON(PKCS7_R_NO_CONTENT_TYPE), "no content type" },
    { ERR_REASON(PKCS7_R_NO_DEFAULT_DIGEST), "no default digest" },
    { ERR_REASON(PKCS7_R_NO_MATCHING_DIGEST_TYPE_FOUND),
     "no matching digest type found" },
    { ERR_REASON(PKCS7_R_NO_MULTIPART_BODY_FAILURE),
     "no multipart body failure" },
    { ERR_REASON(PKCS7_R_NO_MULTIPART_BOUNDARY), "no multipart boundary" },
    { ERR_REASON(PKCS7_R_NO_RECIPIENT_MATCHES_CERTIFICATE),
     "no recipient matches certificate" },
    { ERR_REASON(PKCS7_R_NO_RECIPIENT_MATCHES_KEY), "no recipient matches key" },
    { ERR_REASON(PKCS7_R_NO_SIGNATURES_ON_DATA), "no signatures on data" },
    { ERR_REASON(PKCS7_R_NO_SIGNERS), "no signers" },
    { ERR_REASON(PKCS7_R_NO_SIG_CONTENT_TYPE), "no sig content type" },
    { ERR_REASON(PKCS7_R_OPERATION_NOT_SUPPORTED_ON_THIS_TYPE),
     "operation not supported on this type" },
    { ERR_REASON(PKCS7_R_PKCS7_ADD_SIGNATURE_ERROR),
     "pkcs7 add signature error" },
    { ERR_REASON(PKCS7_R_PKCS7_ADD_SIGNER_ERROR), "pkcs7 add signer error" },
    { ERR_REASON(PKCS7_R_PKCS7_DATAFINAL), "pkcs7 datafinal" },
    { ERR_REASON(PKCS7_R_PKCS7_DATAFINAL_ERROR), "pkcs7 datafinal error" },
    { ERR_REASON(PKCS7_R_PKCS7_DATASIGN), "pkcs7 datasign" },
    { ERR_REASON(PKCS7_R_PKCS7_PARSE_ERROR), "pkcs7 parse error" },
    { ERR_REASON(PKCS7_R_PKCS7_SIG_PARSE_ERROR), "pkcs7 sig parse error" },
    { ERR_REASON(PKCS7_R_PRIVATE_KEY_DOES_NOT_MATCH_CERTIFICATE),
     "private key does not match certificate" },
    { ERR_REASON(PKCS7_R_SIGNATURE_FAILURE), "signature failure" },
    { ERR_REASON(PKCS7_R_SIGNER_CERTIFICATE_NOT_FOUND),
     "signer certificate not found" },
    { ERR_REASON(PKCS7_R_SIGNING_CTRL_FAILURE), "signing ctrl failure" },
    { ERR_REASON(PKCS7_R_SIGNING_NOT_SUPPORTED_FOR_THIS_KEY_TYPE),
     "signing not supported for this key type" },
    { ERR_REASON(PKCS7_R_SIG_INVALID_MIME_TYPE), "sig invalid mime type" },
    { ERR_REASON(PKCS7_R_SMIME_TEXT_ERROR), "smime text error" },
    { ERR_REASON(PKCS7_R_UNABLE_TO_FIND_CERTIFICATE),
     "unable to find certificate" },
    { ERR_REASON(PKCS7_R_UNABLE_TO_FIND_MEM_BIO), "unable to find mem bio" },
    { ERR_REASON(PKCS7_R_UNABLE_TO_FIND_MESSAGE_DIGEST),
     "unable to find message digest" },
    { ERR_REASON(PKCS7_R_UNKNOWN_DIGEST_TYPE), "unknown digest type" },
    { ERR_REASON(PKCS7_R_UNKNOWN_OPERATION), "unknown operation" },
    { ERR_REASON(PKCS7_R_UNSUPPORTED_CIPHER_TYPE), "unsupported cipher type" },
    { ERR_REASON(PKCS7_R_UNSUPPORTED_CONTENT_TYPE), "unsupported content type" },
    { ERR_REASON(PKCS7_R_WRONG_CONTENT_TYPE), "wrong content type" },
    { ERR_REASON(PKCS7_R_WRONG_PKCS7_TYPE), "wrong pkcs7 type" },
    { 0, NULL }
};

#endif

void ERR_load_PKCS7_strings(void)
{
#ifndef OPENSSL_NO_ERR
    if (ERR_func_error_string(PKCS7_str_functs[0].error) == NULL) {
        ERR_load_strings(0, PKCS7_str_functs);
        ERR_load_strings(0, PKCS7_str_reasons);
    }
#endif
}