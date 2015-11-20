#ifndef PROGRAMSETTINGS_H
#define PROGRAMSETTINGS_H

class ProgramSettings
{
  public:
    ProgramSettings(char);
    String ToString();
  private:
    char type; /* 'A', 'B' or 'C' */
    int cost;
    // etc.
};

#endif

