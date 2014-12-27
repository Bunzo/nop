typedef struct {
	unsigned int opcd: 8;
	unsigned int op0: 8;
	unsigned int op1: 8;
	unsigned int op2: 8;
} ins;

// Instructions
// 0x00		add  op1, op2  : op1 = op1 + op2
// 0x01		addi op1, #IMM : op1 = op1 + IMM (IMM : number)
// 0x02		sub  op1, op2  : op1 = op1 - op2
// 0x03		subi op1, #IMM : op1 = op1 - IMM (IMM : number)
// 0x04		mul  op1, op2  : op1 = op1 * op2
// 0x05		muli op1, #IMM : op1 = op1 * IMM (IMM : number)
// 0x06		ld   op1, op2  : op1 = mem[op2]
// 0x07		ldi  op1, #IMM : op1 = IMM[op2]
// 0x08		st   op1, op2  : mem[ op1 ] = op2
// 0x09		sti  op1, #IMM : mem[ op1 ] = IMM
