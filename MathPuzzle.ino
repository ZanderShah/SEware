//int num1[4]; 
//int num2[4]; 
//int num3[4]; 
//int ans[4];// 1 for true, 0 for false
//int type[4]; //+ - *
//
//int curMathState =0;
//void MathPuzzle(OrbitInput *obi, GameState *gs) {
//  if (gs->needsReset) {
//    SetMemory(gs, 2, 0);
//    
//    gs->words[0].x = 0;
//    gs->words[0].y = 0;
//
//    gs->shapes[0].type = 1;
//    gs->shapes[0].pos.x = 0;
//    gs->shapes[0].pos.dX = 0;
//    gs->shapes[0].pos.y = 15;
//    gs->shapes[0].pos.dY = 15;
//    gs->shapes[0].width = 15;
//    gs->shapes[0].height = 15;
//    gs->shapes[0].visible = true;
//
//    gs->needsReset = false;
//    gs->words[1].x = 0;
//    gs->words[1].y = 20;
//  }
//  
//  if (!initialized){//set the solution!
//    initialized = 1;
//    time_t randTime;
//    //srand((unsigned) time(&randTime));
//    for (int i=0; i < 4; i++){
//      int a = (rand() % 100) + 1;
//      int b = (rand()%100) +1;
//      int c = rand()%2;
//      int ty = rand()%3;
//      num1[i]=a;
//      num2[i]=b;
//      type[i]=ty;
//      int tempVal;
//      if (ty==1){
//        tempVal=a+b;
//      }else if (ty==2){
//        tempVal=a-b;
//      }else{
//        tempVal = a*b;
//      }
//
//      
//      if (c==1){ //the answer will be true!
//        ans[i]=1;
//      }else{
//        tempVal += (rand() % 100) -49;
//        ans[i]=0;
//      }
//      num3[i]=tempVal;
//      
//    }
//
//    
//    for (int i = 0; i < 3 ;i++){
//      solution[i] = (rand() % (4000 + 1 - 100)) + 100;
//      while (i > 0 && fabs(solution[i]-solution[i - 1]) < 500){
//        solution[i] = (rand() % (4000 + 1 - 100)) + 100;
//      }
//    }
//
//    strcpy(gs->words[0].w, "True or False?");
//    gs->words[0].x = 0;
//    gs->words[0].y = 0;
//
//  }
//
//  //state the problem on screen:
//  char s1[5],s2[5],s3[5],op[2];
//  sprintf(s1,"%d",num1[curMathState]);
//  sprintf(s2,"%d",num2[curMathState]);
//  sprintf(s3,"%d",num3[curMathState]);
//  
//  if (type[curMathState] ==1){
//    strcpy(op,"+");
//  }else if (type[curMathState] ==2){
//    strcpy(op,"-");
//  }else{
//    strcpy(op,"*");
//  }
//  strcpy(gs->words[1].w, s1);
//  strcat(gs->words[1].w, op);
//  strcat(gs->words[1].w, s2);
//  strcat(gs->words[1].w, "=");
//  strcat(gs->words[1].w, s3);
//
//  char s4[5];
//  sprintf(s4,"%d",curMathState);
//  strcat(gs->words[1].w,s4);
//   
//  if (obi->buttons[0]){ //selected true!
//    if (ans[curMathState]==1){ //got it right
//      curMathState+=1;
//    }else{
//      //lose      
//    }
//  }else if (obi->buttons[1]) { //selected false
//    curMathState+=1;
//    if (ans[curMathState]==0){ //got it right
//      curMathState+=1;
//    }else{
//      //lose      
//    }
//  }
//  
//
//  
//
//  
//
//  if (curMathState >=4){//win
//    
//  }
//
//  
//}
//

