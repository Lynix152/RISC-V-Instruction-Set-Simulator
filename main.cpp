// literature: https://riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf

#include "include/riscv_simulator.h"

int main() {
    RISC_V_Simulator simulator;

    std::vector<int> program = {0b00000000001000110000000010010011}; // ADDI x1, x2, 3
    simulator.load_program(program);

    simulator.execute_next_instruction();

    simulator.print_registers();

    return 0;
}