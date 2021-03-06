typedef enum {_taLeft, _taCenter, _taRight} TTextAlign;
typedef enum {_tavTop, _tavMiddle, _tavBottom} TTextAlignVertical;

typedef struct Screen TScreen;

typedef struct  Button {
  TScreen*  OwnerScreen;
  char          Order;
  unsigned int  Left;
  unsigned int  Top;
  unsigned int  Width;
  unsigned int  Height;
  char          Pen_Width;
  unsigned int  Pen_Color;
  char          Visible;
  char          Active;
  char          Transparent;
  char          *Caption;
  TTextAlign    TextAlign;
  TTextAlignVertical TextAlignVertical;
  const char    *FontName;
  unsigned int  Font_Color;
  char          VerticalText;
  char          Gradient;
  char          Gradient_Orientation;
  unsigned int  Gradient_Start_Color;
  unsigned int  Gradient_End_Color;
  unsigned int  Color;
  char          PressColEnabled;
  unsigned int  Press_Color;
  void          (*OnUpPtr)();
  void          (*OnDownPtr)();
  void          (*OnClickPtr)();
  void          (*OnPressPtr)();
} TButton;

typedef struct  Button_Round {
  TScreen*  OwnerScreen;
  char          Order;
  unsigned int  Left;
  unsigned int  Top;
  unsigned int  Width;
  unsigned int  Height;
  char          Pen_Width;
  unsigned int  Pen_Color;
  char          Visible;
  char          Active;
  char          Transparent;
  char          *Caption;
  TTextAlign    TextAlign;
  TTextAlignVertical TextAlignVertical;
  const char    *FontName;
  unsigned int  Font_Color;
  char          VerticalText;
  char          Gradient;
  char          Gradient_Orientation;
  unsigned int  Gradient_Start_Color;
  unsigned int  Gradient_End_Color;
  unsigned int  Color;
  char          Corner_Radius;
  char          PressColEnabled;
  unsigned int  Press_Color;
  void          (*OnUpPtr)();
  void          (*OnDownPtr)();
  void          (*OnClickPtr)();
  void          (*OnPressPtr)();
} TButton_Round;

struct Screen {
  unsigned int           Color;
  unsigned int           Width;
  unsigned int           Height;
  unsigned int           ObjectsCount;
  unsigned int           ButtonsCount;
  TButton                * const code *Buttons;
  unsigned int           Buttons_RoundCount;
  TButton_Round          * const code *Buttons_Round;
};

extern   TScreen                Screen1;
extern   TButton               Button1;
extern   TButton_Round          ButtonRound1;
extern   TButton                * const code Screen1_Buttons[1];
extern   TButton_Round          * const code Screen1_Buttons_Round[1];


/////////////////////////
// Events Code Declarations
void Button1OnClick();
void ButtonRound1OnClick();
/////////////////////////

/////////////////////////////////
// Caption variables Declarations
extern char Button1_Caption[];
extern char ButtonRound1_Caption[];
/////////////////////////////////

void DrawScreen(TScreen *aScreen);
void DrawButton(TButton *aButton);
void DrawRoundButton(TButton_Round *Around_button);
void Check_TP();
void Start_TP();
void Process_TP_Press(unsigned int X, unsigned int Y);
void Process_TP_Up(unsigned int X, unsigned int Y);
void Process_TP_Down(unsigned int X, unsigned int Y);