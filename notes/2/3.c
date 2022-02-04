/* 
 * Compilation!
 * 
 * An executable file is a single file containing machine code that is
 * executed by the computer. This is also called a binary file. The OS
 * loads this file into memory when it begins execution
 * 
 * Four steps:
 *  1. The preprocessor rewrites and inserts C code based on 
 *     directives (#whatever). gcc -E FILENAME does this
 *  2. Compiler translates pre-processed source into assembly.
 *     gcc -S PP'd_C_FILE does this. This step is where a lot of the
 *     optimization happens, so it is non-reversable.
 *  3. Assembler converst assembly source to a relocatable object file
 *     aka binary. gcc -c ASSEMBLY_FILE does this. The object file 
 *     contains machine code and information for the linker (everything 
 *     that needs to be linked up, all unresolved machine code). objdump 
 *     command shows this linking information.
 *  4. Linker combines all object files into an executable.
 *     gcc -lv OBJECT_FILES does this
 * 
 */