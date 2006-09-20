#include <Rdefines.h>
#include <R_ext/Rdynload.h>
#include <string.h>

#define DEBUG_BIOSTRINGS 1


/* utils.c */

SEXP utils_debug();

int Biostrings_memcmp(char *a, int ia, char *b, int ib, int n, size_t size);

void Biostrings_memcpy_from_i1i2(int i1, int i2,
		char *dest, size_t dest_nmemb,
		char *src, size_t src_nmemb, size_t size);
void Biostrings_memcpy_from_subset(int *subset, int n,
		char *dest, size_t dest_nmemb,
		char *src, size_t src_nmemb, size_t size);

void Biostrings_memcpy_to_i1i2(int i1, int i2,
		char *dest, size_t dest_nmemb,
		char *src, size_t src_nmemb, size_t size);
void Biostrings_memcpy_to_subset(int *subset, int n,
		char *dest, size_t dest_nmemb,
		char *src, size_t src_nmemb, size_t size);

void Biostrings_translate_charcpy_from_i1i2(int i1, int i2,
		char *dest, int dest_length,
		char *src, int src_length,
		char *hash, int hash_length, char hash_hole, int strict);
void Biostrings_translate_charcpy_from_subset(int *subset, int n,
		char *dest, int dest_length,
		char *src, int src_length,
		char *hash, int hash_length, char hash_hole, int strict);

void Biostrings_translate_charcpy_to_i1i2(int i1, int i2,
		char *dest, int dest_length,
		char *src, int src_length,
		char *hash, int hash_length, char hash_hole, int strict);
void Biostrings_translate_charcpy_to_subset(int *subset, int n,
		char *dest, int dest_length,
		char *src, int src_length,
		char *hash, int hash_length, char hash_hole, int strict);

void Biostrings_reverse_memcpy_from_i1i2(int i1, int i2,
		char *dest, size_t dest_nmemb,
		char *src, size_t src_nmemb, size_t size);
void Biostrings_reverse_translate_charcpy_from_i1i2(int i1, int i2,
		char *dest, int dest_length,
		char *src, int src_length,
		char *hash, int hash_length, char hash_hole, int strict);


/* CharBuffer.c */

SEXP CharBuffer_debug();

SEXP sexp_address(SEXP s);
SEXP xp_show(SEXP xp);
SEXP xp_new();
SEXP safe_explode(SEXP s);

SEXP CharBuffer_alloc(SEXP bb_xp, SEXP length);
SEXP CharBuffer_show(SEXP bb_xp);
SEXP CharBuffer_length(SEXP bb_xp);
SEXP CharBuffer_memcmp(SEXP bb1_xp, SEXP first1,
		SEXP bb2_xp, SEXP first2, SEXP width);

SEXP CharBuffer_copy_from_i1i2(SEXP dest_xp, SEXP src_xp, SEXP imin, SEXP imax);
SEXP CharBuffer_copy_from_subset(SEXP dest_xp, SEXP src_xp, SEXP subset);

SEXP CharBuffer_read_chars_from_i1i2(SEXP src_xp, SEXP imin, SEXP imax);
SEXP CharBuffer_read_chars_from_subset(SEXP src_xp, SEXP subset);
SEXP CharBuffer_write_chars_to_i1i2(SEXP dest_xp, SEXP imin, SEXP imax, SEXP string);
SEXP CharBuffer_write_chars_to_subset(SEXP dest_xp, SEXP subset, SEXP string);

SEXP CharBuffer_read_ints_from_i1i2(SEXP src_xp, SEXP imin, SEXP imax);
SEXP CharBuffer_read_ints_from_subset(SEXP src_xp, SEXP subset);
SEXP CharBuffer_write_ints_to_i1i2(SEXP dest_xp, SEXP imin, SEXP imax, SEXP val);
SEXP CharBuffer_write_ints_to_subset(SEXP dest_xp, SEXP subset, SEXP val);

SEXP CharBuffer_read_enc_chars_from_i1i2(SEXP src_xp, SEXP imin, SEXP imax, SEXP hash_xp);
SEXP CharBuffer_read_enc_chars_from_subset(SEXP src_xp, SEXP subset, SEXP hash_xp);
SEXP CharBuffer_write_enc_chars_to_i1i2(SEXP dest_xp, SEXP imin, SEXP imax,
		SEXP string, SEXP hash_xp);
SEXP CharBuffer_write_enc_chars_to_subset(SEXP dest_xp, SEXP subset,
		SEXP string, SEXP hash_xp);


/* IntBuffer.c */

SEXP IntBuffer_alloc(SEXP ib_xp, SEXP length);
SEXP IntBuffer_show(SEXP ib_xp);
SEXP IntBuffer_length(SEXP ib_xp);
SEXP IntBuffer_memcmp(SEXP ib1_xp, SEXP first1,
		SEXP ib2_xp, SEXP first2, SEXP width);

SEXP IntBuffer_read_ints_from_i1i2(SEXP src_xp, SEXP imin, SEXP imax);
SEXP IntBuffer_read_ints_from_subset(SEXP src_xp, SEXP subset);
SEXP IntBuffer_write_ints_to_i1i2(SEXP dest_xp, SEXP imin, SEXP imax, SEXP val);
SEXP IntBuffer_write_ints_to_subset(SEXP dest_xp, SEXP subset, SEXP val);


/* reverseComplement.c */

SEXP CharBuffer_translate_copy_from_i1i2(SEXP dest_xp, SEXP src_xp, SEXP imin, SEXP imax, SEXP hash_xp);
SEXP CharBuffer_translate_copy_from_subset(SEXP dest_xp, SEXP src_xp, SEXP subset, SEXP hash_xp);
SEXP CharBuffer_reverse_copy_from_i1i2(SEXP dest_xp, SEXP src_xp, SEXP imin, SEXP imax);
SEXP CharBuffer_reverse_translate_copy_from_i1i2(SEXP dest_xp, SEXP src_xp, SEXP imin, SEXP imax, SEXP hash_xp);


/* alphabetFrequency.c */

SEXP alphabetFrequency(SEXP x_xp, SEXP x_offset, SEXP x_length);


/* shiftor.c */

SEXP shiftor_debug();

SEXP shiftor(SEXP p_xp, SEXP p_offset, SEXP p_length,
		SEXP s_xp, SEXP s_offset, SEXP s_length,
		SEXP mismatch, SEXP fixed, SEXP count_only);

