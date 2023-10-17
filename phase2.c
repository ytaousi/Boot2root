void phase_2(undefined4 input)
{
  int index;
  int intArray [7];
  
  read_six_numbers(input,intArray + 1);
  if (intArray[1] != 1) {
    explode_bomb();
  }
  index = 1;
  do {   
    if (intArray[index + 1] != (index + 1) * intArray[index]) {
      explode_bomb();
    }
    index = index + 1;
  } while (index < 6);
  return;
}

/*
input : examplestring    

read_six_numbers will fill :  1 2 6 24 120 720
intArray[0] = ;
intArray[1] == 1;
index = 1; 
  intArray[2] == 2 * intArray[1];  
index = 2; 
  intArray[3] == 3 * intArray[2];  
index = 3; 
  intArray[4] == 4 * intArray[3];
index = 4; 
  intArray[5] == 5 * intArray[4];
index = 5; 
  intArray[6] == 6 * intArray[5];
*/

