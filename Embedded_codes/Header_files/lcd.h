 #include "lcd_commands.h"
 #include "types.h"
 void cmdLCD(u8 cmd);
 void charLCD(unsigned char ascii);
 void InitLCD(void);
 void writeLCD(u8 data);
 void BinLCD(u32 n,u8 dp);
 void strLCD(char *p);
 void intLCD(u32 n);
 void f32_LCD(f32 fnum,u8 nDP);
 void HexLCD(u32 n);
 void octLCD(u32 n);
