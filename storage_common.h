/** \file storage_common.h
  *
  * \brief Defines the overall layout of non-volatile storage.
  *
  * The overall layout of non-volatile storage consists of the global (stuff
  * that applies to all wallets) data followed by each wallet record.
  * This file does not describe the format of an individual
  * wallet record; rather it describes where those records go in non-volatile
  * storage.
  *
  * This file is licensed as described by the file LICENCE.
  */

#ifndef STORAGE_COMMON_H_INCLUDED
#define STORAGE_COMMON_H_INCLUDED

/** Length of a wallet record.
  * \warning This must also be a multiple of 16, since the block size of
  *          AES is 128 bits.
  */
#define WALLET_RECORD_LENGTH	160

/** Address where the persistent entropy pool is located. */
#define ADDRESS_ENTROPY_POOL	64
/** Address where the checksum of the persistent entropy pool is located. */
#define ADDRESS_POOL_CHECKSUM	96
/** Address where the wallet staging area is. This staging area is used to
  * ensure that operations which write to a wallet are atomic.
  * \todo Actually use this.
  * \warning This must also be a multiple of 16, since the block size of
  *          AES is 128 bits.
  */
#define ADDRESS_WALLET_STAGING	128
/** Address where wallet records start at. From here on, non-volatile storage
  * will consist of sequential wallet records. */
#define ADDRESS_WALLET_START	(ADDRESS_WALLET_STAGING + WALLET_RECORD_LENGTH)

#endif // #ifndef STORAGE_COMMON_H_INCLUDED
