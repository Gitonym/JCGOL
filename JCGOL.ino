#include <Arduboy2.h>

Arduboy2 arduboy;

const unsigned char menu[] PROGMEM = {
  0xef, 0xa5, 0xad, 0xe7, 0x00, 0xef, 0xab, 0xab, 0xe9, 0x00, 0xeb, 0x4b, 0x8d, 0xed, 0x00, 0xef,
0x28, 0x28, 0xcf, 0x00, 0xef, 0x21, 0x27, 0xef, 0x00, 0xef, 0x2b, 0xeb, 0xe9, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xbd, 0xa4, 0xa5, 0xa4, 0x00, 0xbd, 0xa0, 0xa0, 0x21, 0x00, 0xbd,
0xac, 0xac, 0x25, 0x80, 0xbd, 0x95, 0x15, 0x3c, 0x00, 0x3d, 0x15, 0x35, 0x1d, 0x00, 0x01, 0x00,
0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb7, 0xb5, 0xd5, 0xd4, 0x00, 0xf7,
0x54, 0x54, 0x73, 0x00, 0xf4, 0xb7, 0xb4, 0x90, 0x00, 0xf7, 0xb0, 0xb0, 0x90, 0x00, 0xf0, 0x90,
0x90, 0x60, 0x00, 0x60, 0xf0, 0x60, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd6,
0xd6, 0x5a, 0x5a, 0x00, 0xde, 0x50, 0x50, 0x50, 0x00, 0xde, 0x52, 0x52, 0xde, 0x00, 0xde, 0xd0,
0xdc, 0x5e, 0x00, 0xde, 0xc2, 0xce, 0x5e, 0x00, 0xde, 0x92, 0x12, 0xde, 0x00, 0xde, 0x12, 0x92,
0xcc, 0x00, 0xde, 0x56, 0x56, 0xd2, 0x00, 0xc0, 0x40, 0x40, 0xc0, 0x00, 0xc0, 0x40, 0xc0, 0x00,
0x80, 0xc0, 0x80, 0xfc, 0x6a, 0x6a, 0xab, 0xab, 0x08, 0xeb, 0x0a, 0x0a, 0xea, 0x08, 0xeb, 0xa9,
0xab, 0xe9, 0x08, 0xeb, 0x0a, 0x0a, 0xea, 0x08, 0x2b, 0xea, 0x2a, 0x0a, 0xe8, 0x0b, 0x08, 0xe9,
0x0b, 0x28, 0xeb, 0x2a, 0x0b, 0xeb, 0x48, 0x8b, 0xe9, 0x0b, 0xe9, 0x28, 0xab, 0xa9, 0x09, 0x0b,
0x08, 0x0b, 0x09, 0x09, 0x08, 0x09, 0x0b, 0x09, 0x09, 0x01, 0x79, 0x49, 0x49, 0x78, 0x01, 0x01,
0x01, 0x49, 0x78, 0x41, 0x00, 0x01, 0x68, 0x68, 0x58, 0x59, 0x01, 0x00, 0x48, 0x59, 0x59, 0x79,
0x00, 0x00, 0x39, 0x21, 0x20, 0x78, 0x01, 0x01, 0x39, 0x68, 0x69, 0x68, 0x00, 0x01, 0x78, 0x51,
0x51, 0x71, 0x01, 0x00, 0x08, 0x08, 0x08, 0x78, 0x00, 0x00, 0x78, 0x68, 0x68, 0x78, 0x78, 0x58,
0x58, 0x70, 0x00, 0x48, 0x78, 0x48, 0x00, 0x78, 0x28, 0x68, 0x38, 0x00, 0x08, 0x78, 0x08, 0x00,
0x78, 0x20, 0x20, 0x78, 0x00, 0x48, 0x78, 0x48, 0x00, 0x78, 0x18, 0x60, 0x78, 0x00, 0x78, 0x48,
0x68, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x1e, 0x12, 0x12, 0x1e, 0x00, 0x00, 0x00, 0x12, 0x1e, 0x10, 0x00, 0x00,
0x1a, 0x1a, 0x16, 0x16, 0x00, 0x00, 0x12, 0x16, 0x16, 0x1e, 0x00, 0x00, 0x0e, 0x08, 0x08, 0x1e,
0x00, 0x00, 0x0e, 0x1a, 0x1a, 0x1a, 0x00, 0x00, 0x1e, 0x14, 0x14, 0x1c, 0x00, 0x00, 0x02, 0x02,
0x02, 0x1e, 0x00, 0x00, 0x1e, 0x1a, 0x1a, 0x1e, 
};

bool cellState[512];
byte screen = 0;
byte frameRate = 10;
byte selectorHeight = 0;
bool wrapScreen = true;
byte cursorX = 0;
byte cursorY = 0;
bool birthRule[9] = {false, false, false, true, false, false, false, false, false};
bool surviveRule[9] = {false, false, true, true, false, false, false, false, false};
byte selectorX = 0;

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
    
    arduboy.drawBitmap(5, 0, menu, 53, 64, WHITE);
    arduboy.setCursor(35, 16);
    arduboy.print(frameRate);

    arduboy.setCursor(59, 26);
    if (wrapScreen) {
      arduboy.print("Y");
    } else {
      arduboy.print("N");
    }

    for (int i = 0; i < 9; i++) {
      if (surviveRule[i]) {
        arduboy.drawFastHLine((i * 6) + 5, 42, 6, WHITE);
        arduboy.drawFastHLine((i * 6) + 5, 47, 6, WHITE);
      }
      if (birthRule[i]) {
        arduboy.drawFastHLine((i * 6) + 5, 56, 6, WHITE);
        arduboy.drawFastHLine((i * 6) + 5, 61, 6, WHITE);
      }
    }

    if (arduboy.justPressed(DOWN_BUTTON)) {
      selectorHeight = (selectorHeight + 1) % 9;
    }

    if (arduboy.justPressed(UP_BUTTON)) {
      selectorHeight = (((selectorHeight - 1) % 9) + 9) % 9;
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

    if (selectorHeight == 6) {
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

    if (selectorHeight < 7) {
      arduboy.drawRect(0, (selectorHeight * 5) + 1, 2, 2, WHITE);
    }

    if (selectorHeight == 7) {
      arduboy.drawFastHLine((selectorX * 6) + 6, 49, 4, WHITE);
      if (arduboy.justPressed(RIGHT_BUTTON)) {
        selectorX = (((selectorX + 1) % 9) + 9) % 9;
      }
      if (arduboy.justPressed(LEFT_BUTTON)) {
        selectorX = (((selectorX - 1) % 9) + 9) % 9;
      }
      if (arduboy.justPressed(A_BUTTON)) {
        surviveRule[selectorX] = !(surviveRule[selectorX]);
      }
    }

    if (selectorHeight == 8) {
      arduboy.drawFastHLine((selectorX * 6) + 6, 63, 4, WHITE);
      if (arduboy.justPressed(RIGHT_BUTTON)) {
        selectorX = (((selectorX + 1) % 9) + 9) % 9;
      }
      if (arduboy.justPressed(LEFT_BUTTON)) {
        selectorX = (((selectorX - 1) % 9) + 9) % 9;
      }
      if (arduboy.justPressed(A_BUTTON)) {
        birthRule[selectorX] = !(birthRule[selectorX]);
      }
    }
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
