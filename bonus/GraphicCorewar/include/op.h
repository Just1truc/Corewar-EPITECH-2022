/*
** EPITECH PROJECT, 2022
** B-CPE-201-LYN-2-1-corewar-leo.dubosclard
** File description:
** op
*/

#ifndef _OP_H_
    #define _OP_H_

    #define TRUE    1
    #define FALSE   0

    #define MEM_SIZE            (8 * 1024)
    #define IDX_MOD             512 /* modulo of the index < */
    #define MAX_ARGS_NUMBER     4 /* this may not be changed 2^*IND_SIZE */

    #define COMMENT_CHAR        '#'
    #define LABEL_CHAR          ':'
    #define DIRECT_CHAR         '%'
    #define SEPARATOR_CHAR      ','

    #define LABEL_CHARS         "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING     ".name"
    #define COMMENT_CMD_STRING  ".comment"

/*
** regs
*/
    #define REG_NUMBER 16 /* r1 <--> rx */

/*
**
*/
typedef char args_type_t;

    #define T_REG   1 /* register */
    #define T_DIR   2 /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_IND   4 // indirect always relative
                    // ( ld 1,r1 put whats in the address (1+pc)
                    // into r1 (4 bytes ))
    #define T_LAB   8 /* LABEL */

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
    int weight;
} op_t;

typedef struct champ_s {
    char *name;
    int selected;
    int check;
} champ_t;

/*
** size (in bytes)
*/
    #define IND_SIZE    2
    #define DIR_SIZE    4
    #define REG_SIZE    DIR_SIZE

/*
** op_tab
*/
static const op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, "alive", FALSE},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", TRUE},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", TRUE},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", TRUE},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", TRUE},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
    "et (and  r1, r2, r3   r1&r2 -> r3", TRUE},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
    "ou  (or   r1, r2, r3   r1 | r2 -> r3", TRUE},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
    "ou (xor  r1, r2, r3   r1^r2 -> r3", TRUE},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", FALSE},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
    "load index", TRUE},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
    "store index", TRUE},
    {"fork", 1, {T_DIR}, 12, 800, "fork", FALSE},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", TRUE},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
    "long load index", TRUE},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", FALSE},
    {"aff", 1, {T_REG}, 16, 2, "aff", TRUE},
    {0, 0, {0}, 0, 0, 0, 0}
};

/*
** header
*/
    #define PROG_NAME_LENGTH        128
    #define COMMENT_LENGTH          2048

typedef struct header_s {
    int magic;
    #define COREWAR_EXEC_MAGIC  0xea83f3 /* why not */
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

/*
** live
*/
    #define CYCLE_TO_DIE    1536 /* number of cycle before beig declared dead*/
    #define CYCLE_DELTA     5
    #define NBR_LIVE        40

static const int proto_to_type[] = {
    [1] = T_REG,
    [2] = T_DIR,
    [3] = T_IND
};

static const int sizes[] = {
    [T_DIR] = DIR_SIZE,
    [T_IND] = IND_SIZE,
    [T_REG] = 1
};

static const int index_sizes[] = {
    [T_DIR] = IND_SIZE,
    [T_IND] = IND_SIZE,
    [T_REG] = 1
};

#endif
