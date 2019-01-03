#include "MyProject_objects.h"
#include "MyProject_resources.h"
#include "built_in.h"


// TFT module connections
sbit TFT_BLED at GPIO_PORTA_DATA3_bit;
sbit TFT_CS at GPIO_PORTH_DATA6_bit;
char TFT_DataPort at GPIO_PORTJ_DATA;
sbit TFT_RD at GPIO_PORTC_DATA5_bit;
sbit TFT_RS at GPIO_PORTG_DATA7_bit;
sbit TFT_RST at GPIO_PORTH_DATA5_bit;
sbit TFT_WR at GPIO_PORTH_DATA4_bit;
sbit TFT_BLED_Direction at GPIO_PORTA_DIR3_bit;
sbit TFT_CS_Direction at GPIO_PORTH_DIR6_bit;
char TFT_DataPort_Direction at GPIO_PORTJ_DIR;
sbit TFT_RD_Direction at GPIO_PORTC_DIR5_bit;
sbit TFT_RS_Direction at GPIO_PORTG_DIR7_bit;
sbit TFT_RST_Direction at GPIO_PORTH_DIR5_bit;
sbit TFT_WR_Direction at GPIO_PORTH_DIR4_bit;
// End TFT module connections

// Touch Panel module connections
sbit DriveX_Left at GPIO_PORTB_DATA4_bit;
sbit DriveX_Right at GPIO_PORTE_DATA0_bit;
sbit DriveY_Up at GPIO_PORTE_DATA1_bit;
sbit DriveY_Down at GPIO_PORTB_DATA5_bit;
sbit DriveX_Left_Direction at GPIO_PORTB_DIR4_bit;
sbit DriveX_Right_Direction at GPIO_PORTE_DIR0_bit;
sbit DriveY_Up_Direction at GPIO_PORTE_DIR1_bit;
sbit DriveY_Down_Direction at GPIO_PORTB_DIR5_bit;
// End Touch Panel module connections

// Global variables
unsigned int Xcoord, Ycoord;
const ADC_THRESHOLD = 750;
char PenDown;
void *PressedObject;
int PressedObjectType;
unsigned int caption_length, caption_height;
unsigned int display_width, display_height;

int _object_count;
unsigned short object_pressed;
TButton *local_button;
TButton *exec_button;
int button_order;
TButton_Round *local_round_button;
TButton_Round *exec_round_button;
int round_button_order;


void Init_ADC() {
  ADC_Set_Input_Channel(_ADC_CHANNEL_10 | _ADC_CHANNEL_11);
  ADC0_Init_Advanced(_ADC_EXTERNAL_REF);
}
static void InitializeTouchPanel() {
  Init_ADC();
  TFT_Init(320, 240);

  TP_TFT_Init(320, 240, 11, 10);                                  // Initialize touch panel
  TP_TFT_Set_ADC_Threshold(ADC_THRESHOLD);                              // Set touch panel ADC threshold

  PenDown = 0;
  PressedObject = 0;
  PressedObjectType = -1;
}

void Calibrate() {
  TFT_Set_Pen(CL_WHITE, 3);
  TFT_Set_Font(TFT_defaultFont, CL_WHITE, FO_HORIZONTAL);
  TFT_Write_Text("Touch selected corners for calibration", 50, 80);
  TFT_Line(315, 239, 319, 239);
  TFT_Line(309, 229, 319, 239);
  TFT_Line(319, 234, 319, 239);
  TFT_Write_Text("first here", 210, 220);

  TP_TFT_Calibrate_Min();                      // Calibration of TP minimum
  Delay_ms(500);

  TFT_Set_Pen(CL_BLACK, 3);
  TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
  TFT_Line(315, 239, 319, 239);
  TFT_Line(309, 229, 319, 239);
  TFT_Line(319, 234, 319, 239);
  TFT_Write_Text("first here", 210, 220);

  TFT_Set_Pen(CL_WHITE, 3);
  TFT_Set_Font(TFT_defaultFont, CL_WHITE, FO_HORIZONTAL);
  TFT_Write_Text("now here ", 20, 5);
  TFT_Line(0, 0, 5, 0);
  TFT_Line(0, 0, 0, 5);
  TFT_Line(0, 0, 10, 10);

  TP_TFT_Calibrate_Max();                       // Calibration of TP maximum
  Delay_ms(500);
}


