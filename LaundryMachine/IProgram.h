#ifndef IPROGRAM_H
#define IPROGRAM_H

typedef enum {
  PROGRAM_A = 0,
  PROGRAM_B = 1,
  PROGRAM_C = 2,
  NO_PROGRAM = -1,
} Program;

class IProgram
{
  public:
    // Inputs
    virtual bool GetStartButton() = 0;
    virtual bool GetProgramButton() = 0;
    virtual bool GetProgramMoney(Program program) = 0;

    // Outputs
    virtual void SetProgramIndicator(Program program) = 0;
};

#endif


