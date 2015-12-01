#ifndef PROGRAMSELECT_H
#define PROGRAMSELECT_H

class ProgramSelect
{
  public:
    ProgramSelect(IProgram *);
    void Poll();
    char GetProgramType();
    void InstallStartHandler(void (* handler)());
  private:
    IProgram * mProgram;
    void (* mStartHandler) (void);
};

#endif