/////////////////////////
  TScreen*  CurrentScreen;

  TScreen                Screen1;
  TButton               Button1;
char Button1_Caption[5] = "Text";

  TButton_Round          ButtonRound1;
char ButtonRound1_Caption[5] = "Text";

  TButton                * const code Screen1_Buttons[1]=
         {
         &Button1              
         };
  TButton_Round          * const code Screen1_Buttons_Round[1]=
         {
         &ButtonRound1         
         };



static void InitializeObjects() {
  Screen1.Color                     = 0x5AEB;
  Screen1.Width                     = 320;
  Screen1.Height                    = 240;
  Screen1.ButtonsCount              = 1;
  Screen1.Buttons                   = Screen1_Buttons;
  Screen1.Buttons_RoundCount        = 1;
  Screen1.Buttons_Round             = Screen1_Buttons_Round;
  Screen1.ObjectsCount              = 2;


  Button1.OwnerScreen     = &Screen1;
  Button1.Order           = 0;
  Button1.Left            = 139;
  Button1.Top             = 109;
  Button1.Width           = 50;
  Button1.Height          = 25;
  Button1.Pen_Width       = 1;
  Button1.Pen_Color       = 0x0000;
  Button1.Visible         = 1;
  Button1.Active          = 1;
  Button1.Transparent     = 1;
  Button1.Caption         = Button1_Caption;
  Button1.TextAlign       = _taCenter;
  Button1.TextAlignVertical= _tavMiddle;
  Button1.FontName        = Tahoma11x13_Regular;
  Button1.PressColEnabled = 1;
  Button1.Font_Color      = 0x0000;
  Button1.VerticalText    = 0;
  Button1.Gradient        = 1;
  Button1.Gradient_Orientation = 0;
  Button1.Gradient_Start_Color = 0xFFFF;
  Button1.Gradient_End_Color = 0xC618;
  Button1.Color           = 0xC618;
  Button1.Press_Color     = 0xE71C;
  Button1.OnUpPtr         = 0;
  Button1.OnDownPtr       = 0;
  Button1.OnClickPtr      = Button1OnClick;
  Button1.OnPressPtr      = 0;

  ButtonRound1.OwnerScreen     = &Screen1;
  ButtonRound1.Order           = 1;
  ButtonRound1.Left            = 35;
  ButtonRound1.Top             = 38;
  ButtonRound1.Width           = 50;
  ButtonRound1.Height          = 25;
  ButtonRound1.Pen_Width       = 1;
  ButtonRound1.Pen_Color       = 0x0000;
  ButtonRound1.Visible         = 1;
  ButtonRound1.Active          = 1;
  ButtonRound1.Transparent     = 1;
  ButtonRound1.Caption         = ButtonRound1_Caption;
  ButtonRound1.TextAlign       = _taCenter;
  ButtonRound1.TextAlignVertical= _tavMiddle;
  ButtonRound1.FontName        = Tahoma11x13_Regular;
  ButtonRound1.PressColEnabled = 1;
  ButtonRound1.Font_Color      = 0x0000;
  ButtonRound1.VerticalText    = 0;
  ButtonRound1.Gradient        = 1;
  ButtonRound1.Gradient_Orientation = 0;
  ButtonRound1.Gradient_Start_Color = 0xFFFF;
  ButtonRound1.Gradient_End_Color = 0xC618;
  ButtonRound1.Color           = 0xC618;
  ButtonRound1.Press_Color     = 0xE71C;
  ButtonRound1.Corner_Radius   = 3;
  ButtonRound1.OnUpPtr         = 0;
  ButtonRound1.OnDownPtr       = 0;
  ButtonRound1.OnClickPtr      = ButtonRound1OnClick;
  ButtonRound1.OnPressPtr      = 0;
}

static char IsInsideObject (unsigned int X, unsigned int Y, unsigned int Left, unsigned int Top, unsigned int Width, unsigned int Height) { // static
  if ( (Left<= X) && (Left+ Width - 1 >= X) &&
       (Top <= Y)  && (Top + Height - 1 >= Y) )
    return 1;
  else
    return 0;
}


