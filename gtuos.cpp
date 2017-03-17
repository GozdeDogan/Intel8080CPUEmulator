#include <iostream>
#include "8080emuCPP.h"
#include "gtuos.h"
#include <cstring>

using namespace std;

uint64_t GTUOS::handleCall(const CPU8080 & cpu){
    unsigned int myint = 0;
    switch(cpu.state->a){
        case 1: // PRINT_B
            PRINT_B(cpu);
            break;
        case 2: // PRINT_MEM
            PRINT_MEM(cpu);
            break;
        case 3: // READ_B
            READ_B(cpu);
            break;
        case 4: // READ_MEM
            READ_MEM(cpu);
            break;
        case 5: // PRINT_STR
            PRINT_STR(cpu);
            break;
        case 6: // READ_STR
            READ_STR(cpu); 
            break;
        default:
            cout << "fault" << endl;
    
    }
}

void GTUOS::PRINT_B(const CPU8080 & cpu){
    cout << "System Call: PRINT_B" << endl;
    cout << "Value of B " << (unsigned)(cpu.state->b) << endl;
}

void GTUOS::READ_B(const CPU8080 & cpu){
    unsigned int myint;
    cout << "System Call: READ_B" << endl;
    cin >> hex >> myint;
    //cout << "myint: " << myint << endl;
    cpu.state->b = myint;
    //cout << "b: " << (unsigned)cpu.state->b <<endl;

}

void GTUOS::PRINT_MEM(const CPU8080 & cpu){
    uint16_t wd;
    cout << "System Call: PRINT_MEM" << endl;
    wd = ((uint16_t)cpu.state->b << 8) | cpu.state->c;
    cout << "Value of MEM " << (unsigned)(cpu.memory[wd]) << endl;
}

void GTUOS::READ_MEM(const CPU8080 & cpu){
    int myint;
    uint16_t wd;
    
    cout << "System Call: READ_MEM" << endl;
    cin >> hex >> myint;
    wd = ((uint16_t)cpu.state->b << 8) | cpu.state->c;
    cpu.memory[wd] = myint;
}

void GTUOS::PRINT_STR(const CPU8080 & cpu){
    uint16_t wd;
    cout << "System Call: PRINT_STR" << endl;
    wd = ((uint16_t)cpu.state->b << 8) | cpu.state->c;
    while(cpu.memory[wd] != '\0'){
        cout << (char)(cpu.memory[wd]);
        wd++;
    } 
    cout << endl;   
}

void GTUOS::READ_STR(const CPU8080 & cpu){
    string s;
    int i=0;
    uint16_t wd;
    
    cout << "System Call: READ_STR" << endl;
    cin >> s;
    wd = ((uint16_t)cpu.state->b << 8) | cpu.state->c;
    i=0;
    while(s[i] != '\0'){
        cpu.memory[wd] = (unsigned char)s[i];
        wd++;
        i++;
    }
    cpu.memory[wd] = s[i];
}

int GTUOS::calculateCycle(const CPU8080 & cpu){
    int cycle = 0;
    switch(cpu.state->a){
        case 1: // PRINT_B
        case 2: // PRINT_MEM
        case 3: // READ_B
        case 4: // READ_MEM
            cycle = 10;
            break;
        case 5: // PRINT_STR 
        case 6: // READ_STR
            cycle = 100;
            break;
    }
    return cycle;
}
