// Include guards (prevents double declaring of functions in .h)
#ifndef UTILS_H 
#define UTILS_H // name of the file

//Prototypes of overloaded functions (functions of same name with different passed variables)
int roundHund(int sendVal);
void roundHund(int& sendVal, int& sendVal2);
double roundHund(double sendVal);

#endif