#include "mem.h"

uint8_t memory[MEMORY_SIZE];
uint16_t opcode;
uint8_t display[DISPLAY_WIDTH * DISPLAY_HEIGHT];

uint8_t fontset[80] =
{
	0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

int init_mem() {
    //clear memory
    for (int i = 0; i < MEMORY_SIZE; i++) memory[i] = 0;
    //load fontset
    if (load_fontset("font/font1.bin") == 1){
	printf("Error: Could not open font file\n");
	return 1;
    }
    pc = 0x200;
    load_fontset(fontset);
    return 0;
}

int loadrom(const char *rom) {
    FILE *file = fopen(rom, "rb");
    if (file == NULL) {
        perror("Failed to open ROM file");
        return -1;
    }

    // Determine file size
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Failed to seek to end of file");
        fclose(file);
        return -1;
    }

    long size = ftell(file);
    if (size == -1) {
        perror("Failed to get file size");
        fclose(file);
        return -1;
    }

    if (size > (4096 - 0x200)) { // CHIP-8 memory size is 4KB, ROM starts at 0x200
        fprintf(stderr, "ROM file is too large to fit in memory\n");
        fclose(file);
        return -1;
    }

    // Reset file pointer to beginning of file
    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("Failed to reset file pointer to beginning");
        fclose(file);
        return -1;
    }

    // Read ROM into memory starting at 0x200
    size_t bytesRead = fread(memory + 0x200, 1, size, file);
    if (bytesRead != (size_t)size) {
        perror("Failed to read ROM file into memory");
        fclose(file);
        return -1;
    }

    fclose(file);
    printf("ROM successfully loaded into memory (%ld bytes)\n", size);
    return 0;
}

void execute(){
	uint8_t x,y,kk,n;
	uint16_t nnn;
	uint32_t i, keyPressed;

	opcode = memory[pc] << 8 | memory[pc+1];
	pc+=2;
	x = (opcode & 0x0F00) >> 8;
	y = (opcode & 0x00F0) >> 4;
	nnn = (opcode & 0x0FFF);
	kk = (opcode & 0x00FF);
	n = (opcode & 0x000F);
	printf("Opcode: %x\n",opcode);
	printf("Program Counter: %x \n",pc);
	printf("I: %x \n",i);
	switch (opcode & 0xF000){
		case 0x0000:
			switch (opcode & 0x00FF){
				case 0x00E0:
					memset(display, 0, 2048);
					drawflag = 1;
					break;
				case 0x00EE:
					--sp;
					pc = stack[sp];
					break;
			} break;
		case 0x1000:
			pc = nnn;
			break;
		case 0x2000:
			stack[sp] = pc;
			++sp;
			pc = nnn;
			break;
	}
}

int load_fontset(char *fontName){
	memcpy(memory+0x50,fontName,80*sizeof(int8_t));
	return 0;
}

void display_font(){
    for (int i = 0; i < FONT_HEIGHT; i++){
        for (int j = 0; j < FONT_WIDTH; j++){
            printf("%02x ", memory[0x50 + i * FONT_WIDTH + j]);
        }
        printf("\n");
    }
}

void print_mem() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (i % 16 == 0) printf("\n");//print 16 bytes per line
        printf("%02x ", memory[i]);
    }
    printf("\n");
}

void write_block(uint16_t addr, uint8_t val) {
    memory[addr] = val;
}

void print_block(uint16_t addr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%02x ", memory[addr + i]);
    }
    printf("\n");
}

