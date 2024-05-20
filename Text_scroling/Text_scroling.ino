#define ROW_COUNT      8
#define COLUMN_COUNT   8
#define TEXT_LENGTH    56
#define SCROLL_SPEED   5

// Define row pins
const int rowPins[ROW_COUNT] = {8, 13, 0, 11, 7, 1, 6, 3};
// Define column pins
const int columnPins[COLUMN_COUNT] = {12, 5, 4, 9, 2, 10, 14, 15};

int position = 0;
int buttonState = 0;
int lastButtonState = 0;
int state = 0;

  int Hello_World [8] [TEXT_LENGTH] ={
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
  {0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,0},
  {0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1,0,0},
  {0,1,1,1,1,1,0,1,1,1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0},
  {0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,1,0,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0},
  {0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0},
  {0,1,0,0,0,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,0,0,0,1,0,0,0,0,1,0,0,1,1,1,0,0,1,0,0,1,0,1,1,1,1,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

void setup() {
  for (int i = 0; i < ROW_COUNT; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }

  for (int i = 0; i < COLUMN_COUNT; i++) {
    pinMode(columnPins[i], OUTPUT);
    digitalWrite(columnPins[i], LOW);
  }
  pinMode(24, INPUT_PULLUP);
}

void selectRow(int row) {
  for (int i = 0; i < ROW_COUNT; i++) {
    digitalWrite(rowPins[i], i + 1 == row ? LOW : HIGH);
  }
}

void setLEDInActiveRow(int column, int state) {
  digitalWrite(columnPins[column - 1], state);
}

void disPlayWithScroll() {
  for (int x = 0; x < 5; x++) {
    for (int j = 0; j < ROW_COUNT; j++) {
      selectRow(j + 1);
      for (int i = 0; i < COLUMN_COUNT; i++) {
        setLEDInActiveRow(i + 1, Hello_World[j][(i + position) - abs((i + position) / (TEXT_LENGTH)) * (TEXT_LENGTH)]);
      }
      delay(SCROLL_SPEED);
    }
  }
  position++;
}
void loop() {
  disPlayWithScroll();
}
