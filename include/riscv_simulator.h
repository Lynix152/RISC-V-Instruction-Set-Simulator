#ifndef RISCV_SIMULATOR_H
#define RISCV_SIMULATOR_H

#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>

class RISC_V_Simulator {
private:
    std::vector<int> registers; // Registersatz
    std::vector<int> memory;    // Speicher
    int pc;                     // Programmzähler

public:
    RISC_V_Simulator();

    void load_program(std::vector<int> program);

    void execute_next_instruction();

    void print_registers();

    int get_register(int index) const;

    void set_register(int index, int value);

    int get_pc() const;

    void set_pc(int value);
};

#endif // RISCV_SIMULATOR_H