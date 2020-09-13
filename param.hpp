#ifndef PARAM_HPP
#define PARAM_HPP

#define MAXARGS 32

class Param
{
private:
   char* inputRedirect;
   char* outputRedirect;
   char* argumentVector[MAXARGS];
   int   argumentCount;
public:
   Param();
   void printParams();

   void setinputRedirect(char *);
   void setoutputRedirect(char *);
   void setargumentCount(int);
   void setargumentVector(char *);

   int getargumentCount();
};
#endif