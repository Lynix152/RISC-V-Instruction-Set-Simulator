#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional> // für std::function

class RISC_V_Simulator {
private:
    std::vector<int> registers; // Registersatz
    std::vector<int> memory;    // Speicher
    int pc;                     // Programmzähler

    // Map zur Zuordnung von Opcodes zu Funktionszeigern
    std::unordered_map<int, std::function<void(int)>> opcode_functions;

public:
    RISC_V_Simulator() {
        registers.resize(32, 0); // 32 Register initialisieren
        memory.resize(1024, 0);  // Speicher initialisieren (1 KB)
        pc = 0;                  // Programmzähler initialisieren

        // Befehlsfunktionen zuweisen
        opcode_functions[0b0000000] = [this](auto && PH1) { execute_add(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b0000011] = [this](auto && PH1) { execute_load(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b1100011] = [this](auto && PH1) { execute_jal(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b0010011] = [this](auto && PH1) { execute_addi(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b0000100] = [this](auto && PH1) { execute_sub(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b0001000] = [this](auto && PH1) { execute_slt(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b1100111] = [this](auto && PH1) { execute_jalr(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b1101111] = [this](auto && PH1) { execute_jal(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b1100111] = [this](auto && PH1) { execute_jalr(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b1100111] = [this](auto && PH1) { execute_jalr(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b1100111] = [this](auto && PH1) { execute_jalr(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b0000010] = [this](auto && PH1) { execute_sw(std::forward<decltype(PH1)>(PH1)); };
        opcode_functions[0b0000010] = [this](auto && PH1) { execute_sw(std::forward<decltype(PH1)>(PH1)); };

    }

    // Lädt das RISC-V-Programm in den Speicher
    void load_program(std::vector<int> program) {
        for (size_t i = 0; i < program.size(); ++i) {
            memory[i] = program[i];
        }
    }

    // Führt die nächste Anweisung im Speicher aus
    void execute_next_instruction() {
        int instruction = memory[pc]; // Holt die nächste Anweisung aus dem Speicher
        int opcode = instruction >> 27;

        // Befehlslogik aufrufen
        if (opcode_functions.find(opcode) != opcode_functions.end()) {
            opcode_functions[opcode](instruction);
        } else {
            // Unerwarteten Befehl behandeln
            std::cerr << "Unerwarteter Befehl mit Opcode: " << opcode << std::endl;
        }

        pc += 4; // Gehe zur nächsten Anweisung
    }

    // Führt die ADD-Operation aus
    void execute_add(int instruction) { // TODO:
        int rd = (instruction >> 7) & 0b11111;
        int rs1 = (instruction >> 15) & 0b11111;
        int rs2 = (instruction >> 20) & 0b11111;
        registers[rd] = registers[rs1] + registers[rs2];
    }

    // Führt die LOAD-Operation aus
    void execute_load(int instruction) { // TODO:
        int rd = (instruction >> 7) & 0b11111;
        int rs1 = (instruction >> 15) & 0b11111;
        int imm = instruction >> 20;
        registers[rd] = memory[registers[rs1] + imm];
    }

    // Führt die JAL-Operation aus
    void execute_jal(int instruction) { // TODO:
        int rd = (instruction >> 7) & 0b11111;
        int imm = instruction >> 20;
        registers[rd] = pc + 4;
        pc += imm - 4;
    }

    // Führt die ADDI-Operation aus
    void execute_addi(int instruction) { // TODO:
        int rd = (instruction >> 7) & 0b11111;
        int rs1 = (instruction >> 15) & 0b11111;
        int imm = instruction >> 20;
        registers[rd] = registers[rs1] + imm;
    }

// Führt die SUB-Operation aus
    void execute_sub(int instruction) { // TODO:
        int rd = (instruction >> 7) & 0b11111;
        int rs1 = (instruction >> 15) & 0b11111;
        int rs2 = (instruction >> 20) & 0b11111;
        registers[rd] = registers[rs1] - registers[rs2];
    }

    // Führt die SLT-Operation aus
    void execute_slt(int instruction) { // TODO:
        int rd = (instruction >> 7) & 0b11111;
        int rs1 = (instruction >> 15) & 0b11111;
        int rs2 = (instruction >> 20) & 0b11111;
        registers[rd] = (registers[rs1] < registers[rs2]) ? 1 : 0;
    }

    // Führt die JALR-Operation aus
    void execute_jalr(int instruction) { // TODO:
        int rd = (instruction >> 7) & 0b11111;
        int rs1 = (instruction >> 15) & 0b11111;
        int imm = instruction >> 20;
        registers[rd] = pc + 4;
        pc = registers[rs1] + imm;
    }

    // Führt die SW-Operation aus
    void execute_sw(int instruction) { // TODO:
        int rs1 = (instruction >> 15) & 0b11111;
        int rs2 = (instruction >> 20) & 0b11111;
        int imm = instruction >> 25;
        memory[registers[rs1] + imm] = registers[rs2];
    }

    // Gibt die Registerinhalte aus
    void print_registers() {
        for (size_t i = 0; i < registers.size(); ++i) {
            std::cout << "Register " << i << ": " << registers[i] << std::endl;
        }
    }
};

// int main() {
    //RISC_V_Simulator simulator;

    // Beispielprogramm laden (ADDI-Operation)
    //std::vector<int> program = {0b00000000001000110000000010010011}; // ADDI x1
//}