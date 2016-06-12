#ifndef BNT_SEQ_H
#define BNT_SEQ_H

#include <stdint.h>
#include <stdio.h>
#include <zlib.h>

#ifndef UBYTE
#define UBYTE
typedef uint8_t ubyte_t;
#endif

typedef struct
{
    int64_t offset;
    int32_t len;
    int32_t n_ambs;
    int32_t gi;
    char *name,*anno;
} bntann1_t;

typedef struct
{
    int64_t offset;
    int32_t len;
    char amb;
} bntamb1_t;

typedef struct
{
    int64_t l_pac;
    uint32_t seed;
    int32_t n_seqs;
    bntann1_t *anns;
    int32_t n_holes;
    bntamb1_t *ambs;
    FILE* fp_pac;
} bntseq_t;

extern unsigned char nst_nt4_table[256];

#ifdef __cplusplus
extern "C"{
#endif

	void bns_dump(const bntseq_t *bns, const char *prefix);
	bntseq_t *bns_restore(const char *prefix);
	bntseq_t *bns_restore_core(const char *ann_filename, const char* amb_filename, const char* pac_filename);
	void bns_destroy(bntseq_t *bns);
	int64_t bns_fasta2bntseq(gzFile fp_fa, const char *prefix, int for_only);
	int bns_pos2rid(const bntseq_t *bns, int64_t pos_f);
	int bns_cnt_ambi(const bntseq_t *bns, int64_t pos_f, int len, int *ref_id);
	uint8_t *bns_get_seq(int64_t l_pac, const uint8_t *pac, int64_t beg, int64_t end, int64_t *len);

#ifdef __cplusplus
}
#endif

static inline int64_t bns_depos(const bntseq_t *bns, int64_t pos, int *is_rev)
{
	return (*is_rev = (pos >= bns->l_pac))? (bns->l_pac<<1) - 1 - pos : pos;
}


#endif
