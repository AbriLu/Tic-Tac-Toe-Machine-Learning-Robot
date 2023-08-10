#include <LiquidCrystal.h>
#include <string.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // initialize the library with the numbers of the interface pins
int str_len(char *h) //function that counts the length of a string of char
{
  int count = 0;
  while (h[count] != '\0')
  {
    count++;
  }
  return count;
}
class learner_laws { //class for learner laws
  public:
    int increment_move1,increment_move2,increment_move3,increment_move4;
    int decrement_move1,decrement_move2,decrement_move3,decrement_move4;
};
class move{  //move class that stores the whole move message 
  //{“LNR-MVR”,”MOVIDS1&MOVPBT”,”19682”,”4”,”4”}
  public:
    char Message_header[30] = "LNR-MVR",Message_type[30] = "MOVIDS0&MOVPBT";
    int Board_ID,Position_ID,Move_Probabilities;
    void print_mov (move a_move);
};
class last_four {  //class for the last four moves
  public:
    move last_move,second_last_move2,third_last_move3,fourth_last_move4;
};
int val = 0;
learner_laws law;  //learner laws variable
/////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  lcd.begin(20, 4);  
  lcd.clear();
}
/////////////////////////////////////////////////////////////
void print_mov (move a_move)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(a_move.Message_type);
  lcd.setCursor(0,1);
  lcd.print(a_move.Board_ID);
  lcd.setCursor(0,2);
  lcd.print(a_move.Position_ID);
  lcd.setCursor(0,3);
  lcd.print(a_move.Move_Probabilities);
  delay(3000);
}
int buttonState3 = 0;       
int lastButtonState3 = 0;   
int buttonState2 = 0;        
int lastButtonState2 = 0; 
int buttonState1 = 0;         
int lastButtonState1 = 0; 
int button3 = 8;
int button2_navigate = 9;
int button1 = 10;
int navigate_count = 0;
int navigate_val = 0;
int is_yes = 2;
int his_count = 0;
int tts = 0;
int l = 0;
int m = 0;
bool outcome_received = false;
char LNR_MVR [8] = "LNR-MVR";
char MVR_LNR [8] = "MVR-LNR";
bool is_LNR_MVR = false;
bool is_MVR_LNR = false;
int i_m = 0;
int i = 1;
char u [30];
char board_id[7];
char position_id[2];
char position_prob[6];
char outcome[3];
move received_move;
last_four last_four_moves;
char last_move [40] = "LNR-MVRMOVIDS1&MOVPBT";
char second_last_move [40] = "LNR-MVRMOVIDS2&MOVPBT";
char third_last_move [40] = "LNR-MVRMOVIDS3&MOVPBT";
char fourth_last_move [40] = "LNR-MVRMOVIDS4&MOVPBT";
char p[2];
void loop() 
{
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //LA LUKUMBI'S PART (consist in using the buttons to set up the learner laws)
  if(his_count == 0) {
    while(1) {
      if (his_count == 0)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("increment_move1");
        his_count = 1;
      }
      lcd.setCursor(0,1);
      lcd.print(val);
      is_yes = 2;
      navigate_val = navigate_count%8;
      //SETTING UP LEARNER LAWS
      ////////////////////////////////////////////////////////////////
      buttonState3 = digitalRead(button3);
      if (buttonState3 != lastButtonState3) { //CLICKING button3
        if (buttonState3 == HIGH) {
          lcd.clear();
          lcd.setCursor(0,1);
          val++;
          lcd.print(val);
          if (navigate_val == 0)
          {
            law.increment_move1 = val;
            lcd.setCursor(0,0);
            lcd.print("increment_move1");
          }
          if (navigate_val == 1)
          {
            law.increment_move2 = val;
            lcd.setCursor(0,0);
            lcd.print("increment_move2");
          }
          if (navigate_val == 2)
          {
            law.increment_move3 = val;
            lcd.setCursor(0,0);
            lcd.print("increment_move3");
          }
          if (navigate_val == 3)
          {
            law.increment_move4 = val;
            lcd.setCursor(0,0);
            lcd.print("increment_move4");
          }
          if (navigate_val == 4)
          {
            law.decrement_move1 = val;
            lcd.setCursor(0,0);
            lcd.print("decrement_move1");
          }
          if (navigate_val == 5)
          {
            law.decrement_move2 = val;
            lcd.setCursor(0,0);
            lcd.print("decrement_move2");
          }
          if (navigate_val == 6)
          {
            law.decrement_move3 = val;
            lcd.setCursor(0,0);
            lcd.print("decrement_move3");
          }
          if (navigate_val == 7)
          {
            law.decrement_move4 = val;
            lcd.setCursor(0,0);
            lcd.print("decrement_move4");
          }
          while(digitalRead(button3) == HIGH)
          {
            while(1)
            {
              if(digitalRead(button3) == LOW)
              {
                break;
              }
            }
          }
        }
        delay(50);
      }
      lastButtonState3 = buttonState3;
      //CLICKING button3 ends
      ////////////////////////////////////////////////////////////////
      //CLICKING button1
      buttonState1 = digitalRead(button1);
      if (buttonState1 != lastButtonState1)
      {
        if (buttonState1 == HIGH) {
          lcd.clear();
          lcd.setCursor(0,1);
          val--;
          lcd.print(val);
          if (navigate_val == 0)
          {
            law.increment_move1 = val;
            lcd.setCursor(0,0);
            lcd.print("increment_move1");
          }
          if (navigate_val == 1)
          {
            law.increment_move2 = val;
            lcd.setCursor(0,0);
            lcd.print("increment_move2");
          }
          if (navigate_val == 2)
          {
            law.increment_move3 = val;
            lcd.setCursor(0,0);
            lcd.print("increment_move3");
          }
          if (navigate_val == 3)
          {
            law.increment_move4 = val;
            lcd.setCursor(0,0);
            lcd.print("increment_move4");
          }
          if (navigate_val == 4)
          {
            law.decrement_move1 = val;
            lcd.setCursor(0,0);
            lcd.print("decrement_move1");
          }
          if (navigate_val == 5)
          {
            law.decrement_move2 = val;
            lcd.setCursor(0,0);
            lcd.print("decrement_move2");
          }
          if (navigate_val == 6)
          {
            law.decrement_move3 = val;
            lcd.setCursor(0,0);
            lcd.print("decrement_move3");
          }
          if (navigate_val == 7)
          {
            law.decrement_move4 = val;
            lcd.setCursor(0,0);
            lcd.print("decrement_move4");
          }
          while(digitalRead(button1) == HIGH)
          {
            while(1)
            {
              if(digitalRead(button1) == LOW)
              {
                break;
              }
            }
          }
        }
        delay(50);
      }
      lastButtonState1 = buttonState1;
      //CLICKING button1 ends
      /////////////////////////////////////////////////////////////////
      //CLICKING button2_navigate
      buttonState2 = digitalRead(button2_navigate);
      if (buttonState2 != lastButtonState2) 
      {
        if (buttonState2 == HIGH) {
          lcd.clear();
          navigate_count++;
          navigate_val = navigate_count%8;
          lcd.setCursor(0,1);
          val = 0;
          lcd.print(val);
          if (navigate_val == 0 && navigate_count < 8)
          {
            lcd.setCursor(0,0);
            lcd.print("increment_move1");
          }
          if (navigate_val == 1)
          {
            lcd.setCursor(0,0);
            lcd.print("increment_move2");
          }
          if (navigate_val == 2)
          {
            lcd.setCursor(0,0);
            lcd.print("increment_move3");
          }
          if (navigate_val == 3)
          {
            lcd.setCursor(0,0);
            lcd.print("increment_move4");
          }
          if (navigate_val == 4)
          {
            lcd.setCursor(0,0);
            lcd.print("decrement_move1");
          }
          if (navigate_val == 5)
          {
            lcd.setCursor(0,0);
            lcd.print("decrement_move2");
          }
          if (navigate_val == 6)
          {
            lcd.setCursor(0,0);
            lcd.print("decrement_move3");
          }
          if (navigate_val == 7)
          {
            lcd.setCursor(0,0);
            lcd.print("decrement_move4");
          }
          while(digitalRead(button2_navigate) == HIGH)
          {
            while(1)
            {
              if(digitalRead(button2_navigate) == LOW)
              {
                break;
              }
            }
          }
        }
        delay(50);
      }
      lastButtonState2 = buttonState2;
      //CLICKING button2_navigate ends
      ///////////////////////////////////////////////////////////
      //SETTING UP LEARNER LAWS ENDS
      if(navigate_count >= 8)
      {
        val = 0;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(law.increment_move1);
        lcd.setCursor(2,0);
        lcd.print(law.increment_move2);
        lcd.setCursor(4,0);
        lcd.print(law.increment_move3);
        lcd.setCursor(6,0);
        lcd.print(law.increment_move4);
        lcd.setCursor(8,0);
        lcd.print(law.decrement_move1);
        lcd.setCursor(10,0);
        lcd.print(law.decrement_move2);
        lcd.setCursor(12,0);
        lcd.print(law.decrement_move3);
        lcd.setCursor(14,0);
        lcd.print(law.decrement_move4);
        lcd.setCursor(0,1);
        lcd.print("Yes?");
        lcd.setCursor(13,1);
        lcd.print("No?");
        while(val == 0) ///button click
        {
          ////////////////////////////////////////////////////////////
          buttonState3 = digitalRead(button3);
          if (buttonState3 != lastButtonState3) { //CLICKING button3
            if (buttonState3 == HIGH) {
              val++;
              while(digitalRead(button3) == HIGH)
              {
                while(1)
                {
                  if(digitalRead(button3) == LOW)
                  {
                    break;
                  }
                }
              }
            }
            delay(50);
          }
          lastButtonState3 = buttonState3;
          //CLICKING button3 ends 
          ////////////////////////////////////////////////////////////
          buttonState1 = digitalRead(button1);
          if (buttonState1 != lastButtonState1) { //CLICKING button3
            if (buttonState1 == HIGH) {
              val--;
              while(digitalRead(button1) == HIGH)
              {
                while(1)
                {
                  if(digitalRead(button1) == LOW)
                  {
                    break;
                  }
                }
              }
            }
            delay(50);
          }
          lastButtonState1 = buttonState1;
          //CLICKING button3 ends 
          ////////////////////////////////////////////////////////////
          if(val == -1)  //test button click
          {
            is_yes = 1;
            break;
          }
          if(val == 1)
          {
            is_yes = 0;
            break;
          } //test button click ends
          ////////////////////////////////////////////////////
        }        ///button click ends

        if(is_yes == 1)
        {
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Learner laws");
          lcd.setCursor(0,1);
          lcd.print("saved");
          break;
        }
        else if (is_yes == 0)
        {
          lcd.clear();
          int wena = 3 + (millis() / 1000);
          while(tts < 3)
          {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Continuning set");
            lcd.setCursor(0,1);
            lcd.print("up in: ");
            lcd.setCursor(8,1);
            lcd.print(wena-(millis() / 1000));
            delay(1000);
            lcd.clear();
            tts++;
          }
          tts = 0;
          delay(1000);
          his_count = 0;
          val = 0;
          navigate_count = 0;
          continue;
        }
      }   
    }
    delay(3000);
    lcd.clear();
    //while(1){}
  }
  //LA LUKUMBI'S PART END
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //T MIYA'S PART
//HAHA//////////////////////////////////
  lcd.clear();
  prev_pos[0] = U[26];
  while (prev_pos[0] == u[26] && strlen(u[26]) <=25) {
    Serial.readBytes(u,30);
    if (prev_pos[0] != u[26]) {
      break;
    }
    lcd.setCursor(4, 1);
    lcd.print("Waiting for");
    lcd.setCursor(4, 2);
    lcd.print("New input");
    lcd.setCursor(13, 2);
    lcd.print(".");
    delay(200);
    lcd.setCursor(14, 2);
    lcd.print(".");
    delay(200);
    lcd.setCursor(15, 2);
    lcd.print(".");
    delay(200);
    lcd.setCursor(13, 2);
    lcd.print("    ");
    delay(200);
  }
  Serial.println(u);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(u);
  delay(2000);

