
void phase_3(char *param_1)

{
  int iVar1;
  char cVar2;
  uint local_10;
  char local_9;
  int local_8;
  
  iVar1 = sscanf(param_1,"%d %c %d",&local_10,&local_9,&local_8);
  if (iVar1 < 3) {
    explode_bomb();
  }
  switch(local_10) {
  case 0:
    cVar2 = 'q';
    if (local_8 != 0x309) {
      explode_bomb();
    }
    break;
  case 1:
    cVar2 = 'b'; // 1 b 214
    if (local_8 != 0xd6) {
      explode_bomb();
    }
    break;
  case 2: // 2 b 755
    cVar2 = 'b';
    if (local_8 != 0x2f3) {
      explode_bomb();
    }
    break;
  case 3: // 3 k 251
    cVar2 = 'k';
    if (local_8 != 0xfb) {
      explode_bomb();
    }
    break;
  case 4: // 4 o 160
    cVar2 = 'o';
    if (local_8 != 0xa0) {
      explode_bomb();
    }
    break;
  case 5: // 5 t 458
    cVar2 = 't';
    if (local_8 != 0x1ca) {
      explode_bomb();
    }
    break;
  case 6: // 6 v 780
    cVar2 = 'v';
    if (local_8 != 0x30c) {
      explode_bomb();
    }
    break;
  case 7: // 7 b 524
    cVar2 = 'b';
    if (local_8 != 0x20c) {
      explode_bomb();
    }
    break;
  default:
    cVar2 = 'x';
    explode_bomb();
  }
  if (cVar2 != local_9) {
    explode_bomb();
  }
  return;
}

