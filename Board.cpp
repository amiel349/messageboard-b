#include "Board.hpp"
#include <iostream>
using ariel::Direction;
using namespace std;
using namespace ariel;

namespace ariel{ 

Board::Board(){}
void Board::post(unsigned int width,unsigned int length,ariel::Direction x, string m_s){
    switch(x){
        case Direction::Horizontal:
        if(width<row_start)
        row_start=width;
        if(length<col_start)
        col_start=length;
        if(length+m_s.size()>col_end)
        col_end=length+m_s.size();
        
        for(size_t i=0; i<m_s.length();i++){
            umap[width][length+i]=m_s[i];
        }
        return;

        case Direction::Vertical:
        if(width<row_start)
        row_start=width;
        if(width+m_s.size()>row_end)
        row_end=width+m_s.size();
        if(length<col_start)
        col_start=length;
        
        for(size_t i=0; i<m_s.length();i++){
            umap[width+i][length]=m_s[i];
        }
        return;

        default:
        return;
    }
};

string Board::read(unsigned int width,unsigned int length,ariel::Direction y,unsigned int num_of_lettters){
    string temp;
    switch(y){
        case Direction::Horizontal:

        for(size_t i=0; i<num_of_lettters;i++){
           if((!umap[width].empty())&&(umap[width][length+i])){
              
               temp+=umap[width][length+i];
               }
           else{
                   temp+="_";
               }
        }
        return temp;
        

        case Direction::Vertical:
        for(size_t i=0; i<num_of_lettters;i++){
           if((!umap[width+i].empty())&&(umap[width+i][length])){

               temp+=umap[width+i][length];
               
           }
           else{
                   temp+="_";
               }
        }
        return temp;

        default:
        return "eror";
    }
    
};
void Board::show(){
    string result;
   for (size_t i =row_start ; i < row_end; i++)
    {    result+="__";
         
      for (size_t j = col_start; j < col_end; j++)
      { if((!umap[i].empty())&&(umap[i][j])){
          result+=umap[i][j];
      }
      else{
          for (size_t k = j; k < col_end; k++)
          {
              result+="_";
          }
          
          break;}
          
      }
      result+="__\n";
      
    }
    cout<<result<<endl;

};

Board::~Board(){};

}
