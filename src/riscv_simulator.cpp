#include "../include/riscv_simulator.h"
#include "../include/riscv_instructions.h"

RISC_V_Simulator::RISC_V_Simulator() {
    registers.resize(32, 0); // 32 Register initialisieren
    memory.resize(1024, 0);  // Speicher initialisieren (1 KB)
    pc = 0;                  // Programmzähler initialisieren
}

void RISC_V_Simulator::load_program(std::vector<int> program) {
    for (size_t i = 0; i < program.size(); ++i) {
        memory[i] = program[i];
    }
}

void RISC_V_Simulator::execute_next_instruction() {
    int instruction = memory[pc]; // Holt die nächste Anweisung aus dem Speicher
    int opcode = instruction >> 27;

    // Befehlslogik aufrufen
    if (opcode_functions.find(opcode) != opcode_functions.end()) {
        opcode_functions[opcode](instruction, *this);
    } else {
        // Unerwarteten Befehl behandeln
        std::cerr << "Unerwarteter Befehl mit Opcode: " << opcode << std::endl;
    }

    pc += 4; // Gehe zur nächsten Anweisung
}

void RISC_V_Simulator::print_registers() {
    for (size_t i = 0; i < registers.size(); ++i) {
        std::cout << "Register " << i << ": " << registers[i] << std::endl;
    }
}

int RISC_V_Simulator::get_register(int index) const {
    return registers[index];
}

void RISC_V_Simulator::set_register(int index, int value) {
    registers[index] = value;
}

int RISC_V_Simulator::get_pc() const {
    return pc;
}

void RISC_V_Simulator::set_pc(int value) {
    pc = value;
}