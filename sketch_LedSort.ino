#include <FastLED.h>
# define Num_Leds 59
# define DATA_pin 7
#define ARRAY_SIZE(array) ((sizeof(array))/(sizeof(array[0])))

CRGB leds[Num_Leds];
int red = 1;
int blue = 2;
int green = 3;
int darkViolet = 4;
int gold = 5;
int forestGreen = 6;
int lavender = 7;
int numsToSort[Num_Leds];
int numsToSortLength = ARRAY_SIZE(numsToSort);

void setup() {
  randomSeed(analogRead(A0));
  FastLED.addLeds<NEOPIXEL, DATA_pin>(leds, Num_Leds);
  Serial.begin(9600);
  genRandomNum(1, 7);
  trunOffLedStrip();
  delay(1000);
}

void loop() {
  //printArr();
  colourLedStrip();
  //delay(500);
  //boulbeSort();
  //selectionSort();
  insertionSort();
  //colourLedStrip();
  //printArr();
  //colourLedStrip();
  //delay(500);
}

void genRandomNum(int minimum, int maximum){
  for(int i = 0; i <= numsToSortLength; i++){
    int ran = random(minimum,(maximum + 1));
    numsToSort[i] = ran;
  }
}

void trunOffLedStrip(){
  for(int i = 0; i < numsToSortLength; i++){
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}

void colourLedStrip(){
  for(int i = 0; i < numsToSortLength; i++){
    assignColour(i, 100);
  }
}

void assignColour(int index, int colourDelay){
  if(numsToSort[index] == red){
      leds[index] = CRGB::Red;
    }
    else if(numsToSort[index] == green){
      leds[index] = CRGB::Green;
    }
    else if(numsToSort[index] == blue){
      leds[index] = CRGB::Blue;
    }
    else if(numsToSort[index] == darkViolet){
      leds[index] = CRGB::DarkViolet;
    }
    else if(numsToSort[index] == gold){
      leds[index] = CRGB::Gold;
    }
    else if(numsToSort[index] == forestGreen){
      leds[index] = CRGB::ForestGreen;
    }
    else if(numsToSort[index] == lavender){
      leds[index] = CRGB::Lavender;
    }
    FastLED.show();
    delay(colourDelay);
}

void boulbeSort(){
  for(int i = 0; i < numsToSortLength; i++){
    for(int j = 0; j < ((numsToSortLength - i) - 1); j++){
      if(numsToSort[j] > numsToSort[j +1]){
        swap(j, j +1, 10);
      }
    }
  }
}

void selectionSort(){
  int minIndex;
   for(int i = 0; i < numsToSortLength -1; i++){
    minIndex = i;
    for(int j = i+1; j < numsToSortLength; j++){
      if(numsToSort[j] < numsToSort[minIndex]){
        minIndex = j;
      }
    }
    if(minIndex != i){
      swap(minIndex, i, 100);
    }
  }
}

void insertionSort(){
  int key, j, i;
  for(i = 1; i < numsToSortLength; i++){
    key = numsToSort[i];
    j = i -1;
    
    while(j >= 0 && numsToSort[j] > key){
      //numsToSort[j+1] = numsToSort[j];
      swap(j+1, j, 1);
      j = j -1;
    }
    //numsToSort[j+1] = key;
    swap(j+1, key, 1);
  }
}

void swap(int indexA, int indexB, int colourDelay){
  int temp = numsToSort[indexA];
  numsToSort[indexA] = numsToSort[indexB];
  numsToSort[indexB] = temp;
  assignColour(indexA, colourDelay);
  assignColour(indexB, colourDelay);
  Serial.println("5");
}

void printArr(){
  for(int i = 0; i < numsToSortLength; i++){
    Serial.print("I: " + String(i));
    Serial.println(") NumToSort[i]: " + String(numsToSort[i]));
  }
}