//HAHA//////////////////////////////////
/*
  if(i==1){
    u[26]={'4'};
    u[27]={'2'};
  }
  else if(i==2){
    u[26]={'6'};
    u[27]={'3'};
  }
  else if(i==3){
    u[26]={'5'};
    u[27]={'3'};
  }
  else if(i==4){
    u[26]={'2'};
    u[27]={'4'};
  }
  else if(i==5){
    u[26]={'7'};
    u[27]={'5'};
  }
  else if(i==6){
    u[26]={'1'};
    u[27]={'9'};
  }
  else{
    u[26]={'3'};
    u[27]={'3'};
    outcome_received = true;
    int iii = rand()%3;
    switch(iii)
    {
      case 0:
        outcome[0] = 'W';
        break;
      case 1:
        outcome[0] = 'L';
        break;
      case 2:
        outcome[0] = 'D';
        break;
    }
  }
*/
  i++;
  //Serial.readBytes(u,30); //Read the serial data and store in var
  //Serial.println(u);
  
  //T MIYA'S PART END
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //T KOMANA'S PART
  //char u [29] = {"MOV-LNRMOVMADE&MOVPBT1968244"};
  //{“LNR-MVR”,”MOVIDS0&MOVPBT”,”19682”,”4”,”4”}
  //char LNR_MVR [8] = "LNR-MVR";
  //char MVR_LNR [8] = "MVR-LNR";
  lcd.setCursor(0,1);
  i_m = 0;
  int count_a = 0;
  int count_b = 0;
  //bool is_LNR_MVR = false;
  //bool is_MVR_LNR = false;
  while(i_m < 7)
  {
    if(LNR_MVR[i_m] == u [i_m])
    {
      count_a++;
    }
    if(MVR_LNR[i_m] == u [i_m])
    {
      count_b++;
    }
    i_m++;
  }
  if(count_a >= 5)
  {
    is_LNR_MVR = true;
  }
  if(count_b >= 5)
  {
    is_MVR_LNR = true;
  }
  count_a = 0;
  count_b = 0;
  i_m = 0;
  int count_ab;
  int my_ind;
  l = m%4;
  if(is_MVR_LNR)
  {
    count_ab = strlen(u);
    my_ind = 0;
    //Serial.print(count_ab);
    while (my_ind < count_ab)
    {
      if(my_ind > 20 && my_ind < 26)
      {
        board_id[my_ind-21] = u[my_ind];
      }
      if(my_ind > 26 && u[my_ind] != '\0' )
      {
        position_prob[my_ind-27] = u[my_ind];
      }
      my_ind++;
    }
    position_id [0] = u[26];
    received_move.Board_ID = atoi(board_id);
    received_move.Position_ID = atoi(position_id);
    received_move.Move_Probabilities = atoi(position_prob);
    l = m%4;
    //{“LNR-MVR”,”MOVIDS0&MOVPBT”,”19682”,”4”,”4”}
    last_four_moves.fourth_last_move4.Message_type[6] = '4';
    last_four_moves.fourth_last_move4.Board_ID =  last_four_moves.third_last_move3.Board_ID;
    last_four_moves.fourth_last_move4.Position_ID = last_four_moves.third_last_move3.Position_ID ;
    last_four_moves.fourth_last_move4.Move_Probabilities = last_four_moves.third_last_move3.Move_Probabilities;
    ////////////////////////////////////////////////////////////////////
    last_four_moves.third_last_move3.Message_type[6] = '3';
    last_four_moves.third_last_move3.Board_ID =  last_four_moves.second_last_move2.Board_ID;
    last_four_moves.third_last_move3.Position_ID = last_four_moves.second_last_move2.Position_ID;
    last_four_moves.third_last_move3.Move_Probabilities = last_four_moves.second_last_move2.Move_Probabilities;
    ////////////////////////////////////////////////////////////////////
    last_four_moves.second_last_move2.Message_type[6] = '2';
    last_four_moves.second_last_move2.Board_ID =  last_four_moves.last_move.Board_ID;
    last_four_moves.second_last_move2.Position_ID = last_four_moves.last_move.Position_ID;
    last_four_moves.second_last_move2.Move_Probabilities = last_four_moves.last_move.Move_Probabilities;
    ////////////////////////////////////////////////////////////////////
    last_four_moves.last_move.Message_type[6] = '1';
    last_four_moves.last_move.Board_ID =  received_move.Board_ID;
    last_four_moves.last_move.Position_ID = received_move.Position_ID;
    last_four_moves.last_move.Move_Probabilities = received_move.Move_Probabilities;
    print_mov (last_four_moves.last_move);
  }
  m++;
  bool is_LNR_MVR = false;
  bool is_MVR_LNR = false;
  //T KOMANA'S PART ENDS
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  
  if (outcome_received)
  {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //MG MANGENE'S PART
    //Learner laws implementation
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Displaying the saved");
    lcd.setCursor(0,1);
    lcd.print("last four moves");
    lcd.setCursor(0,2);
    lcd.print("...");
    lcd.setCursor(0,3);
    lcd.print("Outcome: ");
    lcd.print(outcome);
    delay(3000);
    print_mov (last_four_moves.last_move);
    print_mov (last_four_moves.second_last_move2);
    print_mov (last_four_moves.third_last_move3);
    print_mov (last_four_moves.fourth_last_move4);
    if(outcome[0]=='W' || outcome[0]=='D'){//Increment if Won
      last_four_moves.last_move.Move_Probabilities += law.increment_move1; 
      last_four_moves.second_last_move2.Move_Probabilities += law.increment_move2;
      last_four_moves.third_last_move3.Move_Probabilities += law.increment_move3;
      last_four_moves.fourth_last_move4.Move_Probabilities += law.increment_move4;
    }
     if(outcome[0]=='L'){//Decrement if Lost
      last_four_moves.last_move.Move_Probabilities += law.decrement_move1; 
      last_four_moves.second_last_move2.Move_Probabilities += law.decrement_move2;
      last_four_moves.third_last_move3.Move_Probabilities += law.decrement_move3;
      last_four_moves.fourth_last_move4.Move_Probabilities += law.decrement_move4;
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Displaying the ");
    lcd.setCursor(0,1);
    lcd.print("updated last four");
    lcd.setCursor(0,2);
    lcd.print("moves...");
    lcd.setCursor(0,3);
    lcd.print("Outcome: ");
    lcd.print(outcome);
    delay(3000);
    print_mov (last_four_moves.last_move);
    print_mov (last_four_moves.second_last_move2);
    print_mov (last_four_moves.third_last_move3);
    print_mov (last_four_moves.fourth_last_move4);
    //MG MANGENE'S PART END
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //W ZWANE'S PART
    //convert last_move class to char
  	//last_move[13] = '1';
    p[0] = '1';
    Serial.write(p);
    int num_in = last_four_moves.last_move.Board_ID;
  	int num_in1 = last_four_moves.last_move.Move_Probabilities;
    int num_count = 0;
    int num_out = num_in;
  	int num_out1 = num_in1;
    while (num_in1 > 0)
    {
      num_in1 /= 10;
      num_count++;
    }
    for (int nn = 26+num_count ; nn > 20; --nn)
    {
      if(nn > 26)
      {
        last_move[nn-1] = (num_out1%10) + '0';
      	num_out1 /= 10;
      }
      else if(nn == 26) 
      {
        last_move[nn-1] = last_four_moves.last_move.Position_ID + '0';
      }
      else
      {
        last_move[nn-1] = (num_out%10) + '0';
      	num_out /= 10;
      }
    }
    //convert last_move class to char ENDS
    //////////////////////////////////////////////////////////////////
    //convert second_last_move class to char
  	//last_move[13] = '1';
    num_in = last_four_moves.second_last_move2.Board_ID;
  	num_in1 = last_four_moves.second_last_move2.Move_Probabilities;
    num_count = 0;
    num_out = num_in;
  	num_out1 = num_in1;
    while (num_in1 > 0)
    {
      num_in1 /= 10;
      num_count++;
    }
    for (int nn = 26+num_count ; nn > 20; --nn)
    {
      if(nn > 26)
      {
        second_last_move[nn-1] = (num_out1%10) + '0';
      	num_out1 /= 10;
      }
      else if(nn == 26) 
      {
        second_last_move[nn-1] = last_four_moves.second_last_move2.Position_ID + '0';
      }
      else
      {
        second_last_move[nn-1] = (num_out%10) + '0';
      	num_out /= 10;
      }
    }
    //convert second_last_move class to char ENDS
    //////////////////////////////////////////////////////////////////
    //convert third_last_move class to char
  	//last_move[13] = '1';
    num_in = last_four_moves.third_last_move3.Board_ID;
  	num_in1 = last_four_moves.third_last_move3.Move_Probabilities;
    num_count = 0;
    num_out = num_in;
  	num_out1 = num_in1;
    while (num_in1 > 0)
    {
      num_in1 /= 10;
      num_count++;
    }
    for (int nn = 26+num_count ; nn > 20; --nn)
    {
      if(nn > 26)
      {
        third_last_move[nn-1] = (num_out1%10) + '0';
      	num_out1 /= 10;
      }
      else if(nn == 26) 
      {
        third_last_move[nn-1] = last_four_moves.third_last_move3.Position_ID + '0';
      }
      else
      {
        third_last_move[nn-1] = (num_out%10) + '0';
      	num_out /= 10;
      }
    }
    //convert third_last_move class to char ENDS
    //////////////////////////////////////////////////////////////////
    //convert fourth_last_move class to char
  	//last_move[13] = '1';
    num_in = last_four_moves.fourth_last_move4.Board_ID;
  	num_in1 = last_four_moves.fourth_last_move4.Move_Probabilities;
    num_count = 0;
    num_out = num_in;
  	num_out1 = num_in1;
    while (num_in1 > 0)
    {
      num_in1 /= 10;
      num_count++;
    }
    for (int nn = 26+num_count ; nn > 20; --nn)
    {
      if(nn > 26)
      {
        fourth_last_move[nn-1] = (num_out1%10) + '0';
      	num_out1 /= 10;
      }
      else if(nn == 26) 
      {
        fourth_last_move[nn-1] = last_four_moves.fourth_last_move4.Position_ID + '0';
      }
      else
      {
        fourth_last_move[nn-1] = (num_out%10) + '0';
      	num_out /= 10;
      }
    }
    //convert fourth_last_move class to char ENDS
    /*
  	Serial.println("haha");
  	Serial.println(last_move);
    Serial.println(second_last_move);
    Serial.println(third_last_move);
    Serial.println(fourth_last_move);
  	Serial.println("haha");
    */
    ///////////////////////////////////////////////////////////////////////////////////////
    //Sending the last four moves to the mover-subsystem
    /*
    char last_move [40] = "LNR-MVRMOVIDS1&MOVPBT";
	char second_last_move [40] = "LNR-MVRMOVIDS2&MOVPBT";
	char third_last_move [40] = "LNR-MVRMOVIDS3&MOVPBT";
	char fourth_last_move [40] = "LNR-MVRMOVIDS4&MOVPBT";
    */
    
    
    Serial.write(last_move);
    delay(2000);
    Serial.write(second_last_move);
     delay(2000);
    Serial.write(third_last_move);
     delay(2000);
    Serial.write(fourth_last_move);
     delay(3000);
    p[0]='0';
    
    
    //Sending the last four moves to the mover-subsystem ENDS
    //W ZWANE'S PART END
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    lcd.clear();
    while(1){}
  }
}
