#define GetButton(index)              CurrentScreen->Buttons[index]
#define GetRoundButton(index)         CurrentScreen->Buttons_Round[index]

void DrawButton(TButton *Abutton) {
unsigned int ALeft, ATop;
  if (Abutton->Visible != 0) {
    if (object_pressed == 1) {
      object_pressed = 0;
      TFT_Set_Brush(Abutton->Transparent, Abutton->Press_Color, Abutton->Gradient, Abutton->Gradient_Orientation, Abutton->Gradient_End_Color, Abutton->Gradient_Start_Color);
    }
    else {
      TFT_Set_Brush(Abutton->Transparent, Abutton->Color, Abutton->Gradient, Abutton->Gradient_Orientation, Abutton->Gradient_Start_Color, Abutton->Gradient_End_Color);
    }
    TFT_Set_Pen(Abutton->Pen_Color, Abutton->Pen_Width);
    TFT_Rectangle(Abutton->Left, Abutton->Top, Abutton->Left + Abutton->Width - 1, Abutton->Top + Abutton->Height - 1);
    if (Abutton->VerticalText != 0)
      TFT_Set_Font(Abutton->FontName, Abutton->Font_Color, FO_VERTICAL_COLUMN);
    else
      TFT_Set_Font(Abutton->FontName, Abutton->Font_Color, FO_HORIZONTAL);
    TFT_Write_Text_Return_Pos(Abutton->Caption, Abutton->Left, Abutton->Top);
    if (Abutton->TextAlign == _taLeft)
      ALeft = Abutton->Left + 4;
    else if (Abutton->TextAlign == _taCenter)
      ALeft = Abutton->Left + (Abutton->Width - caption_length) / 2;
    else if (Abutton->TextAlign == _taRight)
      ALeft = Abutton->Left + Abutton->Width - caption_length - 4;

    if (Abutton->TextAlignVertical == _tavTop)
      ATop = Abutton->Top + 4;
    else if (Abutton->TextAlignVertical == _tavMiddle)
      ATop = Abutton->Top + ((Abutton->Height - caption_height) / 2);
    else if (Abutton->TextAlignVertical == _tavBottom)
      ATop = Abutton->Top + (Abutton->Height - caption_height - 4);

    TFT_Write_Text(Abutton->Caption, ALeft, ATop);
  }
}

void DrawRoundButton(TButton_Round *Around_button) {
unsigned int ALeft, ATop;
  if (Around_button->Visible != 0) {
    if (object_pressed == 1) {
      object_pressed = 0;
      TFT_Set_Brush(Around_button->Transparent, Around_button->Press_Color, Around_button->Gradient, Around_button->Gradient_Orientation,
                    Around_button->Gradient_End_Color, Around_button->Gradient_Start_Color);
    }
    else {
      TFT_Set_Brush(Around_button->Transparent, Around_button->Color, Around_button->Gradient, Around_button->Gradient_Orientation,
                    Around_button->Gradient_Start_Color, Around_button->Gradient_End_Color);
    }
    TFT_Set_Pen(Around_button->Pen_Color, Around_button->Pen_Width);
    TFT_Rectangle_Round_Edges(Around_button->Left + 1, Around_button->Top + 1,
      Around_button->Left + Around_button->Width - 2,
      Around_button->Top + Around_button->Height - 2, Around_button->Corner_Radius);
    if (Around_button->VerticalText != 0)
      TFT_Set_Font(Around_button->FontName, Around_button->Font_Color, FO_VERTICAL_COLUMN);
    else
      TFT_Set_Font(Around_button->FontName, Around_button->Font_Color, FO_HORIZONTAL);
    TFT_Write_Text_Return_Pos(Around_button->Caption, Around_button->Left, Around_button->Top);
    if (Around_button->TextAlign == _taLeft)
      ALeft = Around_button->Left + 4;
    else if (Around_button->TextAlign == _taCenter)
      ALeft = Around_button->Left + (Around_button->Width - caption_length) / 2;
    else if (Around_button->TextAlign == _taRight)
      ALeft = Around_button->Left + Around_button->Width - caption_length - 4;

    if (Around_button->TextAlignVertical == _tavTop)
      ATop = Around_button->Top + 3;
    else if (Around_button->TextAlignVertical == _tavMiddle)
      ATop = Around_button->Top + (Around_button->Height - caption_height) / 2;
    else if (Around_button->TextAlignVertical == _tavBottom)
      ATop  = Around_button->Top + Around_button->Height - caption_height - 4;

    TFT_Write_Text(Around_button->Caption, ALeft, ATop);
  }
}

