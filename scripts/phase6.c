
/* WARNING: Type propagation algorithm not settling */
// 4 2 6 3 1 5
void phase_6(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 *local_38;
  int *local_34 [6];
  int array[6];
  
  local_38 = node1;
  read_six_numbers(param_1,array);
  iVar4 = 0;
  do {
    iVar2 = iVar4;
    if (5 < array[iVar4] - 1U)
    {
      explode_bomb();
    }
    while (iVar2 = iVar2 + 1, iVar2 < 6)
    {
      if (array[iVar4] == array[iVar2])
      {
        explode_bomb();
      }
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  iVar4 = 0;
  do {
    iVar2 = 1;
    piVar3 = (int *)local_38;
    if (1 < array[iVar4])
    {
      do {
        piVar3 = (int *)piVar3[2];
        iVar2 = iVar2 + 1;
      } while (iVar2 < array[iVar4]);
    }
    local_34[iVar4] = piVar3;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 6);
  iVar4 = 1;
  piVar3 = local_34[0];
  do {
    piVar1 = local_34[iVar4];
    piVar3[2] = (int)piVar1;
    iVar4 = iVar4 + 1;
    piVar3 = piVar1;
  } while (iVar4 < 6);
  piVar1[2] = 0;
  iVar4 = 0;
  do {
    if (*local_34[0] < *(int *)local_34[0][2]) {
      explode_bomb();
    }
    local_34[0] = (int *)local_34[0][2];
    iVar4 = iVar4 + 1;
  } while (iVar4 < 5);
  return;
}

