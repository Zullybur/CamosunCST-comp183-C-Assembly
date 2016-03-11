EXE=l80
SRC=l80

$(EXE): $(SRC).asm
	@yasm -f elf64 -g dwarf2 $(SRC).asm
	@gcc -o $(EXE) $(SRC).o

test: $(EXE)
	@bash .batch_test.sh $(EXE)

clean:
	@rm -f $(SRC).o $(EXE) core log

run: $(EXE)
	@./$(EXE)
