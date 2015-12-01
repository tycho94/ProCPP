ProgramSettings::ProgramSettings(char t)
{
  type = t;

  switch (type)
  {
    case 'A':
      break;
    case 'B':
      break;
    case 'C':
      break;
    default:
      // TODO: provide error message
      break;
  }
}

String ProgramSettings::ToString()
{
  return ("<todo>");
}

