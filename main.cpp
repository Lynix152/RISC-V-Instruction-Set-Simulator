#include "include/riscv_simulator.h"

int main() {
    RISC_V_Simulator simulator;

    // Beispielprogramm laden (ADDI-Operation)
    std::vector<int> program = {0b00000000001000110000000010010011}; // ADDI x1, x2, 3
    simulator.load_program(program);

    // Eine Anweisung ausführen
    simulator.execute_next_instruction();

    // Registerinhalt ausgeben
    simulator.print_registers();

    return 0;
}