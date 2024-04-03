#include "../include/riscv_instructions.h"

void execute_add(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) + simulator.get_register(rs2));
}

void execute_addi(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = instruction >> 20;
    simulator.set_register(rd, simulator.get_register(rs1) + imm);
}

void execute_sub(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) - simulator.get_register(rs2));
}

void execute_load(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = instruction >> 20;
    simulator.set_register(rd, simulator.get_register(rs1) + imm);
}

void execute_jal(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int imm = instruction >> 20;
    simulator.set_register(rd, simulator.get_pc() + 4);
    simulator.set_pc(simulator.get_pc() + imm - 4);
}

void execute_jalr(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = instruction >> 20;
    simulator.set_register(rd, simulator.get_register(rs1) + imm);
    simulator.set_pc(simulator.get_pc() + 4);
}

void execute_slt(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) < simulator.get_register(rs2));
}

void execute_sw(int instruction, RISC_V_Simulator &simulator) {
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    int imm = instruction >> 25;
    int rd = (instruction >> 7) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) + imm);
}


std::unordered_map<int, std::function<void(int, RISC_V_Simulator&)>> opcode_functions = {
        {0b0000000, execute_add},
        {0b0010011, execute_addi},
        {0b001001, execute_sub},
        {0b0000011, execute_load},
        {0b1100011, execute_jal},
        {0b1100111, execute_jalr},
        {0b0000111, execute_slt},
        {0b0100011, execute_sw}
};
