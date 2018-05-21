#include <Tinyfont.h>
#include <Arduboy2.h>

Arduboy2 arduboy;
Tinyfont tinyfont = Tinyfont(arduboy.sBuffer, Arduboy2::width(), Arduboy2::height());

bool cellState[512];
byte screen = 0;
byte frameRate = 10;
byte selectorHeight = 0;
bool wrapScreen = true;
byte cursorX = 0;
byte cursorY = 0;
bool birthRule[9] = {false, false, false, true, false, false, false, false, false};
bool surviveRule[9] = {false, false, true, true, false, false, false, false, false};

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(frameRate);
  arduboy.initRandomSeed();
  arduboy.clear();
  initCells();
  drawCells();
  arduboy.display();
}

void loop() {
  if (!(arduboy.nextFrame())) {
    return;
  }
  
  arduboy.pollButtons();
  
  if (screen == 0) {
    
    if (arduboy.justPressed(B_BUTTON)) {
      screen += 1;
      selectorHeight = 0;
      arduboy.setFrameRate(30);
    }

    iterateCells();
    eraseEdges();
    arduboy.clear();
    drawCells();
    if (arduboy.justPressed(A_BUTTON)) {
      arduboy.setFrameRate(30);
      screen += 3;
    }
  } else if (screen == 1) {
    drawMenu();
  } else if (screen == 2) {
    arduboy.clear();
    drawCells();
    drawCursor();
    moveCursor();
    toggleCell();

    if (arduboy.justPressed(B_BUTTON)) {
      screen -= 1;
    }
  } else if (screen == 3) {
    if (arduboy.justPressed(A_BUTTON)) {
    iterateCells();
    eraseEdges();
    }
    arduboy.clear();
    drawCells();
    if (arduboy.justPressed(B_BUTTON)) {
      arduboy.setFrameRate(frameRate);
      drawCells();
      arduboy.display();
      screen -= 3;
    }
  }
  arduboy.display();
}

void drawCells() {
  for (int i = 0; i < 512; i++) {
    if (cellState[i]) {
      arduboy.fillRect((i % 32) * 4, ((i - (i % 32)) / 32) * 4, 3, 3, WHITE);
    }
  }
}

void initCells() {
  for (int i = 0; i < 512; i++) {
    cellState[i] = random(0 ,2);
  }
}

void iterateCells() {
  byte alive;
  byte x = 0;
  byte y = 0;
  for (int i = 0; i < 512; i++) {
    alive = 0;
    x = (i % 32) * 4;
    y = ((i - (i % 32)) / 32) * 4;

    if (arduboy.getPixel((((x - 4) % 128) + 128) % 128, (((y - 4) % 64) + 64) % 64)) {
      alive++;
    }
    if (arduboy.getPixel((((x) % 128) + 128) % 128, (((y - 4) % 64) + 64) % 64)) {
      alive++;
    }
    if (arduboy.getPixel((((x + 4) % 128) + 128) % 128, (((y - 4) % 64) + 64) % 64)) {
      alive++;
    }
    if (arduboy.getPixel((((x - 4) % 128) + 128) % 128, (((y) % 64) + 64) % 64)) {
      alive++;
    }
    if (arduboy.getPixel((((x + 4) % 128) + 128) % 128, (((y) % 64) + 64) % 64)) {
      alive++;
    }
    if (arduboy.getPixel((((x - 4) % 128) + 128) % 128, (((y + 4) % 64) + 64) % 64)) {
      alive++;
    }
    if (arduboy.getPixel((((x) % 128) + 128) % 128, (((y + 4) % 64) + 64) % 64)) {
      alive++;
    }
    if (arduboy.getPixel((((x + 4) % 128) + 128) % 128, (((y + 4) % 64) + 64) % 64)) {
      alive++;
    }

    if (arduboy.getPixel(x ,y)) {
      if ((surviveRule[0] and alive == 0) or (surviveRule[1] and alive == 1) or (surviveRule[2] and alive == 2) or (surviveRule[3] and alive == 3) or (surviveRule[4] and alive == 4) or (surviveRule[5] and alive == 5) or (surviveRule[6] and alive == 6) or (surviveRule[7] and alive == 7) or (surviveRule[8] and alive == 8)) {
        cellState[i] = true;
      } else {
        cellState[i] = false;
      }
    } else {
      if ((birthRule[0] and alive == 0) or (birthRule[1] and alive == 1) or (birthRule[2] and alive == 2) or (birthRule[3] and alive == 3) or (birthRule[4] and alive == 4) or (birthRule[5] and alive == 5) or (birthRule[6] and alive == 6) or (birthRule[7] and alive == 7) or (birthRule[8] and alive == 8)) {
        cellState[i] = true;
      } else {
        cellState[i] = false;
      }
    }
  }
}

