#include "rfid_card.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int entry_mode=0;//Entry button pressed flag
int delete_mode=0;//Delete button pressed flag
int exit_mode=0;//Exit button pressed flag
int value=0;   // total amount
int actual_pin=0;//Stores actual ATM PIN received from server
char buf[50];//General purpose communication buffer

void cash_payment_frontend(void);
void card_payment_frontend(void);

//Convert Integer to String
void int_to_str(char *buf,int size,int num)
{
        memset(buf,0,size);
        sprintf(buf,"%d",num);
}
//RFID function
void RFID(void)
{
        if((entry_mode||delete_mode||exit_mode)==0)
                {
        cmdLCD(0X01);
        cmdLCD(0x80);
        strLCD("  Smart Cart");
                cmdLCD(0xC0);
        strLCD("   Ready");
        delay_s(100);
        }
      // ENTRY MODE
        if(entry_mode == 1)
        {
        int status=-1;//initial status
                cmdLCD(0x01);//clear lcd screen
                cmdLCD(0x80);//set cursor line 1
                strLCD("Entry Mode");
                cmdLCD(0xC0);//set cursor to line 2
                strLCD("Scan RFID..");
                //Entry mode selected
                while(entry_mode == 1)
                {
                        if(uart1_ready)//Wait for RFID card scan
                        {
                                uart1_ready = 0;
                                uart1_buf[strcspn(uart1_buf,"\r\n")] = 0;

                                                   // MANAGER CARD
                                if(strcmp(uart1_buf,"12608170")==0)
                                {
                                        cmdLCD(0x01);
                                        cmdLCD(0x80);
                                        strLCD("Manager Card");
                                        cmdLCD(0xC0);
                                        strLCD("Update Stock...");
                                        uart0_tx('M');//transmit 'M' to the backend
                                        uart0_str_tx(uart1_buf);//transmit rfid number
                                        uart0_tx('$');//transmit string end with '$'
                                        delay_s(2);
                                        memset(buf,0,sizeof(buf));//clear buffer
                                                            uart0_str_rx(buf);//receive the exit status fromthe manager
                                                            buf[strcspn(buf,"$\r\n")] = '\0';
                                                            status=atoi(buf);
                                                            if(status==0)
                                                                                {
                                                                      entry_mode=0;
                                                            }
                                                            else
                                                                                {
                                                                                               entry_mode=1;
                                                        }
                                                     }
                       // CUSTOMER CARD
                                else
                                {
                                        uart0_tx('C');//transmit 'C' to the backend
                                        uart0_str_tx(uart1_buf);//transmit the rfid id number
                                        uart0_tx('$');//end with the '$'
                                        cmdLCD(0x01);
                                        cmdLCD(0x80);
                                        strLCD("Customer Card");//display customer card in lcd screen
                                        cmdLCD(0xC0);
                                        strLCD("Adding Items...");
                                        delay_s(2);
                                }
                        }

                //in between entry mode,exit or delete occurs then exit from the entry mode
                        if(delete_mode || exit_mode)
                        {
                                break;
                        }
                }

                //entry mode is equal to zero
                entry_mode = 0;
                cmdLCD(0x01);

        }
        // DELETE MODE
        if(delete_mode == 1)
        {
                cmdLCD(0x01);
                cmdLCD(0x80);
                strLCD("Delete Mode");
                cmdLCD(0xC0);
                strLCD("Scanning card..");
                while(delete_mode == 1)
                {
                        if(uart1_ready)
                        {
                                uart1_ready = 0;
                                uart0_tx('D');
                                uart0_str_tx(uart1_buf);
                                uart0_tx('$');
                                cmdLCD(0x01);
                                cmdLCD(0x80);
                                strLCD("Item Deleted");
                                delay_s(5);
                        }
                        if(entry_mode || exit_mode)
                        {
                                break;
                        }
                }
                delete_mode = 0;
                cmdLCD(0x01);
        }

//exit mode
if(exit_mode == 1)
{
        char choice;
        char buf[20];
        uart0_tx('T');//transmit the 'T' to the backend
        uart0_tx('$');
        memset(buf,0,sizeof(buf));//clear buf
        uart0_str_rx(buf);//receive the cart status
        buf[strcspn(buf,"\r\n")] = '\0';
        //if cart is empty,then display cart empty
          if(strcmp(buf,"EMPTY")==0)
           {
             cmdLCD(0x01);
             cmdLCD(0x80);
             strLCD("Cart Empty");
             delay_s(5);
             exit_mode = 0;
               return;
              }
 //if cart having the items then proceed to the payment
          else
                  {
                        cmdLCD(0x01);
                        cmdLCD(0x80);
                //payment in cash or online
         strLCD("1:Cash 2:Card");
          while(exit_mode==1)
                         {
              if(entry_mode==1 || delete_mode==1)
                          {
                                       exit_mode=0;
                                break;
                  }
                          choice = keyscan();
                                if(choice==0)
                                {
                                        delay_ms(10);
                                continue;
                                }
                            if(choice == '1')
                            {
                                cash_payment_frontend();
                                exit_mode=0;
                break;
                }
                 // ONLINE MODE
                            else if(choice == '2')
                            {
                                card_payment_frontend();
                                        exit_mode=0;
                                        break;
                            }

                        }
                         cmdLCD(0x01);
                 }
   }
}