///////////////////////////////////////////////////////////
//SECOND_ARDUINO_CODE
/*
void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}
int str_len(char *h) //function that counts the length of a string of char
{
  int count = 0;
  while (h[count] != '\0')
  {
    count++;
  }
  return count;
}
char last_move [40];
char second_last_move [40]; 
char third_last_move [40]; 
char fourth_last_move [40];
char p[2] = {"0"};
int len1 = 0;
int len2 = 0;
int len3 = 0;
int len4 = 0;
void loop() {
  len1 = str_len(last_move);
  len2 = str_len(second_last_move);
  len3 = str_len(third_last_move);
  len4 = str_len(fourth_last_move);
  Serial.println(len1);
  Serial.println(len2);
  Serial.println(len3);
  Serial.println(len4);
  Serial.readBytes(p,2);
  if(p[0] == '1')
  {
 Serial.readBytes(last_move,30);
 Serial.println(last_move);
 Serial.println("\n");
 Serial.readBytes(second_last_move,30);
 Serial.println(second_last_move);
  Serial.println("\n");
 Serial.readBytes(third_last_move,40);
  Serial.println(third_last_move);
  Serial.println("\n");
  Serial.readBytes(fourth_last_move,30);
  Serial.println(fourth_last_move);
  Serial.println("\n");
  }
  if(len1>=20 && len2 >= 20 && len3 >= 20 && len4 >= 20){ 
  while(1){}
  }
   Serial.readBytes(p,2);
}
*/