//opukmq
void phase_5(int input)
{
  int iVar1;
  undefined array[6];
  undefined local_6;
  
  iVar1 = string_length(input);
  if (iVar1 != 6) {
    explode_bomb();
  }
  iVar1 = 0;
  do {
    array[iVar1] = (&array_123)[(char)(*(byte *)(iVar1 + input) & 0xf)];
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  local_6 = 0;
  iVar1 = strings_not_equal(array,"giants");
  if (iVar1 != 0) {
    explode_bomb();
  }
  return;
}