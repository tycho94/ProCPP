#ifndef ISOAP_H
#define ISOAP_H

class ISoap
{
  public:
    // Inputs
    virtual void GetSoap1Switch() = 0;
    virtual void GetSoap2Switch() = 0;
    // Outputs
    virtual void SetSoap1(int level) = 0;
    virtual void SetSoap2(int level) = 0;
};

#endif
