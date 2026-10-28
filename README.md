# Oshans C compiler (occ)
## Compiler driver
- accept arguements (input file paths)
- accept flags (--lex, --parse, --codegen)
- run the cmd `gcc -E -P INPUT_FILE -o PREPROCESSED_FILE` (.i is the file extension btw)
- since we dont have the compiler yet, just delete the PREPROCESSED_FILE after creation 
- make the assembly `gcc ASSEMBLY_FILE -o OUTPUT_FILE` and delete it. 
- add a - S flag to spit out the assembly file and not assemble it.