//cash payment
void cash_payment_frontend(void)
{
    char buf[50];
    int total=0;
    int entered_money=0;
    // ASK TOTAL BILL
    uart0_tx('H');
    uart0_tx('$');
    memset(buf,0,sizeof(buf));
    uart0_str_rx(buf);
    buf[strcspn(buf,"$\r\n")] = '\0';
    if(strlen(buf)==0)
        {
    return;
        }
        total=atoi(buf);
    // DISPLAY TOTAL
    cmdLCD(0x01);
    cmdLCD(0x80);
    strLCD("Total bill:");
    cmdLCD(0xC0);
    intLCD(total);
    delay_s(10);
  // ENTER MONEY
l1:cmdLCD(0x01);
    cmdLCD(0x80);
    strLCD("Enter Money:");
    cmdLCD(0xC0);
    entered_money=ReadNum();
    if(entered_money==total)
        {
        uart0_tx('1');
        uart0_tx('$');
        cmdLCD(0x01);
        cmdLCD(0x80);
        strLCD("paid successfully");
        delay_s(5);
        cmdLCD(0x01);
        cmdLCD(0x80);
        strLCD("Thank you for");
                 cmdLCD(0xc0);
          strLCD("   shopping   ");
          delay_s(10);
                return;
                //exit_mode=0;
    }
        //if entered amount is greater than actual amount
    else if(entered_money>total)
        {
        int return_money=entered_money-total;
        uart0_tx('1');
        uart0_tx('$');
        cmdLCD(0x01);

        cmdLCD(0x80);
        strLCD("payment success");
        cmdLCD(0xC0);
        strLCD("return:");
        cmdLCD(0xC0+8);
        intLCD(return_money);
        delay_s(5);
                cmdLCD(0x01);
                cmdLCD(0x80);
                strLCD("Thank you for");
                cmdLCD(0xc0);
                strLCD("   shopping   ");
                delay_s(10);
               //exit_mode=0;
                return;
    }
//if money is lesser than the actual bill
    else
        {
           uart0_tx('0');
            uart0_tx('$');
            cmdLCD(0x01);
            cmdLCD(0x80);
            strLCD("payment failed");
            cmdLCD(0xC0);
            strLCD("less money");
            delay_s(5);
            goto l1;
    }
}

//card payment
void card_payment_frontend(void)
{
    char buf[50];
    int pin;
    cmdLCD(0x01);
    cmdLCD(0x80);
    strLCD("Scan ATM Card");
    while(uart1_ready == 0);
    uart1_ready = 0;
    // SEND CARD
    uart0_tx('B');
    uart0_str_tx(uart1_buf);
    uart0_tx('$');
    // RECEIVE CARD STATUS
    memset(buf,0,sizeof(buf));
    uart0_str_rx(buf);
    buf[strcspn(buf,"$\r\n")] = '\0';
    // INVALID CARD
    if(strcmp(buf,"INVALID")==0)
    {
        cmdLCD(0x01);
        cmdLCD(0x80);
        strLCD("Invalid Card");
        delay_s(2);
        return;
    }

    // CARD OK
        else if(strcmp(buf,"CARD_OK")==0)
        {
            memset(buf,0,sizeof(buf));
            uart0_str_rx(buf);//receive the actual pin
            buf[strcspn(buf,"$\r\n")] = '\0';
            actual_pin=atoi(buf);
        cmdLCD(0x01);
        cmdLCD(0x80);
        strLCD("received PIN:");
        cmdLCD(0xC0);
        intLCD(actual_pin);
        delay_s(2);
loop:cmdLCD(0x01);
        cmdLCD(0x80);
        strLCD("Enter ATM PIN:");
        cmdLCD(0xC0);
        pin = ReadNum();
        delay_s(2);
        // if received pin is equal to the actual pin then SUCCESS
        if(pin==actual_pin)
        {
                uart0_tx('1');
                uart0_tx('$');
            memset(buf,0,sizeof(buf));
            uart0_str_rx(buf);
            buf[strcspn(buf,"$\r\n")] = '\0';
            if(strcmp(buf,"SUCCESS")==0){
            cmdLCD(0x01);
            cmdLCD(0x80);
            strLCD("Payment OK");
            delay_s(5);
                cmdLCD(0x01);
                cmdLCD(0x80);
                strLCD("Thank you for");
                cmdLCD(0xC0);
                strLCD("  shopping  ");
                delay_s(8);
                exit_mode=0;
            return;
        }
                //if the balance is lesser than the bill
      else if(strcmp(buf,"LOW_BAL")==0)
        {
            cmdLCD(0x01);
            cmdLCD(0x80);
            strLCD("LOW Balance");
            delay_s(5);
            return;
        }
        }
       // if pin is not equal to the entered pin then FAIL
   else if(pin!=actual_pin)
        {
                uart0_tx('0');
                uart0_tx('$');
                memset(buf,0,sizeof(buf));
                uart0_str_rx(buf);
                buf[strcspn(buf,"$\r\n")] = '\0';
            cmdLCD(0x01);
            cmdLCD(0x80);
            strLCD("Wrong PIN");
            delay_s(5);
            if(strcmp(buf,"RETRY")==0){
            goto loop;
        }

     // after 3 attempts of pin,card is BLOCKED
     else if(strcmp(buf,"CASH")==0)
        {
            cmdLCD(0x01);
            cmdLCD(0x80);
            strLCD("Card Blocked");
            cmdLCD(0xC0);
            strLCD("Use CASH");
            delay_s(5);
                cmdLCD(0x01);
            cmdLCD(0x80);
            strLCD("Switch To");
            cmdLCD(0xC0);
            strLCD("CASH Mode");
            delay_s(5);
           //CLEAR UART BUFFER
           memset(buf,0,sizeof(buf));
           uart1_ready = 0;
           // START CASH PAYMENT
          cash_payment_frontend();
          return;
        }
      }
    }
}