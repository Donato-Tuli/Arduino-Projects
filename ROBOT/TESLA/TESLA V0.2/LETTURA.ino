void LETTURA() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.println("Partenza:");
  display.setCursor(55, 0);
  display.println(EEPROM.read(0));

  display.setCursor(0, 8);
  display.println("CL1:");
  display.setCursor(25, 8);
  display.println(EEPROM.read(1));

  display.setCursor(50, 8);
  display.println("R:");
  display.setCursor(60, 8);
  if ((EEPROM.read(2)) % 2 == 0) {
    display.println("DES");
  }
  else {
    display.println("SIN");
  }

  display.setCursor(95, 8);
  display.println("a:");
  display.setCursor(110, 8);
  display.println(EEPROM.read(3));

  display.setCursor(0, 16);
  display.println("CL2:");
  display.setCursor(25, 16);
  display.println(EEPROM.read(4));

  display.setCursor(50, 16);
  display.println("R:");
  display.setCursor(60, 16);
  if ((EEPROM.read(5)) % 2 == 0) {
    display.println("DES");
  }
  else {
    display.println("SIN");
  }

  display.setCursor(95, 16);
  display.println("a:");
  display.setCursor(110, 16);
  display.println(EEPROM.read(6));

#ifdef CONTALUCI3
  display.setCursor(0, 24);
  display.println("CL3:");
  display.setCursor(25, 24);
  display.println(EEPROM.read(7));

  display.setCursor(50, 24);
  display.println("R:");
  display.setCursor(60, 24);
  if ((EEPROM.read(8)) % 2 == 0) {
    display.println("DES");
  }
  else {
    display.println("SIN");
  }

  display.setCursor(95, 24);
  display.println("a:");
  display.setCursor(110, 24);
  display.println(EEPROM.read(9));
#endif
  display.display();

}

