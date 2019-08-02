#ifndef DECODE_H
#define DECODE_H
uint8_t decode_get_opcode(uint32_t inst);
void decode_get_i_type(uint32_t inst, struct i_type *i);
uint32_t decode_get_i_imm(uint32_t inst);
#endif
