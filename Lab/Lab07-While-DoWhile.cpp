/*
    จงเขียนโปรแกรมทายตัวเลขซึ่งทำงานดังนี้
    - ตอนเริ่มเกมผู้เล่นจะมีคะแนนเต็ม 100
    - โปรแกรมจะสุ่มตัวเลขที่มีค่าตั้งแต่ 1 ถึง 100
    - ให้ผู้เล่นทายว่าตัวเลขที่โปรแกรมสุ่มมามีค่าเป็นเท่าใด
        - หากทายผิด โปรแกรมจะลบคะแนนของผู้เล่นไป 10 หน่วย พร้อมแจ้งคะแนนปัจจุบันให้ผู้เล่นทราบด้วย
        - หากทายผิด โปรแกรมจะต้องบอกใบ้ว่าคำตอบที่ถูกมีค่า "มากกว่า" หรือ "น้อยกว่า" ตัวเลขที่ผู้ใช้ทาย
        - หากทายผิด ให้โปรแกรมรอรับตัวเลขถัดไปได้เลย
        - หากทายถูก ให้โปรแกรมแสดงความยินดีกับผู้ใช้ พร้อมแจ้งคะแนนปัจจุบันให้กับผู้เช่น
        - เมื่อเล่นเสร็จโปรแกรมรอรับคำสั่งจากผู้ใช้ หากผู้ใช้กรอกเลข 1 จะเข้าสู่โหมดการเล่นเกมใหม่อีกครั้ง หากกด -1 ให้หยุดการทำงานของโปรแกรม

    หมายเหตุ : การสุ่มตัวเลขจะใช้คำสั่ง rand() ที่อยู่ใน stdlib.h หากต้องการสุ่มตัวเลข 0 ถึง 100 ต้องใช้คำสั่งดังนี้
        rand() % 100 + 1
    หมายเหตุ : หากต้องการสุ่มตัวเลขที่เปลี่ยนแปลงตามเวลา ต้องใช้คำสั่ง srand( time( NULL ) ) ในตอนต้นของโปรแกรมด้วย

    Test case & Output:
        Do you want to play game (1=play,-1=exit) :
            1
        (Score=100)
        Guess the winning number (1-100) :
            20
        Sorry, the winning number is HIGHER than 20. (Score=90)
        Guess the winning number (21-100) :
            50
        Sorry, the winning number is LOWER than 50. (Score=80)
        Guess the winning number (21-49) :
            42
        That is correct! The winning number is 42.
        Score this game: 80

        Do you want to play game (1=play,-1=exit) :
            1
        (Score=100)
        Guess the winning number (1-100) : 
            75
        Sorry, the winning number is LOWER than 75. (Score=90)
        Guess the winning number (1-74) : 
            20
        Sorry, the winning number is LOWER than 20. (Score=80)
        Guess the winning number (1-19) : 
            2
        Sorry, the winning number is HIGHER than 2. (Score=70)
        Guess the winning number (3-19) : 
            15
        That is correct! The winning number is 15.
        Score this game: 70

        Do you want to play game (1=play,-1=exit) :
            -1
*/

#include <stdio.h>
#include<stdlib.h>
#include <ctime>

int main() {

    srand( time ( NULL ) ) ;
    int score = 100 ;
    int play, inputuser ;
    int randomNumber = rand() % 100 + 1 ;
    int i = 0 ;
    int min = 0, max = 100 ;
    int allscore = score ;

    do
    {
        printf( "Do you want to play game (1=play,-1=exit) :\n" ) ;
        scanf( "%d", &play ) ;

        if ( play != 1 ) {
            break ;
        }
        min = 0 ;
        max = 100 ;
        score = 100 ;
        while ( play = 1 ) {// play
        
        printf( "Guess the winning number (%d-%d) :\n",min ,max ) ;
        scanf( "%d", &inputuser ) ;

        if ( inputuser == randomNumber ) { // win
            printf( "That is correct! The winning number is %d.\n", randomNumber ) ;
            printf( "Score this game: %d\n", allscore ) ;
            break ;
        }// end while win
        
        if ( inputuser != randomNumber ) { // worng
            allscore -= 10 ;// ถ้าตอบผิด score จะ -10 ก่อน

            if ( randomNumber > inputuser ) { // wrong. but high than randomber
                printf( "Sorry, the winning number is HIGHER than %d. (Score=%d)\n", inputuser, allscore ) ;
                if ( min <= inputuser ) {
                    min = inputuser + 1 ;
                }// ถ้า ตัวเลขที่ใส่มา น้อยกว่า min จะให้แสดง min เหมือนเดิม แต่ถ้ามากกว่า จะแสดงค่าใหม่แทน
            }// end wrong higt

            if ( randomNumber <= inputuser ) { // wrong. but low than randomnumber
                printf( "Sorry, the winning number is LOWWER than %d. (Score=%d)\n", inputuser, allscore ) ;
                if (max > inputuser) {
                    max = inputuser - 1 ;
                }// ถ้า ตัวเลขที่ใส่มา น้อยกว่า max จะให้แสดง max เหมือนเดิม แต่ถ้ามากกว่า จะแสดงค่าใหม่แทน
            }// end wrong low
        }// end wrong ของแท้
        
        if ( allscore == 0 ) { // check score
            printf( "Game Over" ) ;
            break ;
        }// end if check score 

    }//end play
        
    } while ( play = 1 ) ;
    
    return 0 ;
}//end main function