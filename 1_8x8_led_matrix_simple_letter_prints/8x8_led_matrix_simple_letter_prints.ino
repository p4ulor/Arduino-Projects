byte ALL[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte EX[] = {B00000000,B00010000,B00010000,B00010000,B00010000,B00000000,B00010000,B00000000}; //exclamation point
byte A[] = {  B00000000,B00111100,B01100110,B01100110,B01111110,B01100110,B01100110,B01100110};
byte B[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
byte C[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
byte D[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
byte E[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
byte F[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
byte G[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
byte H[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
byte I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
byte J[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
byte K[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
byte L[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
byte M[] = {B00000000,B00000000,B01000100,B10101010,B10010010,B10000010,B10000010,B00000000};
byte N[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
byte O[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
byte P[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
byte Q[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
byte R[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
byte S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
byte T[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte U[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
byte V[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
byte W[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
byte X[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
byte Y[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte Z[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};
byte RESET[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

void setup() {
	for (byte i = 2; i <= 13; i++){
		pinMode(i, OUTPUT);
	}
		
	pinMode(A0, OUTPUT);
	pinMode(A1, OUTPUT);
	pinMode(A2, OUTPUT);
	pinMode(A3, OUTPUT);
}

float timeCount = 0;

void loop() { //its like the main function
	timeCount += 1;

	if (timeCount <  2) {
		drawScreen(ALL);
	} else if (timeCount <  1000) {
		drawScreen(B);
	} else if (timeCount <  2000) {
		drawScreen(C);
	} else if (timeCount <  3000) {
		drawScreen(D);
	} else if (timeCount <  4000) {
		drawScreen(G);
	} else if (timeCount <  5000) {
		drawScreen(H);
	} else if (timeCount <  6000) {
		drawScreen(O);
	} else if (timeCount <  7000) {
		drawScreen(Z);
	} else if (timeCount <  8000) {
		drawScreen(ALL);
	} else {
		// back to the start
		timeCount = 0;
	}
}

const byte rows[] = {2, 3, 4, 5, 6, 7, 8, 9};
const byte col[] = {10, 11, 12, 13, A0, A1, A2, A3};

void drawScreen(byte buffer2[]) {
	// Turn on each row in series
	for (byte i = 0; i < 8; i++) {       // count next row 
		digitalWrite(rows[i], HIGH);       // initiate whole row
		digitalWrite(col[0], HIGH);
		digitalWrite(col[1], HIGH);
		digitalWrite(col[2], HIGH);
		digitalWrite(col[3], HIGH);
		digitalWrite(col[4], HIGH);
		digitalWrite(col[5], HIGH);
		digitalWrite(col[6], HIGH);
		digitalWrite(col[7], HIGH);

		for (byte a = 0; a < 8; a++) {     // count next row
			digitalWrite(col[a], !((buffer2[i] << a) & 0x80));
		}
		
		digitalWrite(rows[i], LOW);   
	}
}