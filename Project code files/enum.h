#pragma once

enum GameZoneBoard {

    Player1 = 0,
    Player2 = 1,
    Computer_Player1 = 0,
    Computer_Player2 = 1,
    LeftBoardPlayer1 = 0,
    rightBoardPlayer1 = 13,
    LeftBoardPlayer2 = 25,
    rightBoardPlayer2 = 38,
    TopBoard = 0,
    Bottom = 19,

    easy = 0,
    medium = 1,
    hard = 2,
    startGame = 0,
    conGame = 1,
    startHumanVsHuman = 1,
    startHumanVsComputer = 2,
    startComputerVsComputer = 3,
    Continue = 4,
    PresentInstructionskeys = 8,
    EXIT = 9,

    Rows = 20,
    Cols = 14,

    RAND = 7,
    RANDBOMB = 20,
    Down = 0,
    Right = 1,
    Left = 2,

    keyboardSize = 10,

    MoveDown = 0,

    BodyPointSize = 4,
    CommandLoop = 10,
    DirLoop = 3,

    Sleep1 = 200,
    Sleep2 = 150,
    Dropsleep = 10,
    CommandLoopSleep = 50,
    ColorGame = 1,

    easy_missing_percentage = 10,
    medium_missing_percentage = 40,

    _Square = 0,
    _LleftShape = 1,
    _LrightShape = 2,
    _RowShape = 3,
    _ZleftShape = 4,
    _ZrightShape = 5,
    _PlusShape = 6,
    _Bomb = 7,

    _BombExplosion =4,
    _BombExplosionLoop = 9,
    Rotate0 = 0,
    Rotate1 =1,
    Rotate2 = 2,
    Rotate3 = 3,


    HumanVsHuman = 0,
    HumanVsComputer = 1,
    ComputerVsComputer = 2,
    space = ' ',

    RegularRoatate = 0,
    _CheckRotate = 1,
    ESC = 27
}; //  only the game zone area

enum KeyBoard1 {
   
    Drop1 = 'x',
    Drop1B = 'X',
    Right1 = 'd',
    Right1B = 'D',
    Left1 = 'a',
    Left1B = 'A',

    RotateClockWise1 = 's',
    RotateClockWise1B = 'S',
    RotateCounterClockWise1 = 'w',
    RotateCounterClockWise1B = 'W'


}; //Keyboard keys for player 1

enum KeyBoard2 {

    Drop2 = 'm',
    Drop2B = 'M',
    Right2 = 'l',
    Right2B = 'L',
    Left2 = 'j',
    Left2B = 'J',

    RotateClockWise2 = 'k',
    RotateClockWise2B = 'K',
    RotateCounterClockWise2 = 'i',
    RotateCounterClockWise2B = 'I'
}; //Keyboard keys for player 2

enum Color {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHTGREY = 7,
    DARKGREY = 8,
    LIGHTBLUE = 9,
    LIGHTGREEN = 10,
    LIGHTCYAN = 11,
    LIGHTRED = 12,
    LIGHTMAGENTA = 13,
    YELLOW = 14,
    WHITE = 15
};