void DrawScreen(TScreen *aScreen) {
 unsigned int order;
  unsigned short button_idx;
  TButton *local_button;
  unsigned short round_button_idx;
  TButton_Round *local_round_button;
  char save_bled, save_bled_direction;

  object_pressed = 0;
  order = 0;
  button_idx = 0;
  round_button_idx = 0;
  CurrentScreen = aScreen;

  if ((display_width != CurrentScreen->Width) || (display_height != CurrentScreen->Height)) {
    save_bled = TFT_BLED;
    save_bled_direction = TFT_BLED_Direction;
    TFT_BLED_Direction = 1;
    TFT_BLED           = 0;
    TFT_Init(CurrentScreen->Width, CurrentScreen->Height);
    TP_TFT_Init(CurrentScreen->Width, CurrentScreen->Height, 11, 10);                                  // Initialize touch panel
    TP_TFT_Set_ADC_Threshold(ADC_THRESHOLD);                              // Set touch panel ADC threshold
    TFT_Fill_Screen(CurrentScreen->Color);
    display_width = CurrentScreen->Width;
    display_height = CurrentScreen->Height;
    TFT_BLED           = save_bled;
    TFT_BLED_Direction = save_bled_direction;
  }
  else
    TFT_Fill_Screen(CurrentScreen->Color);


  while (order < CurrentScreen->ObjectsCount) {
    if (button_idx < CurrentScreen->ButtonsCount) {
      local_button = GetButton(button_idx);
      if (order == local_button->Order) {
        button_idx++;
        order++;
        DrawButton(local_button);
      }
    }

    if (round_button_idx < CurrentScreen->Buttons_RoundCount) {
      local_round_button = GetRoundButton(round_button_idx);
      if (order == local_round_button->Order) {
        round_button_idx++;
        order++;
        DrawRoundButton(local_round_button);
      }
    }

  }
}

void Get_Object(unsigned int X, unsigned int Y) {
  button_order        = -1;
  round_button_order  = -1;
  //  Buttons
  for ( _object_count = 0 ; _object_count < CurrentScreen->ButtonsCount ; _object_count++ ) {
    local_button = GetButton(_object_count);
    if (local_button->Active != 0) {
      if (IsInsideObject(X, Y, local_button->Left, local_button->Top,
                         local_button->Width, local_button->Height) == 1) {
        button_order = local_button->Order;
        exec_button = local_button;
      }
    }
  }

  //  Buttons with Round Edges
  for ( _object_count = 0 ; _object_count < CurrentScreen->Buttons_RoundCount ; _object_count++ ) {
    local_round_button = GetRoundButton(_object_count);
    if (local_round_button->Active != 0) {
      if (IsInsideObject(X, Y, local_round_button->Left, local_round_button->Top,
                         local_round_button->Width, local_round_button->Height) == 1) {
        round_button_order = local_round_button->Order;
        exec_round_button = local_round_button;
      }
    }
  }

  _object_count = -1;
  if (button_order >  _object_count )
    _object_count = button_order;
  if (round_button_order >  _object_count )
    _object_count = round_button_order;
}


void Process_TP_Press(unsigned int X, unsigned int Y) {
  exec_button         = 0;
  exec_round_button   = 0;

  Get_Object(X, Y);

  if (_object_count != -1) {
    if (_object_count == button_order) {
      if (exec_button->Active != 0) {
        if (exec_button->OnPressPtr != 0) {
          exec_button->OnPressPtr();
          return;
        }
      }
    }

    if (_object_count == round_button_order) {
      if (exec_round_button->Active != 0) {
        if (exec_round_button->OnPressPtr != 0) {
          exec_round_button->OnPressPtr();
          return;
        }
      }
    }

  }
}

