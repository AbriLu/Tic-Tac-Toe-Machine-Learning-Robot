#include <LiquidCrystal.h>
#include <string.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // initialize the library with the numbers of the interface pins

class learner_laws { //class for learner laws
  public:
    int increment_move1,increment_move2,increment_move3,increment_move4;
    int decrement_move1,decrement_move2,decrement_move3,decrement_move4;
};
int val = 0;
learner_laws law;  //learner laws variable
void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  lcd.begin(16, 2);  
  lcd.clear();
}
int button3 = 8;
int button2_navigate = 9;
int button1 = 10;
int navigate_count = 0;
int navigate_val = 0;
int is_yes = 2;
int his_count = 0;
void loop() {
  while(1)
  {
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
    ///////////////////////////////////////////////////////
    while(1) //CLICKING button3
    {
      if(digitalRead(button3) == HIGH)
      {
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
      if(digitalRead(button3) == LOW)
      {
        break;
      }
    }      //CLICKING button3 ends
    ////////////////////////////////////////////////////
    while(1) //CLICKING button1
    {
      if(digitalRead(button1) == HIGH)
      {
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
      if(digitalRead(button1) == LOW)
      {
        break;
      }
    }      //CLICKING button1 ends
    /////////////////////////////////////////////////////////
    while(1) //CLICKING button2_navigate
    {
      if(digitalRead(button2_navigate) == HIGH)
      {
        lcd.clear();
        navigate_count++;
        navigate_val = navigate_count%8;
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
        //lcd.print(navigate_val);
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
      if(digitalRead(button2_navigate) == LOW)
      {
        break;
      }
    }      //CLICKING button2_navigate ends
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
        ////////////////////////////////////////////////////
        while(1) //CLICKING button3
        {
          if(digitalRead(button3) == HIGH)
          {
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
          if(digitalRead(button3) == LOW)
          {
            break;
          }
        }       //CLICKING button3 ends
        //////////////////////////////////////////////////
        while(1) //CLICKING button1
        {
          if(digitalRead(button1) == HIGH)
          {
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
          if(digitalRead(button1) == LOW)
          {
            break;
          }
        }       //CLICKING button3 ends
        
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
        lcd.setCursor(0,0);
        lcd.print("Continuning set");
        lcd.setCursor(0,1);
        lcd.print("up");
        his_count = 0;
        val = 0;
        navigate_count = 0;
        continue;
      }
  	}
    
  }
  delay(3000);
  lcd.clear();
  while(1){}
}