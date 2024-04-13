#ifndef RISCV_INSTRUCTIONS_H
#define RISCV_INSTRUCTIONS_H

#include "riscv_simulator.h"

void execute_ADD(int instruction, RISC_V_Simulator &simulator);
void execute_ADDI(int instruction, RISC_V_Simulator &simulator);
void execute_AND(int instruction, RISC_V_Simulator &simulator);
void execute_ANDI(int instruction, RISC_V_Simulator &simulator);
void execute_BEQ(int instruction, RISC_V_Simulator &simulator);
void execute_BNE(int instruction, RISC_V_Simulator &simulator);
void execute_JAL(int instruction, RISC_V_Simulator &simulator);
void execute_JALR(int instruction, RISC_V_Simulator &simulator);
void execute_OR(int instruction, RISC_V_Simulator &simulator);
void execute_ORI(int instruction, RISC_V_Simulator &simulator);
void execute_SLLI(int instruction, RISC_V_Simulator &simulator);
void execute_SLT(int instruction, RISC_V_Simulator &simulator);
void execute_SLTI(int instruction, RISC_V_Simulator &simulator);
void execute_SLTIU(int instruction, RISC_V_Simulator &simulator);
void execute_SRAI(int instruction, RISC_V_Simulator &simulator);
void execute_SRL(int instruction, RISC_V_Simulator &simulator);
void execute_SRLI(int instruction, RISC_V_Simulator &simulator);
void execute_SUB(int instruction, RISC_V_Simulator &simulator);
void execute_SW(int instruction, RISC_V_Simulator &simulator);
void execute_XOR(int instruction, RISC_V_Simulator &simulator);
void execute_XORI(int instruction, RISC_V_Simulator &simulator);





extern std::unordered_map<int, std::function<void(int, RISC_V_Simulator&)>> opcode_functions;

#endif // RISCV_INSTRUCTIONS_H