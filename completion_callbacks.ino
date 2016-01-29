// -----------------------------
// Completion callback routines 
// -----------------------------

void Strip1Complete() { //button1
  if (DEBUG)  Serial.println("strip 1 complete"); 
}

void Strip2Complete() { //button2
  if (DEBUG) Serial.println("strip 2 complete"); 
}

void Strip3Complete() { //ring1
  if (DEBUG)  Serial.println("strip 3 complete");
}

void Strip4Complete() { //ring2
  if (DEBUG)  Serial.println("strip 4 complete");
}

void Strip5Complete() { //panel1
  if (DEBUG)  Serial.println("strip 5 complete");
  Strip5.ActivePattern = NONE; //prevent the fadeUpdate
}

void Strip6Complete() { //panel2
  if (DEBUG) Serial.println("strip 6 complete");
  Strip6.ActivePattern = NONE; //prevent the fadeUpdate
}

void Strip7Complete() { //panel3
  if (DEBUG)  Serial.println("strip 7 complete");
  Strip7.ActivePattern = NONE; //prevent the fadeUpdate
}

void Strip8Complete() { //display1
  if (DEBUG)  Serial.println("strip 8 complete");
  Strip8.ActivePattern = NONE; //prevent the fadeUpdate
}

void Strip9Complete() { //display2
  if (DEBUG)  Serial.println("strip 9 complete");
  Strip9.ActivePattern = NONE; //prevent the fadeUpdate
}

void Strip10Complete() { //display3
  if (DEBUG) Serial.println("strip 10 complete");
  Strip10.ActivePattern = NONE; //prevent the fadeUpdate
}

void Strip11Complete() { //map1
  if (DEBUG)  Serial.println("strip 11 complete");
  Strip11.ActivePattern = NONE; //prevent the fadeUpdate
}

void Strip12Complete() { //map2
  if (DEBUG)  Serial.println("strip 12 complete");

    //pulsing animation
      if (Strip12.Direction == FORWARD) 
    {
        Strip12.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 0); //change direction
        
    } else 
    {
        Strip12.Fade( Strip1.whiteColor, 128, FADE_INTERVAL, 1); //change direction
    }
}
