
void read_six_numbers(char *input,int intArray)
{
  int iVar1;
  
  iVar1 = sscanf(input,"%d %d %d %d %d %d",intArray,intArray + 4,intArray + 8,intArray + 0xc,
                 intArray + 0x10,intArray + 0x14);
  if (iVar1 < 6) {
    explode_bomb();
  }
  return;
}