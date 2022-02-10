/* 
 * Process Memory
 * 
 * Our computer can have many processes running at once, but they share
 * the same CPU, memory, and IO devices.
 * 
 * It is the operating system's job to manage who as access to these resources
 * at what time.
 * 
 * The operating system creates this illuision by:
 * 
 * 1. Context switching - rapidly switching which proccess has control over 
 *    the CPU.
 * 2. Virtual memory - the os can give processes the illusion of contiguous
 *    memory, but it is really a bunch of disparate groups. The os keeps track
 *    of these groups in a page table and handles the translation from virtual
 *    to physical memory. Since memory addresses are 64 bits, we represent them
 *    in hexadecimal. hex numbers are usually prepended with 0x. Thus we have
 *    the following: 0x21e = 0010 0001 1010 = 538
 *                   0xc4e = 1100 0100 1110 = 3150
 *                   0x36f = 0011 0110 1111 = 879
 *    The address space is organized as follows:
 *      - Code at the bottom
 *      - Static initilized variables above code
 *      - Static uninitilized variables above initilized
 *      - Heap above all static variables
 *      - Unmapped memory (big chunk) above heap
 *      - The stack at the very top of the address space
 *      - At the very top above the stack are argv and enviroment variables
 * 
 */