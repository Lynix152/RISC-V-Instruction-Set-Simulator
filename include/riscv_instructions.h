#ifndef RISCV_INSTRUCTIONS_H
#define RISCV_INSTRUCTIONS_H

#include "riscv_simulator.h"

void execute_add(int instruction, RISC_V_Simulator &simulator);
void execute_addi(int instruction, RISC_V_Simulator &simulator);
void execute_sub(int instruction, RISC_V_Simulator &simulator);
void execute_load(int instruction, RISC_V_Simulator &simulator);
void execute_jal(int instruction, RISC_V_Simulator &simulator);
void execute_jalr(int instruction, RISC_V_Simulator &simulator);
void execute_slt(int instruction, RISC_V_Simulator &simulator);
void execute_sw(int instruction, RISC_V_Simulator &simulator);

extern std::unordered_map<int, std::function<void(int, RISC_V_Simulator&)>> opcode_functions;

#endif // RISCV_INSTRUCTIONS_H