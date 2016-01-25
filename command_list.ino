/*
Serial messages (byte 0 - 255):
 * 0 - turn on button 1 light
 * 1 - turn off button 1 light
 * 2 - turn on button 2 light
 * 3 - turn off button 2 light
 * 4 - turn on rfid 1 tag 1 light
 * 5 - turn on rfid 1 tag 2 light
 * 6 - turn on rfid 1 tag 3 light
 * 7 - turn on rfid 1 tag 4 light
 * 8 - turn on rfid 1 circle led waiting mode
 * 9 - turn off rfid 1 circle led  
 * a - turn on rfid 2 tag 1 light
 * b - turn on rfid 2 tag 2 light
 * c - turn on rfid 2 tag 3 light
 * d - turn on rfid 2 tag 4 light
 * e - turn on rfid 2 circle led waiting mode
 * f - turn off rfid 2 circle led 
 * */

void process_command(int incoming) {

    switch(incoming) {
        //button1
        case('0'): Strip1.ColorSet( Strip1.whiteColor ); break; 
        case('1'): Strip1.ColorSet( Strip1.noColor ); break;
        
        //button2
        case('2'): Strip2.ColorSet( Strip1.whiteColor ); break;
        case('3'): Strip2.ColorSet( Strip1.noColor ); break;
        
        //ring1
        case('4'): Strip3.ColorSet( Strip1.pinkColor); break;
        case('5'): Strip3.ColorSet( Strip1.greenColor); break;
        case('6'): Strip3.ColorSet( Strip1.yellowColor); break;
        case('7'): Strip3.ColorSet( Strip1.blueColor); break;
        case('8'): Strip3.Scanner( Strip1.redColor, 50, 1); break;
        case('9'): Strip3.ColorSet( Strip1.noColor); break; 
        
        //ring2
        case('a'): Strip4.ColorSet( Strip1.pinkColor); break;
        case('b'): Strip4.ColorSet( Strip1.greenColor); break;
        case('c'): Strip4.ColorSet( Strip1.yellowColor); break;
        case('d'): Strip4.ColorSet( Strip1.blueColor); break;
        case('e'): Strip4.Scanner( Strip1.redColor, 50, 1); break;
        case('f'): Strip4.ColorSet( Strip1.noColor); break;       
  }
 }
  
