#ifndef IPROGRAM_H
#define IPROGRAM_H

enum Program
{
  PROGRAM_A = 1,
  PROGRAM_B,
  PROGRAM_C = 3
};

class IProgram
{
  public:
    // Inputs
    virtual bool GetStartButton() = 0;
    virtual bool GetProgramButton() = 0;

    // Outputs
    virtual void SetProgramIndicator(int programIndicator) = 0;
};

#endif


