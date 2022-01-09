
module and_gate(a,b,c);

input[1:0] a,b;
output[1:0]  c;

assign c = a & b;



   // Print some stuff as an example
   initial begin
    //   if ($test$plusargs("trace") != 0) begin
         $display("[%0t] Tracing to vlt_dump.vcd...\n", $time);
         $dumpfile("vlt_dump.vcd");
         $dumpvars();
    //   end
    //   $display("[%0t] Model running...\n", $time);
   end

endmodule
