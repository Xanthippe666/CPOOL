#other tests

OR:
	@echo "-- building and Testing OR gate "
	@echo

AND:
	@echo
	@echo "-- Building and Testing AND Gate."
	verilator -Wall -cc --exe --trace --build and_gate.cpp and_gate.v
	@echo "-- build complete."
	./obj_dir/Vand_gate
	@echo "-- test complete."


clean:
	rm -rf obj_dir logs *.log *.dmp *.vpd *.vcd coverage.dat core
