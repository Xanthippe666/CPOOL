#include "Vand_gate.h"
#include "verilated_vcd_c.h"

#include <verilated.h>
#include <iostream>             // Need std::cout

#include <assert.h>

using namespace std;


void printTest(int num){
  cout << "----TEST ----" << num << endl;
}


vluint64_t main_time = 0;
double sc_time_stamp(){
  return main_time;
}

int main(int argc, char** argv, char** env) {
      // Verilated::commandArgs(argc, argv);
      // Verilated::traceEverOn(true);
      // VerilatedVcdC* tfp = new VerilatedVcdC;

      VerilatedContext* contextp = new VerilatedContext;
      contextp->traceEverOn(true);

      contextp->commandArgs(argc, argv);
        Vand_gate* top = new Vand_gate{contextp};
      /////////////////////////////

    //   while (!contextp->gotFinish()) { 
          // for(int i = 0)
        // top->trace(tfp, 0);
        // tfp->open("wave.vcd");

        for(int i = 0 ; i < 4; i++){
          for (int j = 0; j < 4; j++){

            contextp->timeInc(1);

            top->a = i;
            top->b = j;
            top->eval();
            printTest(j*4+i);
            cout << (int) top->a << "&" << (int) top->b << "=" << (int) top->c << endl;
            // cout << (int)( i & j )<< endl;
            assert((int) (i&j) == (int) top->c);


            // tfp->dump(main_time);
            main_time++;

          }
        }

    //   }


       top->final();
      //  tfp->close(); //("wave.vcd")
        ////////////////////////////
      delete top;
      delete contextp;
      return 0;

  }