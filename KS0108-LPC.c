#include <lpc213x.h>

// data bus
#define KS0108_DATA_DIR		IODIR1
#define KS0108_DATA_PIN		IOPIN1
#define KS0108_DATA_SET		IOSET1
#define KS0108_DATA_CLR		IOCLR1

#define KS0108_D0			19

// control bus
#define KS0108_CTRL_DIR		IODIR1
#define KS0108_CTRL_SET		IOSET1
#define KS0108_CTRL_CLR		IOCLR1

#define KS0108_RS			(1 << 16)
#define KS0108_RW			(1 << 17)
#define KS0108_EN			(1 << 18)
#define KS0108_RES			(1 << 29)

#define KS0108_CS1			(1 << 28)
#define KS0108_CS2			(1 << 27)

#define DISPLAY_STATUS_BUSY	0x80

extern unsigned char screen_x;
extern unsigned char screen_y;

//-------------------------------------------------------------------------------------------------
// Delay function
//-------------------------------------------------------------------------------------------------
void GLCD_Delay(void)
{
//asm("nop");
//asm("nop");
__asm
{
nop
nop
}
}
//-------------------------------------------------------------------------------------------------
// Enalbe Controller (0-1)
//-------------------------------------------------------------------------------------------------
void GLCD_EnableController(unsigned char controller)
{
switch(controller){
	case 0 : KS0108_CTRL_CLR = KS0108_CS1; break;
	case 1 : KS0108_CTRL_CLR = KS0108_CS2; break;
	}
}
//-------------------------------------------------------------------------------------------------
// Disable Controller (0-1)
//-------------------------------------------------------------------------------------------------
void GLCD_DisableController(unsigned char controller)
{
switch(controller){
	case 0 : KS0108_CTRL_SET = KS0108_CS1; break;
	case 1 : KS0108_CTRL_SET = KS0108_CS2; break;
	}
}
//-------------------------------------------------------------------------------------------------
// Read Status byte from specified controller (0-1)
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadStatus(unsigned char controller)
{
unsigned char status;
KS0108_DATA_DIR &= ~(0xFF << KS0108_D0);
KS0108_CTRL_SET = KS0108_RW;
KS0108_CTRL_CLR = KS0108_RS;
GLCD_EnableController(controller);
KS0108_CTRL_SET = KS0108_EN;
GLCD_Delay();
status = (KS0108_DATA_PIN >> KS0108_D0);
KS0108_CTRL_CLR = KS0108_EN;
GLCD_DisableController(controller);
return status;
}
//-------------------------------------------------------------------------------------------------
// Write command to specified controller
//-------------------------------------------------------------------------------------------------
void GLCD_WriteCommand(unsigned char commandToWrite, unsigned char controller)
{
while(GLCD_ReadStatus(controller)&DISPLAY_STATUS_BUSY);
KS0108_DATA_DIR |= (0xFF << KS0108_D0);
KS0108_CTRL_CLR = (KS0108_RW | KS0108_RS);
GLCD_EnableController(controller);

KS0108_DATA_SET = (commandToWrite << KS0108_D0);
commandToWrite ^= 0xFF;
KS0108_DATA_CLR = (commandToWrite << KS0108_D0);

KS0108_CTRL_SET = KS0108_EN;
GLCD_Delay();
KS0108_CTRL_CLR = KS0108_EN;
GLCD_DisableController(controller);
}
//-------------------------------------------------------------------------------------------------
// Read data from current position
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadData(void)
{
unsigned char data;
while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
KS0108_DATA_DIR &= ~(0xFF << KS0108_D0);
KS0108_CTRL_SET = (KS0108_RW | KS0108_RS);
GLCD_EnableController(screen_x / 64);
GLCD_Delay();
KS0108_CTRL_SET = KS0108_EN;
GLCD_Delay();
data = (KS0108_DATA_PIN >>  KS0108_D0);
KS0108_CTRL_CLR = KS0108_EN;
GLCD_DisableController(screen_x / 64);
screen_x++;
return data;
}
//-------------------------------------------------------------------------------------------------
// Write data to current position
//-------------------------------------------------------------------------------------------------
void GLCD_WriteData(unsigned char dataToWrite)
{
while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
KS0108_DATA_DIR |= (0xFF << KS0108_D0);
KS0108_CTRL_CLR = KS0108_RW;
KS0108_CTRL_SET = KS0108_RS;

KS0108_DATA_SET = (dataToWrite << KS0108_D0);
dataToWrite ^= 0xFF;
KS0108_DATA_CLR = (dataToWrite << KS0108_D0);

GLCD_EnableController(screen_x / 64);
KS0108_CTRL_SET = KS0108_EN;
GLCD_Delay();
KS0108_CTRL_CLR = KS0108_EN;
GLCD_DisableController(screen_x / 64);
screen_x++;
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_InitalizePorts(void)
{
//VPBDIV = 1;
KS0108_CTRL_DIR |= (KS0108_CS1 | KS0108_CS2 | KS0108_RS | KS0108_RW | KS0108_EN | KS0108_RES);
KS0108_CTRL_SET = (KS0108_CS1 | KS0108_CS2 | KS0108_RES);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadByteFromROMMemory(char * ptr)
{
return *(ptr);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
