#include "mem.h"

uint8_t memory[MEMORY_SIZE];
uint16_t opcode;
uint8_t display[DISPLAY_WIDTH * DISPLAY_HEIGHT];
uint8_t keyboard[16];
uint8_t v[16];

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
    //if (load_fontset("font/font1.bin") == 1){
//	printf("Error: Could not open font file\n");
//	return 1;
  //  }
    pc = 0x200;
    memcpy(memory + 0x50, fontset, sizeof(fontset));
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
	uint32_t i = 0; 
	uint32_t keyPressed;

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
		case 0x3000: 
			if (v[x] == kk) pc += 2;
			break;
			
		//4xkk
		case 0x4000:
			if (v[x] != kk) pc+=2;
			break;

		//5xy0
		case 0x5000:
			if (v[x] == v[y]) pc+=2;
			break;
			
		//6xkk
		case 0x6000:
			v[x] = kk;
			break;
			
		//7xkk
		case 0x7000:
			v[x] += kk;
			break;

		//8xyn	
		case 0x8000:
			switch(n){
				//8xy0
				case 0x0000:
				v[x] = v[y];
				break;
				//8xy1
				case 0x0001:
				v[x] |= v[y];
				break;
				//8xy2
				case 0x0002:
				v[x] &= v[y];
				break;
				//8xy3
				case 0x0003:
				v[x] ^= v[y];
				break;
				//8xy4
				case 0x0004:{
					int i;
					i = (int)(v[x]) + (int)(v[y]);
					if (i > 255)
						v[0xF] = 1;
					else
						v[0xF] = 0;
					v[x] = i & 0xFF;
				}
				break;
			//8xy5
			case 0x0005:
				if (v[x]> v[y] ) v[0xF] = 1;
				else v[0xF] = 0;
				v[x] -= v[y];
				break; 
			//8xy6
			case 0x0006:
				v[0xF] = v[x] &1;
				v[x] >>= 1;
				break;
			//8xy7
			case 0x0007:
				if(v[y] > v[x]) v[0xF] = 1;
				else v[0xF] = 0;
				v[x] = v[y] - v[x];
				break;
			//8xyE
			case 0x000E:
				v[0xF] = v[x] >> 7;
				v[x] <<= 1;
				break; 	

			default: printf("Opcode error 8xxx -> %x\n",opcode );			
			}
			break;
			
			//9xy0
			case 0x9000:
			if(v[x] != v[y]) pc += 2;
			break;

			//Annn
			case 0xA000:
			i = nnn;
			break;

			//Bnnn
			case 0xB000:
			pc = (nnn) + v[0x0];
			break;

			//Cxkk
			case 0xC000:
			v[x] = (rand() % 0x100) & (kk);
			break;

			//Dxyn
			case 0xD000:;
			uint16_t x = v[x];
			uint16_t y = v[y];
			uint16_t height = n;
			uint8_t pixel;

			v[0xF] = 0;
			for (int yline = 0; yline < height; yline++) {
				pixel = memory[y + yline];
				for(int xline = 0; xline < 8; xline++) {
					if((pixel & (0x80 >> xline)) != 0) {
						if(display[(x + xline + ((y + yline) * 64))] == 1){
							v[0xF] = 1;                                   
						}
						display[x + xline + ((y + yline) * 64)] ^= 1;
					}

				}

			}
			drawflag = 1;
			break;
			
			//Exkk
			case 0xE000:
			switch(kk){
				//Ex9E
				case 0x009E:
				if(keyboard[v[x]] != 0)pc += 2;
				break;						
				//ExA1
				case 0x00A1:
				if(keyboard[v[x]]==0)pc+=2;
				break;

			}
			break;

			//Fxkk
			case 0xF000:

			switch(kk){
				//Fx07
				case 0x0007:

				v[x] = delay_timer;
				break;
				//Fx0A
				case 0x000A:
				keyPressed = 0;
				for(i=0;i<16;i++)
				{
					if (keyboard[i])
					{
						keyPressed = 1;
						v[x] = i;
					}
				}
	
				if (keyPressed == 0)
				{
					pc -= 2;
				}
				
				break;
				//Fx15
				case 0x0015:
				delay_timer = v[x];
				break;
				//Fx18
				case 0x0018:
				sound_timer = v[x];
				break;
				//Fx1E
				case 0x001E:
				i = i + v[x];
				break;
				//Fx29
				case 0x0029:
				i = v[x] * 5;
				break;
				//Fx33
				case 0x0033:{
					int vX;
					vX = v[x];
					memory[i]     = (vX - (vX % 100)) / 100;
					vX -= memory[i] * 100;
					memory[i + 1] = (vX - (vX % 10)) / 10;
					vX -= memory[i+1] * 10;
					memory[i + 2] = vX;
				}
				break;

				//Fx55
				case 0x0055:

				for (uint8_t j = 0; j <= i; ++j){
					memory[j+ i] = v[j];
				}
				break;
				//Fx65
				case 0x0065:

				for (uint8_t j = 0; j <= x; ++j){
					v[j] = memory[i+ j];	
				}
				break;

			}
			break;	
		default: printf("OPCODE ERROR -> %x \n",opcode); break;
	}
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

