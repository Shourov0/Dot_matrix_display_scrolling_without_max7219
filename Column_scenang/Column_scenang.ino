const unsigned int ColumnPins[] = {8,13,0,11,7,1,6,3};// Cathode pins
const unsigned int RowPins[]    = {12,5,4,9,2,10,14,15};// Anode pins

// Define the matrix pattern for letter 'A'
const byte letter_A[8] = {
  B00000000,
  B11111100,
  B00010010,
  B00010001,
  B00010001,
  B00010010,
  B11111100,
  B00000000,
};


void setup() {
  // Initialize column and row pins
  for (int i = 0; i < 8; i++) {
    pinMode(ColumnPins[i], OUTPUT);
    pinMode(RowPins[i], OUTPUT);
  }
}

void loop() {
//  int potValue = analogRead(A0);
//  
//  // Map the potentiometer value to delay time range (2ms to 500ms)
//  int delayTime = map(potValue, 0, 1023, 0, 500);
  
  // Display the letter 'A' by column scanning
  for (int col = 0; col < 8; col++) {
    // Turn off all rows
    for (int i = 0; i < 8; i++) {
    digitalWrite(ColumnPins[i], HIGH);
    }
    
    // Turn on the current row
    digitalWrite(ColumnPins[col], LOW);
    
    // Activate the LEDs in the current row according to the letter pattern
    for (int row = 0; row < 8; row++) {
    digitalWrite(RowPins[row], bitRead(letter_A[col], row)); 
    }
    
    // Delay to display the column
    delay(2); // Adjust this delay to control the scanning speed
  }
}
