#include <stdint.h>
#include <stdio.h>

#include "utils.h"
#include "inst.h"



static uint8_t get_funct7(uint32_t inst){ return (uint8_t)get_bits(inst,25, 31); }
static uint8_t get_rs2(uint32_t inst){ return (uint8_t)get_bits(inst, 20, 24); }
static uint8_t get_rs1(uint32_t inst){ return (uint8_t)get_bits(inst, 15, 19); }
static uint8_t get_funct3(uint32_t inst){ return (uint8_t)get_bits(inst, 12, 14); }
static uint8_t get_rd(uint32_t inst){ return (uint8_t)get_bits(inst, 7, 11); }
static uint8_t get_opcode(uint32_t inst){ return (uint8_t)get_bits(inst, 0, 6); }
static uint16_t get_imm_11_0(uint32_t inst){ return (uint16_t)get_bits(inst, 20, 31); }
static uint8_t get_imm_11_5(uint32_t inst){ return (uint8_t)get_bits(inst, 25, 31); }
static uint8_t get_imm_4_0(uint32_t inst){ return (uint8_t)get_bits(inst, 7, 11); }
static uint32_t get_imm_31_12(uint32_t inst){ return (uint32_t)get_bits(inst, 12, 31); }

int decode_get_type(uint32_t inst){

}
uint8_t decode_get_opcode(uint32_t inst){
    return get_opcode(inst);
}

void decode_get_r_type(uint32_t inst, struct r_type *r){
}

void decode_get_i_type(uint32_t inst, struct i_type *i){
    i->rs1 = get_rs1(inst);
    i->funct3 = get_funct3(inst);
    i->rd = get_rd(inst);
    i->opcode = get_opcode(inst);
}

void decode_get_s_type(uint32_t inst, struct s_type *s){
}

void decode_get_u_type(uint32_t inst, struct u_type *u){
    u->rd = get_rd(inst);
    u->opcode = get_opcode(inst);
}

void decode_get_b_type(uint32_t inst, struct b_type *i){
}

void decode_get_j_type(uint32_t inst, struct j_type *i){
}

uint32_t decode_get_i_imm(uint32_t inst){
    uint32_t v = get_bits(inst, 20, 30);
    uint8_t sign_bit = get_bits(inst, 31, 31);
    for(int i=0;i<21;i++){
        v += (sign_bit)<<(i+11);
    }

    return v;
}

uint32_t decode_get_s_imm(uint32_t inst){
}

uint32_t decode_get_b_imm(uint32_t inst){
}

uint32_t decode_get_u_imm(uint32_t inst){
    uint32_t v = get_bits(inst, 12, 31);
    return v<<12;
}

uint32_t decode_get_j_imm(uint32_t inst){
}
