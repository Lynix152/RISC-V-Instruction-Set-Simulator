#include "../include/riscv_instructions.h"

// various instructions
void execute_ADD(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) + simulator.get_register(rs2));
}

void execute_SUB(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) - simulator.get_register(rs2));
}

void execute_ADDI(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = instruction >> 20;
    simulator.set_register(rd, simulator.get_register(rs1) + imm);
}

void execute_LOAD(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = instruction >> 20;
    simulator.set_register(rd, simulator.get_register(rs1) + imm);
}

void execute_SLT(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) < simulator.get_register(rs2));
}

void execute_SW(int instruction, RISC_V_Simulator &simulator) {
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    int imm = instruction >> 25;
    int rd = (instruction >> 7) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) + imm);
}

// TODO: implement other instructions (literature page 116 and following)
// TODO: sort instructions


// ----------------------------------------------------------------
// RV21I Base Instruction Set


void execute_SLL(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int shamt = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) << shamt);
}

void execute_XOR(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) ^ simulator.get_register(rs2));
}

void execute_SRL(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int shamt = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, (unsigned int)simulator.get_register(rs1) >> shamt);
}

void execute_OR(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) | simulator.get_register(rs2));
}

void execute_AND(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    simulator.set_register(rd, simulator.get_register(rs1) & simulator.get_register(rs2));
}

void execute_BEQ(int instruction, RISC_V_Simulator &simulator) {
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    int imm = (instruction >> 7) & 0b111111111111;
    if (simulator.get_register(rs1) == simulator.get_register(rs2)) {
        simulator.set_pc(simulator.get_pc() + imm - 4);
    }
}

void execute_BNE(int instruction, RISC_V_Simulator &simulator) {
    int rs1 = (instruction >> 15) & 0b11111;
    int rs2 = (instruction >> 20) & 0b11111;
    int imm = (instruction >> 7) & 0b111111111111;
    if (simulator.get_register(rs1) != simulator.get_register(rs2)) {
        simulator.set_pc(simulator.get_pc() + imm - 4);
    }
}

void execute_JAL(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int imm = (instruction >> 20) & 0b11111111111111111111;
    int pc = simulator.get_pc();
    simulator.set_register(rd, pc + 4);
    simulator.set_pc(pc + imm - 4);
}

void execute_JALR(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = (instruction >> 20) & 0b11111111111111111111;
    int pc = simulator.get_pc();
    simulator.set_register(rd, pc + 4);
    simulator.set_pc((simulator.get_register(rs1) + imm) & ~1);
}

void execute_SLTI(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = (instruction >> 20) & 0b111111111111;
    simulator.set_register(rd, simulator.get_register(rs1) < imm ? 1 : 0);
}

void execute_SLTIU(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = (instruction >> 20) & 0b111111111111;
    simulator.set_register(rd, (unsigned)simulator.get_register(rs1) < (unsigned)imm ? 1 : 0);
}

void execute_ANDI(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = (instruction >> 20) & 0b111111111111;
    simulator.set_register(rd, simulator.get_register(rs1) & imm);
}

void execute_ORI(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = (instruction >> 20) & 0b111111111111;
    simulator.set_register(rd, simulator.get_register(rs1) | imm);
}

void execute_XORI(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int imm = (instruction >> 20) & 0b111111111111;
    simulator.set_register(rd, simulator.get_register(rs1) ^ imm);
}

void execute_SLLI(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int shamt = (instruction >> 20) & 0b111111;
    simulator.set_register(rd, simulator.get_register(rs1) << shamt);
}

void execute_SRLI(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int shamt = (instruction >> 20) & 0b111111;
    simulator.set_register(rd, (unsigned int)simulator.get_register(rs1) >> shamt);
}

void execute_SRAI(int instruction, RISC_V_Simulator &simulator) {
    int rd = (instruction >> 7) & 0b11111;
    int rs1 = (instruction >> 15) & 0b11111;
    int shamt = (instruction >> 20) & 0b111111;
    simulator.set_register(rd, simulator.get_register(rs1) >> shamt);
}


std::unordered_map<int, std::function<void(int, RISC_V_Simulator&)>> opcode_functions = {
        {0b0110011, execute_ADD},
        {0b0010011, execute_ADDI},
        {0b0110011, execute_AND},
        {00010011, execute_ANDI},
        {0b1100011, execute_BEQ},
        {0b1100011, execute_BNE},
        {0b1101111, execute_JAL},
        {0b1100111, execute_JALR},
        //{0b, execute_LOAD},
        //{0b, execute_ADD},
        {0b0110011, execute_OR},
        {0b0010011, execute_ORI},
        {0b0010011, execute_SLLI},
        {0b0110011, execute_SLT},
        {0b0010011, execute_SLTI},
        {0b0010011, execute_SLTIU},
        {0b0010011, execute_SRAI},
        {0b0110011, execute_SRL},
        {0b0010011, execute_SRLI},
        {0b0110011, execute_SUB},
        {0b0100011, execute_SW},
        {0b0110011, execute_XOR},
        {0b0010011, execute_XORI},


};
