#ifndef PROGRAMSETTINGS_H
#define PROGRAMSETTINGS_H

class ProgramSettings
{
  public:
    ProgramSettings(char);
    String ToString();
    int cost;
  private:
    char type; /* 'A', 'B' or 'C' */
    // etc.
};

#endif
