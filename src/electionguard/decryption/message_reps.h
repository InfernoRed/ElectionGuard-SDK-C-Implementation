#ifndef __DECRYPTION_MESSAGE_REPS_H__
#define __DECRYPTION_MESSAGE_REPS_H__

#include <stdbool.h>
#include <stdint.h>

#include <electionguard/max_values.h>
#include "crypto_reps.h"

struct decryption_share_rep
{
    uint32_t trustee_index;
    uint64_t num_tallies;
    struct encryption_rep tally_share[MAX_SELECTIONS];
    struct cp_proof_rep cp_proofs[MAX_SELECTIONS];
};

struct decryption_fragments_request_rep
{
    uint32_t num_trustees;
    bool requested[MAX_TRUSTEES];
};

struct decryption_fragments_rep
{
    uint32_t trustee_index;
    uint32_t num_trustees;
    uint32_t num_selections;
    bool requested[MAX_TRUSTEES];
    mpz_t partial_decryption_M[MAX_TRUSTEES][MAX_SELECTIONS];
    mpz_t lagrange_coefficient;
    struct cp_proof_rep cp_proofs[MAX_TRUSTEES][MAX_SELECTIONS];
};



#endif /* __DECRYPTION_MESSAGE_REPS_H__ */
