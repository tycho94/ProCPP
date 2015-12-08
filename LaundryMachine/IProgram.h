#ifndef IPROGRAM_H
#define IPROGRAM_H

class IProgram
{
  public:
    // Inputs
    virtual boolean GetStartButton() = 0;
    virtual boolean GetProgramButton() = 0;

    // Outputs
    virtual void SetProgramIndicator(int programIndicator) = 0;
};

#endif


