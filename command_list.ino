/*
 * Button x 2, Ring x 2, Display x 3, Panel x 3, Map x 2 
 *              
 * 0 - turn on button 1 
 * 1 - turn off button 1 
 * 2 - turn on button 2 
 * 3 - turn off button 2 
 * 4 - ring 1 tag 1 
 * 5 - ring 1 tag 2 
 * 6 - ring 1 tag 3 
 * 7 - ring 1 tag 4 
 * 8 - ring 1 waiting mode
 * 9 - turn off ring 1  
 * a - ring 2 tag 1 
 * b - ring 2 tag 2 
 * c - ring 2 tag 3 
 * d - ring 2 tag 4 
 * e - ring 2 waiting mode
 * f - turn off ring 2  
 * g- turn on panel 1
 * h - turn off panel 1
 * i - turn on panel 2
 * j - turn off panel 2
 * k - turn on panel 3
 * l - turn off panel 3
 * m - turn on display 1 
 * n - turn off display 1
 * o - turn on display 2
 * p - turn off display 2
 * q - turn on display 3
 * r - turn off display 3
 * s - turn on map 1
 * t - turn off map 1
 * u - turn on map 2
 * v - turn off map 2
 * */

void process_command(int incoming) {

    switch(incoming) {
        //button1
        case('0'): Strip1.ColorSet( Strip1.white50Color ); break; 
        case('1'): Strip1.TurnOff(); break;
        
        //button2
        case('2'): Strip2.ColorSet( Strip1.white50Color ); break;
        case('3'): Strip2.TurnOff(); break;
        
        //ring1
        case('4'): Strip3.ColorSet( Strip1.pinkColor); break;
        case('5'): Strip3.ColorSet( Strip1.greenColor); break;
        case('6'): Strip3.ColorSet( Strip1.yellowColor); break;
        case('7'): Strip3.ColorSet( Strip1.blueColor); break;
        case('8'): Strip3.Scanner( Strip1.redColor, 50, 1); break;
        case('9'): Strip3.TurnOff(); break; 
        
        //ring2
        case('a'): Strip4.ColorSet( Strip1.pinkColor); break;
        case('b'): Strip4.ColorSet( Strip1.greenColor); break;
        case('c'): Strip4.ColorSet( Strip1.yellowColor); break;
        case('d'): Strip4.ColorSet( Strip1.blueColor); break;
        case('e'): Strip4.Scanner( Strip1.redColor, 50, 1); break;
        case('f'): Strip4.TurnOff(); break;   

        //panel1
        case('g'): Strip5.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 1); break;   
        case('h'): Strip5.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 0); break; 

        //panel2
        case('i'): Strip6.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 1); break;   
        case('j'): Strip6.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 0); break; 

        //panel3
        case('k'): Strip7.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 1); break;   
        case('l'): Strip7.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 0); break; 

        //display1
        case('m'): Strip8.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 1); break;   
        case('n'): Strip8.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 0); break; 

        //display2
        case('o'): Strip9.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 1); break;   
        case('p'): Strip9.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 0); break; 

        //display3
        case('q'): Strip10.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 1); break;   
        case('r'): Strip10.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 0); break; 

        //map1
        case('s'): Strip11.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 1); break;   
        case('t'): Strip11.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 0); break; 

        //map2 - slow pulsing single pixel LEDs
        case('u'): Strip12.Fade( Strip1.white50Color, 128, FADE_INTERVAL, 1); break;   
        case('v'): Strip12.TurnOff(); break; 
            
  }
 }
  