void drawMenu() {

    arduboy.clear();
    
    tinyfont.setCursor(3, 0);
    tinyfont.print("RESUME");
    tinyfont.setCursor(3, 5);
    tinyfont.print("RANDOM");
    tinyfont.setCursor(3, 10);
    tinyfont.print("CLEAR");
    tinyfont.setCursor(3, 15);
    tinyfont.print("EDIT");
    tinyfont.setCursor(3, 20);
    tinyfont.print("SPEED");
    tinyfont.setCursor(90, 20);
    tinyfont.print(frameRate);
    arduboy.fillTriangle(88, 19, 88, 23, 84, 21, WHITE);
    arduboy.fillTriangle(105, 19, 105, 23, 109, 21, WHITE);
    tinyfont.setCursor(3, 25);
    tinyfont.print("RESUME SLOW");
    tinyfont.setCursor(3, 30);
    tinyfont.print("RULES");
    tinyfont.setCursor(3, 35);
    tinyfont.print("WRAP SCREEN");
    tinyfont.setCursor(88, 35);
    if (wrapScreen) {
      tinyfont.print("YES");
    } else {
      tinyfont.print("NO");
    }

    if (arduboy.justPressed(DOWN_BUTTON)) {
      selectorHeight = (selectorHeight + 1) % 8;
    }

    if (arduboy.justPressed(UP_BUTTON)) {
      selectorHeight = (((selectorHeight - 1) % 8) + 8) % 8;
    }

    if (selectorHeight == 0) {
      if (arduboy.justPressed(A_BUTTON)) {
        screen -= 1;
        arduboy.setFrameRate(frameRate);
        arduboy.clear();
        drawCells();
        arduboy.display();
      }
    }

    if (selectorHeight == 1) {
      if (arduboy.justPressed(A_BUTTON)) {
        screen -= 1;
        arduboy.setFrameRate(frameRate);
        arduboy.clear();
        initCells();
        drawCells();
        arduboy.display();
      }
    }

    if (selectorHeight == 2) {
      if (arduboy.justPressed(A_BUTTON)) {
        screen -= 1;
        arduboy.setFrameRate(frameRate);
        for (int i = 0; i < 512; i++) {
          cellState[i] = false;
        }
        arduboy.clear();
        arduboy.display();
      }
    }

    if (selectorHeight == 4) {
      if (arduboy.justPressed(RIGHT_BUTTON)) {
        frameRate = (frameRate + 1) % 121;
        arduboy.delayShort(250);
      }
      if (arduboy.pressed(RIGHT_BUTTON) and (!(arduboy.justPressed(RIGHT_BUTTON)))) {
        frameRate = (frameRate + 1) % 121;
        arduboy.delayShort(75);
      }
      if (arduboy.justPressed(LEFT_BUTTON)) {
        frameRate = (((frameRate - 1) % 121) + 121) % 121;
        arduboy.delayShort(250);
      }
      if (arduboy.pressed(LEFT_BUTTON) and (!(arduboy.justPressed(RIGHT_BUTTON)))) {
        frameRate = (((frameRate - 1) % 121) + 121) % 121;
        arduboy.delayShort(75);
      }
    }

    if (selectorHeight == 7) {
      if (arduboy.justPressed(A_BUTTON) or arduboy.justPressed(RIGHT_BUTTON) or arduboy.justPressed(LEFT_BUTTON)) {
        wrapScreen = !(wrapScreen);
      }
    }

    if (selectorHeight == 3) {
      if (arduboy.justPressed(A_BUTTON)) {
        screen += 1;
      }
    }

    if (selectorHeight == 5) {
      if (arduboy.justPressed(A_BUTTON)) {
        arduboy.setFrameRate(30);
        screen += 2;
      }
    }

    arduboy.drawRect(0, (selectorHeight * 5) + 1, 2, 2, WHITE);
}

void eraseEdges() {
  if (!(wrapScreen)) {
    for (int x = 0; x < 32; x += 1) {
      cellState[x] = false;
      cellState[x + 15 * 32] = false;
    }
    for (int y = 0; y < 16; y += 1) {
      cellState[y * 32] = false;
      cellState[31 + y * 32] = false;
    }
  }
}

void drawCursor() {
  arduboy.drawRect(cursorX - 1, cursorY - 1, 5, 5, WHITE);
}

void moveCursor() {
  if (arduboy.justPressed(RIGHT_BUTTON)) {
    cursorX = (((cursorX + 4) % 128) + 128) % 128;
  }
  if (arduboy.justPressed(LEFT_BUTTON)) {
    cursorX = (((cursorX - 4) % 128) + 128) % 128;
  }
  if (arduboy.justPressed(UP_BUTTON)) {
    cursorY = (((cursorY - 4) % 64) + 64) % 64;
  }
  if (arduboy.justPressed(DOWN_BUTTON)) {
    cursorY = (((cursorY + 4) % 64) + 64) % 64;
  }
}

void toggleCell() {
  if (arduboy.justPressed(A_BUTTON)) {
    cellState[(cursorX / 4) + (cursorY / 4) * 32] = !(cellState[(cursorX / 4) + (cursorY / 4) * 32]);
  }
}