void Process_TP_Up(unsigned int X, unsigned int Y) {

  switch (PressedObjectType) {
    // Button
    case 0: {
      if (PressedObject != 0) {
        exec_button = (TButton*)PressedObject;
        if ((exec_button->PressColEnabled != 0) && (exec_button->OwnerScreen == CurrentScreen)) {
          DrawButton(exec_button);
        }
        break;
      }
      break;
    }
    // Round Button
    case 1: {
      if (PressedObject != 0) {
        exec_round_button = (TButton_Round*)PressedObject;
        if ((exec_round_button->PressColEnabled != 0) && (exec_round_button->OwnerScreen == CurrentScreen)) {
          DrawRoundButton(exec_round_button);
        }
        break;
      }
      break;
    }
  }


  Get_Object(X, Y);


  if (_object_count != -1) {
  // Buttons
    if (_object_count == button_order) {
      if (exec_button->Active != 0) {
        if (exec_button->OnUpPtr != 0)
          exec_button->OnUpPtr();
        if (PressedObject == (void *)exec_button)
          if (exec_button->OnClickPtr != 0)
            exec_button->OnClickPtr();
        PressedObject = 0;
        PressedObjectType = -1;
        return;
      }
    }

  // Buttons with Round Edges
    if (_object_count == round_button_order) {
      if (exec_round_button->Active != 0) {
        if (exec_round_button->OnUpPtr != 0)
          exec_round_button->OnUpPtr();
        if (PressedObject == (void *)exec_round_button)
          if (exec_round_button->OnClickPtr != 0)
            exec_round_button->OnClickPtr();
        PressedObject = 0;
        PressedObjectType = -1;
        return;
      }
    }

  }
  PressedObject = 0;
  PressedObjectType = -1;
}

void Process_TP_Down(unsigned int X, unsigned int Y) {

  object_pressed      = 0;
  exec_button         = 0;
  exec_round_button   = 0;

  Get_Object(X, Y);

  if (_object_count != -1) {
    if (_object_count == button_order) {
      if (exec_button->Active != 0) {
        if (exec_button->PressColEnabled != 0) {
          object_pressed = 1;
          DrawButton(exec_button);
        }
        PressedObject = (void *)exec_button;
        PressedObjectType = 0;
        if (exec_button->OnDownPtr != 0) {
          exec_button->OnDownPtr();
          return;
        }
      }
    }

    if (_object_count == round_button_order) {
      if (exec_round_button->Active != 0) {
        if (exec_round_button->PressColEnabled != 0) {
          object_pressed = 1;
          DrawRoundButton(exec_round_button);
        }
        PressedObject = (void *)exec_round_button;
        PressedObjectType = 1;
        if (exec_round_button->OnDownPtr != 0) {
          exec_round_button->OnDownPtr();
          return;
        }
      }
    }

  }
}

void Check_TP() {
  if (TP_TFT_Press_Detect()) {
    if (TP_TFT_Get_Coordinates(&Xcoord, &Ycoord) == 0) {
    // After a PRESS is detected read X-Y and convert it to Display dimensions space
      Process_TP_Press(Xcoord, Ycoord);
      if (PenDown == 0) {
        PenDown = 1;
        Process_TP_Down(Xcoord, Ycoord);
      }
    }
  }
  else if (PenDown == 1) {
    PenDown = 0;
    Process_TP_Up(Xcoord, Ycoord);
  }
}

void Init_MCU() {
  GPIO_Config(&GPIO_PORTA_DATA_BITS, 0b00001000, _GPIO_DIR_OUTPUT, _GPIO_CFG_DIGITAL_ENABLE | _GPIO_CFG_DRIVE_8mA, 0);
  TFT_BLED = 1;
  TFT_Set_Default_Mode();
  TP_TFT_Set_Default_Mode();
}

void Start_TP() {
  Init_MCU();

  InitializeTouchPanel();

  Delay_ms(1000);
  TFT_Fill_Screen(0);
  Calibrate();
  TFT_Fill_Screen(0);

  InitializeObjects();
  display_width = Screen1.Width;
  display_height = Screen1.Height;
  DrawScreen(&Screen1);
}