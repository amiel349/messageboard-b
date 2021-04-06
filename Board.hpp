#include <iostream>
#include <stdexcept>
#include <map>
#include <iterator>
#include "Direction.hpp"
using namespace std;
using ariel::Direction;
namespace ariel{
    class Board{
        
   private:
   map<unsigned int,map<unsigned int,char >> umap;
   unsigned int row_start=INT32_MAX;
   unsigned int row_end=0;
   unsigned int col_start=INT32_MAX;
   unsigned int col_end=0;

   public:
   // constructor and destructor
     Board();
    ~Board();
    // methods
     void post(unsigned int row,unsigned int column,Direction direction, string m_s);
     string read(unsigned int row,unsigned int column,Direction direction, unsigned int m_r);
     void show();
  
   
   };
}
