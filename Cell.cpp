#include "Cell.h"
#include <iostream>
using namespace std;
namespace gtu{
Cell::Cell() : value('.') {/*Intentionaly leaved blank*/    }

bool Cell::operator ==(const Cell & other) const{

     return(cell==other.cell&&value==other.value&&row==other.row);
}


}
