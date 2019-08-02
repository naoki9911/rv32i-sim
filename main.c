#include <stdint.h>
#include <stdio.h>
#include "inst.h"
#include "decode.h"
#include "cpu.h"

void print_bin(uint32_t v, int bit_len) {
    for(int i=bit_len;i>0;i--){
       printf("%d", (v&(1<<(i-1)))>>(i-1));
    }
}

void init_cpu(struct cpu *cpu) {
    for(int i=0;i<32;i++){
        cpu->reg[i] = 0;
    }
    cpu->pc = 0;
    for(int i=0;i<CPU_MEM_SIZE;i++){
        cpu->mem[i] = 0;
    }
}

int main(){
    struct cpu cpu;
    init_cpu(&cpu);
    uint32_t inst = 0xfff08013;

    switch(decode_get_opcode(inst)){
        case OP_IMM:
            printf("OP_IMM\n");
            uint32_t imm = decode_get_i_imm(inst);
            struct i_type i_inst;
            decode_get_i_type(inst, &i_inst);
            switch(i_inst.funct3){
                case FUNCT3_ADDI:
                    printf("ADDI: imm:%d rs1:%d, rd:%d\n", imm, i_inst.rs1, i_inst.rd);
                    cpu.reg[i_inst.rd] = cpu.reg[i_inst.rs1] + imm;
                    break;
                case FUNCT3_SLTI:
                    break;
                case FUNCT3_SLTIU:
                    break;
                case FUNCT3_ANDI:
                    break;
                case FUNCT3_ORI:
                    break;
                case FUNCT3_XORI:
                    break;
                default:
                    printf("Not Implemented!\n");
            }
            break;
        default:
            printf("Not Implemented!\n");
    }
}